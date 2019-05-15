//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormEditArendPurch.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBLookupComboBoxCentre"
#pragma link "my_DBCtrls"
#pragma resource "*.dfm"
TFormEditArendPurch *FormEditArendPurch;
// ������� �� ������� ���������
TIBTable * Table_Items = NULL;
extern TIBTable * Table_Items;
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
TIBTransaction * OtherTransaction = NULL;
extern TIBTransaction * OtherTransaction;
//---------------------------------------------------------------------------
__fastcall TFormEditArendPurch::TFormEditArendPurch(TComponent* Owner)
	: TForm(Owner)
{
	/*OtherTransaction = new TIBTransaction(NULL);
	OtherTransaction->DefaultDatabase = MainForm->MainConn;

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

	//������� �������� �� ������ ���������
	Table_Items = new TIBTable(NULL);
	Table_Items->Database=MainForm->MainConn;
	Table_Items->Transaction=OtherTransaction;
	Table_Items->TableName = "ITEMS";
	Table_Items->Filter = "Razdel=8";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==1) {
		Flow_1_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==2) {
		Flow_2_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==3) {
		Flow_3_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==4) {
		Flow_4_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==5) {
		Flow_5_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==6) {
		Flow_6_RadioButton->Checked = true;
	}
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger==7) {
		Flow_7_RadioButton->Checked = true;
	} */
}
//---------------------------------------------------------------------------
void __fastcall TFormEditArendPurch::ProcRefreshClient(TObject *Sender)
{
	Clients_Datasource->DataSet->Active=true;
	Clients_Datasource->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
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
//---------------------------------------------------------------------------
void __fastcall TFormEditArendPurch::BitBtn1Click(TObject *Sender)
{
	// ������ ��������� ���������
	if (Flow_1_RadioButton->Checked) {
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger=1;
	}
	if (Flow_2_RadioButton->Checked) {
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger=2;
	}
	if (Flow_3_RadioButton->Checked) {
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger=3;
	}
	if (Flow_4_RadioButton->Checked) {
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger=4;
	}
	if (Flow_5_RadioButton->Checked) {
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger=5;
	}
	if (Flow_6_RadioButton->Checked) {
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger=6;
	}
	if (Flow_7_RadioButton->Checked) {
		MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("LEVEL")->AsInteger=7;
	}
	//�������� ���������
	MainForm->TabPricelist_Datasource_Main->DataSet->CheckBrowseMode();
	//�������� ��������� � ���� ������
	OtherTransaction->CommitRetaining();
	//������� ����� ������
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormEditArendPurch::Flat_ButtonClick(TObject *Sender)
{
	// ������ ������� "��������"
	Table_Items->Active=false;
	Table_Items->Filtered = false;
	Table_Items->Filter = "Razdel=56";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	UnicodeString * resultstr = new UnicodeString;
	*resultstr = MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("FLAT")->AsString;

	FormSelect = new TFormSelect(this, Table_Items, resultstr);
	FormSelect->ShowModal();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("FLAT")->AsString = *resultstr;
	delete FormSelect;
	delete resultstr;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::Region_ButtonClick(TObject *Sender)
{
	// ������ ������� �����
	Table_Items->Active=false;
	Table_Items->Filtered = false;
	Table_Items->Filter = "Razdel=8";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	UnicodeString * resultstr = new UnicodeString;
	*resultstr = MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("REGION")->AsString;

	FormSelect = new TFormSelect(this, Table_Items, resultstr);
	FormSelect->ShowModal();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("REGION")->AsString = *resultstr;
	delete FormSelect;
	delete resultstr;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::Button10Click(TObject *Sender)
{
	// �������� ���� "��������"
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("FLAT")->AsString = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::Typehouse_ButtonClick(TObject *Sender)
{
	// ������ ������� �������������� ����
	Table_Items->Active=false;
	Table_Items->Filtered = false;
	Table_Items->Filter = "Razdel=9";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	UnicodeString * resultstr = new UnicodeString;
	*resultstr = MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("TYPEHOUSE")->AsString;

	FormSelect = new TFormSelect(this, Table_Items, resultstr);
	FormSelect->ShowModal();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("TYPEHOUSE")->AsString = *resultstr;
	delete FormSelect;
	delete resultstr;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::Button11Click(TObject *Sender)
{
	// �������� ���� �������������� ����
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("TYPEHOUSE")->AsString = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::Stuffwall_ButtonClick(TObject *Sender)
{
	// ������ ������� �������� ����
	Table_Items->Active=false;
	Table_Items->Filtered = false;
	Table_Items->Filter = "Razdel=6";
	Table_Items->Filtered = true;
	Table_Items->Active=true;
	Table_Items->FetchAll();

	UnicodeString * resultstr = new UnicodeString;
	*resultstr = MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("STUFFWALL")->AsString;

	FormSelect = new TFormSelect(this, Table_Items, resultstr);
	FormSelect->ShowModal();
	MainForm->TabPricelist_Datasource_Main->DataSet->Edit();
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("STUFFWALL")->AsString = *resultstr;
	delete FormSelect;
	delete resultstr;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::Button12Click(TObject *Sender)
{
	 // �������� ���� �������� ����
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("STUFFWALL")->AsString = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::Button13Click(TObject *Sender)
{
	// �������� ���� �����
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("REGION")->AsString = "";
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::PageControl1DrawTab(TCustomTabControl *Control,
          int TabIndex, const TRect &Rect, bool Active)
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

void __fastcall TFormEditArendPurch::SpeedButton1Click(TObject *Sender)
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

void __fastcall TFormEditArendPurch::SpeedButton3Click(TObject *Sender)
{
	 MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("CLIENT")->AsInteger=0;
	// ����� ��������� ���������� �������� � �������
	ProcRefreshClient(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::RefreshAgent(TObject *Sender)
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
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::Agent_ComboBoxClick(TObject *Sender)
{
	Agent_datasource->DataSet->Active=true;
	Agent_datasource->DataSet->First();
	Agent_datasource->DataSet->MoveBy(Agent_ComboBox->ItemIndex);
	MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("IDAGENT")->AsInteger=
		Agent_datasource->DataSet->FieldByName("ID")->AsInteger;
	RefreshAgent(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::Button1Click(TObject *Sender)
{
	FormAgKartEdit = new TFormAgKartEdit(this,Agent_datasource,MainForm->MainConn,TransactionAgent);
	FormAgKartEdit->ShowModal();
	delete FormAgKartEdit;
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::BitBtn2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEditArendPurch::FormActivate(TObject *Sender)
{
	// ��������
	Flat_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Flat_DBEdit->DataField="FLAT";

	// ��������������
	Typehouse_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Typehouse_DBEdit->DataField="TYPEHOUSE";

	// �������� ����
	Stuffwall_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Stuffwall_DBEdit->DataField="STUFFWALL";

	// �����
	Region_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Region_DBEdit->DataField="REGION";

	//
	Compstr_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Compstr_DBEdit->DataField="COMPSTR";

	// � �����
	Num_card_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Num_card_DBEdit->DataField="NUM_CARD";

	// ������
	Swbalcony_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swbalcony_DBCheckBox->DataField="SWBALCONY";

	// ������
	Swloggia_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swloggia_DBCheckBox->DataField="SWLOGGIA";

	// ������
	Swphone_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swphone_DBCheckBox->DataField="SWPHONE";

	// �������������� ����������
	Addinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Addinfo_DBMemo->DataField="ADDINFO";

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
	// ���
	Swrub_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Swrub_DBCheckBox->DataField="SWRUB";
	// ���� ��
	Pricefrom_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Pricefrom_DBEdit->DataField="PRICEFROM";
	// ���� ��
	Priceto_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Priceto_DBEdit->DataField="PRICETO";
	// ���� �����
	Date_enter_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Date_enter_DBEdit->DataField="DATE_ENTER";
	// ���� �������������
	Date_ch_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Date_ch_DBEdit->DataField="DATE_CH";
	// �������������� ���������� ��� ������
	Agentinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Agentinfo_DBMemo->DataField="AGENTINFO";
	// ��������� ����������
	Reklinfo_DBMemo->DataSource=MainForm->TabPricelist_Datasource_Main;
	Reklinfo_DBMemo->DataField="REKLINFO";
	// ���-�� ������
	Rooms_DBEdit->DataSource=MainForm->TabPricelist_Datasource_Main;
	Rooms_DBEdit->DataField="ROOMS";
	// ��������/�������
	if (MainForm->TabPricelist_Datasource_Main->DataSet->FieldByName("TYPEFLAT")->AsInteger==1) {
		Typeflat1_RadioButton->Checked = true;
	} else {
		Typeflat2_RadioButton->Checked = true;
	}
	// ������
	Furniture_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Furniture_DBCheckBox->DataField="FURNITURE";

	// �����������
	Refrigerator_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Refrigerator_DBCheckBox->DataField="REFRIGERATOR";

	// �����
	Audio_DBCheckBox->DataSource=MainForm->TabPricelist_Datasource_Main;
	Audio_DBCheckBox->DataField="AUDIO";
}
//---------------------------------------------------------------------------

