#include "user_interface.h"

using namespace dll_mix_gui_1;

int UIMain()
{
	//THIS CODE is required to start our User interface
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	user_interface^ NewUi = gcnew user_interface();
	Application::Run(NewUi); //Run our New user interface (linking to "User_Interface.h")
	return 1;
}