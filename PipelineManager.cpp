#include "PipelineManager.h"
#include <filesystem>
#include "Pipeline.h"
#include "easylogging++.h"
#include "AnyNode.h"
#include "ApiNode.h"
#include "ConditionNode.h"
#include "MessageNode.h"
#include "SimpleTaskNode.h"
#include "SubProcess.h"

PipelineManager* Singleton<PipelineManager>::m_pSingleton = NULL;

PipelineManager::PipelineManager()
{

}

PipelineManager::~PipelineManager()
{

}

bool PipelineManager::Init()
{
	FilterInit();
	RegisterInit();
	return true;
}

bool PipelineManager::ReadPath(const char* _file_path)
{
	TraversePath(_file_path);
	return true;
}

bool PipelineManager::GenPipeline()
{
	for(StrMapIter iter = m_mapPipelineName.begin();iter != m_mapPipelineName.end();++iter)
	{
		CreatePipeline(iter->second);
	}
	return true;
}


bool PipelineManager::BindNodeFile()
{
	std::map<std::string, Pipeline*>::iterator  iter = m_mapPipeline.begin();
	for (; iter != m_mapPipeline.end(); ++iter)
	{
		iter->second->BindNodeFile();
	}

	return true;
}



Pipeline* PipelineManager::CreatePipeline(std::string  _file_path)
{
	std::map<std::string, Pipeline*>::iterator  iter = m_mapPipeline.find(_file_path);
	if (iter != m_mapPipeline.end())
	{
		LOG(WARNING) << "CreatePipeline:: pipeline already exists:" << _file_path;
		return iter->second;
	}
	Pipeline* pipeline = new Pipeline();
	pipeline->ParseFile(_file_path);
	m_mapPipeline[_file_path] = pipeline;
	return pipeline;
}

bool PipelineManager::FindPipelinePath(std::string& _file_name,std::string& _file_path)
{
	StrMapIter  iter = m_mapPipelineName.find(_file_name);
	if (iter == m_mapPipelineName.end())
	{
		LOG(WARNING) << "FindPipelinePath:: _file_path non exists:" << _file_name;
		return false;
	}
	_file_path = iter->second;
	return true;
}

Pipeline* PipelineManager::FindPipeline(std::string& _file_name)
{
	std::string filePath;
	bool bFind = FindPipelinePath(_file_name, filePath);
	if (!bFind)
	{
		LOG(WARNING) << "FindPipeline:: _file_path non exists:" << _file_name;
		return NULL;
	}
	std::map<std::string, Pipeline*>::iterator  iter = m_mapPipeline.find(filePath);
	if (iter == m_mapPipeline.end())
	{
		LOG(WARNING) << "FindPipeline:: pipeline non exists:" << filePath;
		return NULL;
	}
	return iter->second;
}

bool PipelineManager::FilterNode()
{
	std::map<std::string, Pipeline*>::iterator  iter = m_mapPipeline.begin();
	for (; iter != m_mapPipeline.end(); ++iter)
	{
		iter->second->TraverNodeFile();
	}
	return true;
}

bool PipelineManager::FindBinderNode(std::string pipeline)
{
	Pipeline* pipe = FindPipeline(pipeline);
	if (pipe == NULL)
	{
		return false;
	}
	pipe->TraverNodeFile();
	return true;
}


bool PipelineManager::FindTaskNode(Pipeline* _pipeline, std::string& _task_handle, std::string& _dag_name)
{
	std::string::size_type pos;
	pos = _dag_name.find("#");
	int length = _dag_name.size();
	if (pos != std::string::npos)
	{
		std::string pipelineName = _dag_name.substr(0, pos);
		Pipeline* pipeline = gPipelineInstance->FindPipeline(pipelineName);
		if (!pipeline)
		{
			LOG(ERROR) << "FindTaskNode:pipeline not find:" << pipelineName;
			return false;
		}
		std::string dagName = _dag_name.substr(pos + 1, length);
		return FindTaskNode(pipeline, _task_handle, dagName);
	}
	else
	{
		/*return _pipeline->FindNodeHandle(_dag_name, _task_handle);*/
		return NULL;
	}
	return false;
}


bool PipelineManager::WriteReport()
{
	std::map<std::string, Pipeline*>::iterator  iter = m_mapPipeline.begin();
	for ( ;iter != m_mapPipeline.end();++iter)
	{
		iter->second->WriteReport(); 
	}
	return true;
}

TaskNode* PipelineManager::CreateNode(std::string node_type)
{
	auto it = m_nodeFuncMap.find(node_type);
	if (it == m_nodeFuncMap.end())
	{
		LOG(ERROR) << "CreateNode msg:%s is not defin" << node_type.c_str();
		return NULL;
	}
	return it->second();
}


void PipelineManager::Release()
{
	m_nodeFuncMap.clear();
}


