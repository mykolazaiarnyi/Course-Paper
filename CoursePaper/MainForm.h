#pragma once
#include"DBConnecter.h"
#include"Atm.h"
#include"Gateway.h"

namespace CoursePaper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			atm1 = gcnew Atm(atmPanel1);
			validationButton1->Click += gcnew EventHandler(atm1, &Atm::checkValid);
			transferButton1->Click += gcnew EventHandler(atm1, &Atm::goToTransfer);
			withdrawButton1->Click += gcnew EventHandler(atm1, &Atm::goToWithdraw);
			exitMenuButton1->Click += gcnew EventHandler(atm1, &Atm::exit);
			makeTransferButton1->Click += gcnew EventHandler(atm1, &Atm::makeTransfer);
			makeWithdrawButton1->Click += gcnew EventHandler(atm1, &Atm::makeWithdraw);
			backTransferButton1->Click += gcnew EventHandler(atm1, &Atm::back);
			backWithdrawButton1->Click += gcnew EventHandler(atm1, &Atm::back);
			menuPanel1->Hide();
			transferPanel1->Hide();
			withdrawPanel1->Hide();

			atm2 = gcnew Atm(atmPanel2);
			validationButton2->Click += gcnew EventHandler(atm2, &Atm::checkValid);
			transferMenuButton2->Click += gcnew EventHandler(atm2, &Atm::goToTransfer);
			withdrawMenuButton2->Click += gcnew EventHandler(atm2, &Atm::goToWithdraw);
			exitMenuButton2->Click += gcnew EventHandler(atm2, &Atm::exit);
			transferTransferButton2->Click += gcnew EventHandler(atm2, &Atm::makeTransfer);
			withdrawWithdrawButton2->Click += gcnew EventHandler(atm2, &Atm::makeWithdraw);
			backTransferButton2->Click += gcnew EventHandler(atm2, &Atm::back);
			backWithdrawButton2->Click += gcnew EventHandler(atm2, &Atm::back);
			menuPanel2->Hide();
			transferPanel2->Hide();
			withdrawPanel2->Hide();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			Gateway::thread->Abort();
		}
	private: System::Windows::Forms::Panel^  validationPanel1;

	private: System::Windows::Forms::Button^  validationButton1;
	private: System::Windows::Forms::TextBox^  pinText1;
	private: System::Windows::Forms::TextBox^  cardNumberValidationText1;
	private: System::Windows::Forms::Label^  pinLabel1;
	private: System::Windows::Forms::Label^  cardNumberValidationLabel1;
	private: System::Windows::Forms::Label^  atmMessage1;
	private: System::Windows::Forms::Panel^  menuPanel1;
	private: System::Windows::Forms::Button^  withdrawButton1;
	private: System::Windows::Forms::Button^  transferButton1;
	private: System::Windows::Forms::Panel^  withdrawPanel1;
	private: System::Windows::Forms::Button^  exitMenuButton1;
	private: System::Windows::Forms::Button^  backWithdrawButton1;
	private: System::Windows::Forms::Button^  makeWithdrawButton1;
	private: System::Windows::Forms::TextBox^  amountWithdrawText1;
	private: System::Windows::Forms::Label^  amountWithdrawLabel1;
	private: System::Windows::Forms::Panel^  transferPanel1;
	private: System::Windows::Forms::Button^  makeTransferButton1;
	private: System::Windows::Forms::Label^  amountTransferLabel1;
	private: System::Windows::Forms::Label^  receiverTransferLabel1;
	private: System::Windows::Forms::TextBox^  amountTransferText1;
	private: System::Windows::Forms::TextBox^  receiverTransferText1;
	private: System::Windows::Forms::Panel^  atmPanel1;
	private: System::Windows::Forms::Button^  backTransferButton1;
	private: System::Windows::Forms::Panel^  atmPanel2;
	private: System::Windows::Forms::Panel^  validationPanel2;
	private: System::Windows::Forms::Label^  numberValidationLabel2;
	private: System::Windows::Forms::TextBox^  numberValidationText2;
	private: System::Windows::Forms::Label^  pinValidationLabel2;
	private: System::Windows::Forms::TextBox^  pinValidationText2;
	private: System::Windows::Forms::Button^  validationButton2;
	private: System::Windows::Forms::Panel^  menuPanel2;
	private: System::Windows::Forms::Button^  transferMenuButton2;
	private: System::Windows::Forms::Button^  withdrawMenuButton2;
	private: System::Windows::Forms::Button^  exitMenuButton2;
	private: System::Windows::Forms::Panel^  transferPanel2;
	private: System::Windows::Forms::Label^  receiverTransferLabel2;
	private: System::Windows::Forms::TextBox^  receiverTransferText2;
	private: System::Windows::Forms::Label^  amountTransferLabel2;
	private: System::Windows::Forms::TextBox^  amountTransferText2;
	private: System::Windows::Forms::Button^  transferTransferButton2;
	private: System::Windows::Forms::Button^  backTransferButton2;
	private: System::Windows::Forms::Panel^  withdrawPanel2;
	private: System::Windows::Forms::Label^  amountWithdrawLabel2;
	private: System::Windows::Forms::TextBox^  amountWithdrawText2;
	private: System::Windows::Forms::Button^  withdrawWithdrawButton2;
	private: System::Windows::Forms::Button^  backWithdrawButton2;
	private: System::Windows::Forms::Label^  atmMessage2;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->validationPanel1 = (gcnew System::Windows::Forms::Panel());
			this->cardNumberValidationLabel1 = (gcnew System::Windows::Forms::Label());
			this->cardNumberValidationText1 = (gcnew System::Windows::Forms::TextBox());
			this->pinLabel1 = (gcnew System::Windows::Forms::Label());
			this->pinText1 = (gcnew System::Windows::Forms::TextBox());
			this->validationButton1 = (gcnew System::Windows::Forms::Button());
			this->transferPanel1 = (gcnew System::Windows::Forms::Panel());
			this->receiverTransferLabel1 = (gcnew System::Windows::Forms::Label());
			this->receiverTransferText1 = (gcnew System::Windows::Forms::TextBox());
			this->amountTransferLabel1 = (gcnew System::Windows::Forms::Label());
			this->amountTransferText1 = (gcnew System::Windows::Forms::TextBox());
			this->makeTransferButton1 = (gcnew System::Windows::Forms::Button());
			this->backTransferButton1 = (gcnew System::Windows::Forms::Button());
			this->withdrawPanel1 = (gcnew System::Windows::Forms::Panel());
			this->amountWithdrawLabel1 = (gcnew System::Windows::Forms::Label());
			this->amountWithdrawText1 = (gcnew System::Windows::Forms::TextBox());
			this->makeWithdrawButton1 = (gcnew System::Windows::Forms::Button());
			this->backWithdrawButton1 = (gcnew System::Windows::Forms::Button());
			this->menuPanel1 = (gcnew System::Windows::Forms::Panel());
			this->transferButton1 = (gcnew System::Windows::Forms::Button());
			this->withdrawButton1 = (gcnew System::Windows::Forms::Button());
			this->exitMenuButton1 = (gcnew System::Windows::Forms::Button());
			this->atmMessage1 = (gcnew System::Windows::Forms::Label());
			this->atmPanel1 = (gcnew System::Windows::Forms::Panel());
			this->atmPanel2 = (gcnew System::Windows::Forms::Panel());
			this->validationPanel2 = (gcnew System::Windows::Forms::Panel());
			this->numberValidationLabel2 = (gcnew System::Windows::Forms::Label());
			this->numberValidationText2 = (gcnew System::Windows::Forms::TextBox());
			this->pinValidationLabel2 = (gcnew System::Windows::Forms::Label());
			this->pinValidationText2 = (gcnew System::Windows::Forms::TextBox());
			this->validationButton2 = (gcnew System::Windows::Forms::Button());
			this->menuPanel2 = (gcnew System::Windows::Forms::Panel());
			this->transferMenuButton2 = (gcnew System::Windows::Forms::Button());
			this->withdrawMenuButton2 = (gcnew System::Windows::Forms::Button());
			this->exitMenuButton2 = (gcnew System::Windows::Forms::Button());
			this->transferPanel2 = (gcnew System::Windows::Forms::Panel());
			this->receiverTransferLabel2 = (gcnew System::Windows::Forms::Label());
			this->receiverTransferText2 = (gcnew System::Windows::Forms::TextBox());
			this->amountTransferLabel2 = (gcnew System::Windows::Forms::Label());
			this->amountTransferText2 = (gcnew System::Windows::Forms::TextBox());
			this->transferTransferButton2 = (gcnew System::Windows::Forms::Button());
			this->backTransferButton2 = (gcnew System::Windows::Forms::Button());
			this->withdrawPanel2 = (gcnew System::Windows::Forms::Panel());
			this->amountWithdrawLabel2 = (gcnew System::Windows::Forms::Label());
			this->amountWithdrawText2 = (gcnew System::Windows::Forms::TextBox());
			this->withdrawWithdrawButton2 = (gcnew System::Windows::Forms::Button());
			this->backWithdrawButton2 = (gcnew System::Windows::Forms::Button());
			this->atmMessage2 = (gcnew System::Windows::Forms::Label());
			this->validationPanel1->SuspendLayout();
			this->transferPanel1->SuspendLayout();
			this->withdrawPanel1->SuspendLayout();
			this->menuPanel1->SuspendLayout();
			this->atmPanel1->SuspendLayout();
			this->atmPanel2->SuspendLayout();
			this->validationPanel2->SuspendLayout();
			this->menuPanel2->SuspendLayout();
			this->transferPanel2->SuspendLayout();
			this->withdrawPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// validationPanel1
			// 
			this->validationPanel1->Controls->Add(this->cardNumberValidationLabel1);
			this->validationPanel1->Controls->Add(this->cardNumberValidationText1);
			this->validationPanel1->Controls->Add(this->pinLabel1);
			this->validationPanel1->Controls->Add(this->pinText1);
			this->validationPanel1->Controls->Add(this->validationButton1);
			this->validationPanel1->Location = System::Drawing::Point(3, 45);
			this->validationPanel1->Name = L"validationPanel1";
			this->validationPanel1->Size = System::Drawing::Size(151, 130);
			this->validationPanel1->TabIndex = 0;
			// 
			// cardNumberValidationLabel1
			// 
			this->cardNumberValidationLabel1->AutoSize = true;
			this->cardNumberValidationLabel1->Location = System::Drawing::Point(33, 5);
			this->cardNumberValidationLabel1->Name = L"cardNumberValidationLabel1";
			this->cardNumberValidationLabel1->Size = System::Drawing::Size(90, 17);
			this->cardNumberValidationLabel1->TabIndex = 0;
			this->cardNumberValidationLabel1->Text = L"Card number";
			// 
			// cardNumberValidationText1
			// 
			this->cardNumberValidationText1->Location = System::Drawing::Point(8, 25);
			this->cardNumberValidationText1->Name = L"cardNumberValidationText1";
			this->cardNumberValidationText1->Size = System::Drawing::Size(135, 22);
			this->cardNumberValidationText1->TabIndex = 2;
			// 
			// pinLabel1
			// 
			this->pinLabel1->AutoSize = true;
			this->pinLabel1->Location = System::Drawing::Point(60, 50);
			this->pinLabel1->Name = L"pinLabel1";
			this->pinLabel1->Size = System::Drawing::Size(30, 17);
			this->pinLabel1->TabIndex = 1;
			this->pinLabel1->Text = L"PIN";
			// 
			// pinText1
			// 
			this->pinText1->Location = System::Drawing::Point(54, 70);
			this->pinText1->Name = L"pinText1";
			this->pinText1->Size = System::Drawing::Size(42, 22);
			this->pinText1->TabIndex = 3;
			// 
			// validationButton1
			// 
			this->validationButton1->Location = System::Drawing::Point(34, 98);
			this->validationButton1->Name = L"validationButton1";
			this->validationButton1->Size = System::Drawing::Size(75, 23);
			this->validationButton1->TabIndex = 4;
			this->validationButton1->Text = L"Next";
			this->validationButton1->UseVisualStyleBackColor = true;
			// 
			// transferPanel1
			// 
			this->transferPanel1->Controls->Add(this->receiverTransferLabel1);
			this->transferPanel1->Controls->Add(this->receiverTransferText1);
			this->transferPanel1->Controls->Add(this->amountTransferLabel1);
			this->transferPanel1->Controls->Add(this->amountTransferText1);
			this->transferPanel1->Controls->Add(this->makeTransferButton1);
			this->transferPanel1->Controls->Add(this->backTransferButton1);
			this->transferPanel1->Location = System::Drawing::Point(8, 45);
			this->transferPanel1->Name = L"transferPanel1";
			this->transferPanel1->Size = System::Drawing::Size(142, 156);
			this->transferPanel1->TabIndex = 4;
			// 
			// receiverTransferLabel1
			// 
			this->receiverTransferLabel1->AutoSize = true;
			this->receiverTransferLabel1->Location = System::Drawing::Point(38, 5);
			this->receiverTransferLabel1->Name = L"receiverTransferLabel1";
			this->receiverTransferLabel1->Size = System::Drawing::Size(64, 17);
			this->receiverTransferLabel1->TabIndex = 2;
			this->receiverTransferLabel1->Text = L"Receiver";
			// 
			// receiverTransferText1
			// 
			this->receiverTransferText1->Location = System::Drawing::Point(4, 25);
			this->receiverTransferText1->Name = L"receiverTransferText1";
			this->receiverTransferText1->Size = System::Drawing::Size(135, 22);
			this->receiverTransferText1->TabIndex = 0;
			// 
			// amountTransferLabel1
			// 
			this->amountTransferLabel1->AutoSize = true;
			this->amountTransferLabel1->Location = System::Drawing::Point(39, 50);
			this->amountTransferLabel1->Name = L"amountTransferLabel1";
			this->amountTransferLabel1->Size = System::Drawing::Size(56, 17);
			this->amountTransferLabel1->TabIndex = 3;
			this->amountTransferLabel1->Text = L"Amount";
			// 
			// amountTransferText1
			// 
			this->amountTransferText1->Location = System::Drawing::Point(18, 70);
			this->amountTransferText1->Name = L"amountTransferText1";
			this->amountTransferText1->Size = System::Drawing::Size(100, 22);
			this->amountTransferText1->TabIndex = 1;
			// 
			// makeTransferButton1
			// 
			this->makeTransferButton1->Location = System::Drawing::Point(30, 98);
			this->makeTransferButton1->Name = L"makeTransferButton1";
			this->makeTransferButton1->Size = System::Drawing::Size(75, 23);
			this->makeTransferButton1->TabIndex = 5;
			this->makeTransferButton1->Text = L"Transfer";
			this->makeTransferButton1->UseVisualStyleBackColor = true;
			// 
			// backTransferButton1
			// 
			this->backTransferButton1->Location = System::Drawing::Point(40, 127);
			this->backTransferButton1->Name = L"backTransferButton1";
			this->backTransferButton1->Size = System::Drawing::Size(55, 23);
			this->backTransferButton1->TabIndex = 4;
			this->backTransferButton1->Text = L"Back";
			this->backTransferButton1->UseVisualStyleBackColor = true;
			// 
			// withdrawPanel1
			// 
			this->withdrawPanel1->Controls->Add(this->amountWithdrawLabel1);
			this->withdrawPanel1->Controls->Add(this->amountWithdrawText1);
			this->withdrawPanel1->Controls->Add(this->makeWithdrawButton1);
			this->withdrawPanel1->Controls->Add(this->backWithdrawButton1);
			this->withdrawPanel1->Location = System::Drawing::Point(21, 44);
			this->withdrawPanel1->Name = L"withdrawPanel1";
			this->withdrawPanel1->Size = System::Drawing::Size(106, 153);
			this->withdrawPanel1->TabIndex = 3;
			// 
			// amountWithdrawLabel1
			// 
			this->amountWithdrawLabel1->AutoSize = true;
			this->amountWithdrawLabel1->Location = System::Drawing::Point(26, 9);
			this->amountWithdrawLabel1->Name = L"amountWithdrawLabel1";
			this->amountWithdrawLabel1->Size = System::Drawing::Size(56, 17);
			this->amountWithdrawLabel1->TabIndex = 0;
			this->amountWithdrawLabel1->Text = L"Amount";
			// 
			// amountWithdrawText1
			// 
			this->amountWithdrawText1->Location = System::Drawing::Point(3, 30);
			this->amountWithdrawText1->Name = L"amountWithdrawText1";
			this->amountWithdrawText1->Size = System::Drawing::Size(100, 22);
			this->amountWithdrawText1->TabIndex = 2;
			// 
			// makeWithdrawButton1
			// 
			this->makeWithdrawButton1->Location = System::Drawing::Point(10, 57);
			this->makeWithdrawButton1->Name = L"makeWithdrawButton1";
			this->makeWithdrawButton1->Size = System::Drawing::Size(88, 23);
			this->makeWithdrawButton1->TabIndex = 3;
			this->makeWithdrawButton1->Text = L"Withdraw";
			this->makeWithdrawButton1->UseVisualStyleBackColor = true;
			// 
			// backWithdrawButton1
			// 
			this->backWithdrawButton1->Location = System::Drawing::Point(24, 86);
			this->backWithdrawButton1->Name = L"backWithdrawButton1";
			this->backWithdrawButton1->Size = System::Drawing::Size(55, 23);
			this->backWithdrawButton1->TabIndex = 4;
			this->backWithdrawButton1->Text = L"Back";
			this->backWithdrawButton1->UseVisualStyleBackColor = true;
			// 
			// menuPanel1
			// 
			this->menuPanel1->Controls->Add(this->transferButton1);
			this->menuPanel1->Controls->Add(this->withdrawButton1);
			this->menuPanel1->Controls->Add(this->exitMenuButton1);
			this->menuPanel1->Location = System::Drawing::Point(12, 45);
			this->menuPanel1->Name = L"menuPanel1";
			this->menuPanel1->Size = System::Drawing::Size(129, 115);
			this->menuPanel1->TabIndex = 2;
			// 
			// transferButton1
			// 
			this->transferButton1->Location = System::Drawing::Point(3, 5);
			this->transferButton1->Name = L"transferButton1";
			this->transferButton1->Size = System::Drawing::Size(109, 23);
			this->transferButton1->TabIndex = 0;
			this->transferButton1->Text = L"Transfer";
			this->transferButton1->UseVisualStyleBackColor = true;
			// 
			// withdrawButton1
			// 
			this->withdrawButton1->Location = System::Drawing::Point(16, 34);
			this->withdrawButton1->Name = L"withdrawButton1";
			this->withdrawButton1->Size = System::Drawing::Size(82, 23);
			this->withdrawButton1->TabIndex = 1;
			this->withdrawButton1->Text = L"Withdraw";
			this->withdrawButton1->UseVisualStyleBackColor = true;
			// 
			// exitMenuButton1
			// 
			this->exitMenuButton1->Location = System::Drawing::Point(19, 62);
			this->exitMenuButton1->Name = L"exitMenuButton1";
			this->exitMenuButton1->Size = System::Drawing::Size(75, 23);
			this->exitMenuButton1->TabIndex = 2;
			this->exitMenuButton1->Text = L"Exit";
			this->exitMenuButton1->UseVisualStyleBackColor = true;
			// 
			// atmMessage1
			// 
			this->atmMessage1->AutoSize = true;
			this->atmMessage1->Location = System::Drawing::Point(16, 6);
			this->atmMessage1->Name = L"atmMessage1";
			this->atmMessage1->Size = System::Drawing::Size(131, 34);
			this->atmMessage1->TabIndex = 1;
			this->atmMessage1->Text = L"Insert card number \r\n        and PIN";
			// 
			// atmPanel1
			// 
			this->atmPanel1->Controls->Add(this->withdrawPanel1);
			this->atmPanel1->Controls->Add(this->atmMessage1);
			this->atmPanel1->Controls->Add(this->validationPanel1);
			this->atmPanel1->Controls->Add(this->menuPanel1);
			this->atmPanel1->Controls->Add(this->transferPanel1);
			this->atmPanel1->Location = System::Drawing::Point(12, 12);
			this->atmPanel1->Name = L"atmPanel1";
			this->atmPanel1->Size = System::Drawing::Size(162, 221);
			this->atmPanel1->TabIndex = 5;
			// 
			// atmPanel2
			// 
			this->atmPanel2->Controls->Add(this->withdrawPanel2);
			this->atmPanel2->Controls->Add(this->atmMessage2);
			this->atmPanel2->Controls->Add(this->validationPanel2);
			this->atmPanel2->Controls->Add(this->menuPanel2);
			this->atmPanel2->Controls->Add(this->transferPanel2);
			this->atmPanel2->Location = System::Drawing::Point(180, 12);
			this->atmPanel2->Name = L"atmPanel2";
			this->atmPanel2->Size = System::Drawing::Size(162, 221);
			this->atmPanel2->TabIndex = 5;
			// 
			// validationPanel2
			// 
			this->validationPanel2->Controls->Add(this->numberValidationLabel2);
			this->validationPanel2->Controls->Add(this->numberValidationText2);
			this->validationPanel2->Controls->Add(this->pinValidationLabel2);
			this->validationPanel2->Controls->Add(this->pinValidationText2);
			this->validationPanel2->Controls->Add(this->validationButton2);
			this->validationPanel2->Location = System::Drawing::Point(3, 45);
			this->validationPanel2->Name = L"validationPanel2";
			this->validationPanel2->Size = System::Drawing::Size(151, 130);
			this->validationPanel2->TabIndex = 0;
			// 
			// numberValidationLabel2
			// 
			this->numberValidationLabel2->AutoSize = true;
			this->numberValidationLabel2->Location = System::Drawing::Point(33, 5);
			this->numberValidationLabel2->Name = L"numberValidationLabel2";
			this->numberValidationLabel2->Size = System::Drawing::Size(90, 17);
			this->numberValidationLabel2->TabIndex = 0;
			this->numberValidationLabel2->Text = L"Card number";
			// 
			// numberValidationText2
			// 
			this->numberValidationText2->Location = System::Drawing::Point(8, 25);
			this->numberValidationText2->Name = L"numberValidationText2";
			this->numberValidationText2->Size = System::Drawing::Size(135, 22);
			this->numberValidationText2->TabIndex = 2;
			// 
			// pinValidationLabel2
			// 
			this->pinValidationLabel2->AutoSize = true;
			this->pinValidationLabel2->Location = System::Drawing::Point(60, 50);
			this->pinValidationLabel2->Name = L"pinValidationLabel2";
			this->pinValidationLabel2->Size = System::Drawing::Size(30, 17);
			this->pinValidationLabel2->TabIndex = 1;
			this->pinValidationLabel2->Text = L"PIN";
			// 
			// pinValidationText2
			// 
			this->pinValidationText2->Location = System::Drawing::Point(54, 70);
			this->pinValidationText2->Name = L"pinValidationText2";
			this->pinValidationText2->Size = System::Drawing::Size(42, 22);
			this->pinValidationText2->TabIndex = 3;
			// 
			// validationButton2
			// 
			this->validationButton2->Location = System::Drawing::Point(34, 98);
			this->validationButton2->Name = L"validationButton2";
			this->validationButton2->Size = System::Drawing::Size(75, 23);
			this->validationButton2->TabIndex = 4;
			this->validationButton2->Text = L"Next";
			this->validationButton2->UseVisualStyleBackColor = true;
			// 
			// menuPanel2
			// 
			this->menuPanel2->Controls->Add(this->transferMenuButton2);
			this->menuPanel2->Controls->Add(this->withdrawMenuButton2);
			this->menuPanel2->Controls->Add(this->exitMenuButton2);
			this->menuPanel2->Location = System::Drawing::Point(12, 45);
			this->menuPanel2->Name = L"menuPanel2";
			this->menuPanel2->Size = System::Drawing::Size(129, 115);
			this->menuPanel2->TabIndex = 2;
			// 
			// transferMenuButton2
			// 
			this->transferMenuButton2->Location = System::Drawing::Point(10, 5);
			this->transferMenuButton2->Name = L"transferMenuButton2";
			this->transferMenuButton2->Size = System::Drawing::Size(109, 23);
			this->transferMenuButton2->TabIndex = 0;
			this->transferMenuButton2->Text = L"Transfer";
			this->transferMenuButton2->UseVisualStyleBackColor = true;
			// 
			// withdrawMenuButton2
			// 
			this->withdrawMenuButton2->Location = System::Drawing::Point(22, 34);
			this->withdrawMenuButton2->Name = L"withdrawMenuButton2";
			this->withdrawMenuButton2->Size = System::Drawing::Size(82, 23);
			this->withdrawMenuButton2->TabIndex = 1;
			this->withdrawMenuButton2->Text = L"Withdraw";
			this->withdrawMenuButton2->UseVisualStyleBackColor = true;
			// 
			// exitMenuButton2
			// 
			this->exitMenuButton2->Location = System::Drawing::Point(26, 62);
			this->exitMenuButton2->Name = L"exitMenuButton2";
			this->exitMenuButton2->Size = System::Drawing::Size(75, 23);
			this->exitMenuButton2->TabIndex = 2;
			this->exitMenuButton2->Text = L"Exit";
			this->exitMenuButton2->UseVisualStyleBackColor = true;
			// 
			// transferPanel2
			// 
			this->transferPanel2->Controls->Add(this->receiverTransferLabel2);
			this->transferPanel2->Controls->Add(this->receiverTransferText2);
			this->transferPanel2->Controls->Add(this->amountTransferLabel2);
			this->transferPanel2->Controls->Add(this->amountTransferText2);
			this->transferPanel2->Controls->Add(this->transferTransferButton2);
			this->transferPanel2->Controls->Add(this->backTransferButton2);
			this->transferPanel2->Location = System::Drawing::Point(8, 45);
			this->transferPanel2->Name = L"transferPanel2";
			this->transferPanel2->Size = System::Drawing::Size(142, 156);
			this->transferPanel2->TabIndex = 4;
			// 
			// receiverTransferLabel2
			// 
			this->receiverTransferLabel2->AutoSize = true;
			this->receiverTransferLabel2->Location = System::Drawing::Point(38, 5);
			this->receiverTransferLabel2->Name = L"receiverTransferLabel2";
			this->receiverTransferLabel2->Size = System::Drawing::Size(64, 17);
			this->receiverTransferLabel2->TabIndex = 2;
			this->receiverTransferLabel2->Text = L"Receiver";
			// 
			// receiverTransferText2
			// 
			this->receiverTransferText2->Location = System::Drawing::Point(4, 25);
			this->receiverTransferText2->Name = L"receiverTransferText2";
			this->receiverTransferText2->Size = System::Drawing::Size(135, 22);
			this->receiverTransferText2->TabIndex = 0;
			// 
			// amountTransferLabel2
			// 
			this->amountTransferLabel2->AutoSize = true;
			this->amountTransferLabel2->Location = System::Drawing::Point(39, 50);
			this->amountTransferLabel2->Name = L"amountTransferLabel2";
			this->amountTransferLabel2->Size = System::Drawing::Size(56, 17);
			this->amountTransferLabel2->TabIndex = 3;
			this->amountTransferLabel2->Text = L"Amount";
			// 
			// amountTransferText2
			// 
			this->amountTransferText2->Location = System::Drawing::Point(18, 70);
			this->amountTransferText2->Name = L"amountTransferText2";
			this->amountTransferText2->Size = System::Drawing::Size(100, 22);
			this->amountTransferText2->TabIndex = 1;
			// 
			// transferTransferButton2
			// 
			this->transferTransferButton2->Location = System::Drawing::Point(30, 98);
			this->transferTransferButton2->Name = L"transferTransferButton2";
			this->transferTransferButton2->Size = System::Drawing::Size(75, 23);
			this->transferTransferButton2->TabIndex = 5;
			this->transferTransferButton2->Text = L"Transfer";
			this->transferTransferButton2->UseVisualStyleBackColor = true;
			// 
			// backTransferButton2
			// 
			this->backTransferButton2->Location = System::Drawing::Point(40, 127);
			this->backTransferButton2->Name = L"backTransferButton2";
			this->backTransferButton2->Size = System::Drawing::Size(55, 23);
			this->backTransferButton2->TabIndex = 4;
			this->backTransferButton2->Text = L"Back";
			this->backTransferButton2->UseVisualStyleBackColor = true;
			// 
			// withdrawPanel2
			// 
			this->withdrawPanel2->Controls->Add(this->amountWithdrawLabel2);
			this->withdrawPanel2->Controls->Add(this->amountWithdrawText2);
			this->withdrawPanel2->Controls->Add(this->withdrawWithdrawButton2);
			this->withdrawPanel2->Controls->Add(this->backWithdrawButton2);
			this->withdrawPanel2->Location = System::Drawing::Point(21, 44);
			this->withdrawPanel2->Name = L"withdrawPanel2";
			this->withdrawPanel2->Size = System::Drawing::Size(106, 153);
			this->withdrawPanel2->TabIndex = 3;
			// 
			// amountWithdrawLabel2
			// 
			this->amountWithdrawLabel2->AutoSize = true;
			this->amountWithdrawLabel2->Location = System::Drawing::Point(26, 9);
			this->amountWithdrawLabel2->Name = L"amountWithdrawLabel2";
			this->amountWithdrawLabel2->Size = System::Drawing::Size(56, 17);
			this->amountWithdrawLabel2->TabIndex = 0;
			this->amountWithdrawLabel2->Text = L"Amount";
			// 
			// amountWithdrawText2
			// 
			this->amountWithdrawText2->Location = System::Drawing::Point(3, 30);
			this->amountWithdrawText2->Name = L"amountWithdrawText2";
			this->amountWithdrawText2->Size = System::Drawing::Size(100, 22);
			this->amountWithdrawText2->TabIndex = 2;
			// 
			// withdrawWithdrawButton2
			// 
			this->withdrawWithdrawButton2->Location = System::Drawing::Point(10, 57);
			this->withdrawWithdrawButton2->Name = L"withdrawWithdrawButton2";
			this->withdrawWithdrawButton2->Size = System::Drawing::Size(88, 23);
			this->withdrawWithdrawButton2->TabIndex = 3;
			this->withdrawWithdrawButton2->Text = L"Withdraw";
			this->withdrawWithdrawButton2->UseVisualStyleBackColor = true;
			// 
			// backWithdrawButton2
			// 
			this->backWithdrawButton2->Location = System::Drawing::Point(24, 86);
			this->backWithdrawButton2->Name = L"backWithdrawButton2";
			this->backWithdrawButton2->Size = System::Drawing::Size(55, 23);
			this->backWithdrawButton2->TabIndex = 4;
			this->backWithdrawButton2->Text = L"Back";
			this->backWithdrawButton2->UseVisualStyleBackColor = true;
			// 
			// atmMessage2
			// 
			this->atmMessage2->AutoSize = true;
			this->atmMessage2->Location = System::Drawing::Point(16, 6);
			this->atmMessage2->Name = L"atmMessage2";
			this->atmMessage2->Size = System::Drawing::Size(131, 34);
			this->atmMessage2->TabIndex = 1;
			this->atmMessage2->Text = L"Insert card number \r\n        and PIN";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(828, 385);
			this->Controls->Add(this->atmPanel2);
			this->Controls->Add(this->atmPanel1);
			this->Name = L"MainForm";
			this->Text = L"Modeling of connection between ATMs and bank";
			this->validationPanel1->ResumeLayout(false);
			this->validationPanel1->PerformLayout();
			this->transferPanel1->ResumeLayout(false);
			this->transferPanel1->PerformLayout();
			this->withdrawPanel1->ResumeLayout(false);
			this->withdrawPanel1->PerformLayout();
			this->menuPanel1->ResumeLayout(false);
			this->atmPanel1->ResumeLayout(false);
			this->atmPanel1->PerformLayout();
			this->atmPanel2->ResumeLayout(false);
			this->atmPanel2->PerformLayout();
			this->validationPanel2->ResumeLayout(false);
			this->validationPanel2->PerformLayout();
			this->menuPanel2->ResumeLayout(false);
			this->transferPanel2->ResumeLayout(false);
			this->transferPanel2->PerformLayout();
			this->withdrawPanel2->ResumeLayout(false);
			this->withdrawPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		Atm^ atm1;
		Atm^ atm2;
};
}
