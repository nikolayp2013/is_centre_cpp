//---------------------------------------------------------------------------

#ifndef UnitFormAgentFilterH
#define UnitFormAgentFilterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "UnitFormAgent.h"
//---------------------------------------------------------------------------
class TFormAgentFilter : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape5;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TComboBox *ComboBox2;
	TComboBox *ComboBox3;
	TComboBox *ComboBox4;
	TComboBox *ComboBox5;
	TButton *Button4;
	TButton *Button5;
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAgentFilter(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAgentFilter *FormAgentFilter;
//---------------------------------------------------------------------------
#endif
