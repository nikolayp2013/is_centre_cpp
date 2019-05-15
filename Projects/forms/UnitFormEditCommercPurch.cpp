//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormEditCommercPurch.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBLookupComboBoxCentre"
#pragma link "my_DBCtrls"
#pragma resource "*.dfm"
TFormEditCommercPurch *FormEditCommercPurch;
// Таблица со списком элементов
TIBTable * Table_Items = NULL;
extern TIBTable * Table_Items;
// Таблица со списком клиентов
TIBTable * Table_Clients = NULL;
extern TIBTable * Table_Clients;
TDataSource * Clients_Datasource =NULL;
extern TDataSource * Clients_Datasource;
// Таблица со списком категорий клиента
TIBTable * Table_Clients_kategory1 = NULL;
extern TIBTable * Table_Clients_kategory1;
TIBTable * Table_Clients_kategory2 = NULL;
extern TIBTable * Table_Clients_kategory2;
TDataSource * Clients_Datasource_kategory =NULL;
extern TDataSource * Clients_Datasource_kategory;
// Для агента
TIBTransaction * TransactionAgent = NULL;
extern TIBTransaction * TransactionAgent;
// Таблица со списком агентов
TIBTable * Table_Agent = NULL;
extern TIBTable * Table_Agent;
TDataSource * Agent_datasource = NULL;
extern TDataSource * Agent_datasource;
// Таблица цель использования
TIBTable * Table_Purposeuse = NULL;
extern TIBTable * Table_Purposeuse;
TDataSource * Purposeuse_datasource = NULL;
extern TDataSource * Purposeuse_datasource;
// Таблица тип недвижимости
TIBTable * Table_Typeowner = NULL;
extern TIBTable * Table_Typeowner;
TDataSource * Typeowner_datasource = NULL;
extern TDataSource * Typeowner_datasource;
// Таблица право
TIBTable * Table_Low = NULL;
extern TIBTable * Table_Low;
TDataSource * Low_datasource = NULL;
extern TDataSource * Low_datasource;
// Таблица состояние
TIBTable * Table_State = NULL;
extern TIBTable * Table_State;
TDataSource * State_datasource = NULL;
extern TDataSource * State_datasource;
// Таблица интернет
TIBTable * Table_Internet = NULL;
extern TIBTable * Table_Internet;
TDataSource * Internet_datasource = NULL;
extern TDataSource * Internet_datasource;
TIBTransaction * OtherTransaction = NULL;
extern TIBTransaction * OtherTransaction;
//---------------------------------------------------------------------------
__fastcall TFormEditCommercPurch::TFormEditCommercPurch(TComponent* Owner)
	: TForm(Owner)
{
	/*OtherTransaction = new TIBTransaction(NULL);
	OtherTransaction->DefaultDatabase = MainForm->MainConn;

	//Создать табличку со списко клиентов
	Table_Clients = new TIBTable(NULL);
	Table_Clients->Database=MainForm->MainConn;
	Table_Clients->Transaction=OtherTransaction;
	Table_Clients->TableName = "CLIENTS";
	Table_Clients->Filter = "COMPID=";
	char * tmpint = new char[17];
	itoa(OwnerCode,tmpint,10);
	Table_Clients->Filter = Table_Clients->Filter+tmpint;
	delete tmpint;
	Table_Clients->Filtered = true;
	Table_Clients->Active=true;
	Table_Clients->FetchAll();

	//Создать табличку со списком категорий клиентов
	Table_Clients_kategory1 = new TIBTable(NULL);
	Table_Clients_kategory1->Database=MainForm->MainConn;
	Table_Clients_kategory1->Transaction=OtherTransaction;
	Table_Clients_kategory1->TableName = "ITEMS";
	Table_Clients_kategory1->Filter = "RAZDEL=15 and MGROUP=0";
	Table_Clients_kategory1->Filtered = true;
	Table_Clients_kategory1->Active=true;
	Table_Clients_kategory1->FetchAll();
	Table_Clients_kategory1->Edit();

	//Создать табличку со списком категорий клиентов для юр. лица
	Table_Clients_kategory2 = new TIBTable(NULL);
	Table_Clients_kategory2->Database=MainForm->MainConn;
	Table_Clients_kategory2->Transaction=OtherTransaction;
	Table_Clients_kategory2->TableName = "ITEMS";
	Table_Clients_kategory2->Filter = "RAZDEL=15 and MGROUP=1";
	Table_Clients_kategory2->Filtered = true;
	Table_Clients_kategory2->Active=true;
	Table_Clients_kategory2->FetchAll();
	Table_Clients_kategory2->Edit();

	//Создать табличку цель использования
	Table_Purposeuse = new TIBTable(NULL);
	Table_Purposeuse->Database=MainForm->MainConn;
	Table_Purposeuse->Transaction=OtherTransaction;
	Table_Purposeuse->TableName = "ITEMS";
	Table_Purposeuse->Filter = "RAZDEL=46";
	Table_Purposeuse->Filtered = true;
	Table_Purposeuse->Active=true;
	Table_Purposeuse->FetchAll();
	Table_Purposeuse->Edit();
	Purposeuse_datasource = new TDataSource(NULL);
	Purposeuse_datasource->DataSet=Table_Purposeuse;

	//Создать табличку право
	Table_Low = new TIBTable(NULL);
	Table_Low->Database=MainForm->MainConn;
	Table_Low->Transaction=OtherTransaction;
	Table_Low->TableName = "ITEMS";
	Table_Low->Filter = "RAZDEL=60";
	Table_Low->Filtered = true;
	Table_Low->Active=true;
	Table_Low->FetchAll();
	Table_Low->Edit();
	Low_datasource = new TDataSource(NULL);
	Low_datasource->DataSet=Table_Low;

	//Создать тип недвижимости
	Table_Typeowner = new TIBTable(NULL);
	Table_Typeowner->Database=MainForm->MainConn;
	Table_Typeowner->Transaction=OtherTransaction;
	Table_Typeowner->TableName = "ITEMS";
	Table_Typeowner->Filter = "RAZDEL=87";
	Table_Typeowner->Filtered = true;
	Table_Typeowner->Active=true;
	Table_Typeowner->FetchAll();
	Table_Typeowner->Edit();
	Typeowner_datasource = new TDataSource(NULL);
	Typeowner_datasource->DataSet=Table_Typeowner;

	//Создать состояние
	Table_State = new TIBTable(NULL);
	Table_State->Database=MainForm->MainConn;
	Table_State->Transaction=OtherTransaction;
	Table_State->TableName = "ITEMS";
	Table_State->Filter = "RAZDEL=72";
	Table_State->Filtered = true;
	Table_State->Active=true;
	Table_State->FetchAll();
	Table_State->Edit();
	State_datasource = new TDataSource(NULL);
	State_datasource->DataSet=Table_State;

	// Интернет
	Table_Internet = new TIBTable(NULL);
	Table_Internet->Database=MainForm->MainConn;
	Table_Internet->Transaction=OtherTransaction;
	Table_Internet->TableName = "ITEMS";
	Table_Internet->Filter = "RAZDEL=70";
	Table_Internet->Filtered = true;
	Table_Internet->Active=true;
	Table_Internet->FetchAll();
	Table_Internet->Edit();
	Internet_datasource = new TDataSource(NULL);
	Internet_datasource->DataSet=Table_Internet;

	//Создать объект DataSource для таблицы категорий клиентов
	Clients_Datasource_kategory = new TDataSource(NULL);

	//Создать объект DataSource для таблицы клиентов
	Clients_Datasource = new TDataSource(NULL);
	Clients_Datasource->DataSet=Table_Clients;

	// Вызов процедуры обновления сведений о клиенте
	ProcRefreshClient(this);

	//Для агента
	TransactionAgent = new TIBTransaction(NULL);
	TransactionAgent->DefaultDatabase = MainForm->MainConn;

    //Таблица со списком агентов
	Table_Agent = new TIBTable(NULL);
	Table_Agent->Database=MainForm->MainConn;
	Table_Agent->Transaction=TransactionAgent;
	Table_Agent->TableName = "PEOPLE";
	Table_Agent->Active = true;
	Table_Agent->FetchAll();
	Agent_datasource = new TDataSource(NULL);

	//Цикл по всем записям таблицы
	 Table_Agent->First();
	 do {
		Agent_ComboBox->Items->Add(Table_Agent->FieldByName("FULLNAME")->AsString);
		Table_Agent->Next();
	 } while(!Table_Agent->Eof);
	 Table_Agent->First();

	Agent_datasource->DataSet=Table_Agent;
	Agent_datasource->DataSet->Active=false;
	if (!(MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->IsNull ||
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->AsInteger==0)) {
		Agent_datasource->DataSet->Active=True;
		Agent_datasource->DataSet->First();
		if (Agent_datasource->DataSet->Locate("ID",MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->AsInteger,TLocateOptions())) {
			 Agent_ComboBox->ItemIndex = Agent_datasource->DataSet->RecNo-1;
		} else {
		}
	} else {
	}
	if (Agent_datasource->DataSet->Active) {
		Agent_datasource->DataSet->FieldByName("MAINPHONE")->EditMask="000\-00\-00;1;_";
		Agent_datasource->DataSet->FieldByName("ADDPHONE")->EditMask="000\-00\-00;1;_";
	}

	//Создать табличку со списко элементов
	Table_Items = new TIBTable(NULL);
	Table_Items->Database=MainForm->MainConn;
	Table_Items->Transaction=OtherTransaction;
	Table_Items->TableName = "ITEMS";
	Table_Items->Filter = "Razdel=8";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==1) {
		Flow_1_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==2) {
		Flow_2_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==3) {
		Flow_3_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==4) {
		Flow_4_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==5) {
		Flow_5_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==6) {
		Flow_6_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==7) {
		Flow_7_RadioButton->Checked = true;
	} */
}
//---------------------------------------------------------------------------
void __fastcall TFormEditCommercPurch::ProcRefreshClient(TObject *Sender)
{
	Clients_Datasource->DataSet->Active=true;
	Clients_Datasource->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	if (!(MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->IsNull||
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger==0)&&
		Table_Clients->Locate("ID", MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger,TLocateOptions())) {
		if (Table_Clients->FieldByName("FACE")->AsInteger==1) {
			Clients_Datasource_kategory->DataSet=Table_Clients_kategory1;
		} else {
			Clients_Datasource_kategory->DataSet=Table_Clients_kategory2;
		}
		Clients_Datasource_kategory->DataSet->Active=TRUE;
		if (Clients_Datasource_kategory->DataSet->Locate("CODE",Table_Clients->FieldByName("KATID")->AsInteger,TLocateOptions())) {
			ClientKatid_Edit->Text = Clients_Datasource_kategory->DataSet->FieldByName("FULLNAME")->AsString;
		} else {
			ClientKatid_Edit->Text = "";
		}
	} else {
		//MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger=0;
		ClientKatid_Edit->Text = "";
		Clients_Datasource->DataSet->Active=false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormEditCommercPurch::BitBtn1Click(TObject *Sender)
{
	// Кнопка сохранить изменения

	//Фиксация изменений
	MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
	//Записать изменения в базу данных
	OtherTransaction->CommitRetaining();
	//Открыть набор данных
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormEditCommercPurch::Flat_ButtonClick(TObject *Sender)
{
	// Кнопка выбрать "Квартиру"
	Table_Items->Active=false;
	Table_Items->Filtered = false;
	Table_Items->Filter = "Razdel=56";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	UnicodeString * resultstr = new UnicodeString;
	*resultstr = MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("FLAT")->AsString;

	FormSelect = new TFormSelect(this, Table_Items, resultstr);
	FormSelect->ShowModal();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("FLAT")->AsString = *resultstr;
	delete FormSelect;
	delete resultstr;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::Region_ButtonClick(TObject *Sender)
{
	// Кнопка выбрать район
	Table_Items->Active=false;
	Table_Items->Filtered = false;
	Table_Items->Filter = "Razdel=8";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	UnicodeString * resultstr = new UnicodeString;
	*resultstr = MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("REGION")->AsString;

	FormSelect = new TFormSelect(this, Table_Items, resultstr);
	FormSelect->ShowModal();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("REGION")->AsString = *resultstr;
	delete FormSelect;
	delete resultstr;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::Button10Click(TObject *Sender)
{
	// Очистить поле "Квартира"
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("FLAT")->AsString = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::Typehouse_ButtonClick(TObject *Sender)
{
	// Кнопка выбрать характеристику дома
	Table_Items->Active=false;
	Table_Items->Filtered = false;
	Table_Items->Filter = "Razdel=9";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	UnicodeString * resultstr = new UnicodeString;
	*resultstr = MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("TYPEHOUSE")->AsString;

	FormSelect = new TFormSelect(this, Table_Items, resultstr);
	FormSelect->ShowModal();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("TYPEHOUSE")->AsString = *resultstr;
	delete FormSelect;
	delete resultstr;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::Button11Click(TObject *Sender)
{
	// Очистить поле характеристика дома
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("TYPEHOUSE")->AsString = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::Stuffwall_ButtonClick(TObject *Sender)
{
	// Кнопка выбрать материал стен
	Table_Items->Active=false;
	Table_Items->Filtered = false;
	Table_Items->Filter = "Razdel=46";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	UnicodeString * resultstr = new UnicodeString;
	*resultstr = MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("PURPOSEUSE")->AsString;

	FormSelect = new TFormSelect(this, Table_Items, resultstr);
	FormSelect->ShowModal();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("PURPOSEUSE")->AsString = *resultstr;
	delete FormSelect;
	delete resultstr;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::Button12Click(TObject *Sender)
{
	 // Очистить поле материал стен
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("STUFFWALL")->AsString = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::Button13Click(TObject *Sender)
{
	// Очистить поле район
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("REGION")->AsString = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::PageControl1DrawTab(TCustomTabControl *Control,
          int TabIndex, const TRect &Rect, bool Active)
{
	TPageControl *control = (TPageControl*)Control;
	//control->Canvas->Brush->Color = clRed; // НЕОБХОДИМЫЙ ЦВЕТ!!!
	control->Canvas->Font = control->Font;
	//control->Canvas->Font->Style = Active ? control->Canvas->Font->Style << fsBold : control->Canvas->Font->Style >> fsBold;

	AnsiString text = control->Pages[TabIndex]->Caption;
	int textWidth = control->Canvas->TextWidth(text);
	int textHeight = control->Canvas->TextHeight(text);
	int textTop = Rect.Top + (Rect.Height() - textHeight)/2;
	int textLeft = Rect.Left + (Rect.Width() - textWidth)/2;

	control->Canvas->FillRect(Rect);
	control->Canvas->TextOut(textLeft, textTop, text);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::SpeedButton1Click(TObject *Sender)
{
	long * retval = new long;
	*retval = 0;
	FormKlients = new TFormKlients(MainForm, MainForm->MainConn, retval);
	FormKlients->ShowModal();
	if (*retval!=0) {
		 MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger=*retval;
	}
	// Вызов процедуры обновления сведений о клиенте
	ProcRefreshClient(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::SpeedButton3Click(TObject *Sender)
{
	 MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger=0;
	// Вызов процедуры обновления сведений о клиенте
	ProcRefreshClient(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::RefreshAgent(TObject *Sender)
{
	// Обновление сведений об агенте
	Agent_datasource->DataSet->Active=false;
	if (!(MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->IsNull ||
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->AsInteger==0)) {
		Agent_datasource->DataSet->Active=True;
		Agent_datasource->DataSet->First();
		if (Agent_datasource->DataSet->Locate("ID",MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->AsInteger,TLocateOptions())) {
			 Agent_ComboBox->ItemIndex = Agent_datasource->DataSet->RecNo-1;
		} else {
			Agent_datasource->DataSet->Active=false;
		}
	} else {
		Agent_datasource->DataSet->Active=false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::Agent_ComboBoxClick(TObject *Sender)
{
	Agent_datasource->DataSet->Active=true;
	Agent_datasource->DataSet->First();
	Agent_datasource->DataSet->MoveBy(Agent_ComboBox->ItemIndex);
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->AsInteger=
		Agent_datasource->DataSet->FieldByName("ID")->AsInteger;
	RefreshAgent(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::Button1Click(TObject *Sender)
{
	FormAgKartEdit = new TFormAgKartEdit(this,Agent_datasource,MainForm->MainConn,TransactionAgent);
	FormAgKartEdit->ShowModal();
	delete FormAgKartEdit;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::BitBtn2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercPurch::FormActivate(TObject *Sender)
{
	// Квартиру
	Flat_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Flat_DBEdit->DataField="FLAT";

	// Характеристика
	//Typehouse_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	//Typehouse_DBEdit->DataField="TYPEHOUSE";

	// Материал стен
	//Stuffwall_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	//Stuffwall_DBEdit->DataField="STUFFWALL";

	// Район
	Region_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Region_DBEdit->DataField="REGION";

	//
	Compstr_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Compstr_DBEdit->DataField="COMPSTR";

	// № Карты
	Num_card_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Num_card_DBEdit->DataField="NUM_CARD";

	// Балкон
	Swbalcony_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swbalcony_DBCheckBox->DataField="SWBALCONY";

	// Лоджия
	Swloggia_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swloggia_DBCheckBox->DataField="SWLOGGIA";

	// Лоджия
	Swphone_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swphone_DBCheckBox->DataField="SWPHONE";

	// Дополнительная информация
	Addinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Addinfo_DBMemo->DataField="ADDINFO";

	// Телефон клиента
	ClientPhone_DBEdit->DataSource=Clients_Datasource;
	ClientPhone_DBEdit->DataField="PHONE";
	// ICQ клиента
	ClientPager_DBEdit->DataSource=Clients_Datasource;
	ClientPager_DBEdit->DataField="PAGER";
	// E-mail клиента
	ClientOperator_DBEdit->DataSource=Clients_Datasource;
	ClientOperator_DBEdit->DataField="OPERATOR";
	// Фирма клиента
	ClientComp_DBEdit->DataSource=Clients_Datasource;
	ClientComp_DBEdit->DataField="COMP";
	// ФИО клиента
	ClientName_DBEdit->DataSource=Clients_Datasource;
	ClientName_DBEdit->DataField="NAME";
	// Сотовый клиента
	ClientMobile_DBEdit->DataSource=Clients_Datasource;
	ClientMobile_DBEdit->DataField="MOBILE";

	// Телефон агента
	AgentMainphone_DBEdit->DataSource=Agent_datasource;
	AgentMainphone_DBEdit->DataField="MAINPHONE";
	// Указывать в объявлениях имя
	AgChkname_DBCheckBox->DataSource=Agent_datasource;
	AgChkname_DBCheckBox->DataField="CHKNAME";
	// Указывать в объявлениях цену
	AgChkprice_DBCheckBox->DataSource=Agent_datasource;
	AgChkprice_DBCheckBox->DataField="CHKPRICE";
	// Указывать в объявлениях сотовый телефон
	AgChkSot_DBCheckBox->DataSource=Agent_datasource;
	AgChkSot_DBCheckBox->DataField="CHKSOT";
	// Указывать в объявлениях e-mail
	AgChke_mail_DBCheckBox->DataSource=Agent_datasource;
	AgChke_mail_DBCheckBox->DataField="CHKE_MAIL";
	// Указывать в объявлениях рекламный телефон
	AgChkmain_DBCheckBox->DataSource=Agent_datasource;
	AgChkmain_DBCheckBox->DataField="CHKMAIN";
	// Указывать в объявлениях дополнительный телефон
	AgChkadd_DBCheckBox->DataSource=Agent_datasource;
	AgChkadd_DBCheckBox->DataField="CHKADD";
	// Руб
	Swrub_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swrub_DBCheckBox->DataField="SWRUB";
	// Цена от
	Pricefrom_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Pricefrom_DBEdit->DataField="PRICEFROM";
	// Цена до
	Priceto_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Priceto_DBEdit->DataField="PRICETO";
	// Дата ввода
	Date_enter_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Date_enter_DBEdit->DataField="DATE_ENTER";
	// Дата корректировки
	Date_ch_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Date_ch_DBEdit->DataField="DATE_CH";
	// Дополнительная информация для агента
	Agentinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Agentinfo_DBMemo->DataField="AGENTINFO";
	// Рекламная информация
	Reklinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Reklinfo_DBMemo->DataField="REKLINFO";
	// Наименование запроса
	Namequery_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Namequery_DBEdit->DataField="NAMEQUERY";
	// Цель использования
	Purposeuse_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Purposeuse_DBEdit->DataField="PURPOSEUSE";
	// Тип недвижимости
	Typeowner_DBLookupComboBoxCentre->ListSource=Typeowner_datasource;
	Typeowner_DBLookupComboBoxCentre->ListField="FULLNAME";
	Typeowner_DBLookupComboBoxCentre->KeyField="ID";
	Typeowner_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Typeowner_DBLookupComboBoxCentre->DataField="TYPEOWNER";
	// Право
	Low_DBLookupComboBoxCentre->ListSource=Low_datasource;
	Low_DBLookupComboBoxCentre->ListField="FULLNAME";
	Low_DBLookupComboBoxCentre->KeyField="ID";
	Low_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Low_DBLookupComboBoxCentre->DataField="LOW";
	// Состояние
	State_DBLookupComboBoxCentre->ListSource=State_datasource;
	State_DBLookupComboBoxCentre->ListField="FULLNAME";
	State_DBLookupComboBoxCentre->KeyField="ID";
	State_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	State_DBLookupComboBoxCentre->DataField="STATE";
	// Интернет
	Internet_DBLookupComboBoxCentre->ListSource=Internet_datasource;
	Internet_DBLookupComboBoxCentre->ListField="FULLNAME";
	Internet_DBLookupComboBoxCentre->KeyField="ID";
	Internet_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Internet_DBLookupComboBoxCentre->DataField="INTERNET";
	// Площадь объекта от
	Objareafr_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Objareafr_DBEdit->DataField="OBJAREAFR";
	// Площадь объекта до
	Objareato_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Objareato_DBEdit->DataField="OBJAREATO";
	// Этаж от
	Levelfr_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Levelfr_DBEdit->DataField="LEVELFR";
	// Этаж до
	Levelto_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Levelto_DBEdit->DataField="LEVELTO";
	// Кол-во помещений от
	Roomfr_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Roomfr_DBEdit->DataField="ROOMFR";
	// Кол-во помещений до
	Roomto_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Roomto_DBEdit->DataField="ROOMTO";
	// Мин телефонов
	Minphone_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Minphone_DBEdit->DataField="MINPHONE";
	// Мин. санузлов
	Minnodesan_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Minnodesan_DBEdit->DataField="MINNODESAN";
	// Земельный участок от
	Landareafr_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Landareafr_DBEdit->DataField="LANDAREAFR";
	// Земельный участок до
	Landareato_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Landareato_DBEdit->DataField="LANDAREATO";
	// Мин. эл-ро энергии
	Minpower_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Minpower_DBCheckBox->DataField="MINPOWER";
	// Эектроэнергия
	Power_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Power_DBEdit->DataField="POWER";
	// Минимальные габариты въезда горизонт
	Heightgate_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Heightgate_DBEdit->DataField="HEIGHTGATE";
	// Минимальные габариты въезда вертикаль
	Widthgate_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Widthgate_DBEdit->DataField="WIDTHGATE";
	// Рампа
	Rampa_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Rampa_DBCheckBox->DataField="RAMPA";
	// Ж.дорога
	Train_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Train_DBCheckBox->DataField="TRAIN";
	// Отдельный вход
	Enter_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Enter_DBCheckBox->DataField="ENTER";
	// Публичность
	Public_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Public_DBCheckBox->DataField="PUBLIC";
	// Парковка
	Parking_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Parking_DBCheckBox->DataField="PARKING";
	// Отопление
	Hoting_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Hoting_DBCheckBox->DataField="HOTING";
	// Гор. вода
	Hotwater_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Hotwater_DBCheckBox->DataField="HOTWATER";
	// Газ
	Gaz_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Gaz_DBCheckBox->DataField="GAZ";
	// Канализация
	Waterdrain_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Waterdrain_DBCheckBox->DataField="WATERDRAIN";
}
//---------------------------------------------------------------------------

