//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormAgentFilter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAgentFilter *FormAgentFilter;
//---------------------------------------------------------------------------
__fastcall TFormAgentFilter::TFormAgentFilter(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentFilter::Button4Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAgentFilter::Button5Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
