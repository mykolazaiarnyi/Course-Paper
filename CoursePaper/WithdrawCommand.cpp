#include "WithdrawCommand.h"
#include "DBConnecter.h"


WithdrawCommand::WithdrawCommand(long long number, double amount, Atm^ atm)
{
	_number = number;
	_amount = amount;
	_atm = atm;
}

void WithdrawCommand::execute()
{
	try
	{
		if (DBConnecter::checkMoney(_number, _amount)->Equals(true))
		{
			DBConnecter::updateMoney(_number, _amount);
			_atm->withdrawPanel->Controls[1]->Text = "";
			_atm->withdrawPanel->Hide();
			_atm->menuPanel->Show();
			_atm->atmMessage->Text = "Choose an option";
		}
		else
			_atm->atmMessage->Text = "You don\'t have\n  enough money";
		_atm->withdrawPanel->Enabled = true;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK);
		_atm->withdrawPanel->Enabled = true;
	}
}
