// CodeGear C++Builder
// Copyright (c) 1995, 2008 by CodeGear
// All rights reserved

// (DO NOT EDIT: machine generated header) 'My_dbctrls.pas' rev: 20.00

#ifndef My_dbctrlsHPP
#define My_dbctrlsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Mask.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace My_dbctrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFieldDataLink;
class PASCALIMPLEMENTATION TFieldDataLink : public Db::TDataLink
{
	typedef Db::TDataLink inherited;
	
private:
	Db::TField* FField;
	System::WideString FFieldName;
	Classes::TComponent* FControl;
	bool FEditing;
	bool FModified;
	Classes::TNotifyEvent FOnDataChange;
	Classes::TNotifyEvent FOnEditingChange;
	Classes::TNotifyEvent FOnUpdateData;
	Classes::TNotifyEvent FOnActiveChange;
	bool __fastcall GetCanModify(void);
	HIDESBASE void __fastcall SetEditing(bool Value);
	void __fastcall SetField(Db::TField* Value);
	void __fastcall SetFieldName(const System::WideString Value);
	void __fastcall UpdateField(void);
	void __fastcall UpdateRightToLeft(void);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall FocusControl(Db::TFieldRef Field);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Db::TField* Field);
	virtual void __fastcall UpdateData(void);
	
public:
	__fastcall TFieldDataLink(void);
	HIDESBASE bool __fastcall Edit(void);
	void __fastcall Modified(void);
	void __fastcall Reset(void);
	__property bool CanModify = {read=GetCanModify, nodefault};
	__property Classes::TComponent* Control = {read=FControl, write=FControl};
	__property bool Editing = {read=FEditing, nodefault};
	__property Db::TField* Field = {read=FField};
	__property System::WideString FieldName = {read=FFieldName, write=SetFieldName};
	__property Classes::TNotifyEvent OnDataChange = {read=FOnDataChange, write=FOnDataChange};
	__property Classes::TNotifyEvent OnEditingChange = {read=FOnEditingChange, write=FOnEditingChange};
	__property Classes::TNotifyEvent OnUpdateData = {read=FOnUpdateData, write=FOnUpdateData};
	__property Classes::TNotifyEvent OnActiveChange = {read=FOnActiveChange, write=FOnActiveChange};
public:
	/* TDataLink.Destroy */ inline __fastcall virtual ~TFieldDataLink(void) { }
	
};


class DELPHICLASS TPaintControl;
class PASCALIMPLEMENTATION TPaintControl : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Controls::TWinControl* FOwner;
	System::UnicodeString FClassName;
	HWND FHandle;
	void *FObjectInstance;
	void *FDefWindowProc;
	bool FCtl3dButton;
	HWND __fastcall GetHandle(void);
	void __fastcall SetCtl3DButton(bool Value);
	void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall TPaintControl(Controls::TWinControl* AOwner, const System::UnicodeString ClassName);
	__fastcall virtual ~TPaintControl(void);
	void __fastcall DestroyHandle(void);
	__property bool Ctl3DButton = {read=FCtl3dButton, write=SetCtl3DButton, nodefault};
	__property HWND Handle = {read=GetHandle, nodefault};
};


