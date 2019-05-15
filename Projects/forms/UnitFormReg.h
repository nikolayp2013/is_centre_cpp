//---------------------------------------------------------------------------

#ifndef UnitFormRegH
#define UnitFormRegH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "UnitFormStart.h"
#include "IBCustomDataSet.hpp"
#include <DB.hpp>
#include "IBTable.hpp"
#include "MainClass.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormReg : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TEdit *Edit1;
	TComboBox *ComboBox1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
 	__fastcall TFormReg(TComponent* Owner, TIBDatabase * MainConn_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormReg *FormReg;
//---------------------------------------------------------------------------
#endif
