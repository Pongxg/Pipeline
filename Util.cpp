#include "Util.h"
#include<windows.h>

bool UTF8ToUnicode(const std::string& s,  std::wstring& result)
{
	int length = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, NULL, 0);
	wchar_t* buffer = new wchar_t[length];
	bool ret = false;
	int iRet = ::MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, buffer, length);
	if (iRet > 0) {
		result = buffer;
		ret = true;
	}
	delete[]buffer;
	return ret;
}

bool UnicodeToUTF8(const std::wstring& wstrValue, std::string& strRet)
{
	int length = WideCharToMultiByte(CP_UTF8, 0, wstrValue.data(), -1, NULL, 0, NULL, NULL);

	int length1 = wstrValue.length();
	char* buffer = new char[length];
	bool ret = false;
	int iRet = WideCharToMultiByte(CP_UTF8, 0, wstrValue.data(), -1, buffer, length, NULL, NULL);
	if (iRet > 0) {
		strRet = buffer;
		ret = true;
	}
	delete[]buffer;
	return ret;
}