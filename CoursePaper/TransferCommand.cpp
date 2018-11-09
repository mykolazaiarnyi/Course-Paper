#include "TransferCommand.h"
#include "DBConnecter.h"


TransferCommand::TransferCommand(long long sender, long long receiver, double amount, Atm^ atm)
{
	_sender = sender;
	_receiver = receiver;
	_amount = amount;
	_atm = atm;
}

void TransferCommand::execute()
{
	try
	{
		if (DBConnecter::checkMoney(_sender, _amount)->Equals(true))
		{
			DBConnecter::sendMoney(_sender, _receiver, _amount);
			_atm->transferPanel->Controls[1]->Text = "";
			_atm->transferPanel->Controls[3]->Text = "";
			_atm->transferPanel->Hide();
			_atm->menuPanel->Show();
			_atm->atmMessage->Text = "Choose an option";
		}
		else
			_atm->atmMessage->Text = "You don\'t have\n   enough money";
		_atm->transferPanel->Enabled = true;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK);
		_atm->transferPanel->Enabled = true;
	}
}