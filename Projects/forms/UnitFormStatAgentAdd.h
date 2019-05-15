//---------------------------------------------------------------------------

#ifndef UnitFormStatAgentAddH
#define UnitFormStatAgentAddH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FormStatAgent.h"
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxDesgn.hpp"
#include "frxIBXComponents.hpp"
//---------------------------------------------------------------------------
class TFormStatAgAdd : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TfrxReport *frxReport1;
	TfrxDesigner *frxDesigner1;
	TfrxIBXComponents *frxIBXComponents1;
	TfrxDBDataset *frxDBDataset1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormStatAgAdd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormStatAgAdd *FormStatAgAdd;
//---------------------------------------------------------------------------
#endif
