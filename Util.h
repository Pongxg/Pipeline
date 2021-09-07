#pragma once
#include <string>
#include "nlohmann/json.hpp"

enum _Task_Node
{
    TASK_MSG = 0, //消息节点类型
    TASK_API,//api节点类型
    TASK_SUB_PROCESS,//子流程节点类型
    TASK_CONDITION,//条件节点
    TASK_ANY,//any节点，任意上个节点流入即可以执行下一步，通常作为条件节点的结束节点
    TASK_SIMPLE,//简单节点类型，可以直接执行本地代码，类实现SimpleTaskHandler接口即可
};

struct FileNode
{
	std::string fileName;
	std::string filePath;
	std::string filePack;
	std::string replaceNode;
	std::string comment = "";
	std::vector<std::string> execPos;
};
struct Handler
{
	std::string name = "";
	std::string nodetype = "";
	std::string file_path = "";
	std::string package = "";
	std::string comment = "";
	bool bExecCmd = false;
};


typedef std::map<std::string, std::string> StrMap;
typedef StrMap::iterator StrMapIter;
typedef std::pair<StrMapIter, bool > StrMapPair;

typedef std::map<std::string, FileNode> FileNodeMap;
typedef FileNodeMap::iterator  FileNodeIter;
typedef std::pair<FileNodeIter, bool > FileNodePair;



bool UTF8ToUnicode(const std::string& s, std::wstring& result);

bool UnicodeToUTF8(const std::wstring& wstrValue, std::string& strRet);

std::string UnicodeToAscii(const std::wstring& wstr);

void ReplaceChar(std::vector<char>& str, const char old_char, const char new_char);

void ReplaceAll(std::string& str, const std::string& from,const std::string& to);

std::string ASCII2UTF_8(std::string& strAsciiCode);

std::string SanitizeString(std::string& label);