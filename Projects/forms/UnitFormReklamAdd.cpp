//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormReklamAdd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormReklamAdd *FormReklamAdd;
TIBQuery * QueryTab = NULL;
extern TIBQuery * QueryTab;
TIBTransaction * MainTransaction = NULL;
extern TIBTransaction * MainTransaction;
//---------------------------------------------------------------------------
__fastcall TFormReklamAdd::TFormReklamAdd(TComponent* Owner)
	: TForm(Owner)
{
	MainTransaction = new TIBTransaction(NULL);
	MainTransaction->DefaultDatabase = MainForm->MainConn;

	QueryTab = new TIBQuery(NULL);
	QueryTab->Database=MainForm->MainConn;
	QueryTab->Transaction = MainTransaction;
	QueryTab->SQL->Clear();
	QueryTab->SQL->Add("select * from abonents where compid="+(String)CompanyID);
	QueryTab->Open();

	//Memo1->Text = "";
	Memo1->Text=Date().DateString()+"-"+QueryTab->FieldByName("COMPNAME")->AsString+
		QueryTab->FieldByName("ADDRESS")->AsString;
	Memo1->Lines->Append("");
	//Memo1->Text.LastChar();
}
//---------------------------------------------------------------------------
void __fastcall TFormReklamAdd::BitBtn2Click(TObject *Sender)
{
	// ��������
	MainForm->MainTable->Edit();
	if (!MainForm->MainTable->FieldByName("REKLTEXT")->AsString.IsEmpty()) {
		MainForm->MainTable->FieldByName("REKLTEXT")->AsString =
			MainForm->MainTable->FieldByName("REKLTEXT")->AsString + "\r\n";
	}
	MainForm->MainTable->FieldByName("REKLTEXT")->AsString =
		MainForm->MainTable->FieldByName("REKLTEXT")->AsString + Memo1->Text;
	MainForm->MainTable->FieldByName("SWSEND")->AsInteger = 0;
	MainForm->MainTable->CheckBrowseMode();
	//MainForm->MainTable->Transaction->CommitRetaining();

	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormReklamAdd::BitBtn1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------