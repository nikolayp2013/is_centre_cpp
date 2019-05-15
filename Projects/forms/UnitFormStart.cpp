//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormStart.h"
#include "MainClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IBDatabase"
#pragma link "DataDriverEh"
#pragma link "IBXDataDriverEh"
#pragma link "MemTableDataEh"
#pragma link "MemTableEh"
#pragma resource "*.dfm"
TFormStart *FormStart;
TIBDatabase * MainConn1 = NULL;
double nX = 0;
int CompanyID = 0;
String curVersion = "";
String StartDirF = "";
int ReConnect = 0;
TIBTransaction * MainTransaction = NULL;
extern TIBTransaction * MainTransaction;
//---------------------------------------------------------------------------
__fastcall TFormStart::TFormStart(TComponent* Owner)
	: TForm(Owner)
{
	//������� ������ ����������
	MainTransaction = new TIBTransaction(NULL);
	MainTransaction->DefaultDatabase = MainForm->MainConn;

	ComboBox1->Items->Add("������");
	ComboBox1->ItemIndex=0;

    // ��������� �� �������
	TRegistry *reg=new TRegistry(); //������� ������ reg ������ TRegistry
	reg->RootKey=HKEY_LOCAL_MACHINE;  //��� � ��� ������ ��������� ������ � ������� ����� ��������
	reg->OpenKeyReadOnly("SOFTWARE\\center\\Riel 2.0"); //������ ��������� ���� ��� ������ (����� ���� �� � ������������ OpenKey(), �� ��� ������� ��������� ������ ������ ��������� )
	AnsiString TimeStamp;     //������ � ������� �� ������� �������� ��������� �� �������
	TimeStamp=reg->ReadString("TimeStamp");   //������� ��������, ������ ��� ���� ������ ��� ��������
	reg->CloseKey();   //��������� ����
	delete reg;       //����������� ������

	if (TimeStamp.IsEmpty()) {
		ShowMessage("������ ��� �������� ������� \n��������: TimeStamp");
	}
	for (int i = 1; i < NUM_COMPANIES; i++) {
		if (GenA1(this,i)==TimeStamp) {
			CompanyID = i;
			break;
		}
	}
	AnsiString dollar;
	AnsiString euro;
	AnsiString html;
	//AnsiString splen = "$</span>&nbsp;";
	AnsiString splen = "<td class=\"digit\" align=\"right\" nowrap>";
	IdHTTP1->ReadTimeout = 4000;
	MainForm->work_query->Active = false;
	MainForm->work_query->SQL->Clear();
	try {
		IdHTTP1->Head("http://ya.ru");
		/*html=IdHTTP1->Get("http://m.mail.ru/cgi-bin/splash");
		html.Delete(1,html.Pos("$</span>&nbsp;")+splen.Length()-1);
		dollar=html.SubString(1,html.Pos("&nbsp;<")-1);
		splen = "&euro;</span>&nbsp;";
		html.Delete(1,html.Pos("&euro;</span>&nbsp;")+splen.Length()-1);
		euro=html.SubString(1,html.Pos("&nbsp;<")-1);*/
		html=IdHTTP1->Get("http://cbr.ru");
		html.Delete(1,html.Pos("<td class=\"digit\" align=\"right\" nowrap>")+splen.Length()-1);
		dollar=html.SubString(1,html.Pos("&nbsp;<")-1);
		//splen = "&euro;</span>&nbsp;";
		//html.Delete(1,html.Pos("&euro;</span>&nbsp;")+splen.Length()-1);
		//euro=html.SubString(1,html.Pos("&nbsp;<")-1);
		dollar=dollar.Trim();
		//euro=euro.Trim();
		Label2->Caption = "���� �� "+dollar.SubString(1,5);
		MainForm->work_query->SQL->Add("update valuta set doll="+dollar.SubString(1,2)+"."+dollar.SubString(4,2));
		MainForm->work_query->ExecSQL();
	}
	catch(Exception *ex) {
		MainForm->work_query->SQL->Add("select * from valuta");
		MainForm->work_query->Open();
		Label2->Caption = "���� �� "+ MainForm->work_query->FieldByName("DOLL")->AsString;
	}

	DWORD h;
	DWORD Size=GetFileVersionInfoSize(Application->ExeName.c_str(), &h);
	if (Size!=0) {
		char *buf;
		buf=(char *)GlobalAlloc(GMEM_FIXED, Size);
		if (GetFileVersionInfo(Application->ExeName.c_str(),h,Size,buf)!=0)
		{
			char *ValueBuf;
			UINT Len;
			VerQueryValue(buf, "\\VarFileInfo\\Translation", &(void *)ValueBuf,&Len);
			if (Len>=4)
			{
				AnsiString CharSet=IntToHex((int )MAKELONG(*(int *)(ValueBuf+2),*(int *)ValueBuf), 8);
			//if (VerQueryValue(buf,AnsiString("\\StringFileInfo\\"+CharSet+"\\ProductName").c_str(),&(void *)ValueBuf,&Len) !=0)
				//ShowMessage(ValueBuf);
				//AppName->Caption=ValueBuf;
				if (VerQueryValue(buf,AnsiString("\\StringFileInfo\\"+CharSet+"\\FileVersion").c_str(),&(void *)ValueBuf,&Len)!=0)
					curVersion = ValueBuf;
					//ShowMessage(ValueBuf);

				//Version->Caption=ValueBuf;

			/*if (VerQueryValue(buf,AnsiString("\\StringFileInfo\\"+CharSet+"\\LegalCopyright").c_str(),&(void *)ValueBuf,&Len)!=0)
				ShowMessage(ValueBuf);
				//Copyright->Caption=ValueBuf;

			if (VerQueryValue(buf,AnsiString("\\StringFileInfo\\"+CharSet+"\\CompanyName").c_str(),&(void *)ValueBuf,&Len)!=0)
				ShowMessage(ValueBuf);
				//Company->Caption=ValueBuf;*/
			}
		}
		GlobalFree(buf);
	}
	StartDirF = StringReplace(ExtractFilePath(Application->ExeName),String(char(92)),String(char(92))+String(char(92)),TReplaceFlags()<<rfReplaceAll);
}
//---------------------------------------------------------------------------
void __fastcall TFormStart::Panel2Click(TObject *Sender)
{
	// ������ ������
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormStart::Label1MouseEnter(TObject *Sender)
{
	 Label1->Font->Color = clGreen;
}
//---------------------------------------------------------------------------
void __fastcall TFormStart::Label1MouseLeave(TObject *Sender)
{
	Label1->Font->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TFormStart::Label1Click(TObject *Sender)
{
	// ������ ���������
	FormNastr = new TFormNastr(MainForm, MainForm->MainConn);
	FormNastr->ShowModal();
	delete FormNastr;
}
//---------------------------------------------------------------------------
void __fastcall TFormStart::Panel2MouseEnter(TObject *Sender)
{
	Panel2->BevelOuter=bvRaised;
}
//---------------------------------------------------------------------------
void __fastcall TFormStart::Panel2MouseLeave(TObject *Sender)
{
	Panel2->BevelOuter=bvNone;
}
//---------------------------------------------------------------------------
void __fastcall TFormStart::Panel1MouseEnter(TObject *Sender)
{
     Panel1->BevelOuter=bvRaised;
}
//---------------------------------------------------------------------------
void __fastcall TFormStart::Panel1MouseLeave(TObject *Sender)
{
	 Panel1->BevelOuter=bvNone;
}
//---------------------------------------------------------------------------
void __fastcall TFormStart::Panel1Click(TObject *Sender)
{
	// ������ �������
	FormReg = new TFormReg(this,MainForm->MainConn);
	FormReg->ShowModal();
	delete FormReg;
	while (ReConnect==1){
		ReConnect==0;
		FormReg = new TFormReg(this,MainForm->MainConn);
		FormReg->ShowModal();
		delete FormReg;
	}
	Close();
}
//---------------------------------------------------------------------------

String __fastcall TFormStart::GenA1(TObject *Sender, double nCode)
{
	int j;
	long double tmp1;
	String sCode;
	sCode = "";
	MyRandomize (this,log(nCode + 1));\
	for (j = 1; j <= KEY_LEN; j++) {
		 tmp1 = SimpleRoundTo(MyRnd(this) * 10, 0);
		 sCode = sCode + (String)(double)tmp1;
	}
	return sCode;
}
//---------------------------------------------------------------------------

//void __fastcall TFormStart::MyRandomize(TObject *Sender, long double seed)
void __fastcall TFormStart::MyRandomize(TObject *Sender, double seed)
{
	nX = seed;
	nX = SimpleRoundTo(nX,-1*NUM_DIGITS_CODE);
}
//---------------------------------------------------------------------------

//long double __fastcall TFormStart::MyRnd(TObject *Sender)
double __fastcall TFormStart::MyRnd(TObject *Sender)
{
   String tmp1;
   tmp1 = (String)nX * nX;
   tmp1 = "0,"+tmp1.SubString(NUM_DIGITS_CODE / 2 + 3, NUM_DIGITS_CODE);
   nX = tmp1.ToDouble();
   return nX;
}
//---------------------------------------------------------------------------
