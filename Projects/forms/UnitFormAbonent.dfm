object FormAbonent: TFormAbonent
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1054#1073#1097#1072#1103' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086#1073' '#1072#1075#1077#1085#1090#1089#1090#1074#1077
  ClientHeight = 96
  ClientWidth = 733
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 12
    Width = 52
    Height = 13
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 340
    Top = 12
    Width = 48
    Height = 13
    Caption = #1058#1077#1083#1077#1092#1086#1085':'
  end
  object Label3: TLabel
    Left = 516
    Top = 12
    Width = 35
    Height = 13
    Caption = #1040#1076#1088#1077#1089':'
  end
  object Label4: TLabel
    Left = 16
    Top = 64
    Width = 48
    Height = 13
    Caption = #1042#1077#1073' '#1089#1072#1081#1090':'
  end
  object Button1: TButton
    Left = 632
    Top = 62
    Width = 93
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHotLight
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Compname_DBEdit: TDBEdit
    Left = 16
    Top = 31
    Width = 313
    Height = 21
    ReadOnly = True
    TabOrder = 1
  end
  object Phone_DBEdit: TDBEdit
    Left = 340
    Top = 31
    Width = 165
    Height = 21
    ReadOnly = True
    TabOrder = 2
  end
  object Address_DBEdit: TDBEdit
    Left = 516
    Top = 31
    Width = 209
    Height = 21
    ReadOnly = True
    TabOrder = 3
  end
  object Sait_DBEdit: TDBEdit
    Left = 70
    Top = 61
    Width = 259
    Height = 21
    ReadOnly = True
    TabOrder = 4
  end
end