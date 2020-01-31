#ifndef __EventAdapterPlugin_hpp__
#define __EventAdapterPlugin_hpp__

#include "EventAdapterID.h"
#include "SDKDef.h"
#include "SDKAboutPluginsHelper.h"
#include "AIScriptMessage.h"

/**	Creates a new EventAdapterPlugin.
	@param pluginRef IN unique reference to this plugin.
	@return pointer to new EventAdapterPlugin.
*/
Plugin* AllocatePlugin(SPPluginRef pluginRef);

/**	Reloads the EventAdapterPlugin class state when the plugin is 
	reloaded by the application.
	@param plugin IN pointer to plugin being reloaded.
*/
void FixupReload(Plugin* plugin);


class EventAdapterPanelController;

class EventAdapterPlugin : public Plugin
{
public:
	
	EventAdapterPlugin(SPPluginRef pluginRef); //Constructor. @param pluginRef IN reference to this plugin.
    
	virtual ~EventAdapterPlugin(){} //Destructor.

	FIXUP_VTABLE_EX(EventAdapterPlugin, Plugin); //Restores state of EventAdapterPlugin during reload.
	
    
    
protected:

	virtual ASErr SetGlobal(Plugin * plugin);
	virtual ASErr StartupPlugin( SPInterfaceMessage * message );
	virtual ASErr ShutdownPlugin( SPInterfaceMessage * message );
	virtual ASErr PostStartupPlugin( void );
	virtual ASErr GoMenuItem( AIMenuMessage * message );
	virtual ASErr UpdateMenuItem( AIMenuMessage * message );
    virtual ASErr Notify( AINotifierMessage * message );
    virtual ASErr NotifyCSXS( AINotifierMessage * message );
    virtual ASErr Message(char *caller, char *selector, void *message);
	
private:
	AIMenuItemHandle			menuItem;
    EventAdapterPanelController* fEventAdapterPanelController;

	//AIToolHandle		toolHandle;
	AIMenuItemHandle	aboutPluginMenu;

	AINotifierHandle	fRegisterEventNotifierHandle;
	AINotifierHandle    fNotifyToolSelected;
	AINotifierHandle	fShutdownApplicationNotifier;
    AINotifierHandle    artSelectionChangedNotifier;
    AINotifierHandle    swatchListChangedNotifier;
    AINotifierHandle    currentLayerNotifier;
    AINotifierHandle    playActionEveDoneNotifier;
    AINotifierHandle    currentFontChangedNotifier;
    AINotifierHandle    currentFontSizeChangedNotifier;
    AINotifierHandle    fontListChangedNotifier;
    AINotifierHandle    preferencesChangedNotifier;
    AINotifierHandle    rulerUnitChangedNotifier;
    AINotifierHandle    documentWriteOnDiskCompleteNotifier;
    AINotifierHandle    documentWriteOnDiskFailedNotifier;
    AINotifierHandle    documentColorModelChanged;
    AINotifierHandle    paintStyleFillandStrokeChangedNotifier;
    AINotifierHandle    paintStyleGradientStopChangedNotifier;
    AINotifierHandle    artPropertiesChangedNotifier;
    AINotifierHandle    artStyleEditTransparencyNotifier;
    AINotifierHandle    documentChangedNotifier;
    AINotifierHandle    documentNewNotifier;
    AINotifierHandle    documentViewNotifier;
    AINotifierHandle    gradientChangedNotifier;
    AINotifierHandle    endImportCompFontNotifier;
    AINotifierHandle    documentProfilesChangedNotifier;
    AINotifierHandle    documentSpotColorModeChangedNotifier;
    AINotifierHandle    documentCropAreaModifiedNotifier;
    AINotifierHandle    documentRulerOriginChangedNotifier;
    AINotifierHandle    documentBleedsChangedNotifier;
    AINotifierHandle    documentViewEdgesVisibilityChangeNotifier;
    AINotifierHandle    applicationShutdownNotifier;
    AINotifierHandle    ATEDocumentResourceChangedNotifier;
    
    AIResourceManagerHandle     fResourceManagerHandle;

	ASErr AcquirePostStartupSuites( void );
	ASErr ReleasePostStartupSuites( void );
};

#endif
