//---------------------------------------------------------------------------

#ifndef UnitFormUpdateBannerH
#define UnitFormUpdateBannerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "UnitFormSwap.h"
#include <DB.hpp>
#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
#include <ComCtrls.hpp>
#include "IBCustomDataSet.hpp"
#include "IBQuery.hpp"
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "MyAccess.hpp"
#include "UnitUpdateExe.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormUpdateBanner : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TProgressBar *ProgressBar1;
	TMyTable *Table_updatebanner;
	TMyQuery *Query_temp;
	TMyTable *Table_temp_load;
	TMyQuery *Query_updateexe;
	TMyQuery *Query_updatescript;
	TMyQuery *Query_reklama;
	TIdHTTP *IdHTTP1;
	TProgressBar *ProgressBar2;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall IdHTTP1Work(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall IdHTTP1WorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);


private:	// User declarations
public:		// User declarations
	__fastcall TFormUpdateBanner(TComponent* Owner, TMyConnection *SQLConnection1_loc,
			TIBDatabase * MainConn_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormUpdateBanner *FormUpdateBanner;
//---------------------------------------------------------------------------
#endif
