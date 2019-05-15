//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormFilterAddSearch.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormFilterAddSearch *FormFilterAddSearch;
//---------------------------------------------------------------------------
__fastcall TFormFilterAddSearch::TFormFilterAddSearch(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormFilterAddSearch::SpeedButton9Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
