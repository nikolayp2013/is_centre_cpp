object FormReestrAbonent: TFormReestrAbonent
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072
  ClientHeight = 520
  ClientWidth = 812
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  DesignSize = (
    812
    520)
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 8
    Top = 456
    Width = 796
    Height = 56
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label1: TLabel
    Left = 32
    Top = 464
    Width = 13
    Height = 13
    Caption = #8470
  end
  object Label2: TLabel
    Left = 123
    Top = 464
    Width = 52
    Height = 13
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077':'
  end
  object Label3: TLabel
    Left = 336
    Top = 464
    Width = 48
    Height = 13
    Caption = #1058#1077#1083#1077#1092#1086#1085':'
  end
  object Label4: TLabel
    Left = 480
    Top = 464
    Width = 35
    Height = 13
    Caption = #1040#1076#1088#1077#1089':'
  end
  object Compid_Edit: TEdit
    Left = 32
    Top = 483
    Width = 73
    Height = 21
    TabOrder = 0
    OnKeyUp = Compid_EditKeyUp
  end
  object Compname_Edit: TEdit
    Left = 123
    Top = 483
    Width = 190
    Height = 21
    TabOrder = 1
    OnEnter = Compname_EditEnter
    OnKeyUp = Compname_EditKeyUp
  end
  object Phone_Edit: TEdit
    Left = 336
    Top = 483
    Width = 121
    Height = 21
    TabOrder = 2
    OnKeyUp = Phone_EditKeyUp
  end
  object Address_Edit: TEdit
    Left = 480
    Top = 483
    Width = 153
    Height = 21
    TabOrder = 3
    OnEnter = Address_EditEnter
    OnKeyUp = Address_EditKeyUp
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 796
    Height = 442
    FixedColor = clInfoBk
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'compid'
        Title.Alignment = taRightJustify
        Title.Caption = #8470
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 29
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'compname'
        Title.Caption = #1053#1072#1079#1074#1072#1085#1080#1077
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 214
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'phone'
        Title.Caption = #1058#1077#1083#1077#1092#1086#1085
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 241
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'address'
        Title.Caption = #1040#1076#1088#1077#1089
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 275
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 684
    Top = 467
    Width = 92
    Height = 33
    Anchors = []
    BevelWidth = 2
    BiDiMode = bdRightToLeft
    BorderWidth = 1
    Caption = #1057#1073#1088#1086#1089
    Color = clCream
    FullRepaint = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBiDiMode = False
    ParentBackground = False
    ParentFont = False
    TabOrder = 5
    OnClick = Panel1Click
    OnMouseDown = Panel1MouseDown
    OnMouseUp = Panel1MouseUp
  end
end
