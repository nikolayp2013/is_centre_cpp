//---------------------------------------------------------------------------

#ifndef UnitFormSpravAgentH
#define UnitFormSpravAgentH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MainClass.h"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "UnitFormStart.h"
#include "IBCustomDataSet.hpp"
#include "IBDatabase.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TFormSpravAgent : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button3;
	TDBGrid *DBGrid1;
	TIBDataSet *IBDataSet1;
	TIBTransaction *IBTransaction1;
	TDataSource *DataSource1;
	TLabel *Label1;
	TEdit *Comp_Edit;
	TLabel *Label2;
	TEdit *Fgent_Edit;
	TLabel *Label3;
	TEdit *Phone_Edit;
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ProcFind(TObject *Sender);
	void __fastcall Comp_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Fgent_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Phone_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);


private:	// User declarations
public:		// User declarations
	__fastcall TFormSpravAgent(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSpravAgent *FormSpravAgent;
//---------------------------------------------------------------------------
#endif
