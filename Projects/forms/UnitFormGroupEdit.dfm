object FormGroupEdit: TFormGroupEdit
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1043#1088#1091#1087#1087#1099' '#1076#1083#1103' '#1087#1088#1086#1089#1084#1086#1090#1088#1072
  ClientHeight = 454
  ClientWidth = 687
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
    Left = 8
    Top = 18
    Width = 217
    Height = 375
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Shape1: TShape
    Left = 240
    Top = 18
    Width = 439
    Height = 375
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label1: TLabel
    Left = 24
    Top = 11
    Width = 53
    Height = 13
    Caption = ' '#1043#1088#1091#1087#1087#1099': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Label2: TLabel
    Left = 256
    Top = 11
    Width = 95
    Height = 13
    Caption = ' '#1063#1083#1077#1085#1099' '#1075#1088#1091#1087#1087#1099': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = False
  end
  object Shape3: TShape
    Left = 8
    Top = 399
    Width = 671
    Height = 49
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Group_ListBox: TListBox
    Left = 13
    Top = 30
    Width = 207
    Height = 358
    ItemHeight = 13
    TabOrder = 0
    OnClick = Group_ListBoxClick
  end
  object GroupList_CheckListBox: TCheckListBox
    Left = 245
    Top = 30
    Width = 429
    Height = 358
    ItemHeight = 13
    TabOrder = 1
  end
  object ButtonAdd: TButton
    Left = 11
    Top = 408
    Width = 167
    Height = 33
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1075#1088#1091#1087#1087#1091'...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonAddClick
  end
  object ButtonDelete: TButton
    Left = 178
    Top = 408
    Width = 165
    Height = 33
    Caption = #1059#1076#1072#1083#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = ButtonDeleteClick
  end
  object ButtonEdit: TButton
    Left = 343
    Top = 408
    Width = 169
    Height = 33
    Caption = #1048#1079#1084#1077#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = ButtonEditClick
  end
  object ButtonClose: TButton
    Left = 512
    Top = 408
    Width = 164
    Height = 33
    Caption = #1047#1072#1082#1088#1099#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = ButtonCloseClick
  end
end
