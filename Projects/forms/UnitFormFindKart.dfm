object FormFindKart: TFormFindKart
  Left = 0
  Top = 0
  ActiveControl = Edit2
  BorderStyle = bsDialog
  Caption = #1055#1086#1080#1089#1082' '#1082#1072#1088#1090#1086#1095#1082#1080'...'
  ClientHeight = 100
  ClientWidth = 256
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
    Left = 18
    Top = 8
    Width = 75
    Height = 13
    Caption = #1050#1086#1076' '#1072#1073#1086#1085#1077#1085#1090#1072':'
  end
  object Label2: TLabel
    Left = 18
    Top = 35
    Width = 75
    Height = 13
    Caption = #1050#1086#1076' '#1082#1072#1088#1090#1086#1095#1082#1080':'
  end
  object Edit1: TEdit
    Left = 99
    Top = 5
    Width = 142
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 99
    Top = 32
    Width = 142
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 51
    Top = 68
    Width = 75
    Height = 25
    Caption = #1055#1086#1080#1089#1082'...'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 132
    Top = 68
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 3
    OnClick = Button2Click
  end
end
