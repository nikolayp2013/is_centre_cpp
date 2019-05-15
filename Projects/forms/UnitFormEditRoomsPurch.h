//---------------------------------------------------------------------------

#ifndef UnitFormEditRoomsPurchH
#define UnitFormEditRoomsPurchH
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
class TFormEditRoomsPurch : public TForm
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
	TShape *Shape9;
	TShape *Shape10;
	TDBCheckBox *Swbalcony_DBCheckBox;
	TDBCheckBox *Swloggia_DBCheckBox;
	TDBCheckBox *Swphone_DBCheckBox;
	TDBMemo *Addinfo_DBMemo;
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
	TShape *Shape5;
	TButton *Typehouse_Button;
	TButton *Stuffwall_Button;
	TButton *Region_Button;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TDBEdit *Typehouse_DBEdit;
	TDBEdit *Stuffwall_DBEdit;
	TDBEdit *Region_DBEdit;
	TRadioButton *Flow_1_RadioButton;
	TRadioButton *Flow_2_RadioButton;
	TRadioButton *Flow_3_RadioButton;
	TRadioButton *Flow_4_RadioButton;
	TRadioButton *Flow_5_RadioButton;
	TRadioButton *Flow_6_RadioButton;
	TRadioButton *Flow_7_RadioButton;
	TButton *Flat_Button;
	TDBEdit *Flat_DBEdit;
	TButton *Button10;
	TShape *Shape1;
	TPanel *Panel1;
	TRadioButton *Room_RadioButton;
	TRadioButton *Gost_RadioButton;
	TLabel *Label5;
	TDBEdit *Rooms_DBEdit;
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
	__fastcall TFormEditRoomsPurch(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEditRoomsPurch *FormEditRoomsPurch;
//---------------------------------------------------------------------------
#endif
