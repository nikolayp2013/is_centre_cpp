//---------------------------------------------------------------------------

#ifndef UnitFormGroupEditH
#define UnitFormGroupEditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
#include "MainClass.h"
#include "UnitFormAddGroupName.h"
//---------------------------------------------------------------------------
class TFormGroupEdit : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape2;
	TShape *Shape1;
	TLabel *Label1;
	TLabel *Label2;
	TListBox *Group_ListBox;
	TCheckListBox *GroupList_CheckListBox;
	TShape *Shape3;
	TButton *ButtonAdd;
	TButton *ButtonDelete;
	TButton *ButtonEdit;
	TButton *ButtonClose;
	void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall RefreshCheck(TObject *Sender);
	void __fastcall FilterCheck(TObject *Sender);
	void __fastcall Group_ListBoxClick(TObject *Sender);
	void __fastcall ButtonEditClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGroupEdit(TComponent* Owner, TIBDatabase * MainConn_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGroupEdit *FormGroupEdit;
//---------------------------------------------------------------------------
#endif
