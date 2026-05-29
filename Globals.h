#pragma once
using namespace System;

namespace Globals {
    public ref class Datos {
    public:
        static String^ rolActivo = "";
        static String^ nombreActivo = "";
        static String^ usuarioActivo = "";
        static int idUsuarioActivo = 0;
        static int idTiendaActiva = 0;
    };
}