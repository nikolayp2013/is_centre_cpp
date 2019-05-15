//---------------------------------------------------------------------------

#ifndef UnitFormReklamH
#define UnitFormReklamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MainClass.h"
#include "UnitFormReklamAdd.h"
#include <DB.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormReklam : public TForm
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
	__fastcall TFormReklam(TComponent* Owner, int pricetype);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReklam *FormReklam;
//---------------------------------------------------------------------------
#endif
