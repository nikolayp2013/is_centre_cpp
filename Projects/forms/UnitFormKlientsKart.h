//---------------------------------------------------------------------------

#ifndef UnitFormKlientsKartH
#define UnitFormKlientsKartH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "UnitFormKlients.h"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "DBLookupComboBoxCentre.h"
#include "my_DBCtrls.hpp"
//---------------------------------------------------------------------------
class TFormKlientsKart : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape5;
	TLabel *Label1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TShape *Shape1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TButton *Button1;
	TButton *Button2;
	TShape *Shape2;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TDBEdit *Name_DBEdit;
	TDBLookupComboBoxCentre *Katid_DBLookComb;
	TDBEdit *Comp_DBEdit;
	TDBEdit *Phone_DBEdit;
	TDBEdit *Mobile_DBEdit;
	TDBEdit *House_DBEdit;
	TDBEdit *Pager_DBEdit;
	TDBEdit *Operator_DBEdit;
	TDBMemo *Misc_DBMemo;
	TDBEdit *Documents_DBEdit;
	TDBEdit *Rs_DBEdit;
	TDBMemo *Bank_DBMemo;
	TDBEdit *Ks_DBEdit;
	TDBEdit *Bik_DBEdit;
	TDBEdit *Okonh_DBEdit;
	TDBEdit *Okpo_DBEdit;
	TDBEdit *Inn_DBEdit;
	TDBEdit *Status_DBEdit;
	TPanel *Panel1;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall RadioButton4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormKlientsKart(TComponent* Owner, TIBDatabase * MainConn_local,
	TIBTransaction * MainTransaction_local, TDataSource * Clients_Datasource_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormKlientsKart *FormKlientsKart;
//---------------------------------------------------------------------------
#endif
