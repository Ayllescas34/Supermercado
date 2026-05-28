#pragma once

namespace frmConsultaProductos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmConsultaProductos
	/// </summary>
	public ref class frmConsultaProductos : public System::Windows::Forms::Form
	{
	public:
		frmConsultaProductos(void)
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
		~frmConsultaProductos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblConsulta;
	protected:

	private: System::Windows::Forms::TextBox^ textBuscarProducto;
	private: System::Windows::Forms::Label^ lblBuscarProductos;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::Button^ btnVerTodo;




	private: System::Windows::Forms::Label^ lblCategoria;
	private: System::Windows::Forms::DataGridView^ dvgConsultaProductos;


	private: System::Windows::Forms::ComboBox^ cmbCategoria;


	protected:





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
			this->lblConsulta = (gcnew System::Windows::Forms::Label());
			this->textBuscarProducto = (gcnew System::Windows::Forms::TextBox());
			this->lblBuscarProductos = (gcnew System::Windows::Forms::Label());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->btnVerTodo = (gcnew System::Windows::Forms::Button());
			this->lblCategoria = (gcnew System::Windows::Forms::Label());
			this->dvgConsultaProductos = (gcnew System::Windows::Forms::DataGridView());
			this->cmbCategoria = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dvgConsultaProductos))->BeginInit();
			this->SuspendLayout();
			// 
			// lblConsulta
			// 
			this->lblConsulta->AutoSize = true;
			this->lblConsulta->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->lblConsulta->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblConsulta->Location = System::Drawing::Point(12, 21);
			this->lblConsulta->Name = L"lblConsulta";
			this->lblConsulta->Size = System::Drawing::Size(340, 49);
			this->lblConsulta->TabIndex = 0;
			this->lblConsulta->Text = L"Consulta de Productos";
			// 
			// textBuscarProducto
			// 
			this->textBuscarProducto->Location = System::Drawing::Point(21, 129);
			this->textBuscarProducto->Multiline = true;
			this->textBuscarProducto->Name = L"textBuscarProducto";
			this->textBuscarProducto->Size = System::Drawing::Size(331, 28);
			this->textBuscarProducto->TabIndex = 2;
			// 
			// lblBuscarProductos
			// 
			this->lblBuscarProductos->AutoSize = true;
			this->lblBuscarProductos->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBuscarProductos->Location = System::Drawing::Point(18, 99);
			this->lblBuscarProductos->Name = L"lblBuscarProductos";
			this->lblBuscarProductos->Size = System::Drawing::Size(148, 27);
			this->lblBuscarProductos->TabIndex = 3;
			this->lblBuscarProductos->Text = L"Buscar Producto";
			this->lblBuscarProductos->Click += gcnew System::EventHandler(this, &frmConsultaProductos::label2_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->Location = System::Drawing::Point(375, 129);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(75, 28);
			this->btnBuscar->TabIndex = 4;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmConsultaProductos::button1_Click);
			// 
			// btnVerTodo
			// 
			this->btnVerTodo->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btnVerTodo->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVerTodo->Location = System::Drawing::Point(467, 128);
			this->btnVerTodo->Name = L"btnVerTodo";
			this->btnVerTodo->Size = System::Drawing::Size(81, 29);
			this->btnVerTodo->TabIndex = 5;
			this->btnVerTodo->Text = L"Ver Todo";
			this->btnVerTodo->UseVisualStyleBackColor = false;
			// 
			// lblCategoria
			// 
			this->lblCategoria->AutoSize = true;
			this->lblCategoria->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCategoria->Location = System::Drawing::Point(18, 173);
			this->lblCategoria->Name = L"lblCategoria";
			this->lblCategoria->Size = System::Drawing::Size(90, 27);
			this->lblCategoria->TabIndex = 6;
			this->lblCategoria->Text = L"Categoria";
			// 
			// dvgConsultaProductos
			// 
			this->dvgConsultaProductos->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dvgConsultaProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dvgConsultaProductos->Location = System::Drawing::Point(21, 247);
			this->dvgConsultaProductos->Name = L"dvgConsultaProductos";
			this->dvgConsultaProductos->ReadOnly = true;
			this->dvgConsultaProductos->RowHeadersWidth = 51;
			this->dvgConsultaProductos->RowTemplate->Height = 24;
			this->dvgConsultaProductos->Size = System::Drawing::Size(559, 224);
			this->dvgConsultaProductos->TabIndex = 7;
			// 
			// cmbCategoria
			// 
			this->cmbCategoria->BackColor = System::Drawing::Color::Gainsboro;
			this->cmbCategoria->FormattingEnabled = true;
			this->cmbCategoria->Location = System::Drawing::Point(23, 203);
			this->cmbCategoria->Name = L"cmbCategoria";
			this->cmbCategoria->Size = System::Drawing::Size(329, 24);
			this->cmbCategoria->TabIndex = 8;
			// 
			// frmConsultaProductos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 500);
			this->Controls->Add(this->cmbCategoria);
			this->Controls->Add(this->dvgConsultaProductos);
			this->Controls->Add(this->lblCategoria);
			this->Controls->Add(this->btnVerTodo);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->lblBuscarProductos);
			this->Controls->Add(this->textBuscarProducto);
			this->Controls->Add(this->lblConsulta);
			this->Name = L"frmConsultaProductos";
			this->Text = L"frmConsultaProductos";
			this->Load += gcnew System::EventHandler(this, &frmConsultaProductos::frmConsultaProductos_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dvgConsultaProductos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void frmConsultaProductos_Load(System::Object^ sender, System::EventArgs^ e) {}
};
}
