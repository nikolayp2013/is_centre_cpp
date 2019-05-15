//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormExcelExportWidth.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormExcelExportWidth *FormExcelExportWidth;
int * swenter;
extern int * swenter;
int * newwidth;
extern int * newwidth;
//---------------------------------------------------------------------------
__fastcall TFormExcelExportWidth::TFormExcelExportWidth(TComponent* Owner, int * swenter_local, int * newwidth_local)
	: TForm(Owner)
{
	swenter=swenter_local;
	newwidth=newwidth_local;
}
//---------------------------------------------------------------------------
void __fastcall TFormExcelExportWidth::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormExcelExportWidth::Button1Click(TObject *Sender)
{
	*swenter = 1;
	*newwidth=MaskEdit1->Text.ToInt();
	Close();
}
//---------------------------------------------------------------------------
