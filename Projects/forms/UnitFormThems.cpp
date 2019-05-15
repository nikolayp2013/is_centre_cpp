//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormThems.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormThems *FormThems;
//���� � ���������
//AnsiString sPath = ExtractFileDir(Application->ExeName);
TIniFile *Ini = new TIniFile(sPath+"\\THEMS\\options.ini");
//---------------------------------------------------------------------------
__fastcall TFormThems::TFormThems(TComponent* Owner)
	: TForm(Owner)
{
	//ShowMessage(sPath);
	ListBox1->Items->Clear();
	TSearchRec SR;
	if (FindFirst(sPath+"\\THEMS\\*.*", faDirectory, SR) == 0) {
        do {
            if (SR.Attr == faDirectory && SR.Name!="." && SR.Name!="..")
				ListBox1->Items->Add(SR.Name);
        } while (FindNext(SR) == 0);
        FindClose(SR);
	}

	String tmpthems = Ini->ReadString("Thems","Themsname","Default");
	for (int i = 0; i < ListBox1->Items->Count; i++) {
		 if (ListBox1->Items->Strings[i]==tmpthems) {
			  ListBox1->ItemIndex=i;
		 }
	}

	//   �������� ������

	// ���������� �����
	if (Ini->ReadString("MainPanel","Pricein","0")==1) Pricein_CheckBox->Checked=true;
		else Pricein_CheckBox->Checked=false;
	// �������� �����
	if (Ini->ReadString("MainPanel","Addk","0")==1) Addk_CheckBox->Checked=true;
		else Addk_CheckBox->Checked=false;
	// ������� �����
	if (Ini->ReadString("MainPanel","Openk","0")==1) Openk_CheckBox->Checked=true;
		else Openk_CheckBox->Checked=false;
	//  ������� �����
	if (Ini->ReadString("MainPanel","Deletek","0")==1) Deletek_CheckBox->Checked=true;
		else Deletek_CheckBox->Checked=false;
	//  �������� �����
	if (Ini->ReadString("MainPanel","Updatek","0")==1) Updatek_CheckBox->Checked=true;
		else Updatek_CheckBox->Checked=false;
	//  ��������� ���
	if (Ini->ReadString("MainPanel","Agentview","0")==1) Agentview_CheckBox->Checked=true;
		else Agentview_CheckBox->Checked=false;
	//  ���������� ���
	if (Ini->ReadString("MainPanel","Clientview","0")==1) Clientview_CheckBox->Checked=true;
		else Clientview_CheckBox->Checked=false;
	//  ��� ���
	if (Ini->ReadString("MainPanel","DSPview","0")==1) DSPview_CheckBox->Checked=true;
		else DSPview_CheckBox->Checked=false;
	//  �������������� ����
	if (Ini->ReadString("MainPanel","Info","0")==1) Info_CheckBox->Checked=true;
		else Info_CheckBox->Checked=false;
	//  �������
	if (Ini->ReadString("MainPanel","Clients","0")==1) Clients_CheckBox->Checked=true;
		else Clients_CheckBox->Checked=false;
	// ����� ������������
	if (Ini->ReadString("MainPanel","Userch","0")==1) Userch_CheckBox->Checked=true;
		else Userch_CheckBox->Checked=false;
	//  ������
	if (Ini->ReadString("MainPanel","Help","0")==1) Help_CheckBox->Checked=true;
		else Help_CheckBox->Checked=false;

	// �������������� ������

	// ���������� ������
	if (Ini->ReadString("AddPanel","Panel","0")==1) Panel_CheckBox->Checked=true;
		else Panel_CheckBox->Checked=false;
	// ����������� / �����
	if (Ini->ReadString("AddPanel","Sprospred","0")==1) Sprospred_CheckBox->Checked=true;
		else Sprospred_CheckBox->Checked=false;
	// ������
	if (	Ini->ReadString("AddPanel","Print","0")==1) Print_CheckBox->Checked==true;
		else Print_CheckBox->Checked=true;
	//  ���� ���������
	if (Ini->ReadString("AddPanel","Typedog","0")==1) Typedog_CheckBox->Checked=true;
		else Typedog_CheckBox->Checked=false;
	//  ����������
	if (Ini->ReadString("AddPanel","Rekl","0")==1) Rekl_CheckBox->Checked=true;
		else Rekl_CheckBox->Checked=false;

	// WriteInteger

}
//---------------------------------------------------------------------------
void __fastcall TFormThems::Button1Click(TObject *Sender)
{
	// ������ ��

	//   �������� ������

    // ���������� �����
	if (Pricein_CheckBox->Checked) Ini->WriteString("MainPanel","Pricein","1");
		else Ini->WriteString("MainPanel","Pricein","0");
	// �������� �����
	if (Addk_CheckBox->Checked) Ini->WriteString("MainPanel","Addk","1");
		else Ini->WriteString("MainPanel","Addk","0");
	// ������� �����
	if (Openk_CheckBox->Checked) Ini->WriteString("MainPanel","Openk","1");
		else Ini->WriteString("MainPanel","Openk","0");
	//  ������� �����
	if (Deletek_CheckBox->Checked) Ini->WriteString("MainPanel","Deletek","1");
		else Ini->WriteString("MainPanel","Deletek","0");
	//  �������� �����
	if (Updatek_CheckBox->Checked) Ini->WriteString("MainPanel","Updatek","1");
		else Ini->WriteString("MainPanel","Updatek","0");
	//  ��������� ���
	if (Agentview_CheckBox->Checked) Ini->WriteString("MainPanel","Agentview","1");
		else Ini->WriteString("MainPanel","Agentview","0");
	//  ���������� ���
	if (Clientview_CheckBox->Checked) Ini->WriteString("MainPanel","Clientview","1");
		else Ini->WriteString("MainPanel","Clientview","0");
	//  ��� ���
	if (DSPview_CheckBox->Checked) Ini->WriteString("MainPanel","DSPview","1");
		else Ini->WriteString("MainPanel","DSPview","0");
	//  �������������� ����
	if (Info_CheckBox->Checked) Ini->WriteString("MainPanel","Info","1");
		else Ini->WriteString("MainPanel","Info","0");
	//  �������
	if (Clients_CheckBox->Checked) Ini->WriteString("MainPanel","Clients","1");
		else Ini->WriteString("MainPanel","Clients","0");
	// ����� ������������
	if (Userch_CheckBox->Checked) Ini->WriteString("MainPanel","Userch","1");
		else Ini->WriteString("MainPanel","Userch","0");
	//  ������
	if (Help_CheckBox->Checked) Ini->WriteString("MainPanel","Help","1");
		else Ini->WriteString("MainPanel","Help","0");

	// �������������� ������

	// ���������� ������
	if (Panel_CheckBox->Checked) Ini->WriteString("AddPanel","Panel","1");
		else Ini->WriteString("AddPanel","Panel","0");
	// ����������� / �����
	if (Sprospred_CheckBox->Checked) Ini->WriteString("AddPanel","Sprospred","1");
		else Ini->WriteString("AddPanel","Sprospred","0");
	// ������
	if (Print_CheckBox->Checked) Ini->WriteString("AddPanel","Print","1");
		else Ini->WriteString("AddPanel","Print","0");
	//  ���� ���������
	if (Typedog_CheckBox->Checked) Ini->WriteString("AddPanel","Typedog","1");
		else Ini->WriteString("AddPanel","Typedog","0");
	//  ����������
	if (Rekl_CheckBox->Checked) Ini->WriteString("AddPanel","Rekl","1");
		else Ini->WriteString("AddPanel","Rekl","0");

	// ���� ����������
	Ini->WriteString("Thems","Themsname",ListBox1->Items->Strings[ListBox1->ItemIndex]);

	Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormThems::Button2Click(TObject *Sender)
{
	// ������ ������
	Close();
}
//---------------------------------------------------------------------------
