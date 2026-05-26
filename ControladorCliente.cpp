// ============================================================
//  ControladorCliente.cpp  —  Lógica de clientes con MySQL
//  Majo — Grupo 8
//
//  IMPORTANTE: Este archivo usa el conector MySQL de Alejandro.
//  La variable "conn" (conexión abierta) viene de Conexion.h
//  que Alejandro provee. Solo incluye ese header.
// ============================================================
#include "ControladorCliente.h"
//#include "ConexionBD.h"        // <-- header de Alejandro con la conexión MySQL
//#include <mysql/mysql.h>
//#include <sstream>

// ----------------------------------------------------------
//  listarClientes  — SELECT todos los clientes
// ----------------------------------------------------------
//#include "ControladorCliente.h"

using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;

// ============================================================
// Constructor
// ============================================================

ControladorCliente::ControladorCliente() {

    db = gcnew ConexionBD();
}

// ============================================================
// listarClientes
// ============================================================

List<Cliente^>^ ControladorCliente::listarClientes() {

    List<Cliente^>^ lista = gcnew List<Cliente^>();

    try {

        if (db->conexionActiva()) {

            String^ sql =
                "SELECT id_cliente, nit, nombre, telefono, email "
                "FROM CLIENTE ORDER BY nombre ASC";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(sql, db->getConexion());

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {

                Cliente^ c = gcnew Cliente();

                c->id_cliente = Convert::ToInt32(reader["id_cliente"]);
                c->nit = reader["nit"]->ToString();
                c->nombre = reader["nombre"]->ToString();
                c->telefono = reader["telefono"]->ToString();
                c->email = reader["email"]->ToString();

                lista->Add(c);
            }

            reader->Close();
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error listar clientes: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return lista;
}

// ============================================================
// buscarCliente
// ============================================================

List<Cliente^>^ ControladorCliente::buscarCliente(String^ texto) {

    List<Cliente^>^ lista = gcnew List<Cliente^>();

    try {

        if (db->conexionActiva()) {

            String^ sql =
                "SELECT id_cliente, nit, nombre, telefono, email "
                "FROM CLIENTE "
                "WHERE nombre LIKE @t OR nit LIKE @t "
                "ORDER BY nombre ASC";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(sql, db->getConexion());

            cmd->Parameters->AddWithValue("@t", "%" + texto + "%");

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {

                Cliente^ c = gcnew Cliente();

                c->id_cliente = Convert::ToInt32(reader["id_cliente"]);
                c->nit = reader["nit"]->ToString();
                c->nombre = reader["nombre"]->ToString();
                c->telefono = reader["telefono"]->ToString();
                c->email = reader["email"]->ToString();

                lista->Add(c);
            }

            reader->Close();
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error buscar clientes: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return lista;
}

// ============================================================
// guardarCliente
// ============================================================

bool ControladorCliente::guardarCliente(Cliente^ c) {

    try {

        if (db->conexionActiva()) {

            String^ sql;

            if (c->id_cliente == 0) {

                sql =
                    "INSERT INTO CLIENTE (nit, nombre, telefono, email) "
                    "VALUES (@nit, @nombre, @telefono, @email)";
            }
            else {

                sql =
                    "UPDATE CLIENTE SET "
                    "nit=@nit, nombre=@nombre, telefono=@telefono, email=@email "
                    "WHERE id_cliente=@id";
            }

            MySqlCommand^ cmd =
                gcnew MySqlCommand(sql, db->getConexion());

            cmd->Parameters->AddWithValue("@nit", c->nit);
            cmd->Parameters->AddWithValue("@nombre", c->nombre);
            cmd->Parameters->AddWithValue("@telefono", c->telefono);
            cmd->Parameters->AddWithValue("@email", c->email);

            if (c->id_cliente > 0)
                cmd->Parameters->AddWithValue("@id", c->id_cliente);

            return cmd->ExecuteNonQuery() > 0;
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error guardar cliente: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return false;
}

// ============================================================
// eliminarCliente
// ============================================================

bool ControladorCliente::eliminarCliente(int id) {

    try {

        if (db->conexionActiva()) {

            String^ sql =
                "DELETE FROM CLIENTE WHERE id_cliente=@id";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(sql, db->getConexion());

            cmd->Parameters->AddWithValue("@id", id);

            return cmd->ExecuteNonQuery() > 0;
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error eliminar cliente: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return false;
}

// ============================================================
// buscarPorNit
// ============================================================

Cliente^ ControladorCliente::buscarPorNit(String^ nit) {

    Cliente^ c = nullptr;

    try {

        if (db->conexionActiva()) {

            String^ sql =
                "SELECT id_cliente, nit, nombre, telefono, email "
                "FROM CLIENTE WHERE nit=@nit LIMIT 1";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(sql, db->getConexion());

            cmd->Parameters->AddWithValue("@nit", nit);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {

                c = gcnew Cliente();

                c->id_cliente = Convert::ToInt32(reader["id_cliente"]);
                c->nit = reader["nit"]->ToString();
                c->nombre = reader["nombre"]->ToString();
                c->telefono = reader["telefono"]->ToString();
                c->email = reader["email"]->ToString();
            }

            reader->Close();
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error buscar NIT: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return c;
}