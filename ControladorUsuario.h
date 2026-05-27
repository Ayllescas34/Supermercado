#pragma once
#pragma once
#include "ConexionBD.h"
#include "ModeloUsuario.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;
using namespace System::Collections::Generic;

ref class ControladorUsuario {
private:
    ConexionBD^ db;

public:
    ControladorUsuario();

    // Valida el login
    Usuario^ validarLogin(String^ usuario, String^ password);

	// Lista todos los usuarios
	List<Usuario^>^ listarUsuarios();

	// Guarda (insert si id=0, update si id>0)
	bool guardarUsuario(Usuario^ u);

	// Elimina por id
	bool eliminarUsuario(int id_usuario);
};