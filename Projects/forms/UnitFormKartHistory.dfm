object FormKartHistory: TFormKartHistory
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1048#1089#1090#1086#1088#1080#1103' '#1082#1072#1088#1090#1086#1095#1082#1080
  ClientHeight = 353
  ClientWidth = 607
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
  object History_DBGrid: TDBGrid
    Left = 0
    Top = 0
    Width = 609
    Height = 353
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Date_ch'
        Title.Caption = #1044#1072#1090#1072
        Title.Color = clInfoBk
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 76
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Typeactionlookup'
        Title.Caption = #1054#1087#1077#1088#1072#1094#1080#1103
        Title.Color = clInfoBk
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 166
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Fieldval'
        Title.Caption = #1047#1085#1072#1095#1077#1085#1080#1077
        Title.Color = clInfoBk
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 324
        Visible = True
      end>
  end
end
