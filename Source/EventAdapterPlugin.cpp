#include "IllustratorSDK.h"
#include "EventAdapterPlugin.hpp"
#include "EventAdapterPanelController.h"
#include "AICSXS.h"
#include "SDKErrors.h"
#include "EventAdapterSuites.h"

#define CHECK_ERROR if ( error ) {return error;}

extern ImportSuite gPostStartupSuites[];

EventAdapterPlugin *gPlugin = NULL;

Plugin *AllocatePlugin(SPPluginRef pluginRef)
{
	return new EventAdapterPlugin(pluginRef);
}

void FixupReload(Plugin* plugin)
{
	EventAdapterPlugin::FixupVTable((EventAdapterPlugin*) plugin);
}

ASErr EventAdapterPlugin::SetGlobal(Plugin *plugin)
{
	gPlugin = (EventAdapterPlugin *) plugin;
	return kNoErr;
}

EventAdapterPlugin::EventAdapterPlugin(SPPluginRef pluginRef) :
	Plugin(pluginRef),
	menuItem(NULL),
	fEventAdapterPanelController(NULL),
	artSelectionChangedNotifier(NULL),
    swatchListChangedNotifier(NULL),
    currentLayerNotifier(NULL),
    playActionEveDoneNotifier(NULL),
    currentFontChangedNotifier(NULL),
    currentFontSizeChangedNotifier(NULL),
    fontListChangedNotifier(NULL),
    preferencesChangedNotifier(NULL),
    rulerUnitChangedNotifier(NULL),
    documentWriteOnDiskCompleteNotifier(NULL),
    documentWriteOnDiskFailedNotifier(NULL),
    documentColorModelChanged(NULL),
    paintStyleFillandStrokeChangedNotifier(NULL),
    paintStyleGradientStopChangedNotifier(NULL),
    artPropertiesChangedNotifier(NULL),
    artStyleEditTransparencyNotifier(NULL),
    documentChangedNotifier(NULL),
    documentNewNotifier(NULL),
    documentViewNotifier(NULL),
    gradientChangedNotifier(NULL),
    endImportCompFontNotifier(NULL),
    documentProfilesChangedNotifier(NULL),
    documentSpotColorModeChangedNotifier(NULL),
    documentCropAreaModifiedNotifier(NULL),
    documentBleedsChangedNotifier(NULL),
    documentViewEdgesVisibilityChangeNotifier(NULL),
    applicationShutdownNotifier(NULL),
    ATEDocumentResourceChangedNotifier(NULL),


	aboutPluginMenu(NULL),
    fNotifyToolSelected(NULL),
	fShutdownApplicationNotifier(NULL)
{	
	strncpy(fPluginName, kEventAdapterPluginName, kMaxStringLength);	
}

ASErr EventAdapterPlugin::StartupPlugin( SPInterfaceMessage *message )
{
	ASErr error = Plugin::StartupPlugin( message );
	CHECK_ERROR

	// Add About Plugins menu item for this plug-in.
	SDKAboutPluginsHelper aboutPluginsHelper;
	error = aboutPluginsHelper.AddAboutPluginsMenuItem(message, 
				kSDKDefAboutSDKCompanyPluginsGroupName, 
				ai::UnicodeString(kSDKDefAboutSDKCompanyPluginsGroupNameString), 
				"EventAdapter...",
				&aboutPluginMenu);
	CHECK_ERROR

	if (NULL == fEventAdapterPanelController)
	{
		fEventAdapterPanelController = new EventAdapterPanelController();
		CHECK_ERROR
        
	}
    
/*
    //Add Some Notifiers...
    error = sAINotifier->AddNotifier( fPluginRef, "Register Event Notify",
                                     kAICSXSPlugPlugSetupCompleteNotifier, &fRegisterEventNotifierHandle);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIApplicationShutdownNotifier, &fShutdownApplicationNotifier);
    CHECK_ERROR
*/
    
    
    
	return error;
}

