object FormAgentRole: TFormAgentRole
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1056#1077#1076#1072#1082#1090#1086#1088' '#1088#1086#1083#1077#1081
  ClientHeight = 354
  ClientWidth = 571
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
  object Shape5: TShape
    Left = 8
    Top = 45
    Width = 557
    Height = 273
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 72
    Height = 13
    Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 34
    Top = 39
    Width = 34
    Height = 13
    Caption = ' '#1056#1086#1083#1100' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Button1: TButton
    Left = 392
    Top = 324
    Width = 92
    Height = 25
    Caption = #1047#1072#1087#1080#1089#1072#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 490
    Top = 324
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 1
    OnClick = Button2Click
  end
  object Rmykart_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 58
    Width = 209
    Height = 17
    Caption = ' '#1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1089#1074#1086#1080#1093' '#1082#1072#1088#1090#1086#1095#1077#1082
    TabOrder = 2
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Rkartmygr_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 81
    Width = 241
    Height = 17
    Caption = ' '#1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1082#1072#1088#1090#1086#1095#1077#1082' '#1089#1074#1086#1077#1081' '#1075#1088#1091#1087#1087#1099
    TabOrder = 3
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Rallkart_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 104
    Width = 209
    Height = 17
    Caption = ' '#1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1074#1089#1077#1093' '#1082#1072#1088#1090#1086#1095#1077#1082
    TabOrder = 4
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Sendrekl_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 127
    Width = 209
    Height = 17
    Caption = ' '#1055#1086#1076#1072#1095#1072' '#1088#1077#1082#1083#1072#1084#1072#1094#1080#1081
    TabOrder = 5
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Inmail_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 150
    Width = 209
    Height = 17
    Caption = ' '#1056#1072#1073#1086#1090#1072' '#1089#1086' '#1074#1093#1086#1076#1103#1097#1077#1081' '#1087#1086#1095#1090#1086#1081
    TabOrder = 6
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Outmail_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 173
    Width = 209
    Height = 17
    Caption = ' '#1056#1072#1073#1086#1090#1072' '#1089' '#1080#1089#1093#1086#1076#1103#1097#1077#1081' '#1087#1086#1095#1090#1086#1081
    TabOrder = 7
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Pplist_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 196
    Width = 209
    Height = 17
    Caption = ' '#1055#1077#1095#1072#1090#1100' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090#1086#1074
    TabOrder = 8
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Setmarker_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 219
    Width = 241
    Height = 17
    Caption = ' '#1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1084#1077#1090#1086#1082' '#1076#1083#1103' '#1087#1086#1076#1072#1095#1080' '#1086#1073#1098#1103#1074#1083#1077#1085#1080#1081
    TabOrder = 9
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Genmess_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 242
    Width = 209
    Height = 17
    Caption = ' '#1043#1077#1085#1077#1088#1072#1094#1080#1103' '#1086#1073#1098#1103#1074#1083#1077#1085#1080#1081
    TabOrder = 10
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Workkadr_DBCheckBox: TDBCheckBox
    Left = 24
    Top = 265
    Width = 209
    Height = 17
    Caption = ' '#1056#1072#1073#1086#1090#1072' '#1089' '#1082#1072#1076#1088#1072#1084#1080
    TabOrder = 11
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Viewprop_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 279
    Width = 15
    Height = 17
    TabOrder = 12
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Viewcommprice_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 242
    Width = 255
    Height = 17
    Caption = ' '#1055#1088#1086#1089#1084#1086#1090#1088' '#1086#1073#1097#1077#1075#1086' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090#1072
    TabOrder = 13
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Workmypricein_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 219
    Width = 247
    Height = 17
    Caption = ' '#1056#1072#1073#1086#1090#1072' '#1089' '#1074#1085#1091#1090#1088#1077#1085#1085#1080#1084' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090#1086#1084
    TabOrder = 14
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Viewmypriceout_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 196
    Width = 255
    Height = 17
    Caption = ' '#1055#1088#1086#1089#1084#1086#1090#1088' '#1089#1074#1086#1077#1075#1086' '#1074#1085#1077#1096#1085#1077#1075#1086' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090#1072
    TabOrder = 15
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Arcobject_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 173
    Width = 255
    Height = 17
    Caption = ' '#1044#1086#1089#1090#1091#1087' '#1082' '#1072#1088#1093#1080#1074#1091' '#1086#1073#1098#1077#1082#1090#1086#1074
    TabOrder = 16
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Modprintfr_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 150
    Width = 255
    Height = 17
    Caption = ' '#1052#1086#1076#1080#1092#1080#1082#1072#1094#1080#1103' '#1087#1077#1095#1072#1090#1085#1099#1093' '#1092#1086#1088#1084
    TabOrder = 17
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Export_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 127
    Width = 247
    Height = 17
    Caption = ' '#1042#1086#1079#1084#1086#1078#1085#1086#1089#1090#1100' '#1101#1082#1089#1087#1086#1088#1090#1072' '#1076#1072#1085#1085#1099#1093
    TabOrder = 18
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Setconnect_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 104
    Width = 247
    Height = 17
    Caption = ' '#1059#1089#1090#1072#1085#1086#1074#1082#1072' '#1089#1077#1072#1085#1089#1072' '#1089#1074#1103#1079#1080
    TabOrder = 19
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Klientlist_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 81
    Width = 247
    Height = 17
    Caption = ' '#1056#1072#1073#1086#1090#1072' '#1089#1086' '#1089#1087#1080#1089#1082#1086#1084' '#1082#1083#1080#1077#1085#1090#1086#1074
    TabOrder = 20
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Agentlist_DBCheckBox: TDBCheckBox
    Left = 290
    Top = 58
    Width = 247
    Height = 17
    Caption = ' '#1056#1072#1073#1086#1090#1072' '#1089#1086' '#1089#1087#1080#1089#1082#1086#1084' '#1086#1073#1098#1077#1082#1090#1086#1074
    TabOrder = 21
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Button3: TButton
    Left = 311
    Top = 267
    Width = 250
    Height = 42
    Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1088#1072#1079#1076#1077#1083#1100#1085#1099#1077' '#1085#1072#1089#1090#1088#1086#1081#1082#1080' '#1087#1086' '#1087#1088#1086#1084#1086#1090#1088#1091
    TabOrder = 22
    WordWrap = True
    OnClick = Button3Click
  end
  object Status_ComboBox: TComboBox
    Left = 94
    Top = 13
    Width = 227
    Height = 21
    ItemHeight = 13
    TabOrder = 23
    OnClick = Status_ComboBoxClick
  end
end
