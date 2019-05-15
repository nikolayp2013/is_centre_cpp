//---------------------------------------------------------------------------

#ifndef UnitFormTestH
#define UnitFormTestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "IBCustomDataSet.hpp"
#include "IBDatabase.hpp"
#include "IBTable.hpp"
#include <DB.hpp>
#include "MainClass.h"
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <DBXMySql.hpp>
#include <FMTBcd.hpp>
#include <Grids.hpp>
#include <SqlExpr.hpp>
#include <WideStrings.hpp>
#include <DBClient.hpp>
#include <SimpleDS.hpp>
//---------------------------------------------------------------------------
class TFormTest : public TForm
{
__published:	// IDE-managed Components
	TIBDatabase *IBDatabase1;
	TIBTransaction *IBTransaction1;
	TIBTable *IBTable1;
	TIntegerField *IBTable1ID;
	TIntegerField *IBTable1AGENT;
	TIntegerField *IBTable1NUM_CARD;
	TDateField *IBTable1DATE_CH;
	TIntegerField *IBTable1REGION;
	TSmallintField *IBTable1MREGION;
	TIBStringField *IBTable1STREET;
	TSmallintField *IBTable1ROOMS;
	TSmallintField *IBTable1IROOMS;
	TSmallintField *IBTable1TYPEHOUSE;
	TSmallintField *IBTable1level;
	TSmallintField *IBTable1LEVELS;
	TSmallintField *IBTable1STUFFWALL;
	TIBBCDField *IBTable1TOTALAREA;
	TIBBCDField *IBTable1LIVEAREA;
	TIBBCDField *IBTable1KITCHENAREA;
	TSmallintField *IBTable1NODESAN;
	TSmallintField *IBTable1BALCONY;
	TSmallintField *IBTable1SWPHONE;
	TSmallintField *IBTable1VARIANT;
	TIBBCDField *IBTable1PRICE;
	TSmallintField *IBTable1CHECK;
	TIBStringField *IBTable1CRSTREET;
	TIBStringField *IBTable1CORPUS;
	TIntegerField *IBTable1HOUSE;
	TIntegerField *IBTable1FLAT;
	TIntegerField *IBTable1CONTRACT;
	TIntegerField *IBTable1SOURCED;
	TIntegerField *IBTable1VARIANTD;
	TIntegerField *IBTable1MORGAGE;
	TIBStringField *IBTable1PART;
	TIntegerField *IBTable1YEARBUILD;
	TIntegerField *IBTable1SECURITY;
	TIntegerField *IBTable1KONSERG;
	TIntegerField *IBTable1OWNEX;
	TIntegerField *IBTable1TRASH;
	TIntegerField *IBTable1GAZ;
	TIntegerField *IBTable1PARKING;
	TIntegerField *IBTable1NEWBUILD;
	TIntegerField *IBTable1DESIGN;
	TIntegerField *IBTable1STATE;
	TIntegerField *IBTable1LOGGIA;
	TIntegerField *IBTable1GLASSBALC;
	TIntegerField *IBTable1GLASSPACK;
	TBlobField *IBTable1ADDINFO;
	TIntegerField *IBTable1VARSWAP;
	TIntegerField *IBTable1DOPLATA;
	TIBStringField *IBTable1SWAPINFO;
	TSmallintField *IBTable1PICS;
	TPanel *Panel1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormTest(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTest *FormTest;
//---------------------------------------------------------------------------
#endif
