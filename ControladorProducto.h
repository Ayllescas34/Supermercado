#pragma once
#pragma once

// ============================================================
//  ControladorProducto.h  —  Declaraciones del controlador
//  Grupo 8
// ============================================================

#include "ModeloProducto.h"
#include "ModeloCategoria.h"
#include "ConexionBD.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

ref class ControladorProducto {

private:

    ConexionBD^ db;

public:

    ControladorProducto();

    // ---- Productos ----------------------------------------
    List<Producto^>^ listarProductos();

    List<Producto^>^ buscarProducto(String^ textoBusqueda);

    bool guardarProducto(Producto^ p);

    bool eliminarProducto(int id_producto);

    Producto^ buscarPorCodigo(String^ codigo_barras);

    // ---- Categorías (para el ComboBox) --------------------
    List<Categoria^>^ listarCategorias();
};