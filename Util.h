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


typedef std::map<std::string, std::string> StrMap;
typedef StrMap::iterator StrMapIter;
typedef std::pair<StrMapIter, bool > StrMapPair;


bool UTF8ToUnicode(const std::string& s, std::wstring& result);

bool UnicodeToUTF8(const std::wstring& wstrValue, std::string& strRet);

void ReplaceChar(std::vector<char>& str, const char old_char, const char new_char);

void ReplaceAll(std::string& str, const std::string& from,const std::string& to);

std::string SanitizeString(std::string& label);