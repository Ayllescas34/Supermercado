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

        void CrearInterfaz() {

            // ── FORM ──
            this->Text = "Clientes";
            this->Size = Drawing::Size(900, 560);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = Color::FromArgb(245, 247, 250);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;

            // ── FRANJA IZQUIERDA ──
            Panel^ panelLeft = gcnew Panel();
            panelLeft->BackColor = Color::FromArgb(110, 181, 232);
            panelLeft->Location = Point(0, 52);
            panelLeft->Size = Drawing::Size(57, 22);
            this->Controls->Add(panelLeft);

            // ── TITULO ──
            Label^ lblTitulo = gcnew Label();
            lblTitulo->Text = "Clientes";
            lblTitulo->Font = gcnew Drawing::Font("Century Schoolbook", 20, FontStyle::Bold);
            lblTitulo->BackColor = Color::Transparent;
            lblTitulo->ForeColor = Color::FromArgb(30, 30, 30);
            lblTitulo->Location = Point(70, 20);
            lblTitulo->AutoSize = true;

            // ── FRANJA DERECHA ──
            Panel^ panelRight = gcnew Panel();
            panelRight->BackColor = Color::FromArgb(110, 181, 232);
            panelRight->Location = Point(240, 52);
            panelRight->Size = Drawing::Size(660, 22);
            this->Controls->Add(panelRight);

            // ── LABELS ──
            Label^ lblNIT = gcnew Label(); lblNIT->Text = "NIT:";       lblNIT->Location = Point(30, 100); lblNIT->Font = gcnew Drawing::Font("Segoe UI", 10); lblNIT->AutoSize = true;
            Label^ lblNombre = gcnew Label(); lblNombre->Text = "Nombre:";    lblNombre->Location = Point(30, 155); lblNombre->Font = gcnew Drawing::Font("Segoe UI", 10); lblNombre->AutoSize = true;
            Label^ lblTelefono = gcnew Label(); lblTelefono->Text = "Teléfono:";  lblTelefono->Location = Point(30, 210); lblTelefono->Font = gcnew Drawing::Font("Segoe UI", 10); lblTelefono->AutoSize = true;
            Label^ lblEmail = gcnew Label(); lblEmail->Text = "Email:";     lblEmail->Location = Point(30, 265); lblEmail->Font = gcnew Drawing::Font("Segoe UI", 10); lblEmail->AutoSize = true;

            // ── TEXTBOX ──
            txtNIT = gcnew TextBox();
            txtNIT->Location = Point(30, 120);
            txtNIT->Size = Drawing::Size(195, 22);
            txtNIT->Font = gcnew Drawing::Font("Segoe UI", 10);

            txtNombre = gcnew TextBox();
            txtNombre->Location = Point(30, 175);
            txtNombre->Size = Drawing::Size(195, 22);
            txtNombre->Font = gcnew Drawing::Font("Segoe UI", 10);

            txtTelefono = gcnew TextBox();
            txtTelefono->Location = Point(30, 230);
            txtTelefono->Size = Drawing::Size(195, 22);
            txtTelefono->Font = gcnew Drawing::Font("Segoe UI", 10);

            txtEmail = gcnew TextBox();
            txtEmail->Location = Point(30, 285);
            txtEmail->Size = Drawing::Size(195, 22);
            txtEmail->Font = gcnew Drawing::Font("Segoe UI", 10);

            // ── BOTÓN GUARDAR ──
            btnGuardar = gcnew Button();
            btnGuardar->Text = "Guardar";
            btnGuardar->Location = Point(30, 355);
            btnGuardar->Size = Drawing::Size(195, 42);
            btnGuardar->BackColor = Color::FromArgb(110, 181, 232);
            btnGuardar->ForeColor = Color::White;
            btnGuardar->FlatStyle = FlatStyle::Flat;
            btnGuardar->FlatAppearance->BorderSize = 0;
            btnGuardar->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            btnGuardar->Click += gcnew EventHandler(this, &frmClientes::btnGuardar_Click);

            // ── BOTÓN ELIMINAR ──
            btnEliminar = gcnew Button();
            btnEliminar->Text = "Eliminar";
            btnEliminar->Location = Point(30, 408);
            btnEliminar->Size = Drawing::Size(195, 42);
            btnEliminar->BackColor = Color::FromArgb(75, 143, 179);
            btnEliminar->ForeColor = Color::White;
            btnEliminar->FlatStyle = FlatStyle::Flat;
            btnEliminar->FlatAppearance->BorderSize = 0;
            btnEliminar->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            btnEliminar->Click += gcnew EventHandler(this, &frmClientes::btnEliminar_Click);

            // ── BOTÓN REGRESAR ──
            btnRegresar = gcnew Button();
            btnRegresar->Text = "Regresar al Menú";
            btnRegresar->Location = Point(30, 465);
            btnRegresar->Size = Drawing::Size(195, 42);
            btnRegresar->BackColor = Color::FromArgb(84, 153, 211);
            btnRegresar->ForeColor = Color::White;
            btnRegresar->FlatStyle = FlatStyle::Flat;
            btnRegresar->FlatAppearance->BorderSize = 0;
            btnRegresar->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            btnRegresar->Click += gcnew EventHandler(this, &frmClientes::btnRegresar_Click);

            // ── DATAGRIDVIEW ──
            dgvClientes = gcnew DataGridView();
            dgvClientes->Location = Point(260, 90);
            dgvClientes->Size = Drawing::Size(610, 400);
            dgvClientes->BackgroundColor = Color::White;
            dgvClientes->BorderStyle = BorderStyle::FixedSingle;
            dgvClientes->AllowUserToAddRows = false;
            dgvClientes->AllowUserToDeleteRows = false;
            dgvClientes->ReadOnly = true;
            dgvClientes->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            dgvClientes->MultiSelect = false;
            dgvClientes->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dgvClientes->RowHeadersVisible = false;
            dgvClientes->RowTemplate->Height = 28;
            dgvClientes->ColumnHeadersHeight = 34;
            dgvClientes->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(84, 153, 211);
            dgvClientes->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            dgvClientes->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            dgvClientes->DefaultCellStyle->Font = gcnew Drawing::Font("Segoe UI", 10);
            dgvClientes->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(220, 233, 245);
            dgvClientes->DefaultCellStyle->SelectionBackColor = Color::FromArgb(110, 181, 232);
            dgvClientes->DefaultCellStyle->SelectionForeColor = Color::White;
            dgvClientes->EnableHeadersVisualStyles = false;
            dgvClientes->CellClick += gcnew DataGridViewCellEventHandler(this, &frmClientes::dgvClientes_CellClick);

            // ── LABEL CONTEO ──
            lblConteo = gcnew Label();
            lblConteo->Location = Point(260, 500);
            lblConteo->AutoSize = true;
            lblConteo->Font = gcnew Drawing::Font("Segoe UI", 9);
            lblConteo->ForeColor = Color::FromArgb(90, 90, 90);

            // ── AGREGAR CONTROLES ──
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

        void CargarTodosLosClientes() {
            List<Cliente^>^ lista = ControladorCliente().listarClientes();
            Mostrar(lista);
        }

        void Mostrar(List<Cliente^>^ lista) {
            dgvClientes->Rows->Clear();
            dgvClientes->Columns->Clear();
            dgvClientes->Columns->Add("id", "ID");
            dgvClientes->Columns->Add("nit", "NIT");
            dgvClientes->Columns->Add("nombre", "Nombre");
            dgvClientes->Columns->Add("telefono", "Teléfono");
            dgvClientes->Columns->Add("email", "Email");
            dgvClientes->Columns["id"]->Visible = false;

            for each(Cliente ^ c in lista) {
                dgvClientes->Rows->Add(
                    c->id_cliente,
                    c->nit,
                    c->nombre,
                    c->telefono,
                    c->email
                );
            }

            lblConteo->Text = lista->Count.ToString() + " clientes";
        }

        void LimpiarFormulario() {
            idClienteSeleccionado = 0;
            txtNIT->Clear();
            txtNombre->Clear();
            txtTelefono->Clear();
            txtEmail->Clear();
            txtNIT->Focus();
        }

        void btnGuardar_Click(Object^ sender, EventArgs^ e) {
            Cliente^ c = gcnew Cliente();
            c->id_cliente = idClienteSeleccionado;
            c->nit = txtNIT->Text;
            c->nombre = txtNombre->Text;
            c->telefono = txtTelefono->Text;
            c->email = txtEmail->Text;
            ControladorCliente().guardarCliente(c);
            CargarTodosLosClientes();
            LimpiarFormulario();
            MessageBox::Show("Cliente guardado correctamente");
        }

        void btnEliminar_Click(Object^ sender, EventArgs^ e) {
            if (idClienteSeleccionado == 0) {
                MessageBox::Show("Seleccione un cliente");
                return;
            }
            if (MessageBox::Show("¿Eliminar cliente?", "Confirmar", MessageBoxButtons::YesNo)
                == System::Windows::Forms::DialogResult::Yes) {
                ControladorCliente().eliminarCliente(idClienteSeleccionado);
                CargarTodosLosClientes();
                LimpiarFormulario();
                MessageBox::Show("Cliente eliminado");
            }
        }

        void btnRegresar_Click(Object^ sender, EventArgs^ e) {
            this->Close();
        }

        void dgvClientes_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
            if (e->RowIndex < 0) return;
            DataGridViewRow^ fila = dgvClientes->Rows[e->RowIndex];
            idClienteSeleccionado = Convert::ToInt32(fila->Cells["id"]->Value);
            txtNIT->Text = fila->Cells["nit"]->Value->ToString();
            txtNombre->Text = fila->Cells["nombre"]->Value->ToString();
            txtTelefono->Text = fila->Cells["telefono"]->Value->ToString();
            txtEmail->Text = fila->Cells["email"]->Value->ToString();
        }
    };
}