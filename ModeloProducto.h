#pragma once

using namespace System;

// ============================================================
// ModeloProducto.h (C++/CLI)
// Grupo 8
// ============================================================

public ref class Producto {

public:

    int id_producto;
    int id_categoria;

    String^ nombre;
    String^ codigo_barras;
    String^ nombre_categoria;   // para mostrar en grilla

    double precio;

    // Constructor por defecto
    Producto() {

        id_producto   = 0;
        id_categoria  = 0;
        precio        = 0.0;
        nombre        = "";
        codigo_barras = "";
        nombre_categoria = "";
    }

    // Constructor completo
    Producto(
        int    id,
        int    _id_categoria,
        String^ _nombre,
        double  _precio,
        String^ _codigo_barras,
        String^ _nombre_categoria
    ) {
        id_producto      = id;
        id_categoria     = _id_categoria;
        nombre           = _nombre;
        precio           = _precio;
        codigo_barras    = _codigo_barras;
        nombre_categoria = _nombre_categoria;
    }
};
