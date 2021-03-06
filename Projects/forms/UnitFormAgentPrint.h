//---------------------------------------------------------------------------

#ifndef UnitFormAgentPrintH
#define UnitFormAgentPrintH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "UnitFormAgent.h"
//---------------------------------------------------------------------------
class TFormAgentPrint : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape5;
	TButton *Button1;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAgentPrint(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAgentPrint *FormAgentPrint;
//---------------------------------------------------------------------------
#endif
