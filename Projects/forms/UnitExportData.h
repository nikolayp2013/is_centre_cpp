//---------------------------------------------------------------------------

#ifndef UnitExportDataH
#define UnitExportDataH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "MainClass.h"
//---------------------------------------------------------------------------
class TFormExportData : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet4;
	TTabSheet *TabSheet5;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button3;
	TCheckBox *CheckBox1;
	TLabel *Label2;
	TEdit *Edit2;
	TButton *Button4;
	TLabel *Label3;
	TEdit *Edit3;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall PageControl1DrawTab(TCustomTabControl *Control, int TabIndex, const TRect &Rect,
          bool Active);
private:	// User declarations
public:		// User declarations
	__fastcall TFormExportData(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormExportData *FormExportData;
//---------------------------------------------------------------------------
#endif
