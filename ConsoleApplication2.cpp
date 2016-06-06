// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"


//int main()
//{
  //  return 0;
//}

#include "stdafx.h"
#include <sapi.h>

int main(int argc, char* argv[])
{
	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr))
	{
		hr = pVoice->Speak(L"Здравствуйте", 0, NULL);

		// Change pitch
		hr = pVoice->Speak(L"Вы меня  <pitch middle = '-10'/> слышите?", SPF_IS_XML, NULL);
		pVoice->Release();
		pVoice = NULL;
	}
	::CoUninitialize();
	return TRUE;
}