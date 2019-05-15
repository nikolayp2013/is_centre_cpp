//---------------------------------------------------------------------------

#ifndef FormGallaryViewAddH
#define FormGallaryViewAddH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FormGallaryView.h"
#include <ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdServerIOHandler.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <DB.hpp>
#include <SqlExpr.hpp>
#include <WideStrings.hpp>
//---------------------------------------------------------------------------
class TFormGallViewAdd : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TImage *Image1;
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall Label1MouseEnter(TObject *Sender);
	void __fastcall Label1MouseLeave(TObject *Sender);
	void __fastcall Label7MouseEnter(TObject *Sender);
	void __fastcall Label7MouseLeave(TObject *Sender);
	void __fastcall Label8MouseEnter(TObject *Sender);
	void __fastcall Label8MouseLeave(TObject *Sender);
	void __fastcall Label6MouseEnter(TObject *Sender);
	void __fastcall Label6MouseLeave(TObject *Sender);
	void __fastcall RefreshPics(TObject *Sender);
	void __fastcall Label6Click(TObject *Sender);
	void __fastcall Label7Click(TObject *Sender);
	void __fastcall Label8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGallViewAdd(TComponent* Owner, int * swgall_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGallViewAdd *FormGallViewAdd;
//---------------------------------------------------------------------------
#endif
