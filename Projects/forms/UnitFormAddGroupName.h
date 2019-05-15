//---------------------------------------------------------------------------

#ifndef UnitFormAddGroupNameH
#define UnitFormAddGroupNameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFormGroupEdit.h"
//---------------------------------------------------------------------------
class TFormAddGroupName : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TLabel *Label1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAddGroupName(TComponent* Owner, TIBTable * Table_Group_local, int * retval_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAddGroupName *FormAddGroupName;
//---------------------------------------------------------------------------
#endif
