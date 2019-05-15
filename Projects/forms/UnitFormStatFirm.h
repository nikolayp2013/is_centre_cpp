//---------------------------------------------------------------------------

#ifndef UnitFormStatFirmH
#define UnitFormStatFirmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "MainClass.h"
#include "IBCustomDataSet.hpp"
#include "IBDatabase.hpp"
#include "IBQuery.hpp"
#include <DB.hpp>
#include "UnitFormStart.h"
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxDBXComponents.hpp"
#include "frxDesgn.hpp"
//---------------------------------------------------------------------------
class TFormStatFirm : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TCheckBox *CheckBox1;
	TButton *Button1;
	TButton *Button2;
	TIBQuery *IBQuery1;
	TIBTransaction *IBTransaction1;
	TDataSource *DataSource1;
	TfrxReport *frxReport1;
	TfrxDesigner *frxDesigner1;
	TfrxDBXComponents *frxDBXComponents1;
	TfrxDBDataset *frxDBDataset1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormStatFirm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormStatFirm *FormStatFirm;
//---------------------------------------------------------------------------
#endif
