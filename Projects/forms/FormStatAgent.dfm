object FormStatAg: TFormStatAg
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1087#1086' '#1072#1075#1077#1085#1090#1072#1084
  ClientHeight = 179
  ClientWidth = 273
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Shape5: TShape
    Left = 7
    Top = 12
    Width = 260
    Height = 121
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label1: TLabel
    Left = 23
    Top = 5
    Width = 104
    Height = 13
    Caption = ' '#1042#1080#1076#1099' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090#1086#1074' '
    Transparent = False
  end
  object CheckBox1: TCheckBox
    Left = 23
    Top = 24
    Width = 137
    Height = 17
    Caption = #1054#1090#1087#1088#1072#1074#1083#1103#1077#1084#1099#1081' '#1074' '#1089#1077#1090#1100
    Checked = True
    State = cbChecked
    TabOrder = 0
  end
  object CheckBox2: TCheckBox
    Left = 23
    Top = 46
    Width = 137
    Height = 17
    Caption = #1042#1085#1091#1090#1088#1077#1085#1085#1080#1081' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090
    Checked = True
    State = cbChecked
    TabOrder = 1
  end
  object CheckBox3: TCheckBox
    Left = 23
    Top = 69
    Width = 137
    Height = 17
    Caption = #1053#1077#1087#1088#1086#1074#1077#1088#1077#1085#1085#1099#1077' '#1086#1073#1098#1077#1082#1090#1099
    TabOrder = 2
  end
  object CheckBox4: TCheckBox
    Left = 23
    Top = 92
    Width = 137
    Height = 17
    Caption = #1040#1088#1093#1080#1074#1085#1099#1081' '#1087#1088#1072#1081#1089'-'#1083#1080#1089#1090
    TabOrder = 3
  end
  object Button1: TButton
    Left = 89
    Top = 146
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 170
    Top = 146
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 5
    OnClick = Button2Click
  end
  object IBQuery1: TIBQuery
    Database = MainForm.MainConn
    Transaction = IBTransaction1
    SQL.Strings = (
      'select idagent,'
      '(select fullname from people where id=idagent) as agentname,'
      
        '(select shortname from items where code= (select statusid from p' +
        'eople where id=idagent)) as dolg,'
      'sum(cnt1) as cnt1, '
      'sum(cnt2) as cnt2,'
      'sum(cnt3) as cnt3,'
      'sum(cnt4) as cnt4,'
      'sum(cnt5) as cnt5,'
      'sum(cnt6) as cnt6,'
      'sum(cnt7) as cnt7,'
      'sum(cnt8) as cnt8,'
      'sum(cnt9) as cnt9,'
      'sum(cnt10) as cnt10,'
      'sum(cnt11) as cnt11,'
      'sum(cnt12) as cnt12,'
      'sum(cnt13) as cnt13'
      ' from '
      '(select idagent,'
      'count(idagent) as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from APARTSELL a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      'count(idagent) as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from ROOMSSELL a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      'count(idagent) as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from ARENDSELL a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      'count(idagent) as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from HOUSESELL a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      'count(idagent) as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from GARAGESELL a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      'count(idagent) as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from LANDSELL a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      'count(idagent) as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from NewBuildsSELL a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      'count(idagent) as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from CommercSELL1 a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      'count(idagent) as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from CommercSELL2 a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      'count(idagent) as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from CommercSELL3 a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      'count(idagent) as cnt11,'
      '0 as cnt12,'
      '0 as cnt13'
      'from CommercSELL4 a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      'count(idagent) as cnt12,'
      '0 as cnt13'
      'from BusinessSell a  where pricetype=1 group by idagent'
      'union select idagent,'
      '0 as cnt1,'
      '0 as cnt2,'
      '0 as cnt3,'
      '0 as cnt4,'
      '0 as cnt5,'
      '0 as cnt6,'
      '0 as cnt7,'
      '0 as cnt8,'
      '0 as cnt9,'
      '0 as cnt10,'
      '0 as cnt11,'
      '0 as cnt12,'
      'count(idagent) as cnt13'
      'from AbroadSell a  where pricetype=1 group by idagent'
      ') group by idagent')
    Left = 8
    Top = 144
  end
  object IBTransaction1: TIBTransaction
    DefaultDatabase = FormStart.MainConn1
    Left = 56
    Top = 144
  end
end
