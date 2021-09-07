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

std::string UnicodeToAscii(const std::wstring& wstr) {
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	char* pAssii = (char*)malloc(sizeof(char) * ansiiLen);
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);
	std::string ret_str = pAssii;
	free(pAssii);
	return ret_str;
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



std::wstring Acsi2WideByte(std::string& strascii)
{
	int widesize = MultiByteToWideChar(CP_ACP, 0, (char*)strascii.c_str(), -1, NULL, 0);
	if (widesize == ERROR_NO_UNICODE_TRANSLATION)
	{
		throw std::exception("Invalid UTF-8 sequence.");
	}
	if (widesize == 0)
	{
		throw std::exception("Error in conversion.");
	}
	std::vector<wchar_t> resultstring(widesize);
	int convresult = MultiByteToWideChar(CP_ACP, 0, (char*)strascii.c_str(), -1, &resultstring[0], widesize);


	if (convresult != widesize)
	{
		throw std::exception("La falla!");
	}

	return std::wstring(&resultstring[0]);
}

std::string Unicode2Utf8(const std::wstring& widestring)
{
	int utf8size = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, NULL, 0, NULL, NULL);
	if (utf8size == 0)
	{
		throw std::exception("Error in conversion.");
	}

	std::vector<char> resultstring(utf8size);

	int convresult = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, &resultstring[0], utf8size, NULL, NULL);

	if (convresult != utf8size)
	{
		throw std::exception("La falla!");
	}

	return std::string(&resultstring[0]);
}



std::string ASCII2UTF_8(std::string& strAsciiCode)
{
	std::string strRet("");
	//先把 ascii 转为 unicode  
	std::wstring wstr = Acsi2WideByte(strAsciiCode);
	//最后把 unicode 转为 utf8  
	strRet = Unicode2Utf8(wstr);
	return strRet;
}