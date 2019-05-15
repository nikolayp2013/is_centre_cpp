object FormMap: TFormMap
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1050#1072#1088#1090#1072
  ClientHeight = 515
  ClientWidth = 649
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = Button1Click
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 19
    Width = 95
    Height = 13
    Caption = #1040#1076#1088#1077#1089' '#1076#1083#1103' '#1087#1086#1080#1089#1082#1072':'
  end
  object Edit1: TEdit
    Left = 128
    Top = 16
    Width = 417
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 565
    Top = 14
    Width = 75
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 1
    OnClick = Button1Click
  end
  object WebBrowser1: TWebBrowser
    Left = 5
    Top = 56
    Width = 641
    Height = 443
    TabOrder = 2
    ControlData = {
      4C00000040420000C92D00000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
end
