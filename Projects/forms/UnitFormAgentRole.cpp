//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormAgentRole.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBLookupComboBoxCentre"
#pragma link "my_DBCtrls"
#pragma resource "*.dfm"
TFormAgentRole *FormAgentRole;
TIBDatabase * MainConn = NULL;
extern TIBDatabase * MainConn;
TIBTransaction * TransactionRole = NULL;
extern TIBTransaction * TransactionRole;
TIBTable * Table_Role = NULL;
extern TIBTable * Table_Role;
TDataSource * Role_datasource = NULL;
extern TDataSource * Role_datasource;
TIBTable * Table_Agent_Status = NULL;
extern TIBTable * Table_Agent_Status;
//---------------------------------------------------------------------------
__fastcall TFormAgentRole::TFormAgentRole(TComponent* Owner, TIBDatabase * MainConn_local)
	: TForm(Owner)
{
	MainConn = MainConn_local;
	TransactionRole = new TIBTransaction(NULL);
	TransactionRole->DefaultDatabase = MainConn;

	//Таблица со списком ролей
	Table_Role = new TIBTable(NULL);
	Table_Role->Database=MainConn;
	Table_Role->Transaction=TransactionRole;
	Table_Role->TableName = "ROLETABLE";
	Table_Role->Active = true;
	Table_Role->FetchAll();

	Role_datasource = new TDataSource(NULL);
	Role_datasource->DataSet=Table_Role;
	Role_datasource->DataSet->Edit();

	// Редактирование своих карточек
	Rmykart_DBCheckBox->DataSource=Role_datasource;
	Rmykart_DBCheckBox->DataField="RMYKART";

	// Редактирование карточек своей группы
	Rkartmygr_DBCheckBox->DataSource=Role_datasource;
	Rkartmygr_DBCheckBox->DataField="RKARTMYGR";

	// Редактирование всех карточек
	Rallkart_DBCheckBox->DataSource=Role_datasource;
	Rallkart_DBCheckBox->DataField="RALLKART";

	// Подача рекламаций
	Sendrekl_DBCheckBox->DataSource=Role_datasource;
	Sendrekl_DBCheckBox->DataField="SENDREKL";

	// Работа со входящей почтой
	Inmail_DBCheckBox->DataSource=Role_datasource;
	Inmail_DBCheckBox->DataField="INMAIL";

	// Работа с исходящей почтой
	Outmail_DBCheckBox->DataSource=Role_datasource;
	Outmail_DBCheckBox->DataField="OUTMAIL";

	// Печать прайс-листов
	Pplist_DBCheckBox->DataSource=Role_datasource;
	Pplist_DBCheckBox->DataField="PPLIST";

	// Установка меток для подачи объявлений
	Setmarker_DBCheckBox->DataSource=Role_datasource;
	Setmarker_DBCheckBox->DataField="SETMARKER";

	// Генерация объявлений
	Genmess_DBCheckBox->DataSource=Role_datasource;
	Genmess_DBCheckBox->DataField="GENMESS";

	// Работа с кадрами
	Workkadr_DBCheckBox->DataSource=Role_datasource;
	Workkadr_DBCheckBox->DataField="WORKKADR";

	// Работа со списком объектов
	Agentlist_DBCheckBox->DataSource=Role_datasource;
	Agentlist_DBCheckBox->DataField="AGENTLIST";

	// Работа со списком клиентов
	Klientlist_DBCheckBox->DataSource=Role_datasource;
	Klientlist_DBCheckBox->DataField="KLIENTLIST";

	// Установка сеанса связи
	Setconnect_DBCheckBox->DataSource=Role_datasource;
	Setconnect_DBCheckBox->DataField="SETCONNECT";

	// Возможность экспорта данных
	Export_DBCheckBox->DataSource=Role_datasource;
	Export_DBCheckBox->DataField="EXPORT";

	// Модификация печатных форм
	Modprintfr_DBCheckBox->DataSource=Role_datasource;
	Modprintfr_DBCheckBox->DataField="MODPRINTFR";

	// Достук к архиву объектов
	Arcobject_DBCheckBox->DataSource=Role_datasource;
	Arcobject_DBCheckBox->DataField="ARCOBJECT";

	// Просмотр своего внешнего прайс-листа
	Viewmypriceout_DBCheckBox->DataSource=Role_datasource;
	Viewmypriceout_DBCheckBox->DataField="VIEWMYPRICEOUT";

	// Работа с внутренним прайс-листом
	Workmypricein_DBCheckBox->DataSource=Role_datasource;
	Workmypricein_DBCheckBox->DataField="WORKMYPRICEIN";

	// Просмотр общего прайс-листа
	Viewcommprice_DBCheckBox->DataSource=Role_datasource;
	Viewcommprice_DBCheckBox->DataField="VIEWCOMMPRICE";

	// Использовать раздельные настройки
	Viewprop_DBCheckBox->DataSource=Role_datasource;
	Viewprop_DBCheckBox->DataField="VIEWPROP";

	//Таблица со списком ролей пользователей (статусов)
	Table_Agent_Status = new TIBTable(NULL);
	Table_Agent_Status->Database=MainConn;
	Table_Agent_Status->Transaction=TransactionRole;
	Table_Agent_Status->TableName = "ITEMS";
	Table_Agent_Status->Filter="RAZDEL=52";
	Table_Agent_Status->Filtered=TRUE;
	Table_Agent_Status->Active = true;
	Table_Agent_Status->FetchAll();

    //Цикл по всем записям таблицы
	 Table_Agent_Status->First();
	 do {
		Status_ComboBox->Items->Add(Table_Agent_Status->FieldByName("FULLNAME")->AsString);
		Table_Agent_Status->Next();
	 } while(!Table_Agent_Status->Eof);
	 Table_Agent_Status->First();

	 Role_datasource->DataSet->Locate("STATUSID", Table_Agent_Status->FieldByName("CODE")->AsString.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);

	 Status_ComboBox->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentRole::Button1Click(TObject *Sender)
{
	//Фиксация изменений
	Role_datasource->DataSet->CheckBrowseMode();
	//Записать изменения в базу данных
	TransactionRole->CommitRetaining();
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentRole::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentRole::Status_ComboBoxClick(TObject *Sender)
{
	Table_Agent_Status->First();
	Table_Agent_Status->MoveBy(Status_ComboBox->ItemIndex);

	Role_datasource->DataSet->Locate("STATUSID", Table_Agent_Status->FieldByName("CODE")->AsString.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
}
//---------------------------------------------------------------------------

void __fastcall TFormAgentRole::Button3Click(TObject *Sender)
{
	FormAgentRoleAdd = new TFormAgentRoleAdd(this);
	FormAgentRoleAdd->ShowModal();
	delete FormAgentRoleAdd;
}
//---------------------------------------------------------------------------

