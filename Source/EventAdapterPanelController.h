#ifndef __EventAdapterPANELCONTROLLER_H__
#define __EventAdapterPANELCONTROLLER_H__

#include "SDKPlugPlug.h"
#include "IllustratorSDK.h"
#include "FlashUIController.h"
#include "EventAdapterPlugin.hpp"

extern EventAdapterPlugin *gPlugin;

class EventAdapterPanelController : public FlashUIController
{
public:
	EventAdapterPanelController();

	csxs::event::EventErrorCode RegisterCSXSEventListeners();
	csxs::event::EventErrorCode RemoveEventListeners();
	AIErr Initialise(AIFilterMessage* pb);
    

    
    void sendToolEvent (const char *name);
    void sendSelectionEvent();
    void sendSwatchListChanged();
    void sendCurrentLayer();
    void sendActionDone();
    void sendCurrentFontChanged();
    void sendCurrentFontSizeChanged();
    void sendFontListSizeChanged();
    void sendPreferencesChanged();
    void rulerUnitChanged();
    void documentWriteOnDiskComplete();
    void documentWriteOnDiskFailed();
    void documentCMChanged();
    void fillAndStrokeChanged();
    void gradientStopChangedNotifier();
    void artPropertiesChanged();
    void editTransparencyNotifier();
    void documentChanged();
    void documentNew();
    void documentViewChanged();
    void gradientChanged();
    void endImportCompFont();
    void documentProfilesChanged();
    void documentSpotColorModeChanged();
    void documentCropAreaModified();
    void documentRulerOriginChanged();
    void documentBleedsChanged();
    void documentViewEdgesVisibilityChanged();
    void applicationShutdown();
    void ATEDocumentResourceChanged();
    
private:

public:
	static ai::UnicodeString UnescapeXML(ai::UnicodeString srcValue);
};
#endif
