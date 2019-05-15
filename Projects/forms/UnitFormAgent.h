//---------------------------------------------------------------------------

#ifndef UnitFormAgentH
#define UnitFormAgentH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "MainClass.h"
#include "UnitAgKartEdit.h"
#include "UnitFormAgentPrint.h"
#include "UnitFormAgentFilter.h"
#include "UnitFormAbonent.h"
#include "UnitFormAgentRole.h"
#include "IBCustomDataSet.hpp"
#include "IBQuery.hpp"
#include <DB.hpp>
#include "IBDatabase.hpp"
#include "IBTable.hpp"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormAgent : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TDBGrid *GridAgent;
	TShape *Shape5;
	TCheckBox *CheckBox1;
	TShape *Shape1;
	TCheckBox *CheckBox2;
	TLabel *Label1;
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall SpeedButton6Click(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAgent(TComponent* Owner, TIBDatabase * MainConnLoc);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAgent *FormAgent;
//---------------------------------------------------------------------------
#endif
