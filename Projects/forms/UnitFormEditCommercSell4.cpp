//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormEditCommercSell4.h"

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

TFormEditCommercSell4 *FormEditCommercSell4;
TIBTransaction * OtherTransaction = NULL;
extern TIBTransaction * OtherTransaction;
// ������� �� ������� �������
TIBTable * Table_Items_8 = NULL;
extern TIBTable * Table_Items_8;
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
// ������� ��������
TIBTable * Table_Parking = NULL;
extern TIBTable * Table_Parking;
TDataSource * 	Parking_datasource = NULL;
extern TDataSource * Parking_datasource;
// ������� ����� ������ �����������
TIBTable * Table_Commplace = NULL;
extern TIBTable * Table_Commplace;
TDataSource * 	Commplace_datasource = NULL;
extern TDataSource * Commplace_datasource;
// ������� ��������
TIBTable * Table_Internet = NULL;
extern TIBTable * Table_Internet;
TDataSource * 	Internet_datasource = NULL;
extern TDataSource * Internet_datasource;
// ������� ���������
TIBTable * Table_Placement = NULL;
extern TIBTable * Table_Placement;
TDataSource * 	Placement_datasource = NULL;
extern TDataSource * Placement_datasource;
// ������� �������
TIBTable * Table_Profile = NULL;
extern TIBTable * Table_Profile;
TDataSource * 	Profile_datasource = NULL;
extern TDataSource * Profile_datasource;
// ������� �� ������� ���������
TIBTable * Table_Items = NULL;
extern TIBTable * Table_Items;

void __fastcall TFormEditCommercSell4::FormCreate(TObject *Sender)
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
__fastcall TFormEditCommercSell4::TFormEditCommercSell4(TComponent* Owner)
			: TForm(Owner)
{
   /*	OtherTransaction = new TIBTransaction(NULL);
	OtherTransaction->DefaultDatabase = MainForm->MainConn;

	//������� ������� �� ������� �������� (���������)
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	//������� �� ������� ������� ��������� �������
	Table_Items_8 = new TIBTable(NULL);
	Table_Items_8->Database=MainForm->MainConn;
	Table_Items_8->Transaction=OtherTransaction;
	Table_Items_8->TableName = "ITEMS";
	Table_Items_8->Filter="RAZDEL=8";
	Table_Items_8->Filtered=TRUE;
	Table_Items_8->Active = TRUE;
	Table_Items_8->FetchAll();
	Region_datasource = new TDataSource(NULL);
	Region_datasource->DataSet=Table_Items_8;
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
	//������� ����� �����������
	Table_Items_10 = new TIBTable(NULL);
	Table_Items_10->Database=MainForm->MainConn;
	Table_Items_10->Transaction=OtherTransaction;
	Table_Items_10->TableName = "ITEMS";
	Table_Items_10->Filter="RAZDEL=48";
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
	//������� ���� ������������
	Table_Typehouse = new TIBTable(NULL);
	Table_Typehouse->Database=MainForm->MainConn;
	Table_Typehouse->Transaction=OtherTransaction;
	Table_Typehouse->TableName = "ITEMS";
	Table_Typehouse->Filter="RAZDEL=47";
	Table_Typehouse->Filtered=TRUE;
	Table_Typehouse->Active = TRUE;
	Table_Typehouse->FetchAll();
	Typehouse_datasource = new TDataSource(NULL);
	Typehouse_datasource->DataSet=Table_Typehouse;
	//������� ��������
	Table_Parking = new TIBTable(NULL);
	Table_Parking->Database=MainForm->MainConn;
	Table_Parking->Transaction=OtherTransaction;
	Table_Parking->TableName = "ITEMS";
	Table_Parking->Filter="RAZDEL=71";
	Table_Parking->Filtered=TRUE;
	Table_Parking->Active = TRUE;
	Table_Parking->FetchAll();
	Parking_datasource = new TDataSource(NULL);
	Parking_datasource->DataSet=Table_Parking;
	//������� ���������
	Table_Placement = new TIBTable(NULL);
	Table_Placement->Database=MainForm->MainConn;
	Table_Placement->Transaction=OtherTransaction;
	Table_Placement->TableName = "ITEMS";
	Table_Placement->Filter="RAZDEL=73";
	Table_Placement->Filtered=TRUE;
	Table_Placement->Active = TRUE;
	Table_Placement->FetchAll();
	Placement_datasource = new TDataSource(NULL);
	Placement_datasource->DataSet=Table_Placement;
	//������� �������
	Table_Profile = new TIBTable(NULL);
	Table_Profile->Database=MainForm->MainConn;
	Table_Profile->Transaction=OtherTransaction;
	Table_Profile->TableName = "ITEMS";
	Table_Profile->Filter="RAZDEL=74";
	Table_Profile->Filtered=TRUE;
	Table_Profile->Active = TRUE;
	Table_Profile->FetchAll();
	Profile_datasource = new TDataSource(NULL);
	Profile_datasource->DataSet=Table_Profile;
	//������� ����� ������ �����������
	Table_Commplace = new TIBTable(NULL);
	Table_Commplace->Database=MainForm->MainConn;
	Table_Commplace->Transaction=OtherTransaction;
	Table_Commplace->TableName = "ITEMS";
	Table_Commplace->Filter="RAZDEL=75";
	Table_Commplace->Filtered=TRUE;
	Table_Commplace->Active = TRUE;
	Table_Commplace->FetchAll();
	Commplace_datasource = new TDataSource(NULL);
	Commplace_datasource->DataSet=Table_Commplace;
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
	Table_State->Filter="RAZDEL=72";
	Table_State->Filtered=TRUE;
	Table_State->Active = TRUE;
	Table_State->FetchAll();
	State_datasource = new TDataSource(NULL);
	State_datasource->DataSet=Table_State;
	//������� �� ������� ���������
	Table_Swphone = new TIBTable(NULL);
	Table_Swphone->Database=MainForm->MainConn;
	Table_Swphone->Transaction=OtherTransaction;
	Table_Swphone->TableName = "ITEMS";
	Table_Swphone->Filter="RAZDEL=21";
	Table_Swphone->Filtered=TRUE;
	Table_Swphone->Active = TRUE;
	Table_Swphone->FetchAll();
	Swphone_datasource = new TDataSource(NULL);
	Swphone_datasource->DataSet=Table_Swphone;
	//������� �� ������� ��������� ������
	Table_Nodesan = new TIBTable(NULL);
	Table_Nodesan->Database=MainForm->MainConn;
	Table_Nodesan->Transaction=OtherTransaction;
	Table_Nodesan->TableName = "ITEMS";
	Table_Nodesan->Filter="RAZDEL=44";
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

	//������� ��������
	Table_Internet = new TIBTable(NULL);
	Table_Internet->Database=MainForm->MainConn;
	Table_Internet->Transaction=OtherTransaction;
	Table_Internet->TableName = "ITEMS";
	Table_Internet->Filter="RAZDEL=70";
	Table_Internet->Filtered=TRUE;
	Table_Internet->Active = TRUE;
	Table_Internet->FetchAll();
	Internet_datasource = new TDataSource(NULL);
	Internet_datasource->DataSet=Table_Internet;

    //������� ������� � ����� ��������������
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();

	Application->OnMessage = OnApplicationMessage;

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
	if (MainForm->TabPricelist_Datasource_Main->DataSet->RecordCount==0) {
		Table_History->Filter=Table_History->Filter+"0";
	} else {
		Table_History->Filter=Table_History->Filter+MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("ID")->AsString;
    }
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

    //������� �������� �� ������ ���������
	Table_Items = new TIBTable(NULL);
	Table_Items->Database=MainForm->MainConn;
	Table_Items->Transaction=OtherTransaction;
	Table_Items->TableName = "ITEMS";
	Table_Items->Filter = "Razdel=8";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll(); */
}
//---------------------------------------------------------------------------
void __fastcall TFormEditCommercSell4::ProcRefreshClient(TObject *Sender)
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