ASErr EventAdapterPlugin::PostStartupPlugin()
{
	ASErr error = kNoErr;
    error = sAIUser->CreateCursorResourceMgr(fPluginRef,&fResourceManagerHandle);
	error = AcquirePostStartupSuites();
    
    
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIToolSelectedNotifier, &fNotifyToolSelected);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIArtSelectionChangedNotifier, &artSelectionChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAISwatchListChangedNotifier, &swatchListChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAICurrentLayerNotifier, &currentLayerNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIActionManagerPlayActionEventDoneNotifier, &playActionEveDoneNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAICurrentFontChangedNotifier, &currentFontChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAICurrentFontSizeChangedNotifier, &currentFontSizeChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIFontListChangedNotifier, &fontListChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIPreferenceChangedNotifier, &preferencesChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentRulerUnitChangedNotifier, &rulerUnitChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentWriteOnDiskCompleteNotifier, &documentWriteOnDiskCompleteNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentWriteOnDiskFailedNotifier, &documentWriteOnDiskFailedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentClrMdlChangedNotifier, &documentColorModelChanged);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIPaintStyleFillStrokeChangedNotifier, &paintStyleFillandStrokeChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIPaintStyleGradientStopChangedNotifier, &paintStyleGradientStopChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIArtPropertiesChangedNotifier, &artPropertiesChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIArtStyleEditTransparencyNotifier, &artStyleEditTransparencyNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentChangedNotifier, &documentChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentNewNotifier, &documentNewNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentViewChangedNotifier, &documentViewNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIArtGradientChangedNotifier, &gradientChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIEndImportCompFontNotifier, &endImportCompFontNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentProfilesChangedNotifier, &documentProfilesChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentSpotColorModeChangedNotifier, &documentSpotColorModeChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentCropAreaModifiedNotifier, &documentCropAreaModifiedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentRulerOriginChangedNotifier, &documentRulerOriginChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentBleedsChangedNotifier, &documentBleedsChangedNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIDocumentViewEdgesVisibilityChangeNotifier, &documentViewEdgesVisibilityChangeNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kAIApplicationShutdownNotifier, &applicationShutdownNotifier);
    CHECK_ERROR
    error = sAINotifier->AddNotifier( fPluginRef, "EventAdapterPlugin",
                                     kATEDocumentResourceChangedNotifier, &ATEDocumentResourceChangedNotifier);
    CHECK_ERROR
    
    
    
	return error;
} //

ASErr EventAdapterPlugin::ShutdownPlugin( SPInterfaceMessage *message )
{
	// Destroy the flash UI
	if (fEventAdapterPanelController != NULL)
	{
		fEventAdapterPanelController->RemoveEventListeners();
		delete fEventAdapterPanelController;
		fEventAdapterPanelController = NULL;
		Plugin::LockPlugin(false);
	}
	ReleasePostStartupSuites();
	ASErr error = Plugin::ShutdownPlugin( message );
	return error;
}

ASErr EventAdapterPlugin::AcquirePostStartupSuites()
{
	ASErr error = kNoErr;

	for ( int i = 0; gPostStartupSuites[i].name != nullptr; ++i )
	{
		if ( gPostStartupSuites[i].suite != nullptr )
		{
			ASErr tmperr = sSPBasic->AcquireSuite(	gPostStartupSuites[i].name, 
					gPostStartupSuites[i].version, 
					(const void **) gPostStartupSuites[i].suite );
			SDK_ASSERT_MSG_NOTHROW(!tmperr, 
					aisdk::format_args("AcquireSuite failed for suite=%s version=%d", 
					gPostStartupSuites[i].name, 
					gPostStartupSuites[i].version));

			if (tmperr && !error)
			{
				// A suite could not be acquired - note first error encountered for later return to caller then carry on.
				error = tmperr;
			}
		}
	}

	return error;
}

