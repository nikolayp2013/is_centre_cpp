//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormReestrAbonent.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormReestrAbonent *FormReestrAbonent;
TIBDatabase * MainConn = NULL;
extern TIBDatabase * MainConn;
TIBTransaction * AgentTransaction = NULL;
extern TIBTransaction * AgentTransaction;
TIBDataSet * Table_Abonents_loc = NULL;
extern TIBDataSet * Table_Abonents_loc;
TDataSource * Agent_Datasource =NULL;
extern TDataSource * Agent_Datasource;
//---------------------------------------------------------------------------
__fastcall TFormReestrAbonent::TFormReestrAbonent(TComponent* Owner, TIBDatabase * MainConn_local)
	: TForm(Owner)
{
	MainConn = MainConn_local;

	//Создать объект транзакций
	AgentTransaction = new TIBTransaction(NULL);
	AgentTransaction->DefaultDatabase = MainConn;

    //Создать табличку со списко абонентов
	/*Table_Abonents_loc = new TIBTable(NULL);
	Table_Abonents_loc->Database=MainConn;
	Table_Abonents_loc->Transaction=AgentTransaction;
	Table_Abonents_loc->TableName = "ABONENTS";
	//Table_Abonents_loc->Filter = "COMPID=";
	//char * tmpint = new char[17];
	//itoa(OwnerCode,tmpint,10);
	//Table_Abonents_loc->Filter = Table_Abonents_loc->Filter+tmpint;
	//delete tmpint;
	//Table_Abonents_loc->Filtered = true;
	Table_Abonents_loc->Active=true;
	Table_Abonents_loc->FetchAll(); */

	Table_Abonents_loc = new TIBDataSet(NULL);
	Table_Abonents_loc->Database=MainConn;
	Table_Abonents_loc->Transaction=AgentTransaction;
	Table_Abonents_loc->SelectSQL->Clear();
	//char * tmpint = new char[17];
	//itoa(OwnerCode,tmpint,10);
	Table_Abonents_loc->SelectSQL->Append("select * from abonents order by compid");
	//delete tmpint;
	//Table_Abonents_loc->InsertSQL->Append("insert into CLIENTS (ID,NAME,COMPID,KATID,COMP,PHONE,HOUSE,MOBILE,PAGER,OPERATOR,MISC,WHO,DOCUMENTS,RS,BANK,KS,INN,BIK,OKONH,OKPO,STATUS,FACE) values (:ID,:NAME,:COMPID,:KATID,:COMP,:PHONE,:HOUSE,:MOBILE,:PAGER,:OPERATOR,:MISC,:WHO,:DOCUMENTS,:RS,:BANK,:KS,:INN,:BIK,:OKONH,:OKPO,:STATUS,:FACE)");
	//Table_Clients->ModifySQL->Append("update CLIENTS set NAME=:NAME,COMPID=:COMPID,KATID=:KATID,COMP=:COMP,PHONE=:PHONE,HOUSE=:HOUSE,MOBILE=:MOBILE,PAGER=:PAGER,OPERATOR=:OPERATOR,MISC=:MISC,WHO=:WHO,DOCUMENTS=:DOCUMENTS,RS=:RS,BANK=:BANK,KS=:KS,INN=:INN,BIK=:BIK,OKONH=:OKONH,OKPO=:OKPO,STATUS=:STATUS,FACE=:FACE where ID = :OLD_ID");
	//Table_Clients->DeleteSQL->Append("delete from CLIENTS where ID = :OLD_ID");
	Table_Abonents_loc->RefreshSQL->Append("select * from abonents where ID = :ID");
	//Table_Clients->Filtered = true;
	Table_Abonents_loc->Active = TRUE;
	Table_Abonents_loc->FetchAll();
	//Table_Abonents_loc->Edit();

	//Создать объект DataSource
	Agent_Datasource = new TDataSource(NULL);
	Agent_Datasource->DataSet=Table_Abonents_loc;
	Agent_Datasource->DataSet->Active=TRUE;

	DBGrid1->DataSource = Agent_Datasource;
}
//---------------------------------------------------------------------------
void __fastcall TFormReestrAbonent::ProcFind(TObject *Sender)
{
	// Процедура поиска
	Table_Abonents_loc->Active = false;
	Table_Abonents_loc->SelectSQL->Clear();
	String tmpSQL = "";
	if (!Compid_Edit->Text.IsEmpty()) {
		 tmpSQL = tmpSQL + " where compid=" + Compid_Edit->Text;
	}
	if (!Compname_Edit->Text.IsEmpty()) {
		 if (!tmpSQL.IsEmpty()) {
			tmpSQL = tmpSQL + " and upper(compname collate PXW_CYRL) like '%" + AnsiUpperCase(Compname_Edit->Text) +"%'";
		 } else {
			tmpSQL = tmpSQL + " where upper(compname collate PXW_CYRL) like '%" + AnsiUpperCase(Compname_Edit->Text) +"%'";
		 }
	}
	if (!Phone_Edit->Text.IsEmpty()) {
		 if (!tmpSQL.IsEmpty()) {
			tmpSQL = tmpSQL + " and phone like '%" + Phone_Edit->Text +"%'";
		 } else {
			tmpSQL = tmpSQL + " where phone like '%" + Phone_Edit->Text +"%'";
         }
	}
	if (!Address_Edit->Text.IsEmpty()) {
		 if (!tmpSQL.IsEmpty()) {
			tmpSQL = tmpSQL + " and upper(address collate PXW_CYRL) like '%" + AnsiUpperCase(Address_Edit->Text) +"%'";
		 } else {
			tmpSQL = tmpSQL + " where upper(address collate PXW_CYRL) like '%" + AnsiUpperCase(Address_Edit->Text) +"%'";
		 }
	}
	Table_Abonents_loc->SelectSQL->Append("select * from abonents "+tmpSQL+" order by compid");
	Table_Abonents_loc->Active = TRUE;
	Table_Abonents_loc->Refresh();
	//Table_Abonents_loc->FetchAll();
	//Agent_Datasource->DataSet->Active=TRUE;

	//DBGrid1->DataSource = Agent_Datasource;
	/*if (Agent_Datasource->DataSet->Locate("COMPID",Compid_Edit->Text.c_str(),TLocateOptions()
			<< loPartialKey	<<loCaseInsensitive)) {
		 Abort();
	}
	if (Agent_Datasource->DataSet->Locate("COMPNAME",Compname_Edit->Text.c_str(),TLocateOptions()
			<< loPartialKey	<<loCaseInsensitive)) {
		 Abort();
	}
	if (Agent_Datasource->DataSet->Locate("PHONE",Phone_Edit->Text.c_str(),TLocateOptions()
			<< loPartialKey	<<loCaseInsensitive)) {
		 Abort();
	}
	if (Agent_Datasource->DataSet->Locate("ADDRESS",Address_Edit->Text.c_str(),TLocateOptions()
			<< loPartialKey	<<loCaseInsensitive)) {
	} */
}
//---------------------------------------------------------------------------

void __fastcall TFormReestrAbonent::Compid_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	ProcFind(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormReestrAbonent::Compname_EditKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	ProcFind(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormReestrAbonent::Phone_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	ProcFind(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormReestrAbonent::Address_EditKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	ProcFind(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormReestrAbonent::Compname_EditEnter(TObject *Sender)
{
	//MainForm->SetLanguage(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormReestrAbonent::Address_EditEnter(TObject *Sender)
{
	//MainForm->SetLanguage(this);
}
//---------------------------------------------------------------------------


void __fastcall TFormReestrAbonent::Panel1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	 Panel1->BevelOuter =  bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TFormReestrAbonent::Panel1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	Panel1->BevelOuter =  bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TFormReestrAbonent::Panel1Click(TObject *Sender)
{
	Compid_Edit->Text 	= "";
	Compname_Edit->Text = "";
	Phone_Edit->Text 	= "";
	Address_Edit->Text 	= "";
	ProcFind(this);
}
//---------------------------------------------------------------------------

