//---------------------------------------------------------------------------

#ifndef UnitFormSelectVH
#define UnitFormSelectVH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFormEditApartPurch.h"
//---------------------------------------------------------------------------
class TFormSelect : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSelect(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSelect *FormSelect;
//---------------------------------------------------------------------------
#endif
