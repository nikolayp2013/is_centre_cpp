//---------------------------------------------------------------------------

#ifndef UnitFormSelectBlueH
#define UnitFormSelectBlueH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFormEditApartPurch.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TFormSelectBlue : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TCheckListBox *Item_CheckListBox;
	TBitBtn *BitBtn1;
	void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSelectBlue(TComponent* Owner, TIBTable * Table_Items_local,
		UnicodeString * resultstr_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSelectBlue *FormSelectBlue;
//---------------------------------------------------------------------------
#endif
