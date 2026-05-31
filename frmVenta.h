#pragma once
#include "Globals.h"
#include "frmClienteRapido.h"
#include "ControladorVenta.h"
#include "ControladorCliente.h"
#include "ControladorProducto.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmVenta : public System::Windows::Forms::Form
	{
	public:
		frmVenta(void)
		{
			InitializeComponent();
		}

	protected:
		~frmVenta()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ lblTienda;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblCajero;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblPaso1;
	private: System::Windows::Forms::Label^ lblPaso2;
	private: System::Windows::Forms::Label^ lblPaso3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtBuscarCliente;
	private: System::Windows::Forms::Button^ btnBuscarCliente;
	private: System::Windows::Forms::Button^ btnCF;
	private: System::Windows::Forms::DataGridView^ dgvClientes;
	private: System::Windows::Forms::Label^ lblClienteNoEncontrado;
	private: System::Windows::Forms::Button^ btnCrearCliente;
	private: System::Windows::Forms::Label^ lblClienteSeleccionado;
	private: System::Windows::Forms::Button^ btnSiguientePaso1;
	private: System::Windows::Forms::Button^ btnRegresar;

	private:
		int idClienteSeleccionado = 0;
		String^ nombreClienteSeleccionado = "";

	private: System::Windows::Forms::Panel^ panelProductos;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridView^ dgvProductos;
	private: System::Windows::Forms::Button^ btnBuscarProducto;
	private: System::Windows::Forms::TextBox^ txtBuscarProducto;
	private: System::Windows::Forms::Label^ lblUltimoAgregado;
	private: System::Windows::Forms::Button^ btnDeshacer;
	private: System::Windows::Forms::Button^ btnAgregar;
	private: System::Windows::Forms::TextBox^ txtCantidad;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ dgvCarrito;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Label^ lblIVA;
	private: System::Windows::Forms::Label^ lblSubtotal;
	private: System::Windows::Forms::Button^ btnSiguientePaso2;
	private: System::Windows::Forms::Button^ btnLimpiarCarrito;
	private: System::Windows::Forms::Button^ btnVolverPaso1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ lblClienteActivo;

	private:
		ref struct Item {
			int idProducto;
			String^ nombre;
			int cantidad;
			double precio;
			double subtotal;
		};

		System::Collections::Generic::List<Item^>^ carrito;
		System::Collections::Generic::Stack<Item^>^ historial;

		int idProductoSeleccionado = 0;
		String^ nombreProductoSeleccionado = "";
		double precioProductoSeleccionado = 0.0;

	private: System::Windows::Forms::Panel^ panelPago;
	private: System::Windows::Forms::Button^ btnCancelarVenta;
	private: System::Windows::Forms::Label^ lblResumenCajero;
	private: System::Windows::Forms::Label^ lblResumenCliente;
	private: System::Windows::Forms::Label^ lblCambio;
	private: System::Windows::Forms::TextBox^ txtMontoRecibido;
	private: System::Windows::Forms::Label^ lblMontoRecibido;
	private: System::Windows::Forms::RadioButton^ rbTarjeta;
	private: System::Windows::Forms::RadioButton^ rbEfectivo;
	private: System::Windows::Forms::Button^ btnConfirmarVenta;
	private: System::Windows::Forms::Button^ btnVolverPaso2;
	private: System::Windows::Forms::Label^ lblResumenTotal;
	private: System::Windows::Forms::Label^ lblResumenIVA;
	private: System::Windows::Forms::Label^ lblResumenSubtotal;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label14;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lblTienda = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblCajero = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblPaso1 = (gcnew System::Windows::Forms::Label());
			this->lblPaso2 = (gcnew System::Windows::Forms::Label());
			this->lblPaso3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtBuscarCliente = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscarCliente = (gcnew System::Windows::Forms::Button());
			this->btnCF = (gcnew System::Windows::Forms::Button());
			this->dgvClientes = (gcnew System::Windows::Forms::DataGridView());
			this->lblClienteNoEncontrado = (gcnew System::Windows::Forms::Label());
			this->btnCrearCliente = (gcnew System::Windows::Forms::Button());
			this->lblClienteSeleccionado = (gcnew System::Windows::Forms::Label());
			this->btnSiguientePaso1 = (gcnew System::Windows::Forms::Button());
			this->btnRegresar = (gcnew System::Windows::Forms::Button());
			this->panelProductos = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->lblClienteActivo = (gcnew System::Windows::Forms::Label());
			this->btnSiguientePaso2 = (gcnew System::Windows::Forms::Button());
			this->btnLimpiarCarrito = (gcnew System::Windows::Forms::Button());
			this->btnVolverPaso1 = (gcnew System::Windows::Forms::Button());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->lblIVA = (gcnew System::Windows::Forms::Label());
			this->lblSubtotal = (gcnew System::Windows::Forms::Label());
			this->dgvCarrito = (gcnew System::Windows::Forms::DataGridView());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->lblUltimoAgregado = (gcnew System::Windows::Forms::Label());
			this->btnDeshacer = (gcnew System::Windows::Forms::Button());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->txtCantidad = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dgvProductos = (gcnew System::Windows::Forms::DataGridView());
			this->btnBuscarProducto = (gcnew System::Windows::Forms::Button());
			this->txtBuscarProducto = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panelPago = (gcnew System::Windows::Forms::Panel());
			this->btnCancelarVenta = (gcnew System::Windows::Forms::Button());
			this->lblResumenCajero = (gcnew System::Windows::Forms::Label());
			this->lblResumenCliente = (gcnew System::Windows::Forms::Label());
			this->lblCambio = (gcnew System::Windows::Forms::Label());
			this->txtMontoRecibido = (gcnew System::Windows::Forms::TextBox());
			this->lblMontoRecibido = (gcnew System::Windows::Forms::Label());
			this->rbTarjeta = (gcnew System::Windows::Forms::RadioButton());
			this->rbEfectivo = (gcnew System::Windows::Forms::RadioButton());
			this->btnConfirmarVenta = (gcnew System::Windows::Forms::Button());
			this->btnVolverPaso2 = (gcnew System::Windows::Forms::Button());
			this->lblResumenTotal = (gcnew System::Windows::Forms::Label());
			this->lblResumenIVA = (gcnew System::Windows::Forms::Label());
			this->lblResumenSubtotal = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClientes))->BeginInit();
			this->panelProductos->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCarrito))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->BeginInit();
			this->panelPago->SuspendLayout();
			this->SuspendLayout();

			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nueva Venta";

			this->panel1->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(882, 40);
			this->panel1->TabIndex = 1;

			this->panel2->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->panel2->Controls->Add(this->lblTienda);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->lblCajero);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(20, 46);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(840, 30);
			this->panel2->TabIndex = 2;

			this->lblTienda->AutoSize = true;
			this->lblTienda->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblTienda->ForeColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->lblTienda->Location = System::Drawing::Point(407, 7);
			this->lblTienda->Name = L"lblTienda";
			this->lblTienda->Size = System::Drawing::Size(14, 17);
			this->lblTienda->TabIndex = 4;
			this->lblTienda->Text = L"-";

			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->label3->Location = System::Drawing::Point(289, 6);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 17);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Tienda:";

			this->lblCajero->AutoSize = true;
			this->lblCajero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblCajero->ForeColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->lblCajero->Location = System::Drawing::Point(119, 6);
			this->lblCajero->Name = L"lblCajero";
			this->lblCajero->Size = System::Drawing::Size(14, 17);
			this->lblCajero->TabIndex = 2;
			this->lblCajero->Text = L"-";

			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->label2->Location = System::Drawing::Point(22, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Cajero:";

			this->lblPaso1->AutoSize = true;
			this->lblPaso1->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->lblPaso1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPaso1->ForeColor = System::Drawing::Color::White;
			this->lblPaso1->Location = System::Drawing::Point(42, 95);
			this->lblPaso1->Name = L"lblPaso1";
			this->lblPaso1->Size = System::Drawing::Size(79, 18);
			this->lblPaso1->TabIndex = 3;
			this->lblPaso1->Text = L"1. Cliente";

			this->lblPaso2->AutoSize = true;
			this->lblPaso2->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->lblPaso2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPaso2->ForeColor = System::Drawing::Color::White;
			this->lblPaso2->Location = System::Drawing::Point(139, 95);
			this->lblPaso2->Name = L"lblPaso2";
			this->lblPaso2->Size = System::Drawing::Size(105, 18);
			this->lblPaso2->TabIndex = 4;
			this->lblPaso2->Text = L"2. Productos";

			this->lblPaso3->AutoSize = true;
			this->lblPaso3->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->lblPaso3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPaso3->ForeColor = System::Drawing::Color::White;
			this->lblPaso3->Location = System::Drawing::Point(260, 95);
			this->lblPaso3->Name = L"lblPaso3";
			this->lblPaso3->Size = System::Drawing::Size(66, 18);
			this->lblPaso3->TabIndex = 5;
			this->lblPaso3->Text = L"3. Pago";

			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->label4->Location = System::Drawing::Point(42, 168);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 18);
			this->label4->TabIndex = 6;
			this->label4->Text = L"NIT o Nombre:";

			this->txtBuscarCliente->Location = System::Drawing::Point(200, 168);
			this->txtBuscarCliente->Name = L"txtBuscarCliente";
			this->txtBuscarCliente->Size = System::Drawing::Size(165, 22);
			this->txtBuscarCliente->TabIndex = 7;

			this->btnBuscarCliente->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnBuscarCliente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBuscarCliente->FlatAppearance->BorderSize = 0;
			this->btnBuscarCliente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnBuscarCliente->ForeColor = System::Drawing::Color::White;
			this->btnBuscarCliente->Location = System::Drawing::Point(392, 164);
			this->btnBuscarCliente->Name = L"btnBuscarCliente";
			this->btnBuscarCliente->Size = System::Drawing::Size(75, 28);
			this->btnBuscarCliente->TabIndex = 8;
			this->btnBuscarCliente->Text = L"Buscar";
			this->btnBuscarCliente->UseVisualStyleBackColor = false;
			this->btnBuscarCliente->Click += gcnew System::EventHandler(this, &frmVenta::btnBuscarCliente_Click);

			this->btnCF->BackColor = System::Drawing::Color::DarkOrange;
			this->btnCF->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCF->FlatAppearance->BorderSize = 0;
			this->btnCF->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnCF->ForeColor = System::Drawing::Color::White;
			this->btnCF->Location = System::Drawing::Point(485, 164);
			this->btnCF->Name = L"btnCF";
			this->btnCF->Size = System::Drawing::Size(188, 28);
			this->btnCF->TabIndex = 9;
			this->btnCF->Text = L"CF — Consumidor Final";
			this->btnCF->UseVisualStyleBackColor = false;
			this->btnCF->Click += gcnew System::EventHandler(this, &frmVenta::btnCF_Click);

			this->dgvClientes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvClientes->Location = System::Drawing::Point(20, 236);
			this->dgvClientes->Name = L"dgvClientes";
			this->dgvClientes->RowHeadersWidth = 51;
			this->dgvClientes->RowTemplate->Height = 24;
			this->dgvClientes->Size = System::Drawing::Size(840, 165);
			this->dgvClientes->TabIndex = 10;
			this->dgvClientes->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmVenta::dgvClientes_CellClick);

			this->lblClienteNoEncontrado->AutoSize = true;
			this->lblClienteNoEncontrado->BackColor = System::Drawing::Color::Tomato;
			this->lblClienteNoEncontrado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblClienteNoEncontrado->ForeColor = System::Drawing::Color::White;
			this->lblClienteNoEncontrado->Location = System::Drawing::Point(65, 432);
			this->lblClienteNoEncontrado->Name = L"lblClienteNoEncontrado";
			this->lblClienteNoEncontrado->Size = System::Drawing::Size(0, 18);
			this->lblClienteNoEncontrado->TabIndex = 11;
			this->lblClienteNoEncontrado->Visible = false;

			this->btnCrearCliente->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnCrearCliente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCrearCliente->FlatAppearance->BorderSize = 0;
			this->btnCrearCliente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnCrearCliente->ForeColor = System::Drawing::Color::White;
			this->btnCrearCliente->Location = System::Drawing::Point(650, 419);
			this->btnCrearCliente->Name = L"btnCrearCliente";
			this->btnCrearCliente->Size = System::Drawing::Size(190, 31);
			this->btnCrearCliente->TabIndex = 12;
			this->btnCrearCliente->Text = L"+ Crear cliente";
			this->btnCrearCliente->UseVisualStyleBackColor = false;
			this->btnCrearCliente->Click += gcnew System::EventHandler(this, &frmVenta::btnCrearCliente_Click);

			this->lblClienteSeleccionado->AutoSize = true;
			this->lblClienteSeleccionado->BackColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblClienteSeleccionado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblClienteSeleccionado->ForeColor = System::Drawing::Color::FromArgb(50, 50, 50);
			this->lblClienteSeleccionado->Location = System::Drawing::Point(65, 478);
			this->lblClienteSeleccionado->Name = L"lblClienteSeleccionado";
			this->lblClienteSeleccionado->Size = System::Drawing::Size(0, 18);
			this->lblClienteSeleccionado->TabIndex = 13;
			this->lblClienteSeleccionado->Visible = false;

			this->btnSiguientePaso1->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnSiguientePaso1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSiguientePaso1->FlatAppearance->BorderSize = 0;
			this->btnSiguientePaso1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnSiguientePaso1->ForeColor = System::Drawing::Color::White;
			this->btnSiguientePaso1->Location = System::Drawing::Point(625, 493);
			this->btnSiguientePaso1->Name = L"btnSiguientePaso1";
			this->btnSiguientePaso1->Size = System::Drawing::Size(235, 48);
			this->btnSiguientePaso1->TabIndex = 14;
			this->btnSiguientePaso1->Text = L"Siguiente ->";
			this->btnSiguientePaso1->UseVisualStyleBackColor = false;
			this->btnSiguientePaso1->Click += gcnew System::EventHandler(this, &frmVenta::btnSiguientePaso1_Click);

			this->btnRegresar->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->btnRegresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnRegresar->ForeColor = System::Drawing::Color::White;
			this->btnRegresar->Location = System::Drawing::Point(20, 500);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(180, 48);
			this->btnRegresar->TabIndex = 15;
			this->btnRegresar->Text = L"<- Regresar al Menu";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmVenta::btnRegresar_Click);

			this->panelProductos->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->panelProductos->Controls->Add(this->panel3);
			this->panelProductos->Controls->Add(this->btnSiguientePaso2);
			this->panelProductos->Controls->Add(this->btnLimpiarCarrito);
			this->panelProductos->Controls->Add(this->btnVolverPaso1);
			this->panelProductos->Controls->Add(this->lblTotal);
			this->panelProductos->Controls->Add(this->lblIVA);
			this->panelProductos->Controls->Add(this->lblSubtotal);
			this->panelProductos->Controls->Add(this->dgvCarrito);
			this->panelProductos->Controls->Add(this->label7);
			this->panelProductos->Controls->Add(this->lblUltimoAgregado);
			this->panelProductos->Controls->Add(this->btnDeshacer);
			this->panelProductos->Controls->Add(this->btnAgregar);
			this->panelProductos->Controls->Add(this->txtCantidad);
			this->panelProductos->Controls->Add(this->label6);
			this->panelProductos->Controls->Add(this->dgvProductos);
			this->panelProductos->Controls->Add(this->btnBuscarProducto);
			this->panelProductos->Controls->Add(this->txtBuscarProducto);
			this->panelProductos->Controls->Add(this->label5);
			this->panelProductos->Location = System::Drawing::Point(0, 45);
			this->panelProductos->Name = L"panelProductos";
			this->panelProductos->Size = System::Drawing::Size(882, 498);
			this->panelProductos->TabIndex = 15;
			this->panelProductos->Visible = false;

			this->panel3->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->panel3->Controls->Add(this->lblClienteActivo);
			this->panel3->Location = System::Drawing::Point(25, 14);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(840, 30);
			this->panel3->TabIndex = 18;

			this->lblClienteActivo->AutoSize = true;
			this->lblClienteActivo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblClienteActivo->ForeColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->lblClienteActivo->Location = System::Drawing::Point(364, 3);
			this->lblClienteActivo->Name = L"lblClienteActivo";
			this->lblClienteActivo->Size = System::Drawing::Size(14, 17);
			this->lblClienteActivo->TabIndex = 6;
			this->lblClienteActivo->Text = L"-";

			this->btnSiguientePaso2->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnSiguientePaso2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSiguientePaso2->FlatAppearance->BorderSize = 0;
			this->btnSiguientePaso2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnSiguientePaso2->ForeColor = System::Drawing::Color::White;
			this->btnSiguientePaso2->Location = System::Drawing::Point(727, 417);
			this->btnSiguientePaso2->Name = L"btnSiguientePaso2";
			this->btnSiguientePaso2->Size = System::Drawing::Size(113, 26);
			this->btnSiguientePaso2->TabIndex = 17;
			this->btnSiguientePaso2->Text = L"Ir a Pago ->";
			this->btnSiguientePaso2->UseVisualStyleBackColor = false;
			this->btnSiguientePaso2->Click += gcnew System::EventHandler(this, &frmVenta::btnSiguientePaso2_Click);

			this->btnLimpiarCarrito->BackColor = System::Drawing::Color::FromArgb(150, 150, 150);
			this->btnLimpiarCarrito->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLimpiarCarrito->FlatAppearance->BorderSize = 0;
			this->btnLimpiarCarrito->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnLimpiarCarrito->ForeColor = System::Drawing::Color::White;
			this->btnLimpiarCarrito->Location = System::Drawing::Point(601, 417);
			this->btnLimpiarCarrito->Name = L"btnLimpiarCarrito";
			this->btnLimpiarCarrito->Size = System::Drawing::Size(120, 26);
			this->btnLimpiarCarrito->TabIndex = 16;
			this->btnLimpiarCarrito->Text = L"Limpiar todo";
			this->btnLimpiarCarrito->UseVisualStyleBackColor = false;
			this->btnLimpiarCarrito->Click += gcnew System::EventHandler(this, &frmVenta::btnLimpiarCarrito_Click);

			this->btnVolverPaso1->BackColor = System::Drawing::Color::FromArgb(150, 150, 150);
			this->btnVolverPaso1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVolverPaso1->FlatAppearance->BorderSize = 0;
			this->btnVolverPaso1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnVolverPaso1->ForeColor = System::Drawing::Color::White;
			this->btnVolverPaso1->Location = System::Drawing::Point(392, 416);
			this->btnVolverPaso1->Name = L"btnVolverPaso1";
			this->btnVolverPaso1->Size = System::Drawing::Size(96, 26);
			this->btnVolverPaso1->TabIndex = 15;
			this->btnVolverPaso1->Text = L"<- Volver";
			this->btnVolverPaso1->UseVisualStyleBackColor = false;
			this->btnVolverPaso1->Click += gcnew System::EventHandler(this, &frmVenta::btnVolverPaso1_Click);

			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblTotal->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblTotal->Location = System::Drawing::Point(389, 361);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(120, 18);
			this->lblTotal->TabIndex = 14;
			this->lblTotal->Text = L"TOTAL: Q 0.00";

			this->lblIVA->AutoSize = true;
			this->lblIVA->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblIVA->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblIVA->Location = System::Drawing::Point(389, 339);
			this->lblIVA->Name = L"lblIVA";
			this->lblIVA->Size = System::Drawing::Size(141, 18);
			this->lblIVA->TabIndex = 13;
			this->lblIVA->Text = L"IVA (12%): Q 0.00";

			this->lblSubtotal->AutoSize = true;
			this->lblSubtotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblSubtotal->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblSubtotal->Location = System::Drawing::Point(389, 317);
			this->lblSubtotal->Name = L"lblSubtotal";
			this->lblSubtotal->Size = System::Drawing::Size(130, 18);
			this->lblSubtotal->TabIndex = 12;
			this->lblSubtotal->Text = L"Subtotal: Q 0.00";

			this->dgvCarrito->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCarrito->Location = System::Drawing::Point(392, 130);
			this->dgvCarrito->Name = L"dgvCarrito";
			this->dgvCarrito->RowHeadersWidth = 51;
			this->dgvCarrito->RowTemplate->Height = 24;
			this->dgvCarrito->Size = System::Drawing::Size(448, 150);
			this->dgvCarrito->TabIndex = 10;

			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(389, 108);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(60, 18);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Carrito";

			this->lblUltimoAgregado->AutoSize = true;
			this->lblUltimoAgregado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lblUltimoAgregado->Location = System::Drawing::Point(137, 471);
			this->lblUltimoAgregado->Name = L"lblUltimoAgregado";
			this->lblUltimoAgregado->Size = System::Drawing::Size(0, 17);
			this->lblUltimoAgregado->TabIndex = 8;

			this->btnDeshacer->BackColor = System::Drawing::Color::FromArgb(255, 180, 100);
			this->btnDeshacer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeshacer->FlatAppearance->BorderSize = 0;
			this->btnDeshacer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnDeshacer->ForeColor = System::Drawing::Color::White;
			this->btnDeshacer->Location = System::Drawing::Point(47, 428);
			this->btnDeshacer->Name = L"btnDeshacer";
			this->btnDeshacer->Size = System::Drawing::Size(260, 33);
			this->btnDeshacer->TabIndex = 7;
			this->btnDeshacer->Text = L"Deshacer ultimo";
			this->btnDeshacer->UseVisualStyleBackColor = false;
			this->btnDeshacer->Click += gcnew System::EventHandler(this, &frmVenta::btnDeshacer_Click);

			this->btnAgregar->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnAgregar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAgregar->FlatAppearance->BorderSize = 0;
			this->btnAgregar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnAgregar->ForeColor = System::Drawing::Color::White;
			this->btnAgregar->Location = System::Drawing::Point(47, 388);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(260, 33);
			this->btnAgregar->TabIndex = 6;
			this->btnAgregar->Text = L"+ Agregar al carrito";
			this->btnAgregar->UseVisualStyleBackColor = false;
			this->btnAgregar->Click += gcnew System::EventHandler(this, &frmVenta::btnAgregar_Click);

			this->txtCantidad->Location = System::Drawing::Point(147, 357);
			this->txtCantidad->Name = L"txtCantidad";
			this->txtCantidad->Size = System::Drawing::Size(138, 22);
			this->txtCantidad->TabIndex = 5;
			this->txtCantidad->Text = L"1";

			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->label6->Location = System::Drawing::Point(64, 360);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 17);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Cantidad:";

			this->dgvProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProductos->Location = System::Drawing::Point(12, 192);
			this->dgvProductos->Name = L"dgvProductos";
			this->dgvProductos->RowHeadersWidth = 51;
			this->dgvProductos->RowTemplate->Height = 24;
			this->dgvProductos->Size = System::Drawing::Size(360, 160);
			this->dgvProductos->TabIndex = 3;
			this->dgvProductos->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmVenta::dgvProductos_CellClick);

			this->btnBuscarProducto->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnBuscarProducto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBuscarProducto->FlatAppearance->BorderSize = 0;
			this->btnBuscarProducto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnBuscarProducto->ForeColor = System::Drawing::Color::White;
			this->btnBuscarProducto->Location = System::Drawing::Point(189, 141);
			this->btnBuscarProducto->Name = L"btnBuscarProducto";
			this->btnBuscarProducto->Size = System::Drawing::Size(96, 26);
			this->btnBuscarProducto->TabIndex = 2;
			this->btnBuscarProducto->Text = L"Buscar";
			this->btnBuscarProducto->UseVisualStyleBackColor = false;
			this->btnBuscarProducto->Click += gcnew System::EventHandler(this, &frmVenta::btnBuscarProducto_Click);

			this->txtBuscarProducto->Location = System::Drawing::Point(45, 145);
			this->txtBuscarProducto->Name = L"txtBuscarProducto";
			this->txtBuscarProducto->Size = System::Drawing::Size(138, 22);
			this->txtBuscarProducto->TabIndex = 1;

			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(42, 108);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(147, 18);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Codigo o Nombre:";

			this->panelPago->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->panelPago->Controls->Add(this->btnCancelarVenta);
			this->panelPago->Controls->Add(this->lblResumenCajero);
			this->panelPago->Controls->Add(this->lblResumenCliente);
			this->panelPago->Controls->Add(this->lblCambio);
			this->panelPago->Controls->Add(this->txtMontoRecibido);
			this->panelPago->Controls->Add(this->lblMontoRecibido);
			this->panelPago->Controls->Add(this->rbTarjeta);
			this->panelPago->Controls->Add(this->rbEfectivo);
			this->panelPago->Controls->Add(this->btnConfirmarVenta);
			this->panelPago->Controls->Add(this->btnVolverPaso2);
			this->panelPago->Controls->Add(this->lblResumenTotal);
			this->panelPago->Controls->Add(this->lblResumenIVA);
			this->panelPago->Controls->Add(this->lblResumenSubtotal);
			this->panelPago->Controls->Add(this->label11);
			this->panelPago->Controls->Add(this->label12);
			this->panelPago->Controls->Add(this->label14);
			this->panelPago->Location = System::Drawing::Point(1, -3);
			this->panelPago->Name = L"panelPago";
			this->panelPago->Size = System::Drawing::Size(879, 546);
			this->panelPago->TabIndex = 16;
			this->panelPago->Visible = false;

			this->btnCancelarVenta->BackColor = System::Drawing::Color::FromArgb(180, 50, 50);
			this->btnCancelarVenta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancelarVenta->FlatAppearance->BorderSize = 0;
			this->btnCancelarVenta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnCancelarVenta->ForeColor = System::Drawing::Color::White;
			this->btnCancelarVenta->Location = System::Drawing::Point(536, 364);
			this->btnCancelarVenta->Name = L"btnCancelarVenta";
			this->btnCancelarVenta->Size = System::Drawing::Size(120, 26);
			this->btnCancelarVenta->TabIndex = 56;
			this->btnCancelarVenta->Text = L"Cancelar";
			this->btnCancelarVenta->UseVisualStyleBackColor = false;
			this->btnCancelarVenta->Click += gcnew System::EventHandler(this, &frmVenta::btnCancelarVenta_Click);

			this->lblResumenCajero->AutoSize = true;
			this->lblResumenCajero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblResumenCajero->Location = System::Drawing::Point(399, 176);
			this->lblResumenCajero->Name = L"lblResumenCajero";
			this->lblResumenCajero->Size = System::Drawing::Size(0, 18);
			this->lblResumenCajero->TabIndex = 55;

			this->lblResumenCliente->AutoSize = true;
			this->lblResumenCliente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblResumenCliente->Location = System::Drawing::Point(399, 135);
			this->lblResumenCliente->Name = L"lblResumenCliente";
			this->lblResumenCliente->Size = System::Drawing::Size(0, 18);
			this->lblResumenCliente->TabIndex = 54;

			this->lblCambio->AutoSize = true;
			this->lblCambio->BackColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblCambio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCambio->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblCambio->Location = System::Drawing::Point(62, 344);
			this->lblCambio->Name = L"lblCambio";
			this->lblCambio->Size = System::Drawing::Size(97, 16);
			this->lblCambio->TabIndex = 53;
			this->lblCambio->Text = L"Cambio: Q 0.00";

			this->txtMontoRecibido->Location = System::Drawing::Point(65, 234);
			this->txtMontoRecibido->Name = L"txtMontoRecibido";
			this->txtMontoRecibido->Size = System::Drawing::Size(191, 22);
			this->txtMontoRecibido->TabIndex = 52;
			this->txtMontoRecibido->TextChanged += gcnew System::EventHandler(this, &frmVenta::txtMontoRecibido_TextChanged);

			this->lblMontoRecibido->AutoSize = true;
			this->lblMontoRecibido->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMontoRecibido->Location = System::Drawing::Point(60, 207);
			this->lblMontoRecibido->Name = L"lblMontoRecibido";
			this->lblMontoRecibido->Size = System::Drawing::Size(121, 18);
			this->lblMontoRecibido->TabIndex = 51;
			this->lblMontoRecibido->Text = L"Monto recibido";

			this->rbTarjeta->AutoSize = true;
			this->rbTarjeta->Location = System::Drawing::Point(185, 119);
			this->rbTarjeta->Name = L"rbTarjeta";
			this->rbTarjeta->Size = System::Drawing::Size(71, 20);
			this->rbTarjeta->TabIndex = 50;
			this->rbTarjeta->Text = L"Tarjeta";
			this->rbTarjeta->UseVisualStyleBackColor = true;

			this->rbEfectivo->AutoSize = true;
			this->rbEfectivo->Checked = true;
			this->rbEfectivo->Location = System::Drawing::Point(65, 119);
			this->rbEfectivo->Name = L"rbEfectivo";
			this->rbEfectivo->Size = System::Drawing::Size(76, 20);
			this->rbEfectivo->TabIndex = 49;
			this->rbEfectivo->TabStop = true;
			this->rbEfectivo->Text = L"Efectivo";
			this->rbEfectivo->UseVisualStyleBackColor = true;

			this->btnConfirmarVenta->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			this->btnConfirmarVenta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConfirmarVenta->FlatAppearance->BorderSize = 0;
			this->btnConfirmarVenta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnConfirmarVenta->ForeColor = System::Drawing::Color::White;
			this->btnConfirmarVenta->Location = System::Drawing::Point(699, 363);
			this->btnConfirmarVenta->Name = L"btnConfirmarVenta";
			this->btnConfirmarVenta->Size = System::Drawing::Size(140, 26);
			this->btnConfirmarVenta->TabIndex = 48;
			this->btnConfirmarVenta->Text = L"Confirmar Venta";
			this->btnConfirmarVenta->UseVisualStyleBackColor = false;
			this->btnConfirmarVenta->Click += gcnew System::EventHandler(this, &frmVenta::btnConfirmarVenta_Click);

			this->btnVolverPaso2->BackColor = System::Drawing::Color::FromArgb(150, 150, 150);
			this->btnVolverPaso2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnVolverPaso2->FlatAppearance->BorderSize = 0;
			this->btnVolverPaso2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->btnVolverPaso2->ForeColor = System::Drawing::Color::White;
			this->btnVolverPaso2->Location = System::Drawing::Point(404, 363);
			this->btnVolverPaso2->Name = L"btnVolverPaso2";
			this->btnVolverPaso2->Size = System::Drawing::Size(96, 26);
			this->btnVolverPaso2->TabIndex = 47;
			this->btnVolverPaso2->Text = L"<- Volver";
			this->btnVolverPaso2->UseVisualStyleBackColor = false;
			this->btnVolverPaso2->Click += gcnew System::EventHandler(this, &frmVenta::btnVolverPaso2_Click);

			this->lblResumenTotal->AutoSize = true;
			this->lblResumenTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblResumenTotal->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblResumenTotal->Location = System::Drawing::Point(401, 308);
			this->lblResumenTotal->Name = L"lblResumenTotal";
			this->lblResumenTotal->Size = System::Drawing::Size(120, 18);
			this->lblResumenTotal->TabIndex = 46;
			this->lblResumenTotal->Text = L"TOTAL: Q 0.00";

			this->lblResumenIVA->AutoSize = true;
			this->lblResumenIVA->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblResumenIVA->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblResumenIVA->Location = System::Drawing::Point(401, 286);
			this->lblResumenIVA->Name = L"lblResumenIVA";
			this->lblResumenIVA->Size = System::Drawing::Size(141, 18);
			this->lblResumenIVA->TabIndex = 45;
			this->lblResumenIVA->Text = L"IVA (12%): Q 0.00";

			this->lblResumenSubtotal->AutoSize = true;
			this->lblResumenSubtotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblResumenSubtotal->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
			this->lblResumenSubtotal->Location = System::Drawing::Point(401, 264);
			this->lblResumenSubtotal->Name = L"lblResumenSubtotal";
			this->lblResumenSubtotal->Size = System::Drawing::Size(130, 18);
			this->lblResumenSubtotal->TabIndex = 44;
			this->lblResumenSubtotal->Text = L"Subtotal: Q 0.00";

			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label11->Location = System::Drawing::Point(399, 86);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(167, 18);
			this->label11->TabIndex = 43;
			this->label11->Text = L"Resumen de la Venta";

			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->label12->Location = System::Drawing::Point(149, 418);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 17);
			this->label12->TabIndex = 42;

			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->label14->Location = System::Drawing::Point(59, 86);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(135, 18);
			this->label14->TabIndex = 41;
			this->label14->Text = L"Metodo de pago:";

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(245, 247, 250);
			this->ClientSize = System::Drawing::Size(882, 552);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Controls->Add(this->panelProductos);
			this->Controls->Add(this->panelPago);
			this->Controls->Add(this->btnRegresar);
			this->Controls->Add(this->btnSiguientePaso1);
			this->Controls->Add(this->lblClienteSeleccionado);
			this->Controls->Add(this->btnCrearCliente);
			this->Controls->Add(this->lblClienteNoEncontrado);
			this->Controls->Add(this->dgvClientes);
			this->Controls->Add(this->btnCF);
			this->Controls->Add(this->btnBuscarCliente);
			this->Controls->Add(this->txtBuscarCliente);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lblPaso3);
			this->Controls->Add(this->lblPaso2);
			this->Controls->Add(this->lblPaso1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"frmVenta";
			this->Text = L"Nueva Venta";
			this->Load += gcnew System::EventHandler(this, &frmVenta::frmVenta_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClientes))->EndInit();
			this->panelProductos->ResumeLayout(false);
			this->panelProductos->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCarrito))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->EndInit();
			this->panelPago->ResumeLayout(false);
			this->panelPago->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		System::Void frmVenta_Load(System::Object^ sender, System::EventArgs^ e) {
			lblCajero->Text = "Cajero: " + Globals::Datos::nombreActivo;
			lblTienda->Text = "Tienda: " + Globals::Datos::idTiendaActiva.ToString();
			lblClienteNoEncontrado->Visible = false;
			lblClienteSeleccionado->Visible = false;
			btnCrearCliente->Visible = false;
			btnSiguientePaso1->Enabled = false;

			carrito = gcnew System::Collections::Generic::List<Item^>();
			historial = gcnew System::Collections::Generic::Stack<Item^>();
		}

		System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		System::Void btnCF_Click(System::Object^ sender, System::EventArgs^ e) {
			idClienteSeleccionado = 1;
			nombreClienteSeleccionado = "Consumidor Final";
			lblClienteSeleccionado->Text = "Cliente: Consumidor Final (CF)";
			lblClienteSeleccionado->Visible = true;
			lblClienteNoEncontrado->Visible = false;
			btnCrearCliente->Visible = false;
			btnSiguientePaso1->Enabled = true;
		}

		System::Void btnBuscarCliente_Click(System::Object^ sender, System::EventArgs^ e) {
			if (txtBuscarCliente->Text->Trim() == "") return;

			idClienteSeleccionado = 0;
			nombreClienteSeleccionado = "";
			lblClienteSeleccionado->Visible = false;
			btnSiguientePaso1->Enabled = false;

			ControladorCliente^ ctrl = gcnew ControladorCliente();
			List<Cliente^>^ lista = ctrl->buscarCliente(txtBuscarCliente->Text->Trim());

			DataTable^ dt = gcnew DataTable();
			dt->Columns->Add("id_cliente");
			dt->Columns->Add("nit");
			dt->Columns->Add("nombre");
			dt->Columns->Add("telefono");

			for (int i = 0; i < lista->Count; i++) {
				Cliente^ c = lista[i];
				DataRow^ row = dt->NewRow();
				row["id_cliente"] = c->id_cliente;
				row["nit"] = c->nit;
				row["nombre"] = c->nombre;
				row["telefono"] = c->telefono;
				dt->Rows->Add(row);
			}

			dgvClientes->DataSource = dt;

			if (lista->Count == 0) {
				lblClienteNoEncontrado->Text = "NIT o nombre no encontrado.";
				lblClienteNoEncontrado->Visible = true;
				btnCrearCliente->Visible = true;
			}
			else {
				lblClienteNoEncontrado->Visible = false;
				btnCrearCliente->Visible = false;
			}
		}

		System::Void dgvClientes_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0) {
				DataGridViewRow^ fila = dgvClientes->Rows[e->RowIndex];
				idClienteSeleccionado = Convert::ToInt32(fila->Cells["id_cliente"]->Value);
				nombreClienteSeleccionado = fila->Cells["nombre"]->Value->ToString();
				lblClienteSeleccionado->Text = "Cliente: " + nombreClienteSeleccionado +
					" (NIT: " + fila->Cells["nit"]->Value->ToString() + ")";
				lblClienteSeleccionado->Visible = true;
				btnSiguientePaso1->Enabled = true;
			}
		}

		System::Void btnCrearCliente_Click(System::Object^ sender, System::EventArgs^ e) {
			frmClienteRapido^ popup = gcnew frmClienteRapido();

			if (popup->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				ControladorCliente^ ctrl = gcnew ControladorCliente();
				Cliente^ clienteCreado = ctrl->buscarPorNit(popup->NitIngresado);

				if (clienteCreado != nullptr) {
					idClienteSeleccionado = clienteCreado->id_cliente;
					nombreClienteSeleccionado = clienteCreado->nombre;
					lblClienteSeleccionado->Text = "Cliente: " + clienteCreado->nombre +
						" (NIT: " + clienteCreado->nit + ")";
				}
				else {
					idClienteSeleccionado = 0;
					nombreClienteSeleccionado = popup->NombreIngresado;
					lblClienteSeleccionado->Text = "Cliente: " + popup->NombreIngresado +
						" (NIT: " + popup->NitIngresado + ")";
				}

				lblClienteSeleccionado->Visible = true;
				lblClienteNoEncontrado->Visible = false;
				btnCrearCliente->Visible = false;
				btnSiguientePaso1->Enabled = true;
			}
		}

		System::Void btnSiguientePaso1_Click(System::Object^ sender, System::EventArgs^ e) {
			txtBuscarCliente->Visible = false;
			btnBuscarCliente->Visible = false;
			btnCF->Visible = false;
			dgvClientes->Visible = false;
			lblClienteNoEncontrado->Visible = false;
			lblClienteSeleccionado->Visible = false;
			btnCrearCliente->Visible = false;
			btnSiguientePaso1->Visible = false;

			lblClienteActivo->Text = "Cliente: " + nombreClienteSeleccionado;
			lblClienteActivo->Visible = true;

			panelProductos->Visible = true;

			lblPaso1->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			lblPaso2->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			lblPaso2->ForeColor = System::Drawing::Color::White;
		}

		System::Void btnBuscarProducto_Click(System::Object^ sender, System::EventArgs^ e) {
			if (txtBuscarProducto->Text->Trim() == "") return;

			try {
				ControladorProducto^ ctrl = gcnew ControladorProducto();
				List<Producto^>^ lista = ctrl->buscarProducto(txtBuscarProducto->Text->Trim());

				DataTable^ dt = gcnew DataTable();
				dt->Columns->Add("id_producto");
				dt->Columns->Add("codigo_barras");
				dt->Columns->Add("nombre");
				dt->Columns->Add("precio");

				for each (Producto ^ p in lista) {
					DataRow^ row = dt->NewRow();
					row["id_producto"] = p->id_producto;
					row["codigo_barras"] = p->codigo_barras;
					row["nombre"] = p->nombre;
					row["precio"] = p->precio.ToString("0.00");
					dt->Rows->Add(row);
				}

				dgvProductos->DataSource = dt;

				dgvProductos->Columns["id_producto"]->Visible = false;

				dgvProductos->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::None;
				dgvProductos->RowTemplate->Height = 25;
				dgvProductos->ColumnHeadersHeight = 30;

				dgvProductos->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
				dgvProductos->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
				dgvProductos->ColumnHeadersDefaultCellStyle->Font =
					gcnew System::Drawing::Font("Segoe UI", 10, System::Drawing::FontStyle::Bold);

				dgvProductos->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(220, 233, 245);
				dgvProductos->DefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI", 10);

				dgvProductos->Columns["id_producto"]->Width = 60;
				dgvProductos->Columns["codigo_barras"]->Width = 90;
				dgvProductos->Columns["nombre"]->Width = 150;
				dgvProductos->Columns["precio"]->Width = 70;

				if (lista->Count == 0)
					MessageBox::Show("Producto no encontrado.", "Aviso");
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error en busqueda: " + ex->Message);
			}
		}

		System::Void dgvProductos_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0) {
				DataGridViewRow^ fila = dgvProductos->Rows[e->RowIndex];
				idProductoSeleccionado = Convert::ToInt32(fila->Cells["id_producto"]->Value);
				nombreProductoSeleccionado = fila->Cells["nombre"]->Value->ToString();
				precioProductoSeleccionado = Convert::ToDouble(fila->Cells["precio"]->Value);
			}
		}

		System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
			if (idProductoSeleccionado == 0) {
				MessageBox::Show("Selecciona un producto primero.", "Aviso");
				return;
			}

			int cantidad = Convert::ToInt32(txtCantidad->Text);
			if (cantidad <= 0) {
				MessageBox::Show("La cantidad debe ser mayor a 0.", "Aviso");
				return;
			}

			Item^ item = gcnew Item();
			item->idProducto = idProductoSeleccionado;
			item->nombre = nombreProductoSeleccionado;
			item->cantidad = cantidad;
			item->precio = precioProductoSeleccionado;
			item->subtotal = cantidad * precioProductoSeleccionado;

			carrito->Add(item);
			historial->Push(item);

			lblUltimoAgregado->Text = "stack -> ultimo: " + item->nombre + " x" + cantidad;

			ActualizarCarrito();

			idProductoSeleccionado = 0;
			txtCantidad->Text = "1";
		}

		void ActualizarCarrito() {
			DataTable^ dt = gcnew DataTable();
			dt->Columns->Add("#");
			dt->Columns->Add("Producto");
			dt->Columns->Add("Cant");
			dt->Columns->Add("Precio");
			dt->Columns->Add("Subtotal");

			double subtotal = 0;

			for (int i = 0; i < carrito->Count; i++) {
				Item^ item = carrito[i];
				DataRow^ row = dt->NewRow();
				row["#"] = i + 1;
				row["Producto"] = item->nombre;
				row["Cant"] = item->cantidad;
				row["Precio"] = "Q " + item->precio.ToString("0.00");
				row["Subtotal"] = "Q " + item->subtotal.ToString("0.00");
				dt->Rows->Add(row);
				subtotal += item->subtotal;
			}

			dgvCarrito->DataSource = dt;

			double iva = subtotal * 0.12;
			double total = subtotal + iva;

			lblSubtotal->Text = "Subtotal: Q " + subtotal.ToString("0.00");
			lblIVA->Text = "IVA (12%): Q " + iva.ToString("0.00");
			lblTotal->Text = "TOTAL: Q " + total.ToString("0.00");
		}

		System::Void btnDeshacer_Click(System::Object^ sender, System::EventArgs^ e) {
			if (historial->Count == 0) {
				MessageBox::Show("No hay productos para deshacer.", "Aviso");
				return;
			}

			Item^ ultimo = historial->Pop();
			carrito->RemoveAt(carrito->Count - 1);

			if (historial->Count > 0) {
				Item^ anterior = historial->Peek();
				lblUltimoAgregado->Text = "stack -> ultimo: " + anterior->nombre + " x" + anterior->cantidad;
			}
			else {
				lblUltimoAgregado->Text = "";
			}

			ActualizarCarrito();

			MessageBox::Show("Se quito: " + ultimo->nombre, "Deshacer");
		}

		System::Void btnLimpiarCarrito_Click(System::Object^ sender, System::EventArgs^ e) {
			if (carrito->Count == 0) return;

			System::Windows::Forms::DialogResult confirmacion = MessageBox::Show(
				"¿Limpiar todo el carrito?",
				"Confirmar",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning
			);

			if (confirmacion == System::Windows::Forms::DialogResult::Yes) {
				carrito->Clear();
				historial->Clear();
				lblUltimoAgregado->Text = "";
				ActualizarCarrito();
			}
		}

		System::Void btnVolverPaso1_Click(System::Object^ sender, System::EventArgs^ e) {
			panelProductos->Visible = false;
			txtBuscarCliente->Visible = true;
			btnBuscarCliente->Visible = true;
			btnCF->Visible = true;
			dgvClientes->Visible = true;
			lblClienteSeleccionado->Visible = true;
			btnSiguientePaso1->Visible = true;
			btnSiguientePaso1->Enabled = true;
			lblPaso1->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			lblPaso1->ForeColor = System::Drawing::Color::White;
			lblPaso2->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			lblPaso2->ForeColor = System::Drawing::Color::White;
		}

		System::Void btnSiguientePaso2_Click(System::Object^ sender, System::EventArgs^ e) {
			if (carrito->Count == 0) {
				MessageBox::Show("El carrito esta vacio.", "Aviso");
				return;
			}

			lblResumenCliente->Text = "Cliente: " + nombreClienteSeleccionado;
			lblResumenCajero->Text = "Cajero: " + Globals::Datos::nombreActivo;
			lblResumenSubtotal->Text = lblSubtotal->Text;
			lblResumenIVA->Text = lblIVA->Text;
			lblResumenTotal->Text = lblTotal->Text;

			panelProductos->Visible = false;
			panelPago->Visible = true;
			panelPago->BringToFront();

			lblPaso2->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			lblPaso2->ForeColor = System::Drawing::Color::White;
			lblPaso3->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			lblPaso3->ForeColor = System::Drawing::Color::White;
		}

		System::Void btnVolverPaso2_Click(System::Object^ sender, System::EventArgs^ e) {
			panelPago->Visible = false;
			panelProductos->Visible = true;
			lblPaso2->BackColor = System::Drawing::Color::FromArgb(84, 153, 211);
			lblPaso2->ForeColor = System::Drawing::Color::White;
			lblPaso3->BackColor = System::Drawing::Color::FromArgb(110, 181, 232);
			lblPaso3->ForeColor = System::Drawing::Color::White;
		}

		System::Void btnCancelarVenta_Click(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::DialogResult confirmacion = MessageBox::Show(
				"¿Cancelar la venta?",
				"Confirmar",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning
			);
			if (confirmacion == System::Windows::Forms::DialogResult::Yes) {
				this->Close();
			}
		}

		System::Void txtMontoRecibido_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (txtMontoRecibido->Text->Trim() == "") {
					lblCambio->Text = "Cambio: Q 0.00";
					lblCambio->BackColor = System::Drawing::Color::FromArgb(220, 233, 245);
					return;
				}

				String^ totalStr = lblResumenTotal->Text->Replace("TOTAL: Q ", "")->Trim();
				double total = Convert::ToDouble(totalStr);
				double monto = Convert::ToDouble(txtMontoRecibido->Text);

				if (monto < total) {
					lblCambio->Text = "Monto insuficiente. Faltan Q " + (total - monto).ToString("0.00");
					lblCambio->BackColor = System::Drawing::Color::Tomato;
					lblCambio->ForeColor = System::Drawing::Color::White;
				}
				else {
					double cambio = monto - total;
					lblCambio->Text = "Cambio: Q " + cambio.ToString("0.00");
					lblCambio->BackColor = System::Drawing::Color::FromArgb(220, 233, 245);
					lblCambio->ForeColor = System::Drawing::Color::FromArgb(84, 153, 211);
				}
			}
			catch (...) {
				lblCambio->Text = "Cambio: Q 0.00";
			}
		}

		System::Void btnConfirmarVenta_Click(System::Object^ sender, System::EventArgs^ e) {
			if (rbEfectivo->Checked) {
				if (txtMontoRecibido->Text->Trim() == "") {
					MessageBox::Show("Ingresa el monto recibido.", "Aviso");
					return;
				}
				String^ totalStr = lblResumenTotal->Text->Replace("TOTAL: Q ", "")->Trim();
				double total = Convert::ToDouble(totalStr);
				double monto = Convert::ToDouble(txtMontoRecibido->Text);
				if (monto < total) {
					MessageBox::Show("El monto recibido es insuficiente.", "Error");
					return;
				}
			}

			String^ metodoPago = rbEfectivo->Checked ? "Efectivo" : "Tarjeta";

			String^ totalStr2 = lblResumenTotal->Text->Replace("TOTAL: Q ", "")->Trim();
			double totalFinal = Convert::ToDouble(totalStr2);

			ControladorVenta^ ctrlVenta = gcnew ControladorVenta();
			int idVenta = ctrlVenta->guardarVenta(
				Globals::Datos::idTiendaActiva,
				idClienteSeleccionado,
				Globals::Datos::idUsuarioActivo,
				totalFinal,
				metodoPago
			);

			if (idVenta == 0) {
				MessageBox::Show("Error al guardar la venta.", "Error");
				return;
			}

			for (int i = 0; i < carrito->Count; i++) {
				Item^ item = carrito[i];
				ctrlVenta->guardarDetalle(
					idVenta,
					item->idProducto,
					item->cantidad,
					item->precio
				);
			}

			String^ resumen = "VENTA CONFIRMADA\n\n";
			resumen += "No. Venta: #" + idVenta + "\n";
			resumen += "Cliente: " + nombreClienteSeleccionado + "\n";
			resumen += "Cajero: " + Globals::Datos::nombreActivo + "\n";
			resumen += "Metodo: " + metodoPago + "\n";
			resumen += lblResumenSubtotal->Text + "\n";
			resumen += lblResumenIVA->Text + "\n";
			resumen += lblResumenTotal->Text + "\n";
			if (rbEfectivo->Checked) {
				resumen += lblCambio->Text;
			}

			MessageBox::Show(resumen, "Venta Exitosa");

			carrito->Clear();
			historial->Clear();
			this->Close();
		}
	};
}