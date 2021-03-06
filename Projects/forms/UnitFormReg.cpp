//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormReg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IBCustomDataSet"
#pragma link "IBTable"
#pragma resource "*.dfm"
TFormReg *FormReg;
TIBDatabase * MainConn = NULL;
extern TIBDatabase * MainConn;
TIBTransaction * MainTransaction = NULL;
extern TIBTransaction * MainTransaction;
TIBTable * Table_People = NULL;
extern TIBTable * Table_People;
//---------------------------------------------------------------------------
__fastcall TFormReg::TFormReg(TComponent* Owner, TIBDatabase * MainConn_local)
	: TForm(Owner)
{
	MainConn = MainConn_local;
	//������� ������ ����������
	MainTransaction = new TIBTransaction(NULL);
	MainTransaction->DefaultDatabase = MainConn;

	//������� �������� �� ������ ���������
	Table_People = new TIBTable(NULL);
	Table_People->Database=MainConn;
	Table_People->Transaction=MainTransaction;
	Table_People->TableName = "PEOPLE";
	Table_People->Filter = "COMPID="+(String)CompanyID;
	Table_People->Filtered = true;
	Table_People->Active=true;
	Table_People->FetchAll();

	ComboBox1->Items->Clear();
	if (CompanyID==0) {
		ComboBox1->Items->Add("��������");
	} else {
		//
		Table_People->First();
		while (!Table_People->Eof){
			ComboBox1->Items->Add(Table_People->FieldByName("FULLNAME")->AsString);
			Table_People->Next();
		}
	}
	ComboBox1->ItemIndex=1;
}
//---------------------------------------------------------------------------

void __fastcall TFormReg::BitBtn1Click(TObject *Sender)
{
	// �������� ������
	Table_People->RecNo = ComboBox1->ItemIndex+1;
	if (Edit1->Text==Table_People->FieldByName("PASSWORDV")->AsString) {
    	FormRegOk = 1;
		//ShowMessage("������ �����");
		//FormStart->Visible=false;
		//FormReg->Visible=false;
		//FormStart->WindowState = wsMinimized;
		//FormReg->WindowState = wsMinimized;
		//FormStart->Width=1;
		//FormStart->Top=1;
		//MainForm = new TMainForm(this);
		//MainForm->ShowModal();
		//delete MainForm;
		Close();
	} else {
        FormRegOk = 0;
    }

}
//---------------------------------------------------------------------------

void __fastcall TFormReg::BitBtn2Click(TObject *Sender)
{
	// ������ ������
	FormRegOk = 0;
	Close();
}
//---------------------------------------------------------------------------

