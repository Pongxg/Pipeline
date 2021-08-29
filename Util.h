#pragma once
#include <string>
#include "nlohmann/json.hpp"

enum _Task_Node
{
    TASK_MSG = 0, //��Ϣ�ڵ�����
    TASK_API,//api�ڵ�����
    TASK_SUB_PROCESS,//�����̽ڵ�����
    TASK_CONDITION,//�����ڵ�
    TASK_ANY,//any�ڵ㣬�����ϸ��ڵ����뼴����ִ����һ����ͨ����Ϊ�����ڵ�Ľ����ڵ�
    TASK_SIMPLE,//�򵥽ڵ����ͣ�����ֱ��ִ�б��ش��룬��ʵ��SimpleTaskHandler�ӿڼ���
};


typedef std::map<std::string, std::string> StrMap;
typedef StrMap::iterator StrMapIter;
typedef std::pair<StrMapIter, bool > StrMapPair;


bool UTF8ToUnicode(const std::string& s, std::wstring& result);

bool UnicodeToUTF8(const std::wstring& wstrValue, std::string& strRet);

void ReplaceChar(std::vector<char>& str, const char old_char, const char new_char);

void ReplaceAll(std::string& str, const std::string& from,const std::string& to);

std::string SanitizeString(std::string& label);