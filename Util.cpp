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

void ReplaceChar(std::vector<char> &str,const char old_char, const char new_char)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == old_char)
		{
			str[i] = new_char;
		}
	}
 }    


void ReplaceAll(std::string& str, const std::string& from, const std::string& to) {
	if (from.empty())
		return;

	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
}


std::string SanitizeString(std::string& label) {
	// escape a double quote
	ReplaceAll(label, "\"", "\\\"");
	// newline -> \n
	ReplaceAll(label, "\n", "\\n");
	return label;
}
