#pragma once
using namespace System;

public ref class Venta {
public:
	int id_venta;
	int id_tienda;
	int id_cliente;
	int id_usuario;
	String^ fecha;
	double total;
	String^ metodo_pago;

	Venta() {
		id_venta = 0;
		id_tienda = 0;
		id_cliente = 0;
		id_usuario = 0;
		fecha = "";
		total = 0.0;
		metodo_pago = "";
	}
};

public ref class DetalleVenta {
public:
	int id_detalle;
	int id_venta;
	int id_producto;
	int cantidad;
	double precio_unitario;

	DetalleVenta() {
		id_detalle = 0;
		id_venta = 0;
		id_producto = 0;
		cantidad = 0;
		precio_unitario = 0.0;
	}
};