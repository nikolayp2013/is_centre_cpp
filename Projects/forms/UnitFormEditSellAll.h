//---------------------------------------------------------------------------

#ifndef UnitFormEditSellAllH
#define UnitFormEditSellAllH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFormEditApartPurch.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormEditSellAll : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *SpeedButton1;
	TListBox *Item_ListBox;
	TSpeedButton *SpeedButton2;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormEditSellAll(TComponent* Owner, TIBTable * Table_Items_local,
		UnicodeString * resultstr_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEditSellAll *FormEditSellAll;
//---------------------------------------------------------------------------
#endif
