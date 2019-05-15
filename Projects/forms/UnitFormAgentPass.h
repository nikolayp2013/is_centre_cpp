//---------------------------------------------------------------------------

#ifndef UnitFormAgentPassH
#define UnitFormAgentPassH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <UnitAgKartEdit.h>
//---------------------------------------------------------------------------
class TFormAgentPass : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAgentPass(TComponent* Owner, TDataSource * Agent_datasource_local,
		TIBTransaction * TransactionAgent_loc);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAgentPass *FormAgentPass;
//---------------------------------------------------------------------------
#endif
