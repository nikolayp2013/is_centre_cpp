//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormAddGroupName.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAddGroupName *FormAddGroupName;
TIBTable * Table_Group = NULL;
extern TIBTable * Table_Group;
int * retval;
//---------------------------------------------------------------------------
__fastcall TFormAddGroupName::TFormAddGroupName(TComponent* Owner, TIBTable * Table_Group_local, int * retval_local)
	: TForm(Owner)
{
	Table_Group = Table_Group_local;
	retval = retval_local;
}
//---------------------------------------------------------------------------
void __fastcall TFormAddGroupName::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAddGroupName::Button1Click(TObject *Sender)
{
	*retval = 1;
	Table_Group->FieldByName("GROUP_NAME")->AsString = Edit1->Text;
	Close();
}
//---------------------------------------------------------------------------
