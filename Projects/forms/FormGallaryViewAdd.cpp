//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormGallaryViewAdd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGallViewAdd *FormGallViewAdd;
//TIBDatabase * MainConn = NULL;
//extern TIBDatabase * MainConn;
//TIBTransaction * MainTransaction = NULL;
//extern TIBTransaction * MainTransaction;
//TIBDataSet * MainTable = NULL;
//extern TIBDataSet * MainTable;
// ������� �� ������� ����������
TIBTable * Table_Pics = NULL;
extern TIBTable * Table_Pics;
int * swgall;
extern int * swgall;
TIBTransaction * OtherTransaction = NULL;
extern TIBTransaction * OtherTransaction;
//---------------------------------------------------------------------------
__fastcall TFormGallViewAdd::TFormGallViewAdd(TComponent* Owner, int * swgall_local)
	: TForm(Owner)
{
	swgall = swgall_local;

    OtherTransaction = new TIBTransaction(NULL);
	OtherTransaction->DefaultDatabase = MainForm->MainConn;

	//������� �������� �� ������� ��������
	Table_Pics = new TIBTable(NULL);
	Table_Pics->Database=MainForm->MainConn;
	Table_Pics->Transaction=OtherTransaction;
	Table_Pics->TableName = "TABLE_PICS";
	Table_Pics->Filter = "IDPARENT='"+MainForm->MainTable->FieldByName("GUID")->AsString+"'";
	Table_Pics->Filtered = true;
	Table_Pics->Active=true;
	Table_Pics->FetchAll();
	Table_Pics->First();
	RefreshPics(this);
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::RefreshPics(TObject *Sender)
{
	// ���������� ��������
	if (Table_Pics->RecordCount>0 && !Table_Pics->FieldByName("PICS")->IsNull) {
		Image1->Visible = true;
		Label2->Visible = false;
		Label3->Visible = false;
		Label4->Visible = false;
		Label5->Visible = false;
		TJPEGImage *jpg = new TJPEGImage();
		try {
			jpg->Assign(Table_Pics->FieldByName("PICS"));
			Image1->Picture->Assign(jpg);
		}
		catch(Exception *ex) {
			Image1->Picture->Assign(Table_Pics->FieldByName("PICS"));
		}
		delete jpg;
	} else {
		 Image1->Visible = false;
		 Label2->Visible = true;
		 Label3->Visible = true;
		 Label4->Visible = true;
		 Label5->Visible = true;
	}
	if (Table_Pics->RecNo==1) {
		Label7->Visible=false;
	} else {
		Label7->Visible=true;
	}
	if (Table_Pics->RecordCount==Table_Pics->RecNo) {
		 Label8->Visible = false;
	} else {
        Label8->Visible = true;
	}
	//ShowMessage(Table_Pics->RecordCount);
	//ShowMessage(Table_Pics->RecNo);
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::Label1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::Label1MouseEnter(TObject *Sender)
{
	Label1->Font->Color = clRed;
	//IdServerIOHandlerSSLOpenSSL1->I
	//IdSSLIOHandlerSocketOpenSSL1->H
	//SQLConnection1->H
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::Label1MouseLeave(TObject *Sender)
{
	Label1->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TFormGallViewAdd::Label7MouseEnter(TObject *Sender)
{
	Label7->Font->Color = clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::Label7MouseLeave(TObject *Sender)
{
	Label7->Font->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::Label8MouseEnter(TObject *Sender)
{
	Label8->Font->Color = clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::Label8MouseLeave(TObject *Sender)
{
	Label8->Font->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::Label6MouseEnter(TObject *Sender)
{
	 Label6->Font->Color = clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::Label6MouseLeave(TObject *Sender)
{
	 Label6->Font->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TFormGallViewAdd::Label6Click(TObject *Sender)
{
	*swgall = 1;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormGallViewAdd::Label7Click(TObject *Sender)
{
	if (!Table_Pics->Bof) {
		 Table_Pics->Prior();
	}
	RefreshPics(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormGallViewAdd::Label8Click(TObject *Sender)
{
	if (!Table_Pics->Eof) {
		 Table_Pics->Next();
	}
	RefreshPics(this);
}
//---------------------------------------------------------------------------

