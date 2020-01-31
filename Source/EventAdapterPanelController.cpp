#include "IllustratorSDK.h"
#include "EventAdapterPanelController.h"
#include "AppContext.hpp"
#include "EventAdapterSuites.h"
#include "Plugin.hpp"

#define EA_UI_EXTENSION              "net.sytes.chuwa.eventadaptertest"

#define EVENT_TYPE_PANEL_READY       "com.adobe.csxs.events.EventAdapterPanelReady"
#define EVENT_TYPE_SCRIPTSLOTSSETSC  "com.adobe.csxs.events.EventAdapterToolChanged"


static void PanelReadyFunc(const csxs::event::Event* const eventParam, void* const context){}

EventAdapterPanelController::EventAdapterPanelController()
: FlashUIController(EA_UI_EXTENSION){}

// Add event listeners
csxs::event::EventErrorCode EventAdapterPanelController::RegisterCSXSEventListeners()
{
    csxs::event::EventErrorCode result = csxs::event::kEventErrorCode_Success;
    do
    {
        result = fPPLib.AddEventListener(EVENT_TYPE_PANEL_READY, PanelReadyFunc, this);
        if ( result != csxs::event::kEventErrorCode_Success )
        {
            break;
        }
    }
    while(false);
    return result;
}

// Remove event listeners
csxs::event::EventErrorCode EventAdapterPanelController::RemoveEventListeners()
{
    csxs::event::EventErrorCode result = csxs::event::kEventErrorCode_Success;
    do
    {
        result = fPPLib.RemoveEventListener(EVENT_TYPE_PANEL_READY, PanelReadyFunc, this);
        if ( result != csxs::event::kEventErrorCode_Success )
        {
            break;
        }
    }
    while(false);
    return result;
}

ai::UnicodeString EventAdapterPanelController::UnescapeXML(ai::UnicodeString srcValue)
{
	//Only unescaping ampersand currently could be expanded to other charaters
	ai::UnicodeString ampersandStr("&amp;");
	ai::UnicodeString::size_type start = srcValue.find(ampersandStr);
	if(start <= srcValue.length())
	{
		srcValue.replace(start,ampersandStr.length(),ai::UnicodeString("&"));
	}
	return srcValue;
}

void EventAdapterPanelController::sendToolEvent(const char *name)
{
    stringstream myString;
    myString << "<payload><toolname>" << name << "</toolname></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    
    csxs::event::Event event = {"com.adobe.csxs.events.toolChanged",
        csxs::event::kEventScope_Application,
        "getNotify",
        NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::sendSelectionEvent()
{
    stringstream myString;
    myString << "<payload><event>SelectionChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.selectionChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::sendSwatchListChanged()
{
    stringstream myString;
    myString << "<payload><event>SwatchListChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.swatchListChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::sendCurrentLayer()
{
    stringstream myString;
    myString << "<payload><event>CurrentLayerChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.currentLayerChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::sendActionDone()
{
    stringstream myString;
    myString << "<payload><event>ActionFinished</event></payload>";
    sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.playActionDone",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::sendCurrentFontChanged()
{
   stringstream myString;
    myString << "<payload><event>CurrentFontChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.currentFontChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::sendCurrentFontSizeChanged()
{
    stringstream myString;
    myString << "<payload><event>CurrentFontSizeChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.currentFontSizeChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::sendFontListSizeChanged()
{
    stringstream myString;
    myString << "<payload><event>FontListChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.fontListChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::sendPreferencesChanged()
{
    stringstream myString;
    myString << "<payload><event>PreferencesChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.preferencesChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::rulerUnitChanged()
{
    stringstream myString;
    myString << "<payload><event>RulerUnitChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.rulerUnitChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentWriteOnDiskComplete()
{
    stringstream myString;
    myString << "<payload><event>DocumentWriteOnDiskComplete</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentWriteOnDiskComplete",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentWriteOnDiskFailed()
{
    stringstream myString;
    myString << "<payload><event>DocumentWriteOnDiskFailed</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentWriteOnDiskFailed",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentCMChanged()
{
    stringstream myString;
    myString << "<payload><event>DocumentColorModelChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentColorModelChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::fillAndStrokeChanged()
{
    stringstream myString;
    myString << "<payload><event>FillAndStrokeChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.paintStyleFillAndStrokeChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::gradientStopChangedNotifier()
{
    stringstream myString;
    myString << "<payload><event>GradientStopChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.gradientStopChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::artPropertiesChanged()
{
    stringstream myString;
    myString << "<payload><event>ArtPropertiesChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.artPropertiesChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::editTransparencyNotifier()
{
    stringstream myString;
    myString << "<payload><event>ArtStyleEditTransparency</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.editTransparency",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentChanged()
{
    stringstream myString;
    myString << "<payload><event>DocumentChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentNew()
{
    stringstream myString;
    myString << "<payload><event>NewDocumentCreated</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentNew",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentViewChanged()
{
    stringstream myString;
    myString << "<payload><event>DocumentViewChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentViewChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::gradientChanged()
{
    stringstream myString;
    myString << "<payload><event>GradientChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.gradientChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::endImportCompFont()
{
    stringstream myString;
    myString << "<payload><event>EndImportCompleteFontEvent</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.endImportCompFont",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentProfilesChanged()
{
    stringstream myString;
    myString << "<payload><event>documentProfilesChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentProfilesChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentSpotColorModeChanged()
{
    stringstream myString;
    myString << "<payload><event>documentSpotColorModeChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentSpotColorModeChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentCropAreaModified()
{
    stringstream myString;
    myString << "<payload><event>documentCropAreaModified</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentCropAreaModified",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentRulerOriginChanged()
{
    stringstream myString;
    myString << "<payload><event>documentRulerOriginChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentRulerOriginChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentBleedsChanged()
{
    stringstream myString;
    myString << "<payload><event>documentBleedChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.events.documentBleedsChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::documentViewEdgesVisibilityChanged()
{
    stringstream myString;
    myString << "<payload><event>documentViewEdgesVisibilityChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.documentViewEdgesVisibilityChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::applicationShutdown()
{
    stringstream myString;
    myString << "<payload><event>applicationShutdown</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.applicationShutdown",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}

void EventAdapterPanelController::ATEDocumentResourceChanged()
{
    stringstream myString;
    myString << "<payload><event>ATEDocumentResourceChanged</event></payload>";
    //sAIUser->MessageAlert(ai::UnicodeString(myString.str()));
    std::string xmlstring = myString.str();
    csxs::event::Event event = {"com.adobe.csxs.ateDocumentResourceChanged",
        csxs::event::kEventScope_Application, "getNotify", NULL,
        xmlstring.c_str()};
    fPPLib.DispatchEvent(&event);
}




