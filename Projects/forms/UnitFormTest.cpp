//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormTest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IBCustomDataSet"
#pragma link "IBDatabase"
#pragma link "IBTable"
#pragma resource "*.dfm"
TFormTest *FormTest;
//---------------------------------------------------------------------------
__fastcall TFormTest::TFormTest(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormTest::Button1Click(TObject *Sender)
{
	Panel1->Brush->Style=bsCross;
	Panel1->Brush->Color=clBlue;
}
//---------------------------------------------------------------------------


