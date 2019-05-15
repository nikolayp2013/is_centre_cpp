//---------------------------------------------------------------------------

#ifndef UnitAgKartEditH
#define UnitAgKartEditH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ExtCtrls.hpp>
#include <UnitFormAgent.h>
#include <UnitFormAgentPass.h>
#include "DBLookupComboBoxCentre.h"
#include "my_DBCtrls.hpp"
//---------------------------------------------------------------------------
class TFormAgKartEdit : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonPass;
	TLabel *Label1;
	TComboBox *Manager_ComboBox;
	TLabel *Label2;
	TDBEdit *LicKart_DBEdit;
	TLabel *Label3;
	TDBEdit *DateEnter_DBEdit;
	TLabel *Label4;
	TDBEdit *KartNo_DBEdit;
	TShape *Shape2;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TDBEdit *Surname_DBEdit;
	TDBEdit *Name_DBEdit;
	TDBEdit *Secname_DBEdit;
	TDBEdit *Fullname_DBEdit;
	TShape *Shape1;
	TLabel *Label8;
	TDBEdit *ReklName_DBEdit;
	TShape *Shape3;
	TLabel *Label9;
	TDBEdit *ReklPhone_DBEdit;
	TLabel *Label10;
	TDBEdit *PhoneAdd_DBEdit;
	TShape *Shape4;
	TLabel *Label11;
	TLabel *Label12;
	TDBEdit *SotPhone_DBEdit;
	TDBEdit *E_mail_DBEdit;
	TLabel *Label13;
	TShape *Shape5;
	TButton *Button1;
	TShape *Shape6;
	TLabel *Label14;
	TDBCheckBox *Name_DBCheckBox;
	TDBCheckBox *Price_DBCheckBox;
	TDBCheckBox *Main_DBCheckBox;
	TDBCheckBox *Sot_DBCheckBox;
	TDBCheckBox *e_mail_DBCheckBox;
	TDBCheckBox *Add_DBCheckBox;
	TDBLookupComboBoxCentre *Status_DBLookupComboBoxCentre;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Surname_DBEditEnter(TObject *Sender);
	void __fastcall E_mail_DBEditEnter(TObject *Sender);
	void __fastcall ButtonPassClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormAgKartEdit(TComponent* Owner, TDataSource * Agent_datasource_local,
		TIBDatabase * MainConn_local, TIBTransaction * TransactionAgent_loc);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAgKartEdit *FormAgKartEdit;
//---------------------------------------------------------------------------
#endif
