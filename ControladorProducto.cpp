// ============================================================
//  ControladorProducto.cpp  —  Lógica de productos con MySQL
//  Grupo 8
//
//  Adaptado a ConexionBD del proyecto:
//    - SELECTs simples       → db->ejecutaConsulta(sql)
//    - SELECTs con parámetros→ MySqlCommand + db->getConexion()
//    - INSERT / UPDATE / DEL → db->ejecutaIUD(cmd)
// ============================================================

#include "ControladorProducto.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;

// ============================================================
// Constructor
// ============================================================

ControladorProducto::ControladorProducto() {

    db = gcnew ConexionBD();
}

// ============================================================
// listarProductos  —  SELECT todos con JOIN a CATEGORIA
// ============================================================

List<Producto^>^ ControladorProducto::listarProductos() {

    List<Producto^>^ lista = gcnew List<Producto^>();

    try {

        String^ sql =
            "SELECT p.id_producto, p.id_categoria, "
            "       p.nombre, p.precio, p.codigo_barras, "
            "       c.nombre AS nombre_categoria "
            "FROM PRODUCTO p "
            "INNER JOIN CATEGORIA c "
            "    ON p.id_categoria = c.id_categoria "
            "ORDER BY p.nombre ASC";

        MySqlDataReader^ reader = db->ejecutaConsulta(sql);

        if (reader != nullptr) {

            while (reader->Read()) {

                Producto^ p = gcnew Producto();

                p->id_producto      = Convert::ToInt32(reader["id_producto"]);
                p->id_categoria     = Convert::ToInt32(reader["id_categoria"]);
                p->nombre           = reader["nombre"]->ToString();
                p->precio           = Convert::ToDouble(reader["precio"]);
                p->codigo_barras    = reader["codigo_barras"]->ToString();
                p->nombre_categoria = reader["nombre_categoria"]->ToString();

                lista->Add(p);
            }

            reader->Close();
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error listar productos: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return lista;
}

// ============================================================
// buscarProducto  —  búsqueda por nombre o código (con params)
// ============================================================

List<Producto^>^ ControladorProducto::buscarProducto(String^ texto) {

    List<Producto^>^ lista = gcnew List<Producto^>();

    try {

        if (db->conexionActiva()) {

            String^ sql =
                "SELECT p.id_producto, p.id_categoria, "
                "       p.nombre, p.precio, p.codigo_barras, "
                "       c.nombre AS nombre_categoria "
                "FROM PRODUCTO p "
                "INNER JOIN CATEGORIA c "
                "    ON p.id_categoria = c.id_categoria "
                "WHERE p.nombre LIKE @t OR p.codigo_barras LIKE @t "
                "ORDER BY p.nombre ASC";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(sql, db->getConexion());

            cmd->Parameters->AddWithValue("@t", "%" + texto + "%");

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {

                Producto^ p = gcnew Producto();

                p->id_producto      = Convert::ToInt32(reader["id_producto"]);
                p->id_categoria     = Convert::ToInt32(reader["id_categoria"]);
                p->nombre           = reader["nombre"]->ToString();
                p->precio           = Convert::ToDouble(reader["precio"]);
                p->codigo_barras    = reader["codigo_barras"]->ToString();
                p->nombre_categoria = reader["nombre_categoria"]->ToString();

                lista->Add(p);
            }

            reader->Close();
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error buscar productos: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return lista;
}

// ============================================================
// guardarProducto  —  INSERT si id==0, UPDATE si id>0
//   Usa db->ejecutaIUD(cmd)  tal como define ConexionBD
// ============================================================

bool ControladorProducto::guardarProducto(Producto^ p) {

    try {

        if (db->conexionActiva()) {

            String^ sql;

            if (p->id_producto == 0) {

                sql =
                    "INSERT INTO PRODUCTO "
                    "  (id_categoria, nombre, precio, codigo_barras) "
                    "VALUES (@id_cat, @nombre, @precio, @codigo)";
            }
            else {

                sql =
                    "UPDATE PRODUCTO SET "
                    "  id_categoria = @id_cat, "
                    "  nombre       = @nombre, "
                    "  precio       = @precio, "
                    "  codigo_barras = @codigo "
                    "WHERE id_producto = @id";
            }

            MySqlCommand^ cmd = gcnew MySqlCommand(sql);

            cmd->Parameters->AddWithValue("@id_cat", p->id_categoria);
            cmd->Parameters->AddWithValue("@nombre",  p->nombre);
            cmd->Parameters->AddWithValue("@precio",  p->precio);
            cmd->Parameters->AddWithValue("@codigo",  p->codigo_barras);

            if (p->id_producto > 0)
                cmd->Parameters->AddWithValue("@id", p->id_producto);

            return db->ejecutaIUD(cmd) > 0;
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error guardar producto: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return false;
}

// ============================================================
// eliminarProducto
// ============================================================

bool ControladorProducto::eliminarProducto(int id) {

    try {

        if (db->conexionActiva()) {

            String^ sql =
                "DELETE FROM PRODUCTO WHERE id_producto = @id";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql);

            cmd->Parameters->AddWithValue("@id", id);

            return db->ejecutaIUD(cmd) > 0;
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error eliminar producto: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return false;
}

// ============================================================
// buscarPorCodigo
// ============================================================

Producto^ ControladorProducto::buscarPorCodigo(String^ codigo) {

    Producto^ prod = nullptr;

    try {

        if (db->conexionActiva()) {

            String^ sql =
                "SELECT p.id_producto, p.id_categoria, "
                "       p.nombre, p.precio, p.codigo_barras, "
                "       c.nombre AS nombre_categoria "
                "FROM PRODUCTO p "
                "INNER JOIN CATEGORIA c "
                "    ON p.id_categoria = c.id_categoria "
                "WHERE p.codigo_barras = @codigo LIMIT 1";

            MySqlCommand^ cmd =
                gcnew MySqlCommand(sql, db->getConexion());

            cmd->Parameters->AddWithValue("@codigo", codigo);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {

                prod = gcnew Producto();

                prod->id_producto      = Convert::ToInt32(reader["id_producto"]);
                prod->id_categoria     = Convert::ToInt32(reader["id_categoria"]);
                prod->nombre           = reader["nombre"]->ToString();
                prod->precio           = Convert::ToDouble(reader["precio"]);
                prod->codigo_barras    = reader["codigo_barras"]->ToString();
                prod->nombre_categoria = reader["nombre_categoria"]->ToString();
            }

            reader->Close();
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error buscar por código: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return prod;
}

// ============================================================
// listarCategorias  —  para el ComboBox del formulario
// ============================================================

List<Categoria^>^ ControladorProducto::listarCategorias() {

    List<Categoria^>^ lista = gcnew List<Categoria^>();

    try {

        String^ sql =
            "SELECT id_categoria, nombre "
            "FROM CATEGORIA ORDER BY nombre ASC";

        MySqlDataReader^ reader = db->ejecutaConsulta(sql);

        if (reader != nullptr) {

            while (reader->Read()) {

                Categoria^ cat = gcnew Categoria();

                cat->id_categoria = Convert::ToInt32(reader["id_categoria"]);
                cat->nombre       = reader["nombre"]->ToString();

                lista->Add(cat);
            }

            reader->Close();
        }
    }
    catch (Exception^ ex) {

        MessageBox::Show("Error listar categorías: " + ex->Message);
    }
    finally {

        db->cerrarConexion();
    }

    return lista;
}
