#pragma once
#include "ControladorUsuario.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

namespace Supermercado {

    public ref class frmUsuarios : public Form {

    private:

        int idUsuarioSeleccionado;

        TextBox^ txtNombre;
        TextBox^ txtUsuario;
        TextBox^ txtPassword;

        ComboBox^ cmbRol;
        ComboBox^ cmbTienda;

        Button^ btnGuardar;
        Button^ btnEliminar;
        Button^ btnRegresar;

        DataGridView^ dgvUsuarios;
        Label^ lblConteo;

        Panel^ panel1;
        Panel^ panel2;

        System::Collections::Generic::Dictionary<String^, int>^ mapaTiendas;

    public:

        frmUsuarios() {

            idUsuarioSeleccionado = 0;
            mapaTiendas = gcnew System::Collections::Generic::Dictionary<String^, int>();

            CrearInterfaz();
            CargarTiendas();
            CargarUsuarios();
        }

    private:

        void CrearInterfaz() {

            this->Text = "Usuarios";
            this->Size = Drawing::Size(950, 580);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = Color::FromArgb(245, 247, 250);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;

            // ── FRANJA IZQUIERDA ──
            panel2 = gcnew Panel();
            panel2->BackColor = Color::FromArgb(110, 181, 232);
            panel2->Location = Point(0, 52);
            panel2->Size = Drawing::Size(57, 22);
            this->Controls->Add(panel2);

            // ── FRANJA DERECHA ──
            panel1 = gcnew Panel();
            panel1->BackColor = Color::FromArgb(110, 181, 232);
            panel1->Location = Point(280, 52);
            panel1->Size = Drawing::Size(670, 22);
            this->Controls->Add(panel1);

            // ── TITULO ──
            Label^ lblTitulo = gcnew Label();
            lblTitulo->Text = "Gestión de Usuarios";
            lblTitulo->Font = gcnew Drawing::Font("Century Schoolbook", 20, FontStyle::Bold);
            lblTitulo->BackColor = Color::Transparent;
            lblTitulo->ForeColor = Color::FromArgb(30, 30, 30);
            lblTitulo->Location = Point(70, 15);
            lblTitulo->AutoSize = true;

            // ── LABELS ──
            Label^ lblNombre = gcnew Label();
            lblNombre->Text = "Nombre:";
            lblNombre->Location = Point(30, 100);
            lblNombre->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);

            Label^ lblUsuario = gcnew Label();
            lblUsuario->Text = "Usuario:";
            lblUsuario->Location = Point(30, 160);
            lblUsuario->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);

