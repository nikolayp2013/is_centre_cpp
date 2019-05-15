//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormKartHistory.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormKartHistory *FormKartHistory;
TDataSource * History_datasource = NULL;
extern TDataSource * History_datasource;
//---------------------------------------------------------------------------
__fastcall TFormKartHistory::TFormKartHistory(TComponent* Owner, TDataSource * History_datasource_local)
	: TForm(Owner)
{
	History_datasource = History_datasource_local;
	History_DBGrid->DataSource = History_datasource;
}
//---------------------------------------------------------------------------
