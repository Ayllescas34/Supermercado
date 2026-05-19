#pragma once

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmClienteRapido
	/// </summary>
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
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
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
			this->txtNit = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(113, 9);
			this->label1->MaximumSize = System::Drawing::Size(300, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 31);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Cliente Rápido";
			// 
			// txtNit
			// 
			this->txtNit->Location = System::Drawing::Point(231, 84);
			this->txtNit->Name = L"txtNit";
			this->txtNit->Size = System::Drawing::Size(100, 22);
			this->txtNit->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(98, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"NIT:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(98, 141);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Nombre:";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(231, 141);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(100, 22);
			this->txtNombre->TabIndex = 4;
			// 
			// btnGuardar
			// 
			this->btnGuardar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardar->Location = System::Drawing::Point(129, 206);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(75, 23);
			this->btnGuardar->TabIndex = 6;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmClienteRapido::btnGuardar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->Location = System::Drawing::Point(230, 205);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(75, 23);
			this->btnCancelar->TabIndex = 7;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmClienteRapido::btnCancelar_Click);
			// 
			// lblError
			// 
			this->lblError->AutoSize = true;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblError->ForeColor = System::Drawing::Color::Red;
			this->lblError->Location = System::Drawing::Point(177, 263);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(0, 17);
			this->lblError->TabIndex = 8;
			this->lblError->Visible = false;
			// 
			// frmClienteRapido
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(432, 303);
			this->Controls->Add(this->lblError);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtNit);
			this->Controls->Add(this->label1);
			this->Name = L"frmClienteRapido";
			this->Text = L"frmClienteRapido";
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
		this->DialogResult = System::Windows::Forms::DialogResult::OK;

		NitIngresado = txtNit->Text->Trim();
		NombreIngresado = txtNombre->Text->Trim();
		this->Close();
	}
};
}
