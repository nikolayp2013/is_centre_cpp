object FormSpravAgent: TFormSpravAgent
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082' '#1072#1075#1077#1085#1090#1086#1074' '#1074' '#1089#1080#1089#1090#1077#1084#1077
  ClientHeight = 495
  ClientWidth = 769
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
    Left = 98
    Top = 446
    Width = 49
    Height = 13
    Caption = #1050#1086#1084#1087#1072#1085#1080#1103
  end
  object Label2: TLabel
    Left = 327
    Top = 447
    Width = 30
    Height = 13
    Caption = #1040#1075#1077#1085#1090
  end
  object Label3: TLabel
    Left = 485
    Top = 447
    Width = 60
    Height = 13
    Caption = #1058#1077#1083'. '#1072#1075#1077#1085#1090#1072
  end
  object Button1: TButton
    Left = 605
    Top = 457
    Width = 75
    Height = 25
    Caption = #1048#1084#1087#1086#1088#1090
    TabOrder = 0
  end
  object Button3: TButton
    Left = 686
    Top = 457
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = Button3Click
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 769
    Height = 445
    BiDiMode = bdLeftToRight
    DataSource = DataSource1
    ParentBiDiMode = False
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'COMP'
        Title.Alignment = taCenter
        Title.Caption = #1050#1086#1084#1087#1072#1085#1080#1103
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 343
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'AGENT'
        Title.Alignment = taCenter
        Title.Caption = #1040#1075#1077#1085#1090
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 209
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'PHONE'
        Title.Alignment = taCenter
        Title.Caption = #1058#1077#1083'. '#1072#1075#1077#1085#1090#1072
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -11
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 179
        Visible = True
      end>
  end
  object Comp_Edit: TEdit
    Left = 4
    Top = 461
    Width = 248
    Height = 21
    TabOrder = 3
    OnKeyUp = Comp_EditKeyUp
  end
  object Fgent_Edit: TEdit
    Left = 254
    Top = 461
    Width = 178
    Height = 21
    TabOrder = 4
    OnKeyUp = Fgent_EditKeyUp
  end
  object Phone_Edit: TEdit
    Left = 433
    Top = 461
    Width = 156
    Height = 21
    TabOrder = 5
    OnKeyUp = Phone_EditKeyUp
  end
  object IBDataSet1: TIBDataSet
    Database = MainForm.MainConn
    Transaction = MainForm.IBTransaction1
    SelectSQL.Strings = (
      'select * from AGENTS')
    Left = 48
    Top = 528
  end
  object IBTransaction1: TIBTransaction
    DefaultDatabase = FormStart.MainConn1
    Left = 120
    Top = 528
  end
  object DataSource1: TDataSource
    DataSet = IBDataSet1
    Left = 192
    Top = 528
  end
end
