object FormExcelExportWidth: TFormExcelExportWidth
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1096#1080#1088#1080#1085#1099' '#1087#1086#1083#1103
  ClientHeight = 135
  ClientWidth = 399
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
    Width = 250
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1096#1080#1088#1080#1085#1091' '#1087#1086#1083#1103' ('#1096#1080#1088#1080#1085#1072' '#1087#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102' 10)'
  end
  object Button1: TButton
    Left = 316
    Top = 16
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 316
    Top = 47
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = Button2Click
  end
  object MaskEdit1: TMaskEdit
    Left = 8
    Top = 106
    Width = 378
    Height = 21
    EditMask = '999;0; '
    MaxLength = 3
    TabOrder = 2
  end
end
