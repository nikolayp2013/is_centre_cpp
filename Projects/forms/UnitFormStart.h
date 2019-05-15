//---------------------------------------------------------------------------

#ifndef UnitFormStartH
#define UnitFormStartH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <pngimage.hpp>
#include <Graphics.hpp>
#include "UnitFormReg.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include "IBDatabase.hpp"
#include <DB.hpp>
#include <Buttons.hpp>
#include "DataDriverEh.hpp"
#include "IBXDataDriverEh.hpp"
#include "MemTableDataEh.hpp"
#include "MemTableEh.hpp"
extern double nX;
extern int CompanyID;
const int KEY_LEN = 20;
const int NUM_DIGITS_CODE = 8;
const int NUM_COMPANIES = 500;
extern String curVersion;
extern String StartDirF;
extern int ReConnect;
//---------------------------------------------------------------------------
class TFormStart : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TPanel *Panel2;
	TLabel *Label1;
	TComboBox *ComboBox1;
	TLabel *Label2;
	TImage *Image2;
	TLabel *Label3;
	TPanel *Panel1;
	TImage *Image3;
	TLabel *Label4;
	TIBDatabase *MainConn1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TIBXDataDriverEh *IBXDataDriverEh1;
	TMemTableEh *MemTableEh1;
	TIBTransaction *IBTransaction1;
	TIdHTTP *IdHTTP1;
	void __fastcall Panel2Click(TObject *Sender);
	void __fastcall Label1MouseEnter(TObject *Sender);
	void __fastcall Label1MouseLeave(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall Panel2MouseEnter(TObject *Sender);
	void __fastcall Panel2MouseLeave(TObject *Sender);
	void __fastcall Panel1MouseEnter(TObject *Sender);
	void __fastcall Panel1MouseLeave(TObject *Sender);
	void __fastcall Panel1Click(TObject *Sender);
	String __fastcall GenA1(TObject *Sender, double nCode);
	//void __fastcall MyRandomize(TObject *Sender, long double seed);
	void __fastcall MyRandomize(TObject *Sender, double seed);
	//long double __fastcall MyRnd(TObject *Sender);
	double __fastcall MyRnd(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormStart(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormStart *FormStart;
//---------------------------------------------------------------------------
#endif
