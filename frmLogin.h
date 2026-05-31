#pragma once
#include "ControladorUsuario.h"
#include "Globals.h"
#include "frmMenu.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmLogin : public System::Windows::Forms::Form
	{
	public:
		frmLogin(void)
		{
			InitializeComponent();
		}

	protected:
		~frmLogin()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panelCard;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Label^ lblSubtitle;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnIngresar;
	private: System::Windows::Forms::Label^ lblError;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelCard = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnIngresar = (gcnew System::Windows::Forms::Button());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			this->panelCard->BackColor = System::Drawing::Color::White;
			this->panelCard->Location = System::Drawing::Point(75, 50);
			this->panelCard->Size = System::Drawing::Size(420, 420);
			this->panelCard->TabIndex = 98;
			this->panelCard->BorderStyle = BorderStyle::FixedSingle;
			this->panelCard->Controls->Add(this->lblError);
			this->panelCard->Controls->Add(this->btnIngresar);
			this->panelCard->Controls->Add(this->txtPassword);
			this->panelCard->Controls->Add(this->label4);
			this->panelCard->Controls->Add(this->txtUsuario);
			this->panelCard->Controls->Add(this->label3);
			this->panelCard->Controls->Add(this->lblSubtitle);
			this->panelCard->Controls->Add(this->lblTitle);

			this->lblTitle->AutoSize = false;
			this->lblTitle->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 20, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(0, 0);
			this->lblTitle->Size = System::Drawing::Size(420, 60);
			this->lblTitle->TabIndex = 3;
			this->lblTitle->Text = L"Iniciar Sesion";
			this->lblTitle->TextAlign = ContentAlignment::MiddleCenter;

			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->BackColor = System::Drawing::Color::White;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(120, 120, 120);
			this->lblSubtitle->Location = System::Drawing::Point(30, 75);
			this->lblSubtitle->Size = System::Drawing::Size(360, 20);
			this->lblSubtitle->TabIndex = 4;
			this->lblSubtitle->Text = L"Ingresa tus credenciales para continuar";
			this->lblSubtitle->TextAlign = ContentAlignment::MiddleCenter;

			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->label3->Location = System::Drawing::Point(40, 120);
			this->label3->Text = L"Usuario";
			this->label3->TabIndex = 5;

			this->txtUsuario->BackColor = System::Drawing::Color::White;
			this->txtUsuario->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->txtUsuario->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->txtUsuario->Location = System::Drawing::Point(40, 145);
			this->txtUsuario->Size = System::Drawing::Size(340, 32);
			this->txtUsuario->TabIndex = 6;

			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->label4->Location = System::Drawing::Point(40, 195);
			this->label4->Text = L"Contrasena";
			this->label4->TabIndex = 7;

			this->txtPassword->BackColor = System::Drawing::Color::White;
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->txtPassword->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->txtPassword->Location = System::Drawing::Point(40, 220);
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(340, 32);
			this->txtPassword->TabIndex = 8;

			this->btnIngresar->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnIngresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIngresar->FlatAppearance->BorderSize = 0;
			this->btnIngresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->btnIngresar->ForeColor = System::Drawing::Color::White;
			this->btnIngresar->Location = System::Drawing::Point(40, 280);
			this->btnIngresar->Cursor = Cursors::Hand;
			this->btnIngresar->Size = System::Drawing::Size(340, 45);
			this->btnIngresar->TabIndex = 9;
			this->btnIngresar->Text = L"INGRESAR AL SISTEMA";
			this->btnIngresar->UseVisualStyleBackColor = false;
			this->btnIngresar->Click += gcnew System::EventHandler(this, &frmLogin::btnIngresar_Click);

			this->lblError->AutoSize = true;
			this->lblError->BackColor = System::Drawing::Color::White;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblError->ForeColor = System::Drawing::Color::FromArgb(220, 80, 80);
			this->lblError->Location = System::Drawing::Point(40, 335);
			this->lblError->Visible = false;
			this->lblError->TabIndex = 10;

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->ClientSize = System::Drawing::Size(570, 540);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Controls->Add(this->panelCard);
			this->Name = L"frmLogin";
			this->Text = L"Supermercado - Iniciar Sesion";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void btnIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = txtUsuario->Text->Trim();
		String^ password = txtPassword->Text->Trim();

		if (usuario == "" || password == "") {
			lblError->Text = "Por favor ingresa usuario y contrasena.";
			lblError->Visible = true;
			return;
		}

		ControladorUsuario^ ctrl = gcnew ControladorUsuario();
		Usuario^ usuarioLogueado = ctrl->validarLogin(usuario, password);

		if (usuarioLogueado != nullptr) {
			Globals::Datos::rolActivo = usuarioLogueado->rol;
			Globals::Datos::nombreActivo = usuarioLogueado->nombre;
			Globals::Datos::usuarioActivo = usuarioLogueado->usuario;
			Globals::Datos::idUsuarioActivo = usuarioLogueado->id_usuario;
			Globals::Datos::idTiendaActiva = usuarioLogueado->id_tienda;

			MessageBox::Show("Bienvenido, " + usuarioLogueado->nombre + "!", "Sesion Iniciada", MessageBoxButtons::OK, MessageBoxIcon::Information);
			lblError->Visible = false;
			txtUsuario->Clear();
			txtPassword->Clear();

			frmMenu^ menu = gcnew frmMenu();
			this->Hide();
			menu->ShowDialog();
			this->Close();
		}
		else {
			lblError->Text = "Usuario o contrasena incorrectos.";
			lblError->Visible = true;
			txtPassword->Clear();
			txtUsuario->Focus();
		}
	}
	};
}