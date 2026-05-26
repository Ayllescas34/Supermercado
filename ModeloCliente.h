#pragma once
#pragma once

using namespace System;

// ============================================================
// ModeloCliente.h (C++/CLI)
// ============================================================

public ref class Cliente {

public:

    int id_cliente;

    String^ nit;
    String^ nombre;
    String^ telefono;
    String^ email;

    // Constructor por defecto
    Cliente() {

        id_cliente = 0;
        nit = "CF";
        nombre = "";
        telefono = "";
        email = "";
    }

    // Constructor completo
    Cliente(
        int id,
        String^ _nit,
        String^ _nombre,
        String^ _telefono,
        String^ _email
    ) {
        id_cliente = id;
        nit = _nit;
        nombre = _nombre;
        telefono = _telefono;
        email = _email;
    }
};