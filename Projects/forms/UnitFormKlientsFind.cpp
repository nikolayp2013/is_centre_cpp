//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormKlientsFind.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormKlientsFind *FormKlientsFind;
TDataSource * Clients_Datasource =NULL;
extern TDataSource * Clients_Datasource;
//---------------------------------------------------------------------------
__fastcall TFormKlientsFind::TFormKlientsFind(TComponent* Owner, TDataSource * Clients_Datasource_local)
	: TForm(Owner)
{
	 Clients_Datasource = Clients_Datasource_local;
	 Clients_Datasource->DataSet->First();
}
//---------------------------------------------------------------------------
void __fastcall TFormKlientsFind::Button1Click(TObject *Sender)
{
	if (Clients_Datasource->DataSet->Locate("NAME",Edit1->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive)) {
		Comp_Edit->Text = Clients_Datasource->DataSet->FieldByName("COMP")->AsString;
		Name_Edit->Text = Clients_Datasource->DataSet->FieldByName("NAME")->AsString;
		Abort();
	} else {
		Comp_Edit->Text = "";
		Name_Edit->Text = "";
	}
	if (Clients_Datasource->DataSet->Locate("COMP",Edit1->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive)) {
		Comp_Edit->Text = Clients_Datasource->DataSet->FieldByName("COMP")->AsString;
		Name_Edit->Text = Clients_Datasource->DataSet->FieldByName("NAME")->AsString;
		Abort();
	} else {
		Comp_Edit->Text = "";
		Name_Edit->Text = "";
	}
	if (Clients_Datasource->DataSet->Locate("PHONE",Edit1->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive)) {
		Comp_Edit->Text = Clients_Datasource->DataSet->FieldByName("COMP")->AsString;
		Name_Edit->Text = Clients_Datasource->DataSet->FieldByName("NAME")->AsString;
		Abort();
	} else {
		Comp_Edit->Text = "";
		Name_Edit->Text = "";
	}
	if (Clients_Datasource->DataSet->Locate("MISC",Edit1->Text.c_str(),TLocateOptions() << loPartialKey
			<<loCaseInsensitive)) {
		Comp_Edit->Text = Clients_Datasource->DataSet->FieldByName("COMP")->AsString;
		Name_Edit->Text = Clients_Datasource->DataSet->FieldByName("NAME")->AsString;
		Abort();
	} else {
		Comp_Edit->Text = "";
		Name_Edit->Text = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormKlientsFind::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormKlientsFind::Edit1Enter(TObject *Sender)
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

