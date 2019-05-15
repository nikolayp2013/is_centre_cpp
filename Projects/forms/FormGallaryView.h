//---------------------------------------------------------------------------

#ifndef FormGallaryViewH
#define FormGallaryViewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "MainClass.h"
#include "FormGallaryViewAdd.h"
#include <ExtCtrls.hpp>
//#define CB(i, o, c) o = i + c; o=(o > 255)? 255 :(o < 0) ? 0 : o; i=o;
//---------------------------------------------------------------------------
class TFormGallView : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TImage *Image1;
	TButton *Button1;
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	//void __fastcall ChangeBrightness(TObject *Sender, TImage * img, int c);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGallView(TComponent* Owner,	int * swgall_local);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGallView *FormGallView;
//---------------------------------------------------------------------------
#endif