void __fastcall TFormEditCommercSell4::FormShow(TObject *Sender)
{
	//�����
	Region_DBLookComb->ListSource=Region_datasource;
	Region_DBLookComb->ListField="FULLNAME";
	Region_DBLookComb->KeyField="CODE";
	Region_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Region_DBLookComb->DataField="REGION";
	//�����
	Streets_DBLookupListBox->ListSource=Streets_datasource;
	Streets_DBLookupListBox->ListField="STREETNAME";
	Streets_DBLookupListBox->KeyField="STREETNAME";
	Streets_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Streets_DBEdit->DataField="STREET";
	//��������� ���� ��������
	Streets_DBEdit->Color=(TColor)RGB(255,220,220);
	//�����������
	Cross_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Cross_DBEdit->DataField="CRSTREET";
	//����������
	mRegion_DBLookComb->ListSource=mRegion_datasource;
	mRegion_DBLookComb->ListField="FULLNAME";
	mRegion_DBLookComb->KeyField="CODE";
	mRegion_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	mRegion_DBLookComb->DataField="MREGION";
	// ���
	House_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	House_DBEdit->DataField="HOUSE";
	House_DBEdit->DataSource->DataSet->FieldByName("HOUSE")->Alignment=taLeftJustify;
	// ������
	Corpus_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Corpus_DBEdit->DataField="CORPUS";
	// ��������
	Flat_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Flat_DBEdit->DataField="FLAT";
	Flat_DBEdit->DataSource->DataSet->FieldByName("FLAT")->Alignment=taLeftJustify;
	// �������
	Contract_DBLookComb->ListSource=Contract_datasource;
	Contract_DBLookComb->ListField="FULLNAME";
	Contract_DBLookComb->KeyField="ID";
	Contract_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Contract_DBLookComb->DataField="CONTRACT";
	// ��������
	Source_DBLookComb->ListSource=Source_datasource;
	Source_DBLookComb->ListField="FULLNAME";
	Source_DBLookComb->KeyField="CODE";
	Source_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Source_DBLookComb->DataField="SOURCED";
	// �������
	Variant_DBLookComb->ListSource=Variant_datasource;
	Variant_DBLookComb->ListField="FULLNAME";
	Variant_DBLookComb->KeyField="CODE";
	Variant_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Variant_DBLookComb->DataField="VARIANT";
	// �������
	Mortgage_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Mortgage_DBCheckBox->DataField="MORGAGE";
	// ����
	Part_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Part_DBEdit->DataField="PART";
	// ����
	Level_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Level_DBEdit->DataField="LEVEL";
	// ���������
	Levels_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Levels_DBEdit->DataField="LEVELS";
	// ��� ����
	Typehouse_DBLookComb->ListSource=Typehouse_datasource;
	Typehouse_DBLookComb->ListField="FULLNAME";
	Typehouse_DBLookComb->KeyField="CODE";
	Typehouse_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Typehouse_DBLookComb->DataField="TYPEHOUSE";
	// �������� ����
	Stuffwall_DBLookComb->ListSource=Stuffwall_datasource;
	Stuffwall_DBLookComb->ListField="FULLNAME";
	Stuffwall_DBLookComb->KeyField="CODE";
	Stuffwall_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Stuffwall_DBLookComb->DataField="STUFFWALL";
	// ��� ���������
	Yearbuild_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Yearbuild_DBEdit->DataField="YEARBUILD";
	// ������
	Security_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Security_DBCheckBox->DataField="SECURITY";
	// ��������
	Konserg_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Konserg_DBCheckBox->DataField="KONSERG";
	// ������. ��. �����.
	Ownex_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Ownex_DBCheckBox->DataField="OWNEX";
	// ������������
	Trash_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Trash_DBCheckBox->DataField="TRASH";
	// ���
	Gaz_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Gaz_DBCheckBox->DataField="GAZ";
	// �������
	Parking_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Parking_DBCheckBox->DataField="PARKING";
	// �����������
	Newbuild_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Newbuild_DBCheckBox->DataField="NEWBUILD";
	// ������
	Rooms_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Rooms_DBEdit->DataField="ROOMS";
	// ������� ������
	iRooms_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	iRooms_DBEdit->DataField="IROOMS";
	// ����������
	Design_DBLookComb->ListSource=Design_datasource;
	Design_DBLookComb->ListField="FULLNAME";
	Design_DBLookComb->KeyField="CODE";
	Design_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Design_DBLookComb->DataField="DESIGN";
	// ���������
	State_DBLookComb->ListSource=State_datasource;
	State_DBLookComb->ListField="FULLNAME";
	State_DBLookComb->KeyField="CODE";
	State_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	State_DBLookComb->DataField="STATE";
	// ��������
	Balcony_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Balcony_DBEdit->DataField="BALCONY";
	// ������
	Loggia_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Loggia_DBEdit->DataField="LOGGIA";
	// ����� �������
	Totalarea_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Totalarea_DBEdit->DataField="TOTALAREA";
	// ����� �������
	Livearea_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Livearea_DBEdit->DataField="LIVEAREA";
	// ������� �����
	Kitchenarea_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Kitchenarea_DBEdit->DataField="KITCHENAREA";
	// �������
	Swphone_DBLookComb->ListSource=Swphone_datasource;
	Swphone_DBLookComb->ListField="FULLNAME";
	Swphone_DBLookComb->KeyField="CODE";
	Swphone_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swphone_DBLookComb->DataField="SWPHONE";
	// �������
	Nodesan_DBLookComb->ListSource=Nodesan_datasource;
	Nodesan_DBLookComb->ListField="FULLNAME";
	Nodesan_DBLookComb->KeyField="CODE";
	Nodesan_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Nodesan_DBLookComb->DataField="NODESAN";
	// ��������� ������
	Glassbalc_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Glassbalc_DBCheckBox->DataField="GLASSBALC";
	// �����������
	Glasspack_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Glasspack_DBCheckBox->DataField="GLASSPACK";
	// �������������� ����������
	Addinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Addinfo_DBMemo->DataField="ADDINFO";
	// ������� ������
	Varswap_DBLookComb->ListSource=Varswap_datasource;
	Varswap_DBLookComb->ListField="FULLNAME";
	Varswap_DBLookComb->KeyField="ID";
	Varswap_DBLookComb->DataSource=MainForm->TabPricelist_Datasource_Main;
	Varswap_DBLookComb->DataField="VARSWAP";
	// �������
	Doplata_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Doplata_DBCheckBox->DataField="DOPLATA";
	// ���������� �� ������
	Swapinfo_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swapinfo_DBEdit->DataField="SWAPINFO";
	// ����
	Price_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Price_DBEdit->DataField="PRICE";
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("PRICE")->EditMask="99999;0;_";
	// � �����
	Num_card_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Num_card_DBEdit->DataField="NUM_CARD";
	// �������� ��������, ������������ ����������
	Compstr_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Compstr_DBEdit->DataField="COMPSTR";
	// ������� �������
	ClientPhone_DBEdit->DataSource=Clients_Datasource;
	ClientPhone_DBEdit->DataField="PHONE";
	// ICQ �������
	ClientPager_DBEdit->DataSource=Clients_Datasource;
	ClientPager_DBEdit->DataField="PAGER";
	// E-mail �������
	ClientOperator_DBEdit->DataSource=Clients_Datasource;
	ClientOperator_DBEdit->DataField="OPERATOR";
	// ����� �������
	ClientComp_DBEdit->DataSource=Clients_Datasource;
	ClientComp_DBEdit->DataField="COMP";
	// ��� �������
	ClientName_DBEdit->DataSource=Clients_Datasource;
	ClientName_DBEdit->DataField="NAME";
	// ������� �������
	ClientMobile_DBEdit->DataSource=Clients_Datasource;
	ClientMobile_DBEdit->DataField="MOBILE";
	// �������������� ���������� ��� ������
	Agentinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Agentinfo_DBMemo->DataField="AGENTINFO";
	// ��������� ����������
	Reklinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Reklinfo_DBMemo->DataField="REKLINFO";
	// ������� ������
	AgentMainphone_DBEdit->DataSource=Agent_datasource;
	AgentMainphone_DBEdit->DataField="MAINPHONE";
	// ��������� � ����������� ���
	AgChkname_DBCheckBox->DataSource=Agent_datasource;
	AgChkname_DBCheckBox->DataField="CHKNAME";
	// ��������� � ����������� ����
	AgChkprice_DBCheckBox->DataSource=Agent_datasource;
	AgChkprice_DBCheckBox->DataField="CHKPRICE";
	// ��������� � ����������� ������� �������
	AgChkSot_DBCheckBox->DataSource=Agent_datasource;
	AgChkSot_DBCheckBox->DataField="CHKSOT";
	// ��������� � ����������� e-mail
	AgChke_mail_DBCheckBox->DataSource=Agent_datasource;
	AgChke_mail_DBCheckBox->DataField="CHKE_MAIL";
	// ��������� � ����������� ��������� �������
	AgChkmain_DBCheckBox->DataSource=Agent_datasource;
	AgChkmain_DBCheckBox->DataField="CHKMAIN";
	// ��������� � ����������� �������������� �������
	AgChkadd_DBCheckBox->DataSource=Agent_datasource;
	AgChkadd_DBCheckBox->DataField="CHKADD";
	// ���� ����� �����
	Date_enter_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Date_enter_DBEdit->DataField="DATE_ENTER";
	// ���� �������������
	Date_ch_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Date_ch_DBEdit->DataField="DATE_CH";
	// �������
	Neighbors_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Neighbors_DBEdit->DataField="NEIGHBORS";
	// ������
	Object_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Object_DBEdit->DataField="OBJECT";
	// ����� �����������
	Formoffer_DBLookupComboBoxCentre->ListSource=mRegion_datasource;
	Formoffer_DBLookupComboBoxCentre->ListField="FULLNAME";
	Formoffer_DBLookupComboBoxCentre->KeyField="ID";
	Formoffer_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Formoffer_DBLookupComboBoxCentre->DataField="FORMOFFER";
	// �������
	Contract_DBLookupComboBoxCentre->ListSource=Contract_datasource;
	Contract_DBLookupComboBoxCentre->ListField="FULLNAME";
	Contract_DBLookupComboBoxCentre->KeyField="ID";
	Contract_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Contract_DBLookupComboBoxCentre->DataField="CONTRACT";
	// ���������� �����
	Town_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Town_DBEdit->DataField="TOWN";
	// �����
	Street_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Street_DBEdit->DataField="STREET";
	// ���. �����
	//Amountline_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	//Amountline_DBEdit->DataField="AMOUNTLINE";
	// �������� ����
	Stuffwall_DBLookupComboBoxCentre->ListSource=Stuffwall_datasource;
	Stuffwall_DBLookupComboBoxCentre->ListField="FULLNAME";
	Stuffwall_DBLookupComboBoxCentre->KeyField="CODE";
	Stuffwall_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Stuffwall_DBLookupComboBoxCentre->DataField="STUFFWALL";
	// ���������
	State_DBLookupComboBoxCentre->ListSource=State_datasource;
	State_DBLookupComboBoxCentre->ListField="FULLNAME";
	State_DBLookupComboBoxCentre->KeyField="CODE";
	State_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	State_DBLookupComboBoxCentre->DataField="STATE";
	// �����
	Landarea_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Landarea_DBEdit->DataField="LANDAREA";
	// ����� �������������
	Formowner_DBLookupComboBoxCentre->ListSource=Typehouse_datasource;
	Formowner_DBLookupComboBoxCentre->ListField="FULLNAME";
	Formowner_DBLookupComboBoxCentre->KeyField="CODE";
	Formowner_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Formowner_DBLookupComboBoxCentre->DataField="FORMOWNER";
	// ������������� �� ������ ����
	//Ownerto_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	//Ownerto_DBEdit->DataField="OWNERTO";
	// ���������
	Hoting_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Hoting_DBCheckBox->DataField="HOTING";
	// ���. ����
	Hotwater_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Hotwater_DBCheckBox->DataField="HOTWATER";
	// ���
	Gaz_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Gaz_DBCheckBox->DataField="GAZ";
	// �����������
	Waterdrain_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Waterdrain_DBCheckBox->DataField="WATERDRAIN";
	// ��������������
	Power_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Power_DBCheckBox->DataField="POWER";
	// ��������� ���
	Hotingadd_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Hotingadd_DBEdit->DataField="HOTINGADD";
	// ���. ���� ���
	Hotwateradd_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Hotwateradd_DBEdit->DataField="HOTWATERADD";
	// ��� ���
	Gazadd_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Gazadd_DBEdit->DataField="GAZADD";
	// ����������� ���
	Waterdrainadd_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Waterdrainadd_DBEdit->DataField="WATERDRAINADD";
	// �������������� ���
	Poweradd_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Poweradd_DBEdit->DataField="POWERADD";
	// �������
	//Purpose_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	//Purpose_DBCheckBox->DataField="PURPOSE";
	// �������������
	Purposeuse_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Purposeuse_DBEdit->DataField="PURPOSEUSE";
	// �������
	//Befor_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	//Befor_DBEdit->DataField="BEFOR";
	// ���������
	Hotingi_DBLookupComboBoxCentre->ListSource=Swphone_datasource;
	Hotingi_DBLookupComboBoxCentre->ListField="FULLNAME";
	Hotingi_DBLookupComboBoxCentre->KeyField="CODE";
	Hotingi_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Hotingi_DBLookupComboBoxCentre->DataField="HOTINGI";
	// ������
	Securety_DBLookupComboBoxCentre->ListSource=Nodesan_datasource;
	Securety_DBLookupComboBoxCentre->ListField="FULLNAME";
	Securety_DBLookupComboBoxCentre->KeyField="CODE";
	Securety_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Securety_DBLookupComboBoxCentre->DataField="SECURETY";
	// �������� ������������
	Firesign_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Firesign_DBCheckBox->DataField="FIRESIGN";
	// �� ������
	Part_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Part_DBCheckBox->DataField="PART";
	// �� ������ ��
	Partfrom_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Partfrom_DBEdit->DataField="PARTFROM";
	// �� ������ ��
	Partto_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Partto_DBEdit->DataField="PARTTO";
	// ���� ����� ���.
	Commprice_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Commprice_DBEdit->DataField="COMMPRICE";
	// ������������ �������
	Kommpay_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Kommpay_DBCheckBox->DataField="KOMMPAY";
	// ����������������
	Balansowner_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Balansowner_DBEdit->DataField="BALANSOWNER";
	// ����������� �����
	Inventnum_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Inventnum_DBEdit->DataField="INVENTNUM";
	// ����
	Code_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Code_DBEdit->DataField="CODE";
    // ��� ����� � ������������
	Yearenter_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Yearenter_DBEdit->DataField="YEARENTER";
	// ������� ������, �����
	Liter_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Liter_DBEdit->DataField="LITER";
	// ������������
	Houseowner_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Houseowner_DBEdit->DataField="HOUSEOWNER";
	// ��������
	Seller_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Seller_DBEdit->DataField="SELLER";
	// ������
	Sale_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Sale_DBEdit->DataField="SALE";
    // ��������
	Source_DBLookupComboBoxCentre->ListSource=Source_datasource;
	Source_DBLookupComboBoxCentre->ListField="FULLNAME";
	Source_DBLookupComboBoxCentre->KeyField="CODE";
	Source_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Source_DBLookupComboBoxCentre->DataField="SOURCED";
	// �������������
	Owner_DBLookupComboBoxCentre->ListSource=Typehouse_datasource;
	Owner_DBLookupComboBoxCentre->ListField="FULLNAME";
	Owner_DBLookupComboBoxCentre->KeyField="CODE";
	Owner_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Owner_DBLookupComboBoxCentre->DataField="OWNER";
	// ��������
	Nal_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Nal_DBCheckBox->DataField="NAL";
	// ������
	Beznal_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Beznal_DBCheckBox->DataField="BEZNAL";
	// ��������� �����
	Mix_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Mix_DBCheckBox->DataField="MIX";
	// �����
	Rub_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Rub_DBCheckBox->DataField="RUB";
	// �.�.
	Ued_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Ued_DBCheckBox->DataField="UED";
	// ��������
	Nal_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Nal_DBCheckBox->DataField="NAL";
	// ������ ������ (�� ������)
	Directpaybefor_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Directpaybefor_DBCheckBox->DataField="DIRECTPAYBEFOR";
	// ������ ������ (����� ������)
	Directpayafter_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Directpayafter_DBCheckBox->DataField="DIRECTPAYAFTER";
	// ��������� ����� ����������
	Mixakkred_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Mixakkred_DBCheckBox->DataField="MIXAKKRED";
	// ��������� ��������
	Mixetap_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Mixetap_DBCheckBox->DataField="MIXETAP";
	// ����
	Other_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Other_DBCheckBox->DataField="OTHER";
	// ��������� ����
	//Enter_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	//Enter_DBCheckBox->DataField="ENTER";
	// ���� ���
	Otheradd_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Otheradd_DBMemo->DataField="OTHERADD";
	// Internet
	/*Internet_DBLookupComboBoxCentre->ListSource=Internet_datasource;
	Internet_DBLookupComboBoxCentre->ListField="FULLNAME";
	Internet_DBLookupComboBoxCentre->KeyField="CODE";
	Internet_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Internet_DBLookupComboBoxCentre->DataField="INTERNET"; */
	// ��������
	/*Parking_DBLookupComboBoxCentre->ListSource=Parking_datasource;
	Parking_DBLookupComboBoxCentre->ListField="FULLNAME";
	Parking_DBLookupComboBoxCentre->KeyField="CODE";
	Parking_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Parking_DBLookupComboBoxCentre->DataField="PARKING";*/
	// ����� ������ �����������
	/*Commplace_DBLookupComboBoxCentre->ListSource=Commplace_datasource;
	Commplace_DBLookupComboBoxCentre->ListField="FULLNAME";
	Commplace_DBLookupComboBoxCentre->KeyField="CODE";
	Commplace_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Commplace_DBLookupComboBoxCentre->DataField="COMMPLACE";*/
	// �������� ����
	Stuffwall_DBLookupComboBoxCentre->ListSource=Stuffwall_datasource;
	Stuffwall_DBLookupComboBoxCentre->ListField="FULLNAME";
	Stuffwall_DBLookupComboBoxCentre->KeyField="CODE";
	Stuffwall_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Stuffwall_DBLookupComboBoxCentre->DataField="STUFFWALL";
	// ���������
	State_DBLookupComboBoxCentre->ListSource=State_datasource;
	State_DBLookupComboBoxCentre->ListField="FULLNAME";
	State_DBLookupComboBoxCentre->KeyField="CODE";
	State_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	State_DBLookupComboBoxCentre->DataField="STATE";
	// ���������
	/*Placement_DBLookupComboBoxCentre->ListSource=Placement_datasource;
	Placement_DBLookupComboBoxCentre->ListField="FULLNAME";
	Placement_DBLookupComboBoxCentre->KeyField="CODE";
	Placement_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Placement_DBLookupComboBoxCentre->DataField="PLACEMENT";*/
	// �������
	/*Profile_DBLookupComboBoxCentre->ListSource=Profile_datasource;
	Profile_DBLookupComboBoxCentre->ListField="FULLNAME";
	Profile_DBLookupComboBoxCentre->KeyField="CODE";
	Profile_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Profile_DBLookupComboBoxCentre->DataField="PROFILE";*/
	// �������� ������������
	//Equipment_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	//Equipment_DBCheckBox->DataField="EQUIPMENT";
	// �������
	Profile_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Profile_DBMemo->DataField="PROFILE";
	// �������� ������� �� �����
	Powerin_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Powerin_DBEdit->DataField="POWERIN";
	// ������ �������
	Height_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Height_DBEdit->DataField="HEIGHT";
	// �������� ������ �� �����������
	Hor_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Hor_DBEdit->DataField="HOR";
	// �������� ������ �� ���������
	Vert_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Vert_DBEdit->DataField="VERT";
	// �/� �����
	Train_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Train_DBCheckBox->DataField="TRAIN";
	// ������������ ���������
	Mehpogruz_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Mehpogruz_DBCheckBox->DataField="MEHPOGRUZ";
	// ���������
	Rampa_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Rampa_DBCheckBox->DataField="RAMPA";
	// ������������ ����������
	Transp_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Transp_DBCheckBox->DataField="TRANSP";
}
//---------------------------------------------------------------------------


