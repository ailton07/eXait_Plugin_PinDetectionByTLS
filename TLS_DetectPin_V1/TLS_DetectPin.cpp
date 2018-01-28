// TLS_Check_V2.cpp : Defines the entry point for the console application.
//

#include <windows.h> 
#include <stdio.h> 

#define _LIMIAR 3

// ---------- start of eXait header modifications
#define DllExport extern "C" __declspec(dllexport)
DllExport char* GetPluginName(void);
DllExport char* GetPluginDescription(void);
DllExport int DoMyJob(void);

char* GetPluginName(void)
{
	static char PluginName[] = "Detect Pin by TLS";
	return PluginName;
}

char* GetPluginDescription(void)
{
	static char MyDescription[] = "This plugin implements a search function to search for TLS entries.";
	return MyDescription;
}
// ---------- end of eXait header modifications


VOID ErrorExit (LPSTR lpszMessage) 
{ 
	fprintf(stderr, "%s\n", lpszMessage); 
	ExitProcess(0); 
}

int count32tls()
{
	printf("\t== count32tls ==\n");
	int quantidade = 0;
	DWORD dwTlsIndex;
	LPVOID lpvData; 
	int value;

	for(dwTlsIndex = 0; dwTlsIndex < 32; dwTlsIndex++)
	{

		lpvData = TlsGetValue(dwTlsIndex);
		value = reinterpret_cast<int>(lpvData);

		// printf("TLS[%d] = lpvData=%lx\n", dwTlsIndex, value);
		if(value != 0) {
			quantidade++;
			// printf("TLS[%d] = lpvData igual a zero\n", dwTlsIndex);
		}

	}
	return quantidade;
}

int DoMyJob(void)
{
	int quantidade = 0;

	quantidade = count32tls();

	printf("Quantidade de slots do TLS ativos: %d\n", quantidade);

	if(quantidade > _LIMIAR)
	{
		printf("PIN DETECTED\n");
		return 1;
	}
	else
	{
		printf("Pin not detected\n");
		return 0;
	}

	//system("pause");
	return 0;
}

//int main()
//{
//	int quantidade = 0;
//
//	quantidade = count32tls();
//
//	printf("Quantidade de slots do TLS ativos: %d\n", quantidade);
//
//	if(quantidade > _LIMIAR)
//		printf("PIN DETECTED\n");
//	else
//		printf("Pin not detected\n");
//
//	system("pause");
//	return 0;
//}

