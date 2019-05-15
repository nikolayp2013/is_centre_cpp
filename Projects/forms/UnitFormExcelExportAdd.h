//---------------------------------------------------------------------------

#ifndef UnitFormExcelExportAddH
#define UnitFormExcelExportAddH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitFormExcelExport.h"
//---------------------------------------------------------------------------
class TFormExcelExportAdd : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Enter(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormExcelExportAdd(TComponent* Owner, int * swenter_local, string * nameform_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormExcelExportAdd *FormExcelExportAdd;
//---------------------------------------------------------------------------
#endif

