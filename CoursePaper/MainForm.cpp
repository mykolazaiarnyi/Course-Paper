#include "MainForm.h"
#include "Gateway.h"

using namespace System;
using namespace System::Windows::Forms;



[STAThreadAttribute]
void Main(array<String^>^ args)
{
	Gateway::thread->Start();
	DBConnecter::DBConnecter();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CoursePaper::MainForm form;
	Application::Run(%form);
}