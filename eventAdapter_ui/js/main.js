var csInterface = new CSInterface();

themeSynchronizer.init();
csInterface.addEventListener("com.adobe.csxs.events.toolChanged", toolChanged);
csInterface.addEventListener("com.adobe.csxs.events.selectionChanged", selectionChanged);
csInterface.addEventListener("com.adobe.csxs.events.playActionDone", playActionDone);
csInterface.addEventListener("com.adobe.csxs.events.swatchListChanged", swatchChanged);
csInterface.addEventListener("com.adobe.csxs.events.currentLayerChanged", layerChanged);
csInterface.addEventListener("com.adobe.csxs.events.currentFontChanged", fontChanged);
csInterface.addEventListener("com.adobe.csxs.events.currentFontSizeChanged", fontSizeChanged);
csInterface.addEventListener("com.adobe.csxs.events.fontListChanged", fontListChanged);
csInterface.addEventListener("com.adobe.csxs.events.preferencesChanged", prefChanged);
csInterface.addEventListener("com.adobe.csxs.events.rulerUnitChanged", rulerUnitChanged);
csInterface.addEventListener("com.adobe.csxs.events.documentWriteOnDiskComplete", documentWriteOnDiskComplete);
csInterface.addEventListener("com.adobe.csxs.events.documentWriteOnDiskFailed", documentWriteOnDiskFailed);
csInterface.addEventListener("com.adobe.csxs.events.documentColorModelChanged", documentColorModelChanged);
csInterface.addEventListener("com.adobe.csxs.events.paintStyleFillAndStrokeChanged", paintStyleFillAndStrokeChanged);
csInterface.addEventListener("com.adobe.csxs.events.gradientStopChanged", gradientStopChanged);
csInterface.addEventListener("com.adobe.csxs.events.artPropertiesChanged", artPropertiesChanged);
csInterface.addEventListener("com.adobe.csxs.events.editTransparency", editTransparency);
csInterface.addEventListener("com.adobe.csxs.events.documentChanged", documentChanged);
csInterface.addEventListener("com.adobe.csxs.events.documentNew", documentNew);
csInterface.addEventListener("com.adobe.csxs.events.documentViewChanged", documentViewChanged);
csInterface.addEventListener("com.adobe.csxs.events.gradientChanged", gradientChanged);
csInterface.addEventListener("com.adobe.csxs.events.endImportCompFont", endImportCompFont);
csInterface.addEventListener("com.adobe.csxs.events.documentProfilesChanged", documentProfilesChanged);
csInterface.addEventListener("com.adobe.csxs.events.documentSpotColorModeChanged", documentSpotColorModeChanged);
csInterface.addEventListener("com.adobe.csxs.events.documentCropAreaModified", documentCropAreaModified);
csInterface.addEventListener("com.adobe.csxs.events.documentRulerOriginChanged", documentRulerOriginChanged);
csInterface.addEventListener("com.adobe.csxs.events.documentBleedsChanged", documentBleedsChanged);
csInterface.addEventListener("com.adobe.csxs.events.documentViewEdgesVisibilityChanged", documentViewEdgesVisibilityChanged);
csInterface.addEventListener("com.adobe.csxs.events.applicationShutdown", applicationShutdown);
csInterface.addEventListener("com.adobe.csxs.events.ateDocumentResourceChanged", ateDocumentResourceChanged);





function toolChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Tool Changed Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
	//if (ev.data.indexOf("Adobe Pen Tool")<0) csInterface.evalScript(`app.selectTool("Adobe Pen Tool")`)
}

function selectionChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Selection Changed Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function playActionDone(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Action Finished Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function swatchChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Swatch List Changed Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function layerChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Layer Selection Changed Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function fontChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Current Font Changed Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function fontSizeChanged(ev){
	//alert(ev.data);
	
	document.getElementById("text").value += "<!--Current Font Size Changed Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function fontListChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Font List Changed Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function prefChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Preferences Changed Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function rulerUnitChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Ruler Unit Changed Event Called--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentWriteOnDiskComplete(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document Write OnDisk Complete Event--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentWriteOnDiskFailed(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document Write OnDisk Failed Event--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentColorModelChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document Color Model Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function paintStyleFillAndStrokeChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--PaintStyle Fill and Stroke Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function gradientStopChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Gradient Stop Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function artPropertiesChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Art Properties Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function editTransparency(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Art Properties Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentNew(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--New Document Created--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentViewChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document View Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function gradientChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Gradient Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function endImportCompFont(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Import Font Complete--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentProfilesChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document Profiles Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentSpotColorModeChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document Spot Color Mode Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentCropAreaModified(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document Crop Area Modified--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentRulerOriginChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document Ruler Origin Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentBleedsChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document Bleed Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function documentViewEdgesVisibilityChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Document View Edges Visibility Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function applicationShutdown(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--Application Shutdown--> \n";
	document.getElementById("text").value += ev.data+"\n";
}

function ateDocumentResourceChanged(ev){
	//alert(ev.data);
	document.getElementById("text").value += "<!--ATE Document Resource Changed--> \n";
	document.getElementById("text").value += ev.data+"\n";
}


