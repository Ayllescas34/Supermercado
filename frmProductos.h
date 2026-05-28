#pragma once

namespace frmProductos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmProductos
	/// </summary>
	public ref class frmProductos : public System::Windows::Forms::Form
	{
	public:
		frmProductos(void)
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
		~frmProductos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtCodigo;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ txtPrecio;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Label^ lblProductos;

	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::Label^ lblPrecio;
	private: System::Windows::Forms::Label^ lblCodigo;
	private: System::Windows::Forms::Label^ lblCategoria;


	protected:

	protected:

	protected:







	private: System::Windows::Forms::ComboBox^ cmbCategoria;

	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Label^ lblBuscar;
	private: System::Windows::Forms::TextBox^ txtBuscar;



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dgvProductos;

	private: System::Windows::Forms::ComboBox^ cmbOrdenar;
	private: System::Windows::Forms::Label^ lblOrdenar;

	private: System::Windows::Forms::Button^ btnOrden;














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
			this->txtCodigo = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->lblProductos = (gcnew System::Windows::Forms::Label());
			this->lblNombre = (gcnew System::Windows::Forms::Label());
			this->lblPrecio = (gcnew System::Windows::Forms::Label());
			this->lblCodigo = (gcnew System::Windows::Forms::Label());
			this->lblCategoria = (gcnew System::Windows::Forms::Label());
			this->cmbCategoria = (gcnew System::Windows::Forms::ComboBox());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->lblBuscar = (gcnew System::Windows::Forms::Label());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dgvProductos = (gcnew System::Windows::Forms::DataGridView());
			this->cmbOrdenar = (gcnew System::Windows::Forms::ComboBox());
			this->lblOrdenar = (gcnew System::Windows::Forms::Label());
			this->btnOrden = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->BeginInit();
			this->SuspendLayout();
			// 
			// txtCodigo
			// 
			this->txtCodigo->Location = System::Drawing::Point(42, 274);
			this->txtCodigo->Name = L"txtCodigo";
			this->txtCodigo->Size = System::Drawing::Size(186, 22);
			this->txtCodigo->TabIndex = 0;
			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(42, 208);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(186, 22);
			this->txtPrecio->TabIndex = 1;
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(42, 147);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(186, 22);
			this->txtNombre->TabIndex = 2;
			// 
			// lblProductos
			// 
			this->lblProductos->AutoSize = true;
			this->lblProductos->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->lblProductos->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProductos->Location = System::Drawing::Point(33, 32);
			this->lblProductos->Name = L"lblProductos";
			this->lblProductos->Size = System::Drawing::Size(164, 49);
			this->lblProductos->TabIndex = 3;
			this->lblProductos->Text = L"Productos";
			// 
			// lblNombre
			// 
			this->lblNombre->AutoSize = true;
			this->lblNombre->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblNombre->Location = System::Drawing::Point(37, 117);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->Size = System::Drawing::Size(82, 27);
			this->lblNombre->TabIndex = 4;
			this->lblNombre->Text = L"Nombre:";
			// 
			// lblPrecio
			// 
			this->lblPrecio->AutoSize = true;
			this->lblPrecio->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrecio->Location = System::Drawing::Point(37, 178);
			this->lblPrecio->Name = L"lblPrecio";
			this->lblPrecio->Size = System::Drawing::Size(69, 27);
			this->lblPrecio->TabIndex = 5;
			this->lblPrecio->Text = L"Precio:";
			this->lblPrecio->Click += gcnew System::EventHandler(this, &frmProductos::label3_Click);
			// 
			// lblCodigo
			// 
			this->lblCodigo->AutoSize = true;
			this->lblCodigo->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCodigo->Location = System::Drawing::Point(37, 244);
			this->lblCodigo->Name = L"lblCodigo";
			this->lblCodigo->Size = System::Drawing::Size(156, 27);
			this->lblCodigo->TabIndex = 6;
			this->lblCodigo->Text = L"Codigo de Barras:";
			// 
			// lblCategoria
			// 
			this->lblCategoria->AutoSize = true;
			this->lblCategoria->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCategoria->Location = System::Drawing::Point(37, 335);
			this->lblCategoria->Name = L"lblCategoria";
			this->lblCategoria->Size = System::Drawing::Size(90, 27);
			this->lblCategoria->TabIndex = 7;
			this->lblCategoria->Text = L"Categoria";
			// 
			// cmbCategoria
			// 
			this->cmbCategoria->BackColor = System::Drawing::Color::Gainsboro;
			this->cmbCategoria->FormattingEnabled = true;
			this->cmbCategoria->Location = System::Drawing::Point(42, 365);
			this->cmbCategoria->Name = L"cmbCategoria";
			this->cmbCategoria->Size = System::Drawing::Size(186, 24);
			this->cmbCategoria->TabIndex = 8;
			this->cmbCategoria->SelectedIndexChanged += gcnew System::EventHandler(this, &frmProductos::comboBox1_SelectedIndexChanged);
			// 
			// btnNuevo
			// 
			this->btnNuevo->BackColor = System::Drawing::Color::PaleGreen;
			this->btnNuevo->Location = System::Drawing::Point(257, 146);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(125, 23);
			this->btnNuevo->TabIndex = 9;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			// 
			// btnGuardar
			// 
			this->btnGuardar->BackColor = System::Drawing::Color::LemonChiffon;
			this->btnGuardar->Location = System::Drawing::Point(257, 207);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(125, 23);
			this->btnGuardar->TabIndex = 10;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = false;
			// 
			// btnEliminar
			// 
			this->btnEliminar->BackColor = System::Drawing::Color::MistyRose;
			this->btnEliminar->Location = System::Drawing::Point(257, 274);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(125, 23);
			this->btnEliminar->TabIndex = 11;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			// 
			// lblBuscar
			// 
			this->lblBuscar->AutoSize = true;
			this->lblBuscar->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBuscar->Location = System::Drawing::Point(502, 54);
			this->lblBuscar->Name = L"lblBuscar";
			this->lblBuscar->Size = System::Drawing::Size(69, 27);
			this->lblBuscar->TabIndex = 12;
			this->lblBuscar->Text = L"Buscar";
			this->lblBuscar->Click += gcnew System::EventHandler(this, &frmProductos::lblBuscar_Click);
			// 
			// txtBuscar
			// 
			this->txtBuscar->Location = System::Drawing::Point(507, 84);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(284, 22);
			this->txtBuscar->TabIndex = 13;
			this->txtBuscar->TextChanged += gcnew System::EventHandler(this, &frmProductos::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(812, 84);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 23);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(943, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Ver Todo";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// dgvProductos
			// 
			this->dgvProductos->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dgvProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProductos->Location = System::Drawing::Point(507, 207);
			this->dgvProductos->Name = L"dgvProductos";
			this->dgvProductos->RowHeadersWidth = 51;
			this->dgvProductos->RowTemplate->Height = 24;
			this->dgvProductos->Size = System::Drawing::Size(561, 262);
			this->dgvProductos->TabIndex = 16;
			this->dgvProductos->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmProductos::dgvProductos_CellContentClick);
			// 
			// cmbOrdenar
			// 
			this->cmbOrdenar->BackColor = System::Drawing::Color::Gainsboro;
			this->cmbOrdenar->FormattingEnabled = true;
			this->cmbOrdenar->Location = System::Drawing::Point(507, 159);
			this->cmbOrdenar->Name = L"cmbOrdenar";
			this->cmbOrdenar->Size = System::Drawing::Size(284, 24);
			this->cmbOrdenar->TabIndex = 17;
			// 
			// lblOrdenar
			// 
			this->lblOrdenar->AutoSize = true;
			this->lblOrdenar->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblOrdenar->Location = System::Drawing::Point(502, 128);
			this->lblOrdenar->Name = L"lblOrdenar";
			this->lblOrdenar->Size = System::Drawing::Size(116, 27);
			this->lblOrdenar->TabIndex = 18;
			this->lblOrdenar->Text = L"Ordenar por:";
			this->lblOrdenar->Click += gcnew System::EventHandler(this, &frmProductos::label6_Click);
			// 
			// btnOrden
			// 
			this->btnOrden->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btnOrden->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOrden->Location = System::Drawing::Point(812, 158);
			this->btnOrden->Name = L"btnOrden";
			this->btnOrden->Size = System::Drawing::Size(125, 24);
			this->btnOrden->TabIndex = 19;
			this->btnOrden->Text = L"Aplicar Orden";
			this->btnOrden->UseVisualStyleBackColor = false;
			// 
			// frmProductos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1096, 494);
			this->Controls->Add(this->btnOrden);
			this->Controls->Add(this->lblOrdenar);
			this->Controls->Add(this->cmbOrdenar);
			this->Controls->Add(this->dgvProductos);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtBuscar);
			this->Controls->Add(this->lblBuscar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->cmbCategoria);
			this->Controls->Add(this->lblCategoria);
			this->Controls->Add(this->lblCodigo);
			this->Controls->Add(this->lblPrecio);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->lblProductos);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->txtCodigo);
			this->Name = L"frmProductos";
			this->Text = L"dgvProductos";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void lblBuscar_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void dgvProductos_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
};
}
