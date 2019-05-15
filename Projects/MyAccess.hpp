// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Myaccess.pas' rev: 20.00

#ifndef MyaccessHPP
#define MyaccessHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Clrclasses.hpp>	// Pascal unit
#include <Crxml.hpp>	// Pascal unit
#include <Myconnectionpool.hpp>	// Pascal unit
#include <Crconnectionpool.hpp>	// Pascal unit
#include <Mysqlapi.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Memutils.hpp>	// Pascal unit
#include <Memds.hpp>	// Pascal unit
#include <Memdata.hpp>	// Pascal unit
#include <Craccess.hpp>	// Pascal unit
#include <Dbaccess.hpp>	// Pascal unit
#include <Myclasses.hpp>	// Pascal unit
#include <Crparser.hpp>	// Pascal unit
#include <Mycall.hpp>	// Pascal unit
#include <Daconsts.hpp>	// Pascal unit
#include <Crvio.hpp>	// Pascal unit
#include <Myconsts.hpp>	// Pascal unit
#include <Dasqlmonitor.hpp>	// Pascal unit
#include <Myservices.hpp>	// Pascal unit
#include <Win32timer.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit
#include <Dbcommontypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#ifdef SetPort
#undef SetPort
#endif

namespace Myaccess
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TMyIsolationLevel { ilReadCommitted, ilReadUnCommitted, ilRepeatableRead, ilSerializable };
#pragma option pop

typedef Memdata::TDANumericType TMyNumericType;

