#pragma once
#pragma once

using namespace System;

public ref class Categoria {

public:
	int id_categoria;
	String^ nombre;
	String^ descripcion;

	Categoria() {
		id_categoria = 0;
		nombre = "";
		descripcion = "";
	}

	Categoria(int id, String^ nom, String^ desc) {
		id_categoria = id;
		nombre = nom;
		descripcion = desc;
	}
};