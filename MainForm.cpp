#include "MainForm.h"
#include "frmLogin.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Supermercado;

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew frmLogin());
}