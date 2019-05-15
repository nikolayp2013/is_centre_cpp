//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormPrint.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RpBase"
#pragma link "RpDefine"
#pragma link "RpRave"
#pragma link "RpSystem"
#pragma link "IBCustomDataSet"
#pragma link "IBDatabase"
#pragma link "IBTable"
#pragma link "RpCon"
#pragma link "RpConDS"
#pragma link "RpFiler"
#pragma link "RpRender"
#pragma link "RpRenderPDF"
#pragma link "RpRenderRTF"
#pragma link "RpRenderText"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxDesgn"
#pragma link "frxExportPDF"
#pragma link "frxExportXLS"
#pragma link "frxIBXComponents"
#pragma link "frxExportODF"
#pragma link "frxExportBIFF"
#pragma resource "*.dfm"
TFormPr *FormPr;
//---------------------------------------------------------------------------
__fastcall TFormPr::TFormPr(TComponent* Owner)
	: TForm(Owner)
{
	// Таблица со списко агентов
	MainForm->Table_Abonents->Active=true;
	MainForm->Table_Abonents->FetchAll();

	Valuta_ComboBox->Items->Add("УЕ");
	Valuta_ComboBox->Items->Add("Руб");
	Valuta_ComboBox->ItemIndex=1;

	ComboBox3->Items->Add("+");
	ComboBox3->Items->Add("-");
	ComboBox3->ItemIndex=0;

	ComboBox4->Items->Add("Ч");
	ComboBox4->Items->Add("%");
	ComboBox4->ItemIndex=0;

	Edit5->Text=0;

	ReportList_ComboBox->Items->Add("Агентская");
	ReportList_ComboBox->Items->Add("Клиентская");
	ReportList_ComboBox->Items->Add("ДСП");

	if (AnsiUpperCase(TypeObject)=="APARTSELL") {
		ReportList_ComboBox->Items->Add("Агентская с пересечением");
		ReportList_ComboBox->Items->Add("Клиентская с пересечением");
		ReportList_ComboBox->Items->Add("ДСП с пересечением");
	}
	if (AnsiUpperCase(TypeObject)!="NEWBUILDSSELL" &&
		AnsiUpperCase(TypeObject)!="ABROADSELL" &&
		AnsiUpperCase(TypeObject)!="BUISNESSSELL") {
		ReportList_ComboBox->Items->Add("Клиентская расширенная");
	}
	if (AnsiUpperCase(TypeObject)=="APARTPURCH") {
		ReportList_ComboBox->Items->Clear();
		ReportList_ComboBox->Items->Add("Кв. Спрос");
	}
	if (AnsiUpperCase(TypeObject)=="ROOMSPURCH") {
		ReportList_ComboBox->Items->Clear();
		ReportList_ComboBox->Items->Add("Ком. Спрос");
	}
	if (AnsiUpperCase(TypeObject)=="ARENDPURCH") {
		ReportList_ComboBox->Items->Clear();
		ReportList_ComboBox->Items->Add("Аренда спрос");
	}
	if (AnsiUpperCase(TypeObject)=="HOUSEPURCH") {
		ReportList_ComboBox->Items->Clear();
		ReportList_ComboBox->Items->Add("Дома спрос");
	}
	if (AnsiUpperCase(TypeObject)=="GARAGEPURCH") {
		ReportList_ComboBox->Items->Clear();
		ReportList_ComboBox->Items->Add("Гаражи спрос");
	}
	if (AnsiUpperCase(TypeObject)=="COMMERCPURCH") {
		ReportList_ComboBox->Items->Clear();
		ReportList_ComboBox->Items->Add("Комм. Спрос");
	}
	ReportList_ComboBox->ItemIndex = 0;

	RadioButton2->Checked = true;
	RadioButton1->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormPr::Exit_ButtonClick(TObject *Sender)
{
	// Кнопка выход
	FormPr->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormPr::Print_ButtonClick(TObject *Sender)
{
	// Кнопка печать
	MainForm->MainTable->DisableControls();
	// Установка фильтра
	// Маржа
	if (Edit5->Text.Trim()!="0") {
    	MainForm->Plus_ComboBox->ItemIndex = ComboBox3->ItemIndex;
		MainForm->Part_ComboBox->ItemIndex = ComboBox4->ItemIndex;
		MainForm->Marza_Edit->Text = Edit5->Text;
		MainForm->ApartFilter(MainForm);
	}
	// Date_ch - дата корректировки
	if (Date_ch1->Text!="  .  .    " && Date_ch2->Text!="  .  .    ") {
		 if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter +"date_ch >= '"+Date_ch1->Text+"' and date_ch <='"+Date_ch2->Text+"'";
	}
	if (Date_ch1->Text!="  .  .    " && Date_ch2->Text=="  .  .    ") {
		 if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter + "date_ch >= '"+Date_ch1->Text+"'";
	}
	if (Date_ch1->Text=="  .  .    " && Date_ch2->Text!="  .  .    ") {
		 if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter + "date_ch <='"+Date_ch2->Text+"'";
	}
    // DateEnter - дата ввода
	if (DateEnter1->Text!="  .  .    " && DateEnter2->Text!="  .  .    ") {
		 if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter + "date_ch >= '"+DateEnter1->Text+"' and date_ch <='"+DateEnter2->Text+"'";
	}
	if (DateEnter1->Text!="  .  .    " && DateEnter2->Text=="  .  .    ") {
		 if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter +"date_ch >= '"+DateEnter1->Text+"'";
	}
	if (DateEnter1->Text=="  .  .    " && DateEnter2->Text!="  .  .    ") {
		 if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter +"date_ch <='"+DateEnter2->Text+"'";
	}
	// Печать только отмеченных позиций
	if (MarkOnly_CheckBox->Checked) {
		 if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter+" check = 1";
	}
	// Кроме отмеченных позиций
	if (MarkNever_CheckBox->Checked) {
          if (MainForm->MainTable->Filter!="") {
			 MainForm->MainTable->Filter = MainForm->MainTable->Filter + " and ";
		 }
		 MainForm->MainTable->Filter = MainForm->MainTable->Filter+" check = 0";
	}
	if (MainForm->MainTable->Filter!="") {
		MainForm->MainTable->Filtered=true;
	}

   // Коммерческая объединенная
   if (AnsiUpperCase(TypeObject)=="COMMERCSELLALL") {
	   String TypeObject_temp;
	   for (int i = 1; i <= 4; i++) {
			TypeObject_temp = "CommercSell"+(String)i;
			if (ReportList_ComboBox->ItemIndex==0) {
				frxReport1->LoadFromFile(sPath+"\\reports\\repAgent_"+TypeObject_temp+".fr3",true);
			}
			if (ReportList_ComboBox->ItemIndex==1) {
				frxReport1->LoadFromFile(sPath+"\\reports\\repKlient_"+TypeObject_temp+".fr3",true);
			}
			if (ReportList_ComboBox->ItemIndex==2) {
				frxReport1->LoadFromFile(sPath+"\\reports\\repDSP_"+TypeObject_temp+".fr3",true);
			}
			if (ReportList_ComboBox->ItemIndex==3) {
				frxReport1->LoadFromFile(sPath+"\\reports\\repAgentCross_"+TypeObject_temp+".fr3",true);
			}
			TfrxMemoView * Memo = dynamic_cast <TfrxMemoView *> (frxReport1->FindObject("Memo1"));
			Memo->Text = MainForm->Table_Abonents->FieldByName("COMPNAME")->AsString+","+
			MainForm->Table_Abonents->FieldByName("ADDRESS")->AsString+"," +
			MainForm->Table_Abonents->FieldByName("PHONE")->AsString;
			frxReport1->PrepareReport();

			// Предварительный просмотр
			if (RadioButton8->Checked) {
				frxReport1->ShowReport(true);
			}
			// Печать
			if (RadioButton7->Checked) {
				frxReport1->Print();
			}
			// PDF
			if (RadioButton9->Checked) {
				frxReport1->Export(frxPDFExport1);
			}
			// Excel
			if (RadioButton10->Checked) {
				frxReport1->Export(frxXLSExport1);
			}
			// Редактировать форму
			if (RadioButton11->Checked) {
				frxReport1->DesignReport();
			}
			delete Memo;
	   }
	   Abort();
   }
   // Аренда объединенная
   if (AnsiUpperCase(TypeObject)=="ARENDSELLALL") {
	   String TypeObject_temp1;
	   for (int i = 1; i <= 6; i++) {
			if (i==1) {
			   TypeObject_temp1 = "CommercSell1";
			}
			if (i==2) {
			   TypeObject_temp1 = "CommercSell2";
			}
			if (i==3) {
			   TypeObject_temp1 = "CommercSell3";
			}
			if (i==4) {
			   TypeObject_temp1 = "CommercSell4";
			}
			if (i==5) {
			   TypeObject_temp1 = "ArendSell";
			}
			if (i==6) {
			   TypeObject_temp1 = "HouseSell";
			}
			if (ReportList_ComboBox->ItemIndex==0) {
				frxReport1->LoadFromFile(sPath+"\\reports\\repAgent_"+TypeObject_temp1+".fr3",true);
			}
			if (ReportList_ComboBox->ItemIndex==1) {
				frxReport1->LoadFromFile(sPath+"\\reports\\repKlient_"+TypeObject_temp1+".fr3",true);
			}
			if (ReportList_ComboBox->ItemIndex==2) {
				frxReport1->LoadFromFile(sPath+"\\reports\\repDSP_"+TypeObject_temp1+".fr3",true);
			}
			if (ReportList_ComboBox->ItemIndex==3) {
				frxReport1->LoadFromFile(sPath+"\\reports\\repAgentCross_"+TypeObject_temp1+".fr3",true);
			}
			TfrxMemoView * Memo = dynamic_cast <TfrxMemoView *> (frxReport1->FindObject("Memo1"));
			Memo->Text = MainForm->Table_Abonents->FieldByName("COMPNAME")->AsString+","+
			MainForm->Table_Abonents->FieldByName("ADDRESS")->AsString+"," +
			MainForm->Table_Abonents->FieldByName("PHONE")->AsString;
			frxReport1->PrepareReport();

			// Предварительный просмотр
			if (RadioButton8->Checked) {
				frxReport1->ShowReport(true);
			}
			// Печать
			if (RadioButton7->Checked) {
				frxReport1->Print();
			}
			// PDF
			if (RadioButton9->Checked) {
				frxReport1->Export(frxPDFExport1);
			}
			// Excel
			if (RadioButton10->Checked) {
				frxReport1->Export(frxXLSExport1);
			}
			// Редактировать форму
			if (RadioButton11->Checked) {
				frxReport1->DesignReport();
			}
			// OpenOffice
			if (RadioButton12->Checked) {
				frxReport1->Export(frxODSExport1);
			}
			delete Memo;
	   }
	   Abort();
   }

   if (ReportList_ComboBox->ItemIndex==0) {
		frxReport1->LoadFromFile(sPath+"\\reports\\repAgent_"+TypeObject+".fr3",true);
   }
   if (ReportList_ComboBox->ItemIndex==1) {
		frxReport1->LoadFromFile(sPath+"\\reports\\repKlient_"+TypeObject+".fr3",true);
   }
   if (ReportList_ComboBox->ItemIndex==2) {
		frxReport1->LoadFromFile(sPath+"\\reports\\repDSP_"+TypeObject+".fr3",true);
   }
   if (ReportList_ComboBox->ItemIndex==3 && AnsiUpperCase(TypeObject)=="APARTSELL") {
		frxReport1->LoadFromFile(sPath+"\\reports\\repAgentCross_"+TypeObject+".fr3",true);
   }
   if (ReportList_ComboBox->ItemIndex==4) {
		frxReport1->LoadFromFile(sPath+"\\reports\\repKlientCross_"+TypeObject+".fr3",true);
   }
   if (ReportList_ComboBox->ItemIndex==5) {
		frxReport1->LoadFromFile(sPath+"\\reports\\repDSPCross_"+TypeObject+".fr3",true);
   }
   if ((ReportList_ComboBox->ItemIndex==6 && AnsiUpperCase(TypeObject)=="APARTSELL") ||
		(ReportList_ComboBox->ItemIndex==3 && AnsiUpperCase(TypeObject)!="APARTSELL")) {
		frxReport1->LoadFromFile(sPath+"\\reports\\repKlientExt_"+TypeObject+".fr3",true);
   }
	TfrxMemoView * Memo = dynamic_cast <TfrxMemoView *> (frxReport1->FindObject("Memo1"));
	Memo->Text = MainForm->Table_Abonents->FieldByName("COMPNAME")->AsString+","+
		MainForm->Table_Abonents->FieldByName("ADDRESS")->AsString+"," +
		MainForm->Table_Abonents->FieldByName("PHONE")->AsString;

	// Валюта
	TfrxMemoView * Price_Memo1 = dynamic_cast <TfrxMemoView *> (frxReport1->FindObject("Price_Memo"));
	if (Valuta_ComboBox->ItemIndex==0) {
		Price_Memo1->Text = "[frxDBDataset3.\"priceue\"]";
		Price_Memo1->DataField = "PRICEUE";
	} else {
		Price_Memo1->Text = "[frxDBDataset3.\"pricerub\"]";
		Price_Memo1->DataField = "PRICERUB";
	}

   frxReport1->PrepareReport();

   // Предварительный просмотр
   if (RadioButton8->Checked) {
	   frxReport1->ShowReport(true);
	   //frxReport1->
   }
   // Печать
   if (RadioButton7->Checked) {
	   frxReport1->Print();
   }
   // PDF
   if (RadioButton9->Checked) {
	   if (SaveDialog_PDF->Execute()) {
		   if (SaveDialog_PDF->FileName!="") {
			   frxPDFExport1->FileName = SaveDialog_PDF->FileName;
			   if (AnsiLowerCase(ExtractFileExt(SaveDialog_PDF->FileName)) != ".pdf") {
					frxPDFExport1->FileName = frxPDFExport1->FileName + ".pdf";
			   }
			   frxReport1->Export(frxPDFExport1);
		   }
	   }
   }
   // Excel
   if (RadioButton10->Checked) {
	   if (SaveDialog_Excel->Execute()) {
		   if (SaveDialog_Excel->FileName!="") {
			   //frxXLSExport1->FileName = SaveDialog_Excel->FileName;
			   frxBIFFExport1->FileName = SaveDialog_Excel->FileName;
			   if (AnsiLowerCase(ExtractFileExt(SaveDialog_Excel->FileName)) != ".xls") {
					//frxXLSExport1->FileName = frxXLSExport1->FileName + ".xls";
					frxBIFFExport1->FileName = frxBIFFExport1->FileName + ".xls";
			   }
			   //frxReport1->Export(frxXLSExport1);
			   frxReport1->Export(frxBIFFExport1);
		   }
	   }
   }
   // Редактировать форму
   if (RadioButton11->Checked) {
	   frxReport1->DesignReport();
   }

   // OpenOffice
   if (RadioButton12->Checked) {
	   if (SaveDialog_OOffice->Execute()) {
		   if (SaveDialog_OOffice->FileName!="") {
			   frxODSExport1->FileName = SaveDialog_OOffice->FileName;
			   if (AnsiLowerCase(ExtractFileExt(SaveDialog_OOffice->FileName)) != ".ods") {
					frxODSExport1->FileName = frxODSExport1->FileName + ".ods";
			   }
			   frxReport1->Export(frxODSExport1);
		   }
	   }
   }
   if (MainForm->MainTable->Filter!="") {
		MainForm->MainTable->Filtered=false;
		MainForm->MainTable->Filter = "";
	}
   delete Memo;
   MainForm->MainTable->EnableControls();
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::DateEnter1DblClick(TObject *Sender)
{
	DateEnter1->Text = Date().DateString();
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::DateEnter2DblClick(TObject *Sender)
{
	DateEnter2->Text = Date().DateString();
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::Date_ch1DblClick(TObject *Sender)
{
	Date_ch1->Text = Date().DateString();
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::Date_ch2DblClick(TObject *Sender)
{
	Date_ch2->Text = Date().DateString();
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::SpeedButton2Click(TObject *Sender)
{
	 // Очистить поле дата ввода
	 DateEnter1->Text="";
	 DateEnter2->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::SpeedButton3Click(TObject *Sender)
{
     // Очистить поле дата корректировки
	 Date_ch1->Text="";
	 Date_ch2->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::MarkOnly_CheckBoxClick(TObject *Sender)
{
	// Печатать только отмеченные позиции
	if (MarkNever_CheckBox->Checked) {
		MarkNever_CheckBox->Checked=false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::MarkNever_CheckBoxClick(TObject *Sender)
{
	// Печатать кроме отмеченных позиций
	if (MarkOnly_CheckBox->Checked) {
		MarkOnly_CheckBox->Checked=false;
	}
}
//---------------------------------------------------------------------------


void __fastcall TFormPr::DateEnter1Exit(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::Date_ch1Exit(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::DateEnter2Exit(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------

void __fastcall TFormPr::Date_ch2Exit(TObject *Sender)
{
	//
}
//---------------------------------------------------------------------------

