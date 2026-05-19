#pragma once
#include "Globals.h"
#include "frmClienteRapido.h"

namespace Supermercado {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmVenta
	/// </summary>
	public ref class frmVenta : public System::Windows::Forms::Form
	{
	public:
		frmVenta(void)
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
		~frmVenta()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
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

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;

	private:
		// Estructura del item del carrito
		ref struct Item {
			String^ nombre;
			int cantidad;
			double precio;
			double subtotal;
		};

		// Vector del carrito
		System::Collections::Generic::List<Item^>^ carrito;

		// Stack para deshacer
		System::Collections::Generic::Stack<Item^>^ historial;

		// Producto seleccionado actualmente
		int idProductoSeleccionado = 0;
		String^ nombreProductoSeleccionado = "";
		double precioProductoSeleccionado = 0.0;





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
			this->panelProductos = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtBuscarProducto = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscarProducto = (gcnew System::Windows::Forms::Button());
			this->dgvProductos = (gcnew System::Windows::Forms::DataGridView());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtCantidad = (gcnew System::Windows::Forms::TextBox());
			this->btnAgregar = (gcnew System::Windows::Forms::Button());
			this->btnDeshacer = (gcnew System::Windows::Forms::Button());
			this->lblUltimoAgregado = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dgvCarrito = (gcnew System::Windows::Forms::DataGridView());
			this->lblSubtotal = (gcnew System::Windows::Forms::Label());
			this->lblIVA = (gcnew System::Windows::Forms::Label());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->btnVolverPaso1 = (gcnew System::Windows::Forms::Button());
			this->btnLimpiarCarrito = (gcnew System::Windows::Forms::Button());
			this->btnSiguientePaso2 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lblClienteActivo = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClientes))->BeginInit();
			this->panelProductos->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCarrito))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Snow;
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nueva Venta";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(882, 40);
			this->panel1->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->Controls->Add(this->lblTienda);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->lblCajero);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(20, 46);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(840, 30);
			this->panel2->TabIndex = 2;
			// 
			// lblTienda
			// 
			this->lblTienda->AutoSize = true;
			this->lblTienda->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTienda->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lblTienda->Location = System::Drawing::Point(407, 7);
			this->lblTienda->Name = L"lblTienda";
			this->lblTienda->Size = System::Drawing::Size(14, 17);
			this->lblTienda->TabIndex = 4;
			this->lblTienda->Text = L"-";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label3->Location = System::Drawing::Point(289, 6);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 17);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Tienda:";
			// 
			// lblCajero
			// 
			this->lblCajero->AutoSize = true;
			this->lblCajero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCajero->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lblCajero->Location = System::Drawing::Point(119, 6);
			this->lblCajero->Name = L"lblCajero";
			this->lblCajero->Size = System::Drawing::Size(14, 17);
			this->lblCajero->TabIndex = 2;
			this->lblCajero->Text = L"-";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(22, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Cajero:";
			// 
			// lblPaso1
			// 
			this->lblPaso1->AutoSize = true;
			this->lblPaso1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->lblPaso1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPaso1->Location = System::Drawing::Point(42, 95);
			this->lblPaso1->Name = L"lblPaso1";
			this->lblPaso1->Size = System::Drawing::Size(79, 18);
			this->lblPaso1->TabIndex = 3;
			this->lblPaso1->Text = L"1. Cliente";
			// 
			// lblPaso2
			// 
			this->lblPaso2->AutoSize = true;
			this->lblPaso2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->lblPaso2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPaso2->Location = System::Drawing::Point(139, 95);
			this->lblPaso2->Name = L"lblPaso2";
			this->lblPaso2->Size = System::Drawing::Size(105, 18);
			this->lblPaso2->TabIndex = 4;
			this->lblPaso2->Text = L"2. Productos";
			// 
			// lblPaso3
			// 
			this->lblPaso3->AutoSize = true;
			this->lblPaso3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->lblPaso3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPaso3->Location = System::Drawing::Point(260, 95);
			this->lblPaso3->Name = L"lblPaso3";
			this->lblPaso3->Size = System::Drawing::Size(66, 18);
			this->lblPaso3->TabIndex = 5;
			this->lblPaso3->Text = L"3. Pago";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(42, 168);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 18);
			this->label4->TabIndex = 6;
			this->label4->Text = L"NIT o Nombre:";
			// 
			// txtBuscarCliente
			// 
			this->txtBuscarCliente->Location = System::Drawing::Point(200, 168);
			this->txtBuscarCliente->Name = L"txtBuscarCliente";
			this->txtBuscarCliente->Size = System::Drawing::Size(165, 22);
			this->txtBuscarCliente->TabIndex = 7;
			// 
			// btnBuscarCliente
			// 
			this->btnBuscarCliente->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnBuscarCliente->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscarCliente->Location = System::Drawing::Point(392, 164);
			this->btnBuscarCliente->Name = L"btnBuscarCliente";
			this->btnBuscarCliente->Size = System::Drawing::Size(75, 28);
			this->btnBuscarCliente->TabIndex = 8;
			this->btnBuscarCliente->Text = L"Buscar";
			this->btnBuscarCliente->UseVisualStyleBackColor = false;
			this->btnBuscarCliente->Click += gcnew System::EventHandler(this, &frmVenta::btnBuscarCliente_Click);
			// 
			// btnCF
			// 
			this->btnCF->BackColor = System::Drawing::Color::DarkOrange;
			this->btnCF->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCF->Location = System::Drawing::Point(485, 164);
			this->btnCF->Name = L"btnCF";
			this->btnCF->Size = System::Drawing::Size(188, 28);
			this->btnCF->TabIndex = 9;
			this->btnCF->Text = L"CF — Consumidor Final";
			this->btnCF->UseVisualStyleBackColor = false;
			this->btnCF->Click += gcnew System::EventHandler(this, &frmVenta::btnCF_Click);
			// 
			// dgvClientes
			// 
			this->dgvClientes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvClientes->Location = System::Drawing::Point(20, 236);
			this->dgvClientes->Name = L"dgvClientes";
			this->dgvClientes->RowHeadersWidth = 51;
			this->dgvClientes->RowTemplate->Height = 24;
			this->dgvClientes->Size = System::Drawing::Size(840, 165);
			this->dgvClientes->TabIndex = 10;
			this->dgvClientes->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmVenta::dgvClientes_CellClick);
			// 
			// lblClienteNoEncontrado
			// 
			this->lblClienteNoEncontrado->AutoSize = true;
			this->lblClienteNoEncontrado->BackColor = System::Drawing::Color::Tomato;
			this->lblClienteNoEncontrado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblClienteNoEncontrado->ForeColor = System::Drawing::Color::Black;
			this->lblClienteNoEncontrado->Location = System::Drawing::Point(65, 432);
			this->lblClienteNoEncontrado->Name = L"lblClienteNoEncontrado";
			this->lblClienteNoEncontrado->Size = System::Drawing::Size(0, 18);
			this->lblClienteNoEncontrado->TabIndex = 11;
			this->lblClienteNoEncontrado->Visible = false;
			// 
			// btnCrearCliente
			// 
			this->btnCrearCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnCrearCliente->Location = System::Drawing::Point(650, 419);
			this->btnCrearCliente->Name = L"btnCrearCliente";
			this->btnCrearCliente->Size = System::Drawing::Size(190, 31);
			this->btnCrearCliente->TabIndex = 12;
			this->btnCrearCliente->Text = L"+ Crear cliente";
			this->btnCrearCliente->UseVisualStyleBackColor = false;
			this->btnCrearCliente->Click += gcnew System::EventHandler(this, &frmVenta::btnCrearCliente_Click);
			// 
			// lblClienteSeleccionado
			// 
			this->lblClienteSeleccionado->AutoSize = true;
			this->lblClienteSeleccionado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lblClienteSeleccionado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblClienteSeleccionado->ForeColor = System::Drawing::Color::Black;
			this->lblClienteSeleccionado->Location = System::Drawing::Point(65, 478);
			this->lblClienteSeleccionado->Name = L"lblClienteSeleccionado";
			this->lblClienteSeleccionado->Size = System::Drawing::Size(0, 18);
			this->lblClienteSeleccionado->TabIndex = 13;
			this->lblClienteSeleccionado->Visible = false;
			// 
			// btnSiguientePaso1
			// 
			this->btnSiguientePaso1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnSiguientePaso1->Location = System::Drawing::Point(625, 493);
			this->btnSiguientePaso1->Name = L"btnSiguientePaso1";
			this->btnSiguientePaso1->Size = System::Drawing::Size(235, 48);
			this->btnSiguientePaso1->TabIndex = 14;
			this->btnSiguientePaso1->Text = L"Siguiente →";
			this->btnSiguientePaso1->UseVisualStyleBackColor = false;
			this->btnSiguientePaso1->Click += gcnew System::EventHandler(this, &frmVenta::btnSiguientePaso1_Click);
			// 
			// panelProductos
			// 
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
			this->panelProductos->Location = System::Drawing::Point(0, 29);
			this->panelProductos->Name = L"panelProductos";
			this->panelProductos->Size = System::Drawing::Size(882, 524);
			this->panelProductos->TabIndex = 15;
			this->panelProductos->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(42, 108);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(147, 18);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Código o Nombre:";
			// 
			// txtBuscarProducto
			// 
			this->txtBuscarProducto->Location = System::Drawing::Point(45, 145);
			this->txtBuscarProducto->Name = L"txtBuscarProducto";
			this->txtBuscarProducto->Size = System::Drawing::Size(138, 22);
			this->txtBuscarProducto->TabIndex = 1;
			// 
			// btnBuscarProducto
			// 
			this->btnBuscarProducto->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnBuscarProducto->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscarProducto->Location = System::Drawing::Point(189, 141);
			this->btnBuscarProducto->Name = L"btnBuscarProducto";
			this->btnBuscarProducto->Size = System::Drawing::Size(96, 26);
			this->btnBuscarProducto->TabIndex = 2;
			this->btnBuscarProducto->Text = L"Buscar";
			this->btnBuscarProducto->UseVisualStyleBackColor = false;
			// 
			// dgvProductos
			// 
			this->dgvProductos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProductos->Location = System::Drawing::Point(20, 192);
			this->dgvProductos->Name = L"dgvProductos";
			this->dgvProductos->RowHeadersWidth = 51;
			this->dgvProductos->RowTemplate->Height = 24;
			this->dgvProductos->Size = System::Drawing::Size(265, 143);
			this->dgvProductos->TabIndex = 3;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(42, 360);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 17);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Cantidad:";
			// 
			// txtCantidad
			// 
			this->txtCantidad->Location = System::Drawing::Point(125, 357);
			this->txtCantidad->Name = L"txtCantidad";
			this->txtCantidad->Size = System::Drawing::Size(138, 22);
			this->txtCantidad->TabIndex = 5;
			this->txtCantidad->Text = L"1";
			// 
			// btnAgregar
			// 
			this->btnAgregar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnAgregar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAgregar->Location = System::Drawing::Point(25, 388);
			this->btnAgregar->Name = L"btnAgregar";
			this->btnAgregar->Size = System::Drawing::Size(260, 33);
			this->btnAgregar->TabIndex = 6;
			this->btnAgregar->Text = L"+ Agregar al carrito";
			this->btnAgregar->UseVisualStyleBackColor = false;
			// 
			// btnDeshacer
			// 
			this->btnDeshacer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btnDeshacer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDeshacer->Location = System::Drawing::Point(25, 428);
			this->btnDeshacer->Name = L"btnDeshacer";
			this->btnDeshacer->Size = System::Drawing::Size(260, 33);
			this->btnDeshacer->TabIndex = 7;
			this->btnDeshacer->Text = L"↩ Deshacer último";
			this->btnDeshacer->UseVisualStyleBackColor = false;
			// 
			// lblUltimoAgregado
			// 
			this->lblUltimoAgregado->AutoSize = true;
			this->lblUltimoAgregado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblUltimoAgregado->Location = System::Drawing::Point(115, 471);
			this->lblUltimoAgregado->Name = L"lblUltimoAgregado";
			this->lblUltimoAgregado->Size = System::Drawing::Size(0, 17);
			this->lblUltimoAgregado->TabIndex = 8;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(389, 108);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(60, 18);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Carrito";
			// 
			// dgvCarrito
			// 
			this->dgvCarrito->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCarrito->Location = System::Drawing::Point(392, 130);
			this->dgvCarrito->Name = L"dgvCarrito";
			this->dgvCarrito->RowHeadersWidth = 51;
			this->dgvCarrito->RowTemplate->Height = 24;
			this->dgvCarrito->Size = System::Drawing::Size(448, 150);
			this->dgvCarrito->TabIndex = 10;
			// 
			// lblSubtotal
			// 
			this->lblSubtotal->AutoSize = true;
			this->lblSubtotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSubtotal->Location = System::Drawing::Point(389, 317);
			this->lblSubtotal->Name = L"lblSubtotal";
			this->lblSubtotal->Size = System::Drawing::Size(130, 18);
			this->lblSubtotal->TabIndex = 12;
			this->lblSubtotal->Text = L"Subtotal: Q 0.00";
			// 
			// lblIVA
			// 
			this->lblIVA->AutoSize = true;
			this->lblIVA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIVA->Location = System::Drawing::Point(389, 339);
			this->lblIVA->Name = L"lblIVA";
			this->lblIVA->Size = System::Drawing::Size(141, 18);
			this->lblIVA->TabIndex = 13;
			this->lblIVA->Text = L"IVA (12%): Q 0.00";
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotal->Location = System::Drawing::Point(389, 361);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(120, 18);
			this->lblTotal->TabIndex = 14;
			this->lblTotal->Text = L"TOTAL: Q 0.00";
			// 
			// btnVolverPaso1
			// 
			this->btnVolverPaso1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btnVolverPaso1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVolverPaso1->Location = System::Drawing::Point(392, 416);
			this->btnVolverPaso1->Name = L"btnVolverPaso1";
			this->btnVolverPaso1->Size = System::Drawing::Size(96, 26);
			this->btnVolverPaso1->TabIndex = 15;
			this->btnVolverPaso1->Text = L"← Volver";
			this->btnVolverPaso1->UseVisualStyleBackColor = false;
			// 
			// btnLimpiarCarrito
			// 
			this->btnLimpiarCarrito->BackColor = System::Drawing::SystemColors::ControlDark;
			this->btnLimpiarCarrito->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiarCarrito->Location = System::Drawing::Point(601, 417);
			this->btnLimpiarCarrito->Name = L"btnLimpiarCarrito";
			this->btnLimpiarCarrito->Size = System::Drawing::Size(120, 26);
			this->btnLimpiarCarrito->TabIndex = 16;
			this->btnLimpiarCarrito->Text = L"Limpiar todo";
			this->btnLimpiarCarrito->UseVisualStyleBackColor = false;
			// 
			// btnSiguientePaso2
			// 
			this->btnSiguientePaso2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnSiguientePaso2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSiguientePaso2->Location = System::Drawing::Point(727, 417);
			this->btnSiguientePaso2->Name = L"btnSiguientePaso2";
			this->btnSiguientePaso2->Size = System::Drawing::Size(113, 26);
			this->btnSiguientePaso2->TabIndex = 17;
			this->btnSiguientePaso2->Text = L"Ir a Pago →";
			this->btnSiguientePaso2->UseVisualStyleBackColor = false;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel3->Controls->Add(this->lblClienteActivo);
			this->panel3->Controls->Add(this->label13);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->label11);
			this->panel3->Location = System::Drawing::Point(25, 14);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(840, 30);
			this->panel3->TabIndex = 18;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label8->Location = System::Drawing::Point(407, 7);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(14, 17);
			this->label8->TabIndex = 4;
			this->label8->Text = L"-";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label9->Location = System::Drawing::Point(289, 6);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(56, 17);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Tienda:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label10->Location = System::Drawing::Point(119, 6);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(14, 17);
			this->label10->TabIndex = 2;
			this->label10->Text = L"-";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label11->Location = System::Drawing::Point(22, 6);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(53, 17);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Cajero:";
			// 
			// lblClienteActivo
			// 
			this->lblClienteActivo->AutoSize = true;
			this->lblClienteActivo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblClienteActivo->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->lblClienteActivo->Location = System::Drawing::Point(666, 6);
			this->lblClienteActivo->Name = L"lblClienteActivo";
			this->lblClienteActivo->Size = System::Drawing::Size(14, 17);
			this->lblClienteActivo->TabIndex = 6;
			this->lblClienteActivo->Text = L"-";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label13->Location = System::Drawing::Point(548, 5);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(55, 17);
			this->label13->TabIndex = 5;
			this->label13->Text = L"Cliente:";
			// 
			// frmVenta
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(882, 553);
			this->Controls->Add(this->panelProductos);
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
			this->Text = L"frmVenta";
			this->Load += gcnew System::EventHandler(this, &frmVenta::frmVenta_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClientes))->EndInit();
			this->panelProductos->ResumeLayout(false);
			this->panelProductos->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProductos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCarrito))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void frmVenta_Load(System::Object^ sender, System::EventArgs^ e) {
		lblCajero->Text = "Cajero: " + Globals::Datos::nombreActivo;
		lblTienda->Text = "Tienda: " + Globals::Datos::idTiendaActiva.ToString();
		lblClienteNoEncontrado->Visible = false;
		lblClienteSeleccionado->Visible = false;
		btnCrearCliente->Visible = false;
		btnSiguientePaso1->Enabled = false;

		carrito = gcnew System::Collections::Generic::List<Item^>();
		historial = gcnew System::Collections::Generic::Stack<Item^>();
	}
	private: System::Void btnCF_Click(System::Object^ sender, System::EventArgs^ e) {
		idClienteSeleccionado = 1;
		nombreClienteSeleccionado = "Consumidor Final";
		lblClienteSeleccionado->Text = "Cliente: Consumidor Final (CF)";
		lblClienteSeleccionado->Visible = true;
		lblClienteNoEncontrado->Visible = false;
		btnCrearCliente->Visible = false;
		btnSiguientePaso1->Enabled = true;
	}
	private: System::Void btnBuscarCliente_Click(System::Object^ sender, System::EventArgs^ e) {

		if (txtBuscarCliente->Text->Trim() == "") {
			return;
		}

		// Limpiar selección anterior
		idClienteSeleccionado = 0;
		nombreClienteSeleccionado = "";
		lblClienteSeleccionado->Visible = false;
		btnSiguientePaso1->Enabled = false;

		// Buscar en la DB — por ahora tabla vacía, se conecta cuando Majo termine ControladorCliente
		// TEMPORAL: simular búsqueda con DataTable vacío
		DataTable^ dt = gcnew DataTable();
		dt->Columns->Add("id_cliente");
		dt->Columns->Add("nit");
		dt->Columns->Add("nombre");
		dt->Columns->Add("telefono");

		dgvClientes->DataSource = dt;

		if (dt->Rows->Count == 0) {
			lblClienteNoEncontrado->Text = "NIT o nombre no encontrado.";
			lblClienteNoEncontrado->Visible = true;
			btnCrearCliente->Visible = true;
		}
		else {
			lblClienteNoEncontrado->Visible = false;
			btnCrearCliente->Visible = false;
		}
	}
	private: System::Void dgvClientes_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
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
	private: System::Void btnCrearCliente_Click(System::Object^ sender, System::EventArgs^ e) {
		frmClienteRapido^ popup = gcnew frmClienteRapido();

		if (popup->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Cliente creado — por ahora solo lo seleccionamos en memoria
			// Cuando Majo termine ControladorCliente, aquí llamamos guardarCliente()
			nombreClienteSeleccionado = popup->NombreIngresado;
			lblClienteSeleccionado->Text = "Cliente: " + popup->NombreIngresado +
				" (NIT: " + popup->NitIngresado + ")";
			lblClienteSeleccionado->Visible = true;
			lblClienteNoEncontrado->Visible = false;
			btnCrearCliente->Visible = false;
			btnSiguientePaso1->Enabled = true;
		}
	}
	private: System::Void btnSiguientePaso1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Ocultar paso 1
		txtBuscarCliente->Visible = false;
		btnBuscarCliente->Visible = false;
		btnCF->Visible = false;
		dgvClientes->Visible = false;
		lblClienteNoEncontrado->Visible = false;
		lblClienteSeleccionado->Visible = false;
		btnCrearCliente->Visible = false;
		btnSiguientePaso1->Visible = false;

		// Mostrar paso 2
		panelProductos->Visible = true;

		// Actualizar barra de pasos
		lblPaso1->BackColor = System::Drawing::Color::LightGreen;
		lblPaso2->BackColor = System::Drawing::Color::SteelBlue;
		lblPaso2->ForeColor = System::Drawing::Color::White;
	}



};
}
