object FormReklamAdd: TFormReklamAdd
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  ClientHeight = 243
  ClientWidth = 348
  Color = 8421631
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 9
    Top = 4
    Width = 166
    Height = 13
    Caption = #1054#1082#1085#1086' '#1088#1077#1082#1083#1072#1084#1072#1094#1080#1080' '#1085#1072' '#1086#1073#1098#1077#1082#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 8
    Top = 23
    Width = 329
    Height = 162
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 242
    Top = 203
    Width = 95
    Height = 29
    Caption = #1047#1072#1082#1088#1099#1090#1100
    DoubleBuffered = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 1
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 122
    Top = 203
    Width = 97
    Height = 29
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    DoubleBuffered = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 2
    OnClick = BitBtn2Click
  end
end
