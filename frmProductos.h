#pragma once
// ============================================================
//  frmProductos.h  —  Gestión de Productos (CRUD)
//  Grupo 8
//
//  Controles:
//    txtNombre, txtPrecio, txtCodigo  → campos del formulario
//    cmbCategoria                     → combo de categorías
//    txtBuscar                        → campo de búsqueda
//    btnGuardar, btnEliminar, btnNuevo → acciones CRUD
//    btnBuscar, btnVerTodos            → búsqueda
//    dgvProductos                     → tabla de productos
//    lblConteo                        → "X productos cargados"
// ============================================================

#include "ControladorProducto.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

namespace Supermercado {

    public ref class frmProductos : public Form {

    private:

        int idProductoSeleccionado;

        // ---- Campos del formulario ----
        TextBox^   txtNombre;
        TextBox^   txtPrecio;
        TextBox^   txtCodigo;
        TextBox^   txtBuscar;
        ComboBox^  cmbCategoria;

        // ---- Botones ----
        Button^ btnNuevo;
        Button^ btnGuardar;
        Button^ btnEliminar;
        Button^ btnBuscar;
        Button^ btnVerTodos;

        // ---- Grid y conteo ----
        DataGridView^ dgvProductos;
        Label^        lblConteo;

    public:

        frmProductos() {

            idProductoSeleccionado = 0;

            CrearInterfaz();

            CargarCategorias();

            CargarTodosLosProductos();
        }

    private:

        // =====================================================
        // INTERFAZ
        // =====================================================

        void CrearInterfaz() {

            // ---- FORM ----
            this->Text = "Productos";
            this->Size = Drawing::Size(950, 580);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = Color::Gainsboro;
            this->FormBorderStyle =
                System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;

            // ---- TÍTULO ----
            Label^ lblTitulo = gcnew Label();
            lblTitulo->Text = "Productos";
            lblTitulo->Font = gcnew Drawing::Font(
                "Times New Roman", 16, FontStyle::Bold);
            lblTitulo->BackColor = Color::LightSteelBlue;
            lblTitulo->Location  = Point(30, 20);
            lblTitulo->AutoSize  = true;

            // ---- LABELS ----
            Label^ lblNombre = gcnew Label();
            lblNombre->Text     = "Nombre:";
            lblNombre->Location = Point(30, 80);

            Label^ lblCategoria = gcnew Label();
            lblCategoria->Text     = "Categoría:";
            lblCategoria->Location = Point(30, 140);

            Label^ lblPrecio = gcnew Label();
            lblPrecio->Text     = "Precio (Q):";
            lblPrecio->Location = Point(30, 200);

            Label^ lblCodigo = gcnew Label();
            lblCodigo->Text     = "Código de barras:";
            lblCodigo->Location = Point(30, 260);

            Label^ lblBuscar = gcnew Label();
            lblBuscar->Text     = "Buscar:";
            lblBuscar->Location = Point(300, 20);

            // ---- TEXTBOX ----
            txtNombre = gcnew TextBox();
            txtNombre->Location = Point(30, 100);
            txtNombre->Size     = Drawing::Size(210, 22);

            txtPrecio = gcnew TextBox();
            txtPrecio->Location = Point(30, 220);
            txtPrecio->Size     = Drawing::Size(210, 22);

            txtCodigo = gcnew TextBox();
            txtCodigo->Location = Point(30, 280);
            txtCodigo->Size     = Drawing::Size(210, 22);

            txtBuscar = gcnew TextBox();
            txtBuscar->Location = Point(300, 38);
            txtBuscar->Size     = Drawing::Size(200, 22);

            // ---- COMBO CATEGORÍA ----
            cmbCategoria = gcnew ComboBox();
            cmbCategoria->Location      = Point(30, 160);
            cmbCategoria->Size          = Drawing::Size(210, 22);
            cmbCategoria->DropDownStyle = ComboBoxStyle::DropDownList;

            // ---- BOTÓN NUEVO ----
            btnNuevo = gcnew Button();
            btnNuevo->Text      = "Nuevo";
            btnNuevo->Location  = Point(30, 360);
            btnNuevo->Size      = Drawing::Size(90, 35);
            btnNuevo->BackColor = Color::LightYellow;
            btnNuevo->FlatStyle = FlatStyle::Flat;
            btnNuevo->Click    += gcnew EventHandler(
                this, &frmProductos::btnNuevo_Click);

            // ---- BOTÓN GUARDAR ----
            btnGuardar = gcnew Button();
            btnGuardar->Text      = "Guardar";
            btnGuardar->Location  = Point(30, 405);
            btnGuardar->Size      = Drawing::Size(90, 35);
            btnGuardar->BackColor = Color::LightSteelBlue;
            btnGuardar->FlatStyle = FlatStyle::Flat;
            btnGuardar->Click    += gcnew EventHandler(
                this, &frmProductos::btnGuardar_Click);

            // ---- BOTÓN ELIMINAR ----
            btnEliminar = gcnew Button();
            btnEliminar->Text      = "Eliminar";
            btnEliminar->Location  = Point(140, 405);
            btnEliminar->Size      = Drawing::Size(90, 35);
            btnEliminar->BackColor = Color::LightCoral;
            btnEliminar->FlatStyle = FlatStyle::Flat;
            btnEliminar->Click    += gcnew EventHandler(
                this, &frmProductos::btnEliminar_Click);

            // ---- BOTÓN BUSCAR ----
            btnBuscar = gcnew Button();
            btnBuscar->Text      = "Buscar";
            btnBuscar->Location  = Point(510, 35);
            btnBuscar->Size      = Drawing::Size(80, 28);
            btnBuscar->BackColor = Color::LightSteelBlue;
            btnBuscar->FlatStyle = FlatStyle::Flat;
            btnBuscar->Click    += gcnew EventHandler(
                this, &frmProductos::btnBuscar_Click);

            // ---- BOTÓN VER TODOS ----
            btnVerTodos = gcnew Button();
            btnVerTodos->Text      = "Ver todos";
            btnVerTodos->Location  = Point(600, 35);
            btnVerTodos->Size      = Drawing::Size(80, 28);
            btnVerTodos->BackColor = Color::LightGray;
            btnVerTodos->FlatStyle = FlatStyle::Flat;
            btnVerTodos->Click    += gcnew EventHandler(
                this, &frmProductos::btnVerTodos_Click);

            // ---- GRID ----
            dgvProductos = gcnew DataGridView();
            dgvProductos->Location           = Point(300, 70);
            dgvProductos->Size               = Drawing::Size(620, 430);
            dgvProductos->BackgroundColor    = Color::WhiteSmoke;
            dgvProductos->BorderStyle        = BorderStyle::FixedSingle;
            dgvProductos->AllowUserToAddRows    = false;
            dgvProductos->AllowUserToDeleteRows = false;
            dgvProductos->ReadOnly           = true;
            dgvProductos->SelectionMode      =
                DataGridViewSelectionMode::FullRowSelect;
            dgvProductos->MultiSelect        = false;
            dgvProductos->AutoSizeColumnsMode =
                DataGridViewAutoSizeColumnsMode::Fill;
            dgvProductos->RowHeadersVisible  = false;
            dgvProductos->CellClick         +=
                gcnew DataGridViewCellEventHandler(
                    this, &frmProductos::dgvProductos_CellClick);

            // ---- LABEL CONTEO ----
            lblConteo = gcnew Label();
            lblConteo->Location = Point(300, 510);
            lblConteo->AutoSize = true;

            // ---- AGREGAR CONTROLES ----
            this->Controls->Add(lblTitulo);

            this->Controls->Add(lblNombre);
            this->Controls->Add(lblCategoria);
            this->Controls->Add(lblPrecio);
            this->Controls->Add(lblCodigo);
            this->Controls->Add(lblBuscar);

            this->Controls->Add(txtNombre);
            this->Controls->Add(txtPrecio);
            this->Controls->Add(txtCodigo);
            this->Controls->Add(txtBuscar);

            this->Controls->Add(cmbCategoria);

            this->Controls->Add(btnNuevo);
            this->Controls->Add(btnGuardar);
            this->Controls->Add(btnEliminar);
            this->Controls->Add(btnBuscar);
            this->Controls->Add(btnVerTodos);

            this->Controls->Add(dgvProductos);
            this->Controls->Add(lblConteo);
        }

        // =====================================================
        // CARGAR CATEGORÍAS EN COMBO
        // =====================================================

        void CargarCategorias() {

            cmbCategoria->Items->Clear();

            List<Categoria^>^ cats =
                ControladorProducto().listarCategorias();

            for each (Categoria ^ cat in cats) {

                // Guardamos el objeto completo como item
                cmbCategoria->Items->Add(cat);
            }

            // Que muestre la propiedad "nombre" del objeto
            cmbCategoria->DisplayMember = "nombre";

            if (cmbCategoria->Items->Count > 0)
                cmbCategoria->SelectedIndex = 0;
        }

        // =====================================================
        // CARGAR PRODUCTOS
        // =====================================================

        void CargarTodosLosProductos() {

            List<Producto^>^ lista =
                ControladorProducto().listarProductos();

            Mostrar(lista);
        }

        // =====================================================
        // MOSTRAR EN GRID
        // =====================================================

        void Mostrar(List<Producto^>^ lista) {

            dgvProductos->Rows->Clear();
            dgvProductos->Columns->Clear();

            dgvProductos->Columns->Add("id",         "ID");
            dgvProductos->Columns->Add("id_cat",     "ID_CAT");
            dgvProductos->Columns->Add("nombre",     "Nombre");
            dgvProductos->Columns->Add("categoria",  "Categoría");
            dgvProductos->Columns->Add("precio",     "Precio (Q)");
            dgvProductos->Columns->Add("codigo",     "Código barras");

            // Columnas ocultas
            dgvProductos->Columns["id"]->Visible     = false;
            dgvProductos->Columns["id_cat"]->Visible = false;

            for each (Producto ^ p in lista) {

                dgvProductos->Rows->Add(
                    p->id_producto,
                    p->id_categoria,
                    p->nombre,
                    p->nombre_categoria,
                    p->precio.ToString("F2"),
                    p->codigo_barras
                );
            }

            lblConteo->Text =
                lista->Count.ToString() + " productos";
        }

        // =====================================================
        // LIMPIAR FORMULARIO
        // =====================================================

        void LimpiarFormulario() {

            idProductoSeleccionado = 0;

            txtNombre->Clear();
            txtPrecio->Clear();
            txtCodigo->Clear();

            if (cmbCategoria->Items->Count > 0)
                cmbCategoria->SelectedIndex = 0;

            txtNombre->Focus();
        }

        // =====================================================
        // VALIDAR FORMULARIO
        // Devuelve true si los datos son correctos.
        // =====================================================

        bool Validar() {

            if (txtNombre->Text->Trim() == "") {
                MessageBox::Show("El nombre del producto es obligatorio.");
                txtNombre->Focus();
                return false;
            }

            double precio;
            if (!Double::TryParse(txtPrecio->Text, precio) || precio <= 0) {
                MessageBox::Show("Ingrese un precio válido mayor a 0.");
                txtPrecio->Focus();
                return false;
            }

            if (cmbCategoria->SelectedItem == nullptr) {
                MessageBox::Show("Seleccione una categoría.");
                cmbCategoria->Focus();
                return false;
            }

            return true;
        }

        // =====================================================
        // BOTÓN NUEVO
        // =====================================================

        void btnNuevo_Click(Object^ sender, EventArgs^ e) {

            LimpiarFormulario();
        }

        // =====================================================
        // BOTÓN GUARDAR
        // =====================================================

        void btnGuardar_Click(Object^ sender, EventArgs^ e) {

            if (!Validar()) return;

            Producto^ p = gcnew Producto();

            p->id_producto = idProductoSeleccionado;
            p->nombre      = txtNombre->Text->Trim();
            p->precio      = Convert::ToDouble(txtPrecio->Text);
            p->codigo_barras = txtCodigo->Text->Trim();

            // Obtener id_categoria del ComboBox
            Categoria^ cat =
                (Categoria^)cmbCategoria->SelectedItem;

            p->id_categoria = cat->id_categoria;

            bool ok = ControladorProducto().guardarProducto(p);

            if (ok) {

                CargarTodosLosProductos();
                LimpiarFormulario();
                MessageBox::Show("Producto guardado correctamente.");
            }
        }

        // =====================================================
        // BOTÓN ELIMINAR
        // =====================================================

        void btnEliminar_Click(Object^ sender, EventArgs^ e) {

            if (idProductoSeleccionado == 0) {
                MessageBox::Show("Seleccione un producto de la lista.");
                return;
            }

            if (
                MessageBox::Show(
                    "¿Desea eliminar el producto seleccionado?",
                    "Confirmar eliminación",
                    MessageBoxButtons::YesNo,
                    MessageBoxIcon::Warning
                )
                == System::Windows::Forms::DialogResult::Yes
            ) {

                bool ok = ControladorProducto()
                    .eliminarProducto(idProductoSeleccionado);

                if (ok) {

                    CargarTodosLosProductos();
                    LimpiarFormulario();
                    MessageBox::Show("Producto eliminado correctamente.");
                }
            }
        }

        // =====================================================
        // BOTÓN BUSCAR
        // =====================================================

        void btnBuscar_Click(Object^ sender, EventArgs^ e) {

            String^ texto = txtBuscar->Text->Trim();

            if (texto == "") {
                CargarTodosLosProductos();
                return;
            }

            List<Producto^>^ lista =
                ControladorProducto().buscarProducto(texto);

            Mostrar(lista);
        }

        // =====================================================
        // BOTÓN VER TODOS
        // =====================================================

        void btnVerTodos_Click(Object^ sender, EventArgs^ e) {

            txtBuscar->Clear();
            CargarTodosLosProductos();
        }

        // =====================================================
        // CLICK EN FILA DEL GRID
        // =====================================================

        void dgvProductos_CellClick(
            Object^ sender,
            DataGridViewCellEventArgs^ e
        ) {

            if (e->RowIndex < 0) return;

            DataGridViewRow^ fila =
                dgvProductos->Rows[e->RowIndex];

            idProductoSeleccionado =
                Convert::ToInt32(fila->Cells["id"]->Value);

            txtNombre->Text =
                fila->Cells["nombre"]->Value->ToString();

            txtPrecio->Text =
                fila->Cells["precio"]->Value->ToString();

            txtCodigo->Text =
                fila->Cells["codigo"]->Value->ToString();

            // Seleccionar la categoría correcta en el combo
            int idCat =
                Convert::ToInt32(fila->Cells["id_cat"]->Value);

            for (int i = 0; i < cmbCategoria->Items->Count; i++) {

                Categoria^ cat =
                    (Categoria^)cmbCategoria->Items[i];

                if (cat->id_categoria == idCat) {
                    cmbCategoria->SelectedIndex = i;
                    break;
                }
            }
        }
    };
}
