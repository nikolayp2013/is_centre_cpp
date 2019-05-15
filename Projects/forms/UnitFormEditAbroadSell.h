//---------------------------------------------------------------------------

#ifndef UnitFormEditAbroadSellH
#define UnitFormEditAbroadSellH
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

class TFormEditAbroadSell : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label6;
	TLabel *Label7;
	TShape *Shape1;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
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
	TShape *Shape5;
	TLabel *Label16;
	TDBEdit *Levels_DBEdit;
	TShape *Shape8;
	TLabel *Label23;
	TLabel *Label24;
	TDBEdit *Rooms_DBEdit;
	TDBEdit *Totalarea_DBEdit;
	TLabel *Label28;
	TLabel *Label29;
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
	TDBLookupComboBoxCentre *Contract_DBLookComb;
	TDBLookupComboBoxCentre *Source_DBLookComb;
	TDBLookupComboBoxCentre *Variant_DBLookComb;
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
	TDBEdit *Yearbuild_DBEdit;
	TDBLookupComboBoxCentre *Design_DBLookComb;
	TDBLookupComboBoxCentre *State_DBLookComb;
	TLabel *Label30;
	TLabel *Label25;
	TLabel *Label51;
	TDBCheckBox *Glassbalc_DBCheckBox;
	TDBCheckBox *Glasspack_DBCheckBox;
	TLabel *Label36;
	TDBCheckBox *Doplata_DBCheckBox;
	TDBLookupComboBoxCentre *Varswap_DBLookComb;
	TButton *Button7;
	TDBEdit *House_DBEdit;
	TDBEdit *Corpus_DBEdit;
	TDBEdit *Flat_DBEdit;
	TLabel *Label8;
	TDBLookupComboBoxCentre *Region_DBLookComb;
	TDBLookupComboBoxCentre *mRegion_DBLookComb;
	TDBEdit *Cross_DBEdit;
	TDBEdit *Streets_DBEdit;
	TLabel *Label2;
	TDBLookupComboBoxCentre *Real_DBLookupComboBoxCentre;
	TDBEdit *Town_DBEdit;
	TDBLookupComboBoxCentre *Formoffer_DBLookupComboBoxCentre;
	TDBLookupComboBoxCentre *Country_DBLookupComboBoxCentre;
	TLabel *Label1;
	TDBLookupComboBoxCentre *Formowner_DBLookupComboBoxCentre;
	TDBEdit *iRooms_DBEdit;
	TDBEdit *Neighbors_DBEdit;
	TDBLookupComboBoxCentre *Stuffwall_DBLookComb;
	TDBLookupComboBoxCentre *Swphone_DBLookComb;
	TDBEdit *Balcony_DBEdit;
	TDBLookupComboBoxCentre *Nodesan_DBLookComb;
	TDBEdit *Loggia_DBEdit;
	TDBEdit *Level_DBEdit;
	TDBEdit *Livearea_DBEdit;
	TDBEdit *Kitchenarea_DBEdit;
	TDBMemo *Addinfobuild_DBMemo;
	TDBEdit *Landarea_DBEdit;
	TLabel *Label37;
	TDBEdit *Swapinfo_DBEdit;
	TLabel *Label5;
	TDBMemo *Addinfoland_DBMemo;
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
	__fastcall TFormEditAbroadSell(TComponent* Owner);
	WNDPROC OldWindowProc;
	WNDPROC OldWindowProcScroll;
	int *yyy;
	//TMyDBLookupListBox * Streets_DBLookupListBox;
};

//class TMy2TDBLookupListBox* : public TDBLookupListBox
//{
//};
//---------------------------------------------------------------------------
extern PACKAGE TFormEditAbroadSell *FormEditAbroadSell;
//---------------------------------------------------------------------------
#endif
