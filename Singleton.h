#pragma once
#include <memory>

template <typename T>
class Singleton
{
public:
	Singleton() {}

	static T *GetInstance()
	{
		if (m_pSingleton == NULL)
			m_pSingleton = new T();

		return m_pSingleton;
	}
	static T *m_pSingleton;
private:
	class GC
	{
	public:
		~GC()
		{
			if (m_pSingleton != NULL) {
				delete m_pSingleton;
				m_pSingleton = NULL;
			}
		}
		static GC gc;
	};
};
