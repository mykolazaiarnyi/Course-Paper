#include "DBConnecter.h"
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;


static DBConnecter::DBConnecter()
{
#ifdef MY_COMP
	connection->Open();
	SqlDataReader^ rdr = checkValidCommand->ExecuteReader();
	while (rdr->Read())
		accounts->Add(Convert::ToInt64(rdr[0]), Convert::ToInt32(rdr[1]));
	connection->Close();

	checkMoneyCommand->CommandType = CommandType::StoredProcedure;
	checkMoneyCommand->Parameters->Add(gcnew SqlParameter("@Number", nullptr));
	checkMoneyCommand->Parameters->Add(gcnew SqlParameter("@Amount", nullptr));

	updateMoneyCommand->CommandType = CommandType::StoredProcedure;
	updateMoneyCommand->Parameters->Add(gcnew SqlParameter("@Number", nullptr));
	updateMoneyCommand->Parameters->Add(gcnew SqlParameter("@Amount", nullptr));

	sendMoneyCommand->CommandType = CommandType::StoredProcedure;
	sendMoneyCommand->Parameters->Add(gcnew SqlParameter("@Sender", nullptr));
	sendMoneyCommand->Parameters->Add(gcnew SqlParameter("@Receiver", nullptr));
	sendMoneyCommand->Parameters->Add(gcnew SqlParameter("@Amount", nullptr));
#else // MY_COMP
	accounts->Add(1111111111111110, 1111);
	accountsMoney->Add(1111111111111110, 500);

	accounts->Add(1111111111111111, 1111);
	accountsMoney->Add(1111111111111111, 400);

	accounts->Add(1111111111111112, 1111);
	accountsMoney->Add(1111111111111112, 450);

	accounts->Add(1111111111111113, 1111);
	accountsMoney->Add(1111111111111113, 300);

	accounts->Add(1111111111111114, 1111);
	accountsMoney->Add(1111111111111114, 500);
#endif
}

bool^ DBConnecter::checkValid(long long number, int pin, System::Windows::Forms::Control^ messageTarget)
{
	if (accounts->ContainsKey(number))
		if (accounts[number] == pin)
			return true;
		else
		{
			messageTarget->Text = "Wrong PIN";
			return false;
		}
	else
	{
		messageTarget->Text = "Wrong card number";
		return false;
	}
}

bool^ DBConnecter::checkMoney(long long number, double amount)
{
#ifdef MY_COMP
	try {
		connection->Open();
		checkMoneyCommand->Parameters["@Number"]->Value = number;
		checkMoneyCommand->Parameters["@Amount"]->Value = amount;
		SqlDataReader^ rdr = checkMoneyCommand->ExecuteReader();
		rdr->Read();
		int rtrn = Convert::ToInt32(rdr[0]);
		connection->Close();
		return (rtrn == 1) ? true : false;
	}
	catch (Exception^ e)
	{
		connection->Close();
		throw e;
	}
#else
	return accountsMoney[number] >= amount;
#endif
}

void DBConnecter::updateMoney(long long number, double amount)
{
#ifdef MY_COMP
	connection->Open();
	updateMoneyCommand->Parameters["@Number"]->Value = number;
	updateMoneyCommand->Parameters["@Amount"]->Value = amount;
	updateMoneyCommand->ExecuteNonQuery();
	connection->Close();
#endif // MY_COMP
}

void DBConnecter::sendMoney(long long sender, long long receiver, double amount)
{
#ifdef MY_COMP
	connection->Open();
	sendMoneyCommand->Parameters["@Sender"]->Value = sender;
	sendMoneyCommand->Parameters["@Receiver"]->Value = receiver;
	sendMoneyCommand->Parameters["@Amount"]->Value = amount;
	sendMoneyCommand->ExecuteNonQuery();
	connection->Close();
#endif // MY_COMP
}

bool^ DBConnecter::exists(long long number)
{
	return accounts->ContainsKey(number);
}