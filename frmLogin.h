#pragma once
#include "ControladorUsuario.h"
#include "Globals.h"
#include "frmMenu.h"
#include "Globals.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmLogin
	/// </summary>
	public ref class frmLogin : public System::Windows::Forms::Form
	{
	public:
		frmLogin(void)
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
		~frmLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnIngresar;
	private: System::Windows::Forms::Label^ lblError;





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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnIngresar = (gcnew System::Windows::Forms::Button());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(218, 41);
			this->label1->MaximumSize = System::Drawing::Size(300, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 35);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Supermercado";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Control;
			this->label2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(254, 76);
			this->label2->MaximumSize = System::Drawing::Size(300, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(138, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Sistema de Gestión";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(163, 137);
			this->label3->MaximumSize = System::Drawing::Size(300, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 22);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Usuario";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label4->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(163, 209);
			this->label4->MaximumSize = System::Drawing::Size(300, 100);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 22);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Contraseña:";
			// 
			// txtUsuario
			// 
			this->txtUsuario->Location = System::Drawing::Point(311, 137);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(160, 22);
			this->txtUsuario->TabIndex = 4;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(311, 209);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(160, 22);
			this->txtPassword->TabIndex = 5;
			// 
			// btnIngresar
			// 
			this->btnIngresar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnIngresar->FlatAppearance->BorderSize = 3;
			this->btnIngresar->Location = System::Drawing::Point(224, 289);
			this->btnIngresar->Margin = System::Windows::Forms::Padding(5);
			this->btnIngresar->Name = L"btnIngresar";
			this->btnIngresar->Size = System::Drawing::Size(203, 32);
			this->btnIngresar->TabIndex = 6;
			this->btnIngresar->Text = L"Ingresar";
			this->btnIngresar->UseVisualStyleBackColor = false;
			this->btnIngresar->Click += gcnew System::EventHandler(this, &frmLogin::btnIngresar_Click);
			// 
			// lblError
			// 
			this->lblError->AccessibleRole = System::Windows::Forms::AccessibleRole::Cursor;
			this->lblError->AutoSize = true;
			this->lblError->BackColor = System::Drawing::Color::DarkSalmon;
			this->lblError->Location = System::Drawing::Point(209, 349);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(0, 16);
			this->lblError->TabIndex = 7;
			// 
			// frmLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(644, 401);
			this->Controls->Add(this->lblError);
			this->Controls->Add(this->btnIngresar);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtUsuario);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"frmLogin";
			this->Text = L"frmLogin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = txtUsuario->Text->Trim();
		String^ password = txtPassword->Text->Trim();

		if (usuario == "" || password == "") {
			lblError->Text = "Por favor ingresa usuario y contraseña.";
			lblError->Visible = true;
			return;
		}

		ControladorUsuario^ ctrl = gcnew ControladorUsuario();
		Usuario^ usuarioLogueado = ctrl->validarLogin(usuario, password);

		if (usuarioLogueado != nullptr) {
			// Guardar datos en Globals
			Globals::Datos::rolActivo = usuarioLogueado->rol;
			Globals::Datos::nombreActivo = usuarioLogueado->nombre;
			Globals::Datos::usuarioActivo = usuarioLogueado->usuario;
			Globals::Datos::idUsuarioActivo = usuarioLogueado->id_usuario;

			MessageBox::Show("Bienvenido, " + usuarioLogueado->nombre, "Login Exitoso");
			lblError->Visible = false;
			txtUsuario->Clear();
			txtPassword->Clear();

			// Abrir frmMenu y cerrar frmLogin
			frmMenu^ menu = gcnew frmMenu();
			this->Hide();
			menu->ShowDialog();
			this->Close();
		}
		else {
			lblError->Text = "Usuario o contraseña incorrectos.";
			lblError->Visible = true;
			txtPassword->Clear();
		}
	}
};
}
