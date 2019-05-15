//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitUpdateExe.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormUpdateExe *FormUpdateExe;
//---------------------------------------------------------------------------
__fastcall TFormUpdateExe::TFormUpdateExe(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormUpdateExe::Button1Click(TObject *Sender)
{
	//IdFTP1->Host = "http://http://iscentre-samara.ru/files";
	//IdFTP1->Passive = true;
	//IdFTP1->Connect();
	//IdFTP1->Get("centre.zip", "c:\\temp\\centre.zip", true);
	TMemoryStream *s = new TMemoryStream();
	IdHTTP1->Get("http://iscentre-samara.ru/files/centre.zip", s);
	s->SaveToFile("c:\\temp\\centre.zip");
}
//---------------------------------------------------------------------------
void __fastcall TFormUpdateExe::IdHTTP1Work(TObject *ASender, TWorkMode AWorkMode,
          __int64 AWorkCount)
{
	ProgressBar1->Position = AWorkCount;
}
//---------------------------------------------------------------------------
void __fastcall TFormUpdateExe::IdHTTP1WorkBegin(TObject *ASender, TWorkMode AWorkMode,
          __int64 AWorkCountMax)
{
	ProgressBar1->Position = 0;
	ProgressBar1->Max = AWorkCountMax;
}
//---------------------------------------------------------------------------
