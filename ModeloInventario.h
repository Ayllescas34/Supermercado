#pragma once
#include <iostream>


public ref class ModeloInventario {
public:
    int id_inventario;
    int id_producto;
    int id_tienda;
    int cantidad;
    int stock_minimo;

    System::String^ nombre_producto;
    System::String^ nombre_tienda;
}; 
