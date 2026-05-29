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

	/// <summary>
	/// frmProductos — Gestión de Productos CRUD
	/// </summary>
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->BeginInit();
			this->SuspendLayout();

			this->txtCodigo->Location = System::Drawing::Point(42, 274);
			this->txtCodigo->Name = L"txtCodigo";
			this->txtCodigo->Size = System::Drawing::Size(186, 22);
			this->txtCodigo->TabIndex = 0;

			this->txtPrecio->Location = System::Drawing::Point(42, 208);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(186, 22);
			this->txtPrecio->TabIndex = 1;

			this->txtNombre->Location = System::Drawing::Point(42, 147);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(186, 22);
			this->txtNombre->TabIndex = 2;

			this->lblProductos->AutoSize = true;
			this->lblProductos->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->lblProductos->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblProductos->Location = System::Drawing::Point(33, 32);
			this->lblProductos->Name = L"lblProductos";
			this->lblProductos->TabIndex = 3;
			this->lblProductos->Text = L"Productos";

			this->lblNombre->AutoSize = true;
			this->lblNombre->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblNombre->Location = System::Drawing::Point(37, 117);
			this->lblNombre->Name = L"lblNombre";
			this->lblNombre->TabIndex = 4;
			this->lblNombre->Text = L"Nombre:";

			this->lblPrecio->AutoSize = true;
			this->lblPrecio->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblPrecio->Location = System::Drawing::Point(37, 178);
			this->lblPrecio->Name = L"lblPrecio";
			this->lblPrecio->TabIndex = 5;
			this->lblPrecio->Text = L"Precio:";

			this->lblCodigo->AutoSize = true;
			this->lblCodigo->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblCodigo->Location = System::Drawing::Point(37, 244);
			this->lblCodigo->Name = L"lblCodigo";
			this->lblCodigo->TabIndex = 6;
			this->lblCodigo->Text = L"Codigo de Barras:";

			this->lblCategoria->AutoSize = true;
			this->lblCategoria->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblCategoria->Location = System::Drawing::Point(37, 335);
			this->lblCategoria->Name = L"lblCategoria";
			this->lblCategoria->TabIndex = 7;
			this->lblCategoria->Text = L"Categoria";

			this->cmbCategoria->BackColor = System::Drawing::Color::Gainsboro;
			this->cmbCategoria->FormattingEnabled = true;
			this->cmbCategoria->Location = System::Drawing::Point(42, 365);
			this->cmbCategoria->Name = L"cmbCategoria";
			this->cmbCategoria->Size = System::Drawing::Size(186, 24);
			this->cmbCategoria->TabIndex = 8;
			this->cmbCategoria->DropDownStyle = ComboBoxStyle::DropDownList;

			this->btnNuevo->BackColor = System::Drawing::Color::PaleGreen;
			this->btnNuevo->Location = System::Drawing::Point(257, 146);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(125, 23);
			this->btnNuevo->TabIndex = 9;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmProductos::btnNuevo_Click);

			this->btnGuardar->BackColor = System::Drawing::Color::LemonChiffon;
			this->btnGuardar->Location = System::Drawing::Point(257, 207);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(125, 23);
			this->btnGuardar->TabIndex = 10;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = false;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmProductos::btnGuardar_Click);

			this->btnEliminar->BackColor = System::Drawing::Color::MistyRose;
			this->btnEliminar->Location = System::Drawing::Point(257, 274);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(125, 23);
			this->btnEliminar->TabIndex = 11;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmProductos::btnEliminar_Click);

			this->lblBuscar->AutoSize = true;
			this->lblBuscar->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblBuscar->Location = System::Drawing::Point(502, 54);
			this->lblBuscar->Name = L"lblBuscar";
			this->lblBuscar->TabIndex = 12;
			this->lblBuscar->Text = L"Buscar";

			this->txtBuscar->Location = System::Drawing::Point(507, 84);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(284, 22);
			this->txtBuscar->TabIndex = 13;

			this->button1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(812, 84);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 23);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmProductos::button1_Click);

			this->button2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(943, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Ver Todo";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmProductos::button2_Click);

			this->dgvProductos->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dgvProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProductos->Location = System::Drawing::Point(507, 207);
			this->dgvProductos->Name = L"dgvProductos";
			this->dgvProductos->RowHeadersWidth = 51;
			this->dgvProductos->RowTemplate->Height = 24;
			this->dgvProductos->Size = System::Drawing::Size(561, 262);
			this->dgvProductos->TabIndex = 16;
			this->dgvProductos->AllowUserToAddRows = false;
			this->dgvProductos->AllowUserToDeleteRows = false;
			this->dgvProductos->ReadOnly = true;
			this->dgvProductos->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			this->dgvProductos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmProductos::dgvProductos_CellClick);

			this->cmbOrdenar->BackColor = System::Drawing::Color::Gainsboro;
			this->cmbOrdenar->FormattingEnabled = true;
			this->cmbOrdenar->Location = System::Drawing::Point(507, 159);
			this->cmbOrdenar->Name = L"cmbOrdenar";
			this->cmbOrdenar->Size = System::Drawing::Size(284, 24);
			this->cmbOrdenar->TabIndex = 17;

			this->lblOrdenar->AutoSize = true;
			this->lblOrdenar->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblOrdenar->Location = System::Drawing::Point(502, 128);
			this->lblOrdenar->Name = L"lblOrdenar";
			this->lblOrdenar->TabIndex = 18;
			this->lblOrdenar->Text = L"Ordenar por:";

			this->btnOrden->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btnOrden->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnOrden->Location = System::Drawing::Point(812, 158);
			this->btnOrden->Name = L"btnOrden";
			this->btnOrden->Size = System::Drawing::Size(125, 24);
			this->btnOrden->TabIndex = 19;
			this->btnOrden->Text = L"Aplicar Orden";
			this->btnOrden->UseVisualStyleBackColor = false;

			this->btnRegresar = (gcnew System::Windows::Forms::Button());
			this->btnRegresar->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnRegresar->Location = System::Drawing::Point(42, 410);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(200, 35);
			this->btnRegresar->TabIndex = 20;
			this->btnRegresar->Text = L"Regresar al Menú";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmProductos::btnRegresar_Click);

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1096, 494);
			this->Controls->Add(this->btnRegresar);
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
			catch (Exception^ ex){
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