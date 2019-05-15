//---------------------------------------------------------------------------

#ifndef FormStatAgentH
#define FormStatAgentH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "UnitFormStatAgentAdd.h"
#include "IBCustomDataSet.hpp"
#include "IBQuery.hpp"
#include <DB.hpp>
#include "UnitFormStart.h"
#include "IBDatabase.hpp"
#include "MainClass.h"
//---------------------------------------------------------------------------
class TFormStatAg : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape5;
	TLabel *Label1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TButton *Button1;
	TButton *Button2;
	TIBQuery *IBQuery1;
	TIBTransaction *IBTransaction1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormStatAg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormStatAg *FormStatAg;
//---------------------------------------------------------------------------
#endif
