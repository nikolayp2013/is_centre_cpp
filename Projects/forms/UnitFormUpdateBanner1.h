//---------------------------------------------------------------------------

#ifndef UnitFormUpdateBanner1H
#define UnitFormUpdateBanner1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "UnitFormSwap.h"
//---------------------------------------------------------------------------
class TFormUpdateBanner1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TPanel *Panel1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormUpdateBanner1(TComponent* Owner, TSQLConnection *SQLConnection1_loc);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormUpdateBanner1 *FormUpdateBanner1;
//---------------------------------------------------------------------------
#endif
