//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormConvert.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IBCustomDataSet"
#pragma link "IBDatabase"
#pragma link "IBTable"
#pragma resource "*.dfm"
TFormConv *FormConv;
TIBDatabase * MainConnConv = NULL;
extern TIBDatabase * MainConnConv;
TIBTransaction * MainTransactionConv = NULL;
extern TIBTransaction * MainTransactionConv;
TIBTable * Table_convert = NULL;
extern TIBTable * Table_convert;
TDataSource * Conv_datasource = NULL;
extern TDataSource * Conv_datasource;
//---------------------------------------------------------------------------
__fastcall TFormConv::TFormConv(TComponent* Owner, TIBDatabase * MainConnLoc,
			TIBTransaction * MainTransactionLoc) : TForm(Owner)
{
	MainConnConv = MainConnLoc;
	MainTransactionConv = MainTransactionLoc;
	Table_convert = new TIBTable(NULL);
	Table_convert->Database=MainConnConv;
	Table_convert->Transaction=MainTransactionConv;
	//Table_convert->TableName = "ABONENTS";
	//Table_convert->TableName = "APARTSELL";
	//Table_convert->TableName = "STREETS";
	Table_convert->TableName = "AGENTS";
	Table_convert->Active = TRUE;
	Conv_datasource = new TDataSource(NULL);
	Conv_datasource->DataSet=Table_convert;
}
//---------------------------------------------------------------------------
void __fastcall TFormConv::Button1Click(TObject *Sender)
{
	//MessageBox( 0, DataSource1->DataSet->FieldByName("ZFULLNAME")->AsString.c_str(), "������", MB_OK );
	//���� �� ���� ������� �������
	 DataSource1->DataSet->First();
	 do {
		Conv_datasource->DataSet->InsertRecord(ARRAYOFCONST((
		DataSource1->DataSet->FieldByName("ZVCOMP")->AsString,
		DataSource1->DataSet->FieldByName("ZVAGENT")->AsString,
		DataSource1->DataSet->FieldByName("ZVAGPH")->AsString)));
		DataSource1->DataSet->Next();
	 } while(!DataSource1->DataSet->Eof);
	 /*do {
		Conv_datasource->DataSet->InsertRecord(ARRAYOFCONST(("",
		DataSource1->DataSet->FieldByName("ZID")->AsString,
		DataSource1->DataSet->FieldByName("ZRAIONID1")->AsString,
		DataSource1->DataSet->FieldByName("ZRAIONID2")->AsString,
		DataSource1->DataSet->FieldByName("ZRAIONID3")->AsString,
		DataSource1->DataSet->FieldByName("ZRAIONID4")->AsString,
		DataSource1->DataSet->FieldByName("ZRAIONID5")->AsString,
		DataSource1->DataSet->FieldByName("ZNAME")->AsString)));
		DataSource1->DataSet->Next();
	 } while(!DataSource1->DataSet->Eof); */
	 /*Conv_datasource->DataSet->Active=true;
	 do {
		Conv_datasource->DataSet->InsertRecord(ARRAYOFCONST((-1,
		"",
		DataSource1->DataSet->FieldByName("ZID")->AsInteger,
		"",
		DataSource1->DataSet->FieldByName("ZSHORTNAME")->AsString,
		DataSource1->DataSet->FieldByName("ZFULLNAME")->AsString,
		DataSource1->DataSet->FieldByName("ZRAZDEL")->AsInteger,
		DataSource1->DataSet->FieldByName("ZGROUP")->AsInteger,
		DataSource1->DataSet->FieldByName("ZFOX")->AsInteger,
		"",
		"")));
		DataSource1->DataSet->Next();
	 } while(!DataSource1->DataSet->Eof); */
	 /*Conv_datasource->DataSet->Active=true;
	 do {
		Conv_datasource->DataSet->InsertRecord(ARRAYOFCONST((-1,
		DataSource1->DataSet->FieldByName("ZCOMPNAME")->AsString,
		DataSource1->DataSet->FieldByName("ZPHONE")->AsString,
		DataSource1->DataSet->FieldByName("ZADDRESS")->AsString,
		DataSource1->DataSet->FieldByName("ZGROUPID")->AsInteger,
		DataSource1->DataSet->FieldByName("ZID")->AsInteger)));
		DataSource1->DataSet->Next();
	 } while(!DataSource1->DataSet->Eof);
	 Conv_datasource->DataSet->Active=true; */
	 /*do {
		Conv_datasource->DataSet->InsertRecord(ARRAYOFCONST((
		DataSource1->DataSet->FieldByName("ZID")->AsInteger,
		DataSource1->DataSet->FieldByName("ZNAMEFIELDS")->AsString,
		DataSource1->DataSet->FieldByName("ZDESCRIPTION")->AsString,
		DataSource1->DataSet->FieldByName("ZBASENAME")->AsString,
		DataSource1->DataSet->FieldByName("ZBASEID")->AsInteger,
		DataSource1->DataSet->FieldByName("ZPROPERTIES")->AsInteger)));
		DataSource1->DataSet->Next();
	 } while(!DataSource1->DataSet->Eof);*/
	 /*do {
		Conv_datasource->DataSet->InsertRecord(ARRAYOFCONST((-1,
		DataSource1->DataSet->FieldByName("ZCOMPNAME")->AsString,
		DataSource1->DataSet->FieldByName("ZPHONE")->AsString,
		DataSource1->DataSet->FieldByName("ZADDRESS")->AsString,
		DataSource1->DataSet->FieldByName("ZGROUPID")->AsInteger,
		DataSource1->DataSet->FieldByName("ZID")->AsInteger)));
		DataSource1->DataSet->Next();
	 } while(!DataSource1->DataSet->Eof);  */
	 /*do {
		Conv_datasource->DataSet->Append();
		Conv_datasource->DataSet->FieldByName("ID")->AsString="-1";
		Conv_datasource->DataSet->FieldByName("PRICETYPE")->AsString="1";
		Conv_datasource->DataSet->FieldByName("AGENT")->AsString=DataSource1->DataSet->FieldByName("ZCOMPID")->AsString;
		Conv_datasource->DataSet->FieldByName("NUM_CARD")->AsString=DataSource1->DataSet->FieldByName("ZCARDNUM")->AsString;
		Conv_datasource->DataSet->FieldByName("DATE_CH")->AsString=DataSource1->DataSet->FieldByName("ZDATECOR")->AsString;
		Conv_datasource->DataSet->FieldByName("REGION")->AsString=DataSource1->DataSet->FieldByName("ZRAIONID")->AsString;
		Conv_datasource->DataSet->FieldByName("MREGION")->AsString=DataSource1->DataSet->FieldByName("ZMRAIONID")->AsString;
		Conv_datasource->DataSet->FieldByName("STREET")->AsString=DataSource1->DataSet->FieldByName("ZSTREETID")->AsString;
		Conv_datasource->DataSet->FieldByName("ROOMS")->AsString=DataSource1->DataSet->FieldByName("ZROOMS")->AsString;
		Conv_datasource->DataSet->FieldByName("IROOMS")->AsString=DataSource1->DataSet->FieldByName("ZIZROOMS")->AsString;
		Conv_datasource->DataSet->FieldByName("TYPEHOUSE")->AsString=DataSource1->DataSet->FieldByName("ZTHID")->AsString;
		Conv_datasource->DataSet->FieldByName("LEVEL")->AsString=DataSource1->DataSet->FieldByName("ZSTAGE")->AsString;
		Conv_datasource->DataSet->FieldByName("LEVELS")->AsString=DataSource1->DataSet->FieldByName("ZHSTAGE")->AsString;
		Conv_datasource->DataSet->FieldByName("STUFFWALL")->AsString=DataSource1->DataSet->FieldByName("ZMATERID")->AsString;
		Conv_datasource->DataSet->FieldByName("TOTALAREA")->AsString=DataSource1->DataSet->FieldByName("ZALL")->AsString;
		Conv_datasource->DataSet->FieldByName("LIVEAREA")->AsString=DataSource1->DataSet->FieldByName("ZLIVING")->AsString;
		Conv_datasource->DataSet->FieldByName("KITCHENAREA")->AsString=DataSource1->DataSet->FieldByName("ZKITCHEN")->AsString;
		Conv_datasource->DataSet->FieldByName("NODESAN")->AsString=DataSource1->DataSet->FieldByName("ZWCID")->AsString;
		Conv_datasource->DataSet->FieldByName("SWPHONE")->AsString=DataSource1->DataSet->FieldByName("ZPHONEID")->AsString;
		Conv_datasource->DataSet->FieldByName("VARIANT")->AsString=DataSource1->DataSet->FieldByName("ZSELLTYPEID")->AsString;
		Conv_datasource->DataSet->FieldByName("PRICE")->AsString=DataSource1->DataSet->FieldByName("ZPRICE")->AsString;
		Conv_datasource->DataSet->FieldByName("CRSTREET")->AsString=DataSource1->DataSet->FieldByName("ZVSTRCROSS")->AsString;
		Conv_datasource->DataSet->FieldByName("CORPUS")->AsString=DataSource1->DataSet->FieldByName("ZCORPUS")->AsString;
		Conv_datasource->DataSet->FieldByName("HOUSE")->AsString=DataSource1->DataSet->FieldByName("ZHOUSE")->AsString;
		Conv_datasource->DataSet->FieldByName("FLAT")->AsString=DataSource1->DataSet->FieldByName("ZAPART")->AsString;
		DataSource1->DataSet->Next();
	 } while(!DataSource1->DataSet->Eof); */
}
//---------------------------------------------------------------------------

void __fastcall TFormConv::Button2Click(TObject *Sender)
{
	//�������� ��������� � ���� ������
	MainTransactionConv->Commit();
	//������� ����� ������
	Conv_datasource->DataSet->Active=True;
}
//---------------------------------------------------------------------------

void __fastcall TFormConv::FormShow(TObject *Sender)
{
	FormConv->DBGrid2->DataSource= Conv_datasource;
	//Conv_datasource->DataSet->Active=TRUE;
}
//---------------------------------------------------------------------------

void __fastcall TFormConv::FormCreate(TObject *Sender)
{
	//TLabel *container= new TLabel(this);
	//container->Parent = FormConv;
	//container->visible=True;
	/*TDBLookupListBox *lbl;
	lbl=new TDBLookupListBox(this);
        lbl->Parent=this;
		//lbl->Caption=AnsiString("Label")+AnsiString(1);
        lbl->Top=1*20;
		lbl->Left=10; */
}
//---------------------------------------------------------------------------

