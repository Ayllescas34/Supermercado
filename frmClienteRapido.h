#pragma once
#include "ControladorCliente.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmClienteRapido : public System::Windows::Forms::Form
	{
	public:
		frmClienteRapido(void)
		{
			InitializeComponent();
			NitIngresado = "";
			NombreIngresado = "";
		}

	protected:
		~frmClienteRapido()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtNit;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::Label^ lblError;

	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtNit = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 20, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->label1->Location = System::Drawing::Point(85, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(260, 35);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Cliente Rapido";

			this->txtNit->BackColor = System::Drawing::Color::White;
			this->txtNit->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtNit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->txtNit->Location = System::Drawing::Point(180, 80);
			this->txtNit->Name = L"txtNit";
			this->txtNit->Size = System::Drawing::Size(180, 32);
			this->txtNit->TabIndex = 2;

			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->label2->Location = System::Drawing::Point(72, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"NIT:";

			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->label3->Location = System::Drawing::Point(72, 140);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Nombre:";

			this->txtNombre->BackColor = System::Drawing::Color::White;
			this->txtNombre->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
			this->txtNombre->Location = System::Drawing::Point(180, 135);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(180, 32);
			this->txtNombre->TabIndex = 4;

			this->btnGuardar->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnGuardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGuardar->FlatAppearance->BorderSize = 0;
			this->btnGuardar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnGuardar->ForeColor = System::Drawing::Color::White;
			this->btnGuardar->Location = System::Drawing::Point(130, 200);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(110, 35);
			this->btnGuardar->TabIndex = 6;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = false;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmClienteRapido::btnGuardar_Click);

			this->btnCancelar->BackColor = System::Drawing::Color::FromArgb(150, 150, 150);
			this->btnCancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancelar->FlatAppearance->BorderSize = 0;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(255, 200);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(110, 35);
			this->btnCancelar->TabIndex = 7;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmClienteRapido::btnCancelar_Click);

			this->lblError->AutoSize = true;
			this->lblError->BackColor = System::Drawing::Color::Transparent;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblError->ForeColor = System::Drawing::Color::FromArgb(220, 80, 80);
			this->lblError->Location = System::Drawing::Point(72, 260);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(0, 17);
			this->lblError->TabIndex = 8;
			this->lblError->Visible = false;

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->ClientSize = System::Drawing::Size(432, 303);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Controls->Add(this->lblError);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtNit);
			this->Controls->Add(this->label1);
			this->Name = L"frmClienteRapido";
			this->Text = L"Cliente Rapido";
			this->ResumeLayout(false);
			this->PerformLayout();
		}

	public:
		String^ NitIngresado;
		String^ NombreIngresado;
#pragma endregion

	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}

	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtNit->Text->Trim() == "") {
			lblError->Text = "El NIT es obligatorio.";
			lblError->Visible = true;
			return;
		}
		if (txtNombre->Text->Trim() == "") {
			lblError->Text = "El nombre es obligatorio.";
			lblError->Visible = true;
			return;
		}

		lblError->Visible = false;

		ControladorCliente^ ctrl = gcnew ControladorCliente();
		Cliente^ nuevo = gcnew Cliente();
		nuevo->nit = txtNit->Text->Trim();
		nuevo->nombre = txtNombre->Text->Trim();
		nuevo->telefono = "";
		nuevo->email = "";

		bool guardado = ctrl->guardarCliente(nuevo);

		if (!guardado) {
			lblError->Text = "Error al guardar en la base de datos.";
			lblError->Visible = true;
			return;
		}

		NitIngresado = txtNit->Text->Trim();
		NombreIngresado = txtNombre->Text->Trim();

		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	};
}