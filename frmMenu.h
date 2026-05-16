#pragma once
//#include "Globals.h"
#include "Globals.h"
#include "frmInventario.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmMenu
	/// </summary>
	public ref class frmMenu : public System::Windows::Forms::Form
	{
	public:
		frmMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
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
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
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
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(90, 122);
			this->label2->MaximumSize = System::Drawing::Size(300, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Bienvenid@, ";
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->Location = System::Drawing::Point(88, 64);
			this->lblTitulo->MaximumSize = System::Drawing::Size(300, 100);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(209, 35);
			this->lblTitulo->TabIndex = 2;
			this->lblTitulo->Text = L"Supermercado";
			// 
			// lblBienvenida
			// 
			this->lblBienvenida->AutoSize = true;
			this->lblBienvenida->BackColor = System::Drawing::SystemColors::Control;
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBienvenida->Location = System::Drawing::Point(189, 122);
			this->lblBienvenida->MaximumSize = System::Drawing::Size(300, 100);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(46, 20);
			this->lblBienvenida->TabIndex = 4;
			this->lblBienvenida->Text = L"name";
			// 
			// btnVenta
			// 
			this->btnVenta->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnVenta->Location = System::Drawing::Point(82, 181);
			this->btnVenta->Name = L"btnVenta";
			this->btnVenta->Size = System::Drawing::Size(261, 57);
			this->btnVenta->TabIndex = 5;
			this->btnVenta->Text = L"Nueva Venta";
			this->btnVenta->UseVisualStyleBackColor = false;
			// 
			// btnProductos
			// 
			this->btnProductos->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnProductos->Location = System::Drawing::Point(386, 181);
			this->btnProductos->Name = L"btnProductos";
			this->btnProductos->Size = System::Drawing::Size(261, 57);
			this->btnProductos->TabIndex = 6;
			this->btnProductos->Text = L"Productos";
			this->btnProductos->UseVisualStyleBackColor = false;
			// 
			// btnInventario
			// 
			this->btnInventario->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnInventario->Location = System::Drawing::Point(696, 176);
			this->btnInventario->Name = L"btnInventario";
			this->btnInventario->Size = System::Drawing::Size(261, 57);
			this->btnInventario->TabIndex = 7;
			this->btnInventario->Text = L"Inventario";
			this->btnInventario->UseVisualStyleBackColor = false;
			this->btnInventario->Click += gcnew System::EventHandler(this, &frmMenu::btnInventario_Click);
			// 
			// btnUsuarios
			// 
			this->btnUsuarios->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnUsuarios->Location = System::Drawing::Point(696, 249);
			this->btnUsuarios->Name = L"btnUsuarios";
			this->btnUsuarios->Size = System::Drawing::Size(261, 57);
			this->btnUsuarios->TabIndex = 10;
			this->btnUsuarios->Text = L"Usuarios";
			this->btnUsuarios->UseVisualStyleBackColor = false;
			// 
			// btnClientes
			// 
			this->btnClientes->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnClientes->Location = System::Drawing::Point(386, 254);
			this->btnClientes->Name = L"btnClientes";
			this->btnClientes->Size = System::Drawing::Size(261, 57);
			this->btnClientes->TabIndex = 9;
			this->btnClientes->Text = L"Clientes";
			this->btnClientes->UseVisualStyleBackColor = false;
			// 
			// btnHistorialVentas
			// 
			this->btnHistorialVentas->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnHistorialVentas->Location = System::Drawing::Point(82, 254);
			this->btnHistorialVentas->Name = L"btnHistorialVentas";
			this->btnHistorialVentas->Size = System::Drawing::Size(261, 57);
			this->btnHistorialVentas->TabIndex = 8;
			this->btnHistorialVentas->Text = L"Historial";
			this->btnHistorialVentas->UseVisualStyleBackColor = false;
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnSalir->Location = System::Drawing::Point(550, 337);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(261, 57);
			this->btnSalir->TabIndex = 13;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &frmMenu::btnSalir_Click);
			// 
			// btnConsultaProductos
			// 
			this->btnConsultaProductos->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnConsultaProductos->Location = System::Drawing::Point(240, 338);
			this->btnConsultaProductos->Name = L"btnConsultaProductos";
			this->btnConsultaProductos->Size = System::Drawing::Size(261, 57);
			this->btnConsultaProductos->TabIndex = 12;
			this->btnConsultaProductos->Text = L"Consultar";
			this->btnConsultaProductos->UseVisualStyleBackColor = false;
			// 
			// lblRol
			// 
			this->lblRol->AutoSize = true;
			this->lblRol->BackColor = System::Drawing::SystemColors::Control;
			this->lblRol->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRol->Location = System::Drawing::Point(836, 122);
			this->lblRol->MaximumSize = System::Drawing::Size(300, 100);
			this->lblRol->Name = L"lblRol";
			this->lblRol->Size = System::Drawing::Size(46, 20);
			this->lblRol->TabIndex = 14;
			this->lblRol->Text = L"name";
			// 
			// frmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 452);
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
			this->Name = L"frmMenu";
			this->Text = L"frmMenu";
			this->Load += gcnew System::EventHandler(this, &frmMenu::frmMenu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void frmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
		// Mostrar bienvenida
		lblBienvenida->Text = Globals::Datos::nombreActivo;
		lblRol->Text = " ( Rol: " + Globals::Datos::rolActivo + ")";

		// validamos el rol para verificar qué opciones le vamos a mostrar al usuario
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




private: System::Void btnInventario_Click(System::Object^ sender, System::EventArgs^ e) {
	frmInventario^ ventanaInventario = gcnew frmInventario();
	ventanaInventario->ShowDialog();
}
};
}
