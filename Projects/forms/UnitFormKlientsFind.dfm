object FormKlientsFind: TFormKlientsFind
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1055#1086#1080#1089#1082' '#1082#1083#1080#1077#1085#1090#1072
  ClientHeight = 108
  ClientWidth = 457
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
    Top = 16
    Width = 85
    Height = 13
    Caption = #1048#1085#1092#1086' '#1086' '#1082#1083#1080#1077#1085#1090#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 54
    Width = 49
    Height = 13
    Caption = #1050#1086#1084#1087#1072#1085#1080#1103
  end
  object Label3: TLabel
    Left = 39
    Top = 81
    Width = 23
    Height = 13
    Caption = #1060#1048#1054
  end
  object Edit1: TEdit
    Left = 107
    Top = 13
    Width = 158
    Height = 21
    TabOrder = 0
    OnEnter = Edit1Enter
  end
  object Button1: TButton
    Left = 271
    Top = 11
    Width = 75
    Height = 25
    Caption = #1055#1086#1080#1089#1082
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 352
    Top = 11
    Width = 97
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 2
    OnClick = Button2Click
  end
  object Comp_Edit: TEdit
    Left = 71
    Top = 51
    Width = 378
    Height = 21
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 3
  end
  object Name_Edit: TEdit
    Left = 71
    Top = 79
    Width = 378
    Height = 21
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
  end
end
