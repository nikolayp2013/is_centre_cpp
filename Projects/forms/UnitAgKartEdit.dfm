object FormAgKartEdit: TFormAgKartEdit
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1051#1080#1095#1085#1072#1103' '#1082#1072#1088#1090#1086#1095#1082#1072' '#1072#1075#1077#1085#1090#1072
  ClientHeight = 247
  ClientWidth = 688
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Shape6: TShape
    Left = 249
    Top = 159
    Width = 433
    Height = 84
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Shape5: TShape
    Left = 4
    Top = 159
    Width = 237
    Height = 84
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label1: TLabel
    Left = 17
    Top = 192
    Width = 57
    Height = 13
    Caption = #1052#1077#1085#1077#1076#1078#1077#1088':'
  end
  object Label2: TLabel
    Left = 160
    Top = 8
    Width = 54
    Height = 13
    Caption = #1051#1080#1094'. '#1082#1072#1088#1090'.'
  end
  object Label3: TLabel
    Left = 360
    Top = 8
    Width = 88
    Height = 13
    Caption = #1044#1072#1090#1072' '#1079#1072#1087#1086#1083#1085#1077#1085#1080#1103
  end
  object Label4: TLabel
    Left = 564
    Top = 8
    Width = 45
    Height = 13
    Caption = #1050#1072#1088#1090'. '#8470
  end
  object Shape2: TShape
    Left = 4
    Top = 30
    Width = 237
    Height = 89
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label5: TLabel
    Left = 30
    Top = 39
    Width = 44
    Height = 13
    Caption = #1060#1072#1084#1080#1083#1080#1103
  end
  object Label6: TLabel
    Left = 55
    Top = 66
    Width = 19
    Height = 13
    Caption = #1048#1084#1103
  end
  object Label7: TLabel
    Left = 25
    Top = 93
    Width = 49
    Height = 13
    Caption = #1054#1090#1095#1077#1089#1090#1074#1086
  end
  object Shape1: TShape
    Left = 249
    Top = 30
    Width = 433
    Height = 118
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label8: TLabel
    Left = 298
    Top = 39
    Width = 53
    Height = 13
    Caption = #1056#1077#1082#1083'. '#1080#1084#1103':'
  end
  object Shape3: TShape
    Left = 257
    Top = 63
    Width = 417
    Height = 78
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label9: TLabel
    Left = 276
    Top = 75
    Width = 75
    Height = 13
    Caption = #1056#1077#1082#1083'. '#1090#1077#1083#1077#1092#1086#1085
  end
  object Label10: TLabel
    Left = 266
    Top = 110
    Width = 85
    Height = 13
    Caption = #1044#1086#1087#1086#1083#1085'. '#1090#1077#1083#1077#1092'.:'
  end
  object Shape4: TShape
    Left = 465
    Top = 63
    Width = 209
    Height = 78
    Brush.Style = bsClear
    Pen.Color = clMedGray
  end
  object Label11: TLabel
    Left = 489
    Top = 75
    Width = 48
    Height = 13
    Caption = #1057#1086#1090'. '#1090#1077#1083'.'
  end
  object Label12: TLabel
    Left = 509
    Top = 110
    Width = 28
    Height = 13
    Caption = 'e-mail'
  end
  object Label13: TLabel
    Left = 13
    Top = 219
    Width = 61
    Height = 13
    Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100':'
  end
  object Label14: TLabel
    Left = 266
    Top = 152
    Width = 141
    Height = 13
    Caption = ' '#1059#1082#1072#1079#1099#1074#1072#1090#1100' '#1074' '#1086#1073#1098#1103#1074#1083#1077#1085#1080#1103#1093' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Transparent = False
  end
  object ButtonPass: TButton
    Left = 4
    Top = 2
    Width = 75
    Height = 25
    Caption = #1055#1072#1088#1086#1083#1100
    TabOrder = 0
    OnClick = ButtonPassClick
  end
  object Manager_ComboBox: TComboBox
    Left = 80
    Top = 189
    Width = 153
    Height = 21
    ItemHeight = 13
    TabOrder = 1
  end
  object LicKart_DBEdit: TDBEdit
    Left = 220
    Top = 2
    Width = 77
    Height = 21
    TabOrder = 2
  end
  object DateEnter_DBEdit: TDBEdit
    Left = 454
    Top = 2
    Width = 83
    Height = 21
    TabOrder = 3
  end
  object KartNo_DBEdit: TDBEdit
    Left = 615
    Top = 2
    Width = 67
    Height = 21
    TabOrder = 4
  end
  object Surname_DBEdit: TDBEdit
    Left = 80
    Top = 36
    Width = 153
    Height = 21
    TabOrder = 5
    OnEnter = Surname_DBEditEnter
  end
  object Name_DBEdit: TDBEdit
    Left = 80
    Top = 63
    Width = 153
    Height = 21
    TabOrder = 6
    OnEnter = Surname_DBEditEnter
  end
  object Secname_DBEdit: TDBEdit
    Left = 80
    Top = 90
    Width = 153
    Height = 21
    TabOrder = 7
    OnEnter = Surname_DBEditEnter
  end
  object Fullname_DBEdit: TDBEdit
    Left = 4
    Top = 127
    Width = 237
    Height = 21
    TabOrder = 8
    OnEnter = Surname_DBEditEnter
  end
  object ReklName_DBEdit: TDBEdit
    Left = 358
    Top = 36
    Width = 316
    Height = 21
    TabOrder = 9
    OnEnter = Surname_DBEditEnter
  end
  object ReklPhone_DBEdit: TDBEdit
    Left = 358
    Top = 72
    Width = 101
    Height = 21
    TabOrder = 10
  end
  object PhoneAdd_DBEdit: TDBEdit
    Left = 358
    Top = 107
    Width = 101
    Height = 21
    TabOrder = 11
  end
  object SotPhone_DBEdit: TDBEdit
    Left = 545
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 12
  end
  object E_mail_DBEdit: TDBEdit
    Left = 545
    Top = 107
    Width = 121
    Height = 21
    TabOrder = 13
    OnEnter = E_mail_DBEditEnter
  end
  object Button1: TButton
    Left = 589
    Top = 214
    Width = 88
    Height = 25
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 14
    OnClick = Button1Click
  end
  object Name_DBCheckBox: TDBCheckBox
    Left = 266
    Top = 189
    Width = 47
    Height = 17
    Alignment = taLeftJustify
    Caption = #1048#1084#1103
    TabOrder = 15
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Price_DBCheckBox: TDBCheckBox
    Left = 266
    Top = 212
    Width = 47
    Height = 17
    Alignment = taLeftJustify
    Caption = #1062#1077#1085#1091
    TabOrder = 16
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Main_DBCheckBox: TDBCheckBox
    Left = 356
    Top = 189
    Width = 75
    Height = 17
    Alignment = taLeftJustify
    Caption = #1056#1077#1082#1083'. '#1090#1077#1083'.'
    TabOrder = 17
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Sot_DBCheckBox: TDBCheckBox
    Left = 469
    Top = 189
    Width = 65
    Height = 17
    Alignment = taLeftJustify
    Caption = #1057#1086#1090'. '#1090#1077#1083'.'
    TabOrder = 18
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object e_mail_DBCheckBox: TDBCheckBox
    Left = 485
    Top = 212
    Width = 49
    Height = 17
    Alignment = taLeftJustify
    Caption = 'e-mail'
    TabOrder = 19
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Add_DBCheckBox: TDBCheckBox
    Left = 356
    Top = 212
    Width = 75
    Height = 17
    Alignment = taLeftJustify
    Caption = #1044#1086#1087'. '#1090#1077#1083'.'
    TabOrder = 20
    ValueChecked = '1'
    ValueUnchecked = '0'
  end
  object Status_DBLookupComboBoxCentre: TDBLookupComboBoxCentre
    Left = 80
    Top = 216
    Width = 153
    Height = 21
    TabOrder = 21
  end
end
