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

	/// <summary>
	/// Resumen de frmInventario
	/// </summary>
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
	private: System::Windows::Forms::Label^ label3; // Este funciona como lblAlerta




	private: System::Windows::Forms::Button^ btnRegresar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colProducto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCantidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colMinimo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::Button^ btnActualizar;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cmbTienda = (gcnew System::Windows::Forms::ComboBox());
			this->btnVerificar = (gcnew System::Windows::Forms::Button());
			this->dgvInventario = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnRegresar = (gcnew System::Windows::Forms::Button());
			this->colProducto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colMinimo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInventario))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->label1->Location = System::Drawing::Point(40, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(475, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Control de Inventarios y Alertas";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->label2->Location = System::Drawing::Point(31, 100);
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
			this->cmbTienda->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Tienda Central", L"Tienda Norte" });
			this->cmbTienda->Location = System::Drawing::Point(31, 130);
			this->cmbTienda->Name = L"cmbTienda";
			this->cmbTienda->Size = System::Drawing::Size(207, 31);
			this->cmbTienda->TabIndex = 2;
			// 
			// btnVerificar
			// 
			this->btnVerificar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnVerificar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnVerificar->ForeColor = System::Drawing::Color::Black;
			this->btnVerificar->Location = System::Drawing::Point(31, 180);
			this->btnVerificar->Name = L"btnVerificar";
			this->btnVerificar->Size = System::Drawing::Size(207, 48);
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
			this->dgvInventario->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgvInventario->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvInventario->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->colProducto,
					this->colCantidad, this->colMinimo, this->colEstado
			});
			this->dgvInventario->Location = System::Drawing::Point(278, 100);
			this->dgvInventario->Name = L"dgvInventario";
			this->dgvInventario->RowHeadersVisible = false;
			this->dgvInventario->RowHeadersWidth = 51;
			this->dgvInventario->RowTemplate->Height = 24;
			this->dgvInventario->Size = System::Drawing::Size(730, 280);
			this->dgvInventario->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(278, 400);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 25);
			this->label3->TabIndex = 5;
			this->label3->Click += gcnew System::EventHandler(this, &frmInventario::label3_Click);
			// 
			// btnRegresar
			// 
			this->btnRegresar->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btnRegresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresar->Location = System::Drawing::Point(35, 362);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(203, 63);
			this->btnRegresar->TabIndex = 6;
			this->btnRegresar->Text = L"Regresar al menu ";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmInventario::btnRegresar_Click);
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
			// btnActualizar
			// 
			this->btnActualizar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnActualizar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnActualizar->Location = System::Drawing::Point(31, 244);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(205, 53);
			this->btnActualizar->TabIndex = 7;
			this->btnActualizar->Text = L"Actualizar Stock";
			this->btnActualizar->UseVisualStyleBackColor = false;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &frmInventario::btnActualizar_Click);
			// 
			// frmInventario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 452);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnRegresar);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dgvInventario);
			this->Controls->Add(this->btnVerificar);
			this->Controls->Add(this->cmbTienda);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"frmInventario";
			this->Text = L"Sistema Supermercado - Gestión de Inventario";
			this->Load += gcnew System::EventHandler(this, &frmInventario::frmInventario_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInventario))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void frmInventario_Load(System::Object^ sender, System::EventArgs^ e) {
		
			if (this->cmbTienda->Items->Count > 0) {
				this->cmbTienda->SelectedIndex = 0;
			}
		}

	private:
		System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		}

	private:
		System::Void btnVerificar_Click(System::Object^ sender, System::EventArgs^ e) {

			
			if (this->cmbTienda->SelectedIndex < 0) return;

			ControladorInventario^ controlador = gcnew ControladorInventario();

			
			int idTiendaSeleccionada = (this->cmbTienda->SelectedIndex == 0) ? 1 : 2;

			
			System::Collections::Generic::List<ModeloInventario^>^ listaInventario = controlador->obtenerInventarioPorTienda(idTiendaSeleccionada);

			this->dgvInventario->Rows->Clear();
			bool tieneStockBajo = false;

			for (int i = 0; i < listaInventario->Count; i++) {
				int renglon = this->dgvInventario->Rows->Add();

				this->dgvInventario->Rows[renglon]->Cells[0]->Value = listaInventario[i]->nombre_producto;
				this->dgvInventario->Rows[renglon]->Cells[1]->Value = listaInventario[i]->cantidad;
				this->dgvInventario->Rows[renglon]->Cells[2]->Value = listaInventario[i]->stock_minimo;

				if (listaInventario[i]->cantidad <= listaInventario[i]->stock_minimo) {
					this->dgvInventario->Rows[renglon]->Cells[3]->Value = L"⚠️ ¡BAJO STOCK!";
					this->dgvInventario->Rows[renglon]->Cells[1]->Style->BackColor = System::Drawing::Color::MistyRose;
					this->dgvInventario->Rows[renglon]->Cells[3]->Style->ForeColor = System::Drawing::Color::Red;
					tieneStockBajo = true;
				}
				else {
					this->dgvInventario->Rows[renglon]->Cells[3]->Value = L"Normal";
					this->dgvInventario->Rows[renglon]->Cells[1]->Style->BackColor = System::Drawing::Color::Honeydew;
				}
			}

			if (tieneStockBajo) {
				this->label3->ForeColor = System::Drawing::Color::Crimson;
				this->label3->Text = L"Atención: Se detectaron productos que necesitan reabastecimiento urgente.";
			}
			else {
				this->label3->ForeColor = System::Drawing::Color::DarkGreen;
				this->label3->Text = L"¡Todo perfecto! El inventario de esta tienda se encuentra estable.";
			}
		}
	private: System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->dgvInventario->Rows->Count == 0) {
		MessageBox::Show("No hay datos en la tabla para actualizar.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	ControladorInventario^ controlador = gcnew ControladorInventario();
	int filasActualizadas = 0;


	for (int i = 0; i < this->dgvInventario->Rows->Count; i++) {
		
		String^ nombreProducto = this->dgvInventario->Rows[i]->Cells[0]->Value->ToString();
		int nuevaCantidad = Convert::ToInt32(this->dgvInventario->Rows[i]->Cells[1]->Value);

		
		int idTiendaSeleccionada = (this->cmbTienda->SelectedIndex == 0) ? 1 : 2;

		
		bool exito = controlador->actualizarStockProducto(nombreProducto, nuevaCantidad, idTiendaSeleccionada);

		if (exito) {
			filasActualizadas++;
		}
	}

	if (filasActualizadas > 0) {
		MessageBox::Show("¡Inventario actualizado con éxito en la Base de Datos!", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		btnVerificar_Click(sender, e);
	}
	else {
		MessageBox::Show("No se pudieron guardar los cambios. Revisa la conexión.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}