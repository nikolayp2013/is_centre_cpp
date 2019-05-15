//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMap *FormMap;
// ������� ������� �� ������� ��������
TDataSource * TabPricelist_Datasource_Main;
extern TDataSource * TabPricelist_Datasource_Main;
//---------------------------------------------------------------------------
__fastcall TFormMap::TFormMap(TComponent* Owner, TDataSource * Table_Datasource)
	: TForm(Owner)
{
	TabPricelist_Datasource_Main = Table_Datasource;
	//ShowMessage(TabPricelist_Datasource_Main->DataSet->FieldByName("street")->AsString);
}
//---------------------------------------------------------------------------
void __fastcall TFormMap::Button1Click(TObject *Sender)
{

   TMemoryStream *stm = new TMemoryStream();
   AnsiString html = " <!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">   "
		" <html xmlns=\"http://www.w3.org/1999/xhtml\"> "
		"   <head>    "
		"     <meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\"/>    "
		"     <title>������ ������������� Google Maps</title> "
		"    <link rel=\"stylesheet\" href=\"styles.css\" media=\"screen\" />   "
		"     <script src=\"http://maps.google.com/maps?file=api&amp;v=2.x&amp;key=ABQIAAAAzr2EBOXUKnm_jVnk0OJI7xSosDVG8KKPE1-m51RBrvYughuyMxQ-i1QfUnH94QxWIa6N4U6MouMmBA\"  "
		"             type=\"text/javascript\"></script>    "
		"     <script type=\"text/javascript\"> "
		" var map;    "
		"  function initialize() {    "
		"     map = new GMap2(document.getElementById(\"map_canvas\")); "
		"        if (GBrowserIsCompatible()) {  "
		"        map.setCenter(new GLatLng(53.2111075, 50.1560589), 17);    "
		" map.addControl(new GLargeMapControl()); "
		" map.addControl(new GMapTypeControl());  "
		" map.setMapType(G_NORMAL_MAP);     "
		" }   }   "
		" var geocoder = new GClientGeocoder();   "
		" function getAdress() {  "
		" var address = \"";

		AnsiString html2 ="\";"
		" geocoder.getLatLng( "
		" address,    "
		" function(point) {   "
		" if (!point) {   "
		" alert(address + \" �� ������\");  "
		" } else {    "
		" geocoder.getLocations(address, addAdr); "
		" }});}   "
		" function addAdr(response) { "
		" map.clearOverlays();    "
		" if (!response || response.Status.code != 200) {alert(\"\\\"\" + address + \"\\\" �� ������\"); "
		" } else {    "
		" place = response.Placemark[0];  "
		" point = new GLatLng(place.Point.coordinates[1], "
		" place.Point.coordinates[0]);    "
		" marker = new GMarker(point);    "
		" map.addOverlay(marker); "
		" marker.openInfoWindowHtml(place.address);   "
		" }}  "
		" </script>   "
		" </head> "
		" <body onload=\"initialize();getAdress()\" onunload=\"GUnload()\">   "
		"<div id=\"map_canvas\" style=\"width:600px; height:400px;\"></div>"
		" </body> "
		" </html> ";

	AnsiString addres = "������,";
	addres = addres + TabPricelist_Datasource_Main->DataSet->FieldByName("street")->AsAnsiString;
	addres = addres + ",";
	addres = addres + TabPricelist_Datasource_Main->DataSet->FieldByName("house")->AsAnsiString;

	if (Edit1->Text.IsEmpty()) {
		Edit1->Text=addres;
	}
	html = html + AnsiToUtf8(Edit1->Text).c_str();
	html = html + html2;

	stm->Write(html.c_str(), html.Length());
	stm->Seek(0, 0);
	IPersistStreamInit *psi;
	TStreamAdapter *sa = new TStreamAdapter(stm, soReference);
	WebBrowser1->Navigate(WideString("about:blank").c_bstr());
	if (SUCCEEDED(WebBrowser1->Document->QueryInterface(IID_IPersistStreamInit,
						(void**) & psi))) {
        Application->ProcessMessages();

		psi->Load(*sa);
        psi->Release();
}
delete stm;
}
//---------------------------------------------------------------------------
