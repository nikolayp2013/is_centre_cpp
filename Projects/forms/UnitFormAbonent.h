//---------------------------------------------------------------------------

#ifndef UnitFormAbonentH
#define UnitFormAbonentH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFormAgent.h"
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFormAbonent : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button1;
	TDBEdit *Compname_DBEdit;
	TDBEdit *Phone_DBEdit;
	TDBEdit *Address_DBEdit;
	TLabel *Label4;
	TDBEdit *Sait_DBEdit;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAbonent(TComponent* Owner, TIBDatabase * MainConn_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAbonent *FormAbonent;
//---------------------------------------------------------------------------
#endif
