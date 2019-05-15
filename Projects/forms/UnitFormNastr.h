//---------------------------------------------------------------------------

#ifndef UnitFormNastrH
#define UnitFormNastrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "MainClass.h"
#include <CheckLst.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormNastr : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape1;
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet5;
	TButton *Button1;
	TButton *Button2;
	TCheckListBox *CheckListBox1;
	TLabel *Label3;
	TEdit *Edit1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	TCheckBox *CheckBox9;
	TCheckBox *CheckBox10;
	TShape *Shape2;
	TLabel *Label4;
	TCheckBox *CheckBox11;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label7;
	TEdit *Edit4;
	TLabel *Label8;
	TEdit *Edit5;
	TEdit *Edit13;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TEdit *Edit14;
	TEdit *Edit15;
	TEdit *Edit16;
	TEdit *Edit17;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TEdit *hostname;
	TEdit *username;
	TEdit *password;
	TLabel *Label27;
	TEdit *DBPath;
	TButton *Button3;
	TOpenDialog *OpenDialog1;
	void __fastcall PageControl1DrawTab(TCustomTabControl *Control, int TabIndex, const TRect &Rect,
          bool Active);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormNastr(TComponent* Owner, TIBDatabase * MainConn_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNastr *FormNastr;
//---------------------------------------------------------------------------
#endif
