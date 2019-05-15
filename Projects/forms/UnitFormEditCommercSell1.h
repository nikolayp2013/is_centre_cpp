//---------------------------------------------------------------------------

#ifndef UnitFormEditCommercSell1H
#define UnitFormEditCommercSell1H
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

class TFormEditCommercSell1 : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape2;
	TLabel *Label5;
	TShape *Shape1;
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
	TLabel *Label47;
	TShape *Shape14;
	TLabel *Label48;
	TDBEdit *Date_enter_DBEdit;
	TDBEdit *Date_ch_DBEdit;
	TLabel *Label49;
	TButton *Button2;
	TDBLookupComboBoxCentre *Region_DBLookComb;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TDBEdit *Price_DBEdit;
	TLabel *Label50;
	TEdit *ClientKatid_Edit;
	TComboBox *Agent_ComboBox;
	TDBCheckBox *Konserg_DBCheckBox;
	TDBCheckBox *Ownex_DBCheckBox;
	TDBCheckBox *Trash_DBCheckBox;
	TDBCheckBox *Parking_DBCheckBox;
	TDBCheckBox *Newbuild_DBCheckBox;
	TLabel *Label21;
	TDBEdit *Yearbuild_DBEdit;
	TDBLookupComboBoxCentre *Design_DBLookComb;
	TLabel *Label30;
	TLabel *Label25;
	TDBCheckBox *Glassbalc_DBCheckBox;
	TDBCheckBox *Glasspack_DBCheckBox;
	TLabel *Label36;
	TDBCheckBox *Doplata_DBCheckBox;
	TDBLookupComboBoxCentre *Varswap_DBLookComb;
	TButton *Button7;
	TDBEdit *Streets_DBEdit;
	TLabel *Label2;
	TLabel *Label3;
	TDBEdit *Cross_DBEdit;
	TLabel *Label4;
	TLabel *Label8;
	TDBEdit *Flat_DBEdit;
	TLabel *Label7;
	TLabel *Label6;
	TDBLookupComboBoxCentre *mRegion_DBLookComb;
	TLabel *Label19;
	TLabel *Label52;
	TDBEdit *Street_DBEdit;
	TLabel *Label53;
	TLabel *Label54;
	TDBLookupComboBoxCentre *Contract_DBLookupComboBoxCentre;
	TDBLookupComboBoxCentre *Formoffer_DBLookupComboBoxCentre;
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
	TDBEdit *Rooms_DBEdit;
	TDBEdit *iRooms_DBEdit;
	TDBEdit *Livearea_DBEdit;
	TDBEdit *Kitchenarea_DBEdit;
	TDBEdit *Loggia_DBEdit;
	TDBEdit *Balcony_DBEdit;
	TDBLookupComboBoxCentre *Typehouse_DBLookComb;
	TDBLookupComboBoxCentre *Swphone_DBLookComb;
	TDBLookupComboBoxCentre *Nodesan_DBLookComb;
	TDBEdit *Neighbors_DBEdit;
	TShape *Shape5;
	TLabel *Label37;
	TDBEdit *Swapinfo_DBEdit;
	TLabel *Label55;
	TLabel *Label56;
	TLabel *Label57;
	TLabel *Label58;
	TLabel *Label59;
	TDBLookupComboBoxCentre *Stuffwall_DBLookupComboBoxCentre;
	TDBEdit *Levels_DBEdit;
	TDBEdit *Amountline_DBEdit;
	TLabel *Label65;
	TShape *Shape10;
	TShape *Shape15;
	TLabel *Label76;
	TDBEdit *Hotwateradd_DBEdit;
	TDBLookupComboBoxCentre *State_DBLookupComboBoxCentre;
	TDBCheckBox *Hotwater_DBCheckBox;
	TLabel *Label11;
	TDBLookupComboBoxCentre *Variant_DBLookComb;
	TDBLookupComboBoxCentre *Source_DBLookComb;
	TLabel *Label10;
	TLabel *Label9;
	TLabel *Label1;
	TDBEdit *Town_DBEdit;
	TDBEdit *Object_DBEdit;
	TLabel *Label61;
	TDBEdit *Totalarea_DBEdit;
	TDBEdit *Landarea_DBEdit;
	TLabel *Label60;
	TLabel *Label62;
	TDBLookupComboBoxCentre *Formowner_DBLookupComboBoxCentre;
	TLabel *Label63;
	TDBEdit *Ownerto_DBEdit;
	TLabel *Label64;
	TDBEdit *Waterdrainadd_DBEdit;
	TDBEdit *Poweradd_DBEdit;
	TDBEdit *Hotingadd_DBEdit;
	TDBEdit *Gazadd_DBEdit;
	TDBCheckBox *Waterdrain_DBCheckBox;
	TDBCheckBox *Power_DBCheckBox;
	TDBCheckBox *Hoting_DBCheckBox;
	TDBCheckBox *Gaz_DBCheckBox;
	TShape *Shape9;
	TLabel *Label66;
	TDBCheckBox *Purpose_DBCheckBox;
	TButton *Typehouse_Button;
	TDBEdit *Purposeuse_DBEdit;
	TButton *Button11;
	TLabel *Label67;
	TDBEdit *Befor_DBEdit;
	TLabel *Label68;
	TDBLookupComboBoxCentre *Hotingi_DBLookupComboBoxCentre;
	TDBLookupComboBoxCentre *Securety_DBLookupComboBoxCentre;
	TLabel *Label69;
	TDBCheckBox *Firesign_DBCheckBox;
	TTabSheet *TabSheet3;
	TLabel *Label70;
	TDBEdit *Balansowner_DBEdit;
	TDBCheckBox *Nal_DBCheckBox;
	TDBLookupComboBoxCentre *Source_DBLookupComboBoxCentre;
	TShape *Shape11;
	TLabel *Label71;
	TDBEdit *Inventnum_DBEdit;
	TLabel *Label72;
	TDBEdit *Code_DBEdit;
	TLabel *Label73;
	TDBEdit *Yearenter_DBEdit;
	TLabel *Label74;
	TDBEdit *House_DBEdit;
	TLabel *Label75;
	TDBEdit *Corpus_DBEdit;
	TLabel *Label77;
	TDBEdit *Liter_DBEdit;
	TLabel *Label78;
	TDBEdit *Houseowner_DBEdit;
	TLabel *Label79;
	TDBEdit *Seller_DBEdit;
	TDBEdit *Sale_DBEdit;
	TLabel *Label80;
	TLabel *Label81;
	TLabel *Label82;
	TDBLookupComboBoxCentre *Owner_DBLookupComboBoxCentre;
	TShape *Shape17;
	TLabel *Label83;
	TDBCheckBox *Beznal_DBCheckBox;
	TDBCheckBox *Mix_DBCheckBox;
	TDBCheckBox *Rub_DBCheckBox;
	TDBCheckBox *Ued_DBCheckBox;
	TShape *Shape18;
	TLabel *Label84;
	TDBCheckBox *Other_DBCheckBox;
	TDBCheckBox *Directpaybefor_DBCheckBox;
	TDBCheckBox *Directpayafter_DBCheckBox;
	TDBCheckBox *Mixakkred_DBCheckBox;
	TDBCheckBox *Mixetap_DBCheckBox;
	TShape *Shape19;
	TLabel *Label85;
	TDBCheckBox *Part_DBCheckBox;
	TDBEdit *Partfrom_DBEdit;
	TLabel *Label86;
	TDBEdit *Partto_DBEdit;
	TLabel *Label87;
	TLabel *Label88;
	TDBEdit *Commprice_DBEdit;
	TDBCheckBox *Kommpay_DBCheckBox;
	TDBMemo *Otheradd_DBMemo;
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
	void __fastcall Typehouse_ButtonClick(TObject *Sender);


private:	// User declarations
	TMyDBLookupListBox * Streets_DBLookupListBox;
public:		// User declarations
	__fastcall TFormEditCommercSell1(TComponent* Owner);
	WNDPROC OldWindowProc;
	WNDPROC OldWindowProcScroll;
	int *yyy;
	//TMyDBLookupListBox * Streets_DBLookupListBox;
};

//class TMy2TDBLookupListBox* : public TDBLookupListBox
//{
//};
//---------------------------------------------------------------------------
extern PACKAGE TFormEditCommercSell1 *FormEditCommercSell1;
//---------------------------------------------------------------------------
#endif
