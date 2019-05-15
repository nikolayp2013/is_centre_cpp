//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitExportData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormExportData *FormExportData;
//---------------------------------------------------------------------------
__fastcall TFormExportData::TFormExportData(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormExportData::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormExportData::PageControl1DrawTab(TCustomTabControl *Control, int TabIndex,
          const TRect &Rect, bool Active)
{
	TPageControl *control = (TPageControl*)Control;
	//control->Canvas->Brush->Color = clRed; // менаундхлши жбер!!!
	control->Canvas->Font = control->Font;
	//control->Canvas->Font->Style = Active ? control->Canvas->Font->Style << fsBold : control->Canvas->Font->Style >> fsBold;

	AnsiString text = control->Pages[TabIndex]->Caption;
	int textWidth = control->Canvas->TextWidth(text);
	int textHeight = control->Canvas->TextHeight(text);
	int textTop = Rect.Top + (Rect.Height() - textHeight)/2;
	int textLeft = Rect.Left + (Rect.Width() - textWidth)/2;

	control->Canvas->FillRect(Rect);
	control->Canvas->TextOut(textLeft, textTop, text);
}
//---------------------------------------------------------------------------
