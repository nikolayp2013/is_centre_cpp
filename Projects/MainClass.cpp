//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <ComObj.hpp>
#include <stdio.h>
#include <math.h>

#include "MainClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IBCustomDataSet"
#pragma link "IBDatabase"
#pragma link "IBTable"
#pragma link "DBLookupComboBoxCentre"
#pragma link "my_DBCtrls"
#pragma link "DBGridEh"
//#pragma link "DBGridEhGrouping"
#pragma link "GridsEh"
#pragma link "ToolCtrlsEh"
#pragma link "DataDriverEh"
#pragma link "MemTableDataEh"
#pragma link "IBXDataDriverEh"
#pragma link "MemTableEh"
#pragma link "frxClass"
#pragma link "frxPreview"
#pragma link "frxDesgn"
#pragma link "frxExportPDF"
#pragma link "frxExportXLS"
#pragma link "frxIBXComponents"
#pragma link "frxDBSet"
#pragma link "IBQuery"
#pragma link "IBQuery"
#pragma resource "*.dfm"
TMainForm *MainForm;
//Путь к экзешнику
//AnsiString sPath = ExtractFileDir(Application->ExeName);
TIniFile *Ini = new TIniFile(sPath+"\\THEMS\\options.ini");
TIniFile *IniFields = new TIniFile(sPath+"\\Propfiles\\fieldsdef.ini");
//TIBDatabase * MainConn = NULL;
//extern TIBDatabase * MainConn;
TIBTransaction * MainTransaction = NULL;
extern TIBTransaction * MainTransaction;
TIBTransaction * SpravTransaction = NULL;
extern TIBTransaction * SpravTransaction;
//TIBTable * MainTable = NULL;
//extern TIBTable * MainTable;
//TDataSource * TabPricelist_Datasource_Main =NULL;
//extern TDataSource * TabPricelist_Datasource_Main;
// Таблица со списком разделов прайс-листа
TIBTable * Table_Razdel = NULL;
extern TIBTable * Table_Razdel;
TDataSource * 	Razdel_datasource = NULL;
extern TDataSource * Razdel_datasource;
TIBTable * Table_Region_short = NULL;
extern TIBTable * Table_Region_short;
TIBTable * Table_mRegion_short = NULL;
extern TIBTable * Table_mRegion_short;
TIBTable * Table_Typehouse = NULL;
extern TIBTable * Table_Typehouse;
TIBTable * Table_Stuffwall = NULL;
extern TIBTable * Table_Stuffwall;
TIBTable * Table_Nodesan = NULL;
extern TIBTable * Table_Nodesan;
TIBTable * Table_Swphone = NULL;
extern TIBTable * Table_Swphone;
TIBTable * Table_Variant = NULL;
extern TIBTable * Table_Variant;
//TIBTable * Table_Abonents = NULL;
// Удаленные записи
TIBTable * Table_Delrecords = NULL;
extern TIBTable * Table_Delrecords;
// Таблица со списком полей
TIBDataSet * Table_Fieldsdef = NULL;
extern TIBDataSet * Table_Fieldsdef;
TIBTransaction * FieldsDefTransaction = NULL;
extern TIBTransaction * FieldsDefTransaction;
//TIBDataSet * MainTable = NULL;
extern TIBDataSet * MainTable;
//extern TIBXDataDriverEh * MainTable;
// Таблица со списком таблиц
TIBTable * Table_Tabledef = NULL;
extern TIBTable * Table_Tabledef;
TIBDataSet * TableFilter = NULL;
extern TIBDataSet * TableFilter;
TIBQuery * vMainTable = NULL;
extern TIBQuery * vMainTable;
String FilterMain = "test2";
String TypeObject = "ApartSell";
// Таблица с историей изменений в карте
TIBTable * Table_History = NULL;
extern TIBTable * Table_History;
TDataSource * History_datasource = NULL;
extern TDataSource * History_datasource;
//TDataSource * History_datasource = NULL;
//extern TDataSource * History_datasource;
TIBTransaction * OtherTransaction = NULL;
extern TIBTransaction * OtherTransaction;
// Таблица со списком групп
TIBTable * Table_Grouptable = NULL;
extern TIBTable * Table_Grouptable;
// Произвольный запрос
TIBQuery * QueryTab = NULL;
extern TIBQuery * QueryTab;
// Необходимость обновления полей главной таблицы
int needfieldsref = 1;
//AnsiString sPath = ExtractFileDir(Application->ExeName);
TIniFile *IniSer = new TIniFile(sPath+"\\ini\\server.ini");
int FormRegOk = 0;
int pricetype = 0;
int swinsert = 0;
String FilterSQL = "";
String strFilterAdd = "";
String strApartFilter = "";
/*String strApartPurchFilter = "";
String strRoomsSellFilter = "";
String strRoomsPurchFilter = "";
String strArendSellFilter = "";
String strArendPurchFilter = "";
String strHouseSellFilter = "";
String strHousePurchFilter = "";
String strGarageSellFilter = "";
String strGaragePurchFilter = "";
String strLandSellFilter = "";
String strNewBuildsSellFilter = "";
String strCommercPurchFilter = "";
String strCommercSell1Filter = "";
String strCommercSell2Filter = "";
String strCommercSell3Filter = "";
String strCommercSell4Filter = "";
String strBusinessSellFilter = "";
String strCommercSellAllFilter = "";
String strArendSellAllFilter = "";
String strAbroadSellFilter = "";*/
//---------------------------------------------------------------------------
//, TIBDatabase * MainConn_local
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	//ShowMessage("Init");
	//MainConn = new TIBDatabase(NULL);
	//MainConn = MainConn_local;
	//ShowMessage("Метка 1");
	//Создать объект транзакций
	MainConn->Connected = false;
	//MainConn1->DatabaseName="localhost:centre_db";
	//MainConn1->DatabaseName="C:\\ISCentre\\base\\CENTRE_DB.FDB";
	MainConn->DatabaseName=IniSer->ReadString("ServerFB","DBPath","");
	//ShowMessage(MainConn->DatabaseName);
	//MainConn1->DatabaseName="localhost:sssd";
	MainConn->Params->Clear();
	MainConn->Params->Add("user_name=sysdba");
	//MainConn1->Params->Add("user_name=Perov");
	MainConn->Params->Add("password=masterkey");
	//MainConn1->Params->Add("user_name=1");
	MainConn->Params->Add("lc_ctype=WIN1251");
	MainConn->LoginPrompt=FALSE;
	MainConn->Connected=TRUE;

	MainTransaction = new TIBTransaction(NULL);
	MainTransaction->DefaultDatabase = MainConn;

	OtherTransaction = new TIBTransaction(NULL);
	OtherTransaction->DefaultDatabase = MainConn;

	QueryTab = new TIBQuery(NULL);
	QueryTab->Database=MainConn;
	QueryTab->Transaction = MainTransaction;

	//Данная функция срабатывает при создании формы
	//ShowMessage(curVersion);

	// Установка тем
	SetThems(this);
	//Создать главный коннект к базе
	/*MainConn = new TIBDatabase(NULL);
	MainConn->DatabaseName="localhost:centre_db";
	//MainConn->DatabaseName="localhost:sssd";
	MainConn->Params->Add("user_name=sysdba");
	//MainConn->Params->Add("user_name=Perov");
	MainConn->Params->Add("password=masterkey");
	//MainConn->Params->Add("user_name=1");
	MainConn->Params->Add("lc_ctype=WIN1251");
	MainConn->LoginPrompt=FALSE;
	MainConn->Connected=TRUE; */

	//Создать объект транзакций
	/*MainTransaction = new TIBTransaction(NULL);
	MainTransaction->DefaultDatabase = MainConn;*/

	//Создать объект транзакций для справочников
	SpravTransaction = new TIBTransaction(NULL);
	SpravTransaction->DefaultDatabase = MainConn;

	//Создать объект транзакций для таблицы со списком полей
	FieldsDefTransaction = new TIBTransaction(NULL);
	FieldsDefTransaction->DefaultDatabase = MainConn;

	vMainTable = new TIBQuery(NULL);
	vMainTable->Database=MainConn;
	vMainTable->Transaction = MainTransaction;

	//Создать табличку со списко абонентов
	//Table_Abonents = new TIBTable(NULL);
	Table_Abonents->Database=MainConn;
	Table_Abonents->Transaction=MainTransaction;
	Table_Abonents->TableName = "ABONENTS";
	Table_Abonents->Filter = "COMPID="+(UnicodeString)OwnerCode;
	//Table_Abonents->
	char * tmpint = new char[17];
	itoa(OwnerCode,tmpint,10);
	//Table_Abonents->Filter = Table_Abonents->Filter+tmpint;
	delete tmpint;
	Table_Abonents->Filtered = true;
	Table_Abonents->Active=true;
	Table_Abonents->First();
	//Таблица со списком районов Самарской области
	Table_Items_8->Database=MainConn;
	Table_Items_8->Transaction=OtherTransaction;
	Table_Items_8->TableName = "ITEMS";
	Table_Items_8->Filter="RAZDEL=8";

	//Создать табличку короткое наименование района
	Table_Region_short = new TIBTable(NULL);
	Table_Region_short->Database=MainConn;
	Table_Region_short->Transaction=MainTransaction;
	Table_Region_short->TableName = "ITEMS";
	Table_Region_short->Filter = "RAZDEL=8";
	Table_Region_short->Filtered = true;
	Table_Region_short->Active=true;
	Table_Region_short->FetchAll();

	//Список удаленных записей
	Table_Delrecords = new TIBTable(NULL);
	Table_Delrecords->Database=MainConn;
	Table_Delrecords->Transaction=MainTransaction;
	Table_Delrecords->TableName = "DELRECORDS";
	Table_Delrecords->Active=true;

	//Создать табличку короткое наименование микрорайона
	Table_mRegion_short = new TIBTable(NULL);
	Table_mRegion_short->Database=MainConn;
	Table_mRegion_short->Transaction=MainTransaction;
	Table_mRegion_short->TableName = "ITEMS";
	Table_mRegion_short->Filter = "RAZDEL=10";
	Table_mRegion_short->Filtered = true;
	Table_mRegion_short->Active=true;
	Table_mRegion_short->FetchAll();

	//Создать табличку характеристика дома
	Table_Typehouse = new TIBTable(NULL);
	Table_Typehouse->Database=MainConn;
	Table_Typehouse->Transaction=MainTransaction;
	Table_Typehouse->TableName = "ITEMS";
	Table_Typehouse->Filter = "RAZDEL=9";
	Table_Typehouse->Filtered = true;
	Table_Typehouse->Active=true;
	Table_Typehouse->FetchAll();

	//Создать табличку материал стен
	Table_Stuffwall = new TIBTable(NULL);
	Table_Stuffwall->Database=MainConn;
	Table_Stuffwall->Transaction=MainTransaction;
	Table_Stuffwall->TableName = "ITEMS";
	Table_Stuffwall->Filter = "RAZDEL=6";
	Table_Stuffwall->Filtered = true;
	Table_Stuffwall->Active=true;
	Table_Stuffwall->FetchAll();

	//Создать табличку тип санузла
	Table_Nodesan = new TIBTable(NULL);
	Table_Nodesan->Database=MainConn;
	Table_Nodesan->Transaction=MainTransaction;
	Table_Nodesan->TableName = "ITEMS";
	Table_Nodesan->Filter = "RAZDEL=5";
	Table_Nodesan->Filtered = true;
	Table_Nodesan->Active=true;
	Table_Nodesan->FetchAll();

	//Создать табличку тип телефона
	Table_Swphone = new TIBTable(NULL);
	Table_Swphone->Database=MainConn;
	Table_Swphone->Transaction=MainTransaction;
	Table_Swphone->TableName = "ITEMS";
	Table_Swphone->Filter = "RAZDEL=7";
	Table_Swphone->Filtered = true;
	Table_Swphone->Active=true;
	Table_Swphone->FetchAll();

	//Создать табличку варианты продажи
	Table_Variant = new TIBTable(NULL);
	Table_Variant->Database=MainConn;
	Table_Variant->Transaction=MainTransaction;
	Table_Variant->TableName = "ITEMS";
	Table_Variant->Filter = "RAZDEL=3";
	Table_Variant->Filtered = true;
	Table_Variant->Active=true;
	Table_Variant->FetchAll();

	//Создать табличку со списком таблиц
	Table_Tabledef = new TIBTable(NULL);
	Table_Tabledef->Database=MainConn;
	Table_Tabledef->Transaction=FieldsDefTransaction;
	Table_Tabledef->TableName = "TABLEDEF";

	//Создать табличку со списком групп
	Table_Grouptable = new TIBTable(NULL);
	Table_Grouptable->Database=MainConn;
	Table_Grouptable->Transaction=FieldsDefTransaction;
	Table_Grouptable->TableName = "GROUPTABLE";
	Table_Grouptable->Active=true;
	Table_Grouptable->FetchAll();

	// Вызов процедуры обновления таблицы со списком талиц
	Refresh_Tabledef(this);

	//Создать табличку со списком полей
	Table_Fieldsdef = new TIBDataSet(NULL);
	Table_Fieldsdef->Database=MainConn;
	Table_Fieldsdef->Transaction=FieldsDefTransaction;
	/*Table_Fieldsdef->Database=MainConn;
	Table_Fieldsdef->Transaction=FieldsDefTransaction;
	Table_Fieldsdef->TableName = "FIELDSDEF";
	Table_Fieldsdef->Filter = "TABLEID=2";
	Table_Fieldsdef->Filtered = true;
	Table_Fieldsdef->Active=true;
	Table_Fieldsdef->FetchAll();*/
	Table_Fieldsdef->Active = false;
	Table_Fieldsdef->SelectSQL->Clear();
	Table_Fieldsdef->SelectSQL->Append("select * from fieldsdef order by tableid,ord");
	Table_Fieldsdef->ModifySQL->Clear();
	Table_Fieldsdef->ModifySQL->Append("update fieldsdef set MANCHECK=:MANCHECK, MANWIDTH=:MANWIDTH where ID=:OLD_ID");
	Table_Fieldsdef->RefreshSQL->Clear();
	Table_Fieldsdef->RefreshSQL->Append("select * from fieldsdef where ID=:ID order by tableid,ord");
	Table_Fieldsdef->Filtered = true;
	Table_Fieldsdef->Active = TRUE;

	// Вызов процедуры обновления таблицы со списком полей
	//ShowMessage("MainForm1");
	Refresh_Fieldsdef(this);

	//MainTable = new TIBDataSet(NULL);
	//MainTable->Database=MainConn;
	//MainTable->Transaction=MainTransaction;

	// Таблица с фильтром
	TableFilter = new TIBDataSet(NULL);
	TableFilter->Database=MainConn;
	TableFilter->Transaction=MainTransaction;
	TableFilter->SelectSQL->Append("select uuid from tablefilter where cur_user=user");
	TableFilter->InsertSQL->Append("insert into tablefilter (uuid,cur_user) values(:uuid,user)");
	TableFilter->DeleteSQL->Append("delete from tablefilter where uuid=:OLD_UUID and cur_user=user");
	TableFilter->RefreshSQL->Append("select uuid from tablefilter where uuid=:UUID and cur_user=user");
	TableFilter->Active=true;

	// Вызов процедуры обновления главной таблицы
	Filter_MainTable(this);

	//Создать объект DataSource для главной формы
	//MainTable->s
	//TabPricelist_Datasource_Main = new TDataSource(NULL);
	//TabPricelist_Datasource_Main->DataSet=MainTable;
	//TabPricelist_Datasource_Main->DataSet=ClientDataSet1;
	//ApplySortingForSQLBasedDataSet(DBMainGrid,MainTable,true,true,"%");
	//TabPricelist_Datasource_Main->DataSet=FormStart->MemTableEh1;
	//FormStart->MainConn1;
	//FormStart->IBTransaction1


	//MainTable->FetchAll();

	/*MainTable->First();
	for (int i = 0; i < 50; i++) {
        MainTable->First();
	}*/
	//TabPricelist_Datasource_Main->DataSet->Active=TRUE;

	//Присвоить главному гриду ссылку на DataSource
	//ShowMessage(DBMainGrid->RowCount);
	MainForm->DBMainGrid->DataSource=TabPricelist_Datasource_Main;
	//ShowMessage(DBMainGrid->RowCount);
	//DBMainGrid->
	// Фильтр этаж
	Level_ComboBox->Items->Add("Не важно");
	Level_ComboBox->Items->Add("Кроме крайних");
	Level_ComboBox->Items->Add("Кроме первого");
	Level_ComboBox->Items->Add("Кроме последнего");
	Level_ComboBox->Items->Add("Только крайние");
	Level_ComboBox->Items->Add("Только первый");
	Level_ComboBox->Items->Add("Только последний");

	ApartFilter(this);

	// История изменений в карте
	Table_History = new TIBTable(NULL);
	Table_History->Database=MainConn;
	Table_History->Transaction=OtherTransaction;
	Table_History->TableName = "KARTHISTORY";
	Table_History->Filter="IDPRICE=";
	Table_History->Filter=Table_History->Filter+TabPricelist_Datasource_Main->DataSet->FieldByName("ID")->AsString;
	Table_History->Filtered=TRUE;

	//Table_Grouptable
	ComboBox2->Items->Clear();
	ComboBox2->Items->Add("Свои филиалы");
	Table_Grouptable->First();
	while (!Table_Grouptable->Eof){
		ComboBox2->Items->Add(Table_Grouptable->FieldByName("GROUP_NAME")->AsString);
		Table_Grouptable->Next();
	}
    //ShowMessage("Метка2");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Refresh_Tabledef(TObject *Sender)
{
	// Процедура обновления таблицы со списком таблиц
	Table_Tabledef->Active=false;
	Table_Tabledef->Filtered = false;
	Table_Tabledef->Filter = "PROPER=14";
	if (Purch_Panel->BevelOuter == bvLowered) {
		Table_Tabledef->Filter = "PROPER=15";
	}
	Table_Tabledef->Filtered = true;
	Table_Tabledef->Active=true;
	Table_Tabledef->FetchAll();

	//Цикл по всем записям таблицы
	Razdel_ComboBox->Items->Clear();
	 Table_Tabledef->First();
	 do {
		Razdel_ComboBox->Items->Add(Table_Tabledef->FieldByName("TABLENAZV")->AsString);
		Table_Tabledef->Next();
	 } while(!Table_Tabledef->Eof);
	 Table_Tabledef->First();
	 Razdel_ComboBox->ItemIndex = 0;

	 Plus_ComboBox->Items->Add("+");
	 Plus_ComboBox->Items->Add("-");
	 Plus_ComboBox->ItemIndex=0;
	 Part_ComboBox->Items->Add("Ч");
	 Part_ComboBox->Items->Add("%");
	 Part_ComboBox->ItemIndex=0;

	 //ShowMessage("Метка 2");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Filter_MainTable(TObject *Sender)
{
	// Процедура установки фильтра на главную таблицу

	MainTable->DisableControls();
	Table_Tabledef->RecNo = Razdel_ComboBox->ItemIndex+1;
	String tablename = Table_Tabledef->FieldByName("Tablename")->AsString;
	String Select_sqltext = "";
	String Insert_sqltext = "";
	String Modify_sqltext = "";
	String Delete_sqltext = "";
	String Refresh_sqltext = "";
	//String FilterSQL = "";

	//  Квартиры - предложение
   if (AnsiUpperCase(tablename)=="APARTSELL") {
		Select_sqltext ="select a.*, 0 as pics, (select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"(select mobilephone from people where id=a.idagent) as mobilephone_text, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, ";
			// Расчет наценки (маржа)
			if (Marza_Edit->Text.Trim()!="0") {
				if (Part_ComboBox->ItemIndex==1) {
					// Если процент
					if (Plus_ComboBox->ItemIndex==0) {
						// + добавить
						Select_sqltext = Select_sqltext + "price + price/100*"+Marza_Edit->Text.Trim()+" as pricerub, "
							"cast((price + price/100*"+Marza_Edit->Text.Trim()+")/(select doll from valuta) as numeric(10,2)) as priceue, ";
					} else {
						// - уменьшить
						Select_sqltext = Select_sqltext + "price - price/100*"+Marza_Edit->Text.Trim()+" as pricerub, "
							"cast((price - price/100*"+Marza_Edit->Text.Trim()+")/(select doll from valuta) as numeric(10,2)) as priceue, ";
					}
				} else {
					// Если часть
                    if (Plus_ComboBox->ItemIndex==0) {
						// + добавить
						Select_sqltext = Select_sqltext + "price +10*"+Marza_Edit->Text.Trim()+" as pricerub, "
							"cast((price +10*"+Marza_Edit->Text.Trim()+")/(select doll from valuta) as numeric(10,2)) as priceue, ";
					} else {
						// - уменьшить
						//Select_sqltext = Select_sqltext + "price - 10*"+Marza_Edit->Text.Trim()+" as pricerub, "
						//	"cast(price - 10*"+Marza_Edit->Text.Trim()+"/(select doll from valuta) as numeric(10,2)) as priceue, ";

						Select_sqltext = Select_sqltext + "case when price - 10*"+Marza_Edit->Text.Trim()+"<0 then 0 else price - 10*"+Marza_Edit->Text.Trim()+" end as pricerub, "
							"cast((case when price - 10*"+Marza_Edit->Text.Trim()+"<0 then 0 else price - 10*"+Marza_Edit->Text.Trim()+" end)/(select doll from valuta) as numeric(10,2)) as priceue, ";
					}
                }
			} else {
				Select_sqltext = Select_sqltext + "price as pricerub, cast(price/(select doll from valuta) as numeric(10,2)) as priceue, ";
			}
			Select_sqltext = Select_sqltext + "region*1000+rooms as regroom"
			" from Apartsell a";
		/*if (!strFilterAdd.IsEmpty() || !strApartFilter.IsEmpty() || !FilterSQL.IsEmpty()) {
			 //ShowMessage("Пусто");
			 Select_sqltext = Select_sqltext + " Where " + strFilterAdd;
			 FilterSQL = FilterSQL + " and " + strFilterAdd;
			 if (!strFilterAdd.IsEmpty()) {
				 Select_sqltext = Select_sqltext + " and ";
				 FilterSQL = FilterSQL + " and ";
			 }
			 FilterSQL = FilterSQL + strApartFilter;
			 Select_sqltext = Select_sqltext + FilterSQL;
		}*/
		//Select_sqltext = Select_sqltext + " order by region, rooms";
		//ShowMessage(Select_sqltext);

		Insert_sqltext = "insert into APARTSELL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, PRICETYPE, SETMARK, REKLTEXT) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :PRICETYPE, :SETMARK, :REKLTEXT)";

		// \"CHECK\"=:\"CHECK\",
		Modify_sqltext = "update APARTSELL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND, SETMARK=:SETMARK, REKLTEXT=:REKLTEXT where ID = :OLD_ID";

		Delete_sqltext = "delete from APARTSELL where ID = :OLD_ID";

		Refresh_sqltext = "select APARTSELL.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, price as priceue, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from APARTSELL where ID = :ID";
   }

	//  Квартиры - спрос
   if (AnsiUpperCase(tablename)=="APARTPURCH") {
		Select_sqltext ="select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, "
			"pricefrom as price"
		" from ApartPurch a";

		Insert_sqltext = "insert into ApartPurch (ID, AGENT, NUM_CARD, DATE_CH, REGION, TYPEHOUSE, \"level\", STUFFWALL, SWBALCONY, "
			"SWPHONE, PRICEFROM, FLAT, SWLOGGIA, ADDINFO, PICS, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, PRICETO, SWRUB, \"CHECK\", PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :TYPEHOUSE, :\"level\", :STUFFWALL, :SWBALCONY, :SWPHONE, :PRICEFROM, "
			":FLAT, :SWLOGGIA, :ADDINFO, :PICS, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :PRICETO, :SWRUB, :\"CHECK\", :PRICETYPE)";

		Modify_sqltext = "update ApartPurch set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", STUFFWALL=:STUFFWALL, SWBALCONY=:SWBALCONY, "
			"SWPHONE=:SWPHONE, PRICEFROM=:PRICEFROM, FLAT=:FLAT, SWLOGGIA=:SWLOGGIA, ADDINFO=:ADDINFO, PICS=:PICS, CLIENT=:CLIENT, "
			"AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, PRICETO=:PRICETO, SWRUB=:SWRUB, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND, \"CHECK\"=:\"CHECK\"  where ID = :OLD_ID";

		Delete_sqltext = "delete from ApartPurch where ID = :OLD_ID";

		Refresh_sqltext = "select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, pricefrom as price "
		" from ApartPurch a where ID = :ID";
	}
   //  Комнаты - предложение
   if (AnsiUpperCase(tablename)=="ROOMSSELL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select mobilephone from people where id=a.idagent) as mobilephone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"cast(price/(select doll from valuta) as numeric(10,2)) as priceue, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from ROOMSSELL a";

		//ShowMessage(strRoomsSellFilter);
		//ShowMessage(Select_sqltext);
		Insert_sqltext = "insert into ROOMSSELL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, :PRICETYPE)";

		Modify_sqltext = "update ROOMSSELL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND where ID = :OLD_ID";

		Delete_sqltext = "delete from ROOMSSELL where ID = :OLD_ID";

		Refresh_sqltext = "select ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, TYPEHOUSE, \"level\", LEVELS, "
			"STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, "
			"CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, "
			"GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from ROOMSSELL where ID = :ID";
	}
   //  Комнаты - спрос
   if (AnsiUpperCase(tablename)=="ROOMSPURCH") {
		Select_sqltext ="select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, pricefrom as price, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from ROOMSPURCH a";

		Insert_sqltext = "insert into ROOMSPURCH (ID, AGENT, NUM_CARD, DATE_CH, REGION, TYPEHOUSE, \"level\", STUFFWALL, SWBALCONY, "
			"SWPHONE, PRICEFROM, FLAT, SWLOGGIA, ADDINFO, PICS, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, PRICETO, SWRUB, ROOMS, IROOMS, \"CHECK\", PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :TYPEHOUSE, :\"level\", :STUFFWALL, :SWBALCONY, :SWPHONE, :PRICEFROM, "
			":FLAT, :SWLOGGIA, :ADDINFO, :PICS, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :PRICETO, :SWRUB, "
			":ROOMS, :IROOMS, :\"CHECK\", :PRICETYPE)";

		Modify_sqltext = "update ROOMSPURCH set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", STUFFWALL=:STUFFWALL, SWBALCONY=:SWBALCONY, "
			"SWPHONE=:SWPHONE, PRICEFROM=:PRICEFROM, FLAT=:FLAT, SWLOGGIA=:SWLOGGIA, ADDINFO=:ADDINFO, PICS=:PICS, CLIENT=:CLIENT, "
			"AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, PRICETO=:PRICETO, "
			"ROOMS=:ROOMS, IROOMS=:IROOMS, SWRUB=:SWRUB, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND, \"CHECK\"=:\"CHECK\" where ID = :OLD_ID";

		Delete_sqltext = "delete from ROOMSPURCH where ID = :OLD_ID";

		Refresh_sqltext = "select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, pricefrom as price, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from ROOMSPURCH a where ID = :ID";
	}

	//  Аренда - предложение
   if (AnsiUpperCase(tablename)=="ARENDSELL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from ARENDSELL a";

		Insert_sqltext = "insert into ARENDSELL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, "
			"TYPEFLAT, SROK, SWSROK, FURNITURE, TV, AUDIO, INTERNET, KABTV, REFRIGERATOR, "
			"WASHING, KITCHEN, CONDITIONER, WINDOW, GAZKOL, KOMPAY, INTERNETPAY, ENERGY, "
			"WATER, GAZPAY, KABTVPAY, PHONEPAY, HOMEPHONE, PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, "
			":TYPEFLAT, :SROK, :SWSROK, :FURNITURE, :TV, :AUDIO, :INTERNET, :KABTV, :REFRIGERATOR, "
			":WASHING, :KITCHEN, :CONDITIONER, :WINDOW, :GAZKOL, :KOMPAY, :INTERNETPAY, :ENERGY, "
			":WATER, :GAZPAY, :KABTVPAY, :PHONEPAY, :HOMEPHONE, :PRICETYPE)";

		Modify_sqltext = "update ARENDSELL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, "
			"TYPEFLAT=:TYPEFLAT, SROK=:SROK, SWSROK=:SWSROK, FURNITURE=:FURNITURE, TV=:TV, AUDIO=:AUDIO, "
			"INTERNET=:INTERNET, KABTV=:KABTV, REFRIGERATOR=:REFRIGERATOR, WASHING=:WASHING, "
			"KITCHEN=:KITCHEN, CONDITIONER=:CONDITIONER, WINDOW=:WINDOW, GAZKOL=:GAZKOL, KOMPAY=:KOMPAY, "
			"INTERNETPAY=:INTERNETPAY, ENERGY=:ENERGY, WATER=:WATER, GAZPAY=:GAZPAY, KABTVPAY=:KABTVPAY, "
			"PHONEPAY=:PHONEPAY, HOMEPHONE=:HOMEPHONE, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND where ID = :OLD_ID";

		Delete_sqltext = "delete from ARENDSELL where ID = :OLD_ID";

		/*Refresh_sqltext = "select ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, TYPEHOUSE, \"level\", LEVELS, "
			"STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, "
			"CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, "
			"GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from ARENDSELL where ID = :ID"; */
		Refresh_sqltext = "select ARENDSELL.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from ARENDSELL where ID = :ID";
   }

   //  Аренда - спрос
   if (AnsiUpperCase(tablename)=="ARENDPURCH") {
		Select_sqltext ="select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from ARENDPURCH a";

		Insert_sqltext = "insert into ARENDPURCH (ID, AGENT, NUM_CARD, DATE_CH, REGION, TYPEHOUSE, \"level\", STUFFWALL, SWBALCONY, "
			"SWPHONE, PRICEFROM, FLAT, SWLOGGIA, ADDINFO, PICS, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, PRICETO, SWRUB, "
			"ROOMS, FURNITURE, REFRIGERATOR, AUDIO, FLOW, \"CHECK\", PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :TYPEHOUSE, :\"level\", :STUFFWALL, :SWBALCONY, :SWPHONE, :PRICEFROM, "
			":FLAT, :SWLOGGIA, :ADDINFO, :PICS, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :PRICETO, :SWRUB, "
			":ROOMS, :FURNITURE, :REFRIGERATOR, :AUDIO, :FLOW, :\"CHECK\", :PRICETYPE)";

		Modify_sqltext = "update ARENDPURCH set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", STUFFWALL=:STUFFWALL, SWBALCONY=:SWBALCONY, "
			"SWPHONE=:SWPHONE, PRICEFROM=:PRICEFROM, FLAT=:FLAT, SWLOGGIA=:SWLOGGIA, ADDINFO=:ADDINFO, PICS=:PICS, CLIENT=:CLIENT, "
			"AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, PRICETO=:PRICETO, SWRUB=:SWRUB, "
			"ROOMS=:ROOMS, FURNITURE=:FURNITURE, REFRIGERATOR=:REFRIGERATOR, AUDIO=:AUDIO, FLOW=:FLOW, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND where ID = :OLD_ID";

		Delete_sqltext = "delete from ARENDPURCH where ID = :OLD_ID";

		Refresh_sqltext = "select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from ARENDPURCH a where ID = :ID";
	}

	//  Дома, дачи, коттеджи - предложение
   if (AnsiUpperCase(tablename)=="HOUSESELL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"0 as priceue_text, "
			"0 as priceru_text "
			" from HOUSESELL a";

		Insert_sqltext = "insert into HOUSESELL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"REALSTATE, PLACE, FORMOWNER, FORMOFFER, SIZEHOUSE, READY, TYPERIGHT, ENERGY, WATER, "
			"HEATING, WATERDRAIN, SAUNA, GARAGE, FROMWATER, FROMBUS, FROMFOREST, FROMTRAIN, LANDAREA, PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":REALSTATE, :PLACE, :FORMOWNER, :FORMOFFER, :SIZEHOUSE, :READY, :TYPERIGHT, :ENERGY, :WATER, "
			":HEATING, :WATERDRAIN, :SAUNA, :GARAGE, :FROMWATER, :FROMBUS, :FROMFOREST, :FROMTRAIN, :LANDAREA, :PRICETYPE)";


		Modify_sqltext = "update HOUSESELL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"REALSTATE=:REALSTATE, PLACE=:PLACE, FORMOWNER=:FORMOWNER, FORMOFFER=:FORMOFFER, SIZEHOUSE=:SIZEHOUSE, READY=:READY, "
			"TYPERIGHT=:TYPERIGHT, ENERGY=:ENERGY, WATER=:WATER, HEATING=:HEATING, WATERDRAIN=:WATERDRAIN, SAUNA=:SAUNA, "
			"GARAGE=:GARAGE, FROMWATER=:FROMWATER, FROMBUS=:FROMBUS, FROMFOREST=:FROMFOREST, FROMTRAIN=:FROMTRAIN, LANDAREA=:LANDAREA, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND "
			" where ID = :OLD_ID";

		Delete_sqltext = "delete from HOUSESELL where ID = :OLD_ID";

		Refresh_sqltext = "select HOUSESELL.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"0 as priceue_text, "
			"0 as priceru_text "
			"from HOUSESELL where ID = :ID";
	}

	//  Дома, дачи, коттеджи - спрос
   if (AnsiUpperCase(tablename)=="HOUSEPURCH") {
		Select_sqltext ="select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from HOUSEPURCH a";

		Insert_sqltext = "insert into HOUSEPURCH (ID, AGENT, NUM_CARD, DATE_CH, REGION, TYPEHOUSE, \"level\", STUFFWALL, SWBALCONY, "
			"SWPHONE, PRICEFROM, FLAT, SWLOGGIA, ADDINFO, PICS, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, PRICETO, SWRUB, "
			"realstate, formpurch, gaz, energy, heating, waterdrain, phone, landarea, garage, marker, \"CHECK\", PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :TYPEHOUSE, :\"level\", :STUFFWALL, :SWBALCONY, :SWPHONE, :PRICEFROM, "
			":FLAT, :SWLOGGIA, :ADDINFO, :PICS, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :PRICETO, :SWRUB, "
			":realstate, :formpurch, :gaz, :energy, :heating, :waterdrain, :phone, :landarea, :garage, :marker, :\"CHECK\", :PRICETYPE)";

		Modify_sqltext = "update HOUSEPURCH set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", STUFFWALL=:STUFFWALL, SWBALCONY=:SWBALCONY, "
			"SWPHONE=:SWPHONE, PRICEFROM=:PRICEFROM, FLAT=:FLAT, SWLOGGIA=:SWLOGGIA, ADDINFO=:ADDINFO, PICS=:PICS, CLIENT=:CLIENT, "
			"AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, PRICETO=:PRICETO, SWRUB=:SWRUB, "
			"realstate=:realstate, formpurch=:formpurch, gaz=:gaz, energy=:energy, heating=:heating, waterdrain=:waterdrain, "
			"phone=:phone, landarea=:landarea, garage=:garage, marker=:marker, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND, \"CHECK\"=:\"CHECK\" "
			" where ID = :OLD_ID";

		Delete_sqltext = "delete from HOUSEPURCH where ID = :OLD_ID";

		Refresh_sqltext = "select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from HOUSEPURCH a where ID = :ID";
	}

   //  Гаражи, уч-ки - предложение
   if (AnsiUpperCase(tablename)=="GARAGESELL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from GARAGESELL a";

		Insert_sqltext = "insert into GARAGESELL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"realstate, formowner, formsell, sizehouse, hightgate, floor, roof, gate, fromtransp, "
			"viewhole, hole, build, energy380, energy220, energy12, heating, PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":realstate, :formowner, :formsell, :sizehouse, :hightgate, :floor, :roof, :gate, :fromtransp, "
			":viewhole, :hole, :build, :energy380, :energy220, :energy12, :heating, :PRICETYPE)";

		Modify_sqltext = "update GARAGESELL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"realstate=:realstate, formowner=:formowner, formsell=:formsell, sizehouse=:sizehouse, "
			"hightgate=:hightgate, floor=:floor, roof=:roof, gate=:gate, fromtransp=:fromtransp, "
			"viewhole=:viewhole, hole=:hole, build=:build, energy380=:energy380, energy220=:energy220, "
			"energy12=:energy12, heating=:heating, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND "
			" where ID = :OLD_ID";

		Delete_sqltext = "delete from GARAGESELL where ID = :OLD_ID";

		Refresh_sqltext = "select GARAGESELL.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from GARAGESELL where ID = :ID";
	}

   //  Гаражи, уч-ки - спрос
   if (AnsiUpperCase(tablename)=="GARAGEPURCH") {
		Select_sqltext ="select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from GARAGEPURCH a";

		Insert_sqltext = "insert into GARAGEPURCH (ID, AGENT, NUM_CARD, DATE_CH, REGION, TYPEHOUSE, \"level\", STUFFWALL, SWBALCONY, "
			"SWPHONE, PRICEFROM, FLAT, SWLOGGIA, ADDINFO, PICS, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, PRICETO, SWRUB, "
			"FORMPURCH, REALSTATE, VIEWHOLE, HOLE, SECURETY, POWER380, POWER220, POWER12, LENGARAGE, "
			"WIDTHGARAGE, HEIGHTGATE, HEIGHTGARAGE, \"CHECK\", PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :TYPEHOUSE, :\"level\", :STUFFWALL, :SWBALCONY, :SWPHONE, :PRICEFROM, "
			":FLAT, :SWLOGGIA, :ADDINFO, :PICS, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :PRICETO, :SWRUB, "
			":FORMPURCH, :REALSTATE, :VIEWHOLE, :HOLE, :SECURETY, :POWER380, :POWER220, :POWER12, :LENGARAGE, "
			":WIDTHGARAGE, :HEIGHTGATE, :HEIGHTGARAGE, :\"CHECK\", :PRICETYPE)";

		Modify_sqltext = "update GARAGEPURCH set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", STUFFWALL=:STUFFWALL, SWBALCONY=:SWBALCONY, "
			"SWPHONE=:SWPHONE, PRICEFROM=:PRICEFROM, FLAT=:FLAT, SWLOGGIA=:SWLOGGIA, ADDINFO=:ADDINFO, PICS=:PICS, CLIENT=:CLIENT, "
			"AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, PRICETO=:PRICETO, SWRUB=:SWRUB, "
			"FORMPURCH=:FORMPURCH, REALSTATE=:REALSTATE, VIEWHOLE=:VIEWHOLE, HOLE=:HOLE, SECURETY=:SECURETY, POWER380=:POWER380, "
			"POWER220=:POWER220, POWER12=:POWER12, LENGARAGE=:LENGARAGE, WIDTHGARAGE=:WIDTHGARAGE, HEIGHTGATE=:HEIGHTGATE, "
			"HEIGHTGARAGE=:HEIGHTGARAGE, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND, \"CHECK\"=:\"CHECK\"  where ID = :OLD_ID";

		Delete_sqltext = "delete from GARAGEPURCH where ID = :OLD_ID";

		Refresh_sqltext = "select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from GARAGEPURCH a where ID = :ID";
	}

	//  Земельные участки - предложение
   if (AnsiUpperCase(tablename)=="LANDSELL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from LANDSELL a";

		Insert_sqltext = "insert into LANDSELL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"REALSTATE, FORMOWNER, FORMOFFER, PLACE, LANDAREA, LANDSTATE, HOUSEOWNER, WRITEOWNER, "
			"WATER, WATERDRAIN, POWER, WATERADD, WATERDRAINADD, POWERADD, GAZADD, FROMWATER, FROMBUS, "
			"FROMFOREST, FROMTRAIN, PURPOSEUSE, ZONE, BOUND, DOC, PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":REALSTATE, :FORMOWNER, :FORMOFFER, :PLACE, :LANDAREA, :LANDSTATE, :HOUSEOWNER, :WRITEOWNER, "
			":WATER, :WATERDRAIN, :POWER, :WATERADD, :WATERDRAINADD, :POWERADD, :GAZADD, :FROMWATER, :FROMBUS, "
			":FROMFOREST, :FROMTRAIN, :PURPOSEUSE, :ZONE, :BOUND, :DOC, :PRICETYPE)";

		Modify_sqltext = "update LANDSELL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"REALSTATE=:REALSTATE, FORMOWNER=:FORMOWNER, FORMOFFER=:FORMOFFER, PLACE=:PLACE, LANDAREA=:LANDAREA, "
			"LANDSTATE=:LANDSTATE, HOUSEOWNER=:HOUSEOWNER, WRITEOWNER=:WRITEOWNER, "
			"WATER=:WATER, WATERDRAIN=:WATERDRAIN, POWER=:POWER, WATERADD=:WATERADD, WATERDRAINADD=:WATERDRAINADD, "
			"POWERADD=:POWERADD, GAZADD=:GAZADD, FROMWATER=:FROMWATER, FROMBUS=:FROMBUS, "
			"FROMFOREST=:FROMFOREST, FROMTRAIN=:FROMTRAIN, PURPOSEUSE=:PURPOSEUSE, ZONE=:ZONE, "
			"BOUND=:BOUND, DOC=:DOC, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND where ID = :OLD_ID";

		Delete_sqltext = "delete from LANDSELL where ID = :OLD_ID";

		Refresh_sqltext = "SELECT LANDSELL.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from LANDSELL where ID = :ID";
	}

	//  Комм. недв. - спрос
   if (AnsiUpperCase(tablename)=="COMMERCPURCH") {
		Select_sqltext ="select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from COMMERCPURCH a";

		Insert_sqltext = "insert into COMMERCPURCH (ID, AGENT, NUM_CARD, DATE_CH, REGION, TYPEHOUSE, \"level\", STUFFWALL, SWBALCONY, "
			"SWPHONE, PRICEFROM, FLAT, SWLOGGIA, ADDINFO, PICS, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, PRICETO, SWRUB, "
			"NAMEQUERY, PURPOSEUSE, OBJAREAFR, OBJAREATO, LEVELFR, LEVELTO, ROOMFR, ROOMTO, "
			"STATE, INTERNET, MINPHONE, MINNODESAN, POWER, HEIGHTGATE, WIDTHGATE, MINPOWER, "
			"RAMPA, TRAIN, ENTER, PUBLIC, PARKING, HOTING, HOTWATER, GAZ, WATERDRAIN, TYPEOWNER, LOW, PRICETYPE"
			") values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :TYPEHOUSE, :\"level\", :STUFFWALL, :SWBALCONY, :SWPHONE, :PRICEFROM, "
			":FLAT, :SWLOGGIA, :ADDINFO, :PICS, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :PRICETO, :SWRUB, "
			":NAMEQUERY, :PURPOSEUSE, :OBJAREAFR, :OBJAREATO, :LEVELFR, :LEVELTO, :ROOMFR, :ROOMTO, "
			":STATE, :INTERNET, :MINPHONE, :MINNODESAN, :POWER, :HEIGHTGATE, :WIDTHGATE, :MINPOWER, "
			":RAMPA, :TRAIN, :ENTER, :PUBLIC, :PARKING, :HOTING, :HOTWATER, :GAZ, :WATERDRAIN, :TYPEOWNER, :LOW, :PRICETYPE"
			")";

		Modify_sqltext = "update COMMERCPURCH set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", STUFFWALL=:STUFFWALL, SWBALCONY=:SWBALCONY, "
			"SWPHONE=:SWPHONE, PRICEFROM=:PRICEFROM, FLAT=:FLAT, SWLOGGIA=:SWLOGGIA, ADDINFO=:ADDINFO, PICS=:PICS, CLIENT=:CLIENT, "
			"AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, PRICETO=:PRICETO, SWRUB=:SWRUB, "
			"NAMEQUERY=:NAMEQUERY, PURPOSEUSE=:PURPOSEUSE, OBJAREAFR=:OBJAREAFR, OBJAREATO=:OBJAREATO, LEVELFR=:LEVELFR, LEVELTO=:LEVELTO, "
			"ROOMFR=:ROOMFR, ROOMTO=:ROOMTO, STATE=:STATE, INTERNET=:INTERNET, MINPHONE=:MINPHONE, MINNODESAN=:MINNODESAN, POWER=:POWER, "
			"HEIGHTGATE=:HEIGHTGATE, WIDTHGATE=:WIDTHGATE, MINPOWER=:MINPOWER, RAMPA=:RAMPA, TRAIN=:TRAIN, ENTER=:ENTER, PUBLIC=:PUBLIC, "
			"PARKING=:PARKING, HOTING=:HOTING, HOTWATER=:HOTWATER, GAZ=:GAZ, WATERDRAIN=:WATERDRAIN, TYPEOWNER=:TYPEOWNER, LOW=:LOW, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND "
			" where ID = :OLD_ID";

		Delete_sqltext = "delete from COMMERCPURCH where ID = :OLD_ID";

		Refresh_sqltext = "select a.*, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text "
		" from GARAGEPURCH a where ID = :ID";
	}

   //  Долевое строительство - предложение
   if (AnsiUpperCase(tablename)=="NEWBUILDSSELL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from NEWBUILDSSELL a";

		Insert_sqltext = "insert into NEWBUILDSSELL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"PLACE, LIFT, READY, GATES, FLATS, WALLS, FLOOR, "
			"PLATE, DOORS, WINDOWS, QUARTER, FIRSTPAY, PRICETYPE"
			") values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":PLACE, :LIFT, :READY, :GATES, :FLATS, :WALLS, :FLOOR, "
			":PLATE, :DOORS, :WINDOWS, :QUARTER, :FIRSTPAY, :PRICETYPE"
			")";

		Modify_sqltext = "update NEWBUILDSSELL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"PLACE=:PLACE, LIFT=:LIFT, READY=:READY, GATES=:GATES, FLATS=:FLATS, WALLS=:WALLS, FLOOR=:FLOOR, "
			"PLATE=:PLATE, DOORS=:DOORS, WINDOWS=:WINDOWS, QUARTER=:QUARTER, FIRSTPAY=:FIRSTPAY, "
			"PRICETYPE=:PRICETYPE, SWSEND=:SWSEND where ID = :OLD_ID";

		Delete_sqltext = "delete from NEWBUILDSSELL where ID = :OLD_ID";

		Refresh_sqltext = "select ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, TYPEHOUSE, \"level\", LEVELS, "
			"STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, "
			"CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, "
			"GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from NEWBUILDSSELL where ID = :ID";
	}

	//  Здания, сооружения - предложение
   if (AnsiUpperCase(tablename)=="COMMERCSELL1") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, price as pricerub_, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from COMMERCSELL1 a";

		Insert_sqltext = "insert into COMMERCSELL1 (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"OBJECT, FORMOFFER, TOWN, AMOUNTLINE, LANDAREA, FORMOWNER, OWNERTO, HOTWATER, "
			"WATERDRAIN, POWER, HOTING, PURPOSE, FIRESIGN, COMMPAY, NAL, BEZNAL, "
			"MIX, RUB, UED, DIRECTPAYBEFOR, DIRECTPAYAFTER, MIXAKKRED, MIXETAP, OTHER, "
			"HOTWATERADD, WATERDRAINADD, POWERADD, HOTINGADD, GAZADD, PURPOSEUSE, BEFOR, "
			"HOTINGI, PARTFROM, PARTTO, BALANSOWNER, INVENTNUM, CODE, YEARENTER, LITER, "
			"HOUSEOWNER, SELLER, SALE, SOURCE, OWNER, OTHERADD, COMMPRICE, SECURETY, KOMMPAY, PRICETYPE"
			") values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":OBJECT, :FORMOFFER, :TOWN, :AMOUNTLINE, :LANDAREA, :FORMOWNER, :OWNERTO, :HOTWATER, "
			":WATERDRAIN, :POWER, :HOTING, :PURPOSE, :FIRESIGN, :COMMPAY, :NAL, :BEZNAL, "
			":MIX, :RUB, :UED, :DIRECTPAYBEFOR, :DIRECTPAYAFTER, :MIXAKKRED, :MIXETAP, :OTHER, "
			":HOTWATERADD, :WATERDRAINADD, :POWERADD, :HOTINGADD, :GAZADD, :PURPOSEUSE, :BEFOR, "
			":HOTINGI, :PARTFROM, :PARTTO, :BALANSOWNER, :INVENTNUM, :CODE, :YEARENTER, :LITER, "
			":HOUSEOWNER, :SELLER, :SALE, :SOURCE, :OWNER, :OTHERADD, :COMMPRICE, :SECURETY, :KOMMPAY, :PRICETYPE"
			")";

		Modify_sqltext = "update COMMERCSELL1 set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"OBJECT=:OBJECT, FORMOFFER=:FORMOFFER, TOWN=:TOWN, AMOUNTLINE=:AMOUNTLINE, LANDAREA=:LANDAREA, "
			"FORMOWNER=:FORMOWNER, OWNERTO=:OWNERTO, HOTWATER=:HOTWATER, "
			"WATERDRAIN=:WATERDRAIN, POWER=:POWER, HOTING=:HOTING, PURPOSE=:PURPOSE, FIRESIGN=:FIRESIGN, "
			"COMMPAY=:COMMPAY, NAL=:NAL, BEZNAL=:BEZNAL, "
			"MIX=:MIX, RUB=:RUB, UED=:UED, DIRECTPAYBEFOR=:DIRECTPAYBEFOR, DIRECTPAYAFTER=:DIRECTPAYAFTER, "
			"MIXAKKRED=:MIXAKKRED, MIXETAP=:MIXETAP, OTHER=:OTHER, "
			"HOTWATERADD=:HOTWATERADD, WATERDRAINADD=:WATERDRAINADD, POWERADD=:POWERADD, HOTINGADD=:HOTINGADD, "
			"GAZADD=:GAZADD, PURPOSEUSE=:PURPOSEUSE, BEFOR=:BEFOR, "
			"HOTINGI=:HOTINGI, PARTFROM=:PARTFROM, PARTTO=:PARTTO, BALANSOWNER=:BALANSOWNER, INVENTNUM=:INVENTNUM, "
			"CODE=:CODE, YEARENTER=:YEARENTER, LITER=:LITER, "
			"HOUSEOWNER=:HOUSEOWNER, SELLER=:SELLER, SALE=:SALE, SOURCE=:SOURCE, OWNER=:OWNER, OTHERADD=:OTHERADD, "
			"COMMPRICE=:COMMPRICE, SECURETY=:SECURETY, KOMMPAY=:KOMMPAY, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND"
			" where ID = :OLD_ID";

		Delete_sqltext = "delete from COMMERCSELL1 where ID = :OLD_ID";

		Refresh_sqltext = "select COMMERCSELL1.*,"
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from COMMERCSELL1 where ID = :ID";
	}

   //  Офисные помещения - предложение
   if (AnsiUpperCase(tablename)=="COMMERCSELL2") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, price as pricerub_, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from COMMERCSELL2 a";

		Insert_sqltext = "insert into COMMERCSELL2 (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"OBJECT, FORMOFFER, TOWN, AMOUNTLINE, LANDAREA, FORMOWNER, OWNERTO, HOTWATER, "
			"WATERDRAIN, POWER, HOTING, PURPOSE, FIRESIGN, COMMPAY, NAL, BEZNAL, "
			"MIX, RUB, UED, DIRECTPAYBEFOR, DIRECTPAYAFTER, MIXAKKRED, MIXETAP, OTHER, "
			"HOTWATERADD, WATERDRAINADD, POWERADD, HOTINGADD, GAZADD, PURPOSEUSE, BEFOR, "
			"HOTINGI, PARTFROM, PARTTO, BALANSOWNER, INVENTNUM, CODE, YEARENTER, LITER, "
			"HOUSEOWNER, SELLER, SALE, SOURCE, OWNER, OTHERADD, COMMPRICE, SECURETY, KOMMPAY, INTERNET, COMMPLACE, ENTER, PRICETYPE"
			") values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":OBJECT, :FORMOFFER, :TOWN, :AMOUNTLINE, :LANDAREA, :FORMOWNER, :OWNERTO, :HOTWATER, "
			":WATERDRAIN, :POWER, :HOTING, :PURPOSE, :FIRESIGN, :COMMPAY, :NAL, :BEZNAL, "
			":MIX, :RUB, :UED, :DIRECTPAYBEFOR, :DIRECTPAYAFTER, :MIXAKKRED, :MIXETAP, :OTHER, "
			":HOTWATERADD, :WATERDRAINADD, :POWERADD, :HOTINGADD, :GAZADD, :PURPOSEUSE, :BEFOR, "
			":HOTINGI, :PARTFROM, :PARTTO, :BALANSOWNER, :INVENTNUM, :CODE, :YEARENTER, :LITER, "
			":HOUSEOWNER, :SELLER, :SALE, :SOURCE, :OWNER, :OTHERADD, :COMMPRICE, :SECURETY, :KOMMPAY, :INTERNET, :COMMPLACE, :ENTER, :PRICETYPE"
			")";

		Modify_sqltext = "update COMMERCSELL2 set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"OBJECT=:OBJECT, FORMOFFER=:FORMOFFER, TOWN=:TOWN, AMOUNTLINE=:AMOUNTLINE, LANDAREA=:LANDAREA, "
			"FORMOWNER=:FORMOWNER, OWNERTO=:OWNERTO, HOTWATER=:HOTWATER, "
			"WATERDRAIN=:WATERDRAIN, POWER=:POWER, HOTING=:HOTING, PURPOSE=:PURPOSE, FIRESIGN=:FIRESIGN, "
			"COMMPAY=:COMMPAY, NAL=:NAL, BEZNAL=:BEZNAL, "
			"MIX=:MIX, RUB=:RUB, UED=:UED, DIRECTPAYBEFOR=:DIRECTPAYBEFOR, DIRECTPAYAFTER=:DIRECTPAYAFTER, "
			"MIXAKKRED=:MIXAKKRED, MIXETAP=:MIXETAP, OTHER=:OTHER, "
			"HOTWATERADD=:HOTWATERADD, WATERDRAINADD=:WATERDRAINADD, POWERADD=:POWERADD, HOTINGADD=:HOTINGADD, "
			"GAZADD=:GAZADD, PURPOSEUSE=:PURPOSEUSE, BEFOR=:BEFOR, "
			"HOTINGI=:HOTINGI, PARTFROM=:PARTFROM, PARTTO=:PARTTO, BALANSOWNER=:BALANSOWNER, INVENTNUM=:INVENTNUM, "
			"CODE=:CODE, YEARENTER=:YEARENTER, LITER=:LITER, "
			"HOUSEOWNER=:HOUSEOWNER, SELLER=:SELLER, SALE=:SALE, SOURCE=:SOURCE, OWNER=:OWNER, OTHERADD=:OTHERADD, "
			"COMMPRICE=:COMMPRICE, SECURETY=:SECURETY, KOMMPAY=:KOMMPAY, INTERNET=:INTERNET, COMMPLACE=:COMMPLACE, ENTER=:ENTER, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND"
			" where ID = :OLD_ID";

		Delete_sqltext = "delete from COMMERCSELL2 where ID = :OLD_ID";

		Refresh_sqltext = "select COMMERCSELL2.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from COMMERCSELL2 where ID = :ID";
	}

	//  Торговля, услуги, общепит - предложение
   if (AnsiUpperCase(tablename)=="COMMERCSELL3") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, price as pricerub_, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from COMMERCSELL3 a";

		Insert_sqltext = "insert into COMMERCSELL3 (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"OBJECT, FORMOFFER, TOWN, AMOUNTLINE, LANDAREA, FORMOWNER, OWNERTO, HOTWATER, "
			"WATERDRAIN, POWER, HOTING, PURPOSE, FIRESIGN, COMMPAY, NAL, BEZNAL, "
			"MIX, RUB, UED, DIRECTPAYBEFOR, DIRECTPAYAFTER, MIXAKKRED, MIXETAP, OTHER, "
			"HOTWATERADD, WATERDRAINADD, POWERADD, HOTINGADD, GAZADD, PURPOSEUSE, BEFOR, "
			"HOTINGI, PARTFROM, PARTTO, BALANSOWNER, INVENTNUM, CODE, YEARENTER, LITER, "
			"HOUSEOWNER, SELLER, SALE, SOURCE, OWNER, OTHERADD, COMMPRICE, SECURETY, KOMMPAY, INTERNET, "
			"COMMPLACE, ENTER, PLACEMENT, PROFILE, EQUIPMENT, PRICETYPE"
			") values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":OBJECT, :FORMOFFER, :TOWN, :AMOUNTLINE, :LANDAREA, :FORMOWNER, :OWNERTO, :HOTWATER, "
			":WATERDRAIN, :POWER, :HOTING, :PURPOSE, :FIRESIGN, :COMMPAY, :NAL, :BEZNAL, "
			":MIX, :RUB, :UED, :DIRECTPAYBEFOR, :DIRECTPAYAFTER, :MIXAKKRED, :MIXETAP, :OTHER, "
			":HOTWATERADD, :WATERDRAINADD, :POWERADD, :HOTINGADD, :GAZADD, :PURPOSEUSE, :BEFOR, "
			":HOTINGI, :PARTFROM, :PARTTO, :BALANSOWNER, :INVENTNUM, :CODE, :YEARENTER, :LITER, "
			":HOUSEOWNER, :SELLER, :SALE, :SOURCE, :OWNER, :OTHERADD, :COMMPRICE, :SECURETY, :KOMMPAY, :INTERNET, "
			":COMMPLACE, :ENTER, :PLACEMENT, :PROFILE, :EQUIPMENT, :PRICETYPE"
			")";

		Modify_sqltext = "update COMMERCSELL3 set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"OBJECT=:OBJECT, FORMOFFER=:FORMOFFER, TOWN=:TOWN, AMOUNTLINE=:AMOUNTLINE, LANDAREA=:LANDAREA, "
			"FORMOWNER=:FORMOWNER, OWNERTO=:OWNERTO, HOTWATER=:HOTWATER, "
			"WATERDRAIN=:WATERDRAIN, POWER=:POWER, HOTING=:HOTING, PURPOSE=:PURPOSE, FIRESIGN=:FIRESIGN, "
			"COMMPAY=:COMMPAY, NAL=:NAL, BEZNAL=:BEZNAL, "
			"MIX=:MIX, RUB=:RUB, UED=:UED, DIRECTPAYBEFOR=:DIRECTPAYBEFOR, DIRECTPAYAFTER=:DIRECTPAYAFTER, "
			"MIXAKKRED=:MIXAKKRED, MIXETAP=:MIXETAP, OTHER=:OTHER, "
			"HOTWATERADD=:HOTWATERADD, WATERDRAINADD=:WATERDRAINADD, POWERADD=:POWERADD, HOTINGADD=:HOTINGADD, "
			"GAZADD=:GAZADD, PURPOSEUSE=:PURPOSEUSE, BEFOR=:BEFOR, "
			"HOTINGI=:HOTINGI, PARTFROM=:PARTFROM, PARTTO=:PARTTO, BALANSOWNER=:BALANSOWNER, INVENTNUM=:INVENTNUM, "
			"CODE=:CODE, YEARENTER=:YEARENTER, LITER=:LITER, "
			"HOUSEOWNER=:HOUSEOWNER, SELLER=:SELLER, SALE=:SALE, SOURCE=:SOURCE, OWNER=:OWNER, OTHERADD=:OTHERADD, "
			"COMMPRICE=:COMMPRICE, SECURETY=:SECURETY, KOMMPAY=:KOMMPAY, INTERNET=:INTERNET, "
			"COMMPLACE=:COMMPLACE, ENTER=:ENTER, PLACEMENT=:PLACEMENT, PROFILE=:PROFILE, EQUIPMENT=:EQUIPMENT, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND"
			" where ID = :OLD_ID";

		Delete_sqltext = "delete from COMMERCSELL3 where ID = :OLD_ID";

		Refresh_sqltext = "select COMMERCSELL3.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, price as pricerub_, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from COMMERCSELL3 where ID = :ID";
	}

   //  Склады и производсвенные помещения
   if (AnsiUpperCase(tablename)=="COMMERCSELL4") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from COMMERCSELL4 a";

		Insert_sqltext = "insert into COMMERCSELL4 (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"OBJECT, FORMOFFER, TOWN, AMOUNTLINE, LANDAREA, FORMOWNER, OWNERTO, HOTWATER, "
			"WATERDRAIN, POWER, HOTING, PURPOSE, FIRESIGN, COMMPAY, NAL, BEZNAL, "
			"MIX, RUB, UED, DIRECTPAYBEFOR, DIRECTPAYAFTER, MIXAKKRED, MIXETAP, OTHER, "
			"HOTWATERADD, WATERDRAINADD, POWERADD, HOTINGADD, GAZADD, PURPOSEUSE, BEFOR, "
			"HOTINGI, PARTFROM, PARTTO, BALANSOWNER, INVENTNUM, CODE, YEARENTER, LITER, "
			"HOUSEOWNER, SELLER, SALE, SOURCE, OWNER, OTHERADD, COMMPRICE, SECURETY, KOMMPAY, INTERNET, "
			"COMMPLACE, ENTER, PLACEMENT, PROFILE, EQUIPMENT, POWERIN, HEIGHT, HOR, VERT, TRAIN, "
			"MEHPOGRUZ, RAMPA, TRANSP, PRICETYPE"
			") values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":OBJECT, :FORMOFFER, :TOWN, :AMOUNTLINE, :LANDAREA, :FORMOWNER, :OWNERTO, :HOTWATER, "
			":WATERDRAIN, :POWER, :HOTING, :PURPOSE, :FIRESIGN, :COMMPAY, :NAL, :BEZNAL, "
			":MIX, :RUB, :UED, :DIRECTPAYBEFOR, :DIRECTPAYAFTER, :MIXAKKRED, :MIXETAP, :OTHER, "
			":HOTWATERADD, :WATERDRAINADD, :POWERADD, :HOTINGADD, :GAZADD, :PURPOSEUSE, :BEFOR, "
			":HOTINGI, :PARTFROM, :PARTTO, :BALANSOWNER, :INVENTNUM, :CODE, :YEARENTER, :LITER, "
			":HOUSEOWNER, :SELLER, :SALE, :SOURCE, :OWNER, :OTHERADD, :COMMPRICE, :SECURETY, :KOMMPAY, :INTERNET, "
			":COMMPLACE, :ENTER, :PLACEMENT, :PROFILE, :EQUIPMENT, :POWERIN, :HEIGHT, :HOR, :VERT, :TRAIN, "
			":MEHPOGRUZ, :RAMPA, :TRANSP, :PRICETYPE"
			")";

		Modify_sqltext = "update COMMERCSELL4 set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"OBJECT=:OBJECT, FORMOFFER=:FORMOFFER, TOWN=:TOWN, AMOUNTLINE=:AMOUNTLINE, LANDAREA=:LANDAREA, "
			"FORMOWNER=:FORMOWNER, OWNERTO=:OWNERTO, HOTWATER=:HOTWATER, "
			"WATERDRAIN=:WATERDRAIN, POWER=:POWER, HOTING=:HOTING, PURPOSE=:PURPOSE, FIRESIGN=:FIRESIGN, "
			"COMMPAY=:COMMPAY, NAL=:NAL, BEZNAL=:BEZNAL, "
			"MIX=:MIX, RUB=:RUB, UED=:UED, DIRECTPAYBEFOR=:DIRECTPAYBEFOR, DIRECTPAYAFTER=:DIRECTPAYAFTER, "
			"MIXAKKRED=:MIXAKKRED, MIXETAP=:MIXETAP, OTHER=:OTHER, "
			"HOTWATERADD=:HOTWATERADD, WATERDRAINADD=:WATERDRAINADD, POWERADD=:POWERADD, HOTINGADD=:HOTINGADD, "
			"GAZADD=:GAZADD, PURPOSEUSE=:PURPOSEUSE, BEFOR=:BEFOR, "
			"HOTINGI=:HOTINGI, PARTFROM=:PARTFROM, PARTTO=:PARTTO, BALANSOWNER=:BALANSOWNER, INVENTNUM=:INVENTNUM, "
			"CODE=:CODE, YEARENTER=:YEARENTER, LITER=:LITER, "
			"HOUSEOWNER=:HOUSEOWNER, SELLER=:SELLER, SALE=:SALE, SOURCE=:SOURCE, OWNER=:OWNER, OTHERADD=:OTHERADD, "
			"COMMPRICE=:COMMPRICE, SECURETY=:SECURETY, KOMMPAY=:KOMMPAY, INTERNET=:INTERNET, "
			"COMMPLACE=:COMMPLACE, ENTER=:ENTER, PLACEMENT=:PLACEMENT, PROFILE=:PROFILE, EQUIPMENT=:EQUIPMENT, "
			"POWERIN=:POWERIN, HEIGHT=:HEIGHT, HOR=:HOR, VERT=:VERT, TRAIN=:TRAIN, "
			"MEHPOGRUZ=:MEHPOGRUZ, RAMPA=:RAMPA, TRANSP=:TRANSP, "
			"PRICETYPE=:PRICETYPE, SWSEND=:SWSEND where ID = :OLD_ID";

		Delete_sqltext = "delete from COMMERCSELL4 where ID = :OLD_ID";

		Refresh_sqltext = "select ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, TYPEHOUSE, \"level\", LEVELS, "
			"STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, "
			"CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, "
			"GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from COMMERCSELL4 where ID = :ID";
	}

   //  Карточка продажи готового бизнеса
   if (AnsiUpperCase(tablename)=="BUSINESSSELL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from BUSINESSSELL a";

		Insert_sqltext = "insert into BUSINESSSELL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"BUISNESSNAME, TYPESELL, FORMOWNER, DOING, PARTPAY, CAUSESELL, "
			"OWNKAPITAL, ACTIVPRICE, ZAEMKAPITAL, DEBDOLG, KREDDOLG, "
			"BUISNESSOLD, OKUPAEMOST, AMOUNTPERS, ZP, PLACE, LAND, "
			"OWNERLAND, PLACEMENT, NEMATAKTIV, EQUIPMENT, SPECHAR, "
			"PERSPECTIV, CONTRACTNUM, BEGCONT, ENDCONT, BANKSCHET, FINANCE, PRICETYPE"
			") values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":BUISNESSNAME, :TYPESELL, :FORMOWNER, :DOING, :PARTPAY, :CAUSESELL, "
			":OWNKAPITAL, :ACTIVPRICE, :ZAEMKAPITAL, :DEBDOLG, :KREDDOLG, "
			":BUISNESSOLD, :OKUPAEMOST, :AMOUNTPERS, :ZP, :PLACE, :LAND, "
			":OWNERLAND, :PLACEMENT, :NEMATAKTIV, :EQUIPMENT, :SPECHAR, "
			":PERSPECTIV, :CONTRACTNUM, :BEGCONT, :ENDCONT, :BANKSCHET, :FINANCE, :PRICETYPE"
			")";

		Modify_sqltext = "update BUSINESSSELL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"BUISNESSNAME=:BUISNESSNAME, TYPESELL=:TYPESELL, FORMOWNER=:FORMOWNER, DOING=:DOING, "
			"PARTPAY=:PARTPAY, CAUSESELL=:CAUSESELL, OWNKAPITAL=:OWNKAPITAL, ACTIVPRICE=:ACTIVPRICE, "
			"ZAEMKAPITAL=:ZAEMKAPITAL, DEBDOLG=:DEBDOLG, KREDDOLG=:KREDDOLG, BUISNESSOLD=:BUISNESSOLD, "
			"OKUPAEMOST=:OKUPAEMOST, AMOUNTPERS=:AMOUNTPERS, ZP=:ZP, PLACE=:PLACE, LAND=:LAND, "
			"OWNERLAND=:OWNERLAND, PLACEMENT=:PLACEMENT, NEMATAKTIV=:NEMATAKTIV, EQUIPMENT=:EQUIPMENT, "
			"SPECHAR=:SPECHAR, PERSPECTIV=:PERSPECTIV, CONTRACTNUM=:CONTRACTNUM, BEGCONT=:BEGCONT, "
			"ENDCONT=:ENDCONT, BANKSCHET=:BANKSCHET, FINANCE=:FINANCE, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND "
			"where ID = :OLD_ID";

		Delete_sqltext = "delete from BUSINESSSELL where ID = :OLD_ID";

		Refresh_sqltext = "select BUSINESSSELL.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from BUSINESSSELL where ID = :ID";
	}

   //  Зарубежная недвижимость
   if (AnsiUpperCase(tablename)=="ABROADSELL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from ABROADSELL a";

		Insert_sqltext = "insert into ABROADSELL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"\"real\", FORMOFFER, COUNTRY, TOWN, FORMOWNER, ADDINFOBUILD, "
			"LANDAREA, ADDINFOLAND, PRICETYPE"
			") values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":\"real\", :FORMOFFER, :COUNTRY, :TOWN, :FORMOWNER, :ADDINFOBUILD, "
			":LANDAREA, :ADDINFOLAND, :PRICETYPE"
			")";

		Modify_sqltext = "update ABROADSELL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"\"real\"=:\"real\", FORMOFFER=:FORMOFFER, COUNTRY=:COUNTRY, TOWN=:TOWN, "
			"FORMOWNER=:FORMOWNER, ADDINFOBUILD=:ADDINFOBUILD, LANDAREA=:LANDAREA, "
			"ADDINFOLAND=:ADDINFOLAND, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND"
			" where ID = :OLD_ID";

		Delete_sqltext = "delete from ABROADSELL where ID = :OLD_ID";

		Refresh_sqltext = "select ABROADSELL.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from ABROADSELL where ID = :ID";
	}

   //  Коммерческая (объединенная)
   if (AnsiUpperCase(tablename)=="COMMERCSELLALL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from COMMERCSELLALL a";

		Insert_sqltext = "insert into COMMERCSELLALL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"OBJECT, FORMOFFER, TOWN, AMOUNTLINE, LANDAREA, FORMOWNER, OWNERTO, HOTWATER, "
			"WATERDRAIN, POWER, HOTING, PURPOSE, FIRESIGN, COMMPAY, NAL, BEZNAL, "
			"MIX, RUB, UED, DIRECTPAYBEFOR, DIRECTPAYAFTER, MIXAKKRED, MIXETAP, OTHER, "
			"HOTWATERADD, WATERDRAINADD, POWERADD, HOTINGADD, GAZADD, PURPOSEUSE, BEFOR, "
			"HOTINGI, PARTFROM, PARTTO, BALANSOWNER, INVENTNUM, CODE, YEARENTER, LITER, "
			"HOUSEOWNER, SELLER, SALE, SOURCE, OWNER, OTHERADD, COMMPRICE, SECURETY, KOMMPAY, PRICETYPE"
			") values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, "
			":OBJECT, :FORMOFFER, :TOWN, :AMOUNTLINE, :LANDAREA, :FORMOWNER, :OWNERTO, :HOTWATER, "
			":WATERDRAIN, :POWER, :HOTING, :PURPOSE, :FIRESIGN, :COMMPAY, :NAL, :BEZNAL, "
			":MIX, :RUB, :UED, :DIRECTPAYBEFOR, :DIRECTPAYAFTER, :MIXAKKRED, :MIXETAP, :OTHER, "
			":HOTWATERADD, :WATERDRAINADD, :POWERADD, :HOTINGADD, :GAZADD, :PURPOSEUSE, :BEFOR, "
			":HOTINGI, :PARTFROM, :PARTTO, :BALANSOWNER, :INVENTNUM, :CODE, :YEARENTER, :LITER, "
			":HOUSEOWNER, :SELLER, :SALE, :SOURCE, :OWNER, :OTHERADD, :COMMPRICE, :SECURETY, :KOMMPAY, :PRICETYPE"
			")";

		Modify_sqltext = "update COMMERCSELLALL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, "
			"OBJECT=:OBJECT, FORMOFFER=:FORMOFFER, TOWN=:TOWN, AMOUNTLINE=:AMOUNTLINE, LANDAREA=:LANDAREA, "
			"FORMOWNER=:FORMOWNER, OWNERTO=:OWNERTO, HOTWATER=:HOTWATER, "
			"WATERDRAIN=:WATERDRAIN, POWER=:POWER, HOTING=:HOTING, PURPOSE=:PURPOSE, FIRESIGN=:FIRESIGN, "
			"COMMPAY=:COMMPAY, NAL=:NAL, BEZNAL=:BEZNAL, "
			"MIX=:MIX, RUB=:RUB, UED=:UED, DIRECTPAYBEFOR=:DIRECTPAYBEFOR, DIRECTPAYAFTER=:DIRECTPAYAFTER, "
			"MIXAKKRED=:MIXAKKRED, MIXETAP=:MIXETAP, OTHER=:OTHER, "
			"HOTWATERADD=:HOTWATERADD, WATERDRAINADD=:WATERDRAINADD, POWERADD=:POWERADD, HOTINGADD=:HOTINGADD, "
			"GAZADD=:GAZADD, PURPOSEUSE=:PURPOSEUSE, BEFOR=:BEFOR, "
			"HOTINGI=:HOTINGI, PARTFROM=:PARTFROM, PARTTO=:PARTTO, BALANSOWNER=:BALANSOWNER, INVENTNUM=:INVENTNUM, "
			"CODE=:CODE, YEARENTER=:YEARENTER, LITER=:LITER, "
			"HOUSEOWNER=:HOUSEOWNER, SELLER=:SELLER, SALE=:SALE, SOURCE=:SOURCE, OWNER=:OWNER, OTHERADD=:OTHERADD, "
			"COMMPRICE=:COMMPRICE, SECURETY=:SECURETY, KOMMPAY=:KOMMPAY,"
			"PRICETYPE=:PRICETYPE, SWSEND=:SWSEND where ID = :OLD_ID";

		Delete_sqltext = "delete from COMMERCSELLALL where ID = :OLD_ID";

		Refresh_sqltext = "select COMMERCSELLALL.*, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from COMMERCSELLALL where ID = :ID";
	}

   //  Аренда (объединенная)
   if (AnsiUpperCase(tablename)=="ARENDSELLALL") {
		Select_sqltext ="select a.*,(select shortname from items where razdel=8 and code=a.region) as region_text,"
			"(select shortname from items where razdel=10 and code=a.mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=a.typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=a.nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=a.swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=a.variant) as variant_text, "
			"(select mainphone from people where id=a.idagent) as mainphone_text, "
			"(select advertname from people where id=a.idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=a.stuffwall) as stuffwall_text "
			" from ARENDSELLALL a";

		Insert_sqltext = "insert into ARENDSELLALL (ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, "
			"TYPEHOUSE, \"level\", LEVELS, STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, "
			"PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, "
			"KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, "
			"SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, PRICETYPE) values ("
			":ID, :AGENT, :NUM_CARD, :DATE_CH, :REGION, :MREGION, :STREET, :ROOMS, :IROOMS, :TYPEHOUSE, :\"level\", :LEVELS, "
			":STUFFWALL, :TOTALAREA, :LIVEAREA, :KITCHENAREA, :NODESAN, :BALCONY, :SWPHONE, :VARIANT, :PRICE, :\"CHECK\", "
			":CRSTREET, :CORPUS, :HOUSE, :FLAT, :CONTRACT, :SOURCED, :VARIANTD, :MORGAGE, :PART, :YEARBUILD, :SECURITY, :KONSERG, "
			":OWNEX, :TRASH, :GAZ, :PARKING, :NEWBUILD, :DESIGN, :STATE, :LOGGIA, :GLASSBALC, :GLASSPACK, :ADDINFO, :VARSWAP, "
			":DOPLATA, :SWAPINFO, :PICS, :COMPSTR, :CLIENT, :AGENTINFO, :REKLINFO, :IDAGENT, :DATE_ENTER, :NEIGHBORS, :PRICETYPE)";

		Modify_sqltext = "update ARENDSELLALL set ID=:ID, AGENT=:AGENT, NUM_CARD=:NUM_CARD, DATE_CH=:DATE_CH, REGION=:REGION, "
			"MREGION=:MREGION, STREET=:STREET, ROOMS=:ROOMS, IROOMS=:ROOMS, TYPEHOUSE=:TYPEHOUSE, \"level\"=:\"level\", LEVELS=:LEVELS, "
			"STUFFWALL=:STUFFWALL, TOTALAREA=:TOTALAREA, LIVEAREA=:LIVEAREA, KITCHENAREA=:KITCHENAREA, NODESAN=:NODESAN, BALCONY=:BALCONY, "
			"SWPHONE=:SWPHONE, VARIANT=:VARIANT, PRICE=:PRICE, \"CHECK\"=:\"CHECK\", CRSTREET=:CRSTREET, CORPUS=:CORPUS, HOUSE=:HOUSE, "
			"FLAT=:FLAT, CONTRACT=:CONTRACT, SOURCED=:SOURCED, VARIANTD=:VARIANTD, MORGAGE=:MORGAGE, PART=:PART, YEARBUILD=:YEARBUILD, "
			"SECURITY=:SECURITY, KONSERG=:KONSERG, OWNEX=:OWNEX, TRASH=:TRASH, GAZ=:GAZ, PARKING=:PARKING, NEWBUILD=:NEWBUILD, "
			"DESIGN=:DESIGN, STATE=:STATE, LOGGIA=:LOGGIA, GLASSBALC=:GLASSBALC, GLASSPACK=:GLASSPACK, ADDINFO=:ADDINFO, VARSWAP=:VARSWAP, "
			"DOPLATA=:DOPLATA, SWAPINFO=:SWAPINFO, PICS=:PICS, COMPSTR=:COMPSTR, CLIENT=:CLIENT, AGENTINFO=:AGENTINFO, REKLINFO=:REKLINFO, "
			"IDAGENT=:IDAGENT, DATE_ENTER=:DATE_ENTER, NEIGHBORS=:NEIGHBORS, PRICETYPE=:PRICETYPE, SWSEND=:SWSEND where ID = :OLD_ID";

		Delete_sqltext = "delete from ARENDSELLALL where ID = :OLD_ID";

		Refresh_sqltext = "select ID, AGENT, NUM_CARD, DATE_CH, REGION, MREGION, STREET, ROOMS, IROOMS, TYPEHOUSE, \"level\", LEVELS, "
			"STUFFWALL, TOTALAREA, LIVEAREA, KITCHENAREA, NODESAN, BALCONY, SWPHONE, VARIANT, PRICE, \"CHECK\", CRSTREET, CORPUS, HOUSE, FLAT, "
			"CONTRACT, SOURCED, VARIANTD, MORGAGE, PART, YEARBUILD, SECURITY, KONSERG, OWNEX, TRASH, GAZ, PARKING, NEWBUILD, DESIGN, STATE, LOGGIA, "
			"GLASSBALC, GLASSPACK, ADDINFO, VARSWAP, DOPLATA, SWAPINFO, PICS, COMPSTR, CLIENT, AGENTINFO, REKLINFO, IDAGENT, DATE_ENTER, NEIGHBORS, "
			"(select shortname from items where razdel=8 and code=region) as region_text, "
			"(select shortname from items where razdel=10 and code=mregion) as mregion_text, "
			"(select shortname from items where razdel=9 and code=typehouse) as typehouse_text, "
			"(select shortname from items where razdel=5 and code=nodesan) as nodesan_text, "
			"(select shortname from items where razdel=7 and code=swphone) as swphone_text, "
			"(select shortname from items where razdel=3 and code=variant) as variant_text, "
			"(select mainphone from people where id=idagent) as mainphone_text, "
			"(select advertname from people where id=idagent) as advertname_text, "
			"case when setmark=1 then 'гал' else '   ' end as setmark_text, price as pricerub, "
			"(select shortname from items where razdel=6 and code=stuffwall) as stuffwall_text "
			"from ARENDSELLALL where ID = :ID";
	}


	//ShowMessage(FilterSQL);
	//ClientDataSet1->Active=false;

	/*MainTable->Active = false;
	MainTable->Filtered = false;

	MainTable->SelectSQL->Clear();
	MainTable->SelectSQL->Append("select count(id) as reccount from apartsell "+FilterSQL);
	MainTable->Active = TRUE;
	Reccount_Label->Caption = "Записей - "+MainTable->FieldByName("reccount")->AsString;
	//ShowMessage("Метка1");
	MainTable->Active = false;
	MainTable->SelectSQL->Clear();
	MainTable->SelectSQL->Append(Select_sqltext);
	MainTable->InsertSQL->Clear();
	MainTable->InsertSQL->Append(Insert_sqltext);
	MainTable->ModifySQL->Clear();
	MainTable->ModifySQL->Append(Modify_sqltext);
	MainTable->DeleteSQL->Clear();
	MainTable->DeleteSQL->Append(Delete_sqltext);
	MainTable->RefreshSQL->Clear();
	MainTable->RefreshSQL->Append(Refresh_sqltext);
	MainTable->Filtered = true;
	MainTable->Active = TRUE; */
	//MainTable->Active = false;
	//ShowMessage(FilterSQL);
	//ShowMessage(Select_sqltext);

	// Установка фильтра
	if (!strFilterAdd.IsEmpty()) {
		FilterSQL = FilterSQL + " and ";
	}
	FilterSQL = FilterSQL + strFilterAdd;
	if (!strApartFilter.IsEmpty()) {
		FilterSQL = FilterSQL + " and ";
	}
	FilterSQL = FilterSQL + strApartFilter;
	if (!FilterSQL.IsEmpty()) {
		Select_sqltext = Select_sqltext + FilterSQL;
	}

	MainTable->Close();
	//MainTable->Active = false;
	IBXDataDriverEh1->SelectSQL->Clear();
	//IBXDataDriverEh1->SelectSQL->Append("select count(id) as reccount from apartsell "+FilterSQL);
	//ShowMessage("select count(id) as reccount from "+AnsiUpperCase(tablename)+" "+FilterSQL);
	IBXDataDriverEh1->SelectSQL->Append("select count(id) as reccount from "+AnsiUpperCase(tablename)+" "+FilterSQL);
	MainTable->Open();
	//MainTable->Active = TRUE;
	//MainTable->Active = TRUE;
	Reccount_Label->Caption = "Записей - "+MainTable->FieldByName("reccount")->AsString;
	if (MainTable->FieldByName("reccount")->AsInteger>0) {
		 TabPricelist_Datasource_Main->DataSet=MainTable;
	} else {
        TabPricelist_Datasource_Main->DataSet=NULL;
	}
	SetThems(this);

	//ShowMessage("Метка1");
	//if (!MainTable->Active) {
	   //MainTable->Active = false;

	MainTable->Close();
	   //MainTable->Filtered = false;
	IBXDataDriverEh1->SelectSQL->Clear();
	//ShowMessage(Select_sqltext);
	IBXDataDriverEh1->SelectSQL->Append(Select_sqltext);
	IBXDataDriverEh1->InsertSQL->Clear();
	IBXDataDriverEh1->InsertSQL->Append(Insert_sqltext);
	IBXDataDriverEh1->UpdateSQL->Clear();
	IBXDataDriverEh1->UpdateSQL->Append(Modify_sqltext);
	IBXDataDriverEh1->DeleteSQL->Clear();
	IBXDataDriverEh1->DeleteSQL->Append(Delete_sqltext);
	IBXDataDriverEh1->GetrecSQL->Clear();
	IBXDataDriverEh1->GetrecSQL->Append(Refresh_sqltext);
	//MainTable->Filtered = true;
	//MainTable->FetchAllOnOpen = true;
	MainTable->Open();
	//MainTable->Active = TRUE;
		//ShowMessage("MainTable->Active");
	//}

	//ShowMessage(MainTable->RecordCount);
	//MainTable->FetchRecords(100);
	//MainTable->IsSequenced();
	//MainTable->se
	//MainTable->FetchAllOnOpen = true;
	//MainTable->f


	//MemTableEh1-
	//ClientDataSet1->Active=true;
	//ShowMessage(Select_sqltext);
	//ShowMessage("Метка2");

	FilterMain = FilterSQL;
	//vMainTable->SQL->Clear();
	//vMainTable->SQL->Add("CREATE OR ALTER VIEW VMAINTABLE AS "+Select_sqltext);
	//vMainTable->SQL->Add("CREATE OR ALTER VIEW VMAINTABLE AS select guid, num_card, region, rooms from apartsell "+FilterSQL);
	//vMainTable->SQL->Add("CREATE OR ALTER VIEW VMAINTABLE (AGENT, STREET) AS  select agent, street from apartsell");
	//vMainTable->SQL->Add("CREATE OR ALTER VIEW VMAINTABLE (AGENT, STREET) AS  select agent, street from apartsell");
	//vMainTable->ExecSQL();
	//vMainTable->
	//MainTransaction->CommitRetaining();
	MainTable->EnableControls();

	/*TableFilter->First();
	while (!TableFilter->Eof){
		TableFilter->Delete();
	}
	MainTable->First();
	while (!MainTable->Eof){
		TableFilter->Append();
		TableFilter->FieldByName("UUID")->AsString=MainTable->FieldByName("GUID")->AsString;
		MainTable->Next();
	}
	//Фиксация изменений
	TableFilter->CheckBrowseMode();
	//Записать изменения в базу данных
	MainTransaction->CommitRetaining();
	MainTable->First();*/

	//MainTable->Last();
	//MainTable->First();
	//MainTable->
	//Reccount_Label->Caption = "Записей - "+(UnicodeString)MainTable->RecordCount;
	//MainTable->FetchAll();
	//MainTable->Edit();
	Refresh_Fieldsdef(this);
	FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Refresh_Fieldsdef(TObject *Sender)
{
	// Кнопка "Предложение"
	//ShowMessage("Метка3");
	int swview = 3;
	// Агентский вид
	if (Agent_Panel->BevelOuter == bvLowered) {
		swview = 1;
	}
	// Клиентский вид
	if (Client_Panel->BevelOuter == bvLowered) {
		swview = 2;
	}

	Table_Tabledef->RecNo = Razdel_ComboBox->ItemIndex+1;
	UnicodeString tablename = Table_Tabledef->FieldByName("TABLENAME")->AsString;

	Table_Fieldsdef->Active=false;
	Table_Fieldsdef->Filtered = false;
	Table_Fieldsdef->SelectSQL->Clear();
	Table_Fieldsdef->SelectSQL->Append("select * from fieldsdef where tableid="+Table_Tabledef->FieldByName("ID")->AsString+" order by tableid,ord");
	//Table_Fieldsdef->Filter = "TABLEID="+Table_Tabledef->FieldByName("ID")->AsString;
	Table_Fieldsdef->Filtered = true;
	Table_Fieldsdef->Active=true;
	Table_Fieldsdef->FetchAll();
	//Цикл по всем записям таблицы
	 Table_Fieldsdef->First();
	 while(!Table_Fieldsdef->Eof){
		Table_Fieldsdef->Edit();
		//ShowMessage(IniFields->ReadString(tablename+"_check_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"0"));
		if (IniFields->ReadString(tablename+"_check_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"0")==1)
			Table_Fieldsdef->FieldByName("MANCHECK")->AsInteger=1; else Table_Fieldsdef->FieldByName("MANCHECK")->AsInteger=0;
		Table_Fieldsdef->FieldByName("MANWIDTH")->AsString =
			IniFields->ReadString(tablename+"_width_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"2");
		Table_Fieldsdef->Next();
	 };
	 Table_Fieldsdef->First();
	 //ShowMessage("Метка4");
}

//---------------------------------------------------------------------------

void __fastcall TMainForm::RefreshGrid(TObject *Sender)
{
	// Процедура обновления полей главной таблицы
	//DBMainGrid->Enabled = false;
	//LockWindowUpdate(DBMainGrid->Handle);
	TColumnEh *Column;
	//Column->Width = Column->Width;
	int colwidth = 0;
	int scrollw = 0;
		DBMainGrid->Columns->Items[0]->FieldName = "PICS";
		DBMainGrid->Columns->Items[0]->Title->Caption = "Pic";
		DBMainGrid->Columns->Items[0]->Title->Color = clInfoBk;
		DBMainGrid->Columns->Items[0]->Title->Font->Style = TFontStyles()<<fsBold;
		DBMainGrid->Columns->Items[0]->Width = 24;

		DBMainGrid->Columns->Items[1]->FieldName = "CHECK";
		DBMainGrid->Columns->Items[1]->Title->Caption = "";
		DBMainGrid->Columns->Items[1]->Title->Color = clInfoBk;
		DBMainGrid->Columns->Items[1]->Title->Font->Style = TFontStyles()<<fsBold;
		DBMainGrid->Columns->Items[1]->Width = 24;

		colwidth = 48;
		scrollw = DBMainGrid->ClientWidth;
		Table_Fieldsdef->First();

		int numcol = 1;
		while (!Table_Fieldsdef->Eof){
			if (Table_Fieldsdef->FieldByName("MANCHECK")->AsInteger==1 && colwidth<scrollw) {
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICERUB") {
					if (!Priceru_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICEUE") {
					if (!Priceye_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICERUB_") {
					if (!Priceru_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICEUE_") {
					if (!Priceye_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				numcol = numcol + 1;
				if (numcol>=DBMainGrid->Columns->Count) {
					Column = DBMainGrid->Columns->Add();
				}
				DBMainGrid->Columns->Items[numcol]->FieldName = Table_Fieldsdef->FieldByName("FIELDNAME")->AsString;
				DBMainGrid->Columns->Items[numcol]->Title->Caption = Table_Fieldsdef->FieldByName("FCAPTION")->AsString;
				DBMainGrid->Columns->Items[numcol]->Title->Color = clInfoBk;
				DBMainGrid->Columns->Items[numcol]->Title->Font->Style = TFontStyles()<<fsBold;
				DBMainGrid->Columns->Items[numcol]->Width = scrollw/100*Table_Fieldsdef->FieldByName("MANWIDTH")->AsInteger;
				DBMainGrid->Columns->Items[numcol]->Visible = true;
				DBMainGrid->Columns->Items[numcol]->Title->Hint = Table_Fieldsdef->FieldByName("CAPTFULL")->AsString;
				if (scrollw<850 && (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString.UpperCase()=="TOTALAREA" ||
						Table_Fieldsdef->FieldByName("FIELDNAME")->AsString.UpperCase()=="LIVEAREA" ||
						Table_Fieldsdef->FieldByName("FIELDNAME")->AsString.UpperCase()=="KITCHENAREA")) {
					//DBMainGrid->Columns->Items[numcol]->Width = 4;
					DBMainGrid->Columns->Items[numcol]->Width = scrollw/100*4;
				}

				colwidth = colwidth + DBMainGrid->Columns->Items[numcol]->Width+1;
			}
			Table_Fieldsdef->Next();
		}
		colwidth = colwidth - DBMainGrid->Columns->Items[numcol]->Width-1;

		DBMainGrid->Columns->Items[numcol]->Width = scrollw-colwidth-14;
		// ДСП вид
		if (DSP_Panel->BevelOuter == bvLowered) {
			DBMainGrid->Columns->Items[numcol]->Width = DBMainGrid->Columns->Items[numcol]->Width -32;
			numcol = numcol + 1;
			if (numcol>=DBMainGrid->Columns->Count) {
				Column = DBMainGrid->Columns->Add();
			}
			DBMainGrid->Columns->Items[numcol]->FieldName = "SETMARK_TEXT";
			DBMainGrid->Columns->Items[numcol]->Title->Caption = "НРН";
			DBMainGrid->Columns->Items[numcol]->Title->Color = clInfoBk;
			DBMainGrid->Columns->Items[numcol]->Title->Font->Style = TFontStyles()<<fsBold;
			DBMainGrid->Columns->Items[numcol]->Width = 31;
			DBMainGrid->Columns->Items[numcol]->Visible = true;
		}
		if (numcol<DBMainGrid->Columns->Count) {
			numcol = numcol + 1;
			for (int i = numcol; i < DBMainGrid->Columns->Count; i++) {
				//ShowMessage(DBMainGrid->Columns->Items[i]->Width);
				if (DBMainGrid->Columns->Items[i]->Width != 0) {
					DBMainGrid->Columns->Items[i]->Width = 0;
					//ShowMessage("не 0");
				}
				//if (DBMainGrid->Columns->Items[i]->Visible) {
					//ShowMessage("true");
					//DBMainGrid->Columns->Items[i]->Visible = false;
				//}
				//DBMainGrid->Columns->Items[i]->Width = 0;
			}
		}
	/*TColumnEh *Column;
	int colwidth = 0;
	int scrollw = 0;
		DBMainGrid->Columns->Items[0]->FieldName = "CHECK";
		DBMainGrid->Columns->Items[0]->Title->Caption = "";
		DBMainGrid->Columns->Items[0]->Title->Color = clInfoBk;
		DBMainGrid->Columns->Items[0]->Title->Font->Style = TFontStyles()<<fsBold;
		DBMainGrid->Columns->Items[0]->Width = 24;

		DBMainGrid->Columns->Items[1]->FieldName = "PICS";
		DBMainGrid->Columns->Items[1]->Title->Caption = "Pic";
		DBMainGrid->Columns->Items[1]->Title->Color = clInfoBk;
		DBMainGrid->Columns->Items[1]->Title->Font->Style = TFontStyles()<<fsBold;
		DBMainGrid->Columns->Items[1]->Width = 24;

		colwidth = 48;
		scrollw = DBMainGrid->ClientWidth;
		Table_Fieldsdef->First();

		int numcol = 1;
		while (!Table_Fieldsdef->Eof){
			if (Table_Fieldsdef->FieldByName("MANCHECK")->AsInteger==1 && colwidth<scrollw) {
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICERUB") {
					if (!Priceru_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICEUE") {
					if (!Priceye_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICERUB_") {
					if (!Priceru_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICEUE_") {
					if (!Priceye_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				numcol = numcol + 1;
				if (numcol>=DBMainGrid->Columns->Count) {
					Column = DBMainGrid->Columns->Add();
				}
				DBMainGrid->Columns->Items[numcol]->FieldName = Table_Fieldsdef->FieldByName("FIELDNAME")->AsString;
				DBMainGrid->Columns->Items[numcol]->Title->Caption = Table_Fieldsdef->FieldByName("FCAPTION")->AsString;
				DBMainGrid->Columns->Items[numcol]->Title->Color = clInfoBk;
				DBMainGrid->Columns->Items[numcol]->Title->Font->Style = TFontStyles()<<fsBold;
				DBMainGrid->Columns->Items[numcol]->Width = scrollw/100*Table_Fieldsdef->FieldByName("MANWIDTH")->AsInteger;
				DBMainGrid->Columns->Items[numcol]->Visible = true;
				colwidth = colwidth + DBMainGrid->Columns->Items[numcol]->Width+1;
			}
			Table_Fieldsdef->Next();
		}
		colwidth = colwidth - DBMainGrid->Columns->Items[numcol]->Width-1;

		DBMainGrid->Columns->Items[numcol]->Width = scrollw-colwidth-14;
		// ДСП вид
		if (DSP_Panel->BevelOuter == bvLowered) {
			DBMainGrid->Columns->Items[numcol]->Width = DBMainGrid->Columns->Items[numcol]->Width -32;
			numcol = numcol + 1;
			if (numcol>=DBMainGrid->Columns->Count) {
				Column = DBMainGrid->Columns->Add();
			}
			DBMainGrid->Columns->Items[numcol]->FieldName = "SETMARK_TEXT";
			DBMainGrid->Columns->Items[numcol]->Title->Caption = "НРН";
			DBMainGrid->Columns->Items[numcol]->Title->Color = clInfoBk;
			DBMainGrid->Columns->Items[numcol]->Title->Font->Style = TFontStyles()<<fsBold;
			DBMainGrid->Columns->Items[numcol]->Width = 31;
			DBMainGrid->Columns->Items[numcol]->Visible = true;
		}
		//DBMainGrid->Enabled
		//ShowMessage(DBMainGrid->Columns->Count);
		//ShowMessage(numcol);
		if (numcol<DBMainGrid->Columns->Count) {
			numcol = numcol + 1;
			for (int i = numcol; i < DBMainGrid->Columns->Count; i++) {
				//ShowMessage(DBMainGrid->Columns->Items[i]->Width);
				if (DBMainGrid->Columns->Items[i]->Width != 0) {
					DBMainGrid->Columns->Items[i]->Width = 0;
					//ShowMessage("не 0");
				}
				//if (DBMainGrid->Columns->Items[i]->Visible) {
					//ShowMessage("true");
					//DBMainGrid->Columns->Items[i]->Visible = false;
				//}
				//DBMainGrid->Columns->Items[i]->Width = 0;
			}
		}
		//DBMainGrid->Enabled = true;
		//LockWindowUpdate(NULL);
		//MainTable->tn
		//DBMainGrid->Columns->Items[2]->Title->Caption;
		//DBMainGrid->Columns->Count;
	/*if (needfieldsref==1 || needfieldsref==0) {
		DBMainGrid->Columns->Clear();

		Column = DBMainGrid->Columns->Add();
		Column->FieldName = "PICS";
		Column->Title->Caption = "Pic";
		Column->Title->Color = clInfoBk;
		Column->Title->Font->Style = TFontStyles()<<fsBold;
		Column->Width = 24;

		Column = DBMainGrid->Columns->Add();
		Column->FieldName = "CHECK";
		Column->Title->Caption = "";
		Column->Title->Color = clInfoBk;
		Column->Title->Font->Style = TFontStyles()<<fsBold;
		Column->Width = 24;

		colwidth = 48;
		scrollw = DBMainGrid->ClientWidth;
		Table_Fieldsdef->First();
		//ShowMessage(DBMainGrid->ClientWidth);
		while (!Table_Fieldsdef->Eof){
			//ShowMessage(colwidth);
			if (Table_Fieldsdef->FieldByName("MANCHECK")->AsInteger==1 && colwidth<scrollw) {
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICERUB") {
					if (!Priceru_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICEUE") {
					if (!Priceye_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICERUB_") {
					if (!Priceru_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				if (Table_Fieldsdef->FieldByName("FIELDNAME")->AsString=="PRICEUE_") {
					if (!Priceye_RadioButton->Checked) {
						Table_Fieldsdef->Next();
						continue;
					}
				}
				Column = DBMainGrid->Columns->Add();
				Column->FieldName =  Table_Fieldsdef->FieldByName("FIELDNAME")->AsString;
				Column->Title->Caption = Table_Fieldsdef->FieldByName("FCAPTION")->AsString;
				Column->Title->Color = clInfoBk;
				Column->Title->Font->Style = TFontStyles()<<fsBold;
				Column->Width = scrollw/100*Table_Fieldsdef->FieldByName("MANWIDTH")->AsInteger;
				colwidth = colwidth + Column->Width+1;
			}
			Table_Fieldsdef->Next();
		}
		colwidth = colwidth - Column->Width-1;

		Column->Width = scrollw-colwidth-14;
		// ДСП вид
		if (DSP_Panel->BevelOuter == bvLowered) {
			Column->Width = Column->Width -32;
			Column = DBMainGrid->Columns->Add();
			Column->FieldName = "SETMARK_TEXT";
			Column->Title->Caption = "НРН";
			Column->Title->Color = clInfoBk;
			Column->Title->Font->Style = TFontStyles()<<fsBold;
			Column->Width = 31;

		}
		needfieldsref = 0;
		//ShowMessage(DBMainGrid->Columns->Count);
	} else {
		//DBMainGrid->Columns->Items[2]->Title->Caption;
		DBMainGrid->Columns->Count;
		 //needfieldsref =
		/*colwidth = 48;
		scrollw = DBMainGrid->ClientWidth;
		Table_Fieldsdef->First();
		//ShowMessage(DBMainGrid->ClientWidth);
		while (!Table_Fieldsdef->Eof){
				Column->Width = scrollw/100*Table_Fieldsdef->FieldByName("MANWIDTH")->AsInteger;
				colwidth = colwidth + Column->Width+1;

			Table_Fieldsdef->Next();
		}
		colwidth = colwidth - Column->Width-1;

        Column->Width = scrollw-colwidth-14;
		// ДСП вид
		if (DSP_Panel->BevelOuter == bvLowered) {
			Column->Width = 31;
		} */
    //}
/*for(int i = 0 ;i < col_count;i++)
   total_width +=  Grid->Columns->Items[i]->Width;

  if(Grid->Options.Contains(dgColLines))
   total_width += col_count;

  if(Grid->Options.Contains(dgIndicator))
   total_width += IndicatorWidth;  */


	//ShowMessage(colwidth);
	//ShowMessage(scrollw);

	//Column->Width = DBMainGrid->Width-colwidth-33;

	/*if (colwidth<scrollw) {
		Column->Width = Column->Width + (scrollw-colwidth-33);
	}
	if (colwidth>scrollw) {
		Column->Width = Column->Width - (colwidth-scrollw+33);
	}*
	ShowMessage(scrollw);
	ShowMessage(colwidth);
	/*if (ShowScrollBar(DBMainGrid->Handle,SB_VERT,true)) {
	   ShowMessage("Есть скрол");
	} else {
		ShowMessage("Нет скрола");
    }*/

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button26Click(TObject *Sender)
{
	FormConv = new TFormConv(MainForm,MainConn,MainTransaction);
	FormConv->ShowModal();
	delete FormConv;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button27Click(TObject *Sender)
{
	//Фиксация изменений
	//DataSource1->DataSet->CheckBrowseMode();
	//Записать изменения в базу данных
	//IBTransaction1->Commit();
	//Открыть набор данных
	//IBTable1->Active=True;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Addkart_SpeedButtonClick(TObject *Sender)
{
	//int pricetype = 0;
	if (Spr_Panel->BevelOuter==bvLowered) {
		pricetype = 1;
	}
	if (Opr_Panel->BevelOuter==bvLowered) {
		pricetype = 2;
	}
	if (Apr_Panel->BevelOuter==bvLowered) {
		pricetype = 3;
	}
	//TabPricelist_Datasource_Main->DataSet->DisableControls();
	TabPricelist_Datasource_Main->DataSet=MainTable;
	MainTable->Edit();
	MainTable->Append();
	// Генерация номера карты
	QueryTab->SQL->Clear();
	QueryTab->SQL->Add("SELECT GEN_ID(GEN_NUM_CARD, 1) as num_card FROM RDB$DATABASE;");
	QueryTab->Open();
	MainTable->FieldByName("NUM_CARD")->AsInteger=QueryTab->FieldByName("NUM_CARD")->AsInteger;
	MainTable->FieldByName("ID")->AsInteger=-1;
	//TabPricelist_Datasource_Main->DataSet->FieldByName("MORGAGE")->AsInteger=0;
	//TabPricelist_Datasource_Main->DataSet->FieldByName("SECURITY")->AsInteger=0;
	//TabPricelist_Datasource_Main->DataSet->FieldByName("KONSERG")->AsInteger=0;
	/*TabPricelist_Datasource_Main->DataSet->FieldByName("OWNEX")->AsInteger=0;
	TabPricelist_Datasource_Main->DataSet->FieldByName("TRASH")->AsInteger=0;
	TabPricelist_Datasource_Main->DataSet->FieldByName("GAZ")->AsInteger=0;
	TabPricelist_Datasource_Main->DataSet->FieldByName("PARKING")->AsInteger=0;
	TabPricelist_Datasource_Main->DataSet->FieldByName("NEWBUILD")->AsInteger=0;
	TabPricelist_Datasource_Main->DataSet->FieldByName("GLASSBALC")->AsInteger=0;
	TabPricelist_Datasource_Main->DataSet->FieldByName("GLASSPACK")->AsInteger=0;
	TabPricelist_Datasource_Main->DataSet->FieldByName("DOPLATA")->AsInteger=0; */
	//TabPricelist_Datasource_Main->DataSet->FieldByName("PICS")->AsInteger=0;
	MainTable->FieldByName("COMPSTR")->AsString =
		 Table_Abonents->FieldByName("COMPNAME")->AsString + ", " +
		 Table_Abonents->FieldByName("ADDRESS")->AsString + ", " +
		 Table_Abonents->FieldByName("PHONE")->AsString;
	MainTable->FieldByName("DATE_ENTER")->AsDateTime=Date();
	MainTable->FieldByName("AGENT")->AsInteger=OwnerCode;
	MainTable->FieldByName("PRICETYPE")->AsInteger=pricetype;
	MainTable->FieldByName("CHECK")->AsInteger=0;
	//ShowMessage(IBXDataDriverEh1->InsertSQL->Text);
	//MainTable->Post();
	//MainTable->ApplyUpdates(0);
	//IBTransaction1->CommitRetaining();
	//MainTable->cl
	//IBXDataDriverEh1->ApplyUpdates(MainTable);
	//IBXDataDriverEh1->ApplyUpdates();
	//IBXDataDriverEh1->
	//Вызов формы редактирования карточки
	//Viewkart_SpeedButtonClick(this);

	swinsert=1;
	procviewkart(this);

	//TabPricelist_Datasource_Main->DataSet->EnableControls();
	//FormEdit = new TFormEdit(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main);
	//FormEdit->ShowModal();
	//delete FormEdit;
	//MainTransaction->RollbackRetaining();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Mregion_ButtonClick(TObject *Sender)
{
	// Кнопка микрорайон
	UnicodeString * resultstr = new UnicodeString;
	*resultstr = Mregion_Label->Caption;

	FormSelectBlue = new TFormSelectBlue(this, Table_mRegion_short, resultstr);
	FormSelectBlue->Left = Panel3->Left-10;
	FormSelectBlue->Top = Panel3->Top+Mregion_Button->Top+60;
	FormSelectBlue->ShowModal();
	Mregion_Label->Caption = *resultstr;

	delete FormSelect;
	delete resultstr;
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{

	//Application->Title = Caption;
	//RefreshGrid(this);
	/*DBMainGrid->Columns->Items[0]->Width = 25;
	DBMainGrid->Columns->Items[1]->Width = 25;
	DBMainGrid->Columns->Items[2]->Width = 40;
	DBMainGrid->Columns->Items[3]->Width = 60;
	DBMainGrid->Columns->Items[4]->Width = 60;
	DBMainGrid->Columns->Items[5]->Width = 40;
	DBMainGrid->Columns->Items[6]->Width = 40;
	DBMainGrid->Columns->Items[7]->Width = 200;
	DBMainGrid->Columns->Items[8]->Width = 25;
	DBMainGrid->Columns->Items[9]->Width = 25;
	DBMainGrid->Columns->Items[10]->Width = 50;
	DBMainGrid->Columns->Items[11]->Width = 35;
	DBMainGrid->Columns->Items[12]->Width = 35;
	DBMainGrid->Columns->Items[13]->Width = 50;
	DBMainGrid->Columns->Items[14]->Width = 50;
	DBMainGrid->Columns->Items[15]->Width = 50;
	DBMainGrid->Columns->Items[16]->Width = 50;
	DBMainGrid->Columns->Items[17]->Width = 50;
	DBMainGrid->Columns->Items[18]->Width = 50;
	DBMainGrid->Columns->Items[19]->Width = 50;
	DBMainGrid->Columns->Items[20]->Width = 50;
	DBMainGrid->Columns->Items[21]->Width = 77;*/
	/*if (Table_Agent->RecordCount<2)
		GridAgent->Columns->Items[7]->Width = 167;
	else
		GridAgent->Columns->Items[7]->Width = 149;*/
	/*/Список разделов прайс-листа
	MainForm->Razdel_ComboBox->ListSource=Razdel_datasource;
	MainForm->Razdel_ComboBox->ListField="FULLNAME";
	MainForm->Razdel_ComboBox->KeyField="ID";
	Razdel_datasource->DataSet->First();
	MainForm->Razdel_ComboBox->DataField = MainForm->razdel;
	//MainForm->Razdel_DBLookComb->
	//MainForm->Razdel_DBLookComb->KeyValue = Razdel_datasource->DataSet->FieldByName("fullname")->AsAnsiString;
	*/
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N3Click(TObject *Sender)
{
	MainForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N23Click(TObject *Sender)
{
	FormStatAg = new TFormStatAg(NULL);
	FormStatAg->ShowModal();
	delete FormStatAg;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button11Click(TObject *Sender)
{
	//char * tmpstr = "rrr";
	//char * tmpstr2 = (char*)103;
	//tmpstr = strncat(tmpstr,tmpstr2,3);
	//ShowMessage(tmpstr2);
	//char * szString = new char[17];
		//int i = 1234567890;
		//itoa(i,szString,10);
	//ShowMessage(szString);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N29Click(TObject *Sender)
{
	FormAgent = new TFormAgent(MainForm,MainConn);
	FormAgent->ShowModal();
	delete FormAgent;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N31Click(TObject *Sender)
{
	long * retval = new long;
	*retval = 0;
	FormKlients = new TFormKlients(MainForm, MainConn, retval);
	FormKlients->ShowModal();
	delete FormKlients;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N30Click(TObject *Sender)
{
	FormInfoWindow = new TFormInfoWindow(MainForm);
	FormInfoWindow->ShowModal();
	delete FormInfoWindow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N32Click(TObject *Sender)
{
	int * retval = new int;
	*retval = 0;
	FormFindKart = new TFormFindKart(MainForm,TabPricelist_Datasource_Main, retval);
	FormFindKart->ShowModal();
	delete FormFindKart;
	if (*retval!=0) {
		 Viewkart_SpeedButtonClick(this);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N33Click(TObject *Sender)
{
	// Форма редактирования групп пользователей
	FormGroupEdit = new TFormGroupEdit(MainForm,MainConn);
	FormGroupEdit->ShowModal();
	delete FormGroupEdit;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Exel1Click(TObject *Sender)
{
	// Форма экспорта в excel
	FormExcelExport = new TFormExcelExport(MainForm,MainConn,TabPricelist_Datasource_Main);
	FormExcelExport->ShowModal();
	delete FormExcelExport;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N41Click(TObject *Sender)
{
	FormThems = new TFormThems(MainForm);
	FormThems->ShowModal();
	delete FormThems;
	// Установка тем
	SetThems(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N35Click(TObject *Sender)
{
	FormInfoWindow = new TFormInfoWindow(MainForm);
	FormInfoWindow->ShowModal();
	delete FormInfoWindow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N36Click(TObject *Sender)
{
	FormNastr = new TFormNastr(MainForm, MainConn);
	FormNastr->ShowModal();
	delete FormNastr;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N24Click(TObject *Sender)
{
	FormStatFirm = new TFormStatFirm(MainForm);
	FormStatFirm->ShowModal();
	delete FormStatFirm;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N25Click(TObject *Sender)
{
	FormSpravAgent = new TFormSpravAgent(MainForm);
	FormSpravAgent->ShowModal();
	delete FormSpravAgent;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N26Click(TObject *Sender)
{
	FormReestrAbonent = new TFormReestrAbonent(MainForm, MainConn);
	FormReestrAbonent->ShowModal();
	delete FormReestrAbonent;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DrawGridCheckBox(TCanvas *Canvas, TRect Rect, bool Checked)
{
	int DrawFlags;
	Canvas->TextRect(Rect, Rect.Left + 1, Rect.Top + 1, ' ');
	DrawFrameControl(Canvas->Handle, (RECT*) &Rect, DFC_BUTTON, DFCS_BUTTONPUSH | DFCS_ADJUSTRECT);
	DrawFlags = DFCS_BUTTONCHECK | DFCS_ADJUSTRECT;// DFCS_BUTTONCHECK
	if (Checked) {
		DrawFlags = DrawFlags | DFCS_CHECKED;
	}
	DrawFrameControl(Canvas->Handle, (RECT*) &Rect, DFC_BUTTON, DrawFlags);
}
//---------------------------------------------------------------------------

/*void __fastcall TMainForm::DBMainGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
	// Раскраска не подтвержденных объектов
	if (Spr_Panel->BevelOuter==bvLowered) {
		 if (TabPricelist_Datasource_Main->DataSet->FieldByName("PRICE")->AsInteger==0) {
			  //DBMainGrid->Canvas->Brush->Color=TColor(0x00D2D2FF);//$00D2D2FF
			  DBMainGrid->Canvas->Font->Color=clGreen;
			  DBMainGrid->Canvas->FillRect(Rect);
			  if (Column->Alignment == taRightJustify) {
				  DBMainGrid->Canvas->TextOut(Rect.Right - 2 - Column->Field->Text.Length()*6,
					 Rect.Top+2, Column->Field->Text);
			  } else {
				  DBMainGrid->Canvas->TextOut(Rect.Left+2,Rect.Top+2,Column->Field->Text);
			  }
		 }
	}
	// Раскраска объектов с рекламацией
	//ShowMessage(TabPricelist_Datasource_Main->DataSet->FieldByName("REKL")->AsInteger);
	if (Spr_Panel->BevelOuter==bvLowered) {
		 if (!TabPricelist_Datasource_Main->DataSet->FieldByName("REKLTEXT")->IsNull) {
			  DBMainGrid->Canvas->Brush->Color=TColor(0x00D2D2FF);//$00D2D2FF
			  DBMainGrid->Canvas->FillRect(Rect);
			  if (Column->Alignment == taRightJustify) {
				  DBMainGrid->Canvas->TextOut(Rect.Right - 2 - Column->Field->Text.Length()*6,
					 Rect.Top+2, Column->Field->Text);
			  } else {
				  DBMainGrid->Canvas->TextOut(Rect.Left+2,Rect.Top+2,Column->Field->Text);
			  }
		 }
	}
	// Раскраска желтым фоном устаревших объектов
	if (Opr_Panel->BevelOuter==bvLowered) {
		 if (TabPricelist_Datasource_Main->DataSet->FieldByName("DATE_CH")->AsDateTime<Date()-30) {
              DBMainGrid->Canvas->Brush->Color=TColor(0x0080FFFF);//$0080FFFF
			  DBMainGrid->Canvas->FillRect(Rect);
			  if (Column->Alignment == taRightJustify) {
				  DBMainGrid->Canvas->TextOut(Rect.Right - 2 - Column->Field->Text.Length()*6,
					 Rect.Top+2, Column->Field->Text);
			  } else {
				  DBMainGrid->Canvas->TextOut(Rect.Left+2,Rect.Top+2,Column->Field->Text);
			  }
         }
    }
	// Раскраска своих объектов в общем прайс-листе CompanyID
	if (Apr_Panel->BevelOuter==bvLowered) {
		//pricetype = 1;
		if (TabPricelist_Datasource_Main->DataSet->FieldByName("AGENT")->AsInteger==CompanyID) {
			DBMainGrid->Canvas->Brush->Color=TColor(0x00DEAF61);//$00DEAF61
			DBMainGrid->Canvas->FillRect(Rect);
			if (Column->Alignment == taRightJustify) {
				DBMainGrid->Canvas->TextOut(Rect.Right - 2 - Column->Field->Text.Length()*6,
					Rect.Top+2, Column->Field->Text);
			} else {
				DBMainGrid->Canvas->TextOut(Rect.Left+2,Rect.Top+2,Column->Field->Text);
			}
		}
	}
	if (TabPricelist_Datasource_Main->DataSet->FieldByName("SETMARK")->AsInteger==1) {
		 // Раскраска объектов помеченных для отправки СМИ
		//DBMainGrid->Canvas->Brush->Color=clGreen;
		DBMainGrid->Canvas->Brush->Color=TColor(0x00DFF2D7);//$00DFF2D7
		//DBMainGrid->Canvas->Font->Color=clWhite;
		DBMainGrid->Canvas->FillRect(Rect);
		if (Column->Alignment == taRightJustify) {
			DBMainGrid->Canvas->TextOut(Rect.Right - 2 - Column->Field->Text.Length()*6,
				Rect.Top+2, Column->Field->Text);
		} else {
			DBMainGrid->Canvas->TextOut(Rect.Left+2,Rect.Top+2,Column->Field->Text);
		}
	 }
	Graphics::TBitmap *Im1;
	Im1= new   Graphics::TBitmap;
	if
	(Column->FieldName=="PICS")
	{
		//DBMainGrid->Canvas->Brush->Color=clWhite;
		//DBMainGrid->Canvas->FillRect(Rect);
		if (MainTable->FieldByName("PICS")->Value==1)
		{
        	DBMainGrid->Canvas->Brush->Color=clWhite;
			DBMainGrid->Canvas->FillRect(Rect);
			ImageList1->GetBitmap(2,Im1);
			DBMainGrid->Canvas->Draw((Rect.Left+Rect.Right-Im1->Width)/2,Rect.Top,Im1);
		}
		else
		{
			//ImageList1->GetBitmap(0,Im1);
		}
		//DBMainGrid->Canvas->Draw((Rect.Left+Rect.Right-Im1->Width)/2,Rect.Top,Im1);
	}
	if (DataCol==1)
	{
		DBMainGrid->Canvas->FillRect(Rect);
		if (TabPricelist_Datasource_Main->DataSet->FieldByName("CHECK")->AsInteger!=1) {
		   DrawFrameControl(DBMainGrid->Canvas->Handle, (RECT*) &Rect, DFC_BUTTON, DFCS_BUTTONCHECK | !DFCS_CHECKED);
		} else {
            DrawFrameControl(DBMainGrid->Canvas->Handle, (RECT*) &Rect, DFC_BUTTON, DFCS_BUTTONCHECK | DFCS_CHECKED);
		}
		/*if (TabPricelist_Datasource_Main->DataSet->FieldByName("CHECK")->AsInteger!=1) {
			DrawGridCheckBox(DBMainGrid->Canvas, Rect, true);
		} else {
			DrawGridCheckBox(DBMainGrid->Canvas, Rect, false);
		}*/
//	}
//}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBMainGrid1CellClick(TColumn *Column)
{
	if (Column->FieldName=="CHECK") {
		//DrawGridCheckBox(DBMainGrid->Canvas, Rect, true);
		TabPricelist_Datasource_Main->DataSet->Edit();
		if (TabPricelist_Datasource_Main->DataSet->FieldByName("CHECK")->AsInteger==1) {
			TabPricelist_Datasource_Main->DataSet->FieldByName("CHECK")->AsInteger=0;
		} else {
			TabPricelist_Datasource_Main->DataSet->FieldByName("CHECK")->AsInteger=1;
		}
	}
	if (Column->FieldName=="PICS") {
		//DrawGridCheckBox(DBMainGrid->Canvas, Rect, true);
		//TabPricelist_Datasource_Main->DataSet->Edit();
		int * swgall = new int;
		*swgall = 0;
		if (TabPricelist_Datasource_Main->DataSet->FieldByName("PICS")->AsInteger==1) {
			FormGallView = new TFormGallView(MainForm, swgall);
			FormGallView->ShowModal();
			//ShowMessage(*swgall);
			delete FormGallView;
			if (*swgall==1) {
				FormGall = new TFormGall(MainForm);
				FormGall->ShowModal();
				delete FormGall;
			}
			//TabPricelist_Datasource_Main->DataSet->FieldByName("PICS")->AsInteger=0;
		} else {
			//TabPricelist_Datasource_Main->DataSet->FieldByName("PICS")->AsInteger=1;
		}
	}
	/*if Column.Field.DataType=ftBoolean then begin
  with DBGrid1 do begin
  DataSource.DataSet.Edit;
  Column.Field.AsBoolean:=not Column.Field.AsBoolean;
  DataSource.DataSet.Post;
  end; */
//end;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Delkart_SpeedButtonClick(TObject *Sender)
{
    if (Reccount_Label->Caption.Trim()=="Записей - 0") {
        Abort();
    }
	AnsiString ds = "Вы действительно хотите удалить запись?";
	if (MessageBox(this->Handle,ds.c_str(),"Подтверждение удаления",MB_YESNO | MB_TOPMOST | MB_ICONQUESTION)!=IDYES){
		Abort();
	}
	Table_Tabledef->RecNo = Razdel_ComboBox->ItemIndex+1;

	Table_Delrecords->Append();
	Table_Delrecords->FieldByName("GUID")->AsString=TabPricelist_Datasource_Main->DataSet->FieldByName("GUID")->AsString;
	Table_Delrecords->FieldByName("TABLENAME")->AsString = Table_Tabledef->FieldByName("Tablename")->AsString;
	Table_Delrecords->FieldByName("DATEDEL")->AsDateTime=Date();
	TabPricelist_Datasource_Main->DataSet->Edit();
	TabPricelist_Datasource_Main->DataSet->Delete();
	 //Фиксация изменений
	Table_Delrecords->CheckBrowseMode();
	MainTable->Edit();
	MainTable->Post();
	MainTable->ApplyUpdates(0);
	MainTransaction->CommitRetaining();
	IBTransaction1->CommitRetaining();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::procviewkart(TObject *Sender)
{
	//int pricetype = 0;
	if (Spr_Panel->BevelOuter==bvLowered) {
		pricetype = 1;
	}
	if (Opr_Panel->BevelOuter==bvLowered) {
		pricetype = 2;
	}
	if (Apr_Panel->BevelOuter==bvLowered) {
		pricetype = 3;
	}
	int currrecno;
	currrecno = 0;
	if (MainTable->RecordCount>0) {
	   currrecno = MainTable->RecNo;
	}
	//Вызов формы редактирования карточки: Квартира предложение
	Table_Tabledef->RecNo = Razdel_ComboBox->ItemIndex+1;
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="APARTSELL") {
		if (swinsert==1) {
			MainTable->FieldByName("MORGAGE")->AsInteger=0;
			MainTable->FieldByName("SECURITY")->AsInteger=0;
			MainTable->FieldByName("KONSERG")->AsInteger=0;
			MainTable->FieldByName("OWNEX")->AsInteger=0;
			MainTable->FieldByName("TRASH")->AsInteger=0;
			MainTable->FieldByName("GAZ")->AsInteger=0;
			MainTable->FieldByName("PARKING")->AsInteger=0;
			MainTable->FieldByName("NEWBUILD")->AsInteger=0;
			MainTable->FieldByName("GLASSBALC")->AsInteger=0;
			MainTable->FieldByName("GLASSPACK")->AsInteger=0;
			MainTable->FieldByName("DOPLATA")->AsInteger=0;
		}
		FormEdit = new TFormEdit(MainForm);
		FormEdit->ShowModal();
		delete FormEdit;
	}
	//Вызов формы редактирования карточки: Квартира спрос
	if (Purch_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="APARTPURCH") {
		//FormEditApartPurch = new TFormEditApartPurch(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main);
		if (swinsert==1) {
			TabPricelist_Datasource_Main->DataSet->FieldByName("SWBALCONY")->AsInteger=0;
			TabPricelist_Datasource_Main->DataSet->FieldByName("SWLOGGIA")->AsInteger=0;
			TabPricelist_Datasource_Main->DataSet->FieldByName("SWPHONE")->AsInteger=0;
			TabPricelist_Datasource_Main->DataSet->FieldByName("SWRUB")->AsInteger=0;
		}
		FormEditApartPurch = new TFormEditApartPurch(MainForm);
		FormEditApartPurch->ShowModal();
		delete FormEditApartPurch;
	}

	//Вызов формы редактирования карточки: Комната предложение
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="ROOMSSELL") {
		//FormEditRoomsSell = new TFormEditRoomsSell(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditRoomsSell = new TFormEditRoomsSell(MainForm);
		FormEditRoomsSell->ShowModal();
		delete FormEditRoomsSell;
	}

	//Вызов формы редактирования карточки: Комната спрос
	if (Purch_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="ROOMSPURCH") {
		//FormEditRoomsPurch = new TFormEditRoomsPurch(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditRoomsPurch = new TFormEditRoomsPurch(MainForm);
		FormEditRoomsPurch->ShowModal();
		delete FormEditRoomsPurch;
	}
	//Вызов формы редактирования карточки: Аренда предложение
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="ARENDSELL") {
		FormEditArendSell = new TFormEditArendSell(MainForm);
		//FormEditArendSell = new TFormEditArendSell(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main);
		FormEditArendSell->ShowModal();
		delete FormEditArendSell;
	}

	//Вызов формы редактирования карточки: Аренда спрос
	if (Purch_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="ARENDPURCH") {
		//FormEditArendPurch = new TFormEditArendPurch(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditArendPurch = new TFormEditArendPurch(MainForm);
		FormEditArendPurch->ShowModal();
		delete FormEditArendPurch;
	}

	//Вызов формы редактирования карточки: Дачи, дома коттеджи предложение
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="HOUSESELL") {
		//FormEditHouseSell = new TFormEditHouseSell(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditHouseSell = new TFormEditHouseSell(MainForm);
		FormEditHouseSell->ShowModal();
		delete FormEditHouseSell;
	}

	//Вызов формы редактирования карточки: Дачи, дома коттеджи спрос
	if (Purch_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="HOUSEPURCH") {
		//FormEditHousePurch = new TFormEditHousePurch(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditHousePurch = new TFormEditHousePurch(MainForm);
		FormEditHousePurch->ShowModal();
		delete FormEditHousePurch;
	}

	//Вызов формы редактирования карточки: Гаражи, уч-ки предложение
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="GARAGESELL") {
		//FormEditGarageSell = new TFormEditGarageSell(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditGarageSell = new TFormEditGarageSell(MainForm);
		FormEditGarageSell->ShowModal();
		delete FormEditGarageSell;
	}

	//Вызов формы редактирования карточки: Гаражи, уч-ки спрос
	if (Purch_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="GARAGEPURCH") {
		//FormEditGaragePurch = new TFormEditGaragePurch(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditGaragePurch = new TFormEditGaragePurch(MainForm);
		FormEditGaragePurch->ShowModal();
		delete FormEditGaragePurch;
	}

	//Вызов формы редактирования карточки: Земельные участки предложение
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="LANDSELL") {
		//FormEditGaragePurch = new TFormEditGaragePurch(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditGaragePurch = new TFormEditGaragePurch(MainForm);
		FormEditLandSell->ShowModal();
		delete FormEditLandSell;
	}

	//Вызов формы редактирования карточки: Коммерческая недвижимость спрос
	if (Purch_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="COMMERCPURCH") {
		//FormEditCommercPurch = new TFormEditCommercPurch(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditCommercPurch = new TFormEditCommercPurch(MainForm);
		FormEditCommercPurch->ShowModal();
		delete FormEditCommercPurch;
	}

	//Вызов формы редактирования карточки: Долевое строительство
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="NEWBUILDSSELL") {
		//FormEditNewBuildsSell = new TFormEditNewBuildsSell(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditNewBuildsSell = new TFormEditNewBuildsSell(MainForm);
		FormEditNewBuildsSell->ShowModal();
		delete FormEditNewBuildsSell;
	}

	//Вызов формы редактирования карточки: Здания, сооружения - предложение
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="COMMERCSELL1") {
		//FormEditCommercSell1 = new TFormEditCommercSell1(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditCommercSell1 = new TFormEditCommercSell1(MainForm);
		FormEditCommercSell1->ShowModal();
		delete FormEditCommercSell1;
	}

	//Вызов формы редактирования карточки: Офисные помещения - предложение
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="COMMERCSELL2") {
		//FormEditCommercSell2 = new TFormEditCommercSell2(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditCommercSell2 = new TFormEditCommercSell2(MainForm);
		FormEditCommercSell2->ShowModal();
		delete FormEditCommercSell2;
	}

	//Вызов формы редактирования карточки: Торговля, услуги, общепит - предложение
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="COMMERCSELL3") {
		//FormEditCommercSell3 = new TFormEditCommercSell3(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditCommercSell3 = new TFormEditCommercSell3(MainForm);
		FormEditCommercSell3->ShowModal();
		delete FormEditCommercSell3;
	}

	//Вызов формы редактирования карточки: Склады, производсвенные помещения
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="COMMERCSELL4") {
		//FormEditCommercSell4 = new TFormEditCommercSell4(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditCommercSell4 = new TFormEditCommercSell4(MainForm);
		FormEditCommercSell4->ShowModal();
		delete FormEditCommercSell4;
	}

	//Вызов формы редактирования карточки: Карточка продажи готового бизнеса
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="BUSINESSSELL") {
		//FormEditBusinessSell = new TFormEditBusinessSell(MainForm,MainConn,MainTransaction,TabPricelist_Datasource_Main,pricetype,MainTable);
		FormEditBusinessSell = new TFormEditBusinessSell(MainForm);
		FormEditBusinessSell->ShowModal();
		delete FormEditBusinessSell;
	}

	//Вызов формы редактирования карточки: Зарубежная недвижимость
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="ABROADSELL") {
		FormEditAbroadSell = new TFormEditAbroadSell(MainForm);
		FormEditAbroadSell->ShowModal();
		delete FormEditAbroadSell;
	}

	//Вызов формы редактирования карточки: Коммерческая (объединенная)
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="COMMERCSELLALL") {
		UnicodeString * resultstr = new UnicodeString;
		*resultstr = "";

		// Процедура обновления таблицы со списком таблиц
		Table_Tabledef->Active=false;
		Table_Tabledef->Filtered = false;
		Table_Tabledef->Filter = "ID in(26,30,32,34)";
		Table_Tabledef->Filtered = true;
		Table_Tabledef->Active=true;
		Table_Tabledef->FetchAll();

		FormEditSellAll = new TFormEditSellAll(this, Table_Tabledef, resultstr);
		FormEditSellAll->ShowModal();
		if (AnsiUpperCase(*resultstr)=="COMMERCSELL1") {
			FormEditCommercSell1 = new TFormEditCommercSell1(MainForm);
			FormEditCommercSell1->ShowModal();
			delete FormEditCommercSell1;
		}
		if (AnsiUpperCase(*resultstr)=="COMMERCSELL2") {
			FormEditCommercSell2 = new TFormEditCommercSell2(MainForm);
			FormEditCommercSell2->ShowModal();
			delete FormEditCommercSell2;
		}
		if (AnsiUpperCase(*resultstr)=="COMMERCSELL3") {
			FormEditCommercSell3 = new TFormEditCommercSell3(MainForm);
			FormEditCommercSell3->ShowModal();
			delete FormEditCommercSell3;
		}
		if (AnsiUpperCase(*resultstr)=="COMMERCSELL4") {
			FormEditCommercSell4 = new TFormEditCommercSell4(MainForm);
			FormEditCommercSell4->ShowModal();
			delete FormEditCommercSell4;
		}
		//ShowMessage(*resultstr);
		//TabPricelist_Datasource_Main->DataSet->Edit();
		//TabPricelist_Datasource_Main->DataSet->FieldByName("TYPEHOUSE")->AsString = *resultstr;
		delete FormSelect;
		delete resultstr;

		Table_Tabledef->Active=false;
		Table_Tabledef->Filtered = false;
		Table_Tabledef->Filter = "PROPER = 14";
		Table_Tabledef->Filtered = true;
		Table_Tabledef->Active=true;
		Table_Tabledef->FetchAll();
	}

	//Вызов формы редактирования карточки: Аренда (объединенная)
	if (Sell_Panel->BevelOuter == bvLowered && Table_Tabledef->FieldByName("TABLENAME")->AsAnsiString.UpperCase()=="ARENDSELLALL") {
		UnicodeString * resultstr = new UnicodeString;
		*resultstr = "";

		// Процедура обновления таблицы со списком таблиц
		Table_Tabledef->Active=false;
		Table_Tabledef->Filtered = false;
		Table_Tabledef->Filter = "ID in(10,14,26,30,32,34)";
		Table_Tabledef->Filtered = true;
		Table_Tabledef->Active=true;
		Table_Tabledef->FetchAll();

		FormEditSellAll = new TFormEditSellAll(this, Table_Tabledef, resultstr);
		FormEditSellAll->ShowModal();
		if (AnsiUpperCase(*resultstr)=="COMMERCSELL1") {
			FormEditCommercSell1 = new TFormEditCommercSell1(MainForm);
			FormEditCommercSell1->ShowModal();
			delete FormEditCommercSell1;
		}
		if (AnsiUpperCase(*resultstr)=="COMMERCSELL2") {
			FormEditCommercSell2 = new TFormEditCommercSell2(MainForm);
			FormEditCommercSell2->ShowModal();
			delete FormEditCommercSell2;
		}
		if (AnsiUpperCase(*resultstr)=="COMMERCSELL3") {
			FormEditCommercSell3 = new TFormEditCommercSell3(MainForm);
			FormEditCommercSell3->ShowModal();
			delete FormEditCommercSell3;
		}
		if (AnsiUpperCase(*resultstr)=="COMMERCSELL4") {
			FormEditCommercSell4 = new TFormEditCommercSell4(MainForm);
			FormEditCommercSell4->ShowModal();
			delete FormEditCommercSell4;
		}
		if (AnsiUpperCase(*resultstr)=="ARENDSELL") {
			FormEditArendSell = new TFormEditArendSell(MainForm);
			FormEditArendSell->ShowModal();
			delete FormEditArendSell;
		}
		if (AnsiUpperCase(*resultstr)=="HOUSESELL") {
			FormEditHouseSell = new TFormEditHouseSell(MainForm);
			FormEditHouseSell->ShowModal();
			delete FormEditHouseSell;
		}
		//ShowMessage(*resultstr);
		//TabPricelist_Datasource_Main->DataSet->Edit();
		//TabPricelist_Datasource_Main->DataSet->FieldByName("TYPEHOUSE")->AsString = *resultstr;
		delete FormSelect;
		delete resultstr;

		Table_Tabledef->Active=false;
		Table_Tabledef->Filtered = false;
		Table_Tabledef->Filter = "PROPER = 14";
		Table_Tabledef->Filtered = true;
		Table_Tabledef->Active=true;
		Table_Tabledef->FetchAll();
	}
	Filter_MainTable(this);
	if (currrecno>0) {
		MainTable->RecNo = currrecno;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Viewkart_SpeedButtonClick(TObject *Sender)
{
	if (Reccount_Label->Caption.Trim()!="Записей - 0") {
    	swinsert = 0;
		procviewkart(this);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetThems(TObject *Sender)
{
	// Установка тем
	// sPath
	String tmpthems = Ini->ReadString("Thems","Themsname","Default");
	Spr_Image->Picture->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\SPr.bmp");
	Opr_Image->Picture->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\OPr.bmp");
	Apr_Image->Picture->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\APr.bmp");
	//Myoutprice_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\SPr.bmp");
	//Myinprice_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\OPr.bmp");
	//Allprice_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\APr.bmp");

	Addkart_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\AddC.bmp");
	if (Reccount_Label->Caption.Trim()=="Записей - 0") {
		Viewkart_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\ViewC_nd.bmp");
	} else {
		Viewkart_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\ViewC.bmp");
	}
	if (Reccount_Label->Caption.Trim()=="Записей - 0") {
		Delkart_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\DelC_nd.bmp");
	} else {
		Delkart_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\DelC.bmp");
	}
	if (Reccount_Label->Caption.Trim()=="Записей - 0") {
		Refreshkart_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\RenewC_nd.bmp");
	} else {
		Refreshkart_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\RenewC.bmp");
	}

	Agent_Image->Picture->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\agent.bmp");
	Client_Image->Picture->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\Client.bmp");
	DSP_Image->Picture->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\DSP.bmp");
	//Agent_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\agent.bmp");
	//Client_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\Client.bmp");
	//DSP_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\DSP.bmp");

	Updateprice_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\comm.bmp");
	Info_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\IWin.bmp");
	Clients_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\SCli.bmp");
	Userch_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\ChU.bmp");
	Help_SpeedButton->Glyph->LoadFromFile(sPath+"\\Thems\\"+tmpthems+"\\help.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N42Click(TObject *Sender)
{
   // Сбросить оформление
	Ini->WriteString("Thems","Themsname","Default");
	SetThems(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N47Click(TObject *Sender)
{
	// Сбросить для всех разделов...
	AnsiString ds = "Все настройки ширины столбцов для всех разделов будут сброшены на значения по-умолчанию...\n"
			"Вы уверены?";
	if (MessageBox(this->Handle,ds.c_str(),"Внимание!",MB_YESNO | MB_TOPMOST | MB_ICONQUESTION)!=IDYES){
		Abort();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N44Click(TObject *Sender)
{
	// Настройка ширины столбцов таблицы
	/*int swsell = 2;
	// Кнопка "Предложение"
	if (Sell_Panel->BevelOuter == bvLowered) {
		swsell = 1;
	} */
	int swview = 3;
	// Агентский вид
	if (Agent_Panel->BevelOuter == bvLowered) {
		swview = 1;
	}
	// Клиентский вид
	if (Client_Panel->BevelOuter == bvLowered) {
		swview = 2;
	}
	FieldsDefTransaction->RollbackRetaining();
	Table_Tabledef->RecNo = Razdel_ComboBox->ItemIndex+1;
	FormGridColumn = new TFormGridColumn(MainForm, MainConn, swview, Table_Tabledef->FieldByName("TABLENAME")->AsString,
		Table_Tabledef->FieldByName("ID")->AsInteger);
	FormGridColumn->ShowModal();
	delete FormGridColumn;

	//Цикл по всем записям таблицы
	 Table_Fieldsdef->First();
	 do {
		Table_Fieldsdef->Edit();
		if (IniFields->ReadString("ApartSell_check",Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"0")==1)
			Table_Fieldsdef->FieldByName("MANCHECK")->AsInteger=1; else Table_Fieldsdef->FieldByName("MANCHECK")->AsInteger=0;
		Table_Fieldsdef->FieldByName("MANWIDTH")->AsString =
			IniFields->ReadString("ApartSell_width",Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"2");

		Table_Fieldsdef->Next();
	 } while(!Table_Fieldsdef->Eof);
	 Table_Fieldsdef->First();

     Refresh_Fieldsdef(this);
	 FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Agent_ImageClick(TObject *Sender)
{
	// Кнопка агент

	if (Agent_Panel->BevelOuter==bvLowered) {
		Abort();
	}
	Agent_Panel->BevelOuter=bvLowered;
	Agent_Label->Top = 27;
	// ***
	Client_Panel->BevelOuter=bvNone;
	Client_Label->Top = 28;
	// ***
	DSP_Panel->BevelOuter=bvNone;
	DSP_Label->Top = 28;
	//MainTable->DisableControls();
	Refresh_Fieldsdef(this);
	FormResize(this);
	//MainTable->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Client_ImageClick(TObject *Sender)
{
	// Кнопка клиент

	if (Client_Panel->BevelOuter==bvLowered) {
		Abort();
	}
	Client_Panel->BevelOuter=bvLowered;
	Client_Label->Top = 27;
	// ***
	Agent_Panel->BevelOuter=bvNone;
	Agent_Label->Top = 28;
	// ***
	DSP_Panel->BevelOuter=bvNone;
	DSP_Label->Top = 28;

	Refresh_Fieldsdef(this);
	FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DSP_ImageClick(TObject *Sender)
{
	// Кнопка ДСП

	if (DSP_Panel->BevelOuter==bvLowered) {
		Abort();
	}
	DSP_Panel->BevelOuter=bvLowered;
	DSP_Label->Top = 27;
	// ***
	Agent_Panel->BevelOuter=bvNone;
	Agent_Label->Top = 28;
	// ***
	Client_Panel->BevelOuter=bvNone;
	Client_Label->Top = 28;

    Refresh_Fieldsdef(this);
	FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Spr_ImageClick(TObject *Sender)
{
	// Кнопка свой внешний прайс
	Spr_Panel->BevelOuter=bvLowered;
	// ***
	Opr_Panel->BevelOuter=bvNone;
	// ***
	Apr_Panel->BevelOuter=bvNone;
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Opr_ImageClick(TObject *Sender)
{
	// Свой внутренний прайс
	Opr_Panel->BevelOuter=bvLowered;
	// ***
	Spr_Panel->BevelOuter=bvNone;
	// ***
	Apr_Panel->BevelOuter=bvNone;
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Apr_ImageClick(TObject *Sender)
{
	// Общий прайс
	Apr_Panel->BevelOuter=bvLowered;
	// ***
	Spr_Panel->BevelOuter=bvNone;
	// ***
	Opr_Panel->BevelOuter=bvNone;
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Purch_PanelClick(TObject *Sender)
{
	// Кнопка "Спрос"
	if (Purch_Panel->BevelOuter == bvLowered) {
        Abort();
	}
	Purch_Panel->BevelOuter = bvLowered;
	Sell_Panel->BevelOuter = bvNone;
	Sell_Panel->Color = clBtnFace;

    Refresh_Tabledef(this);
	Razdel_ComboBoxClick(this);
	RefreshFilterPanel(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Purch_PanelMouseEnter(TObject *Sender)
{
	// Кнопка "Спрос" навели мышкой
	if (Purch_Panel->BevelOuter != bvLowered) {
		 Purch_Panel->BevelOuter = bvRaised;
	}
	if (Purch_Panel->BevelOuter == bvLowered) {
		 Purch_Panel->Color = clBtnFace;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Purch_PanelMouseLeave(TObject *Sender)
{
	 // Кнопка "Спрос" убрали указатель мыши
	if (Purch_Panel->BevelOuter == bvRaised) {
		 Purch_Panel->BevelOuter = bvNone;
	}
	if (Purch_Panel->BevelOuter == bvLowered) {
		 Purch_Panel->Color = cl3DLight;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Print_PanelClick(TObject *Sender)
{
	// Кнопка "Печать"
	Table_Tabledef->RecNo = Razdel_ComboBox->ItemIndex+1;
	TypeObject = Table_Tabledef->FieldByName("Tablename")->AsString;

	Print_Panel->BevelOuter = bvLowered;
	FormPr = new TFormPr(this);
	FormPr->ShowModal();
	delete FormPr;
	Print_Panel->BevelOuter = bvNone;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Print_PanelMouseEnter(TObject *Sender)
{
	// Кнопка "Печать" навели мышкой
	if (Print_Panel->BevelOuter != bvLowered) {
		 Print_Panel->BevelOuter = bvRaised;
	}
	//if (Print_Panel->BevelOuter == bvLowered) {
	//	 Print_Panel->Color = clBtnFace;
	//}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Print_PanelMouseLeave(TObject *Sender)
{
	// Кнопка "Печать" убрали указатель мыши
	if (Print_Panel->BevelOuter == bvRaised) {
		 Print_Panel->BevelOuter = bvNone;
	}
	//if (Print_Panel->BevelOuter == bvLowered) {
	//	 Print_Panel->Color = cl3DLight;
   //	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Sell_PanelClick(TObject *Sender)
{
	// Кнопка "Предложение"
	if (Sell_Panel->BevelOuter == bvLowered) {
		Abort();
	}
	Sell_Panel->BevelOuter = bvLowered;
	Purch_Panel->BevelOuter = bvNone;
	Purch_Panel->Color = clBtnFace;

	Refresh_Tabledef(this);
	Razdel_ComboBoxClick(this);
	RefreshFilterPanel(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Sell_PanelMouseEnter(TObject *Sender)
{
	// Кнопка "Предложение" навели мышкой
	if (Sell_Panel->BevelOuter != bvLowered) {
		 Sell_Panel->BevelOuter = bvRaised;
	}
	if (Sell_Panel->BevelOuter == bvLowered) {
		 Sell_Panel->Color = clBtnFace;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Sell_PanelMouseLeave(TObject *Sender)
{
	// Кнопка "Предложение" убрали указатель мыши
	if (Sell_Panel->BevelOuter == bvRaised) {
		 Sell_Panel->BevelOuter = bvNone;
	}
	if (Sell_Panel->BevelOuter == bvLowered) {
		 Sell_Panel->Color = cl3DLight;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button12Click(TObject *Sender)
{
	FormTest = new TFormTest(NULL);
	FormTest->ShowModal();
	delete FormTest;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RS_PanelClick(TObject *Sender)
{
	// Кнопка "Объявления RANT&SALE"
	if (RS_Panel->BevelOuter != bvLowered) {
		RS_Panel->BevelOuter = bvLowered;
	} else {
		RS_Panel->BevelOuter = bvRaised;
	}
	ApartFilter(this);
	//FormPr = new TFormPr(NULL);
	//FormPr->ShowModal();
	//delete FormPr;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RS_PanelMouseEnter(TObject *Sender)
{
	// Кнопка "Объявления RANT&SALE" навели мышкой
	if (RS_Panel->BevelOuter != bvLowered) {
		 RS_Panel->BevelOuter = bvRaised;
	}
	if (RS_Panel->BevelOuter == bvLowered) {
		 RS_Panel->Color = clBtnFace;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RS_PanelMouseLeave(TObject *Sender)
{
	// Кнопка "Объявления RANT&SALE" убрали указатель мыши
	if (RS_Panel->BevelOuter == bvRaised) {
		 RS_Panel->BevelOuter = bvNone;
	}
	if (RS_Panel->BevelOuter == bvLowered) {
		 RS_Panel->Color = cl3DLight;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Excl_PanelClick(TObject *Sender)
{
	 // Кнопка "Эксклюзивный"
	if (Excl_Panel->BevelOuter != bvLowered) {
		Excl_Panel->BevelOuter = bvLowered;
	} else {
		Excl_Panel->BevelOuter = bvRaised;
	}
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Excl_PanelMouseEnter(TObject *Sender)
{
	// Кнопка "Эксклюзивный" навели мышкой
	if (Excl_Panel->BevelOuter != bvLowered) {
		 Excl_Panel->BevelOuter = bvRaised;
	}
	if (Excl_Panel->BevelOuter == bvLowered) {
		 Excl_Panel->Color = clBtnFace;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Excl_PanelMouseLeave(TObject *Sender)
{
	// Кнопка "Эксклюзивный" убрали указатель мыши
	if (Excl_Panel->BevelOuter == bvRaised) {
		 Excl_Panel->BevelOuter = bvNone;
	}
	if (Excl_Panel->BevelOuter == bvLowered) {
		 Excl_Panel->Color = cl3DLight;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Open_PanelClick(TObject *Sender)
{
	// Кнопка "Открытый"
	if (Open_Panel->BevelOuter != bvLowered) {
		Open_Panel->BevelOuter = bvLowered;
	} else {
		Open_Panel->BevelOuter = bvRaised;
	}
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Open_PanelMouseEnter(TObject *Sender)
{
	// Кнопка "Открытый" навели мышкой
	if (Open_Panel->BevelOuter != bvLowered) {
		 Open_Panel->BevelOuter = bvRaised;
	}
	if (Open_Panel->BevelOuter == bvLowered) {
		 Open_Panel->Color = clBtnFace;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Open_PanelMouseLeave(TObject *Sender)
{
	 // Кнопка "Открытый" убрали указатель мыши
	if (Open_Panel->BevelOuter == bvRaised) {
		 Open_Panel->BevelOuter = bvNone;
	}
	if (Open_Panel->BevelOuter == bvLowered) {
		 Open_Panel->Color = cl3DLight;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Nodog_PanelClick(TObject *Sender)
{
	 // Кнопка "Нет договорных отношений"
	if (Nodog_Panel->BevelOuter != bvLowered) {
		Nodog_Panel->BevelOuter = bvLowered;
	} else {
		Nodog_Panel->BevelOuter = bvRaised;
	}
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Nodog_PanelMouseEnter(TObject *Sender)
{
	 // Кнопка "Нет договорных отношений" навели мышкой
	if (Nodog_Panel->BevelOuter != bvLowered) {
		 Nodog_Panel->BevelOuter = bvRaised;
	}
	if (Nodog_Panel->BevelOuter == bvLowered) {
		 Nodog_Panel->Color = clBtnFace;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Nodog_PanelMouseLeave(TObject *Sender)
{
	 // Кнопка "Нет договорных отношений" убрали указатель мыши
	if (Nodog_Panel->BevelOuter == bvRaised) {
		 Nodog_Panel->BevelOuter = bvNone;
	}
	if (Nodog_Panel->BevelOuter == bvLowered) {
		 Nodog_Panel->Color = cl3DLight;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Rekl_PanelClick(TObject *Sender)
{
	// Кнопка "Рекламация"
	int pricetype = 0;
	if (Spr_Panel->BevelOuter==bvLowered) {
		pricetype = 1;
	}
	if (Opr_Panel->BevelOuter==bvLowered) {
		pricetype = 2;
	}
	if (Apr_Panel->BevelOuter==bvLowered) {
		pricetype = 3;
	}
	Rekl_Panel->BevelOuter = bvLowered;
	FormReklam = new TFormReklam(MainForm,pricetype);
	FormReklam->ShowModal();
	delete FormReklam;
	Rekl_Panel->BevelOuter = bvNone;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Rekl_PanelMouseEnter(TObject *Sender)
{
	// Кнопка "Рекламация" навели мышкой
	if (Rekl_Panel->BevelOuter != bvLowered) {
		 Rekl_Panel->BevelOuter = bvRaised;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Rekl_PanelMouseLeave(TObject *Sender)
{
	 // Кнопка "Рекламация" убрали указатель мыши
	if (Rekl_Panel->BevelOuter == bvRaised) {
		 Rekl_Panel->BevelOuter = bvNone;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Excel_PanelClick(TObject *Sender)
{
	// Кнопка "Excel"
	Excel_Panel->BevelOuter = bvLowered;
	//FormExportData = new TFormExportData(MainForm);
	//FormExportData->ShowModal();
	//delete FormExportData;
	FormExportGrid = new TFormExportGrid(MainForm);
	FormExportGrid->ShowModal();
	delete FormExportGrid;
	Excel_Panel->BevelOuter = bvNone;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Excel_PanelMouseEnter(TObject *Sender)
{
	 // Кнопка "Excel" навели мышкой
	if (Excel_Panel->BevelOuter != bvLowered) {
		 Excel_Panel->BevelOuter = bvRaised;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Excel_PanelMouseLeave(TObject *Sender)
{
	// Кнопка "Excel" убрали указатель мыши
	if (Excel_Panel->BevelOuter == bvRaised) {
		 Excel_Panel->BevelOuter = bvNone;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Web_PanelClick(TObject *Sender)
{
	// Кнопка ссылка на сайт
	Web_Panel->BevelOuter = bvLowered;
	ShellExecute(Handle,"open","http://isc63.ru", NULL,NULL,SW_RESTORE);
	//FormExportData = new TFormExportData(MainForm);
	//FormExportData->ShowModal();
	//delete FormExportData;
	Web_Panel->BevelOuter = bvNone;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Web_PanelMouseEnter(TObject *Sender)
{
	// Кнопка ссылка на сайт навели мышкой
	if (Web_Panel->BevelOuter != bvLowered) {
		 Web_Panel->BevelOuter = bvRaised;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Web_PanelMouseLeave(TObject *Sender)
{
	 // Кнопка ссылка на сайт убрали указатель мыши
	if (Web_Panel->BevelOuter == bvRaised) {
		 Web_Panel->BevelOuter = bvNone;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormResize(TObject *Sender)
{
	if (!ComponentState.Contains(csDestroying)) {
		 RefreshGrid(this);
		 CompStr_Edit->Width = Panel2->ClientWidth-CompStr_Edit->Left;
		 CompStr_Label->Width = Panel2->ClientWidth-CompStr_Label->Left;
		 CompStr_Label->Height = 33;
		 Count_Shape->Width = Panel2->ClientWidth-Panel6->ClientWidth-Count_Shape->Left;
		 CloseFilter_Panel->Height = DBMainGrid->ClientHeight;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CloseFilter_PanelMouseEnter(TObject *Sender)
{
	CloseFilter_Panel->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CloseFilter_PanelMouseLeave(TObject *Sender)
{
	CloseFilter_Panel->BevelOuter = bvNone;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CloseFilter_PanelClick(TObject *Sender)
{
	if (CloseFilter_Panel->Caption==">") {
		CloseFilter_Panel->Caption = "<";
		Panel3->Width = 13;
	} else {
		CloseFilter_Panel->Caption=">";
		Panel3->Width = 184;
	}
	FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	FieldsDefTransaction->RollbackRetaining();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Razdel_ComboBoxClick(TObject *Sender)
{
	Filter_MainTable(this);
	Refresh_Fieldsdef(this);
	FormResize(this);
	RefreshFilterPanel(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
	//delete FormFilterAdd;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ApartFilter(TObject *Sender)
{
	// Фильтер
	FilterSQL = "";
	strApartFilter = "";
	Table_Tabledef->RecNo = Razdel_ComboBox->ItemIndex+1;
	String tablename = Table_Tabledef->FieldByName("Tablename")->AsString;
	// Общий фильтр
	// Тип прайса
	int pricetype = 0;
	if (Spr_Panel->BevelOuter==bvLowered) {
		pricetype = 1;
	}
	if (Opr_Panel->BevelOuter==bvLowered) {
		pricetype = 2;
	}
	if (Apr_Panel->BevelOuter==bvLowered) {
		pricetype = 3;
	}
	if (!FilterSQL.IsEmpty()) {
		FilterSQL = FilterSQL + " and ";
	} else {
		FilterSQL = FilterSQL + " where ";
	}
	FilterSQL = FilterSQL + "pricetype = "+(UnicodeString)pricetype;
	// Квартиры предложение APARTSELL
   if (AnsiUpperCase(tablename)=="APARTSELL") {
		// Только с фото
		if (Photo_CheckBox->Checked) {
			strApartFilter = "pics = 1";
		}
		// Кол-во комнат
		if (Room1_CheckBox->Checked || Room2_CheckBox->Checked || Room3_CheckBox->Checked ||
			Room4_CheckBox->Checked || Room5_CheckBox->Checked) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter + "(";
			if (Room1_CheckBox->Checked) {
				strApartFilter = strApartFilter + "rooms=1 or ";
			}
			if (Room2_CheckBox->Checked) {
				strApartFilter = strApartFilter + "rooms=2 or ";
			}
			if (Room3_CheckBox->Checked) {
				strApartFilter = strApartFilter + "rooms=3 or ";
			}
			if (Room4_CheckBox->Checked) {
				strApartFilter = strApartFilter + "rooms=4 or ";
			}
			if (Room5_CheckBox->Checked) {
				strApartFilter = strApartFilter + "rooms>4 or ";
			}
			strApartFilter = strApartFilter + "1=2)";
		}
		// Тип дома
		if (!Typehouse_Label->Caption.IsEmpty()) {
			Table_Typehouse->First();
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter + "(";
			do {
				if (Typehouse_Label->Caption.Pos(Table_Typehouse->FieldByName("SHORTNAME")->AsString)>0) {
					strApartFilter = strApartFilter + "typehouse=" + Table_Typehouse->FieldByName("CODE")->AsString + " OR ";
				}
				Table_Typehouse->Next();
			} while(!Table_Typehouse->Eof);
			strApartFilter = strApartFilter + "1=2)";
		}
		// Материал стен
		if (!Stuffwall_Label->Caption.IsEmpty()) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter + "(";
			Table_Stuffwall->First();
			do {
				if (Stuffwall_Label->Caption.Pos(Table_Stuffwall->FieldByName("SHORTNAME")->AsString)>0) {
					strApartFilter = strApartFilter + "stuffwall=" + Table_Stuffwall->FieldByName("CODE")->AsString + " OR ";
				}
				Table_Stuffwall->Next();
			} while(!Table_Stuffwall->Eof);
			strApartFilter = strApartFilter + "1=2)";
		}
		// Район
		if (!Region_Label->Caption.IsEmpty()) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter + "(";
			Table_Region_short->First();
			do {
				if (Region_Label->Caption.Pos(Table_Region_short->FieldByName("SHORTNAME")->AsString)>0) {
					strApartFilter = strApartFilter + "region=" + Table_Region_short->FieldByName("CODE")->AsString + " OR ";
				}
				Table_Region_short->Next();
			} while(!Table_Region_short->Eof);
			strApartFilter = strApartFilter + "1=2)";
		}
		// Микрорайон
		if (!Mregion_Label->Caption.IsEmpty()) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter + "(";
			Table_mRegion_short->First();
			do {
				if (Mregion_Label->Caption.Pos(Table_mRegion_short->FieldByName("SHORTNAME")->AsString)>0) {
					strApartFilter = strApartFilter + "mregion=" + Table_mRegion_short->FieldByName("CODE")->AsString + " OR ";
				}
				Table_mRegion_short->Next();
			} while(!Table_mRegion_short->Eof);
			strApartFilter = strApartFilter + "1=2)";
		}
	// Обмен
	/*if (!Obmen_Label->Caption.IsEmpty()) {
		if (!strApartFilter.IsEmpty()) {
			strApartFilter = strApartFilter + " and ";
		}
		strApartFilter = strApartFilter + "(";
		Table_Variant->First();
		do {
			if (Obmen_Label->Caption.Pos(Table_Variant->FieldByName("SHORTNAME")->AsString)>0) {
				strApartFilter = strApartFilter + "typehouse=" + Table_Variant->FieldByName("CODE")->AsString + " OR ";
			}
			Table_Variant->Next();
		} while(!Table_Variant->Eof);
		strApartFilter = strApartFilter + "1=2)";
	 } */
		// Предложение
		if (!Sell_Label->Caption.IsEmpty()) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter + "(";
			Table_Variant->First();
			do {
				if (Sell_Label->Caption.Pos(Table_Variant->FieldByName("SHORTNAME")->AsString)>0) {
					strApartFilter = strApartFilter + "variant=" + Table_Variant->FieldByName("CODE")->AsString + " OR ";
				}
				Table_Variant->Next();
			} while(!Table_Variant->Eof);
			strApartFilter = strApartFilter + "1=2)";
		}
		// Этаж
		if (Level_ComboBox->ItemIndex>0) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter + "(";
			// Кроме крайних
			if (Level_ComboBox->ItemIndex==1) {
				strApartFilter = strApartFilter + "\"level\"<>1 and \"level\"<>levels";
			}
			// Кроме первого
			if (Level_ComboBox->ItemIndex==2) {
				strApartFilter = strApartFilter + "\"level\"<>1";
			}
			// Кроме последнего
			if (Level_ComboBox->ItemIndex==3) {
				strApartFilter = strApartFilter + "\"level\"<>levels";
			}
			// Только крайние
			if (Level_ComboBox->ItemIndex==4) {
				strApartFilter = strApartFilter + "\"level\"=1 and \"level\"=levels";
			}
			// Только первый
			if (Level_ComboBox->ItemIndex==5) {
				strApartFilter = strApartFilter + "\"level\"=1";
			}
			// Только последний
			if (Level_ComboBox->ItemIndex==6) {
				strApartFilter = strApartFilter + "\"level\"=levels";
			}
			strApartFilter = strApartFilter + ")";
		}
		// Цена
		if (!Price1_Edit->Text.IsEmpty() || !Price2_Edit->Text.IsEmpty()) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter + "(";
			if (!Price1_Edit->Text.IsEmpty() && Price2_Edit->Text.IsEmpty()) {
				strApartFilter = strApartFilter + "price>="+Price1_Edit->Text;
			}
			if (Price1_Edit->Text.IsEmpty() && !Price2_Edit->Text.IsEmpty()) {
				strApartFilter = strApartFilter + "price<="+Price2_Edit->Text;
			}
			if (!Price1_Edit->Text.IsEmpty() && !Price2_Edit->Text.IsEmpty()) {
				strApartFilter = strApartFilter + "price>="+Price1_Edit->Text +" and price<="+Price2_Edit->Text;
			}
			strApartFilter = strApartFilter + ")";
		}
		// Ипотека
		if (Morgage_CheckBox->Checked) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = "morgage = 1";
		}
		// Доля
		if (Part_CheckBox->Checked) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = "trim(part) is not null";
		}
		if (!Dateto_Edit->Text.IsEmpty()) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			if (Date_ch_RadioButton->Checked) {
				strApartFilter = strApartFilter + "current_date-date_ch<="+Dateto_Edit->Text;
			} else {
				strApartFilter = strApartFilter + "current_date-date_enter<="+Dateto_Edit->Text;
			}
		}
	/*/ Apartsell
	if (!strApartFilter.IsEmpty()) {
		strApartFilter = strApartFilter + " and ";
	}
	strApartFilter = strApartFilter + "pricetype = "+(UnicodeString)pricetype;
	// RoomsSell
	if (!strRoomsSellFilter.IsEmpty()) {
		strRoomsSellFilter = strRoomsSellFilter + " and ";
	}
	strRoomsSellFilter = strRoomsSellFilter + "pricetype = "+(UnicodeString)pricetype;  */
	// Объявления Rent&sale
		if (RS_Panel->BevelOuter == bvLowered) {
			if (!strApartFilter.IsEmpty()) {
			strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter + "agent = 900";
		}
		if (Excl_Panel->BevelOuter == bvLowered || Open_Panel->BevelOuter == bvLowered ||
				Nodog_Panel->BevelOuter == bvLowered) {
			if (!strApartFilter.IsEmpty()) {
				strApartFilter = strApartFilter + " and ";
			}
			strApartFilter = strApartFilter = "(";
			UnicodeString ContractFilter = "";
			// Эксклюзивный договор
			if (Excl_Panel->BevelOuter == bvLowered) {
				if (!ContractFilter.IsEmpty()) {
					ContractFilter = ContractFilter + " or ";
				}
				ContractFilter = ContractFilter + "contract = 15";
			}
			// Открытый договор
			if (Open_Panel->BevelOuter == bvLowered) {
				if (!ContractFilter.IsEmpty()) {
					ContractFilter = ContractFilter + " or ";
				}
				ContractFilter = ContractFilter + "contract = 16";
			}
			// Нет договорных отношений
			if (Nodog_Panel->BevelOuter == bvLowered) {
				if (!ContractFilter.IsEmpty()) {
					ContractFilter = ContractFilter + " or ";
				}
				ContractFilter = ContractFilter + "contract = 17";
			}
			strApartFilter = strApartFilter + ContractFilter + ")";
		}
	}
	//ShowMessage(strApartFilter);

	// Комнаты продложение ROOMSSELL

	Filter_MainTable(this);
	//strApartFilter  Typehouse_Label->Caption
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn1Click(TObject *Sender)
{
	// Кнопка дополнительный фильтр
	if (FormFilterAdd->Left != Panel3->Left - FormFilterAdd->Width) {
		 FormFilterAdd = new TFormFilterAdd(MainForm,MainConn);
		 FormFilterAdd->Left = Panel3->Left - FormFilterAdd->Width;
		 FormFilterAdd->Top = Panel3->Top - 25;
	}
	FormFilterAdd->ShowModal();
	//ShowMessage(*strFilterAdd);
	Filter_MainTable(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Photo_CheckBoxClick(TObject *Sender)
{
	 ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Room1_CheckBoxClick(TObject *Sender)
{
	 ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Room2_CheckBoxClick(TObject *Sender)
{
	 ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Room3_CheckBoxClick(TObject *Sender)
{
	 ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Room4_CheckBoxClick(TObject *Sender)
{
	 ApartFilter(this);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Room5_CheckBoxClick(TObject *Sender)
{
     ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Typehouse_ButtonClick(TObject *Sender)
{
	// Кнопка выбрать тип дома
	UnicodeString * resultstr = new UnicodeString;
	*resultstr = Typehouse_Label->Caption;

	FormSelectBlue = new TFormSelectBlue(this, Table_Typehouse, resultstr);
	FormSelectBlue->Left = Panel3->Left-10;
	FormSelectBlue->Top = Panel3->Top+Typehouse_Button->Top+60;
	FormSelectBlue->ShowModal();
	Typehouse_Label->Caption = *resultstr;

	delete FormSelect;
	delete resultstr;

	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Stuffwall_ButtonClick(TObject *Sender)
{
	// Кнопка выбрать материал стен
	UnicodeString * resultstr = new UnicodeString;
	*resultstr = Stuffwall_Label->Caption;

	FormSelectBlue = new TFormSelectBlue(this, Table_Stuffwall, resultstr);
	FormSelectBlue->Left = Panel3->Left-10;
	FormSelectBlue->Top = Panel3->Top+Stuffwall_Button->Top+60;
	FormSelectBlue->ShowModal();
	Stuffwall_Label->Caption = *resultstr;

	delete FormSelect;
	delete resultstr;
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Region_ButtonClick(TObject *Sender)
{
	// Кнопка район
	UnicodeString * resultstr = new UnicodeString;
	*resultstr = Region_Label->Caption;

	FormSelectBlue = new TFormSelectBlue(this, Table_Region_short, resultstr);
	FormSelectBlue->Left = Panel3->Left-10;
	FormSelectBlue->Top = Panel3->Top+Region_Button->Top+60;
	FormSelectBlue->ShowModal();
	Region_Label->Caption = *resultstr;

	delete FormSelect;
	delete resultstr;
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button6Click(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Sell_ButtonClick(TObject *Sender)
{
	// Кнопка предложение
	UnicodeString * resultstr = new UnicodeString;
	*resultstr = Sell_Label->Caption;

	FormSelectBlue = new TFormSelectBlue(this, Table_Variant, resultstr);
	FormSelectBlue->Left = Panel3->Left-10;
	FormSelectBlue->Top = Panel3->Top+Sell_Button->Top+60;
	FormSelectBlue->ShowModal();
	Sell_Label->Caption = *resultstr;

	delete FormSelect;
	delete resultstr;
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeedButton26Click(TObject *Sender)
{
	//
	Typehouse_Label->Caption = "";
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeedButton27Click(TObject *Sender)
{
	//
	Stuffwall_Label->Caption = "";
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeedButton28Click(TObject *Sender)
{
	//
	Region_Label->Caption = "";
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeedButton29Click(TObject *Sender)
{
	//
	Mregion_Label->Caption = "";
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeedButton30Click(TObject *Sender)
{
	//
	Obmen_Label->Caption = "";
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeedButton31Click(TObject *Sender)
{
	//
	Sell_Label->Caption = "";
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Level_ComboBoxClick(TObject *Sender)
{
    ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Price1_EditExit(TObject *Sender)
{
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Price2_EditExit(TObject *Sender)
{
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Part_CheckBoxClick(TObject *Sender)
{
    ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Morgage_CheckBoxClick(TObject *Sender)
{
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Dateto_EditExit(TObject *Sender)
{
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn2Click(TObject *Sender)
{
	Photo_CheckBox->Checked=false;
	Room1_CheckBox->Checked=false;
	Room2_CheckBox->Checked=false;
	Room3_CheckBox->Checked=false;
	Room4_CheckBox->Checked=false;
	Room5_CheckBox->Checked=false;
	Typehouse_Label->Caption = "";
	Stuffwall_Label->Caption = "";
	Region_Label->Caption = "";
	Mregion_Label->Caption = "";
	Obmen_Label->Caption = "";
	Sell_Label->Caption = "";
	Level_ComboBox->ItemIndex=-1;
	Price1_Edit->Text = "";
	Price2_Edit->Text = "";
	Dateto_Edit->Text = "";

	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RefreshFilterPanel(TObject *Sender)
{
	// Процедура обновления панели фильтра
    Table_Tabledef->RecNo = Razdel_ComboBox->ItemIndex+1;
	String tablename = Table_Tabledef->FieldByName("Tablename")->AsString;
	ApartPurch_Panel->Visible=false;
	ApartSell_Panel->Visible=false;
	RoomsSell_Panel->Visible=false;
	ArendSell_Panel->Visible=false;
	HouseSell_Panel->Visible=false;
	GarageSell_Panel->Visible=false;
	LandSell_Panel->Visible=false;
	CommercSell1_Panel->Visible=false;
	CommercSell2_Panel->Visible=false;
	NewBuildsSell_Panel->Visible=false;
	ArendSellAll_Panel->Visible=false;
	BusinessSell_Panel->Visible=false;
	AbroadSell_Panel->Visible=false;
	if (AnsiUpperCase(tablename)=="APARTSELL") {
		ApartSell_Panel->Visible = true;
		ApartSell_Panel->Left = 9;
		ApartSell_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="APARTPURCH" || AnsiUpperCase(tablename)=="ROOMSPURCH" ||
			AnsiUpperCase(tablename)=="ARENDPURCH" || AnsiUpperCase(tablename)=="HOUSEPURCH" ||
			AnsiUpperCase(tablename)=="GARAGEPURCH" || AnsiUpperCase(tablename)=="COMMERCPURCH") {
		ApartPurch_Panel->Visible = true;
		ApartPurch_Panel->Left = 9;
		ApartPurch_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="ROOMSSELL") {
		RoomsSell_Panel->Visible = true;
		RoomsSell_Panel->Left = 9;
		RoomsSell_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="ARENDSELL") {
		ArendSell_Panel->Visible = true;
		ArendSell_Panel->Left = 9;
		ArendSell_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="HOUSESELL") {
		HouseSell_Panel->Visible = true;
		HouseSell_Panel->Left = 9;
		HouseSell_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="GARAGESELL") {
		GarageSell_Panel->Visible = true;
		GarageSell_Panel->Left = 9;
		GarageSell_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="LANDSELL") {
		LandSell_Panel->Visible = true;
		LandSell_Panel->Left = 9;
		LandSell_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="COMMERCSELL1"|| AnsiUpperCase(tablename)=="COMMERCSELL3"
			|| AnsiUpperCase(tablename)=="COMMERCSELL4" || AnsiUpperCase(tablename)=="COMMERCSELLALL") {
		CommercSell1_Panel->Visible = true;
		CommercSell1_Panel->Left = 9;
		CommercSell1_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="COMMERCSELL2") {
		CommercSell2_Panel->Visible = true;
		CommercSell2_Panel->Left = 9;
		CommercSell2_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="NEWBUILDSSELL") {
		NewBuildsSell_Panel->Visible = true;
		NewBuildsSell_Panel->Left = 9;
		NewBuildsSell_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="ARENDSELLALL") {
		ArendSellAll_Panel->Visible = true;
		ArendSellAll_Panel->Left = 9;
		ArendSellAll_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="BUSINESSSELL") {
		BusinessSell_Panel->Visible = true;
		BusinessSell_Panel->Left = 9;
		BusinessSell_Panel->Top = 19;
	}
	if (AnsiUpperCase(tablename)=="ABROADSELL") {
		AbroadSell_Panel->Visible = true;
		AbroadSell_Panel->Left = 9;
		AbroadSell_Panel->Top = 19;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn4Click(TObject *Sender)
{
	// Поиск по агенту, клиент...
	//if (FormFilterAddSearch->Left != Panel3->Left - FormFilterAdd->Width) {
		 FormFilterAddSearch = new TFormFilterAddSearch(MainForm);
		 FormFilterAddSearch->Left = Panel3->Left - FormFilterAddSearch->Width;
		 FormFilterAddSearch->Top = Panel3->Top + 325;
	//}
	FormFilterAddSearch->ShowModal();
	//ShowMessage(*strFilterAdd);
	//Filter_MainTable(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn7Click(TObject *Sender)
{
	// Кнопка дополнительный фильтр
	if (FormFilterAddArend->Left != Panel3->Left - FormFilterAddArend->Width) {
		 FormFilterAddArend = new TFormFilterAddArend(MainForm,MainConn);
		 FormFilterAddArend->Left = Panel3->Left - FormFilterAddArend->Width;
		 FormFilterAddArend->Top = Panel3->Top - 25;
	}
	FormFilterAddArend->ShowModal();
	//ShowMessage(*strFilterAdd);
	Filter_MainTable(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn6Click(TObject *Sender)
{
	// Кнопка дополнительный фильтр
	if (FormFilterAddRooms->Left != Panel3->Left - FormFilterAddRooms->Width) {
		 FormFilterAddRooms = new TFormFilterAddRooms(MainForm,MainConn);
		 FormFilterAddRooms->Left = Panel3->Left - FormFilterAddRooms->Width;
		 FormFilterAddRooms->Top = Panel3->Top - 25;
	}
	FormFilterAddRooms->ShowModal();
	//ShowMessage(*strFilterAdd);
	Filter_MainTable(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BitBtn9Click(TObject *Sender)
{
	// Кнопка дополнительный фильтр
	if (FormFilterAddHouse->Left != Panel3->Left - FormFilterAddHouse->Width) {
		 FormFilterAddHouse = new TFormFilterAddHouse(MainForm,MainConn);
		 FormFilterAddHouse->Left = Panel3->Left - FormFilterAddHouse->Width;
		 FormFilterAddHouse->Top = Panel3->Top + 160;
	}
	FormFilterAddHouse->ShowModal();
	//ShowMessage(*strFilterAdd);
	Filter_MainTable(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Updateprice_SpeedButtonClick(TObject *Sender)
{
	// Подключение к MySQL
	FormSwap = new TFormSwap(MainForm, MainConn, MainTransaction);
	FormSwap->ShowModal();
	delete FormSwap;
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N10Click(TObject *Sender)
{
	//Сменить статус
	MainTable->Edit();
	if (MainTable->FieldByName("PRICETYPE")->AsInteger==1) {
    	Table_Tabledef->RecNo = Razdel_ComboBox->ItemIndex+1;

		Table_Delrecords->Append();
		Table_Delrecords->FieldByName("GUID")->AsString=TabPricelist_Datasource_Main->DataSet->FieldByName("GUID")->AsString;
		Table_Delrecords->FieldByName("TABLENAME")->AsString = Table_Tabledef->FieldByName("Tablename")->AsString;
		Table_Delrecords->FieldByName("DATEDEL")->AsDateTime=Date();
		MainTable->FieldByName("PRICETYPE")->AsInteger=2;
	} else {
		MainTable->FieldByName("PRICETYPE")->AsInteger=1;
		MainTable->FieldByName("SWSEND")->AsInteger=0;
	}
	 //Фиксация изменений
	MainTable->CheckBrowseMode();
	Table_Delrecords->CheckBrowseMode();
	//Записать изменения в базу данных
	MainTransaction->CommitRetaining();
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N9Click(TObject *Sender)
{
	//Обновить карточку
	if (Reccount_Label->Caption.Trim()=="Записей - 0") {
		Abort();
	}
	int nCurrnum;
	int ncountrec = 0;
	nCurrnum = MainTable->RecNo;
	MainTable->DisableControls();
	MainTable->First();
	while (!MainTable->Eof){
		if (MainTable->FieldByName("CHECK")->AsInteger==1) {
			 ncountrec=ncountrec+1;
		}
		MainTable->Next();
	}
	//ShowMessage(ncountrec);
	AnsiString ds = "Не отмечена ни одна запись.\nОтметить для обновления - F6 или Shift+INS";
	if (ncountrec == 0){
		MessageBox(this->Handle,ds.c_str(),"Обновление",MB_OK | MB_TOPMOST | MB_ICONINFORMATION);
		MainTable->RecNo = nCurrnum;
		MainTable->EnableControls();
		Abort();
	}
	ds = "Обновляется "+(AnsiString)ncountrec+" карточек\nДействительно обновить их?";
	if (MessageBox(this->Handle,ds.c_str(),"Обновление карточки",MB_YESNO | MB_TOPMOST | MB_ICONQUESTION)!=IDYES){
    	MainTable->RecNo = nCurrnum;
		MainTable->EnableControls();
		Abort();
	}
	ds = "Удалить метки?";
	int swmarker = 0;
	if (MessageBox(this->Handle,ds.c_str(),"Обновление карточек",MB_YESNO | MB_TOPMOST | MB_ICONQUESTION)==IDYES){
		swmarker=1;
	}
	MainTable->First();
	while (!MainTable->Eof){
		if (MainTable->FieldByName("CHECK")->AsInteger==1) {
			MainTable->Edit();
			 MainTable->FieldByName("DATE_CH")->AsDateTime=Date()-3;
			 MainTable->FieldByName("SWSEND")->AsInteger=0;
			 if (swmarker==1) {
				 MainTable->FieldByName("CHECK")->AsInteger=0;
			 }
		}
		MainTable->Next();
	}
	//Фиксация изменений
	MainTable->CheckBrowseMode();
	//Записать изменения в базу данных
	MainTransaction->CommitRetaining();
	MainTable->RecNo = nCurrnum;
	MainTable->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	//ShowMessage("create");
	//MainForm->DBMainGrid->DataSource=TabPricelist_Datasource_Main;
	FormStart = new TFormStart(this);
	FormStart->ShowModal();
	delete FormStart;
	if (FormRegOk!=1) {
		//MainForm->Close();
		//Application->Terminate();
		//Application->h
		//exit(0);
		ExitProcess(0);
	}
	//ShowMessage(FormRegOk);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormActivate(TObject *Sender)
{
	//ShowMessage("Метка3");
	//MainForm->DBMainGrid->DataSource=TabPricelist_Datasource_Main;
	//Refresh_Fieldsdef(this);
	//FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N20Click(TObject *Sender)
{
	//ShowMessage("Метка для СМИ");
	int currline;
	//int rcount;
	int cntline=0;
	currline = MainTable->RecNo;
	//rcount = MainTable->RecordCount;
	MainTable->DisableControls();
	/*MainTable->First();
	while(!MainTable->Eof && MainTable->RecNo<=rcount){
		if (MainTable->FieldByName("CHECK")->AsInteger==1) {
			 cntline=cntline+1;
			 MainTable->Edit();
			 MainTable->FieldByName("CHECK")->AsInteger=0;
			 MainTable->FieldByName("SETMARK")->AsInteger=1;
			 MainTable->FieldByName("SWSEND")->AsInteger=0;
		}
		MainTable->Next();
	}
	MainTable->RecNo=currline;
	if (cntline==0) {
		MainTable->Edit();
		MainTable->FieldByName("SETMARK")->AsInteger=1;
		MainTable->FieldByName("SWSEND")->AsInteger=0;
		cntline=cntline+1;
	} */
	MainTable->Edit();
	if (MainTable->FieldByName("SETMARK")->AsInteger==1) {
		MainTable->FieldByName("SETMARK")->AsInteger=0;
	} else {
        MainTable->FieldByName("SETMARK")->AsInteger=1;
    }
	//Фиксация изменений
	MainTable->CheckBrowseMode();
	//Записать изменения в базу данных
	MainTransaction->CommitRetaining();
	Filter_MainTable(this);
	MainTable->RecNo=currline;
	MainTable->EnableControls();
	//ShowMessage(cntline);
	AnsiString ds = "Установлено "+(String)cntline+" меток";
	//ShowMessage(ds);
	//MessageBox(NULL,ds.c_str(),"Установка меток для СМИ",MB_OK | MB_TOPMOST | MB_ICONINFORMATION);
	//MessageBox(NULL,ds.c_str(),"Установка меток для СМИ",MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N59Click(TObject *Sender)
{
	// История карточки
	FormKartHistory = new TFormKartHistory(this,History_datasource);
	FormKartHistory->ShowModal();
	delete FormKartHistory;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Priceru_RadioButtonClick(TObject *Sender)
{
	Refresh_Fieldsdef(this);
	FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Priceye_RadioButtonClick(TObject *Sender)
{
	Refresh_Fieldsdef(this);
	FormResize(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Userch_SpeedButtonClick(TObject *Sender)
{
	//ReConnect = 1;
	MainForm->Visible = false;
	FormReg = new TFormReg(this,MainForm->MainConn);
	FormReg->ShowModal();
	delete FormReg;
	if (FormRegOk!=1) {
		Close();
	}
	MainForm->Visible = true;
	/*while (ReConnect==1){
		ReConnect==0;
		FormReg = new TFormReg(this,MainForm->MainConn);
		FormReg->ShowModal();
		delete FormReg;
	} */
	//Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Help_SpeedButtonClick(TObject *Sender)
{
	// Помощь
	FormHelp = new TFormHelp(this);
	FormHelp->ShowModal();
	delete FormHelp;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::DBMainGridColumns0EditButtonClick(TObject *Sender, bool &Handled)

{
	ShowMessage("click");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBMainGridCellClick(TColumnEh *Column)
{
	//ShowMessage(DBMainGrid->Col);
	//ShowMessage(Column->DisplayText());
	if (Column->FieldName=="PICS" && MainTable->FieldByName("PICS")->AsInteger==1) {
		int * swgall = new int;
		*swgall = 0;
		if (TabPricelist_Datasource_Main->DataSet->FieldByName("PICS")->AsInteger==1) {
			FormGallView = new TFormGallView(MainForm, swgall);
			FormGallView->ShowModal();
			//ShowMessage(*swgall);
			delete FormGallView;
			if (*swgall==1) {
				FormGall = new TFormGall(MainForm);
				FormGall->ShowModal();
				delete FormGall;
			}
			//TabPricelist_Datasource_Main->DataSet->FieldByName("PICS")->AsInteger=0;
		}
	}
	//ShowMessage(Column->FieldName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBMainGridDrawColumnCell(TObject *Sender, const TRect &Rect,
		  int DataCol, TColumnEh *Column, TGridDrawState State)
{
	// Раскраска не подтвержденных объектов
	if (Spr_Panel->BevelOuter==bvLowered) {
		 if (TabPricelist_Datasource_Main->DataSet->FieldByName("PRICE")->AsInteger==0) {
			  if (State.Contains(gdFocused)) {
				  DBMainGrid->Canvas->Font->Color=clWindow;
			  } else {
				  DBMainGrid->Canvas->Font->Color=clGreen;
			  }
			  DBMainGrid->Canvas->FillRect(Rect);
			  DBMainGrid->DefaultDrawColumnCell(Rect,DataCol,Column,State);
		 }
	}
	// Раскраска объектов с рекламацией
	if (Spr_Panel->BevelOuter==bvLowered) {
		 if (!TabPricelist_Datasource_Main->DataSet->FieldByName("REKLTEXT")->IsNull) {
              if (State.Contains(gdFocused)) {
				  DBMainGrid->Canvas->Font->Color=clWindow;
				  DBMainGrid->Canvas->Brush->Color=clHighlight;
			  } else {
				  DBMainGrid->Canvas->Font->Color=clWindowText;
				  DBMainGrid->Canvas->Brush->Color=TColor(0x00D2D2FF);
			  }
			  DBMainGrid->Canvas->FillRect(Rect);
			  DBMainGrid->DefaultDrawColumnCell(Rect,DataCol,Column,State);
		 }
	}
	// Раскраска желтым фоном устаревших объектов
	if (Opr_Panel->BevelOuter==bvLowered) {
		 if (TabPricelist_Datasource_Main->DataSet->FieldByName("DATE_CH")->AsDateTime<Date()-30) {
			  if (State.Contains(gdFocused)) {
				  DBMainGrid->Canvas->Font->Color=clWindow;
			  } else {
				  DBMainGrid->Canvas->Brush->Color=TColor(0x0080FFFF);//$0080FFFF
			  }
			  DBMainGrid->Canvas->FillRect(Rect);
			  DBMainGrid->DefaultDrawColumnCell(Rect,DataCol,Column,State);
         }
    }
	// Раскраска своих объектов в общем прайс-листе CompanyID
	if (Apr_Panel->BevelOuter==bvLowered) {
		//pricetype = 1;
		if (TabPricelist_Datasource_Main->DataSet->FieldByName("AGENT")->AsInteger==CompanyID) {
			if (State.Contains(gdFocused)) {
				DBMainGrid->Canvas->Font->Color=clWindow;
				DBMainGrid->Canvas->Brush->Color=clHighlight;
			} else {
				DBMainGrid->Canvas->Brush->Color=TColor(0x00DEAF61);
			}
			DBMainGrid->Canvas->FillRect(Rect);
			DBMainGrid->DefaultDrawColumnCell(Rect,DataCol,Column,State);
		}
	}
	if (TabPricelist_Datasource_Main->DataSet->FieldByName("SETMARK")->AsInteger==1) {
		// Раскраска объектов помеченных для отправки СМИ
		if (State.Contains(gdFocused)) {
			DBMainGrid->Canvas->Font->Color=clWindow;
			DBMainGrid->Canvas->Brush->Color=clHighlight;
		} else {
            DBMainGrid->Canvas->Font->Color=clWindowText;
			DBMainGrid->Canvas->Brush->Color=TColor(0x00DFF2D7);
		}
		DBMainGrid->Canvas->FillRect(Rect);
		DBMainGrid->DefaultDrawColumnCell(Rect,DataCol,Column,State);
	 }
	 //DBMainGrid->e
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SpeedButton32Click(TObject *Sender)
{
	ApartFilter(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DBMainGridSelectionChanged(TObject *Sender)
{
	/*if (DBMainGrid->SelectedRows->Count!=0) {
    	if (DBMainGrid->SelectedRows->CurrentRowSelected) {
			 ShowMessage(TabPricelist_Datasource_Main->DataSet->RecNo);
		}
	}*/
}
//---------------------------------------------------------------------------

