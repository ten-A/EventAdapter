#include "IllustratorSDK.h"

#include "ATESuites.h"
#include "ATETypes.h"
#include "IText.h"
#include "ATETextSuitesImportHelper.h"
#include "AISwatchList.h"
#include "AILayer.h"
#include "AIActionManager.h"
#include "AIATETextUtil.h"
#include "AIFont.h"
#include "AIPreference.h"
#include "AIDocument.h"
#include "AIPaintStyle.h"
#include "AIArt.h"
#include "AIDocumentView.h"
#include "AIGradient.h"

#include "AIStringFormatUtils.h"


extern "C" SPBasicSuite* sSPBasic;
extern "C" AIToolSuite *sAITool;
extern "C" AIRuntimeSuite *sAIRuntime;
extern "C" AIMdMemorySuite *sAIMdMemory;
extern "C" AIMenuSuite *sAIMenu;
extern "C" AINotifierSuite *sAINotifier;
extern "C" AIStringFormatUtilsSuite *sAIStringFormatUtils;
extern "C" AICSXSExtensionSuite *sAICSXSExtension;
extern "C" AISwatchListSuite *sAISwatchList;
extern "C" AILayerSuite *sAILayer;
extern "C" AIActionManagerSuite *sAIActionManager;
extern "C" AIATETextUtilSuite *sAIATETextUtils;
extern "C" AIPreferenceSuite *sAIPreferences;
extern "C" AIDocumentSuite *sAIDocument;
extern "C" AIPaintStyleSuite *sAIPaintStyle;
extern "C" AIArtSuite *sAIArt;
extern "C" AIDocumentViewSuite *sAIDocumentView;
extern "C" AIGradientSuite *sAIGradient;
extern "C" AIFontSuite *sAIFont;


// globally defined suites that are part of the framework
extern "C" SPAccessSuite	*sSPAccess;
extern "C" AIUnicodeStringSuite *sAIUnicodeString;
extern "C" SPBlocksSuite *sSPBlocks;

//end EventAdapterSuites.h

