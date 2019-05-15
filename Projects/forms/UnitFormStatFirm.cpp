//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormStatFirm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IBCustomDataSet"
#pragma link "IBDatabase"
#pragma link "IBQuery"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxDBXComponents"
#pragma link "frxDesgn"
#pragma resource "*.dfm"
TFormStatFirm *FormStatFirm;
//---------------------------------------------------------------------------
__fastcall TFormStatFirm::TFormStatFirm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormStatFirm::Button2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormStatFirm::CheckBox1Click(TObject *Sender)
{
	IBQuery1->Close();
	if (CheckBox1->Checked) {
		IBQuery1->Params->ParamByName("chk0")->AsInteger = 1;
	} else {
		IBQuery1->Params->ParamByName("chk0")->AsInteger = 0;
	}
	//IBQuery2->Params->CreateParam(ftInteger,"idparent",ptInput);
	//AnsiString s="INSERT INTO TABLE_PICS (IDPRICE,PICS,REMARK,IDPARENT) VALUES (:idparent,:BlobsImage,:remark,:guidpar)";
	//IBQuery2->Params->ParamByName("idparent")->AsInteger=Table_pics_Datasource->DataSet->FieldByName("IDPRICE")->AsInteger;
	//IBQuery1->ExecSQL();
	IBQuery1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFormStatFirm::Button1Click(TObject *Sender)
{
	frxReport1->ShowReport(true);
}
//---------------------------------------------------------------------------

