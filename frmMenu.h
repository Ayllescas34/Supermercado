#pragma once
#include "Globals.h"
#include "frmProductos.h"
#include "frmUsuarios.h"
#include "frmInventario.h"
#include "frmVenta.h"
#include "frmHistorialVentas.h"
#include "frmClientes.h"
#include "frmConsultaProductos.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmMenu : public System::Windows::Forms::Form
	{
	public:
		frmMenu(void)
		{
			InitializeComponent();
		}

	protected:
		~frmMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblTitulo;
	protected:

	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Button^ btnVenta;
	private: System::Windows::Forms::Button^ btnProductos;
	private: System::Windows::Forms::Button^ btnInventario;
	private: System::Windows::Forms::Button^ btnUsuarios;
	private: System::Windows::Forms::Button^ btnClientes;
	private: System::Windows::Forms::Button^ btnHistorialVentas;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnConsultaProductos;
	private: System::Windows::Forms::Label^ lblRol;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->btnVenta = (gcnew System::Windows::Forms::Button());
			this->btnProductos = (gcnew System::Windows::Forms::Button());
			this->btnInventario = (gcnew System::Windows::Forms::Button());
			this->btnUsuarios = (gcnew System::Windows::Forms::Button());
			this->btnClientes = (gcnew System::Windows::Forms::Button());
			this->btnHistorialVentas = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnConsultaProductos = (gcnew System::Windows::Forms::Button());
			this->lblRol = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			//  TITULO 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->BackColor = System::Drawing::Color::Transparent;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(30, 30, 30);
			this->lblTitulo->Location = System::Drawing::Point(66, 30);
			this->lblTitulo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(280, 40);
			this->lblTitulo->TabIndex = 2;
			this->lblTitulo->Text = L"Supermercado";

			//  LABEL BIENVENIDA PREFIJO 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(68, 85);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 19);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Bienvenid@:";

			//  LABEL NOMBRE USUARIO 
			this->lblBienvenida->AutoSize = true;
			this->lblBienvenida->BackColor = System::Drawing::Color::Transparent;
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBienvenida->ForeColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->lblBienvenida->Location = System::Drawing::Point(152, 85);
			this->lblBienvenida->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(50, 19);
			this->lblBienvenida->TabIndex = 4;
			this->lblBienvenida->Text = L"name";

			//  LABEL ROL 
			this->lblRol->AutoSize = true;
			this->lblRol->BackColor = System::Drawing::Color::Transparent;
			this->lblRol->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRol->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblRol->Location = System::Drawing::Point(400, 85);
			this->lblRol->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblRol->Name = L"lblRol";
			this->lblRol->Size = System::Drawing::Size(50, 19);
			this->lblRol->TabIndex = 14;
			this->lblRol->Text = L"name";

			//  BOTON VENTA 
			this->btnVenta->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnVenta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVenta->FlatAppearance->BorderSize = 0;
			this->btnVenta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnVenta->ForeColor = System::Drawing::Color::White;
			this->btnVenta->Location = System::Drawing::Point(62, 140);
			this->btnVenta->Margin = System::Windows::Forms::Padding(2);
			this->btnVenta->Name = L"btnVenta";
			this->btnVenta->Size = System::Drawing::Size(180, 50);
			this->btnVenta->TabIndex = 5;
			this->btnVenta->Text = L"Nueva Venta";
			this->btnVenta->UseVisualStyleBackColor = false;
			this->btnVenta->Click += gcnew System::EventHandler(this, &frmMenu::btnVenta_Click);

			//  BOTON PRODUCTOS 
			this->btnProductos->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnProductos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProductos->FlatAppearance->BorderSize = 0;
			this->btnProductos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnProductos->ForeColor = System::Drawing::Color::White;
			this->btnProductos->Location = System::Drawing::Point(290, 140);
			this->btnProductos->Margin = System::Windows::Forms::Padding(2);
			this->btnProductos->Name = L"btnProductos";
			this->btnProductos->Size = System::Drawing::Size(180, 50);
			this->btnProductos->TabIndex = 6;
			this->btnProductos->Text = L"Productos";
			this->btnProductos->UseVisualStyleBackColor = false;
			this->btnProductos->Click += gcnew System::EventHandler(this, &frmMenu::btnProductos_Click);

			//  BOTON INVENTARIO 
			this->btnInventario->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnInventario->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnInventario->FlatAppearance->BorderSize = 0;
			this->btnInventario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnInventario->ForeColor = System::Drawing::Color::White;
			this->btnInventario->Location = System::Drawing::Point(518, 140);
			this->btnInventario->Margin = System::Windows::Forms::Padding(2);
			this->btnInventario->Name = L"btnInventario";
			this->btnInventario->Size = System::Drawing::Size(180, 50);
			this->btnInventario->TabIndex = 7;
			this->btnInventario->Text = L"Inventario";
			this->btnInventario->UseVisualStyleBackColor = false;
			this->btnInventario->Click += gcnew System::EventHandler(this, &frmMenu::btnInventario_Click);

			//  BOTON HISTORIAL VENTAS 
			this->btnHistorialVentas->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnHistorialVentas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHistorialVentas->FlatAppearance->BorderSize = 0;
			this->btnHistorialVentas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnHistorialVentas->ForeColor = System::Drawing::Color::White;
			this->btnHistorialVentas->Location = System::Drawing::Point(62, 210);
			this->btnHistorialVentas->Margin = System::Windows::Forms::Padding(2);
			this->btnHistorialVentas->Name = L"btnHistorialVentas";
			this->btnHistorialVentas->Size = System::Drawing::Size(180, 50);
			this->btnHistorialVentas->TabIndex = 8;
			this->btnHistorialVentas->Text = L"Historial";
			this->btnHistorialVentas->UseVisualStyleBackColor = false;
			this->btnHistorialVentas->Click += gcnew System::EventHandler(this, &frmMenu::btnHistorialVentas_Click);

			//  BOTON CLIENTES 
			this->btnClientes->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnClientes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClientes->FlatAppearance->BorderSize = 0;
			this->btnClientes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnClientes->ForeColor = System::Drawing::Color::White;
			this->btnClientes->Location = System::Drawing::Point(290, 210);
			this->btnClientes->Margin = System::Windows::Forms::Padding(2);
			this->btnClientes->Name = L"btnClientes";
			this->btnClientes->Size = System::Drawing::Size(180, 50);
			this->btnClientes->TabIndex = 9;
			this->btnClientes->Text = L"Clientes";
			this->btnClientes->UseVisualStyleBackColor = false;
			this->btnClientes->Click += gcnew System::EventHandler(this, &frmMenu::btnClientes_Click);

			//  BOTON USUARIOS 
			this->btnUsuarios->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnUsuarios->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUsuarios->FlatAppearance->BorderSize = 0;
			this->btnUsuarios->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnUsuarios->ForeColor = System::Drawing::Color::White;
			this->btnUsuarios->Location = System::Drawing::Point(518, 210);
			this->btnUsuarios->Margin = System::Windows::Forms::Padding(2);
			this->btnUsuarios->Name = L"btnUsuarios";
			this->btnUsuarios->Size = System::Drawing::Size(180, 50);
			this->btnUsuarios->TabIndex = 10;
			this->btnUsuarios->Text = L"Usuarios";
			this->btnUsuarios->UseVisualStyleBackColor = false;
			this->btnUsuarios->Click += gcnew System::EventHandler(this, &frmMenu::btnUsuarios_Click);

			//  BOTON CONSULTA PRODUCTOS 
			this->btnConsultaProductos->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnConsultaProductos->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConsultaProductos->FlatAppearance->BorderSize = 0;
			this->btnConsultaProductos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnConsultaProductos->ForeColor = System::Drawing::Color::White;
			this->btnConsultaProductos->Location = System::Drawing::Point(290, 280);
			this->btnConsultaProductos->Margin = System::Windows::Forms::Padding(2);
			this->btnConsultaProductos->Name = L"btnConsultaProductos";
			this->btnConsultaProductos->Size = System::Drawing::Size(180, 50);
			this->btnConsultaProductos->TabIndex = 12;
			this->btnConsultaProductos->Text = L"Consultar Productos";
			this->btnConsultaProductos->UseVisualStyleBackColor = false;
			this->btnConsultaProductos->Click += gcnew System::EventHandler(this, &frmMenu::btnConsultaProductos_Click);

			//  BOTON SALIR 
			this->btnSalir->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSalir->FlatAppearance->BorderSize = 0;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnSalir->ForeColor = System::Drawing::Color::White;
			this->btnSalir->Location = System::Drawing::Point(518, 280);
			this->btnSalir->Margin = System::Windows::Forms::Padding(2);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(180, 50);
			this->btnSalir->TabIndex = 13;
			this->btnSalir->Text = L"Cerrar Sesión";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &frmMenu::btnSalir_Click);

			//  FORM 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->ClientSize = System::Drawing::Size(781, 380);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Controls->Add(this->lblRol);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnConsultaProductos);
			this->Controls->Add(this->btnUsuarios);
			this->Controls->Add(this->btnClientes);
			this->Controls->Add(this->btnHistorialVentas);
			this->Controls->Add(this->btnInventario);
			this->Controls->Add(this->btnProductos);
			this->Controls->Add(this->btnVenta);
			this->Controls->Add(this->lblBienvenida);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblTitulo);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"frmMenu";
			this->Text = L"Supermercado - Menú Principal";
			this->Load += gcnew System::EventHandler(this, &frmMenu::frmMenu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void frmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
		lblBienvenida->Text = Globals::Datos::nombreActivo;
		lblRol->Text = "Rol: " + Globals::Datos::rolActivo;

		if (Globals::Datos::rolActivo == "vendedor") {
			btnProductos->Visible = false;
			btnInventario->Visible = false;
			btnHistorialVentas->Visible = false;
			btnUsuarios->Visible = false;
		}
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btnVenta_Click(System::Object^ sender, System::EventArgs^ e) {
		frmVenta^ venta = gcnew frmVenta();
		this->Hide();
		venta->ShowDialog();
		this->Show();
	}

	private: System::Void btnInventario_Click(System::Object^ sender, System::EventArgs^ e) {
		frmInventario^ ventanaInventario = gcnew frmInventario();
		this->Hide();
		ventanaInventario->ShowDialog();
		this->Show();
	}

	private: System::Void btnHistorialVentas_Click(System::Object^ sender, System::EventArgs^ e) {
		Supermercado::frmHistorialVentas^ ventanaHistorial = gcnew Supermercado::frmHistorialVentas();
		this->Hide();
		ventanaHistorial->ShowDialog();
		this->Show();
	}

	private: System::Void btnClientes_Click(System::Object^ sender, System::EventArgs^ e) {
		frmClientes^ ventanaClientes = gcnew frmClientes();
		this->Hide();
		ventanaClientes->ShowDialog();
		this->Show();
	}

	private: System::Void btnUsuarios_Click(System::Object^ sender, System::EventArgs^ e) {
		frmUsuarios^ ventana = gcnew frmUsuarios();
		this->Hide();
		ventana->ShowDialog();
		this->Show();
	}

	private: System::Void btnProductos_Click(Object^ sender, EventArgs^ e) {
		frmProductos^ ventana = gcnew frmProductos();
		this->Hide();
		ventana->ShowDialog();
		this->Show();
	}

	private: System::Void btnConsultaProductos_Click(System::Object^ sender, System::EventArgs^ e) {
		frmConsultaProductos^ ventana = gcnew frmConsultaProductos();
		this->Hide();
		ventana->ShowDialog();
		this->Show();
	}
	};
}