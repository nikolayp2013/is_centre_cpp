object FormThems: TFormThems
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1086#1088' '#1090#1077#1084#1099'...'
  ClientHeight = 325
  ClientWidth = 712
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
  object Shape2: TShape
    Left = 276
    Top = 16
    Width = 428
    Height = 165
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Shape1: TShape
    Left = 8
    Top = 16
    Width = 259
    Height = 301
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label1: TLabel
    Left = 29
    Top = 9
    Width = 110
    Height = 13
    Caption = ' '#1058#1077#1084#1072' '#1086#1092#1086#1088#1084#1083#1077#1085#1080#1103' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Label2: TLabel
    Left = 293
    Top = 9
    Width = 262
    Height = 13
    Caption = ' '#1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1086#1090#1086#1073#1088#1072#1078#1077#1085#1080#1103' - '#1086#1089#1085#1086#1074#1085#1072#1103' '#1087#1072#1085#1077#1083#1100' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Shape3: TShape
    Left = 276
    Top = 193
    Width = 428
    Height = 87
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label3: TLabel
    Left = 293
    Top = 187
    Width = 306
    Height = 13
    Caption = ' '#1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1086#1090#1086#1073#1088#1072#1078#1077#1085#1080#1103' - '#1076#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1072#1103' '#1087#1072#1085#1077#1083#1100' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object ListBox1: TListBox
    Left = 17
    Top = 27
    Width = 241
    Height = 281
    ItemHeight = 13
    TabOrder = 0
  end
  object Button1: TButton
    Left = 548
    Top = 292
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 629
    Top = 292
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 2
    OnClick = Button2Click
  end
  object Pricein_CheckBox: TCheckBox
    Left = 293
    Top = 40
    Width = 97
    Height = 17
    Caption = #1042#1085#1091#1090#1088'. '#1087#1088#1072#1081#1089
    TabOrder = 3
  end
  object Addk_CheckBox: TCheckBox
    Left = 293
    Top = 82
    Width = 97
    Height = 17
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1082'.'
    TabOrder = 4
  end
  object Openk_CheckBox: TCheckBox
    Left = 293
    Top = 105
    Width = 97
    Height = 17
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1082'.'
    TabOrder = 5
  end
  object Deletek_CheckBox: TCheckBox
    Left = 293
    Top = 128
    Width = 97
    Height = 17
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1082'.'
    TabOrder = 6
  end
  object Updatek_CheckBox: TCheckBox
    Left = 293
    Top = 151
    Width = 97
    Height = 17
    Caption = #1054#1073#1085#1086#1074#1080#1090#1100' '#1082'.'
    TabOrder = 7
  end
  object Info_CheckBox: TCheckBox
    Left = 562
    Top = 82
    Width = 97
    Height = 17
    Caption = #1048#1085#1092'. '#1086#1082#1085#1072
    TabOrder = 8
  end
  object Clients_CheckBox: TCheckBox
    Left = 562
    Top = 105
    Width = 97
    Height = 17
    Caption = #1050#1083#1080#1077#1085#1090#1099
    TabOrder = 9
  end
  object Userch_CheckBox: TCheckBox
    Left = 562
    Top = 128
    Width = 142
    Height = 17
    Caption = #1057#1084#1077#1085#1072' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    TabOrder = 10
  end
  object Help_CheckBox: TCheckBox
    Left = 562
    Top = 151
    Width = 97
    Height = 17
    Caption = #1055#1086#1084#1086#1097#1100
    TabOrder = 11
  end
  object Agentview_CheckBox: TCheckBox
    Left = 420
    Top = 82
    Width = 97
    Height = 17
    Caption = #1040#1075#1077#1085#1090#1089#1082#1080#1081' '#1074#1080#1076
    TabOrder = 12
  end
  object Clientview_CheckBox: TCheckBox
    Left = 420
    Top = 105
    Width = 97
    Height = 17
    Caption = #1050#1083#1080#1077#1085#1090#1089#1082#1080#1081' '#1074#1080#1076
    TabOrder = 13
  end
  object DSPview_CheckBox: TCheckBox
    Left = 420
    Top = 128
    Width = 97
    Height = 17
    Caption = #1044#1057#1055' '#1074#1080#1076
    TabOrder = 14
  end
  object Panel_CheckBox: TCheckBox
    Left = 293
    Top = 205
    Width = 132
    Height = 17
    Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1087#1072#1085#1077#1083#1100
    TabOrder = 15
  end
  object Sprospred_CheckBox: TCheckBox
    Left = 317
    Top = 228
    Width = 140
    Height = 17
    Caption = #1055#1088#1077#1076#1083#1086#1078#1077#1085#1080#1077' / '#1057#1087#1088#1086#1089
    TabOrder = 16
  end
  object Print_CheckBox: TCheckBox
    Left = 317
    Top = 251
    Width = 97
    Height = 17
    Caption = #1055#1077#1095#1072#1090#1100
    TabOrder = 17
  end
  object Typedog_CheckBox: TCheckBox
    Left = 533
    Top = 228
    Width = 126
    Height = 17
    Caption = #1042#1080#1076#1099' '#1076#1086#1075#1086#1074#1086#1088#1086#1074
    TabOrder = 18
  end
  object Rekl_CheckBox: TCheckBox
    Left = 533
    Top = 251
    Width = 97
    Height = 17
    Caption = #1056#1077#1082#1083#1072#1084#1072#1094#1080#1103
    TabOrder = 19
  end
end
