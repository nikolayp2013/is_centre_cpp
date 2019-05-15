//---------------------------------------------------------------------------

#ifndef UnitFormSelectH
#define UnitFormSelectH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFormEditApartPurch.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormSelect : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TListBox *Item_ListBox;
	TSpeedButton *SpeedButton1;
	void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSelect(TComponent* Owner, TIBTable * Table_Items_local,
		UnicodeString * resultstr_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSelect *FormSelect;
//---------------------------------------------------------------------------
#endif
