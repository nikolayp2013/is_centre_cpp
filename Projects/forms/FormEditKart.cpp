//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormEditKart.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IBCustomDataSet"
#pragma link "IBTable"
#pragma link "IBDatabase"
#pragma link "DBLookupListBoxCen"
#pragma link "DBLookupComboBoxCen"
#pragma link "DBLookupComboBoxCentre"
#pragma link "DBLookupListBoxCentre"
#pragma resource "*.dfm"

TFormEdit *FormEdit;
TIBTransaction * OtherTransaction = NULL;
extern TIBTransaction * OtherTransaction;
TDataSource * Region_datasource = NULL;
extern TDataSource * Region_datasource;
// ������� �� ������� ����
TIBDataSet * Table_Streets = NULL;
extern TIBDataSet * Table_Streets;
TDataSource * Streets_datasource = NULL;
extern TDataSource * Streets_datasource;
// ������� �� ������� ������������
TIBTable * Table_Items_10 = NULL;
extern TIBTable * Table_Items_10;
TDataSource * mRegion_datasource = NULL;
extern TDataSource * mRegion_datasource;
// ������� �� ������� ���������
TIBTable * Table_Contract = NULL;
extern TIBTable * Table_Contract;
TDataSource * Contract_datasource = NULL;
extern TDataSource * Contract_datasource;
// ������� �� ������� ����������
TIBTable * Table_Source = NULL;
extern TIBTable * Table_Source;
TDataSource * Source_datasource = NULL;
extern TDataSource * Source_datasource;
// ������� �� ������� ���������
TIBTable * Table_Variant = NULL;
extern TIBTable * Table_Variant;
TDataSource * Variant_datasource = NULL;
extern TDataSource * Variant_datasource;
// ������� �� ������� ����� �����
TIBTable * Table_Typehouse = NULL;
extern TIBTable * Table_Typehouse;
TDataSource * Typehouse_datasource = NULL;
extern TDataSource * Typehouse_datasource;
// ������� �� ������� ���������� ����
TIBTable * Table_Stuffwall = NULL;
extern TIBTable * Table_Stuffwall;
TDataSource * 	Stuffwall_datasource = NULL;
extern TDataSource * Stuffwall_datasource;
// ������� �� ������� ����������
TIBTable * Table_Design = NULL;
extern TIBTable * Table_Design;
TDataSource * Design_datasource = NULL;
extern TDataSource * Design_datasource;
// ������� �� ������� ���������
TIBTable * Table_State = NULL;
extern TIBTable * Table_State;
TDataSource * 	State_datasource = NULL;
extern TDataSource * State_datasource;
// ������� �� ������� ��������� ��������
TIBTable * Table_Swphone = NULL;
extern TIBTable * Table_Swphone;
TDataSource * Swphone_datasource = NULL;
extern TDataSource * Swphone_datasource;
// ������� �� ������� ��������� ��� ���� �������
TIBTable * Table_Nodesan = NULL;
extern TIBTable * Table_Nodesan;
TDataSource * 	Nodesan_datasource = NULL;
extern TDataSource * Nodesan_datasource;
// ������� �� ������� ��������� ������
TIBTable * Table_Varswap = NULL;
extern TIBTable * Table_Varswap;
TDataSource * 	Varswap_datasource = NULL;
extern TDataSource * Varswap_datasource;
// ������� �� ������� ��������
TIBTable * Table_Clients = NULL;
extern TIBTable * Table_Clients;
TDataSource * Clients_Datasource =NULL;
extern TDataSource * Clients_Datasource;
// ������� �� ������� ��������� �������
TIBTable * Table_Clients_kategory1 = NULL;
extern TIBTable * Table_Clients_kategory1;
TIBTable * Table_Clients_kategory2 = NULL;
extern TIBTable * Table_Clients_kategory2;
TDataSource * Clients_Datasource_kategory =NULL;
extern TDataSource * Clients_Datasource_kategory;
// ��� ������
TIBTransaction * TransactionAgent = NULL;
extern TIBTransaction * TransactionAgent;
// ������� �� ������� �������
TIBTable * Table_Agent = NULL;
extern TIBTable * Table_Agent;
TDataSource * Agent_datasource = NULL;
extern TDataSource * Agent_datasource;
// ������� � �������� ��������� � �����
TIBTable * Table_History = NULL;
extern TIBTable * Table_History;
TDataSource * History_datasource = NULL;
extern TDataSource * History_datasource;
// ������� � ������ �������� � �������� ��������� � �����
TIBTable * Table_Items_80 = NULL;
extern TIBTable * Table_History;
// ������� � ��������
TIBTable * Table_reklama = NULL;
extern TIBTable * Table_reklama;

