//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("forms\UnitFormEditGarageSell.cpp", FormEditGarageSell);
USEFORM("forms\UnitFormFilterAddHouse.cpp", FormFilterAddHouse);
USEFORM("forms\UnitFormEditCommercSell1.cpp", FormEditCommercSell1);
USEFORM("forms\UnitFormExcelExportWidth.cpp", FormExcelExportWidth);
USEFORM("forms\UnitAgKartEdit.cpp", FormAgKartEdit);
USEFORM("forms\UnitFormKartHistory.cpp", FormKartHistory);
USEFORM("forms\UnitFormSelectBlue.cpp", FormSelectBlue);
USEFORM("forms\UnitFormEditLandSell.cpp", FormEditLandSell);
USEFORM("forms\UnitFormEditCommercSell4.cpp", FormEditCommercSell4);
USEFORM("forms\UnitFormEditCommercSell3.cpp", FormEditCommercSell3);
USEFORM("forms\UnitFormTest.cpp", FormTest);
USEFORM("forms\UnitFormAgentPass.cpp", FormAgentPass);
USEFORM("forms\FormGallaryAddRemark.cpp", FormGallaryAddRem);
USEFORM("forms\FormPrint.cpp", FormPr);
USEFORM("forms\UnitFormGridColumn.cpp", FormGridColumn);
USEFORM("forms\UnitFormEditArendPurch.cpp", FormEditArendPurch);
USEFORM("forms\UnitFormEditBusinessSell.cpp", FormEditBusinessSell);
USEFORM("forms\UnitFormAgentRole.cpp", FormAgentRole);
USEFORM("forms\UnitFormInfoWindow.cpp", FormInfoWindow);
USEFORM("forms\UnitFormAgentPrint.cpp", FormAgentPrint);
USEFORM("forms\UnitFormEditRoomsSell.cpp", FormEditRoomsSell);
USEFORM("forms\UnitFormFilterAddRooms.cpp", FormFilterAddRooms);
USEFORM("forms\UnitFormReklamAdd.cpp", FormReklamAdd);
USEFORM("forms\UnitFormUpdateBanner.cpp", FormUpdateBanner);
USEFORM("forms\UnitFormHelp.cpp", FormHelp);
USEFORM("forms\UnitUpdateExe.cpp", FormUpdateExe);
USEFORM("forms\UnitFormReg.cpp", FormReg);
USEFORM("forms\UnitFormEditCommercSell2.cpp", FormEditCommercSell2);
USEFORM("forms\UnitFormSelect.cpp", FormSelect);
USEFORM("forms\FormGallaryViewAdd.cpp", FormGallViewAdd);
USEFORM("forms\UnitFormEditSellAll.cpp", FormEditSellAll);
USEFORM("forms\UnitFormStart.cpp", FormStart);
USEFORM("forms\UnitFormFilterAddArend.cpp", FormFilterAddArend);
USEFORM("forms\FormStatAgent.cpp", FormStatAg);
USEFORM("forms\UnitFormAbonent.cpp", FormAbonent);
USEFORM("forms\UnitFormFilterAdd.cpp", FormFilterAdd);
USEFORM("forms\UnitFormEditRoomsPurch.cpp", FormEditRoomsPurch);
USEFORM("MainClass.cpp", MainForm);
USEFORM("forms\UnitFormEditHouseSell.cpp", FormEditHouseSell);
USEFORM("forms\FormEditKart.cpp", FormEdit);
USEFORM("forms\UnitFormEditAbroadSell.cpp", FormEditAbroadSell);
USEFORM("forms\UnitFormThems.cpp", FormThems);
USEFORM("forms\FormGallary.cpp", FormGall);
USEFORM("forms\UnitFormReklam.cpp", FormReklam);
USEFORM("forms\UnitFormAgentFilter.cpp", FormAgentFilter);
USEFORM("forms\UnitFormFilterAddDop.cpp", FormFilterAddDop);
USEFORM("forms\UnitFormFindKart.cpp", FormFindKart);
USEFORM("forms\UnitFormKlientsKart.cpp", FormKlientsKart);
USEFORM("forms\UnitFormNastr.cpp", FormNastr);
USEFORM("forms\UnitFormExcelExportAdd.cpp", FormExcelExportAdd);
USEFORM("forms\UnitFormGroupEdit.cpp", FormGroupEdit);
USEFORM("forms\UnitExportData.cpp", FormExportData);
USEFORM("forms\UnitFormReestrAbonent.cpp", FormReestrAbonent);
USEFORM("forms\UnitFormEditHousePurch.cpp", FormEditHousePurch);
USEFORM("forms\UnitFormAddGroupName.cpp", FormAddGroupName);
USEFORM("forms\UnitFormEditGaragePurch.cpp", FormEditGaragePurch);
USEFORM("forms\FormConvert.cpp", FormConv);
USEFORM("forms\UnitFormStatFirm.cpp", FormStatFirm);
USEFORM("forms\UnitFormSpravAgent.cpp", FormSpravAgent);
USEFORM("forms\UnitFormEditArendSell.cpp", FormEditArendSell);
USEFORM("forms\UnitFormKlientsFind.cpp", FormKlientsFind);
USEFORM("forms\UnitFormMap.cpp", FormMap);
USEFORM("forms\UnitFormExcelExport.cpp", FormExcelExport);
USEFORM("forms\UnitFormKlients.cpp", FormKlients);
USEFORM("forms\UnitFormStatAgentAdd.cpp", FormStatAgAdd);
USEFORM("forms\UnitFormAgent.cpp", FormAgent);
USEFORM("forms\UnitFormEditApartPurch.cpp", FormEditApartPurch);
USEFORM("forms\UnitFormSwap.cpp", FormSwap);
USEFORM("forms\UnitFormAgentRoleAdd.cpp", FormAgentRoleAdd);
USEFORM("forms\UnitFormEditNewBuildsSell.cpp", FormEditNewBuildsSell);
USEFORM("forms\FormGallaryView.cpp", FormGallView);
USEFORM("forms\UnitFormFilterAddSearch.cpp", FormFilterAddSearch);
USEFORM("forms\UnitFormEditCommercPurch.cpp", FormEditCommercPurch);
USEFORM("forms\UnitFormExportGrid.cpp", FormExportGrid);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TFormStart), &FormStart);
		Application->CreateForm(__classid(TFormEditArendSell), &FormEditArendSell);
		Application->CreateForm(__classid(TFormConv), &FormConv);
		Application->CreateForm(__classid(TFormPr), &FormPr);
		Application->CreateForm(__classid(TFormStatAg), &FormStatAg);
		Application->CreateForm(__classid(TFormGall), &FormGall);
		Application->CreateForm(__classid(TFormGallaryAddRem), &FormGallaryAddRem);
		Application->CreateForm(__classid(TFormMap), &FormMap);
		Application->CreateForm(__classid(TFormAgent), &FormAgent);
		Application->CreateForm(__classid(TFormAgKartEdit), &FormAgKartEdit);
		Application->CreateForm(__classid(TFormAgentPass), &FormAgentPass);
		Application->CreateForm(__classid(TFormAgentPrint), &FormAgentPrint);
		Application->CreateForm(__classid(TFormAgentFilter), &FormAgentFilter);
		Application->CreateForm(__classid(TFormAbonent), &FormAbonent);
		Application->CreateForm(__classid(TFormAgentRole), &FormAgentRole);
		Application->CreateForm(__classid(TFormAgentRoleAdd), &FormAgentRoleAdd);
		Application->CreateForm(__classid(TFormKlients), &FormKlients);
		Application->CreateForm(__classid(TFormKlientsKart), &FormKlientsKart);
		Application->CreateForm(__classid(TFormKlientsFind), &FormKlientsFind);
		Application->CreateForm(__classid(TFormInfoWindow), &FormInfoWindow);
		Application->CreateForm(__classid(TFormFindKart), &FormFindKart);
		Application->CreateForm(__classid(TFormGroupEdit), &FormGroupEdit);
		Application->CreateForm(__classid(TFormExcelExport), &FormExcelExport);
		Application->CreateForm(__classid(TFormThems), &FormThems);
		Application->CreateForm(__classid(TFormNastr), &FormNastr);
		Application->CreateForm(__classid(TFormStatFirm), &FormStatFirm);
		Application->CreateForm(__classid(TFormSpravAgent), &FormSpravAgent);
		Application->CreateForm(__classid(TFormReestrAbonent), &FormReestrAbonent);
		Application->CreateForm(__classid(TFormReklam), &FormReklam);
		Application->CreateForm(__classid(TFormExportData), &FormExportData);
		Application->CreateForm(__classid(TFormTest), &FormTest);
		Application->CreateForm(__classid(TFormKartHistory), &FormKartHistory);
		Application->CreateForm(__classid(TFormAddGroupName), &FormAddGroupName);
		Application->CreateForm(__classid(TFormExcelExportAdd), &FormExcelExportAdd);
		Application->CreateForm(__classid(TFormExcelExportWidth), &FormExcelExportWidth);
		Application->CreateForm(__classid(TFormGridColumn), &FormGridColumn);
		Application->CreateForm(__classid(TFormEditCommercPurch), &FormEditCommercPurch);
		Application->CreateForm(__classid(TFormEditSellAll), &FormEditSellAll);
		Application->CreateForm(__classid(TFormEdit), &FormEdit);
		Application->CreateForm(__classid(TFormEditArendPurch), &FormEditArendPurch);
		Application->CreateForm(__classid(TFormEditBusinessSell), &FormEditBusinessSell);
		Application->CreateForm(__classid(TFormEditApartPurch), &FormEditApartPurch);
		Application->CreateForm(__classid(TFormEditAbroadSell), &FormEditAbroadSell);
		Application->CreateForm(__classid(TFormEditRoomsPurch), &FormEditRoomsPurch);
		Application->CreateForm(__classid(TFormEditHouseSell), &FormEditHouseSell);
		Application->CreateForm(__classid(TFormEditHousePurch), &FormEditHousePurch);
		Application->CreateForm(__classid(TFormEditNewBuildsSell), &FormEditNewBuildsSell);
		Application->CreateForm(__classid(TFormEditGaragePurch), &FormEditGaragePurch);
		Application->CreateForm(__classid(TFormEditCommercSell2), &FormEditCommercSell2);
		Application->CreateForm(__classid(TFormEditGarageSell), &FormEditGarageSell);
		Application->CreateForm(__classid(TFormEditCommercSell3), &FormEditCommercSell3);
		Application->CreateForm(__classid(TFormEditCommercSell4), &FormEditCommercSell4);
		Application->CreateForm(__classid(TFormEditCommercSell1), &FormEditCommercSell1);
		Application->CreateForm(__classid(TFormEditLandSell), &FormEditLandSell);
		Application->CreateForm(__classid(TFormEditRoomsSell), &FormEditRoomsSell);
		Application->CreateForm(__classid(TFormSelectBlue), &FormSelectBlue);
		Application->CreateForm(__classid(TFormFilterAddRooms), &FormFilterAddRooms);
		Application->CreateForm(__classid(TFormFilterAddDop), &FormFilterAddDop);
		Application->CreateForm(__classid(TFormSelect), &FormSelect);
		Application->CreateForm(__classid(TFormFilterAddSearch), &FormFilterAddSearch);
		Application->CreateForm(__classid(TFormFilterAddArend), &FormFilterAddArend);
		Application->CreateForm(__classid(TFormFilterAddHouse), &FormFilterAddHouse);
		Application->CreateForm(__classid(TFormFilterAdd), &FormFilterAdd);
		Application->CreateForm(__classid(TFormSwap), &FormSwap);
		Application->CreateForm(__classid(TFormUpdateBanner), &FormUpdateBanner);
		Application->CreateForm(__classid(TFormGallView), &FormGallView);
		Application->CreateForm(__classid(TFormGallViewAdd), &FormGallViewAdd);
		Application->CreateForm(__classid(TFormReg), &FormReg);
		Application->CreateForm(__classid(TFormStatAgAdd), &FormStatAgAdd);
		Application->CreateForm(__classid(TFormHelp), &FormHelp);
		Application->CreateForm(__classid(TFormReklamAdd), &FormReklamAdd);
		Application->CreateForm(__classid(TFormUpdateExe), &FormUpdateExe);
		Application->CreateForm(__classid(TFormExportGrid), &FormExportGrid);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
