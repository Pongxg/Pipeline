#pragma once
#include "Singleton.h"
#include "csv2.h"
#include <vector>
class ContextManager :public Singleton<ContextManager>
{
public:
	ContextManager();
	~ContextManager();

	bool WriteReport(std::string name);
private:
	std::vector<std::vector<std::string>> m_vecOutputs;
};

#define gContextInstance ContextManager::GetInstance() 