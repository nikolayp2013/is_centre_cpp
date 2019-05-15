//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormEditSellAll.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEditSellAll *FormEditSellAll;
// ������� �� ������� ���������
TIBTable * Table_Items = NULL;
extern TIBTable * Table_Items;
UnicodeString * resultstr;
extern UnicodeString * resultstr;
//---------------------------------------------------------------------------
__fastcall TFormEditSellAll::TFormEditSellAll(TComponent* Owner, TIBTable * Table_Items_local,
		UnicodeString * resultstr_local)
	: TForm(Owner)
{
	Table_Items = Table_Items_local;
	resultstr = resultstr_local;
	//���� �� ���� ������� �������
	 Table_Items->First();
	 do {
		Item_ListBox->Items->Add(Table_Items->FieldByName("TABLENAZV")->AsString);
		//if ((*resultstr).Pos(Table_Items->FieldByName("SHORTNAME")->AsString)>0) {
		 //Item_ListBox->Selected[Table_Items->RecNo-1]=true;
	 //}
		Table_Items->Next();
	 } while(!Table_Items->Eof);
	 Table_Items->First();
	 Item_ListBox->ItemIndex = 0;

	 //(*resultstr).Pos("3");
	 //ShowMessage((string)*resultstr->Pos("2"));
}
//---------------------------------------------------------------------------

void __fastcall TFormEditSellAll::SpeedButton1Click(TObject *Sender)
{
	Table_Items->RecNo = Item_ListBox->ItemIndex + 1;
	*resultstr = Table_Items->FieldByName("Tablename")->AsString;
	/*for (int i = 0; i < Item_ListBox->Count; i++) {
		if (Item_ListBox->Selected[i]) {
			Table_Items->RecNo = i+1;
			if (*resultstr=="") {
				*resultstr = *resultstr + Table_Items->FieldByName("Shortname")->AsString;
			} else {
				*resultstr = *resultstr + "," + Table_Items->FieldByName("Shortname")->AsString;
            }
		}
	} */
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormEditSellAll::SpeedButton2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