ASErr EventAdapterPlugin::ReleasePostStartupSuites()
{
	ASErr error = kNoErr;

	for ( int i = 0; gPostStartupSuites[i].name != nullptr; ++i )
	{
		if ( gPostStartupSuites[i].suite != nullptr )
		{
			void **s = (void **) gPostStartupSuites[i].suite;
			if (*s != nullptr)
			{
				ASErr tmperr = sSPBasic->ReleaseSuite( gPostStartupSuites[i].name, gPostStartupSuites[i].version );
				*s = nullptr;
				SDK_ASSERT_MSG_NOTHROW(!tmperr, 
						aisdk::format_args("ReleaseSuite failed for suite=%s version=%d", 
						gPostStartupSuites[i].name, 
						gPostStartupSuites[i].version));

				if (tmperr && !error)
				{
					// A suite could not be released - note first error encountered for later return to caller then carry on.
					error = tmperr;
				}
			}
		}
	}

	return error;
}

ASErr EventAdapterPlugin::GoMenuItem( AIMenuMessage *message )
{
	try 
	{
		if ( message->menuItem == menuItem ) 
		{
			if (fEventAdapterPanelController)
			{
				AIBoolean visible = false;

				//fEventAdapterPanelController->IsPrimaryStageVisible(visible);

				if(visible)
				{
					fEventAdapterPanelController->UnloadExtension();
				}
				else
				{
					fEventAdapterPanelController->LoadExtension();
				}
			}
		} 
		else if (message->menuItem == aboutPluginMenu)
		{
			SDKAboutPluginsHelper aboutPluginsHelper;
			aboutPluginsHelper.PopAboutBox(message, "About EventAdapter",
				kSDKDefAboutSDKCompanyPluginsAlertString);
		}
	}
	catch(...)
	{
		return 'ESHD';
	}
	
	return kNoErr;
}

ASErr EventAdapterPlugin::UpdateMenuItem( AIMenuMessage *message )
{
	AIBoolean visible = false;

	//if ( fEventAdapterPanelController != NULL )
		//fEventAdapterPanelController->IsPrimaryStageVisible(visible);

	sAIMenu->CheckItem(menuItem, visible);

	return kNoErr;
}



ASErr EventAdapterPlugin::Message(char *caller, char *selector, void *message)
{
    AIErr error = kNoErr;
    
    if (strcmp(caller, kCallerAIScriptMessage ) == 0){
        error = kNoErr;
        AIScriptMessage *msg = (AIScriptMessage*) message;
        
        ai::UnicodeString msgString("Message recieved!");
        msgString.append(ai::UnicodeString("\rSelector: "));
        msgString.append(ai::UnicodeString(selector));
        msgString.append(ai::UnicodeString("\rMessage: "));
        msgString.append(msg->inParam);
    }
    else
    {
        error = Plugin::Message(caller, selector, message);
    }
    
    return error;
    
}

ASErr EventAdapterPlugin::NotifyCSXS( AINotifierMessage *message )
{
    ASErr error = kNoErr;
    
    try
    {
        if ( message->notifier == fRegisterEventNotifierHandle)
        {
            fEventAdapterPanelController->RegisterCSXSEventListeners();
        }
        if (message->notifier == fShutdownApplicationNotifier)
        {
            if(fResourceManagerHandle != NULL)
            {
                error = sAIUser->DisposeCursorResourceMgr(fResourceManagerHandle);
                fResourceManagerHandle = NULL;
            }
        }
    }
    catch(...)
    {
        return 'EPN ';
    }
    
    return error;
}

