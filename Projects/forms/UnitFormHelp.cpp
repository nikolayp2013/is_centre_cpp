//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormHelp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TFormHelp *FormHelp;
AnsiString sPath = ExtractFileDir(Application->ExeName);
//---------------------------------------------------------------------------
__fastcall TFormHelp::TFormHelp(TComponent* Owner)
	: TForm(Owner)
{
    CppWebBrowser1->Navigate(WideString(sPath+"\\Help\\index.htm").c_bstr());
}
//---------------------------------------------------------------------------
void __fastcall TFormHelp::FormActivate(TObject *Sender)
{
	SetWindowPos(FormHelp->Handle,HWND_NOTOPMOST,0,0,Screen->Width, Screen->Height,SWP_SHOWWINDOW);
}
//---------------------------------------------------------------------------
