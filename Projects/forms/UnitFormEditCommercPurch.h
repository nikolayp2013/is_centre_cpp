//---------------------------------------------------------------------------

#ifndef UnitFormEditCommercPurchH
#define UnitFormEditCommercPurchH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxCentre.h"
#include "my_DBCtrls.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include "MainClass.h"
#include "UnitFormSelect.h"
//---------------------------------------------------------------------------
class TFormEditCommercPurch : public TForm
{
__published:	// IDE-managed Components
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
	TComboBox *Agent_ComboBox;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TShape *Shape12;
	TLabel *Label38;
	TLabel *Label39;
	TLabel *Label40;
	TLabel *Label41;
	TLabel *Label42;
	TLabel *Label43;
	TLabel *Label44;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton1;
	TLabel *Label45;
	TLabel *Label46;
	TLabel *Label50;
	TDBEdit *ClientPhone_DBEdit;
	TDBEdit *ClientName_DBEdit;
	TDBEdit *ClientPager_DBEdit;
	TDBEdit *ClientOperator_DBEdit;
	TDBEdit *ClientComp_DBEdit;
	TDBEdit *ClientMobile_DBEdit;
	TDBMemo *Agentinfo_DBMemo;
	TDBMemo *Reklinfo_DBMemo;
	TEdit *ClientKatid_Edit;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TShape *Shape13;
	TLabel *Label47;
	TDBEdit *Pricefrom_DBEdit;
	TDBCheckBox *Swrub_DBCheckBox;
	TLabel *Label1;
	TDBEdit *Priceto_DBEdit;
	TLabel *Label2;
	TShape *Shape14;
	TDBEdit *Date_enter_DBEdit;
	TDBEdit *Date_ch_DBEdit;
	TLabel *Label48;
	TLabel *Label49;
	TLabel *Label3;
	TLabel *Label4;
	TSpeedButton *ButtonSave;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TButton *Stuffwall_Button;
	TButton *Region_Button;
	TButton *Button12;
	TButton *Button13;
	TDBEdit *Purposeuse_DBEdit;
	TDBEdit *Region_DBEdit;
	TButton *Flat_Button;
	TDBEdit *Flat_DBEdit;
	TButton *Button10;
	TShape *Shape1;
	TLabel *Label5;
	TPanel *Panel1;
	TRadioButton *Room_RadioButton;
	TRadioButton *Gost_RadioButton;
	TDBEdit *Rooms_DBEdit;
	TShape *Shape10;
	TRadioButton *Flow_1_RadioButton;
	TRadioButton *Flow_2_RadioButton;
	TRadioButton *Flow_3_RadioButton;
	TRadioButton *Flow_4_RadioButton;
	TRadioButton *Flow_5_RadioButton;
	TRadioButton *Flow_6_RadioButton;
	TRadioButton *Flow_7_RadioButton;
	TShape *Shape9;
	TDBCheckBox *Swbalcony_DBCheckBox;
	TDBCheckBox *Swloggia_DBCheckBox;
	TDBCheckBox *Swphone_DBCheckBox;
	TShape *Shape2;
	TLabel *Label8;
	TShape *Shape6;
	TLabel *Label9;
	TLabel *Label7;
	TDBEdit *Objareafr_DBEdit;
	TLabel *Label11;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label26;
	TDBEdit *Namequery_DBEdit;
	TLabel *Label10;
	TDBLookupComboBoxCentre *Typeowner_DBLookupComboBoxCentre;
	TLabel *Label27;
	TDBLookupComboBoxCentre *Low_DBLookupComboBoxCentre;
	TLabel *Label28;
	TDBEdit *Objareato_DBEdit;
	TShape *Shape5;
	TLabel *Label6;
	TLabel *Label12;
	TLabel *Label20;
	TDBEdit *Levelfr_DBEdit;
	TDBEdit *Levelto_DBEdit;
	TShape *Shape7;
	TLabel *Label21;
	TLabel *Label24;
	TLabel *Label25;
	TShape *Shape8;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TDBEdit *Roomfr_DBEdit;
	TDBEdit *Roomto_DBEdit;
	TLabel *Label62;
	TDBMemo *Addinfo_DBMemo;
	TLabel *Label32;
	TDBLookupComboBoxCentre *State_DBLookupComboBoxCentre;
	TLabel *Label33;
	TDBLookupComboBoxCentre *Internet_DBLookupComboBoxCentre;
	TLabel *Label34;
	TLabel *Label35;
	TDBEdit *Minphone_DBEdit;
	TDBEdit *Minnodesan_DBEdit;
	TDBCheckBox *Enter_DBCheckBox;
	TDBCheckBox *Public_DBCheckBox;
	TDBCheckBox *Parking_DBCheckBox;
	TDBCheckBox *Hoting_DBCheckBox;
	TDBCheckBox *Hotwater_DBCheckBox;
	TDBCheckBox *Gaz_DBCheckBox;
	TDBCheckBox *Waterdrain_DBCheckBox;
	TShape *Shape11;
	TLabel *Label36;
	TLabel *Label37;
	TLabel *Label51;
	TDBEdit *Landareafr_DBEdit;
	TDBEdit *Landareato_DBEdit;
	TShape *Shape15;
	TLabel *Label52;
	TDBEdit *Power_DBEdit;
	TDBCheckBox *Minpower_DBCheckBox;
	TShape *Shape16;
	TLabel *Label53;
	TLabel *Label54;
	TLabel *Label55;
	TDBEdit *Heightgate_DBEdit;
	TDBEdit *Widthgate_DBEdit;
	TDBCheckBox *Rampa_DBCheckBox;
	TDBCheckBox *Train_DBCheckBox;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall Flat_ButtonClick(TObject *Sender);
	void __fastcall Region_ButtonClick(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Typehouse_ButtonClick(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Stuffwall_ButtonClick(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall ProcRefreshClient(TObject *Sender);
	void __fastcall RefreshAgent(TObject *Sender);
	void __fastcall PageControl1DrawTab(TCustomTabControl *Control, int TabIndex, const TRect &Rect,
          bool Active);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall Agent_ComboBoxClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormEditCommercPurch(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEditCommercPurch *FormEditCommercPurch;
//---------------------------------------------------------------------------
#endif
