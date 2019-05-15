object FormAgentRoleAdd: TFormAgentRoleAdd
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1044#1086#1089#1090#1091#1087' '#1082' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090#1072#1084
  ClientHeight = 200
  ClientWidth = 310
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
    Top = 14
    Width = 51
    Height = 13
    Caption = #1056#1091#1073#1088#1080#1082#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Shape5: TShape
    Left = 23
    Top = 42
    Width = 265
    Height = 111
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label2: TLabel
    Left = 36
    Top = 35
    Width = 43
    Height = 13
    Caption = ' '#1044#1086#1089#1090#1091#1087' '
    Transparent = False
  end
  object ComboBox1: TComboBox
    Left = 73
    Top = 11
    Width = 229
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = #1050#1074#1072#1088#1090#1080#1088#1099
  end
  object CheckBox1: TCheckBox
    Left = 36
    Top = 54
    Width = 173
    Height = 17
    Caption = ' '#1042#1085#1077#1096#1085#1080#1081' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090
    TabOrder = 1
  end
  object CheckBox2: TCheckBox
    Left = 36
    Top = 77
    Width = 185
    Height = 17
    Caption = ' '#1042#1085#1091#1090#1088#1077#1085#1085#1080#1081' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090
    TabOrder = 2
  end
  object CheckBox3: TCheckBox
    Left = 36
    Top = 100
    Width = 185
    Height = 17
    Caption = ' '#1054#1073#1098#1077#1076#1080#1085#1077#1085#1085#1099#1081' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090
    TabOrder = 3
  end
  object CheckBox4: TCheckBox
    Left = 36
    Top = 123
    Width = 185
    Height = 17
    Caption = ' '#1040#1088#1093#1080#1074#1085#1099#1081' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090
    TabOrder = 4
  end
  object Button1: TButton
    Left = 120
    Top = 167
    Width = 101
    Height = 25
    Caption = #1047#1072#1087#1080#1089#1072#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 227
    Top = 167
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 6
    OnClick = Button2Click
  end
end
