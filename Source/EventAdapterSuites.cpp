#include "IllustratorSDK.h"
#include "EventAdapterSuites.h"

extern "C" 
{ 
    AIMdMemorySuite             *sAIMdMemory;
    AIMenuSuite                 *sAIMenu;
    AIToolSuite                 *sAITool;
    AIRuntimeSuite              *sAIRuntime;
    AIStringFormatUtilsSuite    *sAIStringFormatUtils;
    AIUnicodeStringSuite        *sAIUnicodeString;
    SPBlocksSuite               *sSPBlocks;
    AICSXSExtensionSuite        *sAICSXSExtension;
    AISwatchListSuite           *sAISwatchList;
    AILayerSuite                *sAILayer;
    AIActionManagerSuite        *sAIActionManager;
    AIATETextUtilSuite          *sAIATETextUtils;
    AIPreferenceSuite           *sAIPreferences;
    AIDocumentSuite             *sAIDocument;
    AIPaintStyleSuite           *sAIPaintStyle;
    AIArtSuite                  *sAIArt;
    AIDocumentViewSuite         *sAIDocumentView;
    AIGradientSuite             *sAIGradient;
    AIFontSuite                 *sAIFont;
    
	EXTERN_TEXT_SUITES
}

ImportSuite gImportSuites[] = 
{
    kAIMdMemorySuite, kAIMdMemorySuiteVersion, &sAIMdMemory,
    kAIMenuSuite, kAIMenuSuiteVersion, &sAIMenu,
    kAIToolSuite, kAIToolSuiteVersion, &sAITool,
    kAIRuntimeSuite, kAIRuntimeSuiteVersion, &sAIRuntime,
    kAIUnicodeStringSuite, kAIUnicodeStringSuiteVersion, &sAIUnicodeString,
    kSPBlocksSuite, kSPBlocksSuiteVersion, &sSPBlocks,
    kAIStringFormatUtilsSuite, kAIStringFormatUtilsSuiteVersion, &sAIStringFormatUtils,
    kAISwatchListSuite, kAISwatchListSuiteVersion, &sAISwatchList,
    kAILayerSuite, kAILayerSuiteVersion, &sAILayer,
    kAIActionManagerSuite, kAIActionManagerSuiteVersion, &sAIActionManager,
    kAIATETextUtilSuite, kAIATETextUtilSuiteVersion, &sAIATETextUtils,
    kAIPreferenceSuite, kAIPreferenceSuiteVersion, &sAIPreferences,
    kAIDocumentSuite, kAIDocumentSuiteVersion, &sAIDocument,
    kAIPaintStyleSuite, kAIPaintStyleSuiteVersion, &sAIPaintStyle,
    kAIArtSuite, kAIArtSuiteVersion, &sAIArt,
    kAIDocumentViewSuite, kAIDocumentViewSuiteVersion, &sAIDocumentView,
    kAIGradientSuite, kAIGradientSuiteVersion, &sAIGradient,
    kAIFontSuite, kAIFontSuiteVersion, &sAIFont,
    

	IMPORT_TEXT_SUITES

	nullptr, 0, nullptr
};

ImportSuite gPostStartupSuites[] = 
{
	kAICSXSExtensionSuite, kAICSXSExtensionSuiteVersion, &sAICSXSExtension,
	nullptr, 0, nullptr
};
// end EventAdapterSuites.cpp
