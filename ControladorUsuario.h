#pragma once
#pragma once
#include "ConexionBD.h"
#include "ModeloUsuario.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

ref class ControladorUsuario {
private:
    ConexionBD^ db;

public:
    ControladorUsuario();

    // Valida el login
    Usuario^ validarLogin(String^ usuario, String^ password);
};