class DELPHICLASS TCustomMyConnectionOptions;
class PASCALIMPLEMENTATION TCustomMyConnectionOptions : public Dbaccess::TDAConnectionOptions
{
	typedef Dbaccess::TDAConnectionOptions inherited;
	
protected:
	bool FUseUnicode;
	System::UnicodeString FCharset;
	bool FOptimizedBigInt;
	bool FNullForZeroDelphiDate;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall SetUseUnicode(const bool Value);
	void __fastcall SetCharset(const System::UnicodeString Value);
	Memdata::TDANumericType __fastcall GetNumericType(void);
	void __fastcall SetNumericType(Memdata::TDANumericType Value);
	void __fastcall SetOptimizedBigInt(const bool Value);
	void __fastcall SetNullForZeroDelphiDate(const bool Value);
	__property EnableBCD = {default=0};
	__property EnableFMTBCD = {default=0};
	
public:
	__fastcall TCustomMyConnectionOptions(Dbaccess::TCustomDAConnection* Owner);
	__property bool UseUnicode = {read=FUseUnicode, write=SetUseUnicode, default=0};
	__property System::UnicodeString Charset = {read=FCharset, write=SetCharset};
	__property KeepDesignConnected = {default=1};
	__property Memdata::TDANumericType NumericType = {read=GetNumericType, write=SetNumericType, default=0};
	__property bool NullForZeroDelphiDate = {read=FNullForZeroDelphiDate, write=SetNullForZeroDelphiDate, default=0};
	__property bool OptimizedBigInt = {read=FOptimizedBigInt, write=SetOptimizedBigInt, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TCustomMyConnectionOptions(void) { }
	
};


class DELPHICLASS TCustomMyConnection;
class PASCALIMPLEMENTATION TCustomMyConnection : public Dbaccess::TCustomDAConnection
{
	typedef Dbaccess::TCustomDAConnection inherited;
	
protected:
	bool FLoginPrompt;
	System::UnicodeString FDatabase;
	int FConnectionTimeout;
	TCustomMyConnectionOptions* FOptions;
	int FThreadId;
	virtual Craccess::TCRConnectionClass __fastcall GetIConnectionClass(void);
	virtual Craccess::TCRCommandClass __fastcall GetICommandClass(void);
	virtual Craccess::TCRRecordSetClass __fastcall GetIRecordSetClass(void);
	virtual Craccess::TCRMetaDataClass __fastcall GetIMetaDataClass(void);
	virtual void __fastcall CreateIConnection(void);
	virtual void __fastcall SetIConnection(Craccess::TCRConnection* Value);
	HIDESBASE void __fastcall SetOptions(TCustomMyConnectionOptions* Value);
	virtual void __fastcall FillConnectionParameters(Myconnectionpool::TMyConnectionParameters* &ConnectionParameters);
	virtual void __fastcall FillConnectionProps(Myclasses::TMySQLConnection* MySQLConnection);
	Myclasses::TMySQLConnection* __fastcall GetMySQLConnection(void);
	void __fastcall ReturnMySQLConnection(Craccess::TCRConnection* CRConnection);
	virtual System::TClass __fastcall SQLMonitorClass(void);
	virtual Dbaccess::TConnectDialogClass __fastcall ConnectDialogClass(void);
	void __fastcall SetDatabase(System::UnicodeString Value);
	TMyIsolationLevel __fastcall GetIsolationLevel(void);
	void __fastcall SetIsolationLevel(const TMyIsolationLevel Value);
	void __fastcall SetConnectionTimeout(const int Value);
	virtual bool __fastcall NeedPrompt(void);
	void __fastcall CheckInactive(void);
	virtual void __fastcall DoConnect(void);
	virtual System::UnicodeString __fastcall GetClientVersion(void) = 0 ;
	System::UnicodeString __fastcall GetServerVersion();
	unsigned __fastcall GetThreadId(void);
	Myclasses::TMySQLConnection* __fastcall IConnection(void);
	virtual void __fastcall AssignConnectOptions(Dbaccess::TCustomDAConnection* Source);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall virtual TCustomMyConnection(Classes::TComponent* Owner);
	__fastcall virtual ~TCustomMyConnection(void);
	virtual Dbaccess::TCustomDADataSet* __fastcall CreateDataSet(void);
	virtual Dbaccess::TCustomDASQL* __fastcall CreateSQL(void);
	virtual Dbaccess::TDATransaction* __fastcall CreateTransaction(void);
	virtual Dbaccess::TDAMetaData* __fastcall CreateMetaData(void);
	HIDESBASE void __fastcall AssignConnect(TCustomMyConnection* Source);
	virtual System::Variant __fastcall ExecSQL(System::UnicodeString Text, System::Variant const *Params, const int Params_Size);
	virtual void __fastcall GetStoredProcNames(Classes::TStrings* List, bool AllProcs = false);
	void __fastcall GetCharsetNames(Classes::TStrings* List);
	void __fastcall GetIndexNames(Classes::TStrings* List, System::UnicodeString TableName);
	void __fastcall GetTriggerNames(Classes::TStrings* List, bool AllTriggers = false);
	System::UnicodeString __fastcall GetExecuteInfo();
	void __fastcall Ping(void);
	void __fastcall Savepoint(const System::UnicodeString Name);
	void __fastcall RollbackToSavepoint(const System::UnicodeString Name);
	void __fastcall ReleaseSavepoint(const System::UnicodeString Name);
	__property System::UnicodeString ClientVersion = {read=GetClientVersion};
	__property System::UnicodeString ServerVersion = {read=GetServerVersion};
	__property unsigned ThreadId = {read=GetThreadId, nodefault};
	__property System::UnicodeString Database = {read=FDatabase, write=SetDatabase};
	__property int ConnectionTimeout = {read=FConnectionTimeout, write=SetConnectionTimeout, default=15};
	__property TMyIsolationLevel IsolationLevel = {read=GetIsolationLevel, write=SetIsolationLevel, default=0};
	__property TCustomMyConnectionOptions* Options = {read=FOptions, write=SetOptions};
	__property PoolingOptions;
	__property Pooling = {default=0};
	__property Username;
	__property Password;
	__property AfterConnect;
	__property BeforeConnect;
	__property AfterDisconnect;
	__property BeforeDisconnect;
	__property OnLogin;
	__property OnError;
	__property ConnectDialog;
	__property LoginPrompt = {default=1};
};


class DELPHICLASS TMyConnectionOptions;
class DELPHICLASS TMyConnection;
class PASCALIMPLEMENTATION TMyConnectionOptions : public TCustomMyConnectionOptions
{
	typedef TCustomMyConnectionOptions inherited;
	
protected:
	bool FCompress;
	Myclasses::TMyProtocol FProtocol;
	bool FEmbedded;
	bool FDirect;
	bool FCheckBackslashes;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall SetCompress(const bool Value);
	void __fastcall SetProtocol(const Myclasses::TMyProtocol Value);
	void __fastcall SetEmbedded(const bool Value);
	void __fastcall SetDirect(const bool Value);
	void __fastcall SetCheckBackslashes(const bool Value);
	
public:
	__fastcall TMyConnectionOptions(TMyConnection* Owner);
	
__published:
	__property bool Compress = {read=FCompress, write=SetCompress, default=0};
	__property UseUnicode = {default=0};
	__property Charset;
	__property Myclasses::TMyProtocol Protocol = {read=FProtocol, write=SetProtocol, default=0};
	__property bool Embedded = {read=FEmbedded, write=SetEmbedded, default=0};
	__property bool Direct = {read=FDirect, write=SetDirect, default=1};
	__property bool CheckBackslashes = {read=FCheckBackslashes, write=SetCheckBackslashes, default=0};
	__property KeepDesignConnected = {default=1};
	__property NumericType = {default=0};
	__property NullForZeroDelphiDate = {default=0};
	__property OptimizedBigInt = {default=0};
	__property DisconnectedMode = {default=0};
	__property LocalFailover = {default=0};
	__property DefaultSortType = {default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TMyConnectionOptions(void) { }
	
};


class DELPHICLASS TMyConnectionSSLOptions;
class PASCALIMPLEMENTATION TMyConnectionSSLOptions : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
	
protected:
	Dbaccess::TCustomDAConnection* FOwner;
	System::UnicodeString FChipherList;
	System::UnicodeString FCACert;
	System::UnicodeString FKey;
	System::UnicodeString FCert;
	void __fastcall SetChipher(const System::UnicodeString Value);
	void __fastcall SetCA(const System::UnicodeString Value);
	void __fastcall SetKey(const System::UnicodeString Value);
	void __fastcall SetCert(const System::UnicodeString Value);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TMyConnectionSSLOptions(TMyConnection* Owner);
	
__published:
	__property System::UnicodeString ChipherList = {read=FChipherList, write=SetChipher};
	__property System::UnicodeString CACert = {read=FCACert, write=SetCA};
	__property System::UnicodeString Key = {read=FKey, write=SetKey};
	__property System::UnicodeString Cert = {read=FCert, write=SetCert};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TMyConnectionSSLOptions(void) { }
	
};


class PASCALIMPLEMENTATION TMyConnection : public TCustomMyConnection
{
	typedef TCustomMyConnection inherited;
	
protected:
	int FPort;
	TMyConnectionSSLOptions* FSSLOptions;
	Crvio::THttpOptions* FHttpOptions;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	TMyConnectionOptions* __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetOptions(TMyConnectionOptions* Value);
	void __fastcall SetSSLOptions(TMyConnectionSSLOptions* Value);
	void __fastcall SetHttpOptions(Crvio::THttpOptions* Value);
	void __fastcall SetPort(int Value);
	bool __fastcall GetEmbedded(void);
	void __fastcall SetEmbedded(bool Value);
	virtual void __fastcall DoConnect(void);
	virtual System::UnicodeString __fastcall GetClientVersion();
	virtual Dbaccess::TDAConnectionOptions* __fastcall CreateOptions(void);
	virtual void __fastcall FillConnectionParameters(Myconnectionpool::TMyConnectionParameters* &ConnectionParameters);
	virtual void __fastcall FillConnectionProps(Myclasses::TMySQLConnection* MySQLConnection);
	
public:
	__fastcall virtual TMyConnection(Classes::TComponent* Owner);
	__fastcall virtual ~TMyConnection(void);
	
__published:
	__property Database;
	__property int Port = {read=FPort, write=SetPort, default=3306};
	__property ConnectionTimeout = {default=15};
	__property IsolationLevel = {default=0};
	__property TMyConnectionOptions* Options = {read=GetOptions, write=SetOptions};
	__property TMyConnectionSSLOptions* SSLOptions = {read=FSSLOptions, write=SetSSLOptions};
	__property Crvio::THttpOptions* HttpOptions = {read=FHttpOptions, write=SetHttpOptions};
	__property bool Embedded = {read=GetEmbedded, write=SetEmbedded, default=0};
	__property PoolingOptions;
	__property Pooling = {default=0};
	__property Username;
	__property Password;
	__property Server;
	__property Connected = {stored=IsConnectedStored, default=0};
	__property AfterConnect;
	__property BeforeConnect;
	__property AfterDisconnect;
	__property BeforeDisconnect;
	__property OnLogin;
	__property OnError;
	__property OnConnectionLost;
	__property ConnectDialog;
	__property LoginPrompt = {default=1};
	__property IOHandler;
};


#pragma option push -b-
enum TLockRecordType { lrImmediately, lrDelayed };
#pragma option pop

class DELPHICLASS TMySQLGenerator;
class PASCALIMPLEMENTATION TMySQLGenerator : public Myservices::TCustomMySQLGenerator
{
	typedef Myservices::TCustomMySQLGenerator inherited;
	
public:
	/* TCustomMySQLGenerator.Create */ inline __fastcall virtual TMySQLGenerator(Dbaccess::TDADataSetService* AOwner) : Myservices::TCustomMySQLGenerator(AOwner) { }
	
public:
	/* TDASQLGenerator.Destroy */ inline __fastcall virtual ~TMySQLGenerator(void) { }
	
};


class DELPHICLASS TMyDataSetService;
class PASCALIMPLEMENTATION TMyDataSetService : public Myservices::TCustomMyDataSetService
{
	typedef Myservices::TCustomMyDataSetService inherited;
	
protected:
	virtual void __fastcall CreateSQLGenerator(void);
	virtual void __fastcall CreateDataSetUpdater(void);
public:
	/* TCustomMyDataSetService.Create */ inline __fastcall virtual TMyDataSetService(Memds::TMemDataSet* AOwner) : Myservices::TCustomMyDataSetService(AOwner) { }
	
public:
	/* TDADataSetService.Destroy */ inline __fastcall virtual ~TMyDataSetService(void) { }
	
};


class DELPHICLASS TMyDataSetUpdater;
class PASCALIMPLEMENTATION TMyDataSetUpdater : public Myservices::TCustomMyDataSetUpdater
{
	typedef Myservices::TCustomMyDataSetUpdater inherited;
	
protected:
	virtual void __fastcall SetUpdateQueryOptions(const Dbaccess::TStatementType StatementType);
public:
	/* TCustomMyDataSetUpdater.Create */ inline __fastcall virtual TMyDataSetUpdater(Memds::TDataSetService* AOwner) : Myservices::TCustomMyDataSetUpdater(AOwner) { }
	
public:
	/* TDADataSetUpdater.Destroy */ inline __fastcall virtual ~TMyDataSetUpdater(void) { }
	
};


class DELPHICLASS TMyDataSetOptions;
class PASCALIMPLEMENTATION TMyDataSetOptions : public Dbaccess::TDADataSetOptions
{
	typedef Dbaccess::TDADataSetOptions inherited;
	
private:
	bool FFieldsAsString;
	bool FNullForZeroDate;
	bool FCheckRowVersion;
	bool FEnableBoolean;
	bool FBinaryAsString;
	bool FAutoRefresh;
	int FAutoRefreshInterval;
	bool FCreateConnection;
	void __fastcall SetFieldsAsString(bool Value);
	void __fastcall SetNullForZeroDate(bool Value);
	void __fastcall SetEnableBoolean(bool Value);
	void __fastcall SetBinaryAsString(bool Value);
	void __fastcall SetAutoRefresh(bool Value);
	void __fastcall SetAutoRefreshInterval(int Value);
	void __fastcall SetCreateConnection(bool Value);
	void __fastcall SetCheckRowVersion(const bool Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TMyDataSetOptions(Dbaccess::TCustomDADataSet* Owner);
	
__published:
	__property SetFieldsReadOnly = {default=0};
	__property FullRefresh = {default=0};
	__property bool FieldsAsString = {read=FFieldsAsString, write=SetFieldsAsString, default=0};
	__property CompressBlobMode = {default=0};
	__property bool NullForZeroDate = {read=FNullForZeroDate, write=SetNullForZeroDate, default=1};
	__property bool CheckRowVersion = {read=FCheckRowVersion, write=SetCheckRowVersion, default=0};
	__property bool EnableBoolean = {read=FEnableBoolean, write=SetEnableBoolean, default=1};
	__property bool BinaryAsString = {read=FBinaryAsString, write=SetBinaryAsString, default=1};
	__property bool AutoRefresh = {read=FAutoRefresh, write=SetAutoRefresh, default=0};
	__property int AutoRefreshInterval = {read=FAutoRefreshInterval, write=SetAutoRefreshInterval, default=60};
	__property bool CreateConnection = {read=FCreateConnection, write=SetCreateConnection, default=1};
	__property AutoPrepare = {default=0};
	__property LongStrings = {default=1};
	__property RequiredFields = {default=0};
	__property StrictUpdate = {default=1};
	__property NumberRange = {default=0};
	__property ReturnParams = {default=0};
	__property TrimFixedChar = {stored=false, default=1};
	__property QueryRecCount = {default=0};
	__property RemoveOnRefresh = {default=1};
	__property FlatBuffers = {default=0};
	__property QuoteNames = {default=0};
	__property DetailDelay = {default=0};
	__property FieldsOrigin = {default=1};
	__property LocalMasterDetail = {default=0};
	__property CacheCalcFields = {default=0};
	__property UpdateBatchSize = {default=1};
	__property UpdateAllFields = {default=0};
	__property DefaultValues = {default=0};
	__property TrimVarChar = {default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TMyDataSetOptions(void) { }
	
};


class DELPHICLASS TCustomMyDataSet;
typedef void __fastcall (__closure *TMyUpdateExecuteEvent)(TCustomMyDataSet* Sender, Dbaccess::TStatementTypes StatementTypes, Dbaccess::TDAParams* Params);

#pragma option push -b-
enum TLockType { ltRead, ltReadLocal, ltWrite, ltWriteLowPriority };
#pragma option pop

class DELPHICLASS TMyUpdateSQL;
class PASCALIMPLEMENTATION TCustomMyDataSet : public Dbaccess::TCustomDADataSet
{
	typedef Dbaccess::TCustomDADataSet inherited;
	
private:
	TCustomMyConnection* __fastcall GetConnection(void);
	HIDESBASE void __fastcall SetConnection(TCustomMyConnection* Value);
	TMyUpdateSQL* __fastcall GetUpdateObject(void);
	HIDESBASE void __fastcall SetUpdateObject(TMyUpdateSQL* Value);
	
protected:
	virtual System::UnicodeString __fastcall PSGetQuoteChar();
	Myclasses::TMySQLRecordset* FIRecordSet;
	Myclasses::TMySQLCommand* FICommand;
	TMyDataSetService* FDataSetService;
	TMyUpdateExecuteEvent FBeforeUpdateExecute;
	TMyUpdateExecuteEvent FAfterUpdateExecute;
	bool FAfterExecProcessing;
	TMyDataSetOptions* FOptions;
	int FCommandTimeout;
	Win32timer::TWin32Timer* FAutoRefreshTimer;
	void __fastcall AutoRefreshTimer(System::TObject* Sender);
	void __fastcall CheckAutoRefreshTimer(void);
	virtual void __fastcall CreateIRecordSet(void);
	virtual void __fastcall SetIRecordSet(Memdata::TData* Value);
	virtual void __fastcall CreateCommand(void);
	virtual Dbaccess::TDADataSetOptions* __fastcall CreateOptions(void);
	HIDESBASE void __fastcall SetOptions(TMyDataSetOptions* Value);
	virtual Memds::TDataSetServiceClass __fastcall GetDataSetServiceClass(void);
	virtual void __fastcall SetDataSetService(Memds::TDataSetService* Value);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall SetCommandTimeout(const int Value);
	virtual bool __fastcall GetIsQuery(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall BeforeOpenCursor(bool InfoQuery);
	virtual void __fastcall DoAfterExecute(bool Result);
	virtual void __fastcall CreateFieldDefs(void);
	virtual void __fastcall CheckInactive(void);
	virtual bool __fastcall AssignedBeforeUpdateExecute(void);
	virtual void __fastcall DoBeforeUpdateExecute(Db::TDataSet* Sender, Dbaccess::TStatementTypes StatementTypes, Dbaccess::TDAParams* Params);
	virtual bool __fastcall AssignedAfterUpdateExecute(void);
	virtual void __fastcall DoAfterUpdateExecute(Db::TDataSet* Sender, Dbaccess::TStatementTypes StatementTypes, Dbaccess::TDAParams* Params);
	virtual System::UnicodeString __fastcall SQLGetFrom(System::UnicodeString SQLText);
	virtual System::UnicodeString __fastcall SQLAddWhere(System::UnicodeString SQLText, System::UnicodeString Condition);
	virtual System::UnicodeString __fastcall SQLDeleteWhere(System::UnicodeString SQLText);
	virtual System::UnicodeString __fastcall SQLGetWhere(System::UnicodeString SQLText);
	virtual System::UnicodeString __fastcall SQLSetOrderBy(System::UnicodeString SQLText, System::UnicodeString Fields);
	virtual System::UnicodeString __fastcall SQLGetOrderBy(System::UnicodeString SQLText);
	
public:
	__fastcall virtual TCustomMyDataSet(Classes::TComponent* Owner);
	__fastcall virtual ~TCustomMyDataSet(void);
	bool __fastcall OpenNext(void);
	void __fastcall RefreshQuick(const bool CheckDeleted);
	void __fastcall BreakExec(void);
	void __fastcall LockTable(TLockType LockType);
	void __fastcall UnLockTable(void);
	virtual void __fastcall Lock(void)/* overload */;
	HIDESBASE void __fastcall Lock(TLockRecordType LockType)/* overload */;
	void __fastcall GetFieldEnum(Classes::TStrings* List, System::UnicodeString FieldName, System::UnicodeString TableName = L"");
	__property FetchAll = {default=1};
	__property LockMode = {default=0};
	__property KeyFields;
	__property __int64 InsertId = {read=FLastInsertId};
	__property int CommandTimeout = {read=FCommandTimeout, write=SetCommandTimeout, default=0};
	__property TMyUpdateSQL* UpdateObject = {read=GetUpdateObject, write=SetUpdateObject};
	__property TCustomMyConnection* Connection = {read=GetConnection, write=SetConnection};
	__property TMyDataSetOptions* Options = {read=FOptions, write=SetOptions};
	__property TMyUpdateExecuteEvent BeforeUpdateExecute = {read=FBeforeUpdateExecute, write=FBeforeUpdateExecute};
	__property TMyUpdateExecuteEvent AfterUpdateExecute = {read=FAfterUpdateExecute, write=FAfterUpdateExecute};
};


class PASCALIMPLEMENTATION TMyUpdateSQL : public Dbaccess::TCustomDAUpdateSQL
{
	typedef Dbaccess::TCustomDAUpdateSQL inherited;
	
protected:
	virtual Dbaccess::TCustomDADataSetClass __fastcall DataSetClass(void);
	virtual Dbaccess::TCustomDASQLClass __fastcall SQLClass(void);
public:
	/* TCustomDAUpdateSQL.Create */ inline __fastcall virtual TMyUpdateSQL(Classes::TComponent* Owner) : Dbaccess::TCustomDAUpdateSQL(Owner) { }
	/* TCustomDAUpdateSQL.Destroy */ inline __fastcall virtual ~TMyUpdateSQL(void) { }
	
};


class DELPHICLASS TMyQuery;
class PASCALIMPLEMENTATION TMyQuery : public TCustomMyDataSet
{
	typedef TCustomMyDataSet inherited;
	
__published:
	__property SQLInsert;
	__property SQLDelete;
	__property SQLUpdate;
	__property SQLRefresh;
	__property SQLLock;
	__property Connection;
	__property ParamCheck = {default=1};
	__property SQL;
	__property Debug = {default=0};
	__property Macros;
	__property Params;
	__property FetchRows = {default=25};
	__property ReadOnly = {default=0};
	__property UniDirectional = {default=0};
	__property CachedUpdates = {default=0};
	__property AfterExecute;
	__property BeforeUpdateExecute;
	__property AfterUpdateExecute;
	__property OnUpdateError;
	__property OnUpdateRecord;
	__property UpdateObject;
	__property RefreshOptions = {default=0};
	__property AutoCalcFields = {default=1};
	__property Filtered = {default=0};
	__property Filter;
	__property FilterOptions = {default=0};
	__property BeforeOpen;
	__property AfterOpen;
	__property BeforeClose;
	__property AfterClose;
	__property BeforeInsert;
	__property AfterInsert;
	__property BeforeEdit;
	__property AfterEdit;
	__property BeforePost;
	__property AfterPost;
	__property BeforeCancel;
	__property AfterCancel;
	__property BeforeDelete;
	__property AfterDelete;
	__property BeforeScroll;
	__property AfterScroll;
	__property OnCalcFields;
	__property OnDeleteError;
	__property OnEditError;
	__property OnFilterRecord;
	__property OnNewRecord;
	__property OnPostError;
	__property AfterRefresh;
	__property BeforeRefresh;
	__property Options;
	__property FilterSQL;
	__property MasterSource;
	__property MasterFields;
	__property DetailFields;
	__property FetchAll = {default=1};
	__property UpdatingTable;
	__property LockMode = {default=0};
	__property KeyFields;
	__property IndexFieldNames;
	__property CommandTimeout = {default=0};
	__property Active = {default=0};
	__property BeforeFetch;
	__property AfterFetch;
public:
	/* TCustomMyDataSet.Create */ inline __fastcall virtual TMyQuery(Classes::TComponent* Owner) : TCustomMyDataSet(Owner) { }
	/* TCustomMyDataSet.Destroy */ inline __fastcall virtual ~TMyQuery(void) { }
	
};


class DELPHICLASS TMyTableOptions;
class PASCALIMPLEMENTATION TMyTableOptions : public TMyDataSetOptions
{
	typedef TMyDataSetOptions inherited;
	
private:
	bool FUseHandler;
	System::UnicodeString FHandlerIndex;
	void __fastcall SetUseHandler(const bool Value);
	void __fastcall SetHandlerIndex(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TMyTableOptions(Dbaccess::TCustomDADataSet* Owner);
	
__published:
	__property bool UseHandler = {read=FUseHandler, write=SetUseHandler, default=0};
	__property System::UnicodeString HandlerIndex = {read=FHandlerIndex, write=SetHandlerIndex};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TMyTableOptions(void) { }
	
};


class DELPHICLASS TCustomMyTable;
class PASCALIMPLEMENTATION TCustomMyTable : public TCustomMyDataSet
{
	typedef TCustomMyDataSet inherited;
	
protected:
	virtual System::UnicodeString __fastcall PSGetTableName();
	virtual void __fastcall PSSetParams(Db::TParams* AParams);
	virtual void __fastcall PSSetCommandText(const System::UnicodeString CommandText)/* overload */;
	System::UnicodeString FTableName;
	System::UnicodeString FOrderFields;
	int FLimit;
	int FOffset;
	Db::TIndexDefs* FIndexDefs;
	void __fastcall SetTableName(const System::UnicodeString Value);
	void __fastcall SetOrderFields(System::UnicodeString Value);
	void __fastcall SetLimit(const int Value);
	void __fastcall SetOffset(const int Value);
	virtual Dbaccess::TDADataSetOptions* __fastcall CreateOptions(void);
	TMyTableOptions* __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetOptions(TMyTableOptions* Value);
	virtual void __fastcall SetIRecordSet(Memdata::TData* Value);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual bool __fastcall SQLAutoGenerated(void);
	bool __fastcall SeparatedHandler(void);
	virtual void __fastcall BeforeOpenCursor(bool InfoQuery);
	virtual void __fastcall AfterOpenCursor(bool InfoQuery);
	virtual void __fastcall InternalClose(void);
	HIDESBASE Db::TIndexDefs* __fastcall GetIndexDefs(void);
	virtual void __fastcall UpdateIndexDefs(void);
	virtual void __fastcall CheckSQL(void);
	
public:
	__fastcall virtual TCustomMyTable(Classes::TComponent* Owner);
	__fastcall virtual ~TCustomMyTable(void);
	virtual void __fastcall Prepare(void);
	void __fastcall PrepareSQL(void);
	virtual void __fastcall Execute(void);
	void __fastcall EmptyTable(void);
	__property System::UnicodeString TableName = {read=FTableName, write=SetTableName};
	__property System::UnicodeString OrderFields = {read=FOrderFields, write=SetOrderFields};
	__property int Limit = {read=FLimit, write=SetLimit, default=-1};
	__property int Offset = {read=FOffset, write=SetOffset, default=0};
	__property TMyTableOptions* Options = {read=GetOptions, write=SetOptions};
	__property Db::TIndexDefs* IndexDefs = {read=GetIndexDefs};
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  PSSetCommandText(const System::WideString CommandText){ Db::TDataSet::PSSetCommandText(CommandText); }
	
};


class DELPHICLASS TMyTable;
class PASCALIMPLEMENTATION TMyTable : public TCustomMyTable
{
	typedef TCustomMyTable inherited;
	
__published:
	__property TableName;
	__property OrderFields;
	__property Limit = {default=-1};
	__property Offset = {default=0};
	__property MasterFields;
	__property DetailFields;
	__property MasterSource;
	__property ReadOnly = {default=0};
	__property Connection;
	__property Debug = {default=0};
	__property FetchRows = {default=25};
	__property UniDirectional = {default=0};
	__property CachedUpdates = {default=0};
	__property OnUpdateError;
	__property OnUpdateRecord;
	__property UpdateObject;
	__property RefreshOptions = {default=0};
	__property Active = {default=0};
	__property AutoCalcFields = {default=1};
	__property Filtered = {default=0};
	__property Filter;
	__property FilterOptions = {default=0};
	__property BeforeOpen;
	__property AfterOpen;
	__property BeforeClose;
	__property AfterClose;
	__property BeforeInsert;
	__property AfterInsert;
	__property BeforeEdit;
	__property AfterEdit;
	__property BeforePost;
	__property AfterPost;
	__property BeforeCancel;
	__property AfterCancel;
	__property BeforeDelete;
	__property AfterDelete;
	__property BeforeScroll;
	__property AfterScroll;
	__property OnCalcFields;
	__property OnDeleteError;
	__property OnEditError;
	__property OnFilterRecord;
	__property OnNewRecord;
	__property OnPostError;
	__property AfterRefresh;
	__property BeforeRefresh;
	__property Options;
	__property FilterSQL;
	__property FetchAll = {default=1};
	__property LockMode = {default=0};
	__property KeyFields;
	__property IndexFieldNames;
	__property IndexDefs;
	__property CommandTimeout = {default=0};
	__property BeforeFetch;
	__property AfterFetch;
public:
	/* TCustomMyTable.Create */ inline __fastcall virtual TMyTable(Classes::TComponent* Owner) : TCustomMyTable(Owner) { }
	/* TCustomMyTable.Destroy */ inline __fastcall virtual ~TMyTable(void) { }
	
};


class DELPHICLASS TCustomMyStoredProc;
class PASCALIMPLEMENTATION TCustomMyStoredProc : public TCustomMyDataSet
{
	typedef TCustomMyDataSet inherited;
	
protected:
	virtual void __fastcall PSSetCommandText(const System::UnicodeString CommandText)/* overload */;
	System::UnicodeString FStoredProcName;
	void __fastcall SetStoredProcName(const System::UnicodeString Value);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual bool __fastcall SQLAutoGenerated(void);
	virtual void __fastcall BeforeOpenCursor(bool InfoQuery);
	virtual void __fastcall BeforeExecute(void);
	
public:
	void __fastcall ExecProc(void);
	virtual void __fastcall Prepare(void);
	void __fastcall PrepareSQL(void);
	__property System::UnicodeString StoredProcName = {read=FStoredProcName, write=SetStoredProcName};
public:
	/* TCustomMyDataSet.Create */ inline __fastcall virtual TCustomMyStoredProc(Classes::TComponent* Owner) : TCustomMyDataSet(Owner) { }
	/* TCustomMyDataSet.Destroy */ inline __fastcall virtual ~TCustomMyStoredProc(void) { }
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  PSSetCommandText(const System::WideString CommandText){ Db::TDataSet::PSSetCommandText(CommandText); }
	
};


class DELPHICLASS TMyStoredProc;
class PASCALIMPLEMENTATION TMyStoredProc : public TCustomMyStoredProc
{
	typedef TCustomMyStoredProc inherited;
	
__published:
	__property StoredProcName;
	__property SQLInsert;
	__property SQLDelete;
	__property SQLUpdate;
	__property SQLRefresh;
	__property SQLLock;
	__property Connection;
	__property SQL;
	__property Debug = {default=0};
	__property Params;
	__property FetchRows = {default=25};
	__property ReadOnly = {default=0};
	__property UniDirectional = {default=0};
	__property CachedUpdates = {default=0};
	__property AfterExecute;
	__property BeforeUpdateExecute;
	__property AfterUpdateExecute;
	__property OnUpdateError;
	__property OnUpdateRecord;
	__property Options;
	__property UpdateObject;
	__property RefreshOptions = {default=0};
	__property Active = {default=0};
	__property AutoCalcFields = {default=1};
	__property Filtered = {default=0};
	__property Filter;
	__property FilterOptions = {default=0};
	__property BeforeOpen;
	__property AfterOpen;
	__property BeforeClose;
	__property AfterClose;
	__property BeforeInsert;
	__property AfterInsert;
	__property BeforeEdit;
	__property AfterEdit;
	__property BeforePost;
	__property AfterPost;
	__property BeforeCancel;
	__property AfterCancel;
	__property BeforeDelete;
	__property AfterDelete;
	__property BeforeScroll;
	__property AfterScroll;
	__property OnCalcFields;
	__property OnDeleteError;
	__property OnEditError;
	__property OnFilterRecord;
	__property OnNewRecord;
	__property OnPostError;
	__property AfterRefresh;
	__property BeforeRefresh;
	__property UpdatingTable;
	__property FetchAll = {default=1};
	__property LockMode = {default=0};
	__property KeyFields;
	__property CommandTimeout = {default=0};
	__property BeforeFetch;
	__property AfterFetch;
public:
	/* TCustomMyDataSet.Create */ inline __fastcall virtual TMyStoredProc(Classes::TComponent* Owner) : TCustomMyStoredProc(Owner) { }
	/* TCustomMyDataSet.Destroy */ inline __fastcall virtual ~TMyStoredProc(void) { }
	
};


class DELPHICLASS TMyCommand;
class PASCALIMPLEMENTATION TMyCommand : public Dbaccess::TCustomDASQL
{
	typedef Dbaccess::TCustomDASQL inherited;
	
private:
	TCustomMyConnection* __fastcall GetConnection(void);
	HIDESBASE void __fastcall SetConnection(TCustomMyConnection* Value);
	
protected:
	Myclasses::TMySQLCommand* FICommand;
	int FCommandTimeout;
	virtual void __fastcall CreateICommand(void);
	virtual void __fastcall SetICommand(Craccess::TCRCommand* Value);
	virtual Memds::TDataTypesMapClass __fastcall GetDataTypesMap(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall AssembleSQL(void);
	void __fastcall SetCommandTimeout(const int Value);
	virtual Dbaccess::TCustomDAConnection* __fastcall UsedConnection(void);
	
public:
	__fastcall virtual TMyCommand(Classes::TComponent* Owner);
	void __fastcall BreakExec(void);
	__property AutoCommit = {default=0};
	__property __int64 InsertId = {read=FLastInsertId};
	
__published:
	__property TCustomMyConnection* Connection = {read=GetConnection, write=SetConnection};
	__property int CommandTimeout = {read=FCommandTimeout, write=SetCommandTimeout, default=0};
	__property ParamCheck = {default=1};
	__property SQL;
	__property Params;
	__property Macros;
	__property Debug = {default=0};
	__property AfterExecute;
public:
	/* TCustomDASQL.Destroy */ inline __fastcall virtual ~TMyCommand(void) { }
	
};


class DELPHICLASS TMyTransaction;
class PASCALIMPLEMENTATION TMyTransaction : public Dbaccess::TDATransaction
{
	typedef Dbaccess::TDATransaction inherited;
	
protected:
	virtual System::TClass __fastcall SQLMonitorClass(void);
	virtual Craccess::TCRTransactionClass __fastcall GetITransactionClass(void);
	__property IsolationLevel = {default=0};
public:
	/* TDATransaction.Create */ inline __fastcall virtual TMyTransaction(Classes::TComponent* AOwner) : Dbaccess::TDATransaction(AOwner) { }
	/* TDATransaction.Destroy */ inline __fastcall virtual ~TMyTransaction(void) { }
	
};


class DELPHICLASS TMyMetaData;
class PASCALIMPLEMENTATION TMyMetaData : public Dbaccess::TDAMetaData
{
	typedef Dbaccess::TDAMetaData inherited;
	
private:
	TMyConnection* __fastcall GetConnection(void);
	HIDESBASE void __fastcall SetConnection(TMyConnection* Value);
	
__published:
	__property Active = {default=0};
	__property Filtered = {default=0};
	__property Filter;
	__property FilterOptions = {default=0};
	__property IndexFieldNames;
	__property BeforeOpen;
	__property AfterOpen;
	__property BeforeClose;
	__property AfterClose;
	__property BeforeScroll;
	__property AfterScroll;
	__property OnFilterRecord;
	__property MetaDataKind;
	__property Restrictions;
	__property TMyConnection* Connection = {read=GetConnection, write=SetConnection};
public:
	/* TDAMetaData.Create */ inline __fastcall virtual TMyMetaData(Classes::TComponent* AOwner) : Dbaccess::TDAMetaData(AOwner) { }
	/* TDAMetaData.Destroy */ inline __fastcall virtual ~TMyMetaData(void) { }
	
};


class DELPHICLASS TMyDataSource;
class PASCALIMPLEMENTATION TMyDataSource : public Dbaccess::TCRDataSource
{
	typedef Dbaccess::TCRDataSource inherited;
	
public:
	/* TCRDataSource.Create */ inline __fastcall virtual TMyDataSource(Classes::TComponent* Owner) : Dbaccess::TCRDataSource(Owner) { }
	
public:
	/* TDataSource.Destroy */ inline __fastcall virtual ~TMyDataSource(void) { }
	
};


class DELPHICLASS TMyAccessUtils;
class PASCALIMPLEMENTATION TMyAccessUtils : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void __fastcall SetDesigning(TCustomMyDataSet* Obj, bool Value, bool SetChildren = true);
	__classmethod Myclasses::TMySQLRecordset* __fastcall FIRecordSet(TCustomMyDataSet* Obj);
	__classmethod Myclasses::TMySQLCommand* __fastcall FICommand(Classes::TComponent* Obj);
public:
	/* TObject.Create */ inline __fastcall TMyAccessUtils(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TMyAccessUtils(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define MydacVersion L"5.90.0.57"
extern PACKAGE System::TClass __fastcall (*DefConnectDialogClassProc)(void);
extern PACKAGE System::UnicodeString __fastcall TableNamesFromList(Classes::TStrings* List);
extern PACKAGE void __fastcall TableNamesToList(System::UnicodeString Value, Classes::TStrings* List);
extern PACKAGE void __fastcall GetDatabasesList(const TCustomMyConnection* Connection, Classes::TStrings* List);
extern PACKAGE void __fastcall GetTablesList(const TCustomMyConnection* Connection, Classes::TStrings* List);
extern PACKAGE void __fastcall GetIndexNames(const TCustomMyConnection* Connection, Classes::TStrings* List, System::UnicodeString TableName);
extern PACKAGE void __fastcall GetServerList(Classes::TStrings* List);

}	/* namespace Myaccess */
using namespace Myaccess;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MyaccessHPP
