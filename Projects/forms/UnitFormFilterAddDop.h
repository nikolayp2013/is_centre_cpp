//---------------------------------------------------------------------------

#ifndef UnitFormFilterAddDopH
#define UnitFormFilterAddDopH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFormFilterAdd.h"
//---------------------------------------------------------------------------
class TFormFilterAddDop : public TForm
{
__published:	// IDE-managed Components
	TListBox *Filter_ListBox;
	TButton *Button1;
	TEdit *Filter_Edit;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormFilterAddDop(TComponent* Owner, TIBDatabase * MainConn_loc);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFilterAddDop *FormFilterAddDop;
//---------------------------------------------------------------------------
#endif
