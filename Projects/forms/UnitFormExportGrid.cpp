//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormExportGrid.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxExportPDF"
#pragma link "frxExportXLS"
#pragma link "frxExportBIFF"
#pragma resource "*.dfm"
TFormExportGrid *FormExportGrid;
//---------------------------------------------------------------------------
__fastcall TFormExportGrid::TFormExportGrid(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormExportGrid::SpeedButton1Click(TObject *Sender)
{
	// Excel
	MainForm->MainTable->DisableControls();
	// ������ ������ ���������� �������
	if (CheckBox1->Checked) {
		 if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter+" check = 1";
	}
	if (MainForm->MainTable->Filter!="") {
		MainForm->MainTable->Filtered=true;
	}
	//frxReport1->LoadFromFile(sPath+"\\reports\\exportPDF.fr3",true);
	frxReport1->LoadFromFile(sPath+"\\reports\\repAgent_"+TypeObject+".fr3",true);

	TfrxMemoView * Memo = dynamic_cast <TfrxMemoView *> (frxReport1->FindObject("Memo1"));
	Memo->Text = MainForm->Table_Abonents->FieldByName("COMPNAME")->AsString+","+
		MainForm->Table_Abonents->FieldByName("ADDRESS")->AsString+"," +
		MainForm->Table_Abonents->FieldByName("PHONE")->AsString;

	frxReport1->PrepareReport();
	if (SaveDialog2->Execute()) {
		if (SaveDialog2->FileName!="") {
			frxBIFFExport1->FileName = SaveDialog2->FileName;
			if (AnsiLowerCase(ExtractFileExt(SaveDialog2->FileName)) != ".xls") {
				frxBIFFExport1->FileName = frxBIFFExport1->FileName + ".xls";
			}
			frxReport1->Export(frxBIFFExport1);
			MainForm->MainTable->Filtered=false;
			MainForm->MainTable->Filter = "";
			MainForm->MainTable->EnableControls();
			Close();
		}
	}
	MainForm->MainTable->Filtered=false;
	MainForm->MainTable->Filter = "";
	MainForm->MainTable->EnableControls();
	/*if (SaveDialog2->Execute()) {
		if (SaveDialog2->FileName!="") {
			//ShowMessage(SaveDialog1->FileName);
			SaveDBGridEhToExportFile(__classid(TDBGridEhExportAsXLS),MainForm->DBMainGrid,SaveDialog2->FileName,true);
			Close();
			//frxPDFExport1->FileName = SaveDialog1->FileName;
			//frxReport1->Export(frxPDFExport1);
		}
	} */
	//SaveDBGridEhToExportFile(__classid(TDBGridEhExportAsXLS),MainForm->DBMainGrid,"c:\\temp\\file1.xls",true);
}
//---------------------------------------------------------------------------
void __fastcall TFormExportGrid::SpeedButton2Click(TObject *Sender)
{
	// PDF
	MainForm->MainTable->DisableControls();
	// ������ ������ ���������� �������
	if (CheckBox1->Checked) {
		 if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter+" check = 1";
	}
	if (MainForm->MainTable->Filter!="") {
		MainForm->MainTable->Filtered=true;
	}
	//frxReport1->LoadFromFile(sPath+"\\reports\\exportPDF.fr3",true);
	frxReport1->LoadFromFile(sPath+"\\reports\\repAgent_"+TypeObject+".fr3",true);

	TfrxMemoView * Memo = dynamic_cast <TfrxMemoView *> (frxReport1->FindObject("Memo1"));
	Memo->Text = MainForm->Table_Abonents->FieldByName("COMPNAME")->AsString+","+
		MainForm->Table_Abonents->FieldByName("ADDRESS")->AsString+"," +
		MainForm->Table_Abonents->FieldByName("PHONE")->AsString;

	frxReport1->PrepareReport();
	if (SaveDialog1->Execute()) {
		if (SaveDialog1->FileName!="") {
			frxPDFExport1->FileName = SaveDialog1->FileName;
			if (AnsiLowerCase(ExtractFileExt(SaveDialog1->FileName)) != ".pdf") {
				frxPDFExport1->FileName = frxPDFExport1->FileName + ".pdf";
			}
			frxReport1->Export(frxPDFExport1);
			MainForm->MainTable->Filtered=false;
			MainForm->MainTable->Filter = "";
			MainForm->MainTable->EnableControls();
			Close();
		}
	}
	MainForm->MainTable->Filtered=false;
	MainForm->MainTable->Filter = "";
	MainForm->MainTable->EnableControls();
}
//---------------------------------------------------------------------------
void __fastcall TFormExportGrid::SpeedButton3Click(TObject *Sender)
{
	// SQL
}
//---------------------------------------------------------------------------
