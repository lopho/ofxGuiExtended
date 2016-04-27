#include "ofxGuiExtended.h"

ofxGui::ofxGui(){
	setup_done = false;
}

ofxGui::~ofxGui(){
}

void ofxGui::setup(){
	setup_done = true;
	document = std::make_unique<DOM::Document>();
	document->createLayout<ofxDOMFlexBoxLayout>(document.get());
}

DOM::Document* ofxGui::getRoot(){
	if(!setup_done){
		setup();
	}
	return document.get();
}

ofxGuiGroup* ofxGui::addGroup(const std::string& name, const ofJson& config){
	return getRoot()->add<ofxGuiGroup>(name, rootGroupConfig(config));
}

ofxGuiGroup* ofxGui::addGroup(const ofParameterGroup & parameters, const ofJson& config){
	return getRoot()->add<ofxGuiGroup>(parameters, rootGroupConfig(config));
}

ofxGuiPanel* ofxGui::addPanel(const std::string& name, const ofJson& config){
	return getRoot()->add<ofxGuiPanel>(name, rootGroupConfig(config));
}

ofxGuiPanel* ofxGui::addPanel(const ofParameterGroup & parameters, const ofJson& config){
	return getRoot()->add<ofxGuiPanel>(parameters, rootGroupConfig(config));
}

ofxGuiTabs* ofxGui::addTabs(const std::string& name, const ofJson& config){
	return getRoot()->add<ofxGuiTabs>(name, rootGroupConfig(config));
}

ofJson ofxGui::rootGroupConfig(const ofJson& config){
	ofJson res = config;
	if(config.find("width") == config.end()){
		res["width"] = 200;
	}
	if(config.find("position") == config.end()){
		res["position"] = "absolute";
	}
	if(config.find("left") == config.end()){
		res["left"] = 10;
	}
	if(config.find("top") == config.end()){
		res["top"] = 10;
	}
	if(config.find("flex-direction") == config.end()){
		res["flex-direction"] = "column";
	}
	return res;
}
