#pragma once

using namespace System;
using namespace System::Windows::Forms;

ref class Atm
{
	Panel^ atmPanel;	
	Control^ validationPanel;
public:
	Control^ menuPanel;
	Control^ transferPanel;
	Control^ withdrawPanel;
	Control^ atmMessage;
	Atm(Panel^ atmPanel);
	void checkValid(Object^ sender, EventArgs^ e);
	void goToTransfer(Object^ sender, EventArgs^ e);
	void goToWithdraw(Object^ sender, EventArgs^ e);
	void exit(Object^ sender, EventArgs^ e);
	void makeTransfer(Object^ sender, EventArgs^ e);
	void makeWithdraw(Object^ sender, EventArgs^ e);
	void back(Object^ sender, EventArgs^ e);
};