void __fastcall TFormEdit::FormCreate(TObject *Sender)
{
	//--- ����������� �������� ����������� ������ �� ������� ����
	Streets_DBLookupListBox = new TMyDBLookupListBox(this);
	Streets_DBLookupListBox->Parent= this;
	Streets_DBLookupListBox->Name=AnsiString("Streets_DBLookupListBox");
	Streets_DBLookupListBox->Left = 89;
	Streets_DBLookupListBox->Top = 182;
	Streets_DBLookupListBox->Width =160;
	Streets_DBLookupListBox->Height = 17;
	Streets_DBLookupListBox->TabOrder = 9;
    Streets_DBLookupListBox->Visible = False;
	Streets_DBLookupListBox->OnExit = Streets_DBLookupListBoxExit;
	Streets_DBLookupListBox->OnClick = Streets_DBLookupListBoxClick;
	Streets_DBLookupListBox->OnKeyDown = Streets_DBLookupListBoxKeyDown;
	Streets_DBLookupListBox->OnMouseUp = Streets_DBLookupListBoxMouseUp;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//-----  ����������� ��� ������� �����
//---------------------------------------------------------------------------
__fastcall TFormEdit::TFormEdit(TComponent* Owner)
			: TForm(Owner)
{
	if (pricetype==3) {
		Image_Panel->Left = 684;
		Image_Panel->Top = 5;
	}

	OtherTransaction = new TIBTransaction(NULL);
	OtherTransaction->DefaultDatabase = MainForm->MainConn;

	//������� ������� �� ������� �������� (���������)
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	//MainForm->MainTable->Edit();
	//������� �� ������� ������� ��������� �������
	if (!MainForm->Table_Items_8->Active) {
    	MainForm->Table_Items_8->Filtered=TRUE;
		MainForm->Table_Items_8->Active = TRUE;
		MainForm->Table_Items_8->FetchAll();
	}
	Region_datasource = new TDataSource(NULL);
	Region_datasource->DataSet=MainForm->Table_Items_8;
	// - - - - - - - - - - - - - - - - - - - - - -
	// ������� �� ������� ����
	Table_Streets = new TIBDataSet(NULL);
	Table_Streets->Database=MainForm->MainConn;
	Table_Streets->Transaction=OtherTransaction;
	Table_Streets->SelectSQL->Append("select STREETCODE, STREETNAME from STREETS");
	Table_Streets->Active = TRUE;
	Table_Streets->FetchAll();
	Streets_datasource = new TDataSource(NULL);
	Streets_datasource->DataSet=Table_Streets;
	//������� �� ������� ������������
	Table_Items_10 = new TIBTable(NULL);
	Table_Items_10->Database=MainForm->MainConn;
	Table_Items_10->Transaction=OtherTransaction;
	Table_Items_10->TableName = "ITEMS";
	Table_Items_10->Filter="RAZDEL=10";
	Table_Items_10->Filtered=TRUE;
	Table_Items_10->Active = TRUE;
	mRegion_datasource = new TDataSource(NULL);
	mRegion_datasource->DataSet=Table_Items_10;
	mRegion_datasource->DataSet->Last();
	mRegion_datasource->DataSet->First();
	//������� �� ������� ���������
	Table_Contract = new TIBTable(NULL);
	Table_Contract->Database=MainForm->MainConn;
	Table_Contract->Transaction=OtherTransaction;
	Table_Contract->TableName = "ITEMS";
	Table_Contract->Filter="RAZDEL=2";
	Table_Contract->Filtered=TRUE;
	Table_Contract->Active = TRUE;
	Table_Contract->FetchAll();
	Contract_datasource = new TDataSource(NULL);
	Contract_datasource->DataSet=Table_Contract;
	//������� �� ������� ����������
	Table_Source = new TIBTable(NULL);
	Table_Source->Database=MainForm->MainConn;
	Table_Source->Transaction=OtherTransaction;
	Table_Source->TableName = "ITEMS";
	Table_Source->Filter="RAZDEL=55";
	Table_Source->Filtered=TRUE;
	Table_Source->Active = TRUE;
	Table_Source->FetchAll();
	Source_datasource = new TDataSource(NULL);
	Source_datasource->DataSet=Table_Source;
	//������� �� ������� ���������
	Table_Variant = new TIBTable(NULL);
	Table_Variant->Database=MainForm->MainConn;
	Table_Variant->Transaction=OtherTransaction;
	Table_Variant->TableName = "ITEMS";
	Table_Variant->Filter="RAZDEL=3";
	Table_Variant->Filtered=TRUE;
	Table_Variant->Active = TRUE;
	Table_Variant->FetchAll();
	Variant_datasource = new TDataSource(NULL);
	Variant_datasource->DataSet=Table_Variant;
	//������� �� ������� ����� �����
	Table_Typehouse = new TIBTable(NULL);
	Table_Typehouse->Database=MainForm->MainConn;
	Table_Typehouse->Transaction=OtherTransaction;
	Table_Typehouse->TableName = "ITEMS";
	Table_Typehouse->Filter="RAZDEL=9";
	Table_Typehouse->Filtered=TRUE;
	Table_Typehouse->Active = TRUE;
	Table_Typehouse->FetchAll();
	Typehouse_datasource = new TDataSource(NULL);
	Typehouse_datasource->DataSet=Table_Typehouse;
	//������� �� ������� ���������� ����
	Table_Stuffwall = new TIBTable(NULL);
	Table_Stuffwall->Database=MainForm->MainConn;
	Table_Stuffwall->Transaction=OtherTransaction;
	Table_Stuffwall->TableName = "ITEMS";
	Table_Stuffwall->Filter="RAZDEL=6";
	Table_Stuffwall->Filtered=TRUE;
	Table_Stuffwall->Active = TRUE;
	Table_Stuffwall->FetchAll();
	Stuffwall_datasource = new TDataSource(NULL);
	Stuffwall_datasource->DataSet=Table_Stuffwall;
	//������� �� ������� ����������
	Table_Design = new TIBTable(NULL);
	Table_Design->Database=MainForm->MainConn;
	Table_Design->Transaction=OtherTransaction;
	Table_Design->TableName = "ITEMS";
	Table_Design->Filter="RAZDEL=9999";
	Table_Design->Filtered=TRUE;
	Table_Design->Active = TRUE;
	Table_Design->FetchAll();
	Design_datasource = new TDataSource(NULL);
	Design_datasource->DataSet=Table_Design;
	//������� �� ������� ���������
	Table_State = new TIBTable(NULL);
	Table_State->Database=MainForm->MainConn;
	Table_State->Transaction=OtherTransaction;
	Table_State->TableName = "ITEMS";
	Table_State->Filter="RAZDEL=77";
	Table_State->Filtered=TRUE;
	Table_State->Active = TRUE;
	Table_State->FetchAll();
	State_datasource = new TDataSource(NULL);
	State_datasource->DataSet=Table_State;
	//������� �� ������� ��������� ���������
	Table_Swphone = new TIBTable(NULL);
	Table_Swphone->Database=MainForm->MainConn;
	Table_Swphone->Transaction=OtherTransaction;
	Table_Swphone->TableName = "ITEMS";
	Table_Swphone->Filter="RAZDEL=7";
	Table_Swphone->Filtered=TRUE;
	Table_Swphone->Active = TRUE;
	Table_Swphone->FetchAll();
	Swphone_datasource = new TDataSource(NULL);
	Swphone_datasource->DataSet=Table_Swphone;
	//������� �� ������� ��������� ��� ���� �������
	Table_Nodesan = new TIBTable(NULL);
	Table_Nodesan->Database=MainForm->MainConn;
	Table_Nodesan->Transaction=OtherTransaction;
	Table_Nodesan->TableName = "ITEMS";
	Table_Nodesan->Filter="RAZDEL=5";
	Table_Nodesan->Filtered=TRUE;
	Table_Nodesan->Active = TRUE;
	Table_Nodesan->FetchAll();
	Nodesan_datasource = new TDataSource(NULL);
	Nodesan_datasource->DataSet=Table_Nodesan;
	//������� �� ������� ��������� ������
	Table_Varswap = new TIBTable(NULL);
	Table_Varswap->Database=MainForm->MainConn;
	Table_Varswap->Transaction=OtherTransaction;
	Table_Varswap->TableName = "ITEMS";
	Table_Varswap->Filter="RAZDEL=78";
	Table_Varswap->Filtered=TRUE;
	Table_Varswap->Active = TRUE;
	Table_Varswap->FetchAll();
	Varswap_datasource = new TDataSource(NULL);
	Varswap_datasource->DataSet=Table_Varswap;

    //������� ������� � ����� ��������������
	//MainForm->TabPricelist_Datasource_Main->DataSet->Edit();

	//Application->OnMessage = OnApplicationMessage;

	//������� �������� �� ������ ��������
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

	//������� �������� �� ������� ��������� ��������
	Table_Clients_kategory1 = new TIBTable(NULL);
	Table_Clients_kategory1->Database=MainForm->MainConn;
	Table_Clients_kategory1->Transaction=OtherTransaction;
	Table_Clients_kategory1->TableName = "ITEMS";
	Table_Clients_kategory1->Filter = "RAZDEL=15 and MGROUP=0";
	Table_Clients_kategory1->Filtered = true;
	Table_Clients_kategory1->Active=true;
	Table_Clients_kategory1->FetchAll();
	Table_Clients_kategory1->Edit();

	//������� �������� �� ������� ��������� �������� ��� ��. ����
	Table_Clients_kategory2 = new TIBTable(NULL);
	Table_Clients_kategory2->Database=MainForm->MainConn;
	Table_Clients_kategory2->Transaction=OtherTransaction;
	Table_Clients_kategory2->TableName = "ITEMS";
	Table_Clients_kategory2->Filter = "RAZDEL=15 and MGROUP=1";
	Table_Clients_kategory2->Filtered = true;
	Table_Clients_kategory2->Active=true;
	Table_Clients_kategory2->FetchAll();
	Table_Clients_kategory2->Edit();

	//������� ������ DataSource ��� ������� ��������� ��������
	Clients_Datasource_kategory = new TDataSource(NULL);

	//������� ������ DataSource ��� ������� ��������
	Clients_Datasource = new TDataSource(NULL);
	Clients_Datasource->DataSet=Table_Clients;

	// ����� ��������� ���������� �������� � �������
	ProcRefreshClient(this);

	//��� ������
	TransactionAgent = new TIBTransaction(NULL);
	TransactionAgent->DefaultDatabase = MainForm->MainConn;

    //������� �� ������� �������
	Table_Agent = new TIBTable(NULL);
	Table_Agent->Database=MainForm->MainConn;
	Table_Agent->Transaction=TransactionAgent;
	Table_Agent->TableName = "PEOPLE";
	Table_Agent->Active = true;
	Table_Agent->FetchAll();
	Agent_datasource = new TDataSource(NULL);

	//���� �� ���� ������� �������
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

    // ������� �� ������� ����� ��������� � �����
	Table_Items_80 = new TIBTable(NULL);
	Table_Items_80->Database=MainForm->MainConn;
	Table_Items_80->Transaction=OtherTransaction;
	Table_Items_80->TableName = "ITEMS";
	Table_Items_80->Filter="RAZDEL=80";
	Table_Items_80->Filtered=TRUE;
	Table_Items_80->Active = TRUE;
	Table_Items_80->FetchAll();

	// ������� ��������� � �����
	Table_History = new TIBTable(NULL);
	Table_History->Database=MainForm->MainConn;
	Table_History->Transaction=OtherTransaction;
	Table_History->TableName = "KARTHISTORY";
	Table_History->Filter="IDPRICE=";
	Table_History->Filter=Table_History->Filter+MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("ID")->AsString;
	Table_History->Filtered=TRUE;

    TStringField *FKLookup = new TStringField (this);
	FKLookup->Name = "Table_HistoryTYPEACTIONLOOKUP";
	FKLookup->FieldName = "TYPEACTIONLOOKUP";
	FKLookup->FieldKind = fkLookup;
	FKLookup->Size = 200;
	FKLookup->DataSet = Table_History;
	FKLookup->KeyFields = "TYPEACTION"; // �������� ���� ������� �������
	FKLookup->LookupDataSet = Table_Items_80; // ������� ���� ������� ����� �������������
	FKLookup->LookupKeyFields = "CODE"; // �������� ���� �� ������� ������� ����� �������������
	FKLookup->LookupResultField = "FULLNAME"; // ��������������� ���� � ��������������� �������
	FKLookup->ReadOnly = true;

	TIntegerField *FK1 = new TIntegerField (this);
	FK1->Name = "Table_HistoryID";
	FK1->FieldName = "ID";
	FK1->FieldKind = fkData;
	FK1->DataSet = Table_History;

	TIntegerField *FK2 = new TIntegerField (this);
	FK2->Name = "Table_HistoryIDPRICE";
	FK2->FieldName = "IDPRICE";
	FK2->FieldKind = fkData;
	FK2->DataSet = Table_History;

	TDateField *FK3 = new TDateField (this);
	FK3->Name = "MainTableDATE_CH";
	FK3->FieldName = "DATE_CH";
	FK3->FieldKind = fkData;
	FK3->ReadOnly = true;
	FK3->DataSet = Table_History;

	TIntegerField *FK4 = new TIntegerField (this);
	FK4->Name = "Table_HistoryTYPEACTION";
	FK4->FieldName = "TYPEACTION";
	FK4->FieldKind = fkData;
	FK4->DataSet = Table_History;

	TIBStringField *FK5 = new TIBStringField (this);
	FK5->Name = "MainTableFIELDVAL";
	FK5->FieldName = "FIELDVAL";
	FK5->FieldKind = fkData;
	FK5->ReadOnly = true;
	FK5->DataSet = Table_History;

	Table_History->Active = TRUE;
	Table_History->FetchAll();
	History_datasource = new TDataSource(NULL);
	History_datasource->DataSet=Table_History;

	//������� � ��������
	Table_reklama = new TIBTable(NULL);
	Table_reklama->Database=MainForm->MainConn;
	Table_reklama->Transaction=OtherTransaction;
	Table_reklama->TableName = "TABLEREKLAMA";
	Table_reklama->Filter="TABLENAME='APARTSELL'";
	Table_reklama->Filtered=TRUE;
	Table_reklama->Active = TRUE;
	Table_reklama->First();

	if (Table_reklama->RecordCount>0 && !Table_reklama->FieldByName("PICK")->IsNull &&
			!Table_reklama->FieldByName("DATEEND")->IsNull && Table_reklama->FieldByName("DATEEND")->AsDateTime>=Date()) {
		TJPEGImage *jpg = new TJPEGImage();
		try {
			jpg->Assign(Table_reklama->FieldByName("PICK"));
			Image1->Picture->Assign(jpg);
		}
		catch(Exception *ex) {
			Image1->Picture->Assign(Table_reklama->FieldByName("PICK"));
		}
		delete jpg;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormEdit::ProcRefreshClient(TObject *Sender)
{
	Clients_Datasource->DataSet->Active=true;
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

//���������������������������������������������������������������������������
//----------- �������� ��������� � ���� ������
//-----------
//���������������������������������������������������������������������������

void __fastcall TFormEdit::FormShow(TObject *Sender)
{
	//�����
	FormEdit->Region_DBLookComb->ListSource=Region_datasource;
	FormEdit->Region_DBLookComb->ListField="FULLNAME";
	FormEdit->Region_DBLookComb->KeyField="CODE";
	FormEdit->Region_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Region_DBLookComb->DataField="REGION";
	//�����
	FormEdit->Streets_DBLookupListBox->ListSource=Streets_datasource;
	FormEdit->Streets_DBLookupListBox->ListField="STREETNAME";
	FormEdit->Streets_DBLookupListBox->KeyField="STREETNAME";
	FormEdit->Streets_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Streets_DBEdit->DataField="STREET";
	//��������� ���� ��������
	FormEdit->Streets_DBEdit->Color=(TColor)RGB(255,220,220);
	FormEdit->Level_DBEdit->Color=(TColor)RGB(255,220,220);
	FormEdit->Levels_DBEdit->Color=(TColor)RGB(255,220,220);
	FormEdit->Typehouse_DBLookComb->Color=(TColor)RGB(255,220,220);
	FormEdit->Stuffwall_DBLookComb->Color=(TColor)RGB(255,220,220);
	FormEdit->Rooms_DBEdit->Color=(TColor)RGB(255,220,220);
	FormEdit->Totalarea_DBEdit->Color=(TColor)RGB(255,220,220);
	FormEdit->Livearea_DBEdit->Color=(TColor)RGB(255,220,220);
	FormEdit->Kitchenarea_DBEdit->Color=(TColor)RGB(255,220,220);
	//�����������
	FormEdit->Cross_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Cross_DBEdit->DataField="CRSTREET";
	//����������
	FormEdit->mRegion_DBLookComb->ListSource=mRegion_datasource;
	FormEdit->mRegion_DBLookComb->ListField="FULLNAME";
	FormEdit->mRegion_DBLookComb->KeyField="CODE";
	FormEdit->mRegion_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->mRegion_DBLookComb->DataField="MREGION";
	// ���
	FormEdit->House_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->House_DBEdit->DataField="HOUSE";
	FormEdit->House_DBEdit->DataSource->DataSet->FieldByName("HOUSE")->Alignment=taLeftJustify;
	// ������
	FormEdit->Corpus_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Corpus_DBEdit->DataField="CORPUS";
	// ��������
	FormEdit->Flat_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Flat_DBEdit->DataField="FLAT";
	FormEdit->Flat_DBEdit->DataSource->DataSet->FieldByName("FLAT")->Alignment=taLeftJustify;
	// �������
	FormEdit->Contract_DBLookComb->ListSource=Contract_datasource;
	FormEdit->Contract_DBLookComb->ListField="FULLNAME";
	FormEdit->Contract_DBLookComb->KeyField="ID";
	FormEdit->Contract_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Contract_DBLookComb->DataField="CONTRACT";
	// ��������
	FormEdit->Source_DBLookComb->ListSource=Source_datasource;
	FormEdit->Source_DBLookComb->ListField="FULLNAME";
	FormEdit->Source_DBLookComb->KeyField="CODE";
	FormEdit->Source_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Source_DBLookComb->DataField="SOURCED";
	// �������
	FormEdit->Variant_DBLookComb->ListSource=Variant_datasource;
	FormEdit->Variant_DBLookComb->ListField="FULLNAME";
	FormEdit->Variant_DBLookComb->KeyField="CODE";
	FormEdit->Variant_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Variant_DBLookComb->DataField="VARIANT";
	// �������
	FormEdit->Mortgage_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Mortgage_DBCheckBox->DataField="MORGAGE";
	// ����
	FormEdit->Part_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Part_DBEdit->DataField="PART";
	// ����
	FormEdit->Level_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Level_DBEdit->DataField="LEVEL";
	// ���������
	FormEdit->Levels_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Levels_DBEdit->DataField="LEVELS";
	// ��� ����
	FormEdit->Typehouse_DBLookComb->ListSource=Typehouse_datasource;
	FormEdit->Typehouse_DBLookComb->ListField="FULLNAME";
	FormEdit->Typehouse_DBLookComb->KeyField="CODE";
	FormEdit->Typehouse_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Typehouse_DBLookComb->DataField="TYPEHOUSE";
	// �������� ����
	FormEdit->Stuffwall_DBLookComb->ListSource=Stuffwall_datasource;
	FormEdit->Stuffwall_DBLookComb->ListField="FULLNAME";
	FormEdit->Stuffwall_DBLookComb->KeyField="CODE";
	FormEdit->Stuffwall_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Stuffwall_DBLookComb->DataField="STUFFWALL";
	// ��� ���������
	FormEdit->Yearbuild_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Yearbuild_DBEdit->DataField="YEARBUILD";
	// ������
	FormEdit->Security_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Security_DBCheckBox->DataField="SECURITY";
	// ��������
	FormEdit->Konserg_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Konserg_DBCheckBox->DataField="KONSERG";
	// ������. ��. �����.
	FormEdit->Ownex_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Ownex_DBCheckBox->DataField="OWNEX";
	// ������������
	FormEdit->Trash_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Trash_DBCheckBox->DataField="TRASH";
	// ���
	FormEdit->Gaz_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Gaz_DBCheckBox->DataField="GAZ";
	// �������
	FormEdit->Parking_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Parking_DBCheckBox->DataField="PARKING";
	// �����������
	FormEdit->Newbuild_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Newbuild_DBCheckBox->DataField="NEWBUILD";
	// ������
	FormEdit->Rooms_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Rooms_DBEdit->DataField="ROOMS";
	// ������� ������
	FormEdit->iRooms_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->iRooms_DBEdit->DataField="IROOMS";
	// ����������
	FormEdit->Design_DBLookComb->ListSource=Design_datasource;
	FormEdit->Design_DBLookComb->ListField="FULLNAME";
	FormEdit->Design_DBLookComb->KeyField="CODE";
	FormEdit->Design_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Design_DBLookComb->DataField="DESIGN";
	// ���������
	FormEdit->State_DBLookComb->ListSource=State_datasource;
	FormEdit->State_DBLookComb->ListField="FULLNAME";
	FormEdit->State_DBLookComb->KeyField="CODE";
	FormEdit->State_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->State_DBLookComb->DataField="STATE";
	// ��������
	FormEdit->Balcony_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Balcony_DBEdit->DataField="BALCONY";
	// ������
	FormEdit->Loggia_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Loggia_DBEdit->DataField="LOGGIA";
	// ����� �������
	FormEdit->Totalarea_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Totalarea_DBEdit->DataField="TOTALAREA";
	// ����� �������
	FormEdit->Livearea_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Livearea_DBEdit->DataField="LIVEAREA";
	// ������� �����
	FormEdit->Kitchenarea_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Kitchenarea_DBEdit->DataField="KITCHENAREA";
	// �������
	FormEdit->Swphone_DBLookComb->ListSource=Swphone_datasource;
	FormEdit->Swphone_DBLookComb->ListField="FULLNAME";
	FormEdit->Swphone_DBLookComb->KeyField="CODE";
	FormEdit->Swphone_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Swphone_DBLookComb->DataField="SWPHONE";
	// �������
	FormEdit->Nodesan_DBLookComb->ListSource=Nodesan_datasource;
	FormEdit->Nodesan_DBLookComb->ListField="FULLNAME";
	FormEdit->Nodesan_DBLookComb->KeyField="CODE";
	FormEdit->Nodesan_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Nodesan_DBLookComb->DataField="NODESAN";
	// ��������� ������
	FormEdit->Glassbalc_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Glassbalc_DBCheckBox->DataField="GLASSBALC";
	// �����������
	FormEdit->Glasspack_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Glasspack_DBCheckBox->DataField="GLASSPACK";
	// �������������� ����������
	FormEdit->Addinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Addinfo_DBMemo->DataField="ADDINFO";
	// ������� ������
	FormEdit->Varswap_DBLookComb->ListSource=Varswap_datasource;
	FormEdit->Varswap_DBLookComb->ListField="FULLNAME";
	FormEdit->Varswap_DBLookComb->KeyField="ID";
	FormEdit->Varswap_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Varswap_DBLookComb->DataField="VARSWAP";
	// �������
	FormEdit->Doplata_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Doplata_DBCheckBox->DataField="DOPLATA";
	// ���������� �� ������
	FormEdit->Swapinfo_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Swapinfo_DBEdit->DataField="SWAPINFO";
	// ����
	FormEdit->Price_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Price_DBEdit->DataField="PRICE";
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("PRICE")->EditMask="999999;0;_";
	// � �����
	FormEdit->Num_card_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Num_card_DBEdit->DataField="NUM_CARD";
	// �������� ��������, ������������ ����������
	FormEdit->Compstr_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Compstr_DBEdit->DataField="COMPSTR";
	// ������� �������
	FormEdit->ClientPhone_DBEdit->DataSource=Clients_Datasource;
	FormEdit->ClientPhone_DBEdit->DataField="PHONE";
	// ICQ �������
	FormEdit->ClientPager_DBEdit->DataSource=Clients_Datasource;
	FormEdit->ClientPager_DBEdit->DataField="PAGER";
	// E-mail �������
	FormEdit->ClientOperator_DBEdit->DataSource=Clients_Datasource;
	FormEdit->ClientOperator_DBEdit->DataField="OPERATOR";
	// ����� �������
	FormEdit->ClientComp_DBEdit->DataSource=Clients_Datasource;
	FormEdit->ClientComp_DBEdit->DataField="COMP";
	// ��� �������
	FormEdit->ClientName_DBEdit->DataSource=Clients_Datasource;
	FormEdit->ClientName_DBEdit->DataField="NAME";
	// ������� �������
	FormEdit->ClientMobile_DBEdit->DataSource=Clients_Datasource;
	FormEdit->ClientMobile_DBEdit->DataField="MOBILE";
	// �������������� ���������� ��� ������
	FormEdit->Agentinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Agentinfo_DBMemo->DataField="AGENTINFO";
	// ��������� ����������
	FormEdit->Reklinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Reklinfo_DBMemo->DataField="REKLINFO";
	// ������� ������
	FormEdit->AgentMainphone_DBEdit->DataSource=Agent_datasource;
	FormEdit->AgentMainphone_DBEdit->DataField="MAINPHONE";
	// ��������� � ����������� ���
	FormEdit->AgChkname_DBCheckBox->DataSource=Agent_datasource;
	FormEdit->AgChkname_DBCheckBox->DataField="CHKNAME";
	// ��������� � ����������� ����
	FormEdit->AgChkprice_DBCheckBox->DataSource=Agent_datasource;
	FormEdit->AgChkprice_DBCheckBox->DataField="CHKPRICE";
	// ��������� � ����������� ������� �������
	FormEdit->AgChkSot_DBCheckBox->DataSource=Agent_datasource;
	FormEdit->AgChkSot_DBCheckBox->DataField="CHKSOT";
	// ��������� � ����������� e-mail
	FormEdit->AgChke_mail_DBCheckBox->DataSource=Agent_datasource;
	FormEdit->AgChke_mail_DBCheckBox->DataField="CHKE_MAIL";
	// ��������� � ����������� ��������� �������
	FormEdit->AgChkmain_DBCheckBox->DataSource=Agent_datasource;
	FormEdit->AgChkmain_DBCheckBox->DataField="CHKMAIN";
	// ��������� � ����������� �������������� �������
	FormEdit->AgChkadd_DBCheckBox->DataSource=Agent_datasource;
	FormEdit->AgChkadd_DBCheckBox->DataField="CHKADD";
	// ���� ����� �����
	FormEdit->Date_enter_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Date_enter_DBEdit->DataField="DATE_ENTER";
	// ���� �������������
	FormEdit->Date_ch_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	FormEdit->Date_ch_DBEdit->DataField="DATE_CH";
}
//---------------------------------------------------------------------------


void __fastcall TFormEdit::PageControl1DrawTab(TCustomTabControl *Control, int TabIndex,
          const TRect &Rect, bool Active)
{
	TPageControl *control = (TPageControl*)Control;
	//control->Canvas->Brush->Color = clRed; // ����������� ����!!!
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

void __fastcall TFormEdit::ButtonSaveClick(TObject *Sender)
{
    // ������ ���������
	String ds = "";
	if (Streets_DBEdit->Text.IsEmpty()) {
		ds = ds+"- �� ������� ����� \n";
		//break;
	}
	if (Levels_DBEdit->Text.IsEmpty()) {
		ds = ds+"- �� ������� ��������� ���� \n";
	}
	if (Price_DBEdit->Text.IsEmpty() || Price_DBEdit->Text=="0") {
		ds = ds+"- �� ������� ���� \n";
	}
	if (Totalarea_DBEdit->Text.IsEmpty() || Livearea_DBEdit->Text.IsEmpty() || Kitchenarea_DBEdit->Text.IsEmpty()) {
		ds = ds+"- �� ������� ������� \n";
	}
	if (Typehouse_DBLookComb->Text.IsEmpty()) {
		ds = ds+"- �� ������ ��� ���� \n";
	}
	if (Stuffwall_DBLookComb->Text.IsEmpty()) {
		ds = ds+"- �� ������ �������� ���� \n";
	}
	if (Agent_ComboBox->Text.IsEmpty()) {
		ds = ds+"- �� ������ ����� \n";
	}
	if (!ds.IsEmpty()) {
		 MessageBox(NULL,ds.c_str(),"�������� ����������",MB_OK | MB_TOPMOST | MB_ICONSTOP);
	} else {
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("DATE_CH")->AsDateTime=Date();
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("SWSEND")->AsInteger=0;
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("REKLTEXT")->AsString="";
		ProcSave(this);
		MainForm->TabPricelist_Datasource_Main->DataSet->Refresh();
		MainForm->TabPricelist_Datasource_Main->DataSet->Active=True;
	//������� ������� � ����� ��������������
		MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
		Close();
    }
}
//---------------------------------------------------------------------------


//���������������������������������������������������������������������������
//---------- ���� ��������, ���������� �� ������ �� ������� ����
//----------
//���������������������������������������������������������������������������
//---------- ������ -- ����� �������� ��������� ������ ����

//---------- ��������� ����������� ��� ������� �� ���� "�����"
void __fastcall TFormEdit::Streets_DBEditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	Table_Streets->Locate("Streetname", FormEdit->Streets_DBEdit->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
	 FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
	 if (Key==40) {  // ������� "������� �����"
		FormEdit->Streets_DBLookupListBox->ListSource->DataSet->Next();
		FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
		FormEdit->Streets_DBLookupListBox->SetFocus();
	 }
	 if (Key==38) { // ������� "������� ����"
		FormEdit->Streets_DBLookupListBox->ListSource->DataSet->Prior();
		FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
		FormEdit->Streets_DBLookupListBox->SetFocus();
	 }
	 if (Key==13) { // ������� ENTER
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
		FormEdit->Streets_DBLookupListBox->Visible=FALSE;
		FormEdit->Region_DBLookComb->SetFocus();
	 }
}
//---------------------------------------------------------------------------


//----- ��������� ����������� ��� ������� (�����) ����� ������� ���� �� ���� "�����"
void __fastcall TFormEdit::Streets_DBLookupListBoxClick(TObject *Sender)
{
	 if (FormEdit->Streets_DBLookupListBox->Top==98) {
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
	 }
	 if (FormEdit->Streets_DBLookupListBox->Top==124) {
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
	 }
}
//---------------------------------------------------------------------------


//------------ ��������� ����������� ����� ���� "�����" �������� �����
void __fastcall TFormEdit::Streets_DBEditEnter(TObject *Sender)
{
	if (FormEdit->Streets_DBEdit->Text.Length()==0) {
		FormEdit->Streets_DBLookupListBox->ListSource->DataSet->First();
	} else
	{
		Table_Streets->Locate("Streetname", FormEdit->Streets_DBEdit->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
	}
	FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
	FormEdit->Streets_DBLookupListBox->Height=134;
	FormEdit->Streets_DBLookupListBox->Top=98;
	FormEdit->Streets_DBLookupListBox->Visible=TRUE;
	FormEdit->Streets_DBLookupListBox->Enabled=TRUE;

	//---- ������������ ��������� ����������
	char s[64];
	GetKeyboardLayoutName(s);
	//����� ������� �������� ������� ���� (�������� ����)
	if (s!="00000419") {
		 //LoadKeyboardLayout("00000409", KLF_ACTIVATE);
		//Eng���
		LoadKeyboardLayout("00000419", KLF_ACTIVATE);
		//�������
	}
}
//---------------------------------------------------------------------------


//------------ ��������� ����������� ����� ���� "�����" ������ �����
void __fastcall TFormEdit::Streets_DBEditExit(TObject *Sender)
{
	if (!FormEdit->Streets_DBLookupListBox->Focused()){
		if (FormEdit->Streets_DBEdit->Text.Length()!=0) {
			FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
				FormEdit->Streets_DBLookupListBox->KeyValue;
		}
		FormEdit->Streets_DBLookupListBox->Visible=FALSE;
	}
}
//---------------------------------------------------------------------------


//--------- ��������� ����������� ����� � �������� �� ������� ���� ������ �������
void __fastcall TFormEdit::Streets_DBLookupListBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	 if (Key==13) {
		if (FormEdit->Streets_DBLookupListBox->Top==98) {
			FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
				FormEdit->Streets_DBLookupListBox->KeyValue;
		}
		if (FormEdit->Streets_DBLookupListBox->Top==124) {
			FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
				FormEdit->Streets_DBLookupListBox->KeyValue;
		}
		FormEdit->Streets_DBLookupListBox->Visible=FALSE;
		FormEdit->Region_DBLookComb->SetFocus();
	 }
}
//---------------------------------------------------------------------------


//-------- ��������� ����������� ����� � �������� �� ������� ���� ������ ������� ����
void __fastcall TFormEdit::Streets_DBLookupListBoxMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (FormEdit->Streets_DBLookupListBox->Top==98) {
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
	}
	if (FormEdit->Streets_DBLookupListBox->Top==124) {
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
	}
	FormEdit->Streets_DBLookupListBox->Visible=FALSE;
}
//---------------------------------------------------------------------------


//-------- ��������� ����������� ����� � �������� �� ������� ���� ������ �����
void __fastcall TFormEdit::Streets_DBLookupListBoxExit(TObject *Sender)
{
	if (FormEdit->Streets_DBLookupListBox->Top==98) {
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
	}
	if (FormEdit->Streets_DBLookupListBox->Top==124) {
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
	}
	FormEdit->Streets_DBLookupListBox->Visible=FALSE;
}
//---------------------------------------------------------------------------


//-------- ��������� ����������� ����� ���� "�����������" �������� �����
void __fastcall TFormEdit::Cross_DBEditEnter(TObject *Sender)
{
	if (FormEdit->Cross_DBEdit->Text.Length()==0) {
		FormEdit->Streets_DBLookupListBox->ListSource->DataSet->First();
	} else
	{
		Table_Streets->Locate("Streetname", FormEdit->Cross_DBEdit->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
	}
	FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
	FormEdit->Streets_DBLookupListBox->Height=134;
	FormEdit->Streets_DBLookupListBox->Top=124;
	FormEdit->Streets_DBLookupListBox->Visible=TRUE;

	//---- ������������ ��������� ����������
	char s[64];
	GetKeyboardLayoutName(s);
	//����� ������� �������� ������� ���� (�������� ����)
	if (s!="00000419") {
		 //LoadKeyboardLayout("00000409", KLF_ACTIVATE);
		//Eng���
		LoadKeyboardLayout("00000419", KLF_ACTIVATE);
		//�������
	}
}
//---------------------------------------------------------------------------


//-------- ��������� ���������� ����� � ���� "�����������" ������ �������
void __fastcall TFormEdit::Cross_DBEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	//loPartialKey - ������������ ���������� ����������
	//loCaseInsensitive - ������������������ � ��������
	 Table_Streets->Locate("Streetname", FormEdit->Cross_DBEdit->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
	 FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
	 if (Key==40) {   //----- ������� ������� �����
		FormEdit->Streets_DBLookupListBox->ListSource->DataSet->Next();
		FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
		FormEdit->Streets_DBLookupListBox->SetFocus();
	 }
	 if (Key==38) {  //---- ������� ������� ����
		FormEdit->Streets_DBLookupListBox->ListSource->DataSet->Prior();
		FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
		FormEdit->Streets_DBLookupListBox->SetFocus();
	 }
	 if (Key==13) { //--- ������� ����
		FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			FormEdit->Streets_DBLookupListBox->KeyValue;
		FormEdit->Streets_DBLookupListBox->Visible=FALSE;
		FormEdit->Region_DBLookComb->SetFocus();
	 }
}
//---------------------------------------------------------------------------


//-------- ��������� ���������� ����� ���� "�����������" ������ �����
void __fastcall TFormEdit::Cross_DBEditExit(TObject *Sender)
{
	if (!FormEdit->Streets_DBLookupListBox->Focused()){
		if (FormEdit->Cross_DBEdit->Text.Length()!=0) {
			FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
				FormEdit->Streets_DBLookupListBox->KeyValue;
		}
		FormEdit->Streets_DBLookupListBox->Visible=FALSE;
	}
}
//---------------------------------------------------------------------------

//--- ��������� ��������� ���������
void __fastcall TFormEdit::OnApplicationMessage(TMsg & Msg, bool & Handled)
{
   if (Msg.message == WM_MOUSEWHEEL)
	 {
		if (ActiveControl->ClassNameIs("TDBLookupComboBoxCentre"))
		{
			short zDelta = HIWORD(Msg.wParam);
			if (zDelta !=0)
			{
			  Msg.lParam = 0;
			  Msg.message = WM_KEYDOWN;
			   if (zDelta >0 )
				 {
					((TDBLookupComboBoxCentre*)ActiveControl)->DataList->ListSource->DataSet->Prior();
				 }
				 else
				 {
					((TDBLookupComboBoxCentre*)ActiveControl)->DataList->ListSource->DataSet->Next();
				 }
			}
		}
		if (ActiveControl->ClassNameIs("TDBEdit") &&
				!strcmp(((TDBEdit*)ActiveControl)->Name.c_str(),"Streets_DBEdit"))
		{
			short zDelta = HIWORD(Msg.wParam);
			if (zDelta !=0)
			{
			  Msg.lParam = 0;
			  Msg.message = WM_KEYDOWN;
			   if (zDelta >0 )
				 {
					FormEdit->Streets_DBLookupListBox->ListSource->DataSet->Prior();
					//SendMessage(FormEdit->Streets_DBLookupListBox->Handle, WM_VSCROLL, SB_LINEUP, 0);
				 }
				 else
				 {
					FormEdit->Streets_DBLookupListBox->ListSource->DataSet->Next();
					//SendMessage(FormEdit->Streets_DBLookupListBox->Handle, WM_VSCROLL, SB_LINEDOWN, 0);
				 }
				 FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
				 FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
					FormEdit->Streets_DBLookupListBox->KeyValue;
			}
		}

		if (ActiveControl->ClassNameIs("TDBEdit") &&
				!strcmp(((TDBEdit*)ActiveControl)->Name.c_str(),"Cross_DBEdit"))
		{
			short zDelta = HIWORD(Msg.wParam);
			if (zDelta !=0)
			{
			  Msg.lParam = 0;
			  Msg.message = WM_KEYDOWN;
			   if (zDelta >0 )
				 {
					FormEdit->Streets_DBLookupListBox->ListSource->DataSet->Prior();
					//SendMessage(FormEdit->Streets_DBLookupListBox->Handle, WM_VSCROLL, SB_LINEUP, 0);
				 }
				 else
				 {
					FormEdit->Streets_DBLookupListBox->ListSource->DataSet->Next();
					//SendMessage(FormEdit->Streets_DBLookupListBox->Handle, WM_VSCROLL, SB_LINEDOWN, 0);
				 }
				 FormEdit->Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
				 FormEdit->Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
				 	FormEdit->Streets_DBLookupListBox->KeyValue;

			}
		}
  }
}

//---------------------------------------------------------------------------
//-------- ����� ����� �������� ������ �� ������� ����
//---------------------------------------------------------------------------
//------- �����


void __fastcall TFormEdit::SpeedButton2Click(TObject *Sender)
{
	// ������ ������

	// ���� �����������
	if (swinsert==1) {
		MainForm->TabPricelist_Datasource_Main->DataSet->Delete();
		MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
		//MainTransaction->CommitRetaining();
	}
	MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
	//�������� ��������� � ���� ������
	//MainTransaction->RollbackRetaining();
	FormEdit->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::Button6Click(TObject *Sender)
{
	FormGall = new TFormGall(FormEdit);
	FormGall->ShowModal();
	delete FormGall;
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::Button4Click(TObject *Sender)
{
	FormMap = new TFormMap(FormEdit,MainForm->TabPricelist_Datasource_Main);
	FormMap->ShowModal();
	delete FormMap;
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::SpeedButton1Click(TObject *Sender)
{
	long * retval = new long;
	*retval = 0;
	FormKlients = new TFormKlients(MainForm, MainForm->MainConn, retval);
	FormKlients->ShowModal();
	if (*retval!=0) {
		 MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger=*retval;
	}
	// ����� ��������� ���������� �������� � �������
	ProcRefreshClient(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::SpeedButton3Click(TObject *Sender)
{
    MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger=0;
	// ����� ��������� ���������� �������� � �������
	ProcRefreshClient(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::Button5Click(TObject *Sender)
{
	// ������ �����
	if (!MainForm->TabPricelist_Datasource_Main->DataSet->Bof) {
		ProcSave(this);
		MainForm->TabPricelist_Datasource_Main->DataSet->Prior();
		MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
		// ����� ��������� ���������� �������� � �������
		ProcRefreshClient(this);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::Button3Click(TObject *Sender)
{
	// ������ ������
	if (!MainForm->TabPricelist_Datasource_Main->DataSet->Eof) {
		ProcSave(this);
		MainForm->TabPricelist_Datasource_Main->DataSet->Next();
		MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
		// ����� ��������� ���������� �������� � �������
		ProcRefreshClient(this);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::ProcSave(TObject *Sender)
{
	//�������� ���������
	//MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
	//�������� ��������� � ���� ������
	//MainTransaction->CommitRetaining();
	//MainForm->MainTable->Post();
	//MainForm->TabPricelist_Datasource_Main->DataSet->Post();

	MainForm->MainTable->Post();
	MainForm->MainTable->ApplyUpdates(0);
	MainForm->IBTransaction1->CommitRetaining();

	//MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
	//MainForm->MainTable->ApplyUpdates(0);
	//MainForm->MainConn->Transactions->CommitRetaining(0);
	//MainForm->IBTransaction1->CommitRetaining();
	//������� ����� ������
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::RefreshAgent(TObject *Sender)
{
	// ���������� �������� �� ������
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

void __fastcall TFormEdit::Agent_ComboBoxClick(TObject *Sender)
{
     // ����� ������ �� ������
	 Agent_datasource->DataSet->Active=true;
	 Agent_datasource->DataSet->First();
	 Agent_datasource->DataSet->MoveBy(Agent_ComboBox->ItemIndex);
	 MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->AsInteger=
		 Agent_datasource->DataSet->FieldByName("ID")->AsInteger;
	 RefreshAgent(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::Button1Click(TObject *Sender)
{
	// �������������� �������� ������
	FormAgKartEdit = new TFormAgKartEdit(this,Agent_datasource,MainForm->MainConn,TransactionAgent);
	FormAgKartEdit->ShowModal();
	delete FormAgKartEdit;
}
//---------------------------------------------------------------------------

void __fastcall TFormEdit::Button2Click(TObject *Sender)
{
	// ������� ������ � ��������
	FormKartHistory = new TFormKartHistory(this,History_datasource);
	FormKartHistory->ShowModal();
	delete FormKartHistory;
}
//---------------------------------------------------------------------------

