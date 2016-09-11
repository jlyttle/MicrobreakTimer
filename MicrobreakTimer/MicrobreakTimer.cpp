// 20MinuteTimer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MicrobreakTimer.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	int messageBoxAlarm = IDOK;
	
	while (messageBoxAlarm == IDOK)
	{
		Sleep(1000);
		messageBoxAlarm = MessageBox(NULL, L"Remember to take a break and stretch", L"Microbreak Reminder", MB_SETFOREGROUND | MB_ICONINFORMATION | MB_DEFBUTTON2 | MB_OKCANCEL);
	}
	return 0;
}