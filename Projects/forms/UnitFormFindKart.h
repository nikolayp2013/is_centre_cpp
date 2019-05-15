//---------------------------------------------------------------------------

#ifndef UnitFormFindKartH
#define UnitFormFindKartH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MainClass.h"
//---------------------------------------------------------------------------
class TFormFindKart : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormFindKart(TComponent* Owner, TDataSource * TabPricelist_Datasource_Main_Local, int * retval_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFindKart *FormFindKart;
//---------------------------------------------------------------------------
#endif
