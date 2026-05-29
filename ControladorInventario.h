#pragma once
#include "ConexionBD.h"
#include "ModeloInventario.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

using namespace System::Collections::Generic;

ref class ControladorInventario {
private:
    ConexionBD^ db;

public:
    ControladorInventario();

  
    List<ModeloInventario^>^ obtenerInventarioPorTienda(int idTienda);
    bool actualizarStockProducto(String^ nombreProducto, int nuevaCantidad, int idTienda);
};