            Label^ lblPassword = gcnew Label();
            lblPassword->Text = "Contraseña:";
            lblPassword->Location = Point(30, 220);
            lblPassword->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);

            Label^ lblRol = gcnew Label();
            lblRol->Text = "Rol:";
            lblRol->Location = Point(30, 275);
            lblRol->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);

            Label^ lblTienda = gcnew Label();
            lblTienda->Text = "Tienda:";
            lblTienda->Location = Point(30, 330);
            lblTienda->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);

            // ── TEXTBOX ──
            txtNombre = gcnew TextBox();
            txtNombre->Location = Point(30, 125);
            txtNombre->Size = Drawing::Size(220, 28);
            txtNombre->Font = gcnew Drawing::Font("Segoe UI", 10);

            txtUsuario = gcnew TextBox();
            txtUsuario->Location = Point(30, 185);
            txtUsuario->Size = Drawing::Size(220, 28);
            txtUsuario->Font = gcnew Drawing::Font("Segoe UI", 10);

            txtPassword = gcnew TextBox();
            txtPassword->Location = Point(30, 245);
            txtPassword->Size = Drawing::Size(220, 28);
            txtPassword->Font = gcnew Drawing::Font("Segoe UI", 10);
            txtPassword->PasswordChar = '*';

            // ── COMBOBOX ROL ──
            cmbRol = gcnew ComboBox();
            cmbRol->Location = Point(30, 300);
            cmbRol->Size = Drawing::Size(220, 28);
            cmbRol->Font = gcnew Drawing::Font("Segoe UI", 10);
            cmbRol->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbRol->Items->Add("vendedor");
            cmbRol->Items->Add("admin");
            cmbRol->SelectedIndex = 0;

            // ── COMBOBOX TIENDA ──
            cmbTienda = gcnew ComboBox();
            cmbTienda->Location = Point(30, 355);
            cmbTienda->Size = Drawing::Size(220, 28);
            cmbTienda->Font = gcnew Drawing::Font("Segoe UI", 10);
            cmbTienda->DropDownStyle = ComboBoxStyle::DropDownList;

            // ── BOTÓN GUARDAR ──
            btnGuardar = gcnew Button();
            btnGuardar->Text = "Guardar";
            btnGuardar->Location = Point(30, 410);
            btnGuardar->Size = Drawing::Size(105, 40);
            btnGuardar->BackColor = Color::FromArgb(110, 181, 232);
            btnGuardar->ForeColor = Color::White;
            btnGuardar->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);
            btnGuardar->FlatStyle = FlatStyle::Flat;
            btnGuardar->FlatAppearance->BorderSize = 0;
            btnGuardar->Click += gcnew EventHandler(this, &frmUsuarios::btnGuardar_Click);

            // ── BOTÓN ELIMINAR ──
            btnEliminar = gcnew Button();
            btnEliminar->Text = "Eliminar";
            btnEliminar->Location = Point(145, 410);
            btnEliminar->Size = Drawing::Size(105, 40);
            btnEliminar->BackColor = Color::FromArgb(75, 143, 179);
            btnEliminar->ForeColor = Color::White;
            btnEliminar->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);
            btnEliminar->FlatStyle = FlatStyle::Flat;
            btnEliminar->FlatAppearance->BorderSize = 0;
            btnEliminar->Click += gcnew EventHandler(this, &frmUsuarios::btnEliminar_Click);

            // ── BOTÓN REGRESAR ──
            btnRegresar = gcnew Button();
            btnRegresar->Text = "Regresar al Menú";
            btnRegresar->Location = Point(30, 470);
            btnRegresar->Size = Drawing::Size(220, 40);
            btnRegresar->BackColor = Color::FromArgb(84, 153, 211);
            btnRegresar->ForeColor = Color::White;
            btnRegresar->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);
            btnRegresar->FlatStyle = FlatStyle::Flat;
            btnRegresar->FlatAppearance->BorderSize = 0;
            btnRegresar->Click += gcnew EventHandler(this, &frmUsuarios::btnRegresar_Click);

            // ── DATAGRIDVIEW ──
            dgvUsuarios = gcnew DataGridView();
            dgvUsuarios->Location = Point(280, 90);
            dgvUsuarios->Size = Drawing::Size(650, 430);
            dgvUsuarios->BackgroundColor = Color::White;
            dgvUsuarios->BorderStyle = BorderStyle::FixedSingle;
            dgvUsuarios->ColumnHeadersHeight = 34;
            dgvUsuarios->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(84, 153, 211);
            dgvUsuarios->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            dgvUsuarios->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            dgvUsuarios->EnableHeadersVisualStyles = false;
            dgvUsuarios->DefaultCellStyle->Font = gcnew Drawing::Font("Segoe UI", 10);
            dgvUsuarios->DefaultCellStyle->SelectionBackColor = Color::FromArgb(110, 181, 232);
            dgvUsuarios->DefaultCellStyle->SelectionForeColor = Color::White;
            dgvUsuarios->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(220, 233, 245);
            dgvUsuarios->AllowUserToAddRows = false;
            dgvUsuarios->AllowUserToDeleteRows = false;
            dgvUsuarios->ReadOnly = true;
            dgvUsuarios->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            dgvUsuarios->MultiSelect = false;
            dgvUsuarios->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dgvUsuarios->RowHeadersVisible = false;
            dgvUsuarios->RowTemplate->Height = 28;
            dgvUsuarios->CellClick += gcnew DataGridViewCellEventHandler(this, &frmUsuarios::dgvUsuarios_CellClick);

            // ── LABEL CONTEO ──
            lblConteo = gcnew Label();
            lblConteo->Location = Point(280, 530);
            lblConteo->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            lblConteo->ForeColor = Color::FromArgb(84, 153, 211);
            lblConteo->AutoSize = true;

            // ── AGREGAR CONTROLES ──
            this->Controls->Add(lblTitulo);
            this->Controls->Add(lblNombre);
            this->Controls->Add(lblUsuario);
            this->Controls->Add(lblPassword);
            this->Controls->Add(lblRol);
            this->Controls->Add(lblTienda);
            this->Controls->Add(txtNombre);
            this->Controls->Add(txtUsuario);
            this->Controls->Add(txtPassword);
            this->Controls->Add(cmbRol);
            this->Controls->Add(cmbTienda);
            this->Controls->Add(btnGuardar);
            this->Controls->Add(btnEliminar);
            this->Controls->Add(btnRegresar);
            this->Controls->Add(dgvUsuarios);
            this->Controls->Add(lblConteo);
        }

        void CargarTiendas() {
            try {
                ConexionBD^ db = gcnew ConexionBD();
                if (db->conexionActiva()) {
                    String^ sql = "SELECT id_tienda, nombre FROM TIENDA ORDER BY nombre";
                    MySql::Data::MySqlClient::MySqlCommand^ cmd =
                        gcnew MySql::Data::MySqlClient::MySqlCommand(sql, db->getConexion());
                    MySql::Data::MySqlClient::MySqlDataReader^ reader = cmd->ExecuteReader();

                    mapaTiendas->Clear();
                    cmbTienda->Items->Clear();

                    while (reader->Read()) {
                        String^ nombre = reader["nombre"]->ToString();
                        int id = Convert::ToInt32(reader["id_tienda"]);
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
                MessageBox::Show("Error al cargar tiendas: " + ex->Message);
            }
        }

        void CargarUsuarios() {

            List<Usuario^>^ lista = ControladorUsuario().listarUsuarios();

            dgvUsuarios->Rows->Clear();
            dgvUsuarios->Columns->Clear();

            dgvUsuarios->Columns->Add("id", "ID");
            dgvUsuarios->Columns->Add("nombre", "Nombre");
            dgvUsuarios->Columns->Add("usuario", "Usuario");
            dgvUsuarios->Columns->Add("rol", "Rol");
            dgvUsuarios->Columns->Add("id_tienda", "Tienda ID");

            dgvUsuarios->Columns["id"]->Visible = false;
            dgvUsuarios->Columns["id_tienda"]->Visible = false;

            for each (Usuario ^ u in lista) {
                dgvUsuarios->Rows->Add(
                    u->id_usuario,
                    u->nombre,
                    u->usuario,
                    u->rol,
                    u->id_tienda
                );
            }

            lblConteo->Text = lista->Count.ToString() + " usuarios";
        }

        void LimpiarFormulario() {
            idUsuarioSeleccionado = 0;
            txtNombre->Clear();
            txtUsuario->Clear();
            txtPassword->Clear();
            cmbRol->SelectedIndex = 0;
            if (cmbTienda->Items->Count > 0)
                cmbTienda->SelectedIndex = 0;
            txtNombre->Focus();
        }


        void btnGuardar_Click(Object^ sender, EventArgs^ e) {

            if (txtNombre->Text->Trim() == "" ||
                txtUsuario->Text->Trim() == "" ||
                txtPassword->Text->Trim() == "") {
                MessageBox::Show("Nombre, usuario y contraseña son obligatorios.", "Validación");
                return;
            }

            Usuario^ u = gcnew Usuario();
            u->id_usuario = idUsuarioSeleccionado;
            u->nombre = txtNombre->Text->Trim();
            u->usuario = txtUsuario->Text->Trim();
            u->password = txtPassword->Text->Trim();
            u->rol = cmbRol->SelectedItem->ToString();

            String^ tiendaNombre = cmbTienda->SelectedItem->ToString();
            if (mapaTiendas->ContainsKey(tiendaNombre))
                u->id_tienda = mapaTiendas[tiendaNombre];
            else
                u->id_tienda = 1;

            bool ok = ControladorUsuario().guardarUsuario(u);

            if (ok) {
                MessageBox::Show(idUsuarioSeleccionado == 0
                    ? "Usuario creado correctamente."
                    : "Usuario actualizado correctamente.");
                CargarUsuarios();
                LimpiarFormulario();
            }
        }


        void btnEliminar_Click(Object^ sender, EventArgs^ e) {

            if (idUsuarioSeleccionado == 0) {
                MessageBox::Show("Seleccione un usuario de la tabla.");
                return;
            }

            if (MessageBox::Show(
                "¿Eliminar este usuario?",
                "Confirmar",
                MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {

                bool ok = ControladorUsuario().eliminarUsuario(idUsuarioSeleccionado);

                if (ok) {
                    MessageBox::Show("Usuario eliminado.");
                    CargarUsuarios();
                    LimpiarFormulario();
                }
            }
        }


        void btnRegresar_Click(Object^ sender, EventArgs^ e) {
            this->Close();
        }


        void dgvUsuarios_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {

            if (e->RowIndex < 0) return;

            DataGridViewRow^ fila = dgvUsuarios->Rows[e->RowIndex];

            idUsuarioSeleccionado = Convert::ToInt32(fila->Cells["id"]->Value);
            txtNombre->Text = fila->Cells["nombre"]->Value->ToString();
            txtUsuario->Text = fila->Cells["usuario"]->Value->ToString();
            txtPassword->Text = "";
            cmbRol->SelectedItem = fila->Cells["rol"]->Value->ToString();

            int idTienda = Convert::ToInt32(fila->Cells["id_tienda"]->Value);
            for each (System::Collections::Generic::KeyValuePair<String^, int> kvp in mapaTiendas) {
                if (kvp.Value == idTienda) {
                    cmbTienda->SelectedItem = kvp.Key;
                    break;
                }
            }
        }
    };
}