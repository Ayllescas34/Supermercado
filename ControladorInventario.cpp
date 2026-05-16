#include "ControladorInventario.h"

ControladorInventario::ControladorInventario() {
    db = gcnew ConexionBD();
}


List<ModeloInventario^>^ ControladorInventario::obtenerInventarioPorTienda(int idTienda) {
    List<ModeloInventario^>^ lista = gcnew List<ModeloInventario^>();

    try {
        if (db->conexionActiva()) {
            
            String^ sql = "SELECT i.id_inventario, i.id_producto, i.id_tienda, i.cantidad, i.stock_minimo, p.nombre AS nombre_producto "
                "FROM INVENTARIO i "
                "INNER JOIN PRODUCTO p ON i.id_producto = p.id_producto "
                "WHERE i.id_tienda = @idTienda";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
            cmd->Parameters->AddWithValue("@idTienda", idTienda);

            MySqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                ModeloInventario^ inv = gcnew ModeloInventario();
                inv->id_inventario = reader->GetInt32("id_inventario");
                inv->id_producto = reader->GetInt32("id_producto");
                inv->id_tienda = reader->GetInt32("id_tienda");
                inv->cantidad = reader->GetInt32("cantidad");
                inv->stock_minimo = reader->GetInt32("stock_minimo");
                inv->nombre_producto = reader->GetString("nombre_producto");

                lista->Add(inv);
            }

            reader->Close();
            db->cerrarConexion();
        }
    }
    catch (Exception^ ex) {
    }

    return lista;
}

bool ControladorInventario::actualizarStockProducto(String^ nombreProducto, int nuevaCantidad, int idTienda) {
    try {
        if (db->conexionActiva()) {

            String^ consulta = "UPDATE INVENTARIO i "
                "INNER JOIN PRODUCTO p ON i.id_producto = p.id_producto "
                "SET i.cantidad = @cantidad "
                "WHERE p.nombre = @nombre AND i.id_tienda = @idTienda;";

            MySqlCommand^ cmd = gcnew MySqlCommand(consulta, db->getConexion());
            cmd->Parameters->AddWithValue("@cantidad", nuevaCantidad);
            cmd->Parameters->AddWithValue("@nombre", nombreProducto);
            cmd->Parameters->AddWithValue("@idTienda", idTienda);

   
            int filasAfectadas = cmd->ExecuteNonQuery();

            db->cerrarConexion();

            return (filasAfectadas > 0);
        }
    }
    catch (Exception^ ex) {
    }
    return false;
}