void __fastcall TFormEditCommercSell4::PageControl1DrawTab(TCustomTabControl *Control, int TabIndex,
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



//���������������������������������������������������������������������������
//---------- ���� ��������, ���������� �� ������ �� ������� ����
//----------
//���������������������������������������������������������������������������
//---------- ������ -- ����� �������� ��������� ������ ����

//---------- ��������� ����������� ��� ������� �� ���� "�����"
void __fastcall TFormEditCommercSell4::Streets_DBEditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	Table_Streets->Locate("Streetname", Streets_DBEdit->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
	 Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
	 if (Key==40) {  // ������� "������� �����"
		Streets_DBLookupListBox->ListSource->DataSet->Next();
		Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
		Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			Streets_DBLookupListBox->KeyValue;
		Streets_DBLookupListBox->SetFocus();
	 }
	 if (Key==38) { // ������� "������� ����"
		Streets_DBLookupListBox->ListSource->DataSet->Prior();
		Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
		Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			Streets_DBLookupListBox->KeyValue;
		Streets_DBLookupListBox->SetFocus();
	 }
	 if (Key==13) { // ������� ENTER
		Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			Streets_DBLookupListBox->KeyValue;
		Streets_DBLookupListBox->Visible=FALSE;
		Region_DBLookComb->SetFocus();
	 }
}
//---------------------------------------------------------------------------


//----- ��������� ����������� ��� ������� (�����) ����� ������� ���� �� ���� "�����"
void __fastcall TFormEditCommercSell4::Streets_DBLookupListBoxClick(TObject *Sender)
{
	 if (Streets_DBLookupListBox->Top==98) {
		Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			Streets_DBLookupListBox->KeyValue;
	 }
	 if (Streets_DBLookupListBox->Top==124) {
		Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			Streets_DBLookupListBox->KeyValue;
	 }
}
//---------------------------------------------------------------------------


//------------ ��������� ����������� ����� ���� "�����" �������� �����
void __fastcall TFormEditCommercSell4::Streets_DBEditEnter(TObject *Sender)
{
	if (Streets_DBEdit->Text.Length()==0) {
		Streets_DBLookupListBox->ListSource->DataSet->First();
	} else
	{
		Table_Streets->Locate("Streetname", Streets_DBEdit->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
	}
	Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
	Streets_DBLookupListBox->Height=134;
	Streets_DBLookupListBox->Top=98;
	Streets_DBLookupListBox->Visible=TRUE;
	Streets_DBLookupListBox->Enabled=TRUE;

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
void __fastcall TFormEditCommercSell4::Streets_DBEditExit(TObject *Sender)
{
	if (!Streets_DBLookupListBox->Focused()){
		if (Streets_DBEdit->Text.Length()!=0) {
			Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
				Streets_DBLookupListBox->KeyValue;
		}
		Streets_DBLookupListBox->Visible=FALSE;
	}
}
//---------------------------------------------------------------------------


//--------- ��������� ����������� ����� � �������� �� ������� ���� ������ �������
void __fastcall TFormEditCommercSell4::Streets_DBLookupListBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
	 if (Key==13) {
		if (Streets_DBLookupListBox->Top==98) {
			Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
				Streets_DBLookupListBox->KeyValue;
		}
		if (Streets_DBLookupListBox->Top==124) {
			Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
				Streets_DBLookupListBox->KeyValue;
		}
		Streets_DBLookupListBox->Visible=FALSE;
		Region_DBLookComb->SetFocus();
	 }
}
//---------------------------------------------------------------------------


//-------- ��������� ����������� ����� � �������� �� ������� ���� ������ ������� ����
void __fastcall TFormEditCommercSell4::Streets_DBLookupListBoxMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (Streets_DBLookupListBox->Top==98) {
		Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			Streets_DBLookupListBox->KeyValue;
	}
	if (Streets_DBLookupListBox->Top==124) {
		Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			Streets_DBLookupListBox->KeyValue;
	}
	Streets_DBLookupListBox->Visible=FALSE;
}
//---------------------------------------------------------------------------


//-------- ��������� ����������� ����� � �������� �� ������� ���� ������ �����
void __fastcall TFormEditCommercSell4::Streets_DBLookupListBoxExit(TObject *Sender)
{
	if (Streets_DBLookupListBox->Top==98) {
		Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
			Streets_DBLookupListBox->KeyValue;
	}
	if (Streets_DBLookupListBox->Top==124) {
		Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			Streets_DBLookupListBox->KeyValue;
	}
	Streets_DBLookupListBox->Visible=FALSE;
}
//---------------------------------------------------------------------------


//-------- ��������� ����������� ����� ���� "�����������" �������� �����
void __fastcall TFormEditCommercSell4::Cross_DBEditEnter(TObject *Sender)
{
	if (Cross_DBEdit->Text.Length()==0) {
		Streets_DBLookupListBox->ListSource->DataSet->First();
	} else
	{
		Table_Streets->Locate("Streetname", Cross_DBEdit->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
	}
	Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
	Streets_DBLookupListBox->Height=134;
	Streets_DBLookupListBox->Top=124;
	Streets_DBLookupListBox->Visible=TRUE;

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
void __fastcall TFormEditCommercSell4::Cross_DBEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	//loPartialKey - ������������ ���������� ����������
	//loCaseInsensitive - ������������������ � ��������
	 Table_Streets->Locate("Streetname", Cross_DBEdit->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
	 Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
	 if (Key==40) {   //----- ������� ������� �����
		Streets_DBLookupListBox->ListSource->DataSet->Next();
		Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
		Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			Streets_DBLookupListBox->KeyValue;
		Streets_DBLookupListBox->SetFocus();
	 }
	 if (Key==38) {  //---- ������� ������� ����
		Streets_DBLookupListBox->ListSource->DataSet->Prior();
		Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
		Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			Streets_DBLookupListBox->KeyValue;
		Streets_DBLookupListBox->SetFocus();
	 }
	 if (Key==13) { //--- ������� ����
		Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
			Streets_DBLookupListBox->KeyValue;
		Streets_DBLookupListBox->Visible=FALSE;
		Region_DBLookComb->SetFocus();
	 }
}
//---------------------------------------------------------------------------


//-------- ��������� ���������� ����� ���� "�����������" ������ �����
void __fastcall TFormEditCommercSell4::Cross_DBEditExit(TObject *Sender)
{
	if (!Streets_DBLookupListBox->Focused()){
		if (Cross_DBEdit->Text.Length()!=0) {
			Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
				Streets_DBLookupListBox->KeyValue;
		}
		Streets_DBLookupListBox->Visible=FALSE;
	}
}
//---------------------------------------------------------------------------

//--- ��������� ��������� ���������
void __fastcall TFormEditCommercSell4::OnApplicationMessage(TMsg & Msg, bool & Handled)
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
					Streets_DBLookupListBox->ListSource->DataSet->Prior();
					//SendMessage(Streets_DBLookupListBox->Handle, WM_VSCROLL, SB_LINEUP, 0);
				 }
				 else
				 {
					Streets_DBLookupListBox->ListSource->DataSet->Next();
					//SendMessage(Streets_DBLookupListBox->Handle, WM_VSCROLL, SB_LINEDOWN, 0);
				 }
				 Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
				 Streets_DBEdit->DataSource->DataSet->FieldByName("STREET")->Value=
					Streets_DBLookupListBox->KeyValue;
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
					Streets_DBLookupListBox->ListSource->DataSet->Prior();
					//SendMessage(Streets_DBLookupListBox->Handle, WM_VSCROLL, SB_LINEUP, 0);
				 }
				 else
				 {
					Streets_DBLookupListBox->ListSource->DataSet->Next();
					//SendMessage(Streets_DBLookupListBox->Handle, WM_VSCROLL, SB_LINEDOWN, 0);
				 }
				 Streets_DBLookupListBox->KeyValue = Table_Streets->FieldByName("Streetname")->AsAnsiString;
				 Streets_DBEdit->DataSource->DataSet->FieldByName("CRSTREET")->Value=
				 	Streets_DBLookupListBox->KeyValue;

			}
		}
  }
}

