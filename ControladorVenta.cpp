#include "ControladorVenta.h"

using namespace System::Windows::Forms;

//constructor
ControladorVenta::ControladorVenta() {
    db = gcnew ConexionBD();
}

//guarda venta y devulevo id generado
int ControladorVenta::guardarVenta(int id_tienda, int id_cliente, int id_usuario, double total, String^ metodo_pago) {
    
    try {
        if (db->conexionActiva()) {
            String^ sql = "INSERT INTO VENTA (id_tienda, id_cliente, id_usuario, total, metodo_pago) "
                "VALUES (@tienda, @cliente, @usuario, @total, @metodo)";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
            cmd->Parameters->AddWithValue("@tienda", id_tienda);
            cmd->Parameters->AddWithValue("@cliente", id_cliente);
            cmd->Parameters->AddWithValue("@usuario", id_usuario);
            cmd->Parameters->AddWithValue("@total", total);
            cmd->Parameters->AddWithValue("@metodo", metodo_pago);

            cmd->ExecuteNonQuery();

            // Obtener el id generado
            MySqlCommand^ cmdId = gcnew MySqlCommand("SELECT LAST_INSERT_ID()", db->getConexion());
            int idGenerado = Convert::ToInt32(cmdId->ExecuteScalar());
            db->cerrarConexion();
            return idGenerado;

        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error guardar venta: " + ex->Message);
    }
    return 0;
}

// Guarda cada producto del carrito en DETALLE_VENTA
bool ControladorVenta::guardarDetalle(int id_venta, int id_producto,
    int cantidad, double precio_unitario) {
    try {
        if (db->conexionActiva()) {
            String^ sql = "INSERT INTO DETALLE_VENTA (id_venta, id_producto, cantidad, precio_unitario) "
                "VALUES (@venta, @producto, @cantidad, @precio)";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
            cmd->Parameters->AddWithValue("@venta", id_venta);
            cmd->Parameters->AddWithValue("@producto", id_producto);
            cmd->Parameters->AddWithValue("@cantidad", cantidad);
            cmd->Parameters->AddWithValue("@precio", precio_unitario);

            return (cmd->ExecuteNonQuery() > 0);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error guardar detalle: " + ex->Message);
    }
    return false;
}

// Trae todas las ventas para el historial
DataTable^ ControladorVenta::listarVentas() {
    try {
        if (db->conexionActiva()) {
            String^ sql = "SELECT v.id_venta, v.fecha, c.nombre AS cliente, "
                "u.nombre AS cajero, v.total, v.metodo_pago "
                "FROM VENTA v "
                "JOIN CLIENTE c ON v.id_cliente = c.id_cliente "
                "JOIN USUARIO u ON v.id_usuario = u.id_usuario "
                "ORDER BY v.fecha DESC";
            return db->ejecutaConsultaTabla(sql);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error listar ventas: " + ex->Message);
    }
    return gcnew DataTable();
}

// Trae ventas por rango de fechas
DataTable^ ControladorVenta::listarVentasPorFecha(String^ fechaDesde, String^ fechaHasta) {
    try {
        if (db->conexionActiva()) {
            String^ sql = "SELECT v.id_venta, v.fecha, c.nombre AS cliente, "
                "u.nombre AS cajero, v.total, v.metodo_pago "
                "FROM VENTA v "
                "JOIN CLIENTE c ON v.id_cliente = c.id_cliente "
                "JOIN USUARIO u ON v.id_usuario = u.id_usuario "
                "WHERE DATE(v.fecha) BETWEEN @desde AND @hasta "
                "ORDER BY v.fecha DESC";

            MySqlCommand^ cmd = gcnew MySqlCommand(sql, db->getConexion());
            cmd->Parameters->AddWithValue("@desde", fechaDesde);
            cmd->Parameters->AddWithValue("@hasta", fechaHasta);

            MySqlDataAdapter^ da = gcnew MySqlDataAdapter(cmd);
            DataTable^ dt = gcnew DataTable();
            da->Fill(dt);
            return dt;
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error listar ventas por fecha: " + ex->Message);
    }
    return gcnew DataTable();
}