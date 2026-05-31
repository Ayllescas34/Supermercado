#pragma once
#include "ControladorVenta.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmHistorialVentas : public System::Windows::Forms::Form
	{
	private:
		ControladorVenta^ controlador;

	public:
		frmHistorialVentas(void)
		{
			InitializeComponent();
			controlador = gcnew ControladorVenta();
		}

	protected:
		~frmHistorialVentas()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DateTimePicker^ dtpDesde;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ dtpHasta;
	private: System::Windows::Forms::Button^ btnFiltrar;
	private: System::Windows::Forms::Button^ btnVerTodo;
	private: System::Windows::Forms::DataGridView^ dgvVentas;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colFecha;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCliente;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCajero;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTotal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colMetodo;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Button^ btnRegresar;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dtpDesde = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dtpHasta = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnFiltrar = (gcnew System::Windows::Forms::Button());
			this->btnVerTodo = (gcnew System::Windows::Forms::Button());
			this->dgvVentas = (gcnew System::Windows::Forms::DataGridView());
			this->colID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCliente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCajero = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colMetodo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->btnRegresar = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvVentas))->BeginInit();
			this->SuspendLayout();

			//FRANJA IZQUIERDA
			this->panel2->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->panel2->Location = System::Drawing::Point(0, 59);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(83, 22);
			this->panel2->TabIndex = 11;

			// TITULO
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Schoolbook", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(30, 30, 30);
			this->label1->Location = System::Drawing::Point(100, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(360, 40);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Historial de Ventas";

			//FRANJA DERECHA
			this->panel1->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->panel1->Location = System::Drawing::Point(461, 59);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(630, 22);
			this->panel1->TabIndex = 10;

			//LABEL DESDE
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(33, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Desde:";

			//DATE PICKER DESDE
			this->dtpDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->dtpDesde->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpDesde->Location = System::Drawing::Point(109, 120);
			this->dtpDesde->Name = L"dtpDesde";
			this->dtpDesde->Size = System::Drawing::Size(140, 28);
			this->dtpDesde->TabIndex = 2;

			//LABEL HASTA
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(33, 165);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Hasta:";

			// DATE PICKER HASTa
			this->dtpHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->dtpHasta->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpHasta->Location = System::Drawing::Point(109, 165);
			this->dtpHasta->Name = L"dtpHasta";
			this->dtpHasta->Size = System::Drawing::Size(140, 28);
			this->dtpHasta->TabIndex = 4;

			// BUTTON FILTRAR
			this->btnFiltrar->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnFiltrar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFiltrar->FlatAppearance->BorderSize = 0;
			this->btnFiltrar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnFiltrar->ForeColor = System::Drawing::Color::White;
			this->btnFiltrar->Location = System::Drawing::Point(26, 215);
			this->btnFiltrar->Name = L"btnFiltrar";
			this->btnFiltrar->Size = System::Drawing::Size(121, 48);
			this->btnFiltrar->TabIndex = 5;
			this->btnFiltrar->Text = L"Filtrar";
			this->btnFiltrar->UseVisualStyleBackColor = false;
			this->btnFiltrar->Click += gcnew System::EventHandler(this, &frmHistorialVentas::btnFiltrar_Click);

			// BUTTON VER TODO 
			this->btnVerTodo->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnVerTodo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVerTodo->FlatAppearance->BorderSize = 0;
			this->btnVerTodo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnVerTodo->ForeColor = System::Drawing::Color::White;
			this->btnVerTodo->Location = System::Drawing::Point(170, 215);
			this->btnVerTodo->Name = L"btnVerTodo";
			this->btnVerTodo->Size = System::Drawing::Size(121, 48);
			this->btnVerTodo->TabIndex = 6;
			this->btnVerTodo->Text = L"Ver Todo";
			this->btnVerTodo->UseVisualStyleBackColor = false;
			this->btnVerTodo->Click += gcnew System::EventHandler(this, &frmHistorialVentas::btnVerTodo_Click);

			//  DATAGRIDVIEW 
			this->dgvVentas->AllowUserToAddRows = false;
			this->dgvVentas->AllowUserToDeleteRows = false;
			this->dgvVentas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvVentas->BackgroundColor = System::Drawing::Color::White;
			this->dgvVentas->ColumnHeadersHeight = 34;
			this->dgvVentas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvVentas->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->dgvVentas->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dgvVentas->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold);
			this->dgvVentas->EnableHeadersVisualStyles = false;
			this->dgvVentas->DefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 10);
			this->dgvVentas->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->dgvVentas->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dgvVentas->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->dgvVentas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colID, this->colFecha,
					this->colCliente, this->colCajero, this->colTotal, this->colMetodo
			});
			this->dgvVentas->Location = System::Drawing::Point(317, 120);
			this->dgvVentas->Name = L"dgvVentas";
			this->dgvVentas->ReadOnly = true;
			this->dgvVentas->RowHeadersVisible = false;
			this->dgvVentas->RowHeadersWidth = 51;
			this->dgvVentas->RowTemplate->Height = 28;
			this->dgvVentas->Size = System::Drawing::Size(738, 310);
			this->dgvVentas->TabIndex = 7;

			// COLUMNS 
			this->colID->DataPropertyName = L"id_venta";
			this->colID->HeaderText = L"ID";
			this->colID->MinimumWidth = 6;
			this->colID->Name = L"colID";
			this->colID->ReadOnly = true;

			this->colFecha->DataPropertyName = L"fecha";
			this->colFecha->HeaderText = L"Fecha";
			this->colFecha->MinimumWidth = 6;
			this->colFecha->Name = L"colFecha";
			this->colFecha->ReadOnly = true;

			this->colCliente->DataPropertyName = L"cliente";
			this->colCliente->HeaderText = L"Cliente";
			this->colCliente->MinimumWidth = 6;
			this->colCliente->Name = L"colCliente";
			this->colCliente->ReadOnly = true;

			this->colCajero->DataPropertyName = L"cajero";
			this->colCajero->HeaderText = L"Cajero";
			this->colCajero->MinimumWidth = 6;
			this->colCajero->Name = L"colCajero";
			this->colCajero->ReadOnly = true;

			this->colTotal->DataPropertyName = L"total";
			this->colTotal->HeaderText = L"Total";
			this->colTotal->MinimumWidth = 6;
			this->colTotal->Name = L"colTotal";
			this->colTotal->ReadOnly = true;

			this->colMetodo->DataPropertyName = L"metodo_pago";
			this->colMetodo->HeaderText = L"Método";
			this->colMetodo->MinimumWidth = 6;
			this->colMetodo->Name = L"colMetodo";
			this->colMetodo->ReadOnly = true;

			// LABEL TOTAL
			this->lblTotal->AutoSize = true;
			this->lblTotal->BackColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblTotal->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblTotal->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblTotal->Location = System::Drawing::Point(650, 445);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(220, 25);
			this->lblTotal->TabIndex = 8;
			this->lblTotal->Text = L"Total del período: Q 0.00";

			// BUTTON REGRESAR 
			this->btnRegresar->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->btnRegresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegresar->FlatAppearance->BorderSize = 0;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnRegresar->ForeColor = System::Drawing::Color::White;
			this->btnRegresar->Location = System::Drawing::Point(26, 385);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(265, 55);
			this->btnRegresar->TabIndex = 9;
			this->btnRegresar->Text = L"Regresar al Menú";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmHistorialVentas::btnRegresar_Click);

			// FORM 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->ClientSize = System::Drawing::Size(1091, 480);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnRegresar);
			this->Controls->Add(this->lblTotal);
			this->Controls->Add(this->dgvVentas);
			this->Controls->Add(this->btnVerTodo);
			this->Controls->Add(this->btnFiltrar);
			this->Controls->Add(this->dtpHasta);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dtpDesde);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"frmHistorialVentas";
			this->Text = L"Historial de Ventas";
			this->Load += gcnew System::EventHandler(this, &frmHistorialVentas::frmHistorialVentas_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvVentas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		void CargarVentas(DataTable^ datos) {
			if (datos == nullptr || datos->Rows->Count == 0) {
				dgvVentas->DataSource = nullptr;
				lblTotal->Text = "Total del período: Q 0.00";
				MessageBox::Show("No se encontraron ventas.", "Información",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			dgvVentas->DataSource = datos;

			double totalPeriodo = 0.0;
			for each (DataRow ^ fila in datos->Rows) {
				totalPeriodo += Convert::ToDouble(fila["total"]);
			}

			lblTotal->Text = String::Format("Total del período: Q {0:N2}", totalPeriodo);
		}

		System::Void frmHistorialVentas_Load(System::Object^ sender, System::EventArgs^ e) {
			DataTable^ todasVentas = controlador->listarVentas();
			CargarVentas(todasVentas);
		}

		System::Void btnVerTodo_Click(System::Object^ sender, System::EventArgs^ e) {
			DataTable^ todasVentas = controlador->listarVentas();
			CargarVentas(todasVentas);
		}

		System::Void btnFiltrar_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dtpDesde->Value > dtpHasta->Value) {
				MessageBox::Show("La fecha 'Desde' no puede ser mayor que 'Hasta'.",
					"Error de validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ fechaDesde = dtpDesde->Value.ToString("yyyy-MM-dd");
			String^ fechaHasta = dtpHasta->Value.ToString("yyyy-MM-dd");

			DataTable^ ventasFiltradas = controlador->listarVentasPorFecha(fechaDesde, fechaHasta);
			CargarVentas(ventasFiltradas);
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}