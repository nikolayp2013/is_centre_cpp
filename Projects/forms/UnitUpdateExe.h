//---------------------------------------------------------------------------

#ifndef UnitUpdateExeH
#define UnitUpdateExeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdFTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdHTTP.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormUpdateExe : public TForm
{
__published:	// IDE-managed Components
	TIdFTP *IdFTP1;
	TButton *Button1;
	TIdTCPClient *IdTCPClient1;
	TIdHTTP *IdHTTP1;
	TProgressBar *ProgressBar1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall IdHTTP1Work(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall IdHTTP1WorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);


private:	// User declarations
public:		// User declarations
	__fastcall TFormUpdateExe(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormUpdateExe *FormUpdateExe;
//---------------------------------------------------------------------------
#endif
