#pragma once
#include "Singleton.h"
#include <map>
#include <string>
#include <vector>

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

	bool ReadPath(std::string& filePath);

	bool GenPipeline();

	bool WriteReport();

private:
	std::map<std::string, Pipeline*> m_mapPipeline;
	std::map<std::string,std::string>  m_mapKnowNode;
	std::map<std::string, TASK_NODE> m_mapUnknowNode;

	std::vector<std::string> m_vecFullFileName;
};
#define gMaxContext MaxContext::GetInstance() 