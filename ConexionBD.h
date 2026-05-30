#pragma once

#include <iostream>

//using namespace std;
using namespace MySql::Data::MySqlClient;
using namespace System;
using namespace System::Data;


ref class ConexionBD {
private:
	MySqlConnection^ cnn;
	String^ servidor = "localhost";
	String^ basededatos = "supermercado_g8";
	String^ usuario = "root";
	String^ clave = "Dani.2006";
	String^ strConexion;
public:
	ConexionBD() {
		cnn = nullptr;
		strConexion = "Database = " + basededatos +
			"; DataSource = " + servidor +
			"; Port = 3307" +
			"; User id = " + usuario +
			"; Password = " + clave;
	}

	MySqlConnection^ getConexion() {
		try {
			if (cnn == nullptr || cnn->State != ConnectionState::Open) {
				cnn = gcnew MySqlConnection(strConexion);
				cnn->Open();
			}
		}
		catch (Exception^ ex) {
			cnn = nullptr;
		}
		return cnn;
	}

	void cerrarConexion() {
		cnn->Close();
	}

	bool conexionActiva() {
		if (getConexion() == nullptr)
			return false;
		return true;
	}

	// SELECT...
	MySqlDataReader^ ejecutaConsulta(String^ strComando) {
		if (strComando == "") {
			return nullptr;
		}
		if (getConexion() != nullptr) {
			MySqlCommand^ sqlCmd = gcnew MySqlCommand(strComando, getConexion());
			return sqlCmd->ExecuteReader();
		}
		return nullptr;
	}

	// SELECT Table...
	DataTable^ ejecutaConsultaTabla(String^ strComando) {
		DataTable^ dt = gcnew DataTable();
		try {
			if (strComando == "") {
				return nullptr;
			}
			if (getConexion() != nullptr) {
				MySqlDataAdapter^ da = gcnew MySqlDataAdapter(strComando, getConexion());
				da->Fill(dt);
			}
		}
		catch (Exception^ ex) {
		}
		return dt;
	}

	// INSERT, DELETE, UPDATE...
	int ejecutaIUD(MySqlCommand^ strComando) {
		int filasAfectadas = 0;
		if (getConexion() != nullptr) {
			strComando->Connection = getConexion();
			filasAfectadas = strComando->ExecuteNonQuery();
			//MySqlCommand^ sqlCmd = gcnew MySqlCommand(strComando, getConexion());
			//filasAfectadas = sqlCmd->ExecuteNonQuery();			
		}
		return filasAfectadas;
	}
};


