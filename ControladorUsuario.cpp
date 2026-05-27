#include "ControladorUsuario.h"

using namespace System::Windows::Forms;

// Constructor
ControladorUsuario::ControladorUsuario() {
    db = gcnew ConexionBD();
}

// Valida el login contra la base de datos
Usuario^ ControladorUsuario::validarLogin(String^ usuario, String^ password) {
    try {
        if (db->conexionActiva()) {
            String^ sql = "SELECT id_usuario, nombre, usuario, password, rol, id_tienda FROM USUARIO WHERE usuario = @usr AND password = @pwd LIMIT 1";
            MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
            cmd->Parameters->AddWithValue("@usr", usuario);
            cmd->Parameters->AddWithValue("@pwd", password);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                Usuario^ u = gcnew Usuario(
                    reader->GetInt32("id_usuario"),
                    reader->GetString("usuario"),
                    reader->GetString("nombre"),
                    reader->GetString("password"),
                    reader->GetString("rol"),
                    reader->GetInt32("id_tienda")
                );
                reader->Close();
                db->cerrarConexion();
                return u;
            }
            reader->Close();
            db->cerrarConexion();
        }
    }
    catch (Exception^ ex) {
    }
    return nullptr;
}

//listar usuarios
List<Usuario^>^ ControladorUsuario::listarUsuarios() {
    List<Usuario^>^ lista = gcnew List<Usuario^>();
    try {
        if (db->conexionActiva()) {
            String^ sql = "SELECT id_usuario, nombre, usuario, password, rol, id_tienda "
                "FROM USUARIO ORDER BY nombre ASC";
            MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                Usuario^ u = gcnew Usuario();
                u->id_usuario = Convert::ToInt32(reader["id_usuario"]);
                u->nombre = reader["nombre"]->ToString();
                u->usuario = reader["usuario"]->ToString();
                u->password = reader["password"]->ToString();
                u->rol = reader["rol"]->ToString();
                u->id_tienda = Convert::ToInt32(reader["id_tienda"]);
                lista->Add(u);
            }
            reader->Close();
            db->cerrarConexion();
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al listar usuarios: " + ex->Message);
    }
    return lista;
}

//guardar usuario
bool ControladorUsuario::guardarUsuario(Usuario^ u) {
    try {
        if (db->conexionActiva()) {
            String^ sql;

            if (u->id_usuario == 0) {
                // INSERT
                sql = "INSERT INTO USUARIO (nombre, usuario, password, rol, id_tienda) "
                    "VALUES (@nombre, @usuario, @password, @rol, @tienda)";
            }
            else {
                // UPDATE
                sql = "UPDATE USUARIO SET nombre=@nombre, usuario=@usuario, "
                    "password=@password, rol=@rol, id_tienda=@tienda "
                    "WHERE id_usuario=@id";
            }

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
            cmd->Parameters->AddWithValue("@nombre", u->nombre);
            cmd->Parameters->AddWithValue("@usuario", u->usuario);
            cmd->Parameters->AddWithValue("@password", u->password);
            cmd->Parameters->AddWithValue("@rol", u->rol);
            cmd->Parameters->AddWithValue("@tienda", u->id_tienda);

            if (u->id_usuario > 0)
                cmd->Parameters->AddWithValue("@id", u->id_usuario);

            int filas = cmd->ExecuteNonQuery();
            db->cerrarConexion();
            return (filas > 0);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al guardar usuario: " + ex->Message);
    }
    return false;
}

//eliminar usuario
bool ControladorUsuario::eliminarUsuario(int id_usuario) {
    try {
        if (db->conexionActiva()) {
            String^ sql = "DELETE FROM USUARIO WHERE id_usuario = @id";
            MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
            cmd->Parameters->AddWithValue("@id", id_usuario);
            int filas = cmd->ExecuteNonQuery();
            db->cerrarConexion();
            return (filas > 0);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al eliminar usuario: " + ex->Message);
    }
    return false;
}