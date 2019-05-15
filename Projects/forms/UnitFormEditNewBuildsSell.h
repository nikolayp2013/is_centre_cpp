//---------------------------------------------------------------------------

#ifndef UnitFormEditNewBuildsSellH
#define UnitFormEditNewBuildsSellH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <My_DBCtrls.hpp>
#include "IBCustomDataSet.hpp"
#include "IBTable.hpp"
#include <DB.hpp>
#include "MainClass.h"
#include "UnitFormKartHistory.h"
#include "Winuser.h"
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include "IBDatabase.hpp"
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <FormGallary.h>
#include <UnitFormMap.h>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <ADODB.hpp>
//#include "DBLookupListBoxCen.h"
//#include "DBLookupComboBoxCen.h"
#include <strsafe.h>
#include <windows.h>
#include "DBLookupComboBoxCentre.h"
#include "DBLookupListBoxCentre.h"
#include <UnitFormKlients.h>

//#include "stdafx.h"
//#include <afxwin.h>

//---------------------------------------------------------------------------

class TFormEditNewBuildsSell : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape2;
	TLabel *Label1;
	TLabel *Label5;
	TShape *Shape1;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label12;
	TDBEdit *Part_DBEdit;
	TDBCheckBox *Mortgage_DBCheckBox;
	TShape *Shape3;
	TLabel *Label13;
	TDBEdit *Num_card_DBEdit;
	TDBEdit *Compstr_DBEdit;
	TShape *Shape4;
	TLabel *Label14;
	TLabel *Label15;
	TDBEdit *AgentMainphone_DBEdit;
	TDBCheckBox *AgChkname_DBCheckBox;
	TDBCheckBox *AgChkprice_DBCheckBox;
	TDBCheckBox *AgChkSot_DBCheckBox;
	TDBCheckBox *AgChke_mail_DBCheckBox;
	TDBCheckBox *AgChkmain_DBCheckBox;
	TDBCheckBox *AgChkadd_DBCheckBox;
	TButton *Button1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TSpeedButton *SpeedButton2;
	TLabel *Label35;
	TDBMemo *Addinfo_DBMemo;
	TShape *Shape12;
	TLabel *Label38;
	TLabel *Label39;
	TDBEdit *ClientPhone_DBEdit;
	TDBEdit *ClientName_DBEdit;
	TLabel *Label40;
	TDBEdit *ClientPager_DBEdit;
	TLabel *Label41;
	TDBEdit *ClientOperator_DBEdit;
	TLabel *Label42;
	TDBEdit *ClientComp_DBEdit;
	TLabel *Label43;
	TDBEdit *ClientMobile_DBEdit;
	TLabel *Label44;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton1;
	TLabel *Label45;
	TDBMemo *Agentinfo_DBMemo;
	TLabel *Label46;
	TDBMemo *Reklinfo_DBMemo;
	TShape *Shape13;
	TShape *Shape14;
	TLabel *Label48;
	TDBEdit *Date_enter_DBEdit;
	TDBEdit *Date_ch_DBEdit;
	TLabel *Label49;
	TDBLookupComboBoxCentre *Region_DBLookComb;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TDBEdit *Price_DBEdit;
	TLabel *Label50;
	TEdit *ClientKatid_Edit;
	TComboBox *Agent_ComboBox;
	TDBCheckBox *Security_DBCheckBox;
	TDBCheckBox *Konserg_DBCheckBox;
	TDBCheckBox *Ownex_DBCheckBox;
	TDBCheckBox *Trash_DBCheckBox;
	TDBCheckBox *Gaz_DBCheckBox;
	TDBCheckBox *Parking_DBCheckBox;
	TDBCheckBox *Newbuild_DBCheckBox;
	TLabel *Label21;
	TDBLookupComboBoxCentre *Design_DBLookComb;
	TDBLookupComboBoxCentre *State_DBLookComb;
	TLabel *Label30;
	TLabel *Label25;
	TDBCheckBox *Glassbalc_DBCheckBox;
	TDBCheckBox *Glasspack_DBCheckBox;
	TLabel *Label36;
	TDBCheckBox *Doplata_DBCheckBox;
	TDBLookupComboBoxCentre *Varswap_DBLookComb;
	TButton *Button7;
	TLabel *Label3;
	TDBEdit *Cross_DBEdit;
	TLabel *Label4;
	TLabel *Label8;
	TDBEdit *Flat_DBEdit;
	TDBEdit *Corpus_DBEdit;
	TLabel *Label7;
	TLabel *Label6;
	TDBEdit *House_DBEdit;
	TDBLookupComboBoxCentre *mRegion_DBLookComb;
	TLabel *Label53;
	TLabel *Label54;
	TShape *Shape7;
	TShape *Shape16;
	TShape *Shape6;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label20;
	TLabel *Label22;
	TShape *Shape8;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label31;
	TLabel *Label32;
	TLabel *Label33;
	TLabel *Label34;
	TLabel *Label51;
	TDBEdit *Level_DBEdit;
	TDBEdit *Rooms_DBEdit;
	TDBEdit *iRooms_DBEdit;
	TDBEdit *Totalarea_DBEdit;
	TDBEdit *Livearea_DBEdit;
	TDBEdit *Kitchenarea_DBEdit;
	TDBEdit *Loggia_DBEdit;
	TDBEdit *Balcony_DBEdit;
	TDBLookupComboBoxCentre *Typehouse_DBLookComb;
	TDBLookupComboBoxCentre *Stuffwall_DBLookComb;
	TDBLookupComboBoxCentre *Swphone_DBLookComb;
	TDBLookupComboBoxCentre *Nodesan_DBLookComb;
	TDBEdit *Neighbors_DBEdit;
	TShape *Shape5;
	TLabel *Label37;
	TDBEdit *Swapinfo_DBEdit;
	TLabel *Label55;
	TLabel *Label56;
	TLabel *Label59;
	TLabel *Label60;
	TDBLookupComboBoxCentre *State_DBLookupComboBoxCentre;
	TDBLookupComboBoxCentre *Walls_DBLookupComboBoxCentre;
	TDBLookupComboBoxCentre *Floor_DBLookupComboBoxCentre;
	TLabel *Label11;
	TDBLookupComboBoxCentre *Variant_DBLookComb;
	TLabel *Label2;
	TDBEdit *Streets_DBEdit;
	TLabel *Label19;
	TDBEdit *Place_DBEdit;
	TLabel *Label52;
	TDBEdit *Levels_DBEdit;
	TDBEdit *Lift_DBEdit;
	TUpDown *UpDown1;
	TUpDown *UpDown2;
	TDBEdit *Gates_DBEdit;
	TUpDown *UpDown3;
	TLabel *Label57;
	TDBEdit *Flats_DBEdit;
	TLabel *Label58;
	TDBLookupComboBoxCentre *Stuffwal_DBLookupComboBoxCentre;
	TDBEdit *Ready_DBEdit;
	TLabel *Label61;
	TLabel *Label62;
	TDBLookupComboBoxCentre *Plate_DBLookupComboBoxCentre;
	TDBLookupComboBoxCentre *Nodesan_DBLookupComboBoxCentre;
	TLabel *Label63;
	TDBLookupComboBoxCentre *Doors_DBLookupComboBoxCentre;
	TDBLookupComboBoxCentre *Windows_DBLookupComboBoxCentre;
	TLabel *Label64;
	TShape *Shape9;
	TLabel *Label65;
	TLabel *Label66;
	TDBEdit *Yearbuild_DBEdit;
	TLabel *Label67;
	TDBEdit *Quarter_DBEdit;
	TUpDown *UpDown4;
	TLabel *Label68;
	TDBEdit *Firstpay_DBEdit;
	TLabel *Label69;
	TShape *Shape10;
	TDBGrid *DBGrid1;
	TShape *Shape11;
	TLabel *Label70;
	TLabel *Label71;
	TLabel *Label72;
	TLabel *Label73;
	TLabel *Label74;
	TLabel *Label75;
	TLabel *Label76;
	TLabel *Label77;
	TLabel *Label78;
	TLabel *Label79;
	TLabel *Label80;
	TLabel *Label81;
	TLabel *Label82;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TUpDown *UpDown5;
	TShape *Shape15;
	TLabel *Label83;
	TEdit *Edit13;
	TLabel *Label84;
	TEdit *Edit14;
	TShape *Shape17;
	TLabel *Label85;
	TDBLookupComboBoxCentre *DBLookupComboBoxCentre7;
	TLabel *Label47;
	TDBEdit *DBEdit10;
	TLabel *Label86;
	TDBCheckBox *DBCheckBox1;
	TDBCheckBox *DBCheckBox2;
	TLabel *Label87;
	TDBLookupComboBoxCentre *DBLookupComboBoxCentre8;
	TEdit *Edit8;
	TUpDown *UpDown6;
	TEdit *Edit9;
	TUpDown *UpDown7;
	TEdit *Edit10;
	TUpDown *UpDown8;
	TEdit *Edit11;
	TUpDown *UpDown9;
	TEdit *Edit12;
	TButton *Button8;
	TButton *Button9;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall PageControl1DrawTab(TCustomTabControl *Control, int TabIndex, const TRect &Rect,
          bool Active);
	void __fastcall Streets_DBLookupListBoxClick(TObject *Sender);
	void __fastcall Streets_DBEditEnter(TObject *Sender);
	void __fastcall Streets_DBEditExit(TObject *Sender);
	void __fastcall Streets_DBLookupListBoxKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Streets_DBLookupListBoxMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Streets_DBLookupListBoxExit(TObject *Sender);
	void __fastcall Cross_DBEditEnter(TObject *Sender);
	void __fastcall Cross_DBEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Cross_DBEditExit(TObject *Sender);
	void __fastcall Streets_DBEditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall OnApplicationMessage(TMsg & Msg, bool & Handled);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall ProcRefreshClient(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ProcSave(TObject *Sender);
	void __fastcall RefreshAgent(TObject *Sender);
	void __fastcall Agent_ComboBoxClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);


private:	// User declarations
	TMyDBLookupListBox * Streets_DBLookupListBox;
public:		// User declarations
	__fastcall TFormEditNewBuildsSell(TComponent* Owner);
	WNDPROC OldWindowProc;
	WNDPROC OldWindowProcScroll;
	int *yyy;
	//TMyDBLookupListBox * Streets_DBLookupListBox;
};

//class TMy2TDBLookupListBox* : public TDBLookupListBox
//{
//};
//---------------------------------------------------------------------------
extern PACKAGE TFormEditNewBuildsSell *FormEditNewBuildsSell;
//---------------------------------------------------------------------------
#endif
