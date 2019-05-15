//---------------------------------------------------------------------------

#ifndef UnitFormAgentRoleAddH
#define UnitFormAgentRoleAddH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <UnitFormAgentRole.h>
//---------------------------------------------------------------------------
class TFormAgentRoleAdd : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TComboBox *ComboBox1;
	TShape *Shape5;
	TLabel *Label2;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TButton *Button1;
	TButton *Button2;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAgentRoleAdd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAgentRoleAdd *FormAgentRoleAdd;
//---------------------------------------------------------------------------
#endif
