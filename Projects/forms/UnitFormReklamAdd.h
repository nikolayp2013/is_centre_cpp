//---------------------------------------------------------------------------

#ifndef UnitFormReklamAddH
#define UnitFormReklamAddH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "MainClass.h"
#include "UnitFormReklam.h"
//---------------------------------------------------------------------------
class TFormReklamAdd : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TMemo *Memo1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormReklamAdd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReklamAdd *FormReklamAdd;
//---------------------------------------------------------------------------
#endif
