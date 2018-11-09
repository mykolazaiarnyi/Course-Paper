#include "Atm.h"
#include "DBConnecter.h"
#include "Gateway.h"
#include "TransferCommand.h"
#include "WithdrawCommand.h"

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
		{
			Gateway::queue->Enqueue(gcnew TransferCommand(_sender, receiver, amount, this));
			transferPanel->Enabled = false;
		}
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
		Gateway::queue->Enqueue(gcnew WithdrawCommand(number, amount, this));
		withdrawPanel->Enabled = false;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK);
	}
}

void Atm::back(Object^ sender, EventArgs^ e)
{
	if (transferPanel->Visible)
	{
		transferPanel->Hide();
		transferPanel->Controls[1]->Text = "";
		transferPanel->Controls[3]->Text = "";
	}
	if (withdrawPanel->Visible)
	{
		withdrawPanel->Hide();
		withdrawPanel->Controls[1]->Text = "";
	}
	menuPanel->Show();
	atmMessage->Text = "Choose an option";
}