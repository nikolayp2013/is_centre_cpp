//---------------------------------------------------------------------------

#ifndef UnitFormFilterAddSearchH
#define UnitFormFilterAddSearchH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "MainClass.h"
//---------------------------------------------------------------------------
class TFormFilterAddSearch : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton9;
	TShape *Shape3;
	TEdit *Edit1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit2;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	void __fastcall SpeedButton9Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormFilterAddSearch(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFilterAddSearch *FormFilterAddSearch;
//---------------------------------------------------------------------------
#endif
