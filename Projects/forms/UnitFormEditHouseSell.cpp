//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormEditHouseSell.h"

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

TFormEditHouseSell *FormEditHouseSell;
TIBDatabase * MainConn = NULL;
extern TIBDatabase * MainConn;
TIBTransaction * OtherTransaction = NULL;
extern TIBTransaction * OtherTransaction;
// ������� �� ������� �������
TIBTable * Table_Items_8 = NULL;
extern TIBTable * Table_Items_8;
TDataSource * Region_datasource = NULL;
extern TDataSource * Region_datasource;
// ������� ������� �� ������� ��������
TDataSource * TabPricelist_Datasource_Main;
extern TDataSource * TabPricelist_Datasource_Main;
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
// ������� ������������
TIBTable * Table_Realstate = NULL;
extern TIBTable * Table_Realstate;
TDataSource * Realstate_datasource = NULL;
extern TDataSource * Realstate_datasource;
// ������� ����� ��������
TIBTable * Table_Formowner = NULL;
extern TIBTable * Table_Formowner;
TDataSource * Formowner_datasource = NULL;
extern TDataSource * Formowner_datasource;
// ������� ����� �����������
TIBTable * Table_Formoffer = NULL;
extern TIBTable * Table_Formoffer;
TDataSource * Formoffer_datasource = NULL;
extern TDataSource * Formoffer_datasource;
// ������� �����
TIBTable * Table_Typeright = NULL;
extern TIBTable * Table_Typeright;
TDataSource * Typeright_datasource = NULL;
extern TDataSource * Typeright_datasource;
// ������� �������������
TIBTable * Table_Energy = NULL;
extern TIBTable * Table_Energy;
TDataSource * Energy_datasource = NULL;
extern TDataSource * Energy_datasource;
// ������� ����
TIBTable * Table_Water = NULL;
extern TIBTable * Table_Water;
TDataSource * Water_datasource = NULL;
extern TDataSource * Water_datasource;
// ������� ���������
TIBTable * Table_Heating = NULL;
extern TIBTable * Table_Heating;
TDataSource * Heating_datasource = NULL;
extern TDataSource * Heating_datasource;
// ������� �����������
TIBTable * Table_Waterdrain = NULL;
extern TIBTable * Table_Waterdrain;
TDataSource * Waterdrain_datasource = NULL;
extern TDataSource * Waterdrain_datasource;
// ������� ���
TIBTable * Table_Gaz = NULL;
extern TIBTable * Table_Gaz;
TDataSource * Gaz_datasource = NULL;
extern TDataSource * Gaz_datasource;
// ������� �����
TIBTable * Table_Sauna = NULL;
extern TIBTable * Table_Sauna;
TDataSource * Sauna_datasource = NULL;
extern TDataSource * Sauna_datasource;
// ������� �����
TIBTable * Table_Garage = NULL;
extern TIBTable * Table_Garage;
TDataSource * Garage_datasource = NULL;
extern TDataSource * Garage_datasource;

void __fastcall TFormEditHouseSell::FormCreate(TObject *Sender)
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
__fastcall TFormEditHouseSell::TFormEditHouseSell(TComponent* Owner)
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


	// ������� ������������
	Table_Realstate = new TIBTable(NULL);
	Table_Realstate->Database=MainForm->MainConn;
	Table_Realstate->Transaction=OtherTransaction;
	Table_Realstate->TableName = "ITEMS";
	Table_Realstate->Filter="RAZDEL=16";
	Table_Realstate->Filtered=TRUE;
	Table_Realstate->Active = TRUE;
	Table_Realstate->FetchAll();
	Realstate_datasource = new TDataSource(NULL);
	Realstate_datasource->DataSet=Table_Realstate;

	// ������� ����� ��������
	Table_Formowner = new TIBTable(NULL);
	Table_Formowner->Database=MainForm->MainConn;
	Table_Formowner->Transaction=OtherTransaction;
	Table_Formowner->TableName = "ITEMS";
	Table_Formowner->Filter="RAZDEL=47";
	Table_Formowner->Filtered=TRUE;
	Table_Formowner->Active = TRUE;
	Table_Formowner->FetchAll();
	Formowner_datasource = new TDataSource(NULL);
	Formowner_datasource->DataSet=Table_Formowner;

	// ������� �����
	Table_Typeright = new TIBTable(NULL);
	Table_Typeright->Database=MainForm->MainConn;
	Table_Typeright->Transaction=OtherTransaction;
	Table_Typeright->TableName = "ITEMS";
	Table_Typeright->Filter="RAZDEL=47";
	Table_Typeright->Filtered=TRUE;
	Table_Typeright->Active = TRUE;
	Table_Typeright->FetchAll();
	Typeright_datasource = new TDataSource(NULL);
	Typeright_datasource->DataSet=Table_Typeright;

	// ������� ����� �����������
	Table_Formoffer = new TIBTable(NULL);
	Table_Formoffer->Database=MainForm->MainConn;
	Table_Formoffer->Transaction=OtherTransaction;
	Table_Formoffer->TableName = "ITEMS";
	Table_Formoffer->Filter="RAZDEL=18";
	Table_Formoffer->Filtered=TRUE;
	Table_Formoffer->Active = TRUE;
	Table_Formoffer->FetchAll();
	Formoffer_datasource = new TDataSource(NULL);
	Formoffer_datasource->DataSet=Table_Formoffer;

	// ������� �������������
	Table_Energy = new TIBTable(NULL);
	Table_Energy->Database=MainForm->MainConn;
	Table_Energy->Transaction=OtherTransaction;
	Table_Energy->TableName = "ITEMS";
	Table_Energy->Filter="RAZDEL=41";
	Table_Energy->Filtered=TRUE;
	Table_Energy->Active = TRUE;
	Table_Energy->FetchAll();
	Energy_datasource = new TDataSource(NULL);
	Energy_datasource->DataSet=Table_Energy;

	// ������� ����
	Table_Water = new TIBTable(NULL);
	Table_Water->Database=MainForm->MainConn;
	Table_Water->Transaction=OtherTransaction;
	Table_Water->TableName = "ITEMS";
	Table_Water->Filter="RAZDEL=20";
	Table_Water->Filtered=TRUE;
	Table_Water->Active = TRUE;
	Table_Water->FetchAll();
	Water_datasource = new TDataSource(NULL);
	Water_datasource->DataSet=Table_Water;

	// ������� ���������
	Table_Heating = new TIBTable(NULL);
	Table_Heating->Database=MainForm->MainConn;
	Table_Heating->Transaction=OtherTransaction;
	Table_Heating->TableName = "ITEMS";
	Table_Heating->Filter="RAZDEL=21";
	Table_Heating->Filtered=TRUE;
	Table_Heating->Active = TRUE;
	Table_Heating->FetchAll();
	Heating_datasource = new TDataSource(NULL);
	Heating_datasource->DataSet=Table_Heating;

	// ������� �����������
	Table_Waterdrain = new TIBTable(NULL);
	Table_Waterdrain->Database=MainForm->MainConn;
	Table_Waterdrain->Transaction=OtherTransaction;
	Table_Waterdrain->TableName = "ITEMS";
	Table_Waterdrain->Filter="RAZDEL=22";
	Table_Waterdrain->Filtered=TRUE;
	Table_Waterdrain->Active = TRUE;
	Table_Waterdrain->FetchAll();
	Waterdrain_datasource = new TDataSource(NULL);
	Waterdrain_datasource->DataSet=Table_Waterdrain;

	// ������� ���
	Table_Gaz = new TIBTable(NULL);
	Table_Gaz->Database=MainForm->MainConn;
	Table_Gaz->Transaction=OtherTransaction;
	Table_Gaz->TableName = "ITEMS";
	Table_Gaz->Filter="RAZDEL=23";
	Table_Gaz->Filtered=TRUE;
	Table_Gaz->Active = TRUE;
	Table_Gaz->FetchAll();
	Gaz_datasource = new TDataSource(NULL);
	Gaz_datasource->DataSet=Table_Gaz;

	// ������� �����
	Table_Sauna = new TIBTable(NULL);
	Table_Sauna->Database=MainForm->MainConn;
	Table_Sauna->Transaction=OtherTransaction;
	Table_Sauna->TableName = "ITEMS";
	Table_Sauna->Filter="RAZDEL=24";
	Table_Sauna->Filtered=TRUE;
	Table_Sauna->Active = TRUE;
	Table_Sauna->FetchAll();
	Sauna_datasource = new TDataSource(NULL);
	Sauna_datasource->DataSet=Table_Sauna;

	// ������� �����
	Table_Garage = new TIBTable(NULL);
	Table_Garage->Database=MainForm->MainConn;
	Table_Garage->Transaction=OtherTransaction;
	Table_Garage->TableName = "ITEMS";
	Table_Garage->Filter="RAZDEL=25";
	Table_Garage->Filtered=TRUE;
	Table_Garage->Active = TRUE;
	Table_Garage->FetchAll();
	Garage_datasource = new TDataSource(NULL);
	Garage_datasource->DataSet=Table_Garage;

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

       */
}
//---------------------------------------------------------------------------
void __fastcall TFormEditHouseSell::ProcRefreshClient(TObject *Sender)
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

void __fastcall TFormEditHouseSell::FormShow(TObject *Sender)
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
	//Gaz_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	//Gaz_DBCheckBox->DataField="GAZ";
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
	// ������������
	Realstate_DBLookupComboBoxCentre->ListSource=Realstate_datasource;
	Realstate_DBLookupComboBoxCentre->ListField="FULLNAME";
	Realstate_DBLookupComboBoxCentre->KeyField="CODE";
	Realstate_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Realstate_DBLookupComboBoxCentre->DataField="REALSTATE";
	// ����� ����������
	Place_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Place_DBEdit->DataField="PLACE";
	// ����� ��������
	Formowner_DBLookupComboBoxCentre->ListSource=Formowner_datasource;
	Formowner_DBLookupComboBoxCentre->ListField="FULLNAME";
	Formowner_DBLookupComboBoxCentre->KeyField="CODE";
	Formowner_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Formowner_DBLookupComboBoxCentre->DataField="FORMOWNER";
	// ����� �����������
	Formoffer_DBLookupComboBoxCentre->ListSource=Formoffer_datasource;
	Formoffer_DBLookupComboBoxCentre->ListField="FULLNAME";
	Formoffer_DBLookupComboBoxCentre->KeyField="CODE";
	Formoffer_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Formoffer_DBLookupComboBoxCentre->DataField="FORMOFFER";
	// ������ ��������
	Sizehouse_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Sizehouse_DBEdit->DataField="SIZEHOUSE";
	// ���������� � %
	Ready_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Ready_DBEdit->DataField="READY";
	// ������� (���)
	Landarea_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Landarea_DBEdit->DataField="LANDAREA";
	// �����
	Typeright_DBLookupComboBoxCentre->ListSource=Typeright_datasource;
	Typeright_DBLookupComboBoxCentre->ListField="FULLNAME";
	Typeright_DBLookupComboBoxCentre->KeyField="CODE";
	Typeright_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Typeright_DBLookupComboBoxCentre->DataField="TYPERIGHT";
	// �������������
	Energy_DBLookupComboBoxCentre->ListSource=Energy_datasource;
	Energy_DBLookupComboBoxCentre->ListField="FULLNAME";
	Energy_DBLookupComboBoxCentre->KeyField="CODE";
	Energy_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Energy_DBLookupComboBoxCentre->DataField="ENERGY";
	// ����
	Water_DBLookupComboBoxCentre->ListSource=Water_datasource;
	Water_DBLookupComboBoxCentre->ListField="FULLNAME";
	Water_DBLookupComboBoxCentre->KeyField="CODE";
	Water_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Water_DBLookupComboBoxCentre->DataField="WATER";
	// ���������
	Heating_DBLookupComboBoxCentre->ListSource=Heating_datasource;
	Heating_DBLookupComboBoxCentre->ListField="FULLNAME";
	Heating_DBLookupComboBoxCentre->KeyField="CODE";
	Heating_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Heating_DBLookupComboBoxCentre->DataField="HEATING";
	// �����������
	Waterdrain_DBLookupComboBoxCentre->ListSource=Waterdrain_datasource;
	Waterdrain_DBLookupComboBoxCentre->ListField="FULLNAME";
	Waterdrain_DBLookupComboBoxCentre->KeyField="CODE";
	Waterdrain_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Waterdrain_DBLookupComboBoxCentre->DataField="WATERDRAIN";
	// ���
	Gaz_DBLookupComboBoxCentre->ListSource=Gaz_datasource;
	Gaz_DBLookupComboBoxCentre->ListField="FULLNAME";
	Gaz_DBLookupComboBoxCentre->KeyField="CODE";
	Gaz_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Gaz_DBLookupComboBoxCentre->DataField="GAZ";
	// �����
	Sauna_DBLookupComboBoxCentre->ListSource=Sauna_datasource;
	Sauna_DBLookupComboBoxCentre->ListField="FULLNAME";
	Sauna_DBLookupComboBoxCentre->KeyField="CODE";
	Sauna_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Sauna_DBLookupComboBoxCentre->DataField="SAUNA";
	// �����
	Garage_DBLookupComboBoxCentre->ListSource=Garage_datasource;
	Garage_DBLookupComboBoxCentre->ListField="FULLNAME";
	Garage_DBLookupComboBoxCentre->KeyField="CODE";
	Garage_DBLookupComboBoxCentre->DataSource=MainForm->TabPricelist_Datasource_Main;
	Garage_DBLookupComboBoxCentre->DataField="GARAGE";
	// ���������� �� �������
	Fromwater_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Fromwater_DBEdit->DataField="FROMWATER";
	// ���������� �� ��������
	Frombus_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Frombus_DBEdit->DataField="FROMBUS";
	// ���������� �� ����
	Fromforest_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Fromforest_DBEdit->DataField="FROMFOREST";
	// ���������� �� ��/��
	Fromtrain_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Fromtrain_DBEdit->DataField="FROMTRAIN";
}
//---------------------------------------------------------------------------


