//---------------------------------------------------------------------------

#ifndef UnitFormFilterAddArendH
#define UnitFormFilterAddArendH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "MainClass.h"
#include "UnitFormFilterAddDop.h"
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
class TFormFilterAddArend : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton9;
	TComboBox *Region_ComboBox;
	TEdit *Street_Edit;
	TListBox *Selected_ListBox;
	TComboBox *Newbuild_ComboBox;
	TListBox *Streest_ListBox;
	TShape *Shape57;
	TLabel *Label4;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	TCheckBox *CheckBox9;
	TCheckBox *CheckBox10;
	TCheckBox *CheckBox11;
	TShape *Shape1;
	TLabel *Label5;
	TCheckListBox *CheckListBox1;
	TShape *Shape2;
	TLabel *Label6;
	TShape *Shape3;
	TCheckBox *CheckBox12;
	TSpeedButton *SpeedButton4;
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall StreetFilter(TObject *Sender);
	void __fastcall Region_ComboBoxClick(TObject *Sender);
	void __fastcall Street_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFormFilterAddArend(TComponent* Owner, TIBDatabase * MainConn_loc);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFilterAddArend *FormFilterAddArend;
//---------------------------------------------------------------------------
#endif
