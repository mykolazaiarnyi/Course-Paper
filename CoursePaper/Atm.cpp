#include "Atm.h"
#include "DBConnecter.h"

using namespace System;
using namespace System::Windows::Forms;

Atm::Atm(Panel^ atmPanel)
{
	this->atmPanel = atmPanel;
	String^ id = atmPanel->Name->Substring(atmPanel->Name->Length - 1);
	transferPanel = atmPanel->Controls["transferPanel" + id];
	withdrawPanel = atmPanel->Controls["withdrawPanel" + id];
	validationPanel = atmPanel->Controls["validationPanel" + id];
	menuPanel = atmPanel->Controls["menuPanel" + id];
	atmMessage = atmPanel->Controls["atmMessage" + id];
}

void Atm::checkValid(Object^ sender, EventArgs^ e)
{
	try {
		long long number = Int64::Parse(validationPanel->Controls[1]->Text);
		int pin = Int32::Parse(validationPanel->Controls[3]->Text);
		if (DBConnecter::checkValid(number, pin, atmMessage)->Equals(true))
		{
			atmMessage->Text = "Choose an option";
			validationPanel->Hide();
			menuPanel->Show();
		}
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK);
	}
}

void Atm::goToTransfer(Object^ sender, EventArgs^ e)
{
	transferPanel->Show();
	menuPanel->Hide();
	atmMessage->Text = "Insert number\n and amount";
}

void Atm::goToWithdraw(Object^ sender, EventArgs^ e)
{
	withdrawPanel->Show();
	menuPanel->Hide();
	atmMessage->Text = "Insert amount";
}

void Atm::exit(Object^ sender, EventArgs^ e)
{
	validationPanel->Show();
	menuPanel->Hide();
	atmMessage->Text = L"Insert card number \r\n        and PIN";
	validationPanel->Controls[1]->Text = "";
	validationPanel->Controls[3]->Text = "";
}

void Atm::makeTransfer(Object^ sender, EventArgs^ e)
{
	try {
		long long receiver = Int64::Parse(transferPanel->Controls[1]->Text);
		long long _sender = Int64::Parse(validationPanel->Controls[1]->Text);
		double amount = Double::Parse(transferPanel->Controls[3]->Text);
		if (DBConnecter::exists(receiver)->Equals(true))
			if (DBConnecter::checkMoney(_sender, amount)->Equals(true))
			{
				DBConnecter::sendMoney(_sender, receiver, amount);
				atmMessage->Text = "Success";
				transferPanel->Controls[1]->Text = "";
				transferPanel->Controls[3]->Text = "";
				back(sender, e);
			}
			else
				atmMessage->Text = "You don\'t have\n   enough money";
		else
			atmMessage->Text = "Wrong receivers\'\n     number";
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK);
	}
}

void Atm::makeWithdraw(Object^ sender, EventArgs^ e)
{
	try {
		double amount = Double::Parse(withdrawPanel->Controls[1]->Text);
		long long number = Int64::Parse(validationPanel->Controls[1]->Text);
		if (DBConnecter::checkMoney(number, amount)->Equals(true))
		{
			DBConnecter::updateMoney(number, amount);
			atmMessage->Text = "Success";
			withdrawPanel->Controls[1]->Text = "";
			back(sender, e);
		}
		else
			atmMessage->Text = "You don\'t have\n  enough money";
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK);
	}
}

void Atm::back(Object^ sender, EventArgs^ e)
{
	if(transferPanel->Visible)
		transferPanel->Hide();
	if(withdrawPanel->Visible)
		withdrawPanel->Hide();
	menuPanel->Show();
	atmMessage->Text = "Choose an option";
}