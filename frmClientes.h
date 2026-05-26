#pragma once
// ============================================================
//  frmClientes.h  —  Gestión de Clientes (CRUD)
//  Majo — Grupo 8
//
//  Controles usados:
//    txtNIT, txtNombre, txtTelefono, txtEmail  → campos del formulario
//    txtBuscar                                 → campo de búsqueda
//    btnNuevo, btnGuardar, btnEliminar         → acciones CRUD
//    btnBuscar, btnVerTodos                    → búsqueda
//    btnRegresar                               → volver al menú
//    dgvClientes                              → tabla de clientes
//    lblConteo                                 → "X clientes cargados"
// ============================================================

#pragma once

#include "ControladorCliente.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

namespace Supermercado {

    public ref class frmClientes : public Form {

    private:

        int idClienteSeleccionado;

        TextBox^ txtNIT;
        TextBox^ txtNombre;
        TextBox^ txtTelefono;
        TextBox^ txtEmail;

        Button^ btnGuardar;
        Button^ btnEliminar;
        Button^ btnRegresar;

        DataGridView^ dgvClientes;

        Label^ lblConteo;

    public:

        frmClientes() {

            idClienteSeleccionado = 0;

            CrearInterfaz();

            CargarTodosLosClientes();
        }

    private:

        // =====================================================
        // INTERFAZ
        // =====================================================

        void CrearInterfaz() {

            // =====================================================
            // FORM
            // =====================================================

            this->Text = "Clientes";

            this->Size = Drawing::Size(900, 550);

            this->StartPosition =
                FormStartPosition::CenterScreen;

            this->BackColor = Color::Gainsboro;

            this->FormBorderStyle =
                System::Windows::Forms
                ::FormBorderStyle::FixedSingle;

            this->MaximizeBox = false;

            // =====================================================
            // TITULO
            // =====================================================

            Label^ lblTitulo = gcnew Label();

            lblTitulo->Text = "Clientes";

            lblTitulo->Font =
                gcnew Drawing::Font(
                    "Times New Roman",
                    16,
                    FontStyle::Bold
                );

            lblTitulo->BackColor =
                Color::LightSteelBlue;

            lblTitulo->Location = Point(30, 20);

            lblTitulo->AutoSize = true;

            // =====================================================
            // LABELS
            // =====================================================

            Label^ lblNIT = gcnew Label();

            lblNIT->Text = "NIT:";

            lblNIT->Location = Point(30, 80);

            Label^ lblNombre = gcnew Label();

            lblNombre->Text = "Nombre:";

            lblNombre->Location = Point(30, 140);

            Label^ lblTelefono = gcnew Label();

            lblTelefono->Text = "Teléfono:";

            lblTelefono->Location = Point(30, 200);

            Label^ lblEmail = gcnew Label();

            lblEmail->Text = "Email:";

            lblEmail->Location = Point(30, 260);

            // =====================================================
            // TEXTBOX
            // =====================================================

            txtNIT = gcnew TextBox();

            txtNIT->Location = Point(30, 100);

            txtNIT->Size = Drawing::Size(180, 22);

            txtNombre = gcnew TextBox();

            txtNombre->Location = Point(30, 160);

            txtNombre->Size = Drawing::Size(180, 22);

            txtTelefono = gcnew TextBox();

            txtTelefono->Location = Point(30, 220);

            txtTelefono->Size = Drawing::Size(180, 22);

            txtEmail = gcnew TextBox();

            txtEmail->Location = Point(30, 280);

            txtEmail->Size = Drawing::Size(180, 22);

            // =====================================================
            // BOTON GUARDAR
            // =====================================================

            btnGuardar = gcnew Button();

            btnGuardar->Text = "Guardar";

            btnGuardar->Location = Point(30, 350);

            btnGuardar->Size = Drawing::Size(90, 35);

            btnGuardar->BackColor =
                Color::LightSteelBlue;

            btnGuardar->FlatStyle =
                FlatStyle::Flat;

            btnGuardar->Click +=
                gcnew EventHandler(
                    this,
                    &frmClientes::btnGuardar_Click
                );

            // =====================================================
            // BOTON ELIMINAR
            // =====================================================

            btnEliminar = gcnew Button();

            btnEliminar->Text = "Eliminar";

            btnEliminar->Location = Point(140, 350);

            btnEliminar->Size = Drawing::Size(90, 35);

            btnEliminar->BackColor =
                Color::LightGray;

            btnEliminar->FlatStyle =
                FlatStyle::Flat;

            btnEliminar->Click +=
                gcnew EventHandler(
                    this,
                    &frmClientes::btnEliminar_Click
                );

            // =====================================================
            // BOTON REGRESAR
            // =====================================================

            btnRegresar = gcnew Button();

            btnRegresar->Text = "Regresar al Menú";

            btnRegresar->Location = Point(30, 410);

            btnRegresar->Size = Drawing::Size(200, 35);

            btnRegresar->BackColor =
                Color::Silver;

            btnRegresar->FlatStyle =
                FlatStyle::Flat;

            btnRegresar->Click +=
                gcnew EventHandler(
                    this,
                    &frmClientes::btnRegresar_Click
                );

            // =====================================================
            // GRID
            // =====================================================

            dgvClientes = gcnew DataGridView();

            dgvClientes->Location = Point(280, 40);

            dgvClientes->Size = Drawing::Size(570, 400);

            dgvClientes->BackgroundColor =
                Color::WhiteSmoke;

            dgvClientes->BorderStyle =
                BorderStyle::FixedSingle;

            dgvClientes->AllowUserToAddRows = false;

            dgvClientes->AllowUserToDeleteRows = false;

            dgvClientes->ReadOnly = true;

            dgvClientes->SelectionMode =
                DataGridViewSelectionMode::FullRowSelect;

            dgvClientes->MultiSelect = false;

            dgvClientes->AutoSizeColumnsMode =
                DataGridViewAutoSizeColumnsMode::Fill;

            dgvClientes->RowHeadersVisible = false;

            dgvClientes->CellClick +=
                gcnew DataGridViewCellEventHandler(
                    this,
                    &frmClientes::dgvClientes_CellClick
                );

            // =====================================================
            // LABEL CONTEO
            // =====================================================

            lblConteo = gcnew Label();

            lblConteo->Location = Point(280, 460);

            lblConteo->AutoSize = true;

            // =====================================================
            // AGREGAR CONTROLES
            // =====================================================

            this->Controls->Add(lblTitulo);

            this->Controls->Add(lblNIT);
            this->Controls->Add(lblNombre);
            this->Controls->Add(lblTelefono);
            this->Controls->Add(lblEmail);

            this->Controls->Add(txtNIT);
            this->Controls->Add(txtNombre);
            this->Controls->Add(txtTelefono);
            this->Controls->Add(txtEmail);

            this->Controls->Add(btnGuardar);
            this->Controls->Add(btnEliminar);
            this->Controls->Add(btnRegresar);

            this->Controls->Add(dgvClientes);

            this->Controls->Add(lblConteo);
        }

        // =====================================================
        // CARGAR CLIENTES
        // =====================================================

        void CargarTodosLosClientes() {

            List<Cliente^>^ lista =
                ControladorCliente().listarClientes();

            Mostrar(lista);
        }

        // =====================================================
        // MOSTRAR
        // =====================================================

        void Mostrar(List<Cliente^>^ lista) {

            dgvClientes->Rows->Clear();

            dgvClientes->Columns->Clear();

            dgvClientes->Columns->Add("id", "ID");
            dgvClientes->Columns->Add("nit", "NIT");
            dgvClientes->Columns->Add("nombre", "Nombre");
            dgvClientes->Columns->Add("telefono", "Teléfono");
            dgvClientes->Columns->Add("email", "Email");

            dgvClientes->Columns["id"]->Visible = false;

            for each (Cliente ^ c in lista) {

                dgvClientes->Rows->Add(
                    c->id_cliente,
                    c->nit,
                    c->nombre,
                    c->telefono,
                    c->email
                );
            }

            lblConteo->Text =
                lista->Count.ToString() + " clientes";
        }

        // =====================================================
        // LIMPIAR
        // =====================================================

        void LimpiarFormulario() {

            idClienteSeleccionado = 0;

            txtNIT->Clear();

            txtNombre->Clear();

            txtTelefono->Clear();

            txtEmail->Clear();

            txtNIT->Focus();
        }

        // =====================================================
        // GUARDAR
        // =====================================================

        void btnGuardar_Click(
            Object^ sender,
            EventArgs^ e
        ) {

            Cliente^ c = gcnew Cliente();

            c->id_cliente =
                idClienteSeleccionado;

            c->nit =
                txtNIT->Text;

            c->nombre =
                txtNombre->Text;

            c->telefono =
                txtTelefono->Text;

            c->email =
                txtEmail->Text;

            ControladorCliente()
                .guardarCliente(c);

            CargarTodosLosClientes();

            LimpiarFormulario();

            MessageBox::Show(
                "Cliente guardado correctamente"
            );
        }

        // =====================================================
        // ELIMINAR
        // =====================================================

        void btnEliminar_Click(
            Object^ sender,
            EventArgs^ e
        ) {

            if (idClienteSeleccionado == 0) {

                MessageBox::Show(
                    "Seleccione un cliente"
                );

                return;
            }

            if (
                MessageBox::Show(
                    "¿Eliminar cliente?",
                    "Confirmar",
                    MessageBoxButtons::YesNo
                )
                ==
                System::Windows::Forms
                ::DialogResult::Yes
                ) {

                ControladorCliente()
                    .eliminarCliente(
                        idClienteSeleccionado
                    );

                CargarTodosLosClientes();

                LimpiarFormulario();

                MessageBox::Show(
                    "Cliente eliminado"
                );
            }
        }

        // =====================================================
        // REGRESAR AL MENU
        // =====================================================

        void btnRegresar_Click(
            Object^ sender,
            EventArgs^ e
        ) {
            this->Close();
        }

        // =====================================================
        // CLICK GRID
        // =====================================================

        void dgvClientes_CellClick(
            Object^ sender,
            DataGridViewCellEventArgs^ e
        ) {

            if (e->RowIndex < 0)
                return;

            DataGridViewRow^ fila =
                dgvClientes->Rows[e->RowIndex];

            idClienteSeleccionado =
                Convert::ToInt32(
                    fila->Cells["id"]->Value
                );

            txtNIT->Text =
                fila->Cells["nit"]->Value
                ->ToString();

            txtNombre->Text =
                fila->Cells["nombre"]->Value
                ->ToString();

            txtTelefono->Text =
                fila->Cells["telefono"]->Value
                ->ToString();

            txtEmail->Text =
                fila->Cells["email"]->Value
                ->ToString();
        }
    };
}