class DELPHICLASS TMyDBEdit;
class PASCALIMPLEMENTATION TMyDBEdit : public Mask::TCustomMaskEdit
{
	typedef Mask::TCustomMaskEdit inherited;
	
private:
	TFieldDataLink* FDataLink;
	Controls::TControlCanvas* FCanvas;
	Classes::TAlignment FAlignment;
	bool FFocused;
	void __fastcall ActiveChange(System::TObject* Sender);
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall EditingChange(System::TObject* Sender);
	System::WideString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	Types::TPoint __fastcall GetTextMargins();
	void __fastcall ResetMaxLength(void);
	void __fastcall SetDataField(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetFocused(bool Value);
	HIDESBASE void __fastcall SetReadOnly(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall WMCut(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPaste(Messages::TMessage &Message);
	MESSAGE void __fastcall WMUndo(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall Change(void);
	virtual bool __fastcall EditCanModify(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Reset(void);
	
public:
	__fastcall virtual TMyDBEdit(Classes::TComponent* AOwner);
	__fastcall virtual ~TMyDBEdit(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property Db::TField* Field = {read=GetField};
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoSelect = {default=1};
	__property AutoSize = {default=1};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BiDiMode;
	__property BorderStyle = {default=1};
	__property CharCase = {default=0};
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property System::WideString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ImeMode = {default=3};
	__property ImeName;
	__property MaxLength = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PasswordChar = {default=0};
	__property PopupMenu;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnChange;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TMyDBEdit(HWND ParentWindow) : Mask::TCustomMaskEdit(ParentWindow) { }
	
};


class DELPHICLASS TDBText;
class PASCALIMPLEMENTATION TDBText : public Stdctrls::TCustomLabel
{
	typedef Stdctrls::TCustomLabel inherited;
	
private:
	TFieldDataLink* FDataLink;
	void __fastcall DataChange(System::TObject* Sender);
	System::WideString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	System::UnicodeString __fastcall GetFieldText();
	void __fastcall SetDataField(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	
protected:
	virtual System::UnicodeString __fastcall GetLabelText();
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetAutoSize(bool Value);
	
public:
	__fastcall virtual TDBText(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBText(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property Db::TField* Field = {read=GetField};
	
__published:
	__property Align = {default=0};
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property AutoSize = {default=0};
	__property BiDiMode;
	__property Color = {default=-16777211};
	__property Constraints;
	__property System::WideString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Transparent;
	__property ShowHint;
	__property Visible = {default=1};
	__property WordWrap = {default=0};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
};


class DELPHICLASS TMyDBCheckBox;
class PASCALIMPLEMENTATION TMyDBCheckBox : public Stdctrls::TCustomCheckBox
{
	typedef Stdctrls::TCustomCheckBox inherited;
	
private:
	TFieldDataLink* FDataLink;
	System::UnicodeString FValueCheck;
	System::UnicodeString FValueUncheck;
	TPaintControl* FPaintControl;
	void __fastcall DataChange(System::TObject* Sender);
	System::WideString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	Stdctrls::TCheckBoxState __fastcall GetFieldState(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetValueCheck(const System::UnicodeString Value);
	void __fastcall SetValueUncheck(const System::UnicodeString Value);
	void __fastcall UpdateData(System::TObject* Sender);
	bool __fastcall ValueMatch(const System::UnicodeString ValueList, const System::UnicodeString Value);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall Toggle(void);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall virtual TMyDBCheckBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TMyDBCheckBox(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property Checked = {default=0};
	__property Db::TField* Field = {read=GetField};
	__property State = {default=0};
	
__published:
	__property Action;
	__property Align = {default=0};
	__property Alignment = {default=1};
	__property AllowGrayed = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Caption;
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property System::WideString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property System::UnicodeString ValueChecked = {read=FValueCheck, write=SetValueCheck};
	__property System::UnicodeString ValueUnchecked = {read=FValueUncheck, write=SetValueUncheck};
	__property Visible = {default=1};
	__property WordWrap = {default=0};
	__property OnClick;
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TMyDBCheckBox(HWND ParentWindow) : Stdctrls::TCustomCheckBox(ParentWindow) { }
	
};


class DELPHICLASS TMyDBComboBox;
class PASCALIMPLEMENTATION TMyDBComboBox : public Stdctrls::TCustomComboBox
{
	typedef Stdctrls::TCustomComboBox inherited;
	
private:
	TFieldDataLink* FDataLink;
	TPaintControl* FPaintControl;
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall EditingChange(System::TObject* Sender);
	System::UnicodeString __fastcall GetComboText();
	System::WideString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetComboText(const System::UnicodeString Value);
	void __fastcall SetDataField(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetEditReadOnly(void);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	
protected:
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall ComboWndProc(Messages::TMessage &Message, HWND ComboWnd, void * ComboProc);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DropDown(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetItems(const Classes::TStrings* Value);
	virtual void __fastcall SetStyle(Stdctrls::TComboBoxStyle Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall virtual TMyDBComboBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TMyDBComboBox(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property Db::TField* Field = {read=GetField};
	__property Text;
	
__published:
	__property Style = {default=0};
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoComplete = {default=1};
	__property AutoDropDown = {default=0};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BiDiMode;
	__property CharCase = {default=0};
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property System::WideString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property DropDownCount = {default=8};
	__property Enabled = {default=1};
	__property Font;
	__property ImeMode = {default=3};
	__property ImeName;
	__property ItemHeight;
	__property Items = {write=SetItems};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint;
	__property Sorted = {default=0};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnChange;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawItem;
	__property OnDropDown;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMeasureItem;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TMyDBComboBox(HWND ParentWindow) : Stdctrls::TCustomComboBox(ParentWindow) { }
	
};


class DELPHICLASS TDBListBox;
class PASCALIMPLEMENTATION TDBListBox : public Stdctrls::TCustomListBox
{
	typedef Stdctrls::TCustomListBox inherited;
	
private:
	TFieldDataLink* FDataLink;
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall UpdateData(System::TObject* Sender);
	System::WideString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetReadOnly(bool Value);
	HIDESBASE void __fastcall SetItems(Classes::TStrings* Value);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TDBListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBListBox(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property Db::TField* Field = {read=GetField};
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoComplete = {default=1};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BiDiMode;
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D = {default=1};
	__property System::WideString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ImeMode = {default=3};
	__property ImeName;
	__property IntegralHeight = {default=0};
	__property ItemHeight;
	__property Items = {write=SetItems};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint;
	__property Style = {default=0};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawItem;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMeasureItem;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TDBListBox(HWND ParentWindow) : Stdctrls::TCustomListBox(ParentWindow) { }
	
};


class DELPHICLASS TDBRadioGroup;
class PASCALIMPLEMENTATION TDBRadioGroup : public Extctrls::TCustomRadioGroup
{
	typedef Extctrls::TCustomRadioGroup inherited;
	
private:
	TFieldDataLink* FDataLink;
	System::UnicodeString FValue;
	Classes::TStrings* FValues;
	bool FInSetValue;
	Classes::TNotifyEvent FOnChange;
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall UpdateData(System::TObject* Sender);
	System::WideString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	System::UnicodeString __fastcall GetButtonValue(int Index);
	void __fastcall SetDataField(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetValue(const System::UnicodeString Value);
	HIDESBASE void __fastcall SetItems(Classes::TStrings* Value);
	void __fastcall SetValues(Classes::TStrings* Value);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual bool __fastcall CanModify(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property TFieldDataLink* DataLink = {read=FDataLink};
	
public:
	__fastcall virtual TDBRadioGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBRadioGroup(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property Db::TField* Field = {read=GetField};
	__property ItemIndex = {default=-1};
	__property System::UnicodeString Value = {read=FValue, write=SetValue};
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Caption;
	__property Color = {default=-16777211};
	__property Columns = {default=1};
	__property Constraints;
	__property Ctl3D;
	__property System::WideString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Items = {write=SetItems};
	__property ParentBackground;
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property Classes::TStrings* Values = {read=FValues, write=SetValues};
	__property Visible = {default=1};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnClick;
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TDBRadioGroup(HWND ParentWindow) : Extctrls::TCustomRadioGroup(ParentWindow) { }
	
};


class DELPHICLASS TMyDBMemo;
class PASCALIMPLEMENTATION TMyDBMemo : public Stdctrls::TCustomMemo
{
	typedef Stdctrls::TCustomMemo inherited;
	
private:
	TFieldDataLink* FDataLink;
	bool FAutoDisplay;
	bool FFocused;
	bool FMemoLoaded;
	TPaintControl* FPaintControl;
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall EditingChange(System::TObject* Sender);
	System::WideString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	HIDESBASE void __fastcall SetReadOnly(bool Value);
	void __fastcall SetAutoDisplay(bool Value);
	void __fastcall SetFocused(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	MESSAGE void __fastcall WMCut(Messages::TMessage &Message);
	MESSAGE void __fastcall WMPaste(Messages::TMessage &Message);
	MESSAGE void __fastcall WMUndo(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall virtual TMyDBMemo(Classes::TComponent* AOwner);
	__fastcall virtual ~TMyDBMemo(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	virtual void __fastcall LoadMemo(void);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property Db::TField* Field = {read=GetField};
	
__published:
	__property Align = {default=0};
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property bool AutoDisplay = {read=FAutoDisplay, write=SetAutoDisplay, default=1};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BiDiMode;
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property System::WideString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName;
	__property MaxLength = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ScrollBars = {default=0};
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property WantReturns = {default=1};
	__property WantTabs = {default=0};
	__property WordWrap = {default=1};
	__property OnChange;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TMyDBMemo(HWND ParentWindow) : Stdctrls::TCustomMemo(ParentWindow) { }
	
};


class DELPHICLASS TMyDBImage;
class PASCALIMPLEMENTATION TMyDBImage : public Controls::TCustomControl
{
	typedef Controls::TCustomControl inherited;
	
private:
	TFieldDataLink* FDataLink;
	Graphics::TPicture* FPicture;
	Forms::TFormBorderStyle FBorderStyle;
	bool FAutoDisplay;
	bool FStretch;
	bool FCenter;
	bool FPictureLoaded;
	bool FProportional;
	bool FQuickDraw;
	void __fastcall DataChange(System::TObject* Sender);
	System::WideString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall PictureChanged(System::TObject* Sender);
	void __fastcall SetAutoDisplay(bool Value);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetCenter(bool Value);
	void __fastcall SetDataField(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetPicture(Graphics::TPicture* Value);
	void __fastcall SetProportional(bool Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetStretch(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMCut(Messages::TMessage &Message);
	MESSAGE void __fastcall WMCopy(Messages::TMessage &Message);
	MESSAGE void __fastcall WMPaste(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	Types::TRect __fastcall DestRect(Graphics::TPicture* APicture);
	DYNAMIC HPALETTE __fastcall GetPalette(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TMyDBImage(Classes::TComponent* AOwner);
	__fastcall virtual ~TMyDBImage(void);
	void __fastcall CopyToClipboard(void);
	void __fastcall CutToClipboard(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	void __fastcall LoadPicture(void);
	void __fastcall PasteFromClipboard(void);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=GetField};
	__property Graphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property bool AutoDisplay = {read=FAutoDisplay, write=SetAutoDisplay, default=1};
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property bool Center = {read=FCenter, write=SetCenter, default=1};
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property System::WideString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property bool Proportional = {read=FProportional, write=SetProportional, default=0};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property bool QuickDraw = {read=FQuickDraw, write=FQuickDraw, default=1};
	__property ShowHint;
	__property bool Stretch = {read=FStretch, write=SetStretch, default=0};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TMyDBImage(HWND ParentWindow) : Controls::TCustomControl(ParentWindow) { }
	
};


#pragma option push -b-
enum TNavGlyph { ngEnabled, ngDisabled };
#pragma option pop

#pragma option push -b-
enum TNavigateBtn { nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete, nbEdit, nbPost, nbCancel, nbRefresh };
#pragma option pop

typedef Set<TNavigateBtn, nbFirst, nbRefresh>  TNavButtonSet;

#pragma option push -b-
enum My_dbctrls__11 { nsAllowTimer, nsFocusRect };
#pragma option pop

typedef Set<My_dbctrls__11, nsAllowTimer, nsFocusRect>  TNavButtonStyle;

typedef void __fastcall (__closure *ENavClick)(System::TObject* Sender, TNavigateBtn Button);

class DELPHICLASS TMyDBNavigator;
class DELPHICLASS TNavDataLink;
class DELPHICLASS TNavButton;
class PASCALIMPLEMENTATION TMyDBNavigator : public Extctrls::TCustomPanel
{
	typedef Extctrls::TCustomPanel inherited;
	
private:
	TNavDataLink* FDataLink;
	TNavButtonSet FVisibleButtons;
	Classes::TStrings* FHints;
	Classes::TStrings* FDefHints;
	int ButtonWidth;
	Types::TPoint MinBtnSize;
	ENavClick FOnNavClick;
	ENavClick FBeforeAction;
	TNavigateBtn FocusedButton;
	bool FConfirmDelete;
	bool FFlat;
	void __fastcall BtnMouseDown(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall ClickHandler(System::TObject* Sender);
	Db::TDataSource* __fastcall GetDataSource(void);
	Classes::TStrings* __fastcall GetHints(void);
	void __fastcall HintsChanged(System::TObject* Sender);
	void __fastcall InitButtons(void);
	void __fastcall InitHints(void);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetFlat(bool Value);
	void __fastcall SetHints(Classes::TStrings* Value);
	void __fastcall SetSize(int &W, int &H);
	HIDESBASE void __fastcall SetVisible(TNavButtonSet Value);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Messages::TWMWindowPosMsg &Message);
	
protected:
	StaticArray<TNavButton*, 10> Buttons;
	void __fastcall DataChanged(void);
	void __fastcall EditingChanged(void);
	void __fastcall ActiveChanged(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall CalcMinSize(int &W, int &H);
	
public:
	__fastcall virtual TMyDBNavigator(Classes::TComponent* AOwner);
	__fastcall virtual ~TMyDBNavigator(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall BtnClick(TNavigateBtn Index);
	
__published:
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property TNavButtonSet VisibleButtons = {read=FVisibleButtons, write=SetVisible, default=1023};
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property bool Flat = {read=FFlat, write=SetFlat, default=0};
	__property Ctl3D;
	__property Classes::TStrings* Hints = {read=GetHints, write=SetHints};
	__property ParentCtl3D = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property bool ConfirmDelete = {read=FConfirmDelete, write=FConfirmDelete, default=1};
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property Visible = {default=1};
	__property ENavClick BeforeAction = {read=FBeforeAction, write=FBeforeAction};
	__property ENavClick OnClick = {read=FOnNavClick, write=FOnNavClick};
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TMyDBNavigator(HWND ParentWindow) : Extctrls::TCustomPanel(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TNavButton : public Buttons::TSpeedButton
{
	typedef Buttons::TSpeedButton inherited;
	
private:
	TNavigateBtn FIndex;
	TNavButtonStyle FNavStyle;
	Extctrls::TTimer* FRepeatTimer;
	void __fastcall TimerExpired(System::TObject* Sender);
	
protected:
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	
public:
	__fastcall virtual ~TNavButton(void);
	__property TNavButtonStyle NavStyle = {read=FNavStyle, write=FNavStyle, nodefault};
	__property TNavigateBtn Index = {read=FIndex, write=FIndex, nodefault};
public:
	/* TSpeedButton.Create */ inline __fastcall virtual TNavButton(Classes::TComponent* AOwner) : Buttons::TSpeedButton(AOwner) { }
	
};


class PASCALIMPLEMENTATION TNavDataLink : public Db::TDataLink
{
	typedef Db::TDataLink inherited;
	
private:
	TMyDBNavigator* FNavigator;
	
protected:
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall ActiveChanged(void);
	
public:
	__fastcall TNavDataLink(TMyDBNavigator* ANav);
	__fastcall virtual ~TNavDataLink(void);
};


class DELPHICLASS TDataSourceLink;
class DELPHICLASS TDBLookupControl;
class PASCALIMPLEMENTATION TDataSourceLink : public Db::TDataLink
{
	typedef Db::TDataLink inherited;
	
private:
	TDBLookupControl* FDBLookupControl;
	
protected:
	virtual void __fastcall FocusControl(Db::TFieldRef Field);
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Db::TField* Field);
	
public:
	__fastcall TDataSourceLink(void);
public:
	/* TDataLink.Destroy */ inline __fastcall virtual ~TDataSourceLink(void) { }
	
};


class DELPHICLASS TListSourceLink;
class PASCALIMPLEMENTATION TListSourceLink : public Db::TDataLink
{
	typedef Db::TDataLink inherited;
	
private:
	TDBLookupControl* FDBLookupControl;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall LayoutChanged(void);
	
public:
	__fastcall TListSourceLink(void);
public:
	/* TDataLink.Destroy */ inline __fastcall virtual ~TListSourceLink(void) { }
	
};


class PASCALIMPLEMENTATION TDBLookupControl : public Controls::TCustomControl
{
	typedef Controls::TCustomControl inherited;
	
private:
	Db::TDataSource* FLookupSource;
	TDataSourceLink* FDataLink;
	TListSourceLink* FListLink;
	System::WideString FDataFieldName;
	System::UnicodeString FKeyFieldName;
	System::UnicodeString FListFieldName;
	int FListFieldIndex;
	Db::TField* FDataField;
	Db::TField* FMasterField;
	Db::TField* FKeyField;
	Db::TField* FListField;
	Classes::TList* FListFields;
	System::Variant FKeyValue;
	System::UnicodeString FSearchText;
	bool FLookupMode;
	bool FListActive;
	bool FHasFocus;
	int FListDataChanging;
	Classes::TShortCut FNullValueKey;
	void __fastcall CheckNotCircular(void);
	void __fastcall CheckNotLookup(void);
	void __fastcall DataLinkRecordChanged(Db::TField* Field);
	Db::TDataSource* __fastcall GetDataSource(void);
	System::UnicodeString __fastcall GetKeyFieldName();
	Db::TDataSource* __fastcall GetListSource(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataFieldName(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetKeyFieldName(const System::UnicodeString Value);
	void __fastcall SetKeyValue(const System::Variant &Value);
	void __fastcall SetListFieldName(const System::UnicodeString Value);
	void __fastcall SetListSource(Db::TDataSource* Value);
	void __fastcall SetLookupMode(bool Value);
	void __fastcall SetReadOnly(bool Value);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	
protected:
	virtual bool __fastcall CanModify(void);
	virtual int __fastcall GetBorderSize(void);
	virtual int __fastcall GetTextHeight(void);
	virtual void __fastcall KeyValueChanged(void);
	virtual void __fastcall ListLinkDataChanged(void);
	virtual bool __fastcall LocateKey(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall ProcessSearchKey(System::WideChar Key);
	virtual void __fastcall SelectKeyValue(const System::Variant &Value);
	virtual void __fastcall UpdateDataFields(void);
	virtual void __fastcall UpdateListFields(void);
	__property System::WideString DataField = {read=FDataFieldName, write=SetDataFieldName};
	__property TDataSourceLink* DataLink = {read=FDataLink};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property bool HasFocus = {read=FHasFocus, nodefault};
	__property System::UnicodeString KeyField = {read=GetKeyFieldName, write=SetKeyFieldName};
	__property System::Variant KeyValue = {read=FKeyValue, write=SetKeyValue};
	__property bool ListActive = {read=FListActive, nodefault};
	__property System::UnicodeString ListField = {read=FListFieldName, write=SetListFieldName};
	__property int ListFieldIndex = {read=FListFieldIndex, write=FListFieldIndex, default=0};
	__property Classes::TList* ListFields = {read=FListFields};
	__property TListSourceLink* ListLink = {read=FListLink};
	__property Db::TDataSource* ListSource = {read=GetListSource, write=SetListSource};
	__property Classes::TShortCut NullValueKey = {read=FNullValueKey, write=FNullValueKey, default=0};
	__property ParentColor = {default=0};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property System::UnicodeString SearchText = {read=FSearchText, write=FSearchText};
	__property TabStop = {default=1};
	
public:
	__fastcall virtual TDBLookupControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBLookupControl(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=FDataField};
public:
	/* TWinControl.CreateParented */ inline __fastcall TDBLookupControl(HWND ParentWindow) : Controls::TCustomControl(ParentWindow) { }
	
};


class DELPHICLASS TMyDBLookupListBox;
class PASCALIMPLEMENTATION TMyDBLookupListBox : public TDBLookupControl
{
	typedef TDBLookupControl inherited;
	
private:
	int FRecordIndex;
	int FRecordCount;
	int FRowCount;
	Forms::TFormBorderStyle FBorderStyle;
	bool FPopup;
	bool FKeySelected;
	bool FTracking;
	bool FTimerActive;
	bool FLockPosition;
	int FMousePos;
	System::UnicodeString FSelectedItem;
	int __fastcall GetKeyIndex(void);
	void __fastcall SelectCurrent(void);
	void __fastcall SelectItemAt(int X, int Y);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetRowCount(int Value);
	void __fastcall StopTimer(void);
	void __fastcall StopTracking(void);
	void __fastcall TimerScroll(void);
	void __fastcall UpdateScrollBar(void);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Messages::TMessage &Message);
	MESSAGE void __fastcall WMTimer(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Messages::TWMScroll &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall KeyValueChanged(void);
	virtual void __fastcall ListLinkDataChanged(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall UpdateListFields(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall virtual TMyDBLookupListBox(Classes::TComponent* AOwner);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property KeyValue;
	__property System::UnicodeString SelectedItem = {read=FSelectedItem};
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BiDiMode;
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property DataField;
	__property DataSource;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ImeMode = {default=3};
	__property ImeName;
	__property KeyField;
	__property ListField;
	__property ListFieldIndex = {default=0};
	__property ListSource;
	__property NullValueKey = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ReadOnly = {default=0};
	__property int RowCount = {read=FRowCount, write=SetRowCount, stored=false, nodefault};
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TDBLookupControl.Destroy */ inline __fastcall virtual ~TMyDBLookupListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TMyDBLookupListBox(HWND ParentWindow) : TDBLookupControl(ParentWindow) { }
	
};


class DELPHICLASS TPopupDataList;
class PASCALIMPLEMENTATION TPopupDataList : public TMyDBLookupListBox
{
	typedef TMyDBLookupListBox inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall WMMouseActivate(Messages::TWMMouseActivate &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	
public:
	__fastcall virtual TPopupDataList(Classes::TComponent* AOwner);
public:
	/* TDBLookupControl.Destroy */ inline __fastcall virtual ~TPopupDataList(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TPopupDataList(HWND ParentWindow) : TMyDBLookupListBox(ParentWindow) { }
	
};


#pragma option push -b-
enum TDropDownAlign { daLeft, daRight, daCenter };
#pragma option pop

class DELPHICLASS TMyDBLookupComboBox;
class PASCALIMPLEMENTATION TMyDBLookupComboBox : public TDBLookupControl
{
	typedef TDBLookupControl inherited;
	
private:
	TPopupDataList* FDataList;
	int FButtonWidth;
	System::UnicodeString FText;
	int FDropDownRows;
	int FDropDownWidth;
	TDropDownAlign FDropDownAlign;
	bool FListVisible;
	bool FPressed;
	bool FTracking;
	Classes::TAlignment FAlignment;
	bool FLookupMode;
	bool FMouseInControl;
	Classes::TNotifyEvent FOnDropDown;
	Classes::TNotifyEvent FOnCloseUp;
	void __fastcall ListMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall StopTracking(void);
	void __fastcall TrackButton(int X, int Y);
	HIDESBASE MESSAGE void __fastcall CMDialogKey(Messages::TWMKey &Message);
	MESSAGE void __fastcall CMCancelMode(Controls::TCMCancelMode &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall KeyValueChanged(void);
	virtual void __fastcall ListLinkDataChanged(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall UpdateListFields(void);
	
public:
	__fastcall virtual TMyDBLookupComboBox(Classes::TComponent* AOwner);
	virtual void __fastcall CloseUp(bool Accept);
	virtual void __fastcall DropDown(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property KeyValue;
	__property bool ListVisible = {read=FListVisible, nodefault};
	__property System::UnicodeString Text = {read=FText};
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BiDiMode;
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property DataField;
	__property DataSource;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property TDropDownAlign DropDownAlign = {read=FDropDownAlign, write=FDropDownAlign, default=0};
	__property int DropDownRows = {read=FDropDownRows, write=FDropDownRows, default=7};
	__property int DropDownWidth = {read=FDropDownWidth, write=FDropDownWidth, default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ImeMode = {default=3};
	__property ImeName;
	__property KeyField;
	__property ListField;
	__property ListFieldIndex = {default=0};
	__property ListSource;
	__property NullValueKey = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ReadOnly = {default=0};
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property Classes::TNotifyEvent OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	__property TPopupDataList* DataList = {read=FDataList, write=FDataList};
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property Classes::TNotifyEvent OnDropDown = {read=FOnDropDown, write=FOnDropDown};
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TDBLookupControl.Destroy */ inline __fastcall virtual ~TMyDBLookupComboBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TMyDBLookupComboBox(HWND ParentWindow) : TDBLookupControl(ParentWindow) { }
	
};


class DELPHICLASS TDBRichEdit;
class PASCALIMPLEMENTATION TDBRichEdit : public Comctrls::TCustomRichEdit
{
	typedef Comctrls::TCustomRichEdit inherited;
	
private:
	TFieldDataLink* FDataLink;
	bool FAutoDisplay;
	bool FFocused;
	bool FMemoLoaded;
	System::UnicodeString FDataSave;
	void __fastcall BeginEditing(void);
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall EditingChange(System::TObject* Sender);
	System::WideString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const System::WideString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	HIDESBASE void __fastcall SetReadOnly(bool Value);
	void __fastcall SetAutoDisplay(bool Value);
	void __fastcall SetFocused(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	MESSAGE void __fastcall WMCut(Messages::TMessage &Message);
	MESSAGE void __fastcall WMPaste(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	MESSAGE void __fastcall CMGetDataLink(Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TDBRichEdit(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBRichEdit(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	virtual void __fastcall LoadMemo(void);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	__property Db::TField* Field = {read=GetField};
	
__published:
	__property Align = {default=0};
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property bool AutoDisplay = {read=FAutoDisplay, write=SetAutoDisplay, default=1};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BiDiMode;
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property System::WideString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property HideSelection = {default=1};
	__property HideScrollBars = {default=1};
	__property ImeMode = {default=3};
	__property ImeName;
	__property MaxLength = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PlainText = {default=0};
	__property PopupMenu;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ScrollBars = {default=0};
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property WantReturns = {default=1};
	__property WantTabs = {default=0};
	__property WordWrap = {default=1};
	__property OnChange;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseActivate;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResizeRequest;
	__property OnSelectionChange;
	__property OnProtectChange;
	__property OnSaveClipboard;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TDBRichEdit(HWND ParentWindow) : Comctrls::TCustomRichEdit(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word InitRepeatPause = 0x190;
static const ShortInt RepeatPause = 0x64;
static const ShortInt SpaceSize = 0x5;
extern PACKAGE bool __fastcall OkToChangeFieldAlignment(Db::TField* AField, Classes::TAlignment Alignment);
extern PACKAGE bool __fastcall DBUseRightToLeftAlignment(Controls::TControl* AControl, Db::TField* AField);

}	/* namespace My_dbctrls */
using namespace My_dbctrls;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// My_dbctrlsHPP
