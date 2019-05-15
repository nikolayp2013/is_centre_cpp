//---------------------------------------------------------------------------

#ifndef UnitFormKlientsFindH
#define UnitFormKlientsFindH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFormKlients.h"
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFormKlientsFind : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Comp_Edit;
	TEdit *Name_Edit;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Edit1Enter(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormKlientsFind(TComponent* Owner, TDataSource * Clients_Datasource_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormKlientsFind *FormKlientsFind;
//---------------------------------------------------------------------------
#endif
