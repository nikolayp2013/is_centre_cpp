//---------------------------------------------------------------------------

#ifndef FormGallaryH
#define FormGallaryH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "DBLookupListBoxCentre.h"
#include "my_DBCtrls.hpp"
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include "FormEditKart.h"
#include "FormGallaryAddRemark.h"
#include "IBCustomDataSet.hpp"
#include "IBQuery.hpp"
#include <DB.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <CheckLst.hpp>
#include <jpeg.hpp>
#include <SysUtils.hpp>
#include <string.h>
#include <iostream.h>
#include <stdlib.h>
#include <float.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <DBClient.hpp>
#include <DBXMySql.hpp>
#include <SimpleDS.hpp>
#include <SqlExpr.hpp>
#include <WideStrings.hpp>
#include "DBAccess.hpp"
#include "MemDS.hpp"
#include "MyAccess.hpp"

//---------------------------------------------------------------------------
class TFormGall : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSpeedButton *But_add;
	TSpeedButton *But_del;
	TSpeedButton *But_get;
	TSpeedButton *But_send;
	TSpeedButton *SpeedButton5;
	TDBGrid *DBMainGrid;
	TCheckListBox *Image_CheckListBox;
	TImage *Image1;
	TOpenPictureDialog *OpenPictureDialog1;
	TSQLConnection *SQLConnection1;
	TSimpleDataSet *Table_MySQL_Pics1;
	TMyConnection *MyConnection1;
	TMyTable *Table_MySQL_Pics;
	void __fastcall But_addClick(TObject *Sender);
	void __fastcall But_delClick(TObject *Sender);
	void __fastcall ListBox1DrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall Image_CheckListBoxClick(TObject *Sender);
	void __fastcall But_sendClick(TObject *Sender);
	void __fastcall But_getClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormGall(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGall *FormGall;
//---------------------------------------------------------------------------
#endif
