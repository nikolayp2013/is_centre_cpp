//---------------------------------------------------------------------------

#ifndef UnitFormThemsH
#define UnitFormThemsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include "MainClass.h"
//#include "IniFiles.hpp"
//---------------------------------------------------------------------------
class TFormThems : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TLabel *Label1;
	TListBox *ListBox1;
	TShape *Shape2;
	TLabel *Label2;
	TShape *Shape3;
	TLabel *Label3;
	TButton *Button1;
	TButton *Button2;
	TCheckBox *Pricein_CheckBox;
	TCheckBox *Addk_CheckBox;
	TCheckBox *Openk_CheckBox;
	TCheckBox *Deletek_CheckBox;
	TCheckBox *Updatek_CheckBox;
	TCheckBox *Info_CheckBox;
	TCheckBox *Clients_CheckBox;
	TCheckBox *Userch_CheckBox;
	TCheckBox *Help_CheckBox;
	TCheckBox *Agentview_CheckBox;
	TCheckBox *Clientview_CheckBox;
	TCheckBox *DSPview_CheckBox;
	TCheckBox *Panel_CheckBox;
	TCheckBox *Sprospred_CheckBox;
	TCheckBox *Print_CheckBox;
	TCheckBox *Typedog_CheckBox;
	TCheckBox *Rekl_CheckBox;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormThems(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormThems *FormThems;
//---------------------------------------------------------------------------
#endif
