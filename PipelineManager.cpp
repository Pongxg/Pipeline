#include "PipelineManager.h"
#include <iostream>
#include "filesystem/path.h"
#include "filesystem/resolver.h"


using namespace std;
using namespace filesystem;

PipelineManager* Singleton<PipelineManager>::m_pSingleton = NULL;

PipelineManager::PipelineManager()
{

}

PipelineManager::~PipelineManager()
{

}


bool PipelineManager::Init()
{
	m_mapKnowNode["RenewAsterAliModelHandler"]		= "AliModelHandler";
	m_mapKnowNode["Aster2dMaxHandler"]				= "Aster2dMaxHandler";					
	m_mapKnowNode["AsterToVrayHandler"]             = "AsterToVrayHandler";            
	m_mapKnowNode["ColorExtract"]                   = "ColorExtractHandler";            
	m_mapKnowNode["Deal2dHandler"]                  = "Deal2dHandler";            
	m_mapKnowNode["Deal3DHandler"]                  = "Deal3DHandler";            
	m_mapKnowNode["MaterialExtract"]                = "MaterialExtractHandler";            
	m_mapKnowNode["MobileHandler"]                  = "MobileHandler";            
	m_mapKnowNode["ObjConvertHandler"]              = "Obj2MaxHandler";            
	m_mapKnowNode["PreCheckHandler"]                = "PreCheckHandler";            
	m_mapKnowNode["PreviewHandler"]                 = "PreviewHandler";            
	m_mapKnowNode["VrsceneHandler"]                 = "VrsceneHandler";            
	m_mapKnowNode["WriteWebT3dResourceHandler"]     = "WriteWebT3dResourceHandler";            
	m_mapKnowNode["AssemblyModel2AuditIsoFront"]    = "AssemblyModel2AuditIsoHandler";            
	m_mapKnowNode["AssemblyModel2Iso"]              = "AssemblyModel2IsoHandler";            
	m_mapKnowNode["ColorExtract"]                   = "ColorExtractHandler";            
	m_mapKnowNode["Deal2dHandler"]                  = "Deal2dHandler";            
	m_mapKnowNode["Deal3DHandler"]                  = "Deal3DHandler";            
	m_mapKnowNode["gen-vray-material-package"]		= "GenVrayMatPackageHandler";            
	m_mapKnowNode["Mat2IsoHandler"]                 = "Mat2IsoHandler";            
	m_mapKnowNode["MaxPackageCheckHandler"]         = "MaxPackageCheckHandler";            
	m_mapKnowNode["MinifyWallfloor"]                = "MinifyWallfloorHandler";            
	m_mapKnowNode["Model2AuditIsoBack"]             = "Model2AuditIsoHandler";            
	m_mapKnowNode["Model2BigIso"]                   = "Model2BigIsoHandler";            
	m_mapKnowNode["Model2Ies"]                      = "Model2IesHandler";            
	m_mapKnowNode["Model2IsoFront"]                 = "Model2IsoHandler";            
	m_mapKnowNode["Model2ShapePicFront"]            = "Model2ShapeHandler";            
	m_mapKnowNode["GenBigThumbnailSceneJson"]       = "Multifacet2IsoHandler";            
	m_mapKnowNode["Initial2dMaterialParams"]        = "Prepare2dMatParamsHandler";            
	m_mapKnowNode["Render2dIso"]                    = "Render2dIsoHandler";            
	m_mapKnowNode["Render4SceneJson"]               = "Render4SceneJsonHandler";            
	m_mapKnowNode["SetMatParamsHandler"]            = "SetMatParamsHandler";            
	m_mapKnowNode["SetObjInfoHandler"]              = "SetObjInfoHandler";            
	m_mapKnowNode["SetWallfloor"]                   = "SetWallfloorHandler";            
	m_mapKnowNode["Shape2SvgFront"]                 = "shape2svg";          	
	m_mapKnowNode["GenSmallTilingSceneJson"]        = "Tiling2dIsoHandler";            
	m_mapKnowNode["Vrscene2BigIso"]					= "Vrscene2BigIsoHandler";
	m_mapKnowNode["WriteWebT3dResourceHandler"]     = "WriteWebT3dResourceHandler";     


	return true;
}

bool PipelineManager::ReadPath(std::string& filePath)
{
	path pipelineFile(filePath);

	return true;
}

bool PipelineManager::GenPipeline()
{
	return true;
}

bool PipelineManager::WriteReport()
{
	return true;
}

