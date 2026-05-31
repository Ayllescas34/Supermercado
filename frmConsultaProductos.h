#pragma once

#include "ControladorProducto.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmConsultaProductos : public System::Windows::Forms::Form
	{
	private:
		Dictionary<String^, int>^ mapaCategorias;
		Panel^ panel1;
		Panel^ panel2;

	public:
		frmConsultaProductos(void)
		{
			InitializeComponent();
			mapaCategorias = gcnew Dictionary<String^, int>();
			CargarCategorias();
			CargarProductos();
		}

	protected:
		~frmConsultaProductos()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblConsulta;
	private: System::Windows::Forms::TextBox^ textBuscarProducto;
	private: System::Windows::Forms::Label^ lblBuscarProductos;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::Button^ btnVerTodo;
	private: System::Windows::Forms::Label^ lblCategoria;
	private: System::Windows::Forms::DataGridView^ dvgConsultaProductos;
	private: System::Windows::Forms::ComboBox^ cmbCategoria;
	private: System::Windows::Forms::Button^ btnRegresar;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
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
			this->btnRegresar = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dvgConsultaProductos))->BeginInit();
			this->SuspendLayout();

			//  FRANJA IZQUIERDA 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->panel2->Location = System::Drawing::Point(0, 52);
			this->panel2->Size = System::Drawing::Size(57, 22);
			this->panel2->TabIndex = 99;

			//  FRANJA DERECHA 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->panel1->Location = System::Drawing::Point(220, 52);
			this->panel1->Size = System::Drawing::Size(570, 22);
			this->panel1->TabIndex = 98;

			// TITULO 
			this->lblConsulta->AutoSize = true;
			this->lblConsulta->BackColor = System::Drawing::Color::Transparent;
			this->lblConsulta->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblConsulta->ForeColor = System::Drawing::Color::FromArgb(30, 30, 30);
			this->lblConsulta->Location = System::Drawing::Point(70, 15);
			this->lblConsulta->Name = L"lblConsulta";
			this->lblConsulta->TabIndex = 0;
			this->lblConsulta->Text = L"Consulta de Productos";

			//  LABEL BUSCAR 
			this->lblBuscarProductos->AutoSize = true;
			this->lblBuscarProductos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblBuscarProductos->Location = System::Drawing::Point(18, 100);
			this->lblBuscarProductos->Name = L"lblBuscarProductos";
			this->lblBuscarProductos->TabIndex = 3;
			this->lblBuscarProductos->Text = L"Buscar Producto:";

			// TEXTBOX BUSCAR 
			this->textBuscarProducto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->textBuscarProducto->Location = System::Drawing::Point(21, 125);
			this->textBuscarProducto->Name = L"textBuscarProducto";
			this->textBuscarProducto->Size = System::Drawing::Size(331, 28);
			this->textBuscarProducto->TabIndex = 2;

			// BUTTON BUSCAR 
			this->btnBuscar->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnBuscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBuscar->FlatAppearance->BorderSize = 0;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(375, 125);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(85, 28);
			this->btnBuscar->TabIndex = 4;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmConsultaProductos::btnBuscar_Click);

			// BUTTON VER TODO
			this->btnVerTodo->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->btnVerTodo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVerTodo->FlatAppearance->BorderSize = 0;
			this->btnVerTodo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnVerTodo->ForeColor = System::Drawing::Color::White;
			this->btnVerTodo->Location = System::Drawing::Point(475, 125);
			this->btnVerTodo->Name = L"btnVerTodo";
			this->btnVerTodo->Size = System::Drawing::Size(85, 28);
			this->btnVerTodo->TabIndex = 5;
			this->btnVerTodo->Text = L"Ver Todo";
			this->btnVerTodo->UseVisualStyleBackColor = false;
			this->btnVerTodo->Click += gcnew System::EventHandler(this, &frmConsultaProductos::btnVerTodo_Click);

			// LABEL CATEGORIA 
			this->lblCategoria->AutoSize = true;
			this->lblCategoria->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblCategoria->Location = System::Drawing::Point(18, 170);
			this->lblCategoria->Name = L"lblCategoria";
			this->lblCategoria->TabIndex = 6;
			this->lblCategoria->Text = L"Filtrar por Categoría:";

			// COMBOBOX CATEGORIA 
			this->cmbCategoria->BackColor = System::Drawing::Color::White;
			this->cmbCategoria->DropDownStyle = ComboBoxStyle::DropDownList;
			this->cmbCategoria->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->cmbCategoria->FormattingEnabled = true;
			this->cmbCategoria->Location = System::Drawing::Point(21, 195);
			this->cmbCategoria->Name = L"cmbCategoria";
			this->cmbCategoria->Size = System::Drawing::Size(331, 28);
			this->cmbCategoria->TabIndex = 8;
			this->cmbCategoria->SelectedIndexChanged += gcnew System::EventHandler(this, &frmConsultaProductos::cmbCategoria_SelectedIndexChanged);

			//  DATAGRIDVIEW 
			this->dvgConsultaProductos->AllowUserToAddRows = false;
			this->dvgConsultaProductos->AllowUserToDeleteRows = false;
			this->dvgConsultaProductos->BackgroundColor = System::Drawing::Color::White;
			this->dvgConsultaProductos->ColumnHeadersHeight = 34;
			this->dvgConsultaProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dvgConsultaProductos->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->dvgConsultaProductos->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dvgConsultaProductos->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold);
			this->dvgConsultaProductos->EnableHeadersVisualStyles = false;
			this->dvgConsultaProductos->DefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10);
			this->dvgConsultaProductos->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->dvgConsultaProductos->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dvgConsultaProductos->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->dvgConsultaProductos->Location = System::Drawing::Point(21, 240);
			this->dvgConsultaProductos->Name = L"dvgConsultaProductos";
			this->dvgConsultaProductos->ReadOnly = true;
			this->dvgConsultaProductos->RowHeadersVisible = false;
			this->dvgConsultaProductos->RowHeadersWidth = 51;
			this->dvgConsultaProductos->RowTemplate->Height = 28;
			this->dvgConsultaProductos->Size = System::Drawing::Size(559, 220);
			this->dvgConsultaProductos->TabIndex = 7;

			//  BUTTON REGRESAR 
			this->btnRegresar->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->btnRegresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegresar->FlatAppearance->BorderSize = 0;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnRegresar->ForeColor = System::Drawing::Color::White;
			this->btnRegresar->Location = System::Drawing::Point(375, 475);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(205, 35);
			this->btnRegresar->TabIndex = 9;
			this->btnRegresar->Text = L"Regresar al Menú";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmConsultaProductos::btnRegresar_Click);

			// FORM 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->ClientSize = System::Drawing::Size(610, 530);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnRegresar);
			this->Controls->Add(this->cmbCategoria);
			this->Controls->Add(this->dvgConsultaProductos);
			this->Controls->Add(this->lblCategoria);
			this->Controls->Add(this->btnVerTodo);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->lblBuscarProductos);
			this->Controls->Add(this->textBuscarProducto);
			this->Controls->Add(this->lblConsulta);
			this->Name = L"frmConsultaProductos";
			this->Text = L"Consulta de Productos";
			this->Load += gcnew System::EventHandler(this, &frmConsultaProductos::frmConsultaProductos_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dvgConsultaProductos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		void CargarCategorias() {
			try {
				ControladorProducto^ ctrl = gcnew ControladorProducto();
				List<Categoria^>^ lista = ctrl->listarCategorias();
				mapaCategorias->Clear();
				cmbCategoria->Items->Clear();
				cmbCategoria->Items->Add("-- Todas las categorías --");
				for each (Categoria ^ cat in lista) {
					mapaCategorias->Add(cat->nombre, cat->id_categoria);
					cmbCategoria->Items->Add(cat->nombre);
				}
				cmbCategoria->SelectedIndex = 0;
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar categorías: " + ex->Message);
			}
		}

		void CargarProductos() {
			try {
				ControladorProducto^ ctrl = gcnew ControladorProducto();
				List<Producto^>^ lista = ctrl->listarProductos();
				dvgConsultaProductos->Rows->Clear();
				dvgConsultaProductos->Columns->Clear();
				dvgConsultaProductos->Columns->Add("id", "ID");
				dvgConsultaProductos->Columns->Add("nombre", "Producto");
				dvgConsultaProductos->Columns->Add("codigo", "Código");
				dvgConsultaProductos->Columns->Add("precio", "Precio Q");
				dvgConsultaProductos->Columns->Add("categoria", "Categoría");
				dvgConsultaProductos->Columns["id"]->Visible = false;

				for each (Producto ^ p in lista) {
					dvgConsultaProductos->Rows->Add(
						p->id_producto,
						p->nombre,
						p->codigo_barras,
						p->precio.ToString("F2"),
						p->nombre_categoria
					);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar productos: " + ex->Message);
			}
		}

		System::Void frmConsultaProductos_Load(System::Object^ sender, System::EventArgs^ e) {
			CargarProductos();
		}

		System::Void btnBuscar_Click(Object^ sender, EventArgs^ e) {
			if (textBuscarProducto->Text->Trim() == "") {
				MessageBox::Show("Ingresa un producto para buscar.");
				return;
			}
			try {
				ControladorProducto^ ctrl = gcnew ControladorProducto();
				List<Producto^>^ lista = ctrl->buscarProducto(textBuscarProducto->Text->Trim());
				dvgConsultaProductos->Rows->Clear();
				for each (Producto ^ p in lista) {
					dvgConsultaProductos->Rows->Add(
						p->id_producto,
						p->nombre,
						p->codigo_barras,
						p->precio.ToString("F2"),
						p->nombre_categoria
					);
				}
				if (lista->Count == 0)
					MessageBox::Show("No se encontraron productos.");
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error en búsqueda: " + ex->Message);
			}
		}

		System::Void btnVerTodo_Click(Object^ sender, EventArgs^ e) {
			textBuscarProducto->Clear();
			cmbCategoria->SelectedIndex = 0;
			CargarProductos();
		}

		System::Void cmbCategoria_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
			if (cmbCategoria->SelectedIndex == 0) {
				CargarProductos();
				return;
			}
			try {
				String^ catNombre = cmbCategoria->SelectedItem->ToString();
				int idCat = mapaCategorias[catNombre];

				ControladorProducto^ ctrl = gcnew ControladorProducto();
				List<Producto^>^ lista = ctrl->listarProductos();

				dvgConsultaProductos->Rows->Clear();
				int contador = 0;
				for each (Producto ^ p in lista) {
					if (p->id_categoria == idCat) {
						dvgConsultaProductos->Rows->Add(
							p->id_producto,
							p->nombre,
							p->codigo_barras,
							p->precio.ToString("F2"),
							p->nombre_categoria
						);
						contador++;
					}
				}
				if (contador == 0)
					MessageBox::Show("No hay productos en esta categoría.");
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al filtrar: " + ex->Message);
			}
		}

		System::Void btnRegresar_Click(Object^ sender, EventArgs^ e) {
			this->Close();
		}
	};
}