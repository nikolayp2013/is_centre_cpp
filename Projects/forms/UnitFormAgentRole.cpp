//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormAgentRole.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBLookupComboBoxCentre"
#pragma link "my_DBCtrls"
#pragma resource "*.dfm"
TFormAgentRole *FormAgentRole;
TIBDatabase * MainConn = NULL;
extern TIBDatabase * MainConn;
TIBTransaction * TransactionRole = NULL;
extern TIBTransaction * TransactionRole;
TIBTable * Table_Role = NULL;
extern TIBTable * Table_Role;
TDataSource * Role_datasource = NULL;
extern TDataSource * Role_datasource;
TIBTable * Table_Agent_Status = NULL;
extern TIBTable * Table_Agent_Status;
//---------------------------------------------------------------------------
__fastcall TFormAgentRole::TFormAgentRole(TComponent* Owner, TIBDatabase * MainConn_local)
	: TForm(Owner)
{
	MainConn = MainConn_local;
	TransactionRole = new TIBTransaction(NULL);
	TransactionRole->DefaultDatabase = MainConn;

	//������� �� ������� �����
	Table_Role = new TIBTable(NULL);
	Table_Role->Database=MainConn;
	Table_Role->Transaction=TransactionRole;
	Table_Role->TableName = "ROLETABLE";
	Table_Role->Active = true;
	Table_Role->FetchAll();

	Role_datasource = new TDataSource(NULL);
	Role_datasource->DataSet=Table_Role;
	Role_datasource->DataSet->Edit();

	// �������������� ����� ��������
	Rmykart_DBCheckBox->DataSource=Role_datasource;
	Rmykart_DBCheckBox->DataField="RMYKART";

	// �������������� �������� ����� ������
	Rkartmygr_DBCheckBox->DataSource=Role_datasource;
	Rkartmygr_DBCheckBox->DataField="RKARTMYGR";

	// �������������� ���� ��������
	Rallkart_DBCheckBox->DataSource=Role_datasource;
	Rallkart_DBCheckBox->DataField="RALLKART";

	// ������ ����������
	Sendrekl_DBCheckBox->DataSource=Role_datasource;
	Sendrekl_DBCheckBox->DataField="SENDREKL";

	// ������ �� �������� ������
	Inmail_DBCheckBox->DataSource=Role_datasource;
	Inmail_DBCheckBox->DataField="INMAIL";

	// ������ � ��������� ������
	Outmail_DBCheckBox->DataSource=Role_datasource;
	Outmail_DBCheckBox->DataField="OUTMAIL";

	// ������ �����-������
	Pplist_DBCheckBox->DataSource=Role_datasource;
	Pplist_DBCheckBox->DataField="PPLIST";

	// ��������� ����� ��� ������ ����������
	Setmarker_DBCheckBox->DataSource=Role_datasource;
	Setmarker_DBCheckBox->DataField="SETMARKER";

	// ��������� ����������
	Genmess_DBCheckBox->DataSource=Role_datasource;
	Genmess_DBCheckBox->DataField="GENMESS";

	// ������ � �������
	Workkadr_DBCheckBox->DataSource=Role_datasource;
	Workkadr_DBCheckBox->DataField="WORKKADR";

	// ������ �� ������� ��������
	Agentlist_DBCheckBox->DataSource=Role_datasource;
	Agentlist_DBCheckBox->DataField="AGENTLIST";

	// ������ �� ������� ��������
	Klientlist_DBCheckBox->DataSource=Role_datasource;
	Klientlist_DBCheckBox->DataField="KLIENTLIST";

	// ��������� ������ �����
	Setconnect_DBCheckBox->DataSource=Role_datasource;
	Setconnect_DBCheckBox->DataField="SETCONNECT";

	// ����������� �������� ������
	Export_DBCheckBox->DataSource=Role_datasource;
	Export_DBCheckBox->DataField="EXPORT";

	// ����������� �������� ����
	Modprintfr_DBCheckBox->DataSource=Role_datasource;
	Modprintfr_DBCheckBox->DataField="MODPRINTFR";

	// ������ � ������ ��������
	Arcobject_DBCheckBox->DataSource=Role_datasource;
	Arcobject_DBCheckBox->DataField="ARCOBJECT";

	// �������� ������ �������� �����-�����
	Viewmypriceout_DBCheckBox->DataSource=Role_datasource;
	Viewmypriceout_DBCheckBox->DataField="VIEWMYPRICEOUT";

	// ������ � ���������� �����-������
	Workmypricein_DBCheckBox->DataSource=Role_datasource;
	Workmypricein_DBCheckBox->DataField="WORKMYPRICEIN";

	// �������� ������ �����-�����
	Viewcommprice_DBCheckBox->DataSource=Role_datasource;
	Viewcommprice_DBCheckBox->DataField="VIEWCOMMPRICE";

	// ������������ ���������� ���������
	Viewprop_DBCheckBox->DataSource=Role_datasource;
	Viewprop_DBCheckBox->DataField="VIEWPROP";

	//������� �� ������� ����� ������������� (��������)
	Table_Agent_Status = new TIBTable(NULL);
	Table_Agent_Status->Database=MainConn;
	Table_Agent_Status->Transaction=TransactionRole;
	Table_Agent_Status->TableName = "ITEMS";
	Table_Agent_Status->Filter="RAZDEL=52";
	Table_Agent_Status->Filtered=TRUE;
	Table_Agent_Status->Active = true;
	Table_Agent_Status->FetchAll();

    //���� �� ���� ������� �������
	 Table_Agent_Status->First();
	 do {
		Status_ComboBox->Items->Add(Table_Agent_Status->FieldByName("FULLNAME")->AsString);
		Table_Agent_Status->Next();
	 } while(!Table_Agent_Status->Eof);
	 Table_Agent_Status->First();

	 Role_datasource->DataSet->Locate("STATUSID", Table_Agent_Status->FieldByName("CODE")->AsString.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);

	 Status_ComboBox->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentRole::Button1Click(TObject *Sender)
{
	//�������� ���������
	Role_datasource->DataSet->CheckBrowseMode();
	//�������� ��������� � ���� ������
	TransactionRole->CommitRetaining();
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentRole::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentRole::Status_ComboBoxClick(TObject *Sender)
{
	Table_Agent_Status->First();
	Table_Agent_Status->MoveBy(Status_ComboBox->ItemIndex);

	Role_datasource->DataSet->Locate("STATUSID", Table_Agent_Status->FieldByName("CODE")->AsString.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive);
}
//---------------------------------------------------------------------------

void __fastcall TFormAgentRole::Button3Click(TObject *Sender)
{
	FormAgentRoleAdd = new TFormAgentRoleAdd(this);
	FormAgentRoleAdd->ShowModal();
	delete FormAgentRoleAdd;
}
//---------------------------------------------------------------------------

