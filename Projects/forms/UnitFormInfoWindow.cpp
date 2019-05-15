//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormInfoWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TFormInfoWindow *FormInfoWindow;
//AnsiString sPath = ExtractFileDir(Application->ExeName);
//---------------------------------------------------------------------------
__fastcall TFormInfoWindow::TFormInfoWindow(TComponent* Owner)
	: TForm(Owner)
{
	WebBrowser1->Navigate(sPath+"\\Html\\Main.htm");
	WebBrowser2->Navigate(sPath+"\\Html\\extern.htm");
	//WebBrowser4->Navigate(sPath+"\\Html\\extern.htm");
	WebBrowser3->Navigate(sPath+"\\Html\\Mainhlp.htm");

	ComboBox1->Items->Add("Все");
	ComboBox1->Items->Add("Свои");
	ComboBox1->Items->Add("1");
	ComboBox1->Items->Add("2");
	ComboBox1->Items->Add("3");
}
//---------------------------------------------------------------------------
void __fastcall TFormInfoWindow::PageControl1DrawTab(TCustomTabControl *Control, int TabIndex,
          const TRect &Rect, bool Active)
{
	TPageControl *control = (TPageControl*)Control;
	//control->Canvas->Brush->Color = clRed; // НЕОБХОДИМЫЙ ЦВЕТ!!!
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


void __fastcall TFormInfoWindow::BitBtn1Click(TObject *Sender)
{
	// Кнопка назад
	if (PageControl1->TabIndex==0) {
		try {
			WebBrowser2->GoBack();
		}
		catch(Exception *ex) {
			//WebBrowser2->GoHome();
		}
	}
	if (PageControl1->TabIndex==1) {
    	try {
			WebBrowser1->GoBack();
		}
		catch(Exception *ex) {
			//WebBrowser1->GoHome();
		}
	}
	if (PageControl1->TabIndex==2) {
		try {
			WebBrowser3->GoBack();
		}
		catch(Exception *ex) {
			//WebBrowser3->GoHome();
		}
	}
	if (PageControl1->TabIndex==3) {
		try {
			//WebBrowser4->GoBack();
		}
		catch(Exception *ex) {
			//WebBrowser2->GoHome();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormInfoWindow::BitBtn2Click(TObject *Sender)
{
	// Кнопка вперед
	if (PageControl1->TabIndex==0) {
		try {
			WebBrowser2->GoForward();
		}
		catch(Exception *ex) {
			//WebBrowser3->GoHome();
		}
	}
	if (PageControl1->TabIndex==1) {
		try {
			WebBrowser1->GoForward();
		}
		catch(Exception *ex) {
			//WebBrowser3->GoHome();
		}
	}
	if (PageControl1->TabIndex==2) {
		try {
			WebBrowser3->GoForward();
		}
		catch(Exception *ex) {
			//WebBrowser3->GoHome();
		}
	}
	if (PageControl1->TabIndex==3) {
		try {
			//WebBrowser4->GoForward();
		}
		catch(Exception *ex) {
			//WebBrowser3->GoHome();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormInfoWindow::BitBtn3Click(TObject *Sender)
{
	// Кнопка печать
	if (PageControl1->TabIndex==0) {
		try {
			WebBrowser2->ExecWB(::OLECMDID_PRINT, ::OLECMDEXECOPT_PROMPTUSER);
		}
		catch(Exception *ex) {
			 //ShowMessage("Не найден принтер");
		}
	}
	if (PageControl1->TabIndex==1) {
		try {
			WebBrowser1->ExecWB(::OLECMDID_PRINT, ::OLECMDEXECOPT_PROMPTUSER);
		}
		catch(Exception *ex) {
			//WebBrowser3->GoHome();
		}
	}
	if (PageControl1->TabIndex==2) {
		try {
			WebBrowser3->ExecWB(::OLECMDID_PRINT, ::OLECMDEXECOPT_PROMPTUSER);
		}
		catch(Exception *ex) {
			//WebBrowser3->GoHome();
		}
	}
	if (PageControl1->TabIndex==3) {
		try {
			//WebBrowser4->ExecWB(::OLECMDID_PRINT, ::OLECMDEXECOPT_PROMPTUSER);
		}
		catch(Exception *ex) {
			 //ShowMessage("Не найден принтер");
		}
	}
}
//---------------------------------------------------------------------------


