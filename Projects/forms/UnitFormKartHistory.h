//---------------------------------------------------------------------------

#ifndef UnitFormKartHistoryH
#define UnitFormKartHistoryH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "FormEditKart.h"
//---------------------------------------------------------------------------
class TFormKartHistory : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *History_DBGrid;
private:	// User declarations
public:		// User declarations
	__fastcall TFormKartHistory(TComponent* Owner, TDataSource * History_datasource_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormKartHistory *FormKartHistory;
//---------------------------------------------------------------------------
#endif
