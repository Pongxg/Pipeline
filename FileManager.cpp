#include "FileManager.h"
#include <filesystem>
#include "easylogging++.h"
#define PACK_COUNT 6
std::string PACK_FILE[PACK_COUNT] = {"homestyler-model-agents","homestyler-transform-worker","t3d-cloud-platform","t3d-material-fitting","t3d-unify-scheduler","t3d-unify-scheduler" };
std::string PACK_FILE_PATH[PACK_COUNT] = {"D:\\InstallSource\\Pipeline\\bin\\SourceFile\\homestyler-model-agents","D:\\InstallSource\\Pipeline\\bin\\SourceFile\\homestyler-transform-worker",
"D:\\InstallSource\\Pipeline\\bin\\SourceFile\\t3d-cloud-platform" ,"D:\\InstallSource\\Pipeline\\bin\\SourceFile\\t3d-material-fitting" ,"D:\\InstallSource\\Pipeline\\bin\\SourceFile\\t3d-unify-scheduler",
"D:\\InstallSource\\Pipeline\\bin\\SourceFile"};
FileManager* Singleton<FileManager>::m_pSingleton = NULL;
FileManager::FileManager()
{

}

FileManager::~FileManager()
{

}

bool FileManager::Init()
{
	for (int i = PACK_COUNT-1; i < PACK_COUNT; ++i)
	{
		TraversePath(PACK_FILE_PATH[i], PACK_FILE[i]);
	}
	return true;
}


void FileManager::ReadFile(std::string filename,std::vector<std::string> & execCmds)
{
    std::string str;
    std::ifstream in(filename);
    char tempData[256] = { 0 };

	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, str);
			std::size_t found = str.find("Runtime.getRuntime().exec");
			if (found != std::string::npos)
			{
				std::string execStr = std::string("line:")+ std::to_string(__LINE__) + std::string(" func:") + __func__;
				execCmds.push_back(execStr);
			}
		}
	}
	return;
}

void FileManager::TraversePath(std::string path,std::string pack)
{
	std::vector<std::string> mapFiles;
	const std::filesystem::path rootPath(path);
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ rootPath })
		if (dir_entry.path().extension() == ".java") {

			std::string filePath = dir_entry.path().string();

			std::string fileName = dir_entry.path().filename().replace_extension().string();

			FileNode node;
			node.filePath = filePath;
			node.fileName = fileName;
			node.filePack = pack;
			ReadFile(filePath, node.execPos);
			mapFiles.push_back(filePath);
			FileNodePair pairIter = m_mapFileNodes.insert(std::make_pair(filePath, node));
			if (!pairIter.second)
			{
				LOG(ERROR) << "FileManager:: filename already exists:" << fileName << " path:" << filePath;
			}
		}
}
