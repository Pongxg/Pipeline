#pragma once
#include "Singleton.h"
#include "Util.h"
class FileManager :public Singleton<FileManager>
{
public:
	FileManager();
	~FileManager();

	bool Init();
	void TraversePath(std::string path, std::string pack);
	void ReadFile(std::string filename, std::vector<std::string>& execCmds);
private:

	FileNodeMap m_mapFileNodes;
};
#define gFileInstance FileManager::GetInstance() 