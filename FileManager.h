#pragma once
#include "Singleton.h"
#include "Util.h"
#define PACK_COUNT 5
class FileManager :public Singleton<FileManager>
{
public:
	FileManager();
	~FileManager();

	bool ConfigueFilter();
	bool AddFileNode(std::string _name, std::string _node_name, bool filter, std::string comment, std::string pack = "t3d-material-fitting");
	bool Init();
	void TraversePath(std::string path, std::string pack,int id);
	void ReadFile(std::string filename, std::vector<std::string>& execCmds);
	FileNode* GetBindFile(std::string& classRef);
	FileNode* GetBindNodeFile(std::string node, std::string task_type);
	FileNode* GetBindFileNode(std::string node, std::string task_type);
private:

	FileNodeMap m_mapFileNodes;
	FileNodeMap m_mapFileFilterNodes;
};
#define gFileInstance FileManager::GetInstance() 