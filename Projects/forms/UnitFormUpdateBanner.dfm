object FormUpdateBanner: TFormUpdateBanner
  Left = 0
  Top = 0
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsSingle
  ClientHeight = 635
  ClientWidth = 999
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  WindowState = wsMaximized
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 27
    Width = 999
    Height = 608
    ParentCustomHint = False
    Align = alClient
    ParentShowHint = False
    ShowHint = False
    Stretch = True
    ExplicitLeft = 1
    ExplicitTop = 43
    ExplicitHeight = 597
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 999
    Height = 27
    Align = alTop
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 0
    object ProgressBar1: TProgressBar
      Left = 1
      Top = 1
      Width = 997
      Height = 17
      Align = alTop
      Max = 23
      Step = 1
      TabOrder = 0
    end
    object ProgressBar2: TProgressBar
      Left = 1
      Top = 19
      Width = 997
      Height = 7
      Align = alBottom
      DoubleBuffered = True
      ParentDoubleBuffered = False
      Smooth = True
      TabOrder = 1
      ExplicitTop = 20
    end
  end
  object Table_updatebanner: TMyTable
    Left = 936
    Top = 48
  end
  object Query_temp: TMyQuery
    Left = 848
    Top = 120
  end
  object Table_temp_load: TMyTable
    Left = 824
    Top = 48
  end
  object Query_updateexe: TMyQuery
    Left = 760
    Top = 120
  end
  object Query_updatescript: TMyQuery
    Left = 848
    Top = 192
  end
  object Query_reklama: TMyQuery
    Left = 760
    Top = 192
  end
  object IdHTTP1: TIdHTTP
    OnWork = IdHTTP1Work
    OnWorkBegin = IdHTTP1WorkBegin
    AllowCookies = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.Accept = 'text/html, */*'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    HTTPOptions = [hoForceEncodeParams]
    Left = 752
    Top = 56
  end
end
