#pragma once
#include "Singleton.h"
#include <map>
#include <vector>
#include "Util.h"
#include "TaskNode.h"

class Pipeline;
typedef struct _task_node
{
	std::string name;
	std::string path;
	std::string type;
	std::string comment;

}TASK_NODE;
class PipelineManager :public Singleton<PipelineManager>
{
public:

	PipelineManager();
	~PipelineManager();

	bool Init();

	bool ReadPath(const char* _file_path);

	bool GenPipeline();

	Pipeline* CreatePipeline(std::string  _file_path);

	bool FindPipelinePath(std::string& _file_name, std::string& _file_path);

	bool WriteReport();
	
	TaskNode* CreateNode(std::string _node_type);

	void Release();
private:
	bool FilterInit();

	bool RegisterInit();

	void RegisterNodeFunc(std::string node_type, NodeFunction);

	void TraversePath(std::string _path);
private:
	std::map<std::string, Pipeline*> m_mapPipeline;

	std::map<std::string,std::string>  m_mapKnowNode;

	std::map<std::string, TASK_NODE> m_mapUnknowNode;

	StrMap m_mapPipelineName;

	std::unordered_map<std::string, NodeFunction>  m_nodeFuncMap;
};
#define gPipelineInstance PipelineManager::GetInstance() 