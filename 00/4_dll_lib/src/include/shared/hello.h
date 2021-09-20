#ifndef __HELLO_H__
#define __HELLO_H__

// https://docs.microsoft.com/zh-cn/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-160
#ifdef HELLO_SHARED_DLL_EXPORTS
	#define DLL_API __declspec(dllexport)
#else
	#define DLL_API __declspec(dllimport)
#endif

extern "C" DLL_API class Hello
{
public:
	void print();
};

#endif