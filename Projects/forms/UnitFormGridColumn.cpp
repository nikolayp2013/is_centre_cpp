//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormGridColumn.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGridColumn *FormGridColumn;
TIBDatabase * MainConn = NULL;
extern TIBDatabase * MainConn;
TIBTransaction * GridTransaction = NULL;
extern TIBTransaction * GridTransaction;
// ������� �� ������� �����
TIBTable * Table_Fieldsdef = NULL;
extern TIBTable * Table_Fieldsdef;
TDataSource * 	Fieldsdef_datasource = NULL;
extern TDataSource * Fieldsdef_datasource;
//���� � ���������
//AnsiString sPath = ExtractFileDir(Application->ExeName);
TIniFile *Ini = new TIniFile(sPath+"\\Propfiles\\fieldsdef.ini");
int swview;
extern int swview;
UnicodeString tablename;
extern UnicodeString tablename;
UnicodeString strcaption;
extern UnicodeString strcaption;
int tableid;
extern int tableid;
//---------------------------------------------------------------------------
__fastcall TFormGridColumn::TFormGridColumn(TComponent* Owner, TIBDatabase * MainConn_local, int swview_local,
		UnicodeString tablename_local, int tableid_local)
	: TForm(Owner)
{
	MainConn = MainConn_local;
	tableid = tableid_local;

	//������� ������ ����������
	GridTransaction = new TIBTransaction(NULL);
	GridTransaction->DefaultDatabase = MainConn;

	//������� �������� �� ������� �����
	Table_Fieldsdef = new TIBTable(NULL);
	Table_Fieldsdef->Database=MainConn;
	Table_Fieldsdef->Transaction=GridTransaction;
	Table_Fieldsdef->TableName = "FIELDSDEF";
	Table_Fieldsdef->Filter = "TABLEID="+(UnicodeString)tableid;
	Table_Fieldsdef->Filtered = true;
	Table_Fieldsdef->Active=true;
	Table_Fieldsdef->FetchAll();

	Fieldsdef_datasource = new TDataSource(NULL);
	Fieldsdef_datasource->DataSet=Table_Fieldsdef;
	Width_DBEdit->DataSource = Fieldsdef_datasource;
	Width_DBEdit->DataField = "MANWIDTH";

	strcaption="��������� �������: ";
	 swview = swview_local;
	 tablename=tablename_local;
	 if (AnsiUpperCase(tablename)=="APARTSELL") {
		 strcaption = strcaption + "��������";
	 }
	 if (swview==1) {
		 strcaption = strcaption + ", ��������� ���";
	 }
	 if (swview==2) {
		 strcaption = strcaption + ", ���������� ���";
	 }
	 if (swview==3) {
		 strcaption = strcaption + ", ��� ���";
	 }

	//���� �� ���� ������� �������
	 Table_Fieldsdef->First();
	 do {
		Fields_CheckListBox->Items->Add(Table_Fieldsdef->FieldByName("CAPTFULL")->AsString);

		if (Ini->ReadString(tablename+"_check_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"0")==1)
			Fields_CheckListBox->Checked[Table_Fieldsdef->RecNo-1] = true;
		Table_Fieldsdef->Edit();
		Table_Fieldsdef->FieldByName("MANWIDTH")->AsString =
			Ini->ReadString(tablename+"_width_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"2");

		Table_Fieldsdef->Next();
	 } while(!Table_Fieldsdef->Eof);
	 Table_Fieldsdef->First();

	 Width_DBEdit->DataSource->DataSet->FieldByName("MANWIDTH")->Alignment=taLeftJustify;
}
//---------------------------------------------------------------------------
void __fastcall TFormGridColumn::Fields_CheckListBoxClick(TObject *Sender)
{
	 Table_Fieldsdef->First();
	 Table_Fieldsdef->MoveBy(Fields_CheckListBox->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TFormGridColumn::Commit_ButtonClick(TObject *Sender)
{
	// ������ "���������"
	int currno = Table_Fieldsdef->RecNo;
	//���� �� ���� ������� �������
	 Table_Fieldsdef->First();
	 do {
		if (Fields_CheckListBox->Checked[Table_Fieldsdef->RecNo-1])
			Ini->WriteString(tablename+"_check_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"1");
		else Ini->WriteString(tablename+"_check_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"0");
		Ini->WriteString(tablename+"_width_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,
			Table_Fieldsdef->FieldByName("MANWIDTH")->AsString);

		Table_Fieldsdef->Next();
	 } while(!Table_Fieldsdef->Eof);
	 Table_Fieldsdef->RecNo = currno;
}
//---------------------------------------------------------------------------

void __fastcall TFormGridColumn::FormClose(TObject *Sender, TCloseAction &Action)

{
    GridTransaction->RollbackRetaining();
}
//---------------------------------------------------------------------------

void __fastcall TFormGridColumn::Button3Click(TObject *Sender)
{
    // ������ ������
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormGridColumn::Button2Click(TObject *Sender)
{
	// ������ ��
	Commit_ButtonClick(this);
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormGridColumn::Button1Click(TObject *Sender)
{
	// ������� "��-���������"
	int currno = Table_Fieldsdef->RecNo;
	UnicodeString fname_width = "FIELDWIDTH";
	UnicodeString fname_check = "FCHECK";
	if (swview==2) {
	   fname_width = "FWIDTH_CLIENT";
	   fname_check = "FCHECK_CLIENT";
	}
	if (swview==3) {
	   fname_width = "FWIDTH_DSP";
	   fname_check = "FCHECK_DSP";
	}
    //���� �� ���� ������� �������
	 Table_Fieldsdef->First();
	 do {
		Table_Fieldsdef->Edit();
		Table_Fieldsdef->FieldByName("MANWIDTH")->AsInteger = Table_Fieldsdef->FieldByName(fname_width)->AsInteger;
		Table_Fieldsdef->FieldByName("MANCHECK")->AsInteger = Table_Fieldsdef->FieldByName(fname_check)->AsInteger;

		if (Table_Fieldsdef->FieldByName(fname_check)->AsInteger==1){
			Fields_CheckListBox->Checked[Table_Fieldsdef->RecNo-1] = true;
			Ini->WriteString(tablename+"_check_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"1");
		} else {
			Fields_CheckListBox->Checked[Table_Fieldsdef->RecNo-1] = false;
			Ini->WriteString(tablename+"_check_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,"0");
        }

		Ini->WriteString(tablename+"_width_"+"_"+(UnicodeString)swview,Table_Fieldsdef->FieldByName("FIELDNAME")->AsString,
			Table_Fieldsdef->FieldByName("MANWIDTH")->AsString);

		Table_Fieldsdef->Next();
	 } while(!Table_Fieldsdef->Eof);
	 Table_Fieldsdef->RecNo=currno;
}
//---------------------------------------------------------------------------

void __fastcall TFormGridColumn::FormShow(TObject *Sender)
{
	FormGridColumn->Caption = strcaption;
}
//---------------------------------------------------------------------------

