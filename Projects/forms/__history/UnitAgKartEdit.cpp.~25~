//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitAgKartEdit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBLookupComboBoxCentre"
#pragma link "my_DBCtrls"
#pragma resource "*.dfm"
TFormAgKartEdit *FormAgKartEdit;
TIBDatabase * MainConn = NULL;
extern TIBDatabase * MainConn;
TIBTransaction * TransactionAgent = NULL;
extern TIBTransaction * TransactionAgent;
// Таблица со списком ролей пользователей (статусов)
TIBTable * Table_Agent_Status = NULL;
extern TIBTable * Table_Agent_Status;
TDataSource * Agent_datasource = NULL;
extern TDataSource * Agent_datasource;
TDataSource * Agent_Status_datasource = NULL;
extern TDataSource * Agent_Status_datasource;
//---------------------------------------------------------------------------
__fastcall TFormAgKartEdit::TFormAgKartEdit(TComponent* Owner, TDataSource * Agent_datasource_local,
	TIBDatabase * MainConn_local, TIBTransaction * TransactionAgent_loc)
	: TForm(Owner)
{
	MainConn = MainConn_local;
	TransactionAgent = TransactionAgent_loc;
	TransactionAgent->DefaultDatabase = MainConn;

	//Agent_datasource = new TDataSource(NULL);
	Agent_datasource = Agent_datasource_local;

	//Таблица со списком ролей пользователей (статусов)
	Table_Agent_Status = new TIBTable(NULL);
	Table_Agent_Status->Database=MainConn;
	Table_Agent_Status->Transaction=TransactionAgent;
	Table_Agent_Status->TableName = "ITEMS";
	Table_Agent_Status->Filter="RAZDEL=52";
	Table_Agent_Status->Filtered=TRUE;
	Table_Agent_Status->Active = TRUE;
	Table_Agent_Status->FetchAll();
	Agent_Status_datasource = new TDataSource(NULL);
	Agent_Status_datasource->DataSet=Table_Agent_Status;
}
//---------------------------------------------------------------------------
void __fastcall TFormAgKartEdit::FormShow(TObject *Sender)
{
	//Должность
	Status_DBLookupComboBoxCentre->ListSource=Agent_Status_datasource;
	Status_DBLookupComboBoxCentre->ListField="FULLNAME";
	Status_DBLookupComboBoxCentre->KeyField="CODE";
	Status_DBLookupComboBoxCentre->DataSource=Agent_datasource;
	Status_DBLookupComboBoxCentre->DataField="STATUSID";

	// Фамилия
	Surname_DBEdit->DataSource=Agent_datasource;
	Surname_DBEdit->DataField="SURNAME";

	// Имя
	Name_DBEdit->DataSource=Agent_datasource;
	Name_DBEdit->DataField="NAME";

	// Отчество
	Secname_DBEdit->DataSource=Agent_datasource;
	Secname_DBEdit->DataField="SECNAME";

	// Полное имя
	Fullname_DBEdit->DataSource=Agent_datasource;
	Fullname_DBEdit->DataField="FULLNAME";

	// Рекламное имя
	ReklName_DBEdit->DataSource=Agent_datasource;
	ReklName_DBEdit->DataField="ADVERTNAME";

	// Дата заполнения
	DateEnter_DBEdit->DataSource=Agent_datasource;
	DateEnter_DBEdit->DataField="DATEENTER";

	// Карта №
	KartNo_DBEdit->DataSource=Agent_datasource;
	KartNo_DBEdit->DataField="NUMBID";

	// Рекламный телефон
	ReklPhone_DBEdit->DataSource=Agent_datasource;
	ReklPhone_DBEdit->DataField="MAINPHONE";

	// Дополнительный телефон
	PhoneAdd_DBEdit->DataSource=Agent_datasource;
	PhoneAdd_DBEdit->DataField="ADDPHONE";

	// Сотовый телефон
	SotPhone_DBEdit->DataSource=Agent_datasource;
	SotPhone_DBEdit->DataField="MOBILEPHONE";

	// e-mail
	E_mail_DBEdit->DataSource=Agent_datasource;
	E_mail_DBEdit->DataField="E_MAIL";

	// Имя
	Name_DBCheckBox->DataSource=Agent_datasource;
	Name_DBCheckBox->DataField="CHKNAME";

	// Цена
	Price_DBCheckBox->DataSource=Agent_datasource;
	Price_DBCheckBox->DataField="CHKPRICE";

	// Рекламный телефон
	Main_DBCheckBox->DataSource=Agent_datasource;
	Main_DBCheckBox->DataField="CHKMAIN";

	// Дополнительный телефон
	Add_DBCheckBox->DataSource=Agent_datasource;
	Add_DBCheckBox->DataField="CHKADD";

	// Сотовый телефон
	Sot_DBCheckBox->DataSource=Agent_datasource;
	Sot_DBCheckBox->DataField="CHKSOT";

	// e-mail
	e_mail_DBCheckBox->DataSource=Agent_datasource;
	e_mail_DBCheckBox->DataField="CHKE_MAIL";

}
//---------------------------------------------------------------------------
void __fastcall TFormAgKartEdit::FormDestroy(TObject *Sender)
{
	//delete Agent_Status_datasource;
	//delete Table_Agent_Status;
	//delete TransactionAgent;
}
//---------------------------------------------------------------------------
void __fastcall TFormAgKartEdit::Button1Click(TObject *Sender)
{
	//Фиксация изменений
	Agent_datasource->DataSet->CheckBrowseMode();
	//Записать изменения в базу данных
	TransactionAgent->CommitRetaining();
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAgKartEdit::Surname_DBEditEnter(TObject *Sender)
{
	//---- Переключение раскладки клавиатуры
	char s[64];
	GetKeyboardLayoutName(s);
	//таким образом получаем текущий язык (активное окно)
	if (s!="00000419") {
		 //LoadKeyboardLayout("00000409", KLF_ACTIVATE);
		//Engлиш
		LoadKeyboardLayout("00000419", KLF_ACTIVATE);
		//Руссиан
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAgKartEdit::E_mail_DBEditEnter(TObject *Sender)
{
	//---- Переключение раскладки клавиатуры
	char s[64];
	GetKeyboardLayoutName(s);
	//таким образом получаем текущий язык (активное окно)
	if (s!="00000419") {
		 LoadKeyboardLayout("00000409", KLF_ACTIVATE);
		//Engлиш
		//LoadKeyboardLayout("00000419", KLF_ACTIVATE);
		//Руссиан
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormAgKartEdit::ButtonPassClick(TObject *Sender)
{
	FormAgentPass = new TFormAgentPass(this,Agent_datasource,TransactionAgent);
	FormAgentPass->ShowModal();
	delete FormAgentPass;
}
//---------------------------------------------------------------------------

