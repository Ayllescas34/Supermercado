#pragma once

#include "ControladorProducto.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class frmProductos : public System::Windows::Forms::Form
	{
	private:
		int idProductoSeleccionado;
		Dictionary<String^, int>^ mapaCategorias;

	public:
		frmProductos(void)
		{
			InitializeComponent();
			idProductoSeleccionado = 0;
			mapaCategorias = gcnew Dictionary<String^, int>();
			CargarCategorias();
			CargarProductos();
		}

	protected:
		~frmProductos()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txtCodigo;
	private: System::Windows::Forms::TextBox^ txtPrecio;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::Label^ lblProductos;
	private: System::Windows::Forms::Label^ lblNombre;
	private: System::Windows::Forms::Label^ lblPrecio;
	private: System::Windows::Forms::Label^ lblCodigo;
	private: System::Windows::Forms::Label^ lblCategoria;
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
	private: System::Windows::Forms::Button^ btnRegresar;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
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
			this->btnRegresar = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->BeginInit();
			this->SuspendLayout();

			// ──────────── FRANJAS DECORATIVAS ────────────
			this->panel2->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->panel2->Location = System::Drawing::Point(0, 52);
			this->panel2->Size = System::Drawing::Size(57, 22);
			this->panel2->TabIndex = 99;

			this->panel1->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->panel1->Location = System::Drawing::Point(240, 52);
			this->panel1->Size = System::Drawing::Size(1010, 22);
			this->panel1->TabIndex = 98;

			// ──────────── TITULO ────────────
			this->lblProductos->AutoSize = true;
			this->lblProductos->BackColor = System::Drawing::Color::Transparent;
			this->lblProductos->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 24, System::Drawing::FontStyle::Bold));
			this->lblProductos->ForeColor = System::Drawing::Color::FromArgb(30, 30, 30);
			this->lblProductos->Location = System::Drawing::Point(70, 15);
			this->lblProductos->Name = L"lblProductos";
			this->lblProductos->TabIndex = 3;
			this->lblProductos->Text = L"Gestión de Productos";

			// ──────────── LADO IZQUIERDO: ENTRADA DE DATOS ────────────
			// Label Nombre
			this->lblNombre->AutoSize = true;
			this->lblNombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblNombre->Location = System::Drawing::Point(30, 100);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->TabIndex = 4;
			this->lblNombre->Text = L"Nombre:";

			// TextBox Nombre
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtNombre->Location = System::Drawing::Point(30, 125);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(220, 28);
			this->txtNombre->TabIndex = 2;

			// Label Precio
			this->lblPrecio->AutoSize = true;
			this->lblPrecio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblPrecio->Location = System::Drawing::Point(30, 165);
			this->lblPrecio->Name = L"lblPrecio";
			this->lblPrecio->TabIndex = 5;
			this->lblPrecio->Text = L"Precio:";

			// TextBox Precio
			this->txtPrecio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPrecio->Location = System::Drawing::Point(30, 190);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(220, 28);
			this->txtPrecio->TabIndex = 1;

			// Label Codigo
			this->lblCodigo->AutoSize = true;
			this->lblCodigo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblCodigo->Location = System::Drawing::Point(30, 230);
			this->lblCodigo->Name = L"lblCodigo";
			this->lblCodigo->TabIndex = 6;
			this->lblCodigo->Text = L"Código de Barras:";

			// TextBox Codigo
			this->txtCodigo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtCodigo->Location = System::Drawing::Point(30, 255);
			this->txtCodigo->Name = L"txtCodigo";
			this->txtCodigo->Size = System::Drawing::Size(220, 28);
			this->txtCodigo->TabIndex = 0;

			// Label Categoria
			this->lblCategoria->AutoSize = true;
			this->lblCategoria->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblCategoria->Location = System::Drawing::Point(30, 295);
			this->lblCategoria->Name = L"lblCategoria";
			this->lblCategoria->TabIndex = 7;
			this->lblCategoria->Text = L"Categoría:";

			// ComboBox Categoria
			this->cmbCategoria->BackColor = System::Drawing::Color::White;
			this->cmbCategoria->DropDownStyle = ComboBoxStyle::DropDownList;
			this->cmbCategoria->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->cmbCategoria->FormattingEnabled = true;
			this->cmbCategoria->Location = System::Drawing::Point(30, 320);
			this->cmbCategoria->Name = L"cmbCategoria";
			this->cmbCategoria->Size = System::Drawing::Size(220, 28);
			this->cmbCategoria->TabIndex = 8;

			// Button Nuevo
			this->btnNuevo->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnNuevo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNuevo->FlatAppearance->BorderSize = 0;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnNuevo->ForeColor = System::Drawing::Color::White;
			this->btnNuevo->Location = System::Drawing::Point(30, 370);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(220, 40);
			this->btnNuevo->TabIndex = 9;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmProductos::btnNuevo_Click);

			// Button Guardar
			this->btnGuardar->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnGuardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGuardar->FlatAppearance->BorderSize = 0;
			this->btnGuardar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnGuardar->ForeColor = System::Drawing::Color::White;
			this->btnGuardar->Location = System::Drawing::Point(30, 420);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(220, 40);
			this->btnGuardar->TabIndex = 10;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = false;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmProductos::btnGuardar_Click);

			// Button Eliminar
			this->btnEliminar->BackColor = System::Drawing::Color::FromArgb(75, 143, 179);
			this->btnEliminar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEliminar->FlatAppearance->BorderSize = 0;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnEliminar->ForeColor = System::Drawing::Color::White;
			this->btnEliminar->Location = System::Drawing::Point(30, 470);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(220, 40);
			this->btnEliminar->TabIndex = 11;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmProductos::btnEliminar_Click);

			// Button Regresar (AL FONDO)
			this->btnRegresar->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->btnRegresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegresar->FlatAppearance->BorderSize = 0;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnRegresar->ForeColor = System::Drawing::Color::White;
			this->btnRegresar->Location = System::Drawing::Point(30, 640);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(220, 40);
			this->btnRegresar->TabIndex = 20;
			this->btnRegresar->Text = L"Regresar al Menú";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmProductos::btnRegresar_Click);

			// ──────────── LADO DERECHO: TABLA Y BÚSQUEDA ────────────
			// Label Buscar
			this->lblBuscar->AutoSize = true;
			this->lblBuscar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblBuscar->Location = System::Drawing::Point(280, 100);
			this->lblBuscar->Name = L"lblBuscar";
			this->lblBuscar->TabIndex = 12;
			this->lblBuscar->Text = L"Buscar Producto:";

			// TextBox Buscar
			this->txtBuscar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtBuscar->Location = System::Drawing::Point(280, 125);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(300, 28);
			this->txtBuscar->TabIndex = 13;

			// Button Buscar
			this->button1->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(600, 125);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 28);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmProductos::button1_Click);

			// Button Ver Todo
			this->button2->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(710, 125);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 28);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Ver Todo";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmProductos::button2_Click);

			// Label Ordenar
			this->lblOrdenar->AutoSize = true;
			this->lblOrdenar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lblOrdenar->Location = System::Drawing::Point(280, 165);
			this->lblOrdenar->Name = L"lblOrdenar";
			this->lblOrdenar->TabIndex = 18;
			this->lblOrdenar->Text = L"Ordenar por:";

			// ComboBox Ordenar
			this->cmbOrdenar->BackColor = System::Drawing::Color::White;
			this->cmbOrdenar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->cmbOrdenar->FormattingEnabled = true;
			this->cmbOrdenar->Location = System::Drawing::Point(280, 190);
			this->cmbOrdenar->Name = L"cmbOrdenar";
			this->cmbOrdenar->Size = System::Drawing::Size(300, 28);
			this->cmbOrdenar->TabIndex = 17;

			// Button Aplicar Orden
			this->btnOrden->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->btnOrden->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOrden->FlatAppearance->BorderSize = 0;
			this->btnOrden->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnOrden->ForeColor = System::Drawing::Color::White;
			this->btnOrden->Location = System::Drawing::Point(600, 190);
			this->btnOrden->Name = L"btnOrden";
			this->btnOrden->Size = System::Drawing::Size(200, 28);
			this->btnOrden->TabIndex = 19;
			this->btnOrden->Text = L"Aplicar Orden";
			this->btnOrden->UseVisualStyleBackColor = false;

			// DataGridView
			this->dgvProductos->AllowUserToAddRows = false;
			this->dgvProductos->AllowUserToDeleteRows = false;
			this->dgvProductos->BackgroundColor = System::Drawing::Color::White;
			this->dgvProductos->ColumnHeadersHeight = 34;
			this->dgvProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProductos->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->dgvProductos->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dgvProductos->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold);
			this->dgvProductos->EnableHeadersVisualStyles = false;
			this->dgvProductos->DefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10);
			this->dgvProductos->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->dgvProductos->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dgvProductos->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->dgvProductos->Location = System::Drawing::Point(280, 230);
			this->dgvProductos->Name = L"dgvProductos";
			this->dgvProductos->ReadOnly = true;
			this->dgvProductos->RowHeadersVisible = false;
			this->dgvProductos->RowTemplate->Height = 28;
			this->dgvProductos->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			this->dgvProductos->Size = System::Drawing::Size(730, 450);
			this->dgvProductos->TabIndex = 16;
			this->dgvProductos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmProductos::dgvProductos_CellClick);

			// Form
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->ClientSize = System::Drawing::Size(1050, 720);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->lblProductos);
			this->Controls->Add(this->lblNombre);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->lblPrecio);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->lblCodigo);
			this->Controls->Add(this->txtCodigo);
			this->Controls->Add(this->lblCategoria);
			this->Controls->Add(this->cmbCategoria);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnRegresar);
			this->Controls->Add(this->lblBuscar);
			this->Controls->Add(this->txtBuscar);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->lblOrdenar);
			this->Controls->Add(this->cmbOrdenar);
			this->Controls->Add(this->btnOrden);
			this->Controls->Add(this->dgvProductos);
			this->Name = L"frmProductos";
			this->Text = L"Gestión de Productos";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->EndInit();
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
				for each (Categoria ^ cat in lista) {
					mapaCategorias->Add(cat->nombre, cat->id_categoria);
					cmbCategoria->Items->Add(cat->nombre);
				}
				if (cmbCategoria->Items->Count > 0)
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
				dgvProductos->Rows->Clear();
				dgvProductos->Columns->Clear();
				dgvProductos->Columns->Add("id", "ID");
				dgvProductos->Columns->Add("nombre", "Nombre");
				dgvProductos->Columns->Add("codigo", "Código");
				dgvProductos->Columns->Add("precio", "Precio Q");
				dgvProductos->Columns->Add("categoria", "Categoría");
				dgvProductos->Columns->Add("id_cat", "ID Cat");
				dgvProductos->Columns["id"]->Visible = false;
				dgvProductos->Columns["id_cat"]->Visible = false;

				for each (Producto ^ p in lista) {
					dgvProductos->Rows->Add(
						p->id_producto,
						p->nombre,
						p->codigo_barras,
						p->precio.ToString("F2"),
						p->nombre_categoria,
						p->id_categoria
					);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar productos: " + ex->Message);
			}
		}

		void LimpiarFormulario() {
			idProductoSeleccionado = 0;
			txtNombre->Clear();
			txtCodigo->Clear();
			txtPrecio->Clear();
			if (cmbCategoria->Items->Count > 0)
				cmbCategoria->SelectedIndex = 0;
		}

		System::Void btnNuevo_Click(Object^ sender, EventArgs^ e) {
			LimpiarFormulario();
			txtNombre->Focus();
		}

		System::Void btnGuardar_Click(Object^ sender, EventArgs^ e) {
			if (txtNombre->Text->Trim() == "" || txtCodigo->Text->Trim() == "" || txtPrecio->Text->Trim() == "") {
				MessageBox::Show("Nombre, código y precio son obligatorios.", "Validación");
				return;
			}
			double precio = 0.0;
			try {
				precio = Convert::ToDouble(txtPrecio->Text->Trim());
				if (precio < 0) {
					MessageBox::Show("El precio no puede ser negativo.", "Validación");
					return;
				}
			}
			catch (Exception^) {
				MessageBox::Show("Precio inválido.", "Validación");
				return;
			}

			Producto^ p = gcnew Producto();
			p->id_producto = idProductoSeleccionado;
			p->nombre = txtNombre->Text->Trim();
			p->codigo_barras = txtCodigo->Text->Trim();
			p->precio = precio;
			String^ catNombre = cmbCategoria->SelectedItem->ToString();
			if (mapaCategorias->ContainsKey(catNombre))
				p->id_categoria = mapaCategorias[catNombre];
			else
				p->id_categoria = 1;

			ControladorProducto^ ctrl = gcnew ControladorProducto();
			if (ctrl->guardarProducto(p)) {
				MessageBox::Show(idProductoSeleccionado == 0 ? "Producto creado." : "Producto actualizado.");
				CargarProductos();
				LimpiarFormulario();
			}
		}

		System::Void btnEliminar_Click(Object^ sender, EventArgs^ e) {
			if (idProductoSeleccionado == 0) {
				MessageBox::Show("Seleccione un producto.");
				return;
			}
			if (MessageBox::Show("¿Eliminar este producto?", "Confirmar", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
				ControladorProducto^ ctrl = gcnew ControladorProducto();
				if (ctrl->eliminarProducto(idProductoSeleccionado)) {
					MessageBox::Show("Producto eliminado.");
					CargarProductos();
					LimpiarFormulario();
				}
			}
		}

		System::Void button1_Click(Object^ sender, EventArgs^ e) {
			if (txtBuscar->Text->Trim() == "") {
				CargarProductos();
				return;
			}
			ControladorProducto^ ctrl = gcnew ControladorProducto();
			List<Producto^>^ lista = ctrl->buscarProducto(txtBuscar->Text->Trim());
			dgvProductos->Rows->Clear();
			for each (Producto ^ p in lista) {
				dgvProductos->Rows->Add(
					p->id_producto,
					p->nombre,
					p->codigo_barras,
					p->precio.ToString("F2"),
					p->nombre_categoria,
					p->id_categoria
				);
			}
		}

		System::Void button2_Click(Object^ sender, EventArgs^ e) {
			CargarProductos();
			txtBuscar->Clear();
		}

		System::Void dgvProductos_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
			if (e->RowIndex < 0) return;
			DataGridViewRow^ fila = dgvProductos->Rows[e->RowIndex];
			idProductoSeleccionado = Convert::ToInt32(fila->Cells["id"]->Value);
			txtNombre->Text = fila->Cells["nombre"]->Value->ToString();
			txtCodigo->Text = fila->Cells["codigo"]->Value->ToString();
			txtPrecio->Text = fila->Cells["precio"]->Value->ToString();
			String^ catNombre = fila->Cells["categoria"]->Value->ToString();
			if (cmbCategoria->Items->Contains(catNombre))
				cmbCategoria->SelectedItem = catNombre;
		}

		System::Void btnRegresar_Click(Object^ sender, EventArgs^ e) {
			this->Close();
		}
	};
}