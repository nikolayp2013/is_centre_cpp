object FormExportData: TFormExportData
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1069#1082#1089#1087#1086#1088#1090' '#1076#1072#1085#1085#1099#1093
  ClientHeight = 206
  ClientWidth = 348
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
  object PageControl1: TPageControl
    Left = 7
    Top = 8
    Width = 334
    Height = 153
    ActivePage = TabSheet4
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    OwnerDraw = True
    ParentFont = False
    TabOrder = 0
    OnDrawTab = PageControl1DrawTab
    object TabSheet4: TTabSheet
      Caption = #1069#1082#1089#1087#1086#1088#1090' '#1074' EXCEL'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitHeight = 168
      object Label1: TLabel
        Left = 16
        Top = 13
        Width = 126
        Height = 13
        Caption = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1074' '#1092#1072#1081#1083':'
      end
      object Edit1: TEdit
        Left = 16
        Top = 32
        Width = 258
        Height = 21
        TabOrder = 0
      end
      object Button3: TButton
        Left = 280
        Top = 30
        Width = 25
        Height = 25
        Caption = '...'
        TabOrder = 1
      end
      object CheckBox1: TCheckBox
        Left = 16
        Top = 72
        Width = 177
        Height = 17
        Caption = #1058#1086#1083#1100#1082#1086' '#1086#1090#1084#1077#1095#1077#1085#1085#1099#1077' '#1087#1086#1079#1080#1094#1080#1080
        TabOrder = 2
      end
    end
    object TabSheet5: TTabSheet
      Caption = #1069#1082#1089#1087#1086#1088#1090' '#1074' '#1090#1077#1082#1089#1090
      ImageIndex = 4
      ExplicitLeft = 0
      ExplicitTop = -16
      ExplicitHeight = 168
      object Label2: TLabel
        Left = 16
        Top = 13
        Width = 126
        Height = 13
        Caption = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1074' '#1092#1072#1081#1083':'
      end
      object Label3: TLabel
        Left = 24
        Top = 64
        Width = 110
        Height = 13
        Caption = #1057#1080#1084#1074#1086#1083' '#1088#1072#1079#1076#1077#1083#1080#1090#1077#1083#1100':'
      end
      object Edit2: TEdit
        Left = 16
        Top = 32
        Width = 258
        Height = 21
        TabOrder = 0
      end
      object Button4: TButton
        Left = 280
        Top = 30
        Width = 25
        Height = 25
        Caption = '...'
        TabOrder = 1
      end
      object Edit3: TEdit
        Left = 140
        Top = 61
        Width = 53
        Height = 21
        TabOrder = 2
      end
    end
  end
  object Button1: TButton
    Left = 160
    Top = 171
    Width = 75
    Height = 25
    Caption = #1069#1082#1089#1087#1086#1088#1090
    TabOrder = 1
  end
  object Button2: TButton
    Left = 241
    Top = 171
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 2
    OnClick = Button2Click
  end
end
