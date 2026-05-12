#pragma once
#pragma once
using namespace System;

ref class Usuario {
public:
	int id_usuario;
	String^ usuario;
	String^ nombre;
	String^ password;
	String^ rol;
public:
	Usuario() {}
	Usuario(int _id, String^ usr, String^ nom, String^ pwd, String^ r) :
		id_usuario(_id), usuario(usr), nombre(nom), password(pwd), rol(r) {
	}
};