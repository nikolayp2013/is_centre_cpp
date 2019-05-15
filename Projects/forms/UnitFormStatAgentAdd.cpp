//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormStatAgentAdd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxDesgn"
#pragma link "frxIBXComponents"
#pragma resource "*.dfm"
TFormStatAgAdd *FormStatAgAdd;
//---------------------------------------------------------------------------
__fastcall TFormStatAgAdd::TFormStatAgAdd(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormStatAgAdd::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormStatAgAdd::Button1Click(TObject *Sender)
{
	frxReport1->ShowReport(true);
}
//---------------------------------------------------------------------------

