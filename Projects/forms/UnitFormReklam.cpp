//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormReklam.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormReklam *FormReklam;
//---------------------------------------------------------------------------
__fastcall TFormReklam::TFormReklam(TComponent* Owner, int pricetype)
	: TForm(Owner)
{
	Memo1->Text=MainForm->MainTable->FieldByName("REKLTEXT")->AsString;
	//MainForm->MainTable->Fields->FindField()
	//ShowMessage(MainForm->MainTable->Fields->Fields[0]->AsString);
	//int swex = 0;
	//Memo1->Text="";
	//ShowMessage(MainForm->MainTable->Fields->Fields[0]->FullName);
	//ShowMessage(MainForm->MainTable->FieldByName("REKLTEXT")->AsString);
	/*for (int i = 0; i < MainForm->MainTable->FieldCount; i++) {
		if (MainForm->MainTable->Fields->Fields[0]->FullName=="SWSEND") {
			 swex = 1;
		}
	}*/
	//ShowMessage(swex);
	//Memo1->Text="";
	if (pricetype!=3) {
		BitBtn1->Visible=false;
		Memo1->ReadOnly=true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormReklam::BitBtn2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormReklam::BitBtn1Click(TObject *Sender)
{
	// ��������
	MainForm->MainTable->Edit();
	MainForm->MainTable->FieldByName("REKLTEXT")->AsString=Memo1->Text;
	FormReklamAdd = new TFormReklamAdd(this);
	FormReklamAdd->ShowModal();
	delete FormReklamAdd;
	Memo1->Text=MainForm->MainTable->FieldByName("REKLTEXT")->AsString;
	//Close();
}
//---------------------------------------------------------------------------

