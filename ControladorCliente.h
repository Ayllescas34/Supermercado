#pragma once
#include "ModeloCliente.h"
#include <vector>
#include <string>
using namespace std;

// ============================================================
//  ControladorCliente.h  —  Declaraciones del controlador
//  Majo — maneja toda la lógica de clientes con la DB
//  REGLA: Los forms NO escriben SQL. Solo llaman al controlador.
// ============================================================

#pragma once

#include "ModeloCliente.h"
#include "ConexionBD.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

// ============================================================
// ControladorCliente.h
// ============================================================

ref class ControladorCliente {

private:

    ConexionBD^ db;

public:

    ControladorCliente();

    List<Cliente^>^ listarClientes();

    List<Cliente^>^ buscarCliente(String^ textoBusqueda);

    bool guardarCliente(Cliente^ c);

    bool eliminarCliente(int id_cliente);

    Cliente^ buscarPorNit(String^ nit);
};