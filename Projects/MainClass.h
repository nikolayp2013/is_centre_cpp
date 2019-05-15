//---------------------------------------------------------------------------

#ifndef MainClassH
#define MainClassH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBGrids.hpp>
#include <DBXInterbase.hpp>
#include <Grids.hpp>
#include <SimpleDS.hpp>
#include <SqlExpr.hpp>
#include <WideStrings.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <ADODB.hpp>
#include "IBCustomDataSet.hpp"
#include "IBDatabase.hpp"
#include "IBTable.hpp"
#include <Buttons.hpp>
#include <FormEditKart.h>
#include <FormConvert.h>
#include <FormPrint.h>
#include <UnitFormKlients.h>
#include <FormStatAgent.h>
#include "UnitFormAgent.h"
#include "DBLookupComboBoxCentre.h"
#include "my_DBCtrls.hpp"
#include <DBTables.hpp>
#include <iostream.h>
#include <stdlib.h>
#include "UnitFormInfoWindow.h"
#include "UnitFormFindKart.h"
#include "UnitFormGroupEdit.h"
#include "UnitFormExcelExport.h"
#include "UnitFormThems.h"
#include "UnitFormNastr.h"
#include "UnitFormStatFirm.h"
#include "UnitFormSpravAgent.h"
#include "UnitFormReestrAbonent.h"
#include "UnitFormReklam.h"
#include "UnitExportData.h"
#include "UnitFormGridColumn.h"
#include "UnitFormEditApartPurch.h"
#include "UnitFormEditRoomsSell.h"
#include "UnitFormEditRoomsPurch.h"
#include "UnitFormEditArendSell.h"
#include "UnitFormEditArendPurch.h"
#include "UnitFormEditHouseSell.h"
#include "UnitFormEditHousePurch.h"
#include "UnitFormEditGarageSell.h"
#include "UnitFormEditGaragePurch.h"
#include "UnitFormEditLandSell.h"
#include "UnitFormEditCommercPurch.h"
#include "UnitFormEditNewBuildsSell.h"
#include "UnitFormEditCommercSell1.h"
#include "UnitFormEditCommercSell2.h"
#include "UnitFormEditCommercSell3.h"
#include "UnitFormEditCommercSell4.h"
#include "UnitFormEditBusinessSell.h"
#include "UnitFormEditAbroadSell.h"
#include "UnitFormEditSellAll.h"
#include "UnitFormFilterAddArend.h"
#include "UnitFormFilterAddRooms.h"
#include "UnitFormFilterAddHouse.h"
#include "UnitFormFilterAdd.h"
#include "UnitFormFilterAddSearch.h"
#include "UnitFormTest.h"
#include "UnitFormSwap.h"
#include "UnitFormSelectBlue.h"
#include "FormGallaryView.h"
#include <ImgList.hpp>
#include "IniFiles.hpp"
#include <Graphics.hpp>
#include<stdio.h>
#include <ComCtrls.hpp>
#include "DBGridEh.hpp"
//#include "DBGridEhGrouping.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"
#include "DataDriverEh.hpp"
#include "MemTableDataEh.hpp"
#include "IBXDataDriverEh.hpp"
#include <Provider.hpp>
#include "MemTableEh.hpp"
#include "IBQuery.hpp"
#include <string>
#include <CheckLst.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <OleServer.hpp>
#include "UnitFormReg.h"
#include "UnitFormKartHistory.h"
#include "UnitFormHelp.h"
#include "DbUtilsEh.hpp"
#define TGridDrawState Gridseh::TGridDrawState
#define gdFocused Gridseh::gdFocused
#include "frxClass.hpp"
#include "frxPreview.hpp"
#include "frxDesgn.hpp"
#include "frxExportPDF.hpp"
#include "frxExportXLS.hpp"
#include "frxIBXComponents.hpp"
#include "frxDBSet.hpp"
#include "IBQuery.hpp"
#include "DBGridEhImpExp.hpp"
#include "UnitFormExportGrid.h"
const int OwnerCode = 102; // константа определ€юща€ владельца
const AnsiString sPath = ExtractFileDir(Application->ExeName);
extern String FilterMain;
extern String TypeObject;
extern int needfieldsref;
extern int FormRegOk;
extern TIBDatabase * MainConn;
extern TIBTable * Table_Abonents;
extern int pricetype;
extern int swinsert;
extern String FilterSQL;
extern String strFilterAdd;
extern String strApartFilter;
/*extern String strApartPurchFilter;
extern String strRoomsSellFilter;
extern String strRoomsPurchFilter;
extern String strArendSellFilter;
extern String strArendPurchFilter;
extern String strHouseSellFilter;
extern String strHousePurchFilter;
extern String strGarageSellFilter;
extern String strGaragePurchFilter;
extern String strLandSellFilter;
extern String strNewBuildsSellFilter;
extern String strCommercPurchFilter;
extern String strCommercSell1Filter;
extern String strCommercSell2Filter;
extern String strCommercSell3Filter;
extern String strCommercSell4Filter;
extern String strBusinessSellFilter;
extern String strCommercSellAllFilter;
extern String strArendSellAllFilter;
extern String strAbroadSellFilter; */
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N12;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N11;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *Dbl1;
	TMenuItem *N17;
	TMenuItem *Rkbtyncrfzajhvf1;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *N21;
	TMenuItem *N22;
	TMenuItem *N23;
	TMenuItem *N24;
	TMenuItem *N25;
	TMenuItem *N26;
	TMenuItem *N27;
	TMenuItem *N28;
	TMenuItem *RENTSALE1;
	TMenuItem *N29;
	TMenuItem *N30;
	TMenuItem *N31;
	TMenuItem *N32;
	TMenuItem *N33;
	TMenuItem *Exel1;
	TMenuItem *N34;
	TMenuItem *N35;
	TMenuItem *N36;
	TMenuItem *N37;
	TMenuItem *N38;
	TMenuItem *N39;
	TPanel *Panel3;
	TShape *Shape4;
	TCheckBox *Photo_CheckBox;
	TEdit *Dateto_Edit;
	TShape *Shape9;
	TRadioButton *Date_ch_RadioButton;
	TRadioButton *Date_enter_RadioButton;
	TShape *Shape10;
	TShape *Shape11;
	TComboBox *Plus_ComboBox;
	TEdit *Marza_Edit;
	TComboBox *Part_ComboBox;
	TSpeedButton *SpeedButton32;
	TMenuItem *N40;
	TMenuItem *N41;
	TMenuItem *N42;
	TMenuItem *N43;
	TMenuItem *N44;
	TMenuItem *N45;
	TMenuItem *N46;
	TMenuItem *N47;
	TImageList *ImageList1;
	TIBTable *IBTable1;
	TPanel *Panel1;
	TSpeedButton *Viewkart_SpeedButton;
	TSpeedButton *Addkart_SpeedButton;
	TSpeedButton *Delkart_SpeedButton;
	TSpeedButton *Refreshkart_SpeedButton;
	TSpeedButton *Updateprice_SpeedButton;
	TSpeedButton *Info_SpeedButton;
	TSpeedButton *Clients_SpeedButton;
	TSpeedButton *Userch_SpeedButton;
	TSpeedButton *Help_SpeedButton;
	TButton *Button4;
	TComboBox *Razdel_ComboBox;
	TPanel *Agent_Panel;
	TImage *Agent_Image;
	TLabel *Agent_Label;
	TPanel *DSP_Panel;
	TImage *DSP_Image;
	TLabel *DSP_Label;
	TPanel *Client_Panel;
	TImage *Client_Image;
	TLabel *Client_Label;
	TPanel *Spr_Panel;
	TImage *Spr_Image;
	TPanel *Opr_Panel;
	TImage *Opr_Image;
	TPanel *Apr_Panel;
	TImage *Apr_Image;
	TPanel *Purch_Panel;
	TImage *Purch_Image;
	TPanel *Print_Panel;
	TImage *Print_Image;
	TPanel *Sell_Panel;
	TImage *Sell_Image;
	TButton *Button12;
	TPanel *RS_Panel;
	TImage *Image1;
	TPanel *Excl_Panel;
	TPanel *Open_Panel;
	TPanel *Nodog_Panel;
	TPanel *Rekl_Panel;
	TImage *Image2;
	TPanel *Excel_Panel;
	TImage *Image3;
	TPanel *Web_Panel;
	TPanel *CloseFilter_Panel;
	TPanel *Panel7;
	TCheckBox *CheckBox11;
	TCheckBox *CheckBox10;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	TLabel *Label10;
	TPanel *ApartSell_Panel;
	TShape *Shape6;
	TBevel *Bevel5;
	TBevel *Bevel4;
	TBevel *Bevel2;
	TBevel *Bevel1;
	TShape *Shape5;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TBevel *Bevel3;
	TBevel *Bevel6;
	TSpeedButton *SpeedButton27;
	TSpeedButton *SpeedButton28;
	TSpeedButton *SpeedButton29;
	TSpeedButton *SpeedButton30;
	TSpeedButton *SpeedButton31;
	TShape *Shape7;
	TLabel *Label7;
	TShape *Shape8;
	TLabel *Label8;
	TLabel *Label9;
	TSpeedButton *SpeedButton26;
	TLabel *Typehouse_Label;
	TLabel *Stuffwall_Label;
	TLabel *Region_Label;
	TLabel *Mregion_Label;
	TLabel *Obmen_Label;
	TLabel *Sell_Label;
	TCheckBox *Room5_CheckBox;
	TCheckBox *Room1_CheckBox;
	TCheckBox *Room2_CheckBox;
	TCheckBox *Room3_CheckBox;
	TCheckBox *Room4_CheckBox;
	TButton *Typehouse_Button;
	TButton *Stuffwall_Button;
	TButton *Region_Button;
	TButton *Mregion_Button;
	TButton *Button6;
	TButton *Sell_Button;
	TComboBox *Level_ComboBox;
	TEdit *Price1_Edit;
	TEdit *Price2_Edit;
	TCheckBox *Morgage_CheckBox;
	TCheckBox *Part_CheckBox;
	TBitBtn *BitBtn1;
	TPanel *ApartPurch_Panel;
	TLabel *Label13;
	TPanel *RoomsSell_Panel;
	TShape *Shape2;
	TBevel *Bevel7;
	TBevel *Bevel8;
	TBevel *Bevel9;
	TBevel *Bevel10;
	TShape *Shape12;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TBevel *Bevel11;
	TBevel *Bevel12;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TShape *Shape13;
	TLabel *Label19;
	TShape *Shape14;
	TLabel *Label20;
	TLabel *Label21;
	TSpeedButton *SpeedButton6;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button5;
	TButton *Button7;
	TButton *Button8;
	TComboBox *ComboBox1;
	TEdit *Edit2;
	TEdit *Edit3;
	TBitBtn *BitBtn6;
	TPanel *ArendSell_Panel;
	TShape *Shape15;
	TBevel *Bevel13;
	TBevel *Bevel14;
	TBevel *Bevel15;
	TBevel *Bevel16;
	TShape *Shape16;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TBevel *Bevel17;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TShape *Shape17;
	TLabel *Label33;
	TShape *Shape18;
	TLabel *Label34;
	TLabel *Label35;
	TSpeedButton *SpeedButton12;
	TLabel *Label36;
	TLabel *Label37;
	TLabel *Label38;
	TLabel *Label39;
	TLabel *Label40;
	TLabel *Label41;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	TCheckBox *CheckBox9;
	TCheckBox *CheckBox12;
	TCheckBox *CheckBox13;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button13;
	TButton *Button14;
	TComboBox *ComboBox5;
	TEdit *Edit4;
	TEdit *Edit5;
	TBitBtn *BitBtn7;
	TLabel *Label42;
	TComboBox *ComboBox6;
	TBitBtn *BitBtn8;
	TPanel *HouseSell_Panel;
	TShape *Shape19;
	TBevel *Bevel18;
	TBevel *Bevel19;
	TBevel *Bevel20;
	TBevel *Bevel21;
	TBevel *Bevel22;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton13;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TShape *Shape22;
	TLabel *Label49;
	TLabel *Label50;
	TSpeedButton *SpeedButton16;
	TLabel *Label51;
	TLabel *Label52;
	TLabel *Label53;
	TLabel *Label54;
	TLabel *Label55;
	TLabel *Label56;
	TLabel *Label57;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TEdit *Edit7;
	TEdit *Edit8;
	TBitBtn *BitBtn9;
	TEdit *Edit9;
	TBevel *Bevel23;
	TSpeedButton *SpeedButton17;
	TButton *Button21;
	TBevel *Bevel24;
	TSpeedButton *SpeedButton18;
	TButton *Button22;
	TBevel *Bevel25;
	TSpeedButton *SpeedButton19;
	TButton *Button23;
	TBevel *Bevel26;
	TSpeedButton *SpeedButton20;
	TButton *Button24;
	TBevel *Bevel27;
	TSpeedButton *SpeedButton21;
	TButton *Button25;
	TPanel *GarageSell_Panel;
	TShape *Shape20;
	TBevel *Bevel28;
	TBevel *Bevel29;
	TBevel *Bevel30;
	TBevel *Bevel31;
	TBevel *Bevel32;
	TSpeedButton *SpeedButton22;
	TSpeedButton *SpeedButton23;
	TSpeedButton *SpeedButton24;
	TSpeedButton *SpeedButton25;
	TShape *Shape21;
	TLabel *Label43;
	TLabel *Label44;
	TSpeedButton *SpeedButton33;
	TLabel *Label45;
	TLabel *Label46;
	TLabel *Label47;
	TLabel *Label48;
	TLabel *Label58;
	TLabel *Label59;
	TLabel *Label60;
	TButton *Button26;
	TButton *Button27;
	TButton *Button28;
	TButton *Button29;
	TButton *Button30;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TButton *Button34;
	TShape *Shape23;
	TPanel *LandSell_Panel;
	TShape *Shape24;
	TShape *Shape25;
	TBevel *Bevel33;
	TBevel *Bevel34;
	TBevel *Bevel35;
	TBevel *Bevel36;
	TBevel *Bevel37;
	TSpeedButton *SpeedButton34;
	TSpeedButton *SpeedButton35;
	TSpeedButton *SpeedButton36;
	TSpeedButton *SpeedButton37;
	TShape *Shape26;
	TLabel *Label61;
	TLabel *Label62;
	TSpeedButton *SpeedButton38;
	TLabel *Label63;
	TLabel *Label64;
	TLabel *Label65;
	TLabel *Label66;
	TLabel *Label67;
	TLabel *Label68;
	TLabel *Label69;
	TButton *Button31;
	TButton *Button32;
	TButton *Button33;
	TButton *Button35;
	TButton *Button36;
	TEdit *Edit13;
	TEdit *Edit14;
	TEdit *Edit15;
	TButton *Button37;
	TButton *Button38;
	TBevel *Bevel38;
	TSpeedButton *SpeedButton39;
	TShape *Shape27;
	TLabel *Label70;
	TLabel *Label71;
	TEdit *Edit16;
	TEdit *Edit17;
	TShape *Shape28;
	TLabel *Label72;
	TLabel *Label73;
	TShape *Shape29;
	TLabel *Label74;
	TLabel *Label75;
	TEdit *Edit20;
	TEdit *Edit21;
	TPanel *CommercSell1_Panel;
	TShape *Shape30;
	TShape *Shape31;
	TBevel *Bevel41;
	TBevel *Bevel42;
	TBevel *Bevel43;
	TSpeedButton *SpeedButton40;
	TSpeedButton *SpeedButton41;
	TShape *Shape32;
	TLabel *Label76;
	TLabel *Label77;
	TSpeedButton *SpeedButton44;
	TLabel *Label78;
	TLabel *Label79;
	TLabel *Label80;
	TLabel *Label81;
	TLabel *Label82;
	TLabel *Label83;
	TLabel *Label84;
	TShape *Shape33;
	TLabel *Label85;
	TLabel *Label86;
	TShape *Shape34;
	TLabel *Label87;
	TLabel *Label88;
	TButton *Button20;
	TButton *Button39;
	TButton *Button40;
	TEdit *Edit18;
	TEdit *Edit19;
	TEdit *Edit22;
	TButton *Button43;
	TEdit *Edit23;
	TEdit *Edit24;
	TEdit *Edit25;
	TEdit *Edit26;
	TPanel *CommercSell2_Panel;
	TShape *Shape35;
	TShape *Shape36;
	TBevel *Bevel39;
	TBevel *Bevel40;
	TBevel *Bevel44;
	TSpeedButton *SpeedButton42;
	TSpeedButton *SpeedButton43;
	TShape *Shape37;
	TLabel *Label89;
	TLabel *Label90;
	TSpeedButton *SpeedButton45;
	TLabel *Label91;
	TLabel *Label92;
	TLabel *Label93;
	TLabel *Label94;
	TLabel *Label95;
	TLabel *Label96;
	TLabel *Label97;
	TShape *Shape38;
	TLabel *Label98;
	TLabel *Label99;
	TShape *Shape39;
	TLabel *Label100;
	TLabel *Label101;
	TButton *Button41;
	TButton *Button42;
	TButton *Button44;
	TEdit *Edit27;
	TEdit *Edit28;
	TEdit *Edit29;
	TButton *Button45;
	TEdit *Edit30;
	TEdit *Edit31;
	TEdit *Edit32;
	TEdit *Edit33;
	TCheckBox *CheckBox14;
	TPanel *NewBuildsSell_Panel;
	TShape *Shape40;
	TBevel *Bevel47;
	TBevel *Bevel48;
	TShape *Shape41;
	TLabel *Label102;
	TLabel *Label103;
	TLabel *Label104;
	TLabel *Label105;
	TLabel *Label106;
	TSpeedButton *SpeedButton46;
	TShape *Shape42;
	TLabel *Label107;
	TShape *Shape43;
	TLabel *Label108;
	TLabel *Label109;
	TSpeedButton *SpeedButton50;
	TLabel *Label110;
	TLabel *Label111;
	TLabel *Label112;
	TLabel *Label113;
	TLabel *Label114;
	TLabel *Label115;
	TLabel *Label116;
	TCheckBox *CheckBox15;
	TCheckBox *CheckBox16;
	TCheckBox *CheckBox17;
	TCheckBox *CheckBox18;
	TCheckBox *CheckBox19;
	TButton *Button46;
	TButton *Button47;
	TEdit *Edit34;
	TEdit *Edit35;
	TCheckBox *CheckBox20;
	TCheckBox *CheckBox21;
	TShape *Shape44;
	TEdit *Edit36;
	TLabel *Label117;
	TEdit *Edit37;
	TUpDown *UpDown1;
	TLabel *Label118;
	TLabel *Label119;
	TEdit *Edit38;
	TEdit *Edit39;
	TLabel *Label120;
	TLabel *Label121;
	TShape *Shape45;
	TPanel *ArendSellAll_Panel;
	TShape *Shape46;
	TShape *Shape47;
	TBevel *Bevel46;
	TShape *Shape48;
	TLabel *Label122;
	TLabel *Label123;
	TSpeedButton *SpeedButton49;
	TLabel *Label124;
	TLabel *Label125;
	TLabel *Label126;
	TLabel *Label127;
	TLabel *Label128;
	TLabel *Label129;
	TLabel *Label130;
	TShape *Shape49;
	TLabel *Label131;
	TLabel *Label132;
	TShape *Shape50;
	TButton *Button48;
	TEdit *Edit40;
	TEdit *Edit41;
	TEdit *Edit42;
	TButton *Button51;
	TEdit *Edit43;
	TEdit *Edit44;
	TShape *Shape51;
	TLabel *Label135;
	TLabel *Label136;
	TLabel *Label137;
	TLabel *Label138;
	TLabel *Label139;
	TLabel *Label140;
	TEdit *Edit47;
	TLabel *Label133;
	TComboBox *ComboBox7;
	TLabel *Label134;
	TLabel *Label141;
	TPanel *BusinessSell_Panel;
	TShape *Shape52;
	TShape *Shape54;
	TLabel *Label144;
	TLabel *Label145;
	TLabel *Label146;
	TLabel *Label147;
	TLabel *Label148;
	TLabel *Label149;
	TLabel *Label150;
	TShape *Shape55;
	TLabel *Label151;
	TLabel *Label152;
	TEdit *Edit48;
	TButton *Button53;
	TEdit *Edit49;
	TEdit *Edit50;
	TLabel *Label142;
	TComboBox *ComboBox8;
	TShape *Shape53;
	TLabel *Label143;
	TLabel *Label153;
	TShape *Shape56;
	TLabel *Label154;
	TLabel *Label155;
	TComboBox *ComboBox10;
	TPanel *AbroadSell_Panel;
	TShape *Shape57;
	TShape *Shape58;
	TBevel *Bevel49;
	TShape *Shape59;
	TLabel *Label156;
	TLabel *Label157;
	TSpeedButton *SpeedButton51;
	TLabel *Label158;
	TLabel *Label159;
	TLabel *Label160;
	TLabel *Label161;
	TLabel *Label162;
	TLabel *Label163;
	TLabel *Label164;
	TShape *Shape60;
	TLabel *Label165;
	TLabel *Label166;
	TShape *Shape61;
	TLabel *Label167;
	TLabel *Label168;
	TButton *Button49;
	TEdit *Edit45;
	TEdit *Edit46;
	TEdit *Edit51;
	TButton *Button54;
	TEdit *Edit52;
	TEdit *Edit53;
	TEdit *Edit54;
	TEdit *Edit55;
	TButton *Button50;
	TBevel *Bevel45;
	TSpeedButton *SpeedButton47;
	TShape *Shape62;
	TIBDataSet *MainTable2;
	TPopupMenu *PopupMenu1;
	TMenuItem *N48;
	TMenuItem *N49;
	TMenuItem *N50;
	TMenuItem *N51;
	TMenuItem *N52;
	TMenuItem *N53;
	TMenuItem *N54;
	TMenuItem *N55;
	TMenuItem *N56;
	TMenuItem *N57;
	TMenuItem *N58;
	TMenuItem *N59;
	TMenuItem *N60;
	TMenuItem *N61;
	TMenuItem *N62;
	TMenuItem *N63;
	TMenuItem *N64;
	TPanel *Panel4;
	TPanel *Panel2;
	TLabel *Label1;
	TLabel *CompStr_Label;
	TEdit *Edit1;
	TEdit *CompStr_Edit;
	TPanel *Panel5;
	TShape *Count_Shape;
	TLabel *Reccount_Label;
	TShape *Shape3;
	TPanel *Panel6;
	TShape *Shape1;
	TLabel *Label11;
	TRadioButton *Priceru_RadioButton;
	TRadioButton *Priceye_RadioButton;
	TComboBox *ComboBox2;
	TCheckBox *CheckBox1;
	TDBGridEh *DBMainGrid;
	TClientDataSet *ClientDataSet1;
	TDataSetProvider *DataSetProvider1;
	TDataSource *TabPricelist_Datasource_Main;
	TIBDatabase *MainConn;
	TIBTransaction *IBTransaction1;
	TMemTableEh *MainTable;
	TIBXDataDriverEh *IBXDataDriverEh1;
	TIBTable *Table_Abonents;
	TIBQuery *work_query;
	TIBTable *Table_Items_8;
	TIBTransaction *OtherTransaction;
	void __fastcall Button26Click(TObject *Sender);
	void __fastcall Button27Click(TObject *Sender);
	void __fastcall Addkart_SpeedButtonClick(TObject *Sender);
	void __fastcall Mregion_ButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N23Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall N29Click(TObject *Sender);
	void __fastcall N31Click(TObject *Sender);
	void __fastcall N30Click(TObject *Sender);
	void __fastcall N32Click(TObject *Sender);
	void __fastcall N33Click(TObject *Sender);
	void __fastcall Exel1Click(TObject *Sender);
	void __fastcall N41Click(TObject *Sender);
	void __fastcall N35Click(TObject *Sender);
	void __fastcall N36Click(TObject *Sender);
	void __fastcall N24Click(TObject *Sender);
	void __fastcall N25Click(TObject *Sender);
	void __fastcall N26Click(TObject *Sender);
	//void __fastcall DBMainGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
    //      TColumn *Column, TGridDrawState State);
	void __fastcall DBMainGrid1CellClick(TColumn *Column);
	void __fastcall Delkart_SpeedButtonClick(TObject *Sender);
	void __fastcall Viewkart_SpeedButtonClick(TObject *Sender);
	void __fastcall SetThems(TObject *Sender);
	void __fastcall N42Click(TObject *Sender);
	void __fastcall N47Click(TObject *Sender);
	void __fastcall N44Click(TObject *Sender);
	void __fastcall Agent_ImageClick(TObject *Sender);
	void __fastcall Client_ImageClick(TObject *Sender);
	void __fastcall DSP_ImageClick(TObject *Sender);
	void __fastcall Spr_ImageClick(TObject *Sender);
	void __fastcall Opr_ImageClick(TObject *Sender);
	void __fastcall Apr_ImageClick(TObject *Sender);
	void __fastcall Purch_PanelClick(TObject *Sender);
	void __fastcall Purch_PanelMouseEnter(TObject *Sender);
	void __fastcall Purch_PanelMouseLeave(TObject *Sender);
	void __fastcall Print_PanelClick(TObject *Sender);
	void __fastcall Print_PanelMouseEnter(TObject *Sender);
	void __fastcall Print_PanelMouseLeave(TObject *Sender);
	void __fastcall Sell_PanelClick(TObject *Sender);
	void __fastcall Sell_PanelMouseEnter(TObject *Sender);
	void __fastcall Sell_PanelMouseLeave(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall RS_PanelClick(TObject *Sender);
	void __fastcall RS_PanelMouseEnter(TObject *Sender);
	void __fastcall RS_PanelMouseLeave(TObject *Sender);
	void __fastcall Excl_PanelClick(TObject *Sender);
	void __fastcall Excl_PanelMouseEnter(TObject *Sender);
	void __fastcall Excl_PanelMouseLeave(TObject *Sender);
	void __fastcall Open_PanelClick(TObject *Sender);
	void __fastcall Open_PanelMouseEnter(TObject *Sender);
	void __fastcall Open_PanelMouseLeave(TObject *Sender);
	void __fastcall Nodog_PanelClick(TObject *Sender);
	void __fastcall Nodog_PanelMouseEnter(TObject *Sender);
	void __fastcall Nodog_PanelMouseLeave(TObject *Sender);
	void __fastcall Rekl_PanelClick(TObject *Sender);
	void __fastcall Rekl_PanelMouseEnter(TObject *Sender);
	void __fastcall Rekl_PanelMouseLeave(TObject *Sender);
	void __fastcall Excel_PanelClick(TObject *Sender);
	void __fastcall Excel_PanelMouseEnter(TObject *Sender);
	void __fastcall Excel_PanelMouseLeave(TObject *Sender);
	void __fastcall Web_PanelClick(TObject *Sender);
	void __fastcall Web_PanelMouseEnter(TObject *Sender);
	void __fastcall Web_PanelMouseLeave(TObject *Sender);
	void __fastcall RefreshGrid(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall CloseFilter_PanelMouseEnter(TObject *Sender);
	void __fastcall CloseFilter_PanelMouseLeave(TObject *Sender);
	void __fastcall CloseFilter_PanelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Refresh_Fieldsdef(TObject *Sender);
	void __fastcall Refresh_Tabledef(TObject *Sender);
	void __fastcall Filter_MainTable(TObject *Sender);
	void __fastcall Razdel_ComboBoxClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall ApartFilter(TObject *Sender);
	void __fastcall Photo_CheckBoxClick(TObject *Sender);
	void __fastcall Room1_CheckBoxClick(TObject *Sender);
	void __fastcall Room2_CheckBoxClick(TObject *Sender);
	void __fastcall Room3_CheckBoxClick(TObject *Sender);
	void __fastcall Room4_CheckBoxClick(TObject *Sender);
	void __fastcall Room5_CheckBoxClick(TObject *Sender);
	void __fastcall Typehouse_ButtonClick(TObject *Sender);
	void __fastcall Stuffwall_ButtonClick(TObject *Sender);
	void __fastcall Region_ButtonClick(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Sell_ButtonClick(TObject *Sender);
	void __fastcall SpeedButton26Click(TObject *Sender);
	void __fastcall SpeedButton27Click(TObject *Sender);
	void __fastcall SpeedButton28Click(TObject *Sender);
	void __fastcall SpeedButton29Click(TObject *Sender);
	void __fastcall SpeedButton30Click(TObject *Sender);
	void __fastcall SpeedButton31Click(TObject *Sender);
	void __fastcall Level_ComboBoxClick(TObject *Sender);
	void __fastcall Price1_EditExit(TObject *Sender);
	void __fastcall Price2_EditExit(TObject *Sender);
	void __fastcall Part_CheckBoxClick(TObject *Sender);
	void __fastcall Morgage_CheckBoxClick(TObject *Sender);
	void __fastcall Dateto_EditExit(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall RefreshFilterPanel(TObject *Sender);
	void __fastcall BitBtn7Click(TObject *Sender);
	void __fastcall BitBtn6Click(TObject *Sender);
	void __fastcall BitBtn9Click(TObject *Sender);
	void __fastcall Updateprice_SpeedButtonClick(TObject *Sender);
	void __fastcall DrawGridCheckBox(TCanvas *Canvas, TRect Rect, bool Checked);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall N20Click(TObject *Sender);
	void __fastcall N59Click(TObject *Sender);
	void __fastcall Priceru_RadioButtonClick(TObject *Sender);
	void __fastcall Priceye_RadioButtonClick(TObject *Sender);
	void __fastcall Userch_SpeedButtonClick(TObject *Sender);
	void __fastcall Help_SpeedButtonClick(TObject *Sender);
	void __fastcall procviewkart(TObject *Sender);
	void __fastcall DBMainGridColumns0EditButtonClick(TObject *Sender, bool &Handled);
	void __fastcall DBMainGridCellClick(TColumnEh *Column);
	void __fastcall DBMainGridDrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
		  TColumnEh *Column, TGridDrawState State);
	void __fastcall SpeedButton32Click(TObject *Sender);
	void __fastcall DBMainGridSelectionChanged(TObject *Sender);


   //	void __fastcall BeginResize(TMessage *Sender);
	//void __fastcall EndResize(TObject *Sender);
	/*void __fastcall SetLanguage(TObject *Sender)
	{
    	//---- ѕереключение раскладки клавиатуры
		char s[64];
		GetKeyboardLayoutName(s);
		//таким образом получаем текущий €зык (активное окно)
		if (s!="00000419") {
			//LoadKeyboardLayout("00000409", KLF_ACTIVATE);
			//Engлиш
			LoadKeyboardLayout("00000419", KLF_ACTIVATE);
			//–уссиан
		}
	}; */
private:	// User declarations
public:		// User declarations
//, TIBDatabase * MainConn_local
	__fastcall TMainForm(TComponent* Owner);
	AnsiString razdel;
	//TIBDataSet * MainTable;
	/*BEGIN_MESSAGE_MAP
		MESSAGE_HANDLER (WM_ENTERSIZEMOVE, TMessage, BeginResize(message))
		MESSAGE_HANDLER (WM_EXITSIZEMOVE, TMessage, EndResize)
	END_MESSAGE_MAP(TForm);*/
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
