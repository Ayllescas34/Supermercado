#include "ControladorProducto.h"

using namespace System::Windows::Forms;

ControladorProducto::ControladorProducto() {
	db = gcnew ConexionBD();
}

// ============================================================
// LISTAR TODOS LOS PRODUCTOS con nombre de categoría
// ============================================================
List<Producto^>^ ControladorProducto::listarProductos() {
	List<Producto^>^ lista = gcnew List<Producto^>();
	try {
		if (db->conexionActiva()) {
			String^ sql = "SELECT p.id_producto, p.id_categoria, p.nombre, p.precio, "
				"p.codigo_barras, c.nombre as nombre_categoria "
				"FROM PRODUCTO p "
				"LEFT JOIN CATEGORIA c ON p.id_categoria = c.id_categoria "
				"ORDER BY p.nombre ASC";

			MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
			MySqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read()) {
				Producto^ prod = gcnew Producto();
				prod->id_producto = Convert::ToInt32(reader["id_producto"]);
				prod->id_categoria = Convert::ToInt32(reader["id_categoria"]);
				prod->nombre = reader["nombre"]->ToString();
				prod->precio = Convert::ToDouble(reader["precio"]);
				prod->codigo_barras = reader["codigo_barras"]->ToString();
				prod->nombre_categoria = reader["nombre_categoria"]->ToString();
				lista->Add(prod);
			}
			reader->Close();
			db->cerrarConexion();
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al listar productos: " + ex->Message);
	}
	return lista;
}

// ============================================================
// BUSCAR PRODUCTO por nombre o código
// ============================================================
List<Producto^>^ ControladorProducto::buscarProducto(String^ textoBusqueda) {
	List<Producto^>^ lista = gcnew List<Producto^>();
	try {
		if (db->conexionActiva()) {
			String^ busqueda = "%" + textoBusqueda + "%";
			String^ sql = "SELECT p.id_producto, p.id_categoria, p.nombre, p.precio, "
				"p.codigo_barras, c.nombre as nombre_categoria "
				"FROM PRODUCTO p "
				"LEFT JOIN CATEGORIA c ON p.id_categoria = c.id_categoria "
				"WHERE p.nombre LIKE @busqueda OR p.codigo_barras LIKE @busqueda "
				"ORDER BY p.nombre ASC";

			MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
			cmd->Parameters->AddWithValue("@busqueda", busqueda);
			MySqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read()) {
				Producto^ prod = gcnew Producto();
				prod->id_producto = Convert::ToInt32(reader["id_producto"]);
				prod->id_categoria = Convert::ToInt32(reader["id_categoria"]);
				prod->nombre = reader["nombre"]->ToString();
				prod->precio = Convert::ToDouble(reader["precio"]);
				prod->codigo_barras = reader["codigo_barras"]->ToString();
				prod->nombre_categoria = reader["nombre_categoria"]->ToString();
				lista->Add(prod);
			}
			reader->Close();
			db->cerrarConexion();
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al buscar productos: " + ex->Message);
	}
	return lista;
}

// ============================================================
// GUARDAR PRODUCTO (INSERT si id=0, UPDATE si id>0)
// ============================================================
bool ControladorProducto::guardarProducto(Producto^ p) {
	try {
		if (db->conexionActiva()) {
			String^ sql;

			if (p->id_producto == 0) {
				// INSERT
				sql = "INSERT INTO PRODUCTO (id_categoria, nombre, precio, codigo_barras) "
					"VALUES (@id_cat, @nombre, @precio, @codigo)";
			}
			else {
				// UPDATE
				sql = "UPDATE PRODUCTO SET id_categoria=@id_cat, nombre=@nombre, "
					"precio=@precio, codigo_barras=@codigo "
					"WHERE id_producto=@id";
			}

			MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
			cmd->Parameters->AddWithValue("@id_cat", p->id_categoria);
			cmd->Parameters->AddWithValue("@nombre", p->nombre);
			cmd->Parameters->AddWithValue("@precio", p->precio);
			cmd->Parameters->AddWithValue("@codigo", p->codigo_barras);

			if (p->id_producto > 0)
				cmd->Parameters->AddWithValue("@id", p->id_producto);

			int filas = cmd->ExecuteNonQuery();
			db->cerrarConexion();
			return (filas > 0);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al guardar producto: " + ex->Message);
	}
	return false;
}

// ============================================================
// ELIMINAR PRODUCTO por id
// ============================================================
bool ControladorProducto::eliminarProducto(int id_producto) {
	try {
		if (db->conexionActiva()) {
			String^ sql = "DELETE FROM PRODUCTO WHERE id_producto = @id";
			MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
			cmd->Parameters->AddWithValue("@id", id_producto);
			int filas = cmd->ExecuteNonQuery();
			db->cerrarConexion();
			return (filas > 0);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al eliminar producto: " + ex->Message);
	}
	return false;
}

// ============================================================
// BUSCAR PRODUCTO POR CÓDIGO DE BARRAS (para frmVenta)
// ============================================================
Producto^ ControladorProducto::buscarPorCodigo(String^ codigo_barras) {
	try {
		if (db->conexionActiva()) {
			String^ sql = "SELECT p.id_producto, p.id_categoria, p.nombre, p.precio, "
				"p.codigo_barras, c.nombre as nombre_categoria "
				"FROM PRODUCTO p "
				"LEFT JOIN CATEGORIA c ON p.id_categoria = c.id_categoria "
				"WHERE p.codigo_barras = @codigo";

			MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
			cmd->Parameters->AddWithValue("@codigo", codigo_barras);
			MySqlDataReader^ reader = cmd->ExecuteReader();

			if (reader->Read()) {
				Producto^ prod = gcnew Producto();
				prod->id_producto = Convert::ToInt32(reader["id_producto"]);
				prod->id_categoria = Convert::ToInt32(reader["id_categoria"]);
				prod->nombre = reader["nombre"]->ToString();
				prod->precio = Convert::ToDouble(reader["precio"]);
				prod->codigo_barras = reader["codigo_barras"]->ToString();
				prod->nombre_categoria = reader["nombre_categoria"]->ToString();
				reader->Close();
				db->cerrarConexion();
				return prod;
			}
			reader->Close();
			db->cerrarConexion();
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al buscar por código: " + ex->Message);
	}
	return nullptr;
}

// ============================================================
// LISTAR CATEGORÍAS (para llenar ComboBox)
// ============================================================
List<Categoria^>^ ControladorProducto::listarCategorias() {
	List<Categoria^>^ lista = gcnew List<Categoria^>();
	try {
		if (db->conexionActiva()) {
			String^ sql = "SELECT id_categoria, nombre, descripcion "
				"FROM CATEGORIA "
				"ORDER BY nombre ASC";

			MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
			MySqlDataReader^ reader = cmd->ExecuteReader();

			while (reader->Read()) {
				Categoria^ cat = gcnew Categoria();
				cat->id_categoria = Convert::ToInt32(reader["id_categoria"]);
				cat->nombre = reader["nombre"]->ToString();
				cat->descripcion = reader["descripcion"]->ToString();
				lista->Add(cat);
			}
			reader->Close();
			db->cerrarConexion();
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al listar categorías: " + ex->Message);
	}
	return lista;
}