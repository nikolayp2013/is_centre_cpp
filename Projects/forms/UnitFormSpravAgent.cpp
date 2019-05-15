//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormSpravAgent.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IBCustomDataSet"
#pragma link "IBDatabase"
#pragma resource "*.dfm"
TFormSpravAgent *FormSpravAgent;
//---------------------------------------------------------------------------
__fastcall TFormSpravAgent::TFormSpravAgent(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSpravAgent::Button3Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormSpravAgent::ProcFind(TObject *Sender)
{
    // Процедура поиска
	IBDataSet1->Active = false;
	IBDataSet1->SelectSQL->Clear();
	String tmpSQL = "";
	if (!Comp_Edit->Text.IsEmpty()) {
		 if (!tmpSQL.IsEmpty()) {
			tmpSQL = tmpSQL + " and upper(comp collate PXW_CYRL) like '%" + AnsiUpperCase(Comp_Edit->Text) +"%'";
		 } else {
			tmpSQL = tmpSQL + " where upper(comp collate PXW_CYRL) like '%" + AnsiUpperCase(Comp_Edit->Text) +"%'";
		 }
	}
	if (!Fgent_Edit->Text.IsEmpty()) {
		 if (!tmpSQL.IsEmpty()) {
			tmpSQL = tmpSQL + " and upper(agent collate PXW_CYRL) like '%" + AnsiUpperCase(Fgent_Edit->Text) +"%'";
		 } else {
			tmpSQL = tmpSQL + " where upper(agent collate PXW_CYRL) like '%" + AnsiUpperCase(Fgent_Edit->Text) +"%'";
		 }
	}
	if (!Phone_Edit->Text.IsEmpty()) {
		 if (!tmpSQL.IsEmpty()) {
			tmpSQL = tmpSQL + " and phone like '%" + Phone_Edit->Text +"%'";
		 } else {
			tmpSQL = tmpSQL + " where phone like '%" + Phone_Edit->Text +"%'";
		 }
	}
	IBDataSet1->SelectSQL->Append("select * from agents "+tmpSQL+" order by comp");
	IBDataSet1->Active = TRUE;
	DBGrid1->Refresh();
}
//---------------------------------------------------------------------------




void __fastcall TFormSpravAgent::Comp_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	ProcFind(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormSpravAgent::Fgent_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	ProcFind(this);
}
//---------------------------------------------------------------------------

void __fastcall TFormSpravAgent::Phone_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	ProcFind(this);
}
//---------------------------------------------------------------------------

