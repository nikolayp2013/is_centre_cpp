//---------------------------------------------------------------------------

#ifndef UnitFormFilterAddRoomsH
#define UnitFormFilterAddRoomsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "MainClass.h"
#include "UnitFormFilterAddDop.h"
//---------------------------------------------------------------------------
class TFormFilterAddRooms : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton9;
	TComboBox *Region_ComboBox;
	TEdit *Street_Edit;
	TListBox *Selected_ListBox;
	TEdit *Totalarea1_Edit;
	TEdit *Livearea1_Edit;
	TEdit *Kitchenarea1_Edit;
	TEdit *Totalarea2_Edit;
	TEdit *Livearea2_Edit;
	TEdit *Kitchenarea2_Edit;
	TComboBox *Balcony_ComboBox;
	TListBox *Streest_ListBox;
	TLabel *Label11;
	TEdit *Edit1;
	TLabel *Label12;
	TEdit *Edit2;
	TLabel *Label13;
	TEdit *Edit3;
	TLabel *Label14;
	TEdit *Edit4;
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
	__fastcall TFormFilterAddRooms(TComponent* Owner, TIBDatabase * MainConn_loc);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFilterAddRooms *FormFilterAddRooms;
//---------------------------------------------------------------------------
#endif
