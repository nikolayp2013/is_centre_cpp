//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormSelectV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSelect *FormSelect;
//---------------------------------------------------------------------------
__fastcall TFormSelect::TFormSelect(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSelect::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
