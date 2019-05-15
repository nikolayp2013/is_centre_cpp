// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Ehlibcds.pas' rev: 20.00

#ifndef EhlibcdsHPP
#define EhlibcdsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Dbutilseh.hpp>	// Pascal unit
#include <Dbgrideh.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Dbclient.hpp>	// Pascal unit
#include <Provider.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ehlibcds
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCDSDatasetFeaturesEh;
class PASCALIMPLEMENTATION TCDSDatasetFeaturesEh : public Dbutilseh::TDatasetFeaturesEh
{
	typedef Dbutilseh::TDatasetFeaturesEh inherited;
	
public:
	virtual Db::TDataSet* __fastcall GetProviderDataSet(Db::TDataSet* DataSet);
	virtual void __fastcall ApplySorting(System::TObject* Sender, Db::TDataSet* DataSet, bool IsReopen);
	virtual void __fastcall ApplyFilter(System::TObject* Sender, Db::TDataSet* DataSet, bool IsReopen);
public:
	/* TDatasetFeaturesEh.Create */ inline __fastcall virtual TCDSDatasetFeaturesEh(void) : Dbutilseh::TDatasetFeaturesEh() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCDSDatasetFeaturesEh(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ehlibcds */
using namespace Ehlibcds;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// EhlibcdsHPP
