#pragma once

#include "ControladorInventario.h"
#include "ModeloInventario.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class frmInventario : public System::Windows::Forms::Form
	{
	public:
		frmInventario(void)
		{
			InitializeComponent();
		}

	protected:
		~frmInventario()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ cmbTienda;
	private: System::Windows::Forms::Button^ btnVerificar;
	private: System::Windows::Forms::DataGridView^ dgvInventario;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnRegresar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colProducto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colMinimo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::Button^ btnActualizar;

	private: Dictionary<String^, int>^ mapaTiendas;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cmbTienda = (gcnew System::Windows::Forms::ComboBox());
			this->btnVerificar = (gcnew System::Windows::Forms::Button());
			this->dgvInventario = (gcnew System::Windows::Forms::DataGridView());
			this->colProducto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colMinimo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnRegresar = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInventario))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(58, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(590, 40);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Control de Inventarios y Alertas";
			this->label1->Click += gcnew System::EventHandler(this, &frmInventario::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->label2->Location = System::Drawing::Point(31, 119);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(153, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Seleccionar tienda:";
			// 
			// cmbTienda
			// 
			this->cmbTienda->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTienda->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->cmbTienda->FormattingEnabled = true;
			this->cmbTienda->Location = System::Drawing::Point(31, 145);
			this->cmbTienda->Name = L"cmbTienda";
			this->cmbTienda->Size = System::Drawing::Size(207, 31);
			this->cmbTienda->TabIndex = 2;
			// 
			// btnVerificar
			// 
			this->btnVerificar->BackColor = System::Drawing::Color::MediumPurple;
			this->btnVerificar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVerificar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnVerificar->ForeColor = System::Drawing::Color::White;
			this->btnVerificar->Location = System::Drawing::Point(35, 196);
			this->btnVerificar->Name = L"btnVerificar";
			this->btnVerificar->Size = System::Drawing::Size(203, 48);
			this->btnVerificar->TabIndex = 3;
			this->btnVerificar->Text = L"Cargar Inventario";
			this->btnVerificar->UseVisualStyleBackColor = false;
			this->btnVerificar->Click += gcnew System::EventHandler(this, &frmInventario::btnVerificar_Click);
			// 
			// dgvInventario
			// 
			this->dgvInventario->AllowUserToAddRows = false;
			this->dgvInventario->AllowUserToDeleteRows = false;
			this->dgvInventario->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvInventario->BackgroundColor = System::Drawing::Color::Lavender;
			this->dgvInventario->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvInventario->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->colProducto,
					this->colCantidad, this->colMinimo, this->colEstado
			});
			this->dgvInventario->Location = System::Drawing::Point(272, 145);
			this->dgvInventario->Name = L"dgvInventario";
			this->dgvInventario->RowHeadersVisible = false;
			this->dgvInventario->RowHeadersWidth = 51;
			this->dgvInventario->RowTemplate->Height = 24;
			this->dgvInventario->Size = System::Drawing::Size(730, 280);
			this->dgvInventario->TabIndex = 4;
			// 
			// colProducto
			// 
			this->colProducto->HeaderText = L"Producto";
			this->colProducto->MinimumWidth = 6;
			this->colProducto->Name = L"colProducto";
			this->colProducto->ReadOnly = true;
			// 
			// colCantidad
			// 
			this->colCantidad->HeaderText = L"Cantidad Disponible";
			this->colCantidad->MinimumWidth = 6;
			this->colCantidad->Name = L"colCantidad";
			// 
			// colMinimo
			// 
			this->colMinimo->HeaderText = L"Stock Mínimo";
			this->colMinimo->MinimumWidth = 6;
			this->colMinimo->Name = L"colMinimo";
			this->colMinimo->ReadOnly = true;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->ReadOnly = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(278, 400);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 25);
			this->label3->TabIndex = 5;
			// 
			// btnRegresar
			// 
			this->btnRegresar->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnRegresar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresar->ForeColor = System::Drawing::Color::White;
			this->btnRegresar->Location = System::Drawing::Point(35, 380);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(203, 45);
			this->btnRegresar->TabIndex = 6;
			this->btnRegresar->Text = L"Regresar al Menú";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmInventario::btnRegresar_Click);
			// 
			// btnActualizar
			// 
			this->btnActualizar->BackColor = System::Drawing::Color::MediumPurple;
			this->btnActualizar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActualizar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnActualizar->ForeColor = System::Drawing::Color::White;
			this->btnActualizar->Location = System::Drawing::Point(35, 264);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(203, 53);
			this->btnActualizar->TabIndex = 7;
			this->btnActualizar->Text = L"Actualizar Stock";
			this->btnActualizar->UseVisualStyleBackColor = false;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &frmInventario::btnActualizar_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->panel1->ForeColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(518, 52);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(546, 22);
			this->panel1->TabIndex = 8;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->panel2->ForeColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(-5, 52);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(57, 22);
			this->panel2->TabIndex = 9;
			// 
			// frmInventario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->ClientSize = System::Drawing::Size(1041, 452);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnRegresar);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dgvInventario);
			this->Controls->Add(this->btnVerificar);
			this->Controls->Add(this->cmbTienda);
			this->Controls->Add(this->label2);
			this->Name = L"frmInventario";
			this->Text = L"Sistema Supermercado - Gestión de Inventario";
			this->Load += gcnew System::EventHandler(this, &frmInventario::frmInventario_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInventario))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void frmInventario_Load(System::Object^ sender, System::EventArgs^ e) {

		mapaTiendas = gcnew Dictionary<String^, int>();

		try {
			ConexionBD^ db = gcnew ConexionBD();
			if (db->conexionActiva()) {
				String^ sql = "SELECT id_tienda, nombre FROM TIENDA ORDER BY nombre";
				MySql::Data::MySqlClient::MySqlCommand^ cmd =
					gcnew MySql::Data::MySqlClient::MySqlCommand(sql, db->getConexion());
				MySql::Data::MySqlClient::MySqlDataReader^ reader = cmd->ExecuteReader();

				cmbTienda->Items->Clear();

				while (reader->Read()) {
					String^ nombre = reader["nombre"]->ToString();
					int     id = Convert::ToInt32(reader["id_tienda"]);
					mapaTiendas->Add(nombre, id);
					cmbTienda->Items->Add(nombre);
				}
				reader->Close();
				db->cerrarConexion();

				if (cmbTienda->Items->Count > 0)
					cmbTienda->SelectedIndex = 0;
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al cargar tiendas: " + ex->Message, "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: int GetIdTiendaSeleccionada() {
		if (cmbTienda->SelectedItem == nullptr) return 1;
		String^ nombre = cmbTienda->SelectedItem->ToString();
		if (mapaTiendas->ContainsKey(nombre))
			return mapaTiendas[nombre];
		return 1;
	}

	private: System::Void btnVerificar_Click(System::Object^ sender, System::EventArgs^ e) {

		if (cmbTienda->SelectedIndex < 0) {
			MessageBox::Show("Selecciona una tienda primero.", "Aviso");
			return;
		}

		int idTienda = GetIdTiendaSeleccionada();

		ControladorInventario^ controlador = gcnew ControladorInventario();
		List<ModeloInventario^>^ lista = controlador->obtenerInventarioPorTienda(idTienda);

		dgvInventario->Rows->Clear();
		label3->Text = "";
		bool tieneStockBajo = false;

		for (int i = 0; i < lista->Count; i++) {
			int fila = dgvInventario->Rows->Add();

			dgvInventario->Rows[fila]->Cells["colProducto"]->Value = lista[i]->nombre_producto;
			dgvInventario->Rows[fila]->Cells["colCantidad"]->Value = lista[i]->cantidad;
			dgvInventario->Rows[fila]->Cells["colMinimo"]->Value = lista[i]->stock_minimo;

			if (lista[i]->cantidad <= lista[i]->stock_minimo) {
				dgvInventario->Rows[fila]->Cells["colEstado"]->Value = L"⚠ BAJO STOCK";
				dgvInventario->Rows[fila]->Cells["colCantidad"]->Style->BackColor = System::Drawing::Color::MistyRose;
				dgvInventario->Rows[fila]->Cells["colEstado"]->Style->ForeColor = System::Drawing::Color::Red;
				tieneStockBajo = true;
			}
			else {
				dgvInventario->Rows[fila]->Cells["colEstado"]->Value = L"Normal";
				dgvInventario->Rows[fila]->Cells["colCantidad"]->Style->BackColor = System::Drawing::Color::Honeydew;
			}
		}

		if (tieneStockBajo) {
			label3->ForeColor = System::Drawing::Color::Crimson;
			label3->Text = L"Atención: Se detectaron productos que necesitan reabastecimiento urgente.";
		}
		else {
			label3->ForeColor = System::Drawing::Color::DarkGreen;
			label3->Text = L"¡Todo bien! El inventario de esta tienda se encuentra estable.";
		}
	}

	private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {

		if (dgvInventario->Rows->Count == 0) {
			MessageBox::Show("No hay datos en la tabla. Carga el inventario primero.",
				"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		int idTienda = GetIdTiendaSeleccionada();

		ControladorInventario^ controlador = gcnew ControladorInventario();
		int filasActualizadas = 0;

		for (int i = 0; i < dgvInventario->Rows->Count; i++) {
			String^ nombreProducto = dgvInventario->Rows[i]->Cells["colProducto"]->Value->ToString();
			int     nuevaCantidad = Convert::ToInt32(dgvInventario->Rows[i]->Cells["colCantidad"]->Value);

			if (controlador->actualizarStockProducto(nombreProducto, nuevaCantidad, idTienda))
				filasActualizadas++;
		}

		if (filasActualizadas > 0) {
			MessageBox::Show("¡Inventario actualizado correctamente en la base de datos!",
				"Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			btnVerificar_Click(sender, e);
		}
		else {
			MessageBox::Show("No se pudieron guardar los cambios. Revisa la conexión.",
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}