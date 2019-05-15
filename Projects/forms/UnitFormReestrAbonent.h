//---------------------------------------------------------------------------

#ifndef UnitFormReestrAbonentH
#define UnitFormReestrAbonentH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "MainClass.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormReestrAbonent : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TLabel *Label1;
	TEdit *Compid_Edit;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Compname_Edit;
	TEdit *Phone_Edit;
	TEdit *Address_Edit;
	TDBGrid *DBGrid1;
	TPanel *Panel1;
	void __fastcall ProcFind(TObject *Sender);
	void __fastcall Compid_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Compname_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Phone_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Address_EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Compname_EditEnter(TObject *Sender);
	void __fastcall Address_EditEnter(TObject *Sender);
	void __fastcall Panel1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Panel1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Panel1Click(TObject *Sender);






private:	// User declarations
public:		// User declarations
	__fastcall TFormReestrAbonent(TComponent* Owner, TIBDatabase * MainConn_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReestrAbonent *FormReestrAbonent;
//---------------------------------------------------------------------------
#endif
