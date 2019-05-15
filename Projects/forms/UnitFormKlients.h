//---------------------------------------------------------------------------

#ifndef UnitFormKlientsH
#define UnitFormKlientsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "MainClass.h"
#include "UnitFormKlientsKart.h"
#include "UnitFormKlientsFind.h"
#include <FormEditKart.h>
#include "IBCustomDataSet.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TFormKlients : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton5;
	TShape *Shape5;
	TCheckBox *Who1_CheckBox;
	TCheckBox *Who3_CheckBox;
	TButton *Button1;
	TButton *Button2;
	TDBGrid *Clients_DBGrid;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SetFilterClient(TObject *Sender);
	void __fastcall Who1_CheckBoxClick(TObject *Sender);
	void __fastcall Who3_CheckBoxClick(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormKlients(TComponent* Owner, TIBDatabase * MainConn_local, long * retid);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormKlients *FormKlients;
//---------------------------------------------------------------------------
#endif