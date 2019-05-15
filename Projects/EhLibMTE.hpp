// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Ehlibmte.pas' rev: 20.00

#ifndef EhlibmteHPP
#define EhlibmteHPP

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
#include <Memtableeh.hpp>	// Pascal unit
#include <Memtabledataeh.hpp>	// Pascal unit
#include <Datadrivereh.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Toolctrlseh.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ehlibmte
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMTEDatasetFeaturesEh;
class PASCALIMPLEMENTATION TMTEDatasetFeaturesEh : public Dbutilseh::TSQLDatasetFeaturesEh
{
	typedef Dbutilseh::TSQLDatasetFeaturesEh inherited;
	
protected:
	Memtabledataeh::TMemRecViewEh* FBaseNode;
	
public:
	__fastcall virtual TMTEDatasetFeaturesEh(void);
	virtual bool __fastcall LocateText(Dbgrideh::TCustomDBGridEh* AGrid, const System::UnicodeString FieldName, const System::UnicodeString Text, Toolctrlseh::TLocateTextOptionsEh AOptions, Toolctrlseh::TLocateTextDirectionEh Direction, Toolctrlseh::TLocateTextMatchingEh Matching, Toolctrlseh::TLocateTextTreeFindRangeEh TreeFindRange);
	virtual void __fastcall ApplyFilter(System::TObject* Sender, Db::TDataSet* DataSet, bool IsReopen);
	virtual void __fastcall ApplySorting(System::TObject* Sender, Db::TDataSet* DataSet, bool IsReopen);
	virtual void __fastcall ExecuteFindDialog(System::TObject* Sender, System::UnicodeString Text, System::UnicodeString FieldName, bool Modal);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TMTEDatasetFeaturesEh(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool SortInView;

}	/* namespace Ehlibmte */
using namespace Ehlibmte;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// EhlibmteHPP
