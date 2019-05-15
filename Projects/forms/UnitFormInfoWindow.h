//---------------------------------------------------------------------------

#ifndef UnitFormInfoWindowH
#define UnitFormInfoWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include "MainClass.h"
#include <OleCtrls.hpp>
#include <SHDocVw.hpp>
#include "SHDocVw_OCX.h"
#include "docobj.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormInfoWindow : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TWebBrowser *WebBrowser2;
	TWebBrowser *WebBrowser1;
	TWebBrowser *WebBrowser3;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TDBGrid *DBGrid1;
	TSpeedButton *SpeedButton5;
	TComboBox *ComboBox1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	TBitBtn *BitBtn6;
	TMemo *Memo1;
	void __fastcall PageControl1DrawTab(TCustomTabControl *Control, int TabIndex, const TRect &Rect,
          bool Active);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormInfoWindow(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormInfoWindow *FormInfoWindow;
//---------------------------------------------------------------------------
#endif