//---------------------------------------------------------------------------
//-------- ����� ����� �������� ������ �� ������� ����
//---------------------------------------------------------------------------
//------- �����


void __fastcall TFormEditCommercSell4::SpeedButton2Click(TObject *Sender)
{
    //�������� ���������
	//MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
	//�������� ��������� � ���� ������
	//OtherTransaction->RollbackRetaining();
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercSell4::Button6Click(TObject *Sender)
{
	//FormGall = new TFormGall(FormEdit,MainForm->MainConn,OtherTransaction,MainForm->TabPricelist_Datasource_Main);
	//FormGall->ShowModal();
	//delete FormGall;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercSell4::Button4Click(TObject *Sender)
{
	FormMap = new TFormMap(FormEdit,MainForm->TabPricelist_Datasource_Main);
	FormMap->ShowModal();
	delete FormMap;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercSell4::SpeedButton1Click(TObject *Sender)
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

void __fastcall TFormEditCommercSell4::SpeedButton3Click(TObject *Sender)
{
    MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger=0;
	// ����� ��������� ���������� �������� � �������
	ProcRefreshClient(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercSell4::Button5Click(TObject *Sender)
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

void __fastcall TFormEditCommercSell4::Button3Click(TObject *Sender)
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

void __fastcall TFormEditCommercSell4::ProcSave(TObject *Sender)
{
    //�������� ���������
	MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
	//�������� ��������� � ���� ������
	OtherTransaction->CommitRetaining();
	//������� ����� ������
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercSell4::RefreshAgent(TObject *Sender)
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

void __fastcall TFormEditCommercSell4::Agent_ComboBoxClick(TObject *Sender)
{
	 Agent_datasource->DataSet->Active=true;
	 Agent_datasource->DataSet->First();
	 Agent_datasource->DataSet->MoveBy(Agent_ComboBox->ItemIndex);
	 MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->AsInteger=
         Agent_datasource->DataSet->FieldByName("ID")->AsInteger;
	 RefreshAgent(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercSell4::Button1Click(TObject *Sender)
{
	FormAgKartEdit = new TFormAgKartEdit(this,Agent_datasource,MainForm->MainConn,TransactionAgent);
	FormAgKartEdit->ShowModal();
	delete FormAgKartEdit;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercSell4::Button2Click(TObject *Sender)
{
	FormKartHistory = new TFormKartHistory(this,History_datasource);
	FormKartHistory->ShowModal();
	delete FormKartHistory;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercSell4::Button7Click(TObject *Sender)
{
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("DATE_CH")->AsDateTime=Date();
	ProcSave(this);
	MainForm->TabPricelist_Datasource_Main->DataSet->Refresh();
	MainForm->TabPricelist_Datasource_Main->DataSet->Active=True;
	//������� ������� � ����� ��������������
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEditCommercSell4::Typehouse_ButtonClick(TObject *Sender)
{
	// ������ ������� �������������
	Table_Items->Active=false;
	Table_Items->Filtered = false;
	Table_Items->Filter = "Razdel=46";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	UnicodeString * resultstr = new UnicodeString;
	*resultstr = MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("PURPOSEUSE")->AsString;

	FormSelect = new TFormSelect(this, Table_Items, resultstr);
	FormSelect->ShowModal();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("PURPOSEUSE")->AsString = *resultstr;
	delete FormSelect;
	delete resultstr;
}
//---------------------------------------------------------------------------
