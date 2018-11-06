#include "Atm.h"
#include "DBConnecter.h"

using namespace System;
using namespace System::Windows::Forms;

Atm::Atm(Panel^ atmPanel)
{
	this->atmPanel = atmPanel;
}

void Atm::checkValid(Object^ sender, EventArgs^ e)
{
	try {
		auto controls = atmPanel->Controls;
		auto validationPanel = controls[0];
		long long number = Int64::Parse(validationPanel->Controls[1]->Text);
		int pin = Int32::Parse(validationPanel->Controls[3]->Text);
		if (DBConnecter::checkValid(number, pin, controls[4])->Equals(true))
		{
			controls[4]->Text = "Choose an option";
			validationPanel->Hide();
			controls[1]->Show();
		}
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK);
	}
}

void Atm::goToTransfer(Object^ sender, EventArgs^ e)
{
	auto controls = atmPanel->Controls;
	controls[2]->Show();
	controls[1]->Hide();
	controls[4]->Text = "Insert number\n and amount";
}

void Atm::goToWithdraw(Object^ sender, EventArgs^ e)
{
	auto controls = atmPanel->Controls;
	controls[3]->Show();
	controls[1]->Hide();
	controls[4]->Text = "Insert amount";
}

void Atm::exit(Object^ sender, EventArgs^ e)
{
	auto controls = atmPanel->Controls;
	controls[0]->Show();
	controls[1]->Hide();
	controls[4]->Text = L"Insert card number \r\n        and PIN";
	auto validationPanel = controls[0];
	validationPanel->Controls[1]->Text = "";
	validationPanel->Controls[3]->Text = "";
}

void Atm::makeTransfer(Object^ sender, EventArgs^ e)
{
	try {
		auto controls = atmPanel->Controls;
		auto transferPanel = controls[2];
		long long receiver = Int64::Parse(transferPanel->Controls[1]->Text);
		long long _sender = Int64::Parse(controls[0]->Controls[1]->Text);
		double amount = Double::Parse(transferPanel->Controls[3]->Text);
		if (DBConnecter::exists(receiver)->Equals(true))
			if (DBConnecter::checkMoney(_sender, amount)->Equals(true))
			{
				DBConnecter::sendMoney(_sender, receiver, amount);
				controls[4]->Text = "Success";
				transferPanel->Controls[1]->Text = "";
				transferPanel->Controls[3]->Text = "";
				back(sender, e);
			}
			else
				controls[4]->Text = "You don\'t have\n   enough money";
		else
			controls[4]->Text = "Wrong receivers\'\n     number";
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK);
	}
}

void Atm::makeWithdraw(Object^ sender, EventArgs^ e)
{
	try {
		auto controls = atmPanel->Controls;
		double amount = Double::Parse(controls[3]->Controls[1]->Text);
		long long number = Int64::Parse(controls[0]->Controls[1]->Text);
		
		if (DBConnecter::checkMoney(number, amount)->Equals(true))
		{
			DBConnecter::updateMoney(number, amount);
			controls[4]->Text = "Success";
			controls[3]->Controls[1]->Text = "";
			back(sender, e);
		}
		else
			controls[4]->Text = "You don\'t have\n  enough money";
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK);
	}
}

void Atm::back(Object^ sender, EventArgs^ e)
{
	auto controls = atmPanel->Controls;
	if(controls[2]->Visible)
		controls[2]->Hide();
	if(controls[3]->Visible)
		controls[3]->Hide();
	controls[1]->Show();
}