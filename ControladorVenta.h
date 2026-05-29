#pragma once
#include "ConexionBD.h"
#include "ModeloVenta.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

ref class ControladorVenta {
private:
	ConexionBD^ db;

public:
	ControladorVenta();

	//guardamos la venta y devuelve id
	int guardarVenta(int id_tienda, int id_cliente, int id_usuario, double total, String^ metodo_pago);

	//guardar c/u producto del carrito en el detalle
	bool guardarDetalle(int id_venta, int id_producto, int cantidad, double precio_unitario);

	//analizar si uso este o el de daniela //TODO
	DataTable^ listarVentas();

	//ventas por rango de fecha, igual ver el de daniela //TODO
	DataTable^ listarVentasPorFecha(String^ fechaDesde, String^ fechaHasta);
};