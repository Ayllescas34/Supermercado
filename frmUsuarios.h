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

        // Mapeo tienda nombre -> id
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
            this->Size = Drawing::Size(900, 550);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = Color::Gainsboro;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;

            // ── TITULO ──
            Label^ lblTitulo = gcnew Label();
            lblTitulo->Text = "Usuarios";
            lblTitulo->Font = gcnew Drawing::Font("Times New Roman", 16, FontStyle::Bold);
            lblTitulo->BackColor = Color::LightSteelBlue;
            lblTitulo->Location = Point(30, 20);
            lblTitulo->AutoSize = true;

            // ── LABELS ──
            Label^ lblNombre = gcnew Label(); lblNombre->Text = "Nombre:";     lblNombre->Location = Point(30, 80);
            Label^ lblUsuario = gcnew Label(); lblUsuario->Text = "Usuario:";    lblUsuario->Location = Point(30, 140);
            Label^ lblPassword = gcnew Label(); lblPassword->Text = "Contraseña:"; lblPassword->Location = Point(30, 200);
            Label^ lblRol = gcnew Label(); lblRol->Text = "Rol:";        lblRol->Location = Point(30, 260);
            Label^ lblTienda = gcnew Label(); lblTienda->Text = "Tienda:";     lblTienda->Location = Point(30, 310);

            // ── TEXTBOX ──
            txtNombre = gcnew TextBox();
            txtNombre->Location = Point(30, 100);
            txtNombre->Size = Drawing::Size(180, 22);

            txtUsuario = gcnew TextBox();
            txtUsuario->Location = Point(30, 160);
            txtUsuario->Size = Drawing::Size(180, 22);

            txtPassword = gcnew TextBox();
            txtPassword->Location = Point(30, 220);
            txtPassword->Size = Drawing::Size(180, 22);
            txtPassword->PasswordChar = '*';

            // ── COMBOBOX ROL ──
            cmbRol = gcnew ComboBox();
            cmbRol->Location = Point(30, 278);
            cmbRol->Size = Drawing::Size(180, 22);
            cmbRol->DropDownStyle = ComboBoxStyle::DropDownList;
            cmbRol->Items->Add("vendedor");
            cmbRol->Items->Add("admin");
            cmbRol->SelectedIndex = 0;

            // ── COMBOBOX TIENDA ──
            cmbTienda = gcnew ComboBox();
            cmbTienda->Location = Point(30, 328);
            cmbTienda->Size = Drawing::Size(180, 22);
            cmbTienda->DropDownStyle = ComboBoxStyle::DropDownList;

            // ── BOTÓN GUARDAR ──
            btnGuardar = gcnew Button();
            btnGuardar->Text = "Guardar";
            btnGuardar->Location = Point(30, 390);
            btnGuardar->Size = Drawing::Size(90, 35);
            btnGuardar->BackColor = Color::LightSteelBlue;
            btnGuardar->FlatStyle = FlatStyle::Flat;
            btnGuardar->Click += gcnew EventHandler(this, &frmUsuarios::btnGuardar_Click);

            // ── BOTÓN ELIMINAR ──
            btnEliminar = gcnew Button();
            btnEliminar->Text = "Eliminar";
            btnEliminar->Location = Point(140, 390);
            btnEliminar->Size = Drawing::Size(90, 35);
            btnEliminar->BackColor = Color::LightGray;
            btnEliminar->FlatStyle = FlatStyle::Flat;
            btnEliminar->Click += gcnew EventHandler(this, &frmUsuarios::btnEliminar_Click);

            // ── BOTÓN REGRESAR ──
            btnRegresar = gcnew Button();
            btnRegresar->Text = "Regresar al Menú";
            btnRegresar->Location = Point(30, 445);
            btnRegresar->Size = Drawing::Size(200, 35);
            btnRegresar->BackColor = Color::Silver;
            btnRegresar->FlatStyle = FlatStyle::Flat;
            btnRegresar->Click += gcnew EventHandler(this, &frmUsuarios::btnRegresar_Click);

            // ── DATAGRIDVIEW ──
            dgvUsuarios = gcnew DataGridView();
            dgvUsuarios->Location = Point(280, 40);
            dgvUsuarios->Size = Drawing::Size(570, 400);
            dgvUsuarios->BackgroundColor = Color::WhiteSmoke;
            dgvUsuarios->BorderStyle = BorderStyle::FixedSingle;
            dgvUsuarios->AllowUserToAddRows = false;
            dgvUsuarios->AllowUserToDeleteRows = false;
            dgvUsuarios->ReadOnly = true;
            dgvUsuarios->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            dgvUsuarios->MultiSelect = false;
            dgvUsuarios->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dgvUsuarios->RowHeadersVisible = false;
            dgvUsuarios->CellClick += gcnew DataGridViewCellEventHandler(this, &frmUsuarios::dgvUsuarios_CellClick);

            // ── LABEL CONTEO ──
            lblConteo = gcnew Label();
            lblConteo->Location = Point(280, 460);
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

        // =====================================================
        // CARGAR TIENDAS al ComboBox desde DB
        // =====================================================
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

        // =====================================================
        // CARGAR USUARIOS en el DataGridView
        // =====================================================
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

        // =====================================================
        // LIMPIAR FORMULARIO
        // =====================================================
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

            // Obtener id_tienda desde el mapa
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
            txtPassword->Text = "";   // no mostramos la contraseña por seguridad
            cmbRol->SelectedItem = fila->Cells["rol"]->Value->ToString();

            // Buscar tienda por id en el mapa inverso
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