ASErr EventAdapterPlugin::Notify( AINotifierMessage *message )
{
    ASErr error = kNoErr;
    try
    {
        if (strcmp(message->type, kAIToolSelectedNotifier) == 0)
        {
            AIToolHandle tool;
            SPPluginRef toolPlugin;
            if (!sAITool->GetToolPlugin(tool, &toolPlugin))
            {
                const char *name;
                sAITool->GetCurrentToolName(&name);
                fEventAdapterPanelController->sendToolEvent(name);
            }
        }
        if (message->notifier == artSelectionChangedNotifier)
        {
             fEventAdapterPanelController->sendSelectionEvent();
        }
        if (message->notifier == swatchListChangedNotifier)
        {
            fEventAdapterPanelController->sendSwatchListChanged();
        }
        if (message->notifier == currentLayerNotifier)
        {
            fEventAdapterPanelController->sendCurrentLayer();
        }
       if (message->notifier == playActionEveDoneNotifier)
        {
            fEventAdapterPanelController->sendActionDone();
        }
        if (message->notifier == currentFontChangedNotifier)
        {
            fEventAdapterPanelController->sendCurrentFontChanged();
        }
        if (message->notifier == currentFontSizeChangedNotifier)
        {
            fEventAdapterPanelController->sendCurrentFontSizeChanged();
        }
        if (message->notifier == fontListChangedNotifier)
        {
            fEventAdapterPanelController->sendFontListSizeChanged();
        }
        if (message->notifier == preferencesChangedNotifier)
        {
            fEventAdapterPanelController->sendPreferencesChanged();
        }
        if (message->notifier == rulerUnitChangedNotifier)
        {
            fEventAdapterPanelController->rulerUnitChanged();
        }
        if (message->notifier == documentWriteOnDiskCompleteNotifier)
        {
            fEventAdapterPanelController->documentWriteOnDiskComplete();
        }
        if (message->notifier == documentWriteOnDiskFailedNotifier)
        {
            fEventAdapterPanelController->documentWriteOnDiskFailed();
        }
        if (message->notifier == documentColorModelChanged)
        {
            fEventAdapterPanelController->documentCMChanged();
        }
        if (message->notifier == paintStyleFillandStrokeChangedNotifier)
        {
            fEventAdapterPanelController->fillAndStrokeChanged();
        }
        if (message->notifier == paintStyleGradientStopChangedNotifier)
        {
            fEventAdapterPanelController->gradientStopChangedNotifier();
        }
        if (message->notifier == artPropertiesChangedNotifier)
        {
            fEventAdapterPanelController->artPropertiesChanged();
        }
        if (message->notifier == artStyleEditTransparencyNotifier)
        {
            fEventAdapterPanelController->editTransparencyNotifier();
        }
        if (message->notifier == documentChangedNotifier)
        {
            fEventAdapterPanelController->documentChanged();
        }
        if (message->notifier == documentNewNotifier)
        {
            fEventAdapterPanelController->documentNew();
        }
        if (message->notifier == documentViewNotifier)
        {
            fEventAdapterPanelController->documentViewChanged();
        }
        if (message->notifier == gradientChangedNotifier)
        {
            fEventAdapterPanelController->gradientChanged();
        }
        if (message->notifier == endImportCompFontNotifier)
        {
            fEventAdapterPanelController->endImportCompFont();
        }
        if (message->notifier == documentProfilesChangedNotifier)
        {
            fEventAdapterPanelController->documentProfilesChanged();
        }
        if (message->notifier == documentSpotColorModeChangedNotifier)
        {
            fEventAdapterPanelController->documentSpotColorModeChanged();
        }
        if (message->notifier == documentCropAreaModifiedNotifier)
        {
            fEventAdapterPanelController->documentCropAreaModified();
        }
        if (message->notifier == documentRulerOriginChangedNotifier)
        {
            fEventAdapterPanelController->documentRulerOriginChanged();
        }
        if (message->notifier == documentBleedsChangedNotifier)
        {
            fEventAdapterPanelController->documentBleedsChanged();
        }
        if (message->notifier == documentViewEdgesVisibilityChangeNotifier)
        {
            fEventAdapterPanelController->documentViewEdgesVisibilityChanged();
        }
        if (message->notifier == applicationShutdownNotifier)
        {
            fEventAdapterPanelController->applicationShutdown();
        }
        if (message->notifier == ATEDocumentResourceChangedNotifier)
        {
            fEventAdapterPanelController->ATEDocumentResourceChanged();
        }
        
    }
    catch(...)
    {
        return 'EPN ';
    }
    
    return error;
}



// end EventAdapterPlugin.cpp