void __fastcall TFormEditHouseSell::PageControl1DrawTab(TCustomTabControl *Control, int TabIndex,
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
void __fastcall TFormEditHouseSell::Streets_DBEditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
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
void __fastcall TFormEditHouseSell::Streets_DBLookupListBoxClick(TObject *Sender)
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
void __fastcall TFormEditHouseSell::Streets_DBEditEnter(TObject *Sender)
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
void __fastcall TFormEditHouseSell::Streets_DBEditExit(TObject *Sender)
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
void __fastcall TFormEditHouseSell::Streets_DBLookupListBoxKeyDown(TObject *Sender, WORD &Key,
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
void __fastcall TFormEditHouseSell::Streets_DBLookupListBoxMouseUp(TObject *Sender, TMouseButton Button,
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
void __fastcall TFormEditHouseSell::Streets_DBLookupListBoxExit(TObject *Sender)
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
void __fastcall TFormEditHouseSell::Cross_DBEditEnter(TObject *Sender)
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
void __fastcall TFormEditHouseSell::Cross_DBEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
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
void __fastcall TFormEditHouseSell::Cross_DBEditExit(TObject *Sender)
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
void __fastcall TFormEditHouseSell::OnApplicationMessage(TMsg & Msg, bool & Handled)
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


void __fastcall TFormEditHouseSell::SpeedButton2Click(TObject *Sender)
{
    //�������� ���������
	//MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
	//�������� ��������� � ���� ������
	//OtherTransaction->RollbackRetaining();
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEditHouseSell::Button6Click(TObject *Sender)
{
	//FormGall = new TFormGall(FormEdit,MainForm->MainConn,OtherTransaction,MainForm->TabPricelist_Datasource_Main);
	//FormGall->ShowModal();
	//delete FormGall;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditHouseSell::Button4Click(TObject *Sender)
{
	FormMap = new TFormMap(FormEdit,MainForm->TabPricelist_Datasource_Main);
	FormMap->ShowModal();
	delete FormMap;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditHouseSell::SpeedButton1Click(TObject *Sender)
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

void __fastcall TFormEditHouseSell::SpeedButton3Click(TObject *Sender)
{
    MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger=0;
	// ����� ��������� ���������� �������� � �������
	ProcRefreshClient(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditHouseSell::Button5Click(TObject *Sender)
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

void __fastcall TFormEditHouseSell::Button3Click(TObject *Sender)
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

void __fastcall TFormEditHouseSell::ProcSave(TObject *Sender)
{
    //�������� ���������
	MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
	//�������� ��������� � ���� ������
	OtherTransaction->CommitRetaining();
	//������� ����� ������
}
//---------------------------------------------------------------------------

void __fastcall TFormEditHouseSell::RefreshAgent(TObject *Sender)
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

void __fastcall TFormEditHouseSell::Agent_ComboBoxClick(TObject *Sender)
{
	 Agent_datasource->DataSet->Active=true;
	 Agent_datasource->DataSet->First();
	 Agent_datasource->DataSet->MoveBy(Agent_ComboBox->ItemIndex);
	 MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->AsInteger=
         Agent_datasource->DataSet->FieldByName("ID")->AsInteger;
	 RefreshAgent(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditHouseSell::Button1Click(TObject *Sender)
{
	FormAgKartEdit = new TFormAgKartEdit(this,Agent_datasource,MainForm->MainConn,TransactionAgent);
	FormAgKartEdit->ShowModal();
	delete FormAgKartEdit;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditHouseSell::Button2Click(TObject *Sender)
{
	FormKartHistory = new TFormKartHistory(this,History_datasource);
	FormKartHistory->ShowModal();
	delete FormKartHistory;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditHouseSell::Button7Click(TObject *Sender)
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

