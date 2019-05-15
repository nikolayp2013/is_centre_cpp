//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormAgentRoleAdd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAgentRoleAdd *FormAgentRoleAdd;
//---------------------------------------------------------------------------
__fastcall TFormAgentRoleAdd::TFormAgentRoleAdd(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentRoleAdd::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentRoleAdd::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
