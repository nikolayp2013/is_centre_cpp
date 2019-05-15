//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormAbonent.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAbonent *FormAbonent;
TIBDatabase * MainConn = NULL;
extern TIBDatabase * MainConn;
TIBTransaction * TransactionAbonent = NULL;
extern TIBTransaction * TransactionAbonent;
TIBTable * Table_Abonent = NULL;
extern TIBTable * Table_Abonent;
TDataSource * Abonent_datasource = NULL;
extern TDataSource * Abonent_datasource;
//---------------------------------------------------------------------------
__fastcall TFormAbonent::TFormAbonent(TComponent* Owner, TIBDatabase * MainConn_local)
	: TForm(Owner)
{
	MainConn = MainConn_local;
	TransactionAbonent = new TIBTransaction(NULL);
	TransactionAbonent->DefaultDatabase = MainConn;

	//������� �� ������� ���������
	Table_Abonent = new TIBTable(NULL);
	Table_Abonent->Database=MainConn;
	Table_Abonent->Transaction=TransactionAbonent;
	Table_Abonent->TableName = "ABONENTS";
	//Table_Abonent->Filter="RAZDEL=52";
	//Table_Abonent->Filtered=TRUE;
	Table_Abonent->Active = true;
	Table_Abonent->FetchAll();

	Abonent_datasource = new TDataSource(NULL);
	Abonent_datasource->DataSet=Table_Abonent;

	// ��������
	Compname_DBEdit->DataSource=Abonent_datasource;
	Compname_DBEdit->DataField="COMPNAME";

	// �������
	Phone_DBEdit->DataSource=Abonent_datasource;
	Phone_DBEdit->DataField="PHONE";

	// �����
	Address_DBEdit->DataSource=Abonent_datasource;
	Address_DBEdit->DataField="ADDRESS";

}
//---------------------------------------------------------------------------
void __fastcall TFormAbonent::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
