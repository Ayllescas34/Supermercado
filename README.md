# 🏪 SUPERMERCADO GRUPO 8
## Sistema de Gestión Integral

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Windows Forms](https://img.shields.io/badge/Windows%20Forms-.NET-blue?style=for-the-badge)
![MySQL](https://img.shields.io/badge/MySQL-005C84?style=for-the-badge&logo=mysql&logoColor=white)
![Status](https://img.shields.io/badge/Status-COMPLETO-success?style=for-the-badge)

---

## 📋 Descripción General

**Supermercado Grupo 8** es un sistema de gestión integral desarrollado en **C++ con Windows Forms** que permite administrar de manera eficiente todas las operaciones de un supermercado moderno. Desde la gestión de inventarios hasta el procesamiento de ventas, este sistema ofrece una solución completa y profesional.

### ✨ Características Principales

- 🛒 **Gestión de Ventas**: Sistema de 3 fases (Cliente → Productos → Pago)
- 📦 **Control de Inventario**: Seguimiento en tiempo real de stock por tienda
- 👥 **Administración de Clientes**: Registro y búsqueda de clientes con NIT
- 🏷️ **Catálogo de Productos**: 10 categorías con 100+ productos
- 👤 **Control de Usuarios**: 3 roles (Admin, Vendedor, etc.)
- 📊 **Historial de Ventas**: Reporte completo de transacciones
- 🎨 **Interfaz Moderna**: Diseño profesional con paleta azul cohesiva
- 🏢 **Multi-tienda**: Soporte para múltiples ubicaciones

---

## 🛠️ Stack Tecnológico

| Componente | Tecnología |
|-----------|-----------|
| **Lenguaje** | C++ (C++/CLI) |
| **UI Framework** | Windows Forms (.NET) |
| **Base de Datos** | MySQL 5.7+ |
| **IDE** | Visual Studio 2019+ |
| **Arquitectura** | Patrón MVC (3 capas) |

---

## 📦 Requisitos del Sistema

### Hardware
- Procesador: 1.5 GHz mínimo
- RAM: 4 GB mínimo
- Almacenamiento: 500 MB
- Pantalla: 1024x768 resolución mínima

### Software
- **Sistema Operativo**: Windows 7/8/10/11
- **Visual Studio**: 2019 Community Edition o superior
- **MySQL Server**: 5.7 o superior
- **.NET Framework**: 4.7.2 o superior

### Componentes Adicionales
- MySQL Connector/C++ 1.1.14
- Microsoft Visual C++ Redistributable 2019+

---

## 🚀 Instalación y Configuración

### 1️⃣ Clonar el Repositorio
```bash
git clone https://github.com/Ayllescas34/supermercado-g8.git
cd supermercado-g8
git checkout develop
```

### 2️⃣ Configurar la Base de Datos
```bash
# Crear la base de datos
mysql -u root -p < supermercado_db.sql

# O usar el script completo
mysql -u root -p < supermercado_g8_completo.sql
```

### 3️⃣ Configurar Credenciales de BD
Editar en `ConexionBD.h` o archivo de configuración:
```cpp
const String^ SERVIDOR = "localhost";
const String^ USUARIO = "root";
const String^ CONTRASENA = "tu_contrasena";
const String^ BASE_DATOS = "supermercado_g8";
```

### 4️⃣ Compilar en Visual Studio
```
1. Abrir supermercado-g8.sln
2. Build → Rebuild Solution
3. F5 para ejecutar (Debug) o Ctrl+F5 (Release)
```

---

## 📊 Estructura de la Base de Datos

### Tablas Principales

| Tabla | Descripción |
|-------|------------|
| **TIENDA** | Ubicaciones del supermercado |
| **USUARIO** | Cajeros y administradores |
| **CLIENTE** | Datos de clientes (NIT, teléfono, email) |
| **PRODUCTO** | Catálogo con código de barras y precio |
| **CATEGORIA** | 10 categorías de productos |
| **INVENTARIO** | Stock por producto y tienda |
| **VENTA** | Registro de transacciones |
| **DETALLE_VENTA** | Líneas de cada venta |

---

## 👥 Usuarios de Prueba

| Rol | Usuario | Contraseña | Tienda |
|-----|---------|-----------|--------|
| Admin | `jmorales` | `admin123` | Central Z9 |
| Vendedor | `melopez` | `vend123` | Central Z9 |
| Admin | `lchen` | `admin123` | Mixco |
| Vendedor | `agarcia` | `vend123` | Villa Nueva |

---

## 🎨 Paleta de Colores Oficial

```
Azul Base:         #6EB5E8 (110, 181, 232)   — Botones principales
Azul Oscuro:       #5499D3 (84, 153, 211)    — Headers y acentos
Azul Muy Oscuro:   #4B8FB3 (75, 143, 179)    — Detalles
Azul Claro:        #DCE9F5 (220, 233, 245)   — Fondos alternativos
Fondo Principal:   #F5F7FA (245, 247, 250)   — Backgrounds
```

---

## 📱 Pantallas Principales

### 🔐 1. Login
- Autenticación segura
- Validación contra base de datos
- Recuperación de credenciales

### 🏠 2. Menú Principal
- Acceso a todos los módulos
- Diferentes opciones según rol (Admin/Vendedor)
- Información del usuario activo

### 🛒 3. Nueva Venta (3 Fases)

#### **Fase 1: Seleccionar Cliente**
- Búsqueda por NIT o nombre
- Opción "Consumidor Final"
- Crear cliente rápidamente

#### **Fase 2: Agregar Productos**
- Búsqueda por código o nombre
- Ajustar cantidades
- Stack de deshacer último producto
- Vista en tiempo real del carrito

#### **Fase 3: Procesar Pago**
- Método de pago (Efectivo/Tarjeta)
- Cálculo automático de cambio
- Validación de monto
- Confirmación y ticket

### 📦 4. Gestión de Productos
- CRUD completo
- Búsqueda avanzada
- Organización por categoría
- Código de barras

### 📊 5. Inventario
- Visualización por tienda
- Stock disponible
- Stock mínimo alertas
- Actualización de cantidades

### 📈 6. Historial de Ventas
- Reporte por rango de fechas
- Detalles de cada transacción
- Totales por período

### 👤 7. Gestión de Usuarios
- Crear/Editar/Eliminar usuarios
- Asignación de roles
- Asociación a tiendas

### 👥 8. Gestión de Clientes
- Base de datos de clientes
- Búsqueda por NIT
- Historial de compras

### 🔍 9. Consulta de Productos
- Búsqueda rápida
- Filtro por categoría
- Información de precio y disponibilidad

---

## 🏗️ Arquitectura del Sistema

```
┌─────────────────────────────────────┐
│       Capa de Presentación          │
│   (Windows Forms - 10 Formularios)  │
├─────────────────────────────────────┤
│      Capa de Lógica de Negocio      │
│  (Controladores - 7 Controladores)  │
├─────────────────────────────────────┤
│       Capa de Acceso a Datos        │
│   (BD MySQL + Modelos de Datos)     │
└─────────────────────────────────────┘
```

### Componentes Clave

**Formularios (frmX.h)**
- frmLogin
- frmMenu
- frmVenta
- frmProductos
- frmInventario
- frmHistorialVentas
- frmUsuarios
- frmClientes
- frmConsultaProductos
- frmClienteRapido

**Controladores (ControladorX.h/cpp)**
- ControladorUsuario
- ControladorProducto
- ControladorCliente
- ControladorVenta
- ControladorInventario
- Y más...

**Modelos (ModeloX.h)**
- Usuario
- Producto
- Cliente
- Venta
- Y más...

---

## 🔐 Seguridad

✅ **Autenticación**: Validación de usuario y contraseña contra BD  
✅ **Autorización**: Control de acceso por roles  
✅ **Validaciones**: Entrada de datos y consistencia  
✅ **Transacciones**: Integridad en operaciones críticas  
✅ **IVA**: Cálculo automático del 12%  

---

## 💾 Cálculos Importantes

### IVA (Impuesto al Valor Agregado)
```
Subtotal = Suma de (Cantidad × Precio Unitario)
IVA (12%) = Subtotal × 0.12
TOTAL = Subtotal + IVA
```

### Cambio en Venta
```
Si Método = Efectivo:
  Si Monto Recibido >= Total:
    Cambio = Monto Recibido - Total
  Sino:
    Error: Monto insuficiente
```

---

## 📝 Uso del Sistema

### Proceso de Venta Completo

```
1. Login
   └─ Ingresar usuario/contraseña
   
2. Menú Principal
   └─ Seleccionar "Nueva Venta"
   
3. Fase 1: Cliente
   └─ Buscar cliente o seleccionar "Consumidor Final"
   └─ Siguiente →
   
4. Fase 2: Productos
   └─ Buscar producto por código/nombre
   └─ Seleccionar producto
   └─ Ingresar cantidad
   └─ Agregar al carrito
   └─ Repetir según sea necesario
   └─ Ir a Pago →
   
5. Fase 3: Pago
   └─ Seleccionar método (Efectivo/Tarjeta)
   └─ Si Efectivo: Ingresar monto recibido
   └─ Sistema calcula cambio automáticamente
   └─ Confirmar Venta
   └─ Ticket generado ✓
```

---

## 🐛 Solución de Problemas

### Error de Conexión a BD
```
Solución:
1. Verificar MySQL Server está corriendo
2. Confirmar credenciales en ConexionBD.h
3. Verificar firewall permite puerto 3306
4. Recrear base de datos con script SQL
```

### Formularios no cargan
```
Solución:
1. Verificar .NET Framework 4.7.2+
2. Limpiar solución (Clean Solution)
3. Reconstruir solución (Rebuild Solution)
4. Verificar rutas de includes
```

### Productos no aparecen
```
Solución:
1. Verificar tabla PRODUCTO tiene datos
2. Ejecutar: SELECT COUNT(*) FROM producto;
3. Si está vacía, ejecutar script de datos
```

---

## 📞 Equipo de Desarrollo

| Rol | Integrante | Módulos |
|-----|-----------|---------|
| **Líder** | Alejandro | frmVenta, frmUsuarios, frmLogin, frmMenu |
| **Developer** | Majo | frmClientes, frmHistorialVentas |
| **Developer** | Emmanuel | frmProductos, frmConsultaProductos |
| **Developer** | Daniela | frmInventario, frmHistorialVentas |

---


<div align="center">

### 🌟 Desarrollado con ❤️ por Grupo 8

**Supermercado Grupo 8 © 2024-2025**

![Version](https://img.shields.io/badge/Version-1.0.0-blue?style=flat-square)
![Build](https://img.shields.io/badge/Build-Passing-success?style=flat-square)
![Status](https://img.shields.io/badge/Status-Production%20Ready-green?style=flat-square)

</div>
