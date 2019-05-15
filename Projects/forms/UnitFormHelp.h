//---------------------------------------------------------------------------

#ifndef UnitFormHelpH
#define UnitFormHelpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
//---------------------------------------------------------------------------
class TFormHelp : public TForm
{
__published:	// IDE-managed Components
	TCppWebBrowser *CppWebBrowser1;
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormHelp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormHelp *FormHelp;
//---------------------------------------------------------------------------
#endif
