//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormExcelExportAdd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormExcelExportAdd *FormExcelExportAdd;
int * swenter;
extern int * swenter;
string * nameform;
extern string * nameform;
//---------------------------------------------------------------------------
__fastcall TFormExcelExportAdd::TFormExcelExportAdd(TComponent* Owner, int * swenter_local, string * nameform_local)
	: TForm(Owner)
{
	swenter=swenter_local;
	nameform=nameform_local;
}
//---------------------------------------------------------------------------
void __fastcall TFormExcelExportAdd::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormExcelExportAdd::Button1Click(TObject *Sender)
{
	*swenter=1;
	*nameform = Edit1->Text.c_str();
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormExcelExportAdd::Edit1Enter(TObject *Sender)
{
	//---- Переключение раскладки клавиатуры
	char s[64];
	GetKeyboardLayoutName(s);
	//таким образом получаем текущий язык (активное окно)
	if (s!="00000419") {
		 //LoadKeyboardLayout("00000409", KLF_ACTIVATE);
		//Engлиш
		LoadKeyboardLayout("00000419", KLF_ACTIVATE);
		//Руссиан
	}
}
//---------------------------------------------------------------------------

