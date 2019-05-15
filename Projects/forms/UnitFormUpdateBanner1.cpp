//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormUpdateBanner1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormUpdateBanner1 *FormUpdateBanner1;
TSQLConnection *SQLConnection1 = NULL;
extern TSQLConnection *SQLConnection1;
TSimpleDataSet * Table_updatebanner = NULL;
extern TSimpleDataSet * Table_updatebanner;
//---------------------------------------------------------------------------
__fastcall TFormUpdateBanner1::TFormUpdateBanner1(TComponent* Owner, TSQLConnection *SQLConnection1_loc)
	: TForm(Owner)
{
	SQLConnection1 = SQLConnection1_loc;
	Table_updatebanner = new TSimpleDataSet(NULL);
	Table_updatebanner->Connection = SQLConnection1;
	Table_updatebanner->DataSet->CommandType = ctTable;
	Table_updatebanner->DataSet->CommandText="UpdateBanner";
	Table_updatebanner->DataSet->Active = true;

	//ShowMessage(Table_updatebanner->DataSet->RecordCount);
	//Image1->Picture->Assign(Table_pics_Datasource->DataSet->FieldByName("PICS"));
	//Image1->Picture->Assign(Table_updatebanner->DataSet->FieldByName("BANNER"));

	TJPEGImage *jpg = new TJPEGImage();
		try {
			jpg->Assign(Table_updatebanner->DataSet->FieldByName("BANNER"));
			Image1->Picture->Assign(jpg);
		}
		catch(Exception *ex) {
			Image1->Picture->Assign(Table_updatebanner->DataSet->FieldByName("BANNER"));
		}
		delete jpg;
}
//---------------------------------------------------------------------------
void __fastcall TFormUpdateBanner1::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
