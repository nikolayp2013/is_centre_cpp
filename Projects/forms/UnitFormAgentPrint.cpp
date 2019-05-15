//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormAgentPrint.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAgentPrint *FormAgentPrint;
//---------------------------------------------------------------------------
__fastcall TFormAgentPrint::TFormAgentPrint(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentPrint::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentPrint::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
