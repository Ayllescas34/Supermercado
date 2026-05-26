#pragma once
#include "ControladorVenta.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Formulario de Historial de Ventas
	/// Muestra todas las ventas o filtra por rango de fechas
	/// </summary>
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
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
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

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvVentas))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(48, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Historial de Ventas";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(33, 118);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Desde:";
			// 
			// dtpDesde
			// 
			this->dtpDesde->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpDesde->Location = System::Drawing::Point(109, 118);
			this->dtpDesde->Name = L"dtpDesde";
			this->dtpDesde->Size = System::Drawing::Size(100, 22);
			this->dtpDesde->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(33, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 19);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Hasta";
			// 
			// dtpHasta
			// 
			this->dtpHasta->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpHasta->Location = System::Drawing::Point(109, 168);
			this->dtpHasta->Name = L"dtpHasta";
			this->dtpHasta->Size = System::Drawing::Size(100, 22);
			this->dtpHasta->TabIndex = 4;
			// 
			// btnFiltrar
			// 
			this->btnFiltrar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnFiltrar->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFiltrar->Location = System::Drawing::Point(22, 213);
			this->btnFiltrar->Name = L"btnFiltrar";
			this->btnFiltrar->Size = System::Drawing::Size(121, 46);
			this->btnFiltrar->TabIndex = 5;
			this->btnFiltrar->Text = L"Filtrar";
			this->btnFiltrar->UseVisualStyleBackColor = false;
			this->btnFiltrar->Click += gcnew System::EventHandler(this, &frmHistorialVentas::btnFiltrar_Click);
			// 
			// btnVerTodo
			// 
			this->btnVerTodo->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnVerTodo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVerTodo->Location = System::Drawing::Point(170, 213);
			this->btnVerTodo->Name = L"btnVerTodo";
			this->btnVerTodo->Size = System::Drawing::Size(121, 46);
			this->btnVerTodo->TabIndex = 6;
			this->btnVerTodo->Text = L"Ver Todo";
			this->btnVerTodo->UseVisualStyleBackColor = false;
			this->btnVerTodo->Click += gcnew System::EventHandler(this, &frmHistorialVentas::btnVerTodo_Click);
			// 
			// dgvVentas
			// 
			this->dgvVentas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvVentas->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dgvVentas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvVentas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colID, this->colFecha,
					this->colCliente, this->colCajero, this->colTotal, this->colMetodo
			});
			this->dgvVentas->Location = System::Drawing::Point(337, 111);
			this->dgvVentas->Name = L"dgvVentas";
			this->dgvVentas->ReadOnly = true;
			this->dgvVentas->RowHeadersVisible = false;
			this->dgvVentas->RowHeadersWidth = 51;
			this->dgvVentas->RowTemplate->Height = 24;
			this->dgvVentas->Size = System::Drawing::Size(672, 262);
			this->dgvVentas->TabIndex = 7;
			// 
			// colID
			// 
			this->colID->DataPropertyName = L"id_venta";
			this->colID->HeaderText = L"ID";
			this->colID->MinimumWidth = 6;
			this->colID->Name = L"colID";
			this->colID->ReadOnly = true;
			// 
			// colFecha
			// 
			this->colFecha->DataPropertyName = L"fecha";
			this->colFecha->HeaderText = L"Fecha";
			this->colFecha->MinimumWidth = 6;
			this->colFecha->Name = L"colFecha";
			this->colFecha->ReadOnly = true;
			// 
			// colCliente
			// 
			this->colCliente->DataPropertyName = L"cliente";
			this->colCliente->HeaderText = L"Cliente";
			this->colCliente->MinimumWidth = 6;
			this->colCliente->Name = L"colCliente";
			this->colCliente->ReadOnly = true;
			// 
			// colCajero
			// 
			this->colCajero->DataPropertyName = L"cajero";
			this->colCajero->HeaderText = L"Cajero";
			this->colCajero->MinimumWidth = 6;
			this->colCajero->Name = L"colCajero";
			this->colCajero->ReadOnly = true;
			// 
			// colTotal
			// 
			this->colTotal->DataPropertyName = L"total";
			this->colTotal->HeaderText = L"Total";
			this->colTotal->MinimumWidth = 6;
			this->colTotal->Name = L"colTotal";
			this->colTotal->ReadOnly = true;
			// 
			// colMetodo
			// 
			this->colMetodo->DataPropertyName = L"metodo_pago";
			this->colMetodo->HeaderText = L"Método";
			this->colMetodo->MinimumWidth = 6;
			this->colMetodo->Name = L"colMetodo";
			this->colMetodo->ReadOnly = true;
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->BackColor = System::Drawing::Color::Thistle;
			this->lblTotal->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotal->Location = System::Drawing::Point(805, 399);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(168, 19);
			this->lblTotal->TabIndex = 8;
			this->lblTotal->Text = L"Total del periodo: Q 0.00";
			// 
			// btnRegresar
			// 
			this->btnRegresar->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresar->Location = System::Drawing::Point(54, 365);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(204, 46);
			this->btnRegresar->TabIndex = 9;
			this->btnRegresar->Text = L"Regresar al Menú";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmHistorialVentas::btnRegresar_Click);
			// 
			// frmHistorialVentas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1091, 469);
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
		// ============================================================
		// MÉTODO PRINCIPAL: Carga datos desde la DB al DataGridView
		// ============================================================
		void CargarVentas(DataTable^ datos) {
			if (datos == nullptr || datos->Rows->Count == 0) {
				dgvVentas->DataSource = nullptr;
				lblTotal->Text = "Total del periodo: Q 0.00";
				MessageBox::Show("No se encontraron ventas.", "Información",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			// Asignar datos al DataGridView
			dgvVentas->DataSource = datos;

			// Calcular el total sumando la columna "total"
			double totalPeriodo = 0.0;
			for each (DataRow ^ fila in datos->Rows) {
				totalPeriodo += Convert::ToDouble(fila["total"]);
			}

			// Mostrar total con formato Q ###.##
			lblTotal->Text = String::Format("Total del periodo: Q {0:N2}", totalPeriodo);
		}

		// ============================================================
		// Al cargar el formulario, muestra todas las ventas
		// ============================================================
		System::Void frmHistorialVentas_Load(System::Object^ sender, System::EventArgs^ e) {
			DataTable^ todasVentas = controlador->listarVentas();
			CargarVentas(todasVentas);
		}

		// ============================================================
		// Botón "Ver Todo" — recarga todas las ventas
		// ============================================================
		System::Void btnVerTodo_Click(System::Object^ sender, System::EventArgs^ e) {
			DataTable^ todasVentas = controlador->listarVentas();
			CargarVentas(todasVentas);
		}

		// ============================================================
		// Botón "Filtrar" — ventas por rango de fechas
		// ============================================================
		System::Void btnFiltrar_Click(System::Object^ sender, System::EventArgs^ e) {
			// Validar que la fecha "Desde" sea menor o igual a "Hasta"
			if (dtpDesde->Value > dtpHasta->Value) {
				MessageBox::Show("La fecha 'Desde' no puede ser mayor que 'Hasta'.",
					"Error de validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// Convertir fechas a formato MySQL: yyyy-MM-dd
			String^ fechaDesde = dtpDesde->Value.ToString("yyyy-MM-dd");
			String^ fechaHasta = dtpHasta->Value.ToString("yyyy-MM-dd");

			// Consultar controlador
			DataTable^ ventasFiltradas = controlador->listarVentasPorFecha(fechaDesde, fechaHasta);
			CargarVentas(ventasFiltradas);
		}

		// ============================================================
		// Botón "Regresar" — cierra el formulario
		// ============================================================
		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}