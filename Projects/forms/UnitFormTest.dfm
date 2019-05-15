object FormTest: TFormTest
  Left = 0
  Top = 0
  Caption = 'FormTest'
  ClientHeight = 429
  ClientWidth = 521
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 248
    Top = 8
    Width = 185
    Height = 41
    Caption = 'Panel1'
    ParentBackground = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 424
    Top = 55
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object IBDatabase1: TIBDatabase
    Connected = True
    DatabaseName = 'localhost:centre_db'
    Params.Strings = (
      'user_name=sysdba'
      'password=masterkey'
      'lc_ctype=WIN1251')
    LoginPrompt = False
    Left = 24
    Top = 8
  end
  object IBTransaction1: TIBTransaction
    DefaultDatabase = IBDatabase1
    Left = 96
    Top = 8
  end
  object IBTable1: TIBTable
    Database = IBDatabase1
    Transaction = IBTransaction1
    TableName = 'PRICELIST'
    Left = 168
    Top = 8
    object IBTable1ID: TIntegerField
      FieldName = 'ID'
      Required = True
    end
    object IBTable1AGENT: TIntegerField
      FieldName = 'AGENT'
    end
    object IBTable1NUM_CARD: TIntegerField
      FieldName = 'NUM_CARD'
    end
    object IBTable1DATE_CH: TDateField
      FieldName = 'DATE_CH'
    end
    object IBTable1REGION: TIntegerField
      FieldName = 'REGION'
    end
    object IBTable1MREGION: TSmallintField
      FieldName = 'MREGION'
    end
    object IBTable1STREET: TIBStringField
      FieldName = 'STREET'
      Size = 70
    end
    object IBTable1ROOMS: TSmallintField
      FieldName = 'ROOMS'
    end
    object IBTable1IROOMS: TSmallintField
      FieldName = 'IROOMS'
    end
    object IBTable1TYPEHOUSE: TSmallintField
      FieldName = 'TYPEHOUSE'
    end
    object IBTable1level: TSmallintField
      FieldName = 'level'
    end
    object IBTable1LEVELS: TSmallintField
      FieldName = 'LEVELS'
    end
    object IBTable1STUFFWALL: TSmallintField
      FieldName = 'STUFFWALL'
    end
    object IBTable1TOTALAREA: TIBBCDField
      FieldName = 'TOTALAREA'
      Precision = 18
      Size = 2
    end
    object IBTable1LIVEAREA: TIBBCDField
      FieldName = 'LIVEAREA'
      Precision = 18
      Size = 2
    end
    object IBTable1KITCHENAREA: TIBBCDField
      FieldName = 'KITCHENAREA'
      Precision = 18
      Size = 2
    end
    object IBTable1NODESAN: TSmallintField
      FieldName = 'NODESAN'
    end
    object IBTable1BALCONY: TSmallintField
      FieldName = 'BALCONY'
    end
    object IBTable1SWPHONE: TSmallintField
      FieldName = 'SWPHONE'
    end
    object IBTable1VARIANT: TSmallintField
      FieldName = 'VARIANT'
    end
    object IBTable1PRICE: TIBBCDField
      FieldName = 'PRICE'
      Precision = 18
      Size = 2
    end
    object IBTable1CHECK: TSmallintField
      FieldName = 'CHECK'
    end
    object IBTable1CRSTREET: TIBStringField
      FieldName = 'CRSTREET'
      Size = 70
    end
    object IBTable1CORPUS: TIBStringField
      FieldName = 'CORPUS'
      Size = 2
    end
    object IBTable1HOUSE: TIntegerField
      FieldName = 'HOUSE'
    end
    object IBTable1FLAT: TIntegerField
      FieldName = 'FLAT'
    end
    object IBTable1CONTRACT: TIntegerField
      FieldName = 'CONTRACT'
    end
    object IBTable1SOURCED: TIntegerField
      FieldName = 'SOURCED'
    end
    object IBTable1VARIANTD: TIntegerField
      FieldName = 'VARIANTD'
    end
    object IBTable1MORGAGE: TIntegerField
      FieldName = 'MORGAGE'
    end
    object IBTable1PART: TIBStringField
      FieldName = 'PART'
    end
    object IBTable1YEARBUILD: TIntegerField
      FieldName = 'YEARBUILD'
    end
    object IBTable1SECURITY: TIntegerField
      FieldName = 'SECURITY'
    end
    object IBTable1KONSERG: TIntegerField
      FieldName = 'KONSERG'
    end
    object IBTable1OWNEX: TIntegerField
      FieldName = 'OWNEX'
    end
    object IBTable1TRASH: TIntegerField
      FieldName = 'TRASH'
    end
    object IBTable1GAZ: TIntegerField
      FieldName = 'GAZ'
    end
    object IBTable1PARKING: TIntegerField
      FieldName = 'PARKING'
    end
    object IBTable1NEWBUILD: TIntegerField
      FieldName = 'NEWBUILD'
    end
    object IBTable1DESIGN: TIntegerField
      FieldName = 'DESIGN'
    end
    object IBTable1STATE: TIntegerField
      FieldName = 'STATE'
    end
    object IBTable1LOGGIA: TIntegerField
      FieldName = 'LOGGIA'
    end
    object IBTable1GLASSBALC: TIntegerField
      FieldName = 'GLASSBALC'
    end
    object IBTable1GLASSPACK: TIntegerField
      FieldName = 'GLASSPACK'
    end
    object IBTable1ADDINFO: TBlobField
      FieldName = 'ADDINFO'
    end
    object IBTable1VARSWAP: TIntegerField
      FieldName = 'VARSWAP'
    end
    object IBTable1DOPLATA: TIntegerField
      FieldName = 'DOPLATA'
    end
    object IBTable1SWAPINFO: TIBStringField
      FieldName = 'SWAPINFO'
      Size = 200
    end
    object IBTable1PICS: TSmallintField
      FieldName = 'PICS'
    end
  end
end
