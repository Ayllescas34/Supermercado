#include "ControladorUsuario.h"

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