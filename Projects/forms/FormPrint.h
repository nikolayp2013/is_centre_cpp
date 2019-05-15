//---------------------------------------------------------------------------

#ifndef FormPrintH
#define FormPrintH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include "RpBase.hpp"
#include "RpDefine.hpp"
#include "RpRave.hpp"
#include "RpSystem.hpp"
#include "IBCustomDataSet.hpp"
#include "IBDatabase.hpp"
#include "IBTable.hpp"
#include "RpCon.hpp"
#include "RpConDS.hpp"
#include <DB.hpp>
#include "MainClass.h"
#include "RpFiler.hpp"
#include "RpRender.hpp"
#include "RpRenderPDF.hpp"
#include "RpRenderRTF.hpp"
#include "RpRenderText.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxDesgn.hpp"
#include "frxExportPDF.hpp"
#include "frxExportXLS.hpp"
#include "frxIBXComponents.hpp"
#include "frxExportODF.hpp"
#include <Mask.hpp>
#include <Dialogs.hpp>
#include "frxExportBIFF.hpp"

//---------------------------------------------------------------------------
class TFormPr : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape15;
	TLabel *Label49;
	TComboBox *ReportList_ComboBox;
	TCheckBox *CheckBox2;
	TButton *Button1;
	TButton *Button2;
	TSpeedButton *SpeedButton1;
	TShape *Shape1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TShape *Shape2;
	TShape *Shape3;
	TLabel *Label6;
	TLabel *Label7;
	TCheckBox *MarkOnly_CheckBox;
	TComboBox *Valuta_ComboBox;
	TShape *Shape4;
	TLabel *Label8;
	TComboBox *ComboBox3;
	TEdit *Edit5;
	TComboBox *ComboBox4;
	TLabel *Label9;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TRadioButton *RadioButton1;
	TShape *Shape5;
	TLabel *Label10;
	TButton *Print_Button;
	TButton *Exit_Button;
	TIBDatabase *IBDatabase1;
	TIBTransaction *IBTransaction1;
	TPanel *Panel1;
	TRadioButton *RadioButton10;
	TRadioButton *RadioButton9;
	TRadioButton *RadioButton7;
	TRadioButton *RadioButton8;
	TfrxReport *frxReport1;
	TfrxDesigner *frxDesigner1;
	TfrxPDFExport *frxPDFExport1;
	TfrxXLSExport *frxXLSExport1;
	TfrxIBXComponents *frxIBXComponents1;
	TfrxDBDataset *frxDBDataset1;
	TfrxDBDataset *frxDBDataset2;
	TfrxDBDataset *frxDBDataset3;
	TRadioButton *RadioButton11;
	TfrxODTExport *frxODTExport1;
	TRadioButton *RadioButton12;
	TfrxODSExport *frxODSExport1;
	TMaskEdit *DateEnter1;
	TMaskEdit *DateEnter2;
	TMaskEdit *Date_ch1;
	TMaskEdit *Date_ch2;
	TSaveDialog *SaveDialog_Excel;
	TSaveDialog *SaveDialog_OOffice;
	TSaveDialog *SaveDialog_PDF;
	TCheckBox *MarkNever_CheckBox;
	TPanel *Panel2;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton5;
	TRadioButton *RadioButton6;
	TfrxBIFFExport *frxBIFFExport1;
	void __fastcall Exit_ButtonClick(TObject *Sender);
	void __fastcall Print_ButtonClick(TObject *Sender);
	void __fastcall DateEnter1DblClick(TObject *Sender);
	void __fastcall DateEnter2DblClick(TObject *Sender);
	void __fastcall Date_ch1DblClick(TObject *Sender);
	void __fastcall Date_ch2DblClick(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall MarkOnly_CheckBoxClick(TObject *Sender);
	void __fastcall MarkNever_CheckBoxClick(TObject *Sender);
	void __fastcall DateEnter1Exit(TObject *Sender);
	void __fastcall Date_ch1Exit(TObject *Sender);
	void __fastcall DateEnter2Exit(TObject *Sender);
	void __fastcall Date_ch2Exit(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormPr(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPr *FormPr;
//---------------------------------------------------------------------------
#endif