bool PipelineManager::FilterInit()
{
	//m_mapKnowNode["RenewAsterAliModelHandler"] = "AliModelHandler";
	//m_mapKnowNode["Aster2dMaxHandler"] = "Aster2dMaxHandler";
	//m_mapKnowNode["AsterToVrayHandler"] = "AsterToVrayHandler";
	//m_mapKnowNode["ColorExtract"] = "ColorExtractHandler";
	//m_mapKnowNode["Deal2dHandler"] = "Deal2dHandler";
	//m_mapKnowNode["Deal3DHandler"] = "Deal3DHandler";
	//m_mapKnowNode["MaterialExtract"] = "MaterialExtractHandler";
	//m_mapKnowNode["MobileHandler"] = "MobileHandler";
	//m_mapKnowNode["ObjConvertHandler"] = "Obj2MaxHandler";
	//m_mapKnowNode["PreCheckHandler"] = "PreCheckHandler";
	//m_mapKnowNode["PreviewHandler"] = "PreviewHandler";
	//m_mapKnowNode["VrsceneHandler"] = "VrsceneHandler";
	//m_mapKnowNode["WriteWebT3dResourceHandler"] = "WriteWebT3dResourceHandler";
	//m_mapKnowNode["AssemblyModel2AuditIsoFront"] = "AssemblyModel2AuditIsoHandler";
	//m_mapKnowNode["AssemblyModel2Iso"] = "AssemblyModel2IsoHandler";
	//m_mapKnowNode["ColorExtract"] = "ColorExtractHandler";
	//m_mapKnowNode["Deal2dHandler"] = "Deal2dHandler";
	//m_mapKnowNode["Deal3DHandler"] = "Deal3DHandler";
	//m_mapKnowNode["gen-vray-material-package"] = "GenVrayMatPackageHandler";
	//m_mapKnowNode["Mat2IsoHandler"] = "Mat2IsoHandler";
	//m_mapKnowNode["MaxPackageCheckHandler"] = "MaxPackageCheckHandler";
	//m_mapKnowNode["MinifyWallfloor"] = "MinifyWallfloorHandler";
	//m_mapKnowNode["Model2AuditIsoBack"] = "Model2AuditIsoHandler";
	//m_mapKnowNode["Model2BigIso"] = "Model2BigIsoHandler";
	//m_mapKnowNode["Model2Ies"] = "Model2IesHandler";
	//m_mapKnowNode["Model2IsoFront"] = "Model2IsoHandler";
	//m_mapKnowNode["Model2ShapePicFront"] = "Model2ShapeHandler";
	//m_mapKnowNode["GenBigThumbnailSceneJson"] = "Multifacet2IsoHandler";
	//m_mapKnowNode["Initial2dMaterialParams"] = "Prepare2dMatParamsHandler";
	//m_mapKnowNode["Render2dIso"] = "Render2dIsoHandler";
	//m_mapKnowNode["Render4SceneJson"] = "Render4SceneJsonHandler";
	//m_mapKnowNode["SetMatParamsHandler"] = "SetMatParamsHandler";
	//m_mapKnowNode["SetObjInfoHandler"] = "SetObjInfoHandler";
	//m_mapKnowNode["SetWallfloor"] = "SetWallfloorHandler";
	//m_mapKnowNode["Shape2SvgFront"] = "shape2svg";
	//m_mapKnowNode["GenSmallTilingSceneJson"] = "Tiling2dIsoHandler";
	//m_mapKnowNode["Vrscene2BigIso"] = "Vrscene2BigIsoHandler";
	//m_mapKnowNode["WriteWebT3dResourceHandler"] = "WriteWebT3dResourceHandler";
	return true;
}

bool PipelineManager::RegisterInit()
{
	RegisterNodeFunc("simple", SimpleTaskNode::CreateNode);
	RegisterNodeFunc("msg", MessageNode::CreateNode);
	RegisterNodeFunc("sub_process", SubProcess::CreateNode);
	RegisterNodeFunc("any", AnyNode::CreateNode);
	RegisterNodeFunc("condition", ConditionNode::CreateNode);
	RegisterNodeFunc("api", ApiNode::CreateNode);
	return true;
}

void PipelineManager::RegisterNodeFunc(std::string type, NodeFunction func)
{
	m_nodeFuncMap.emplace(type, func);
}


void PipelineManager::TraversePath(std::string path)
{
	const std::filesystem::path rootPath(path);
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ rootPath })
		if (dir_entry.path().extension() == ".json") {
			std::string fileName = dir_entry.path().filename().replace_extension().string();

			std::string filePath = dir_entry.path().string();
			StrMapPair pairIter = m_mapPipelineName.insert(std::make_pair(fileName, filePath));
			if (!pairIter.second)
			{
				LOG(ERROR) << "CreatePipeline:: pipeline already exists:" << fileName<<" path:" << filePath;
			}
		}
}