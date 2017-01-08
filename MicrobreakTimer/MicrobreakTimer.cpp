// 20MinuteTimer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MicrobreakTimer.h"
#include "shellapi.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define WM_MYMESSAGE (WM_APP + 1)

using namespace std;

void RunMessagePump()
{
    MSG queuedMessage;
    for (;;)
    {
        const BOOL wasMessagePresent = PeekMessage(&queuedMessage, NULL, 0, 0, PM_REMOVE);
        if (!wasMessagePresent)
        {
            break;
        }

        TranslateMessage(&queuedMessage);
        DispatchMessage(&queuedMessage);
    }
}


LRESULT CALLBACK WindowsMessageHandlingProcedure(HWND windowHandle, UINT wmMessageCode, WPARAM wParam, LPARAM lParam)
{
    unsigned char asKey = (unsigned char)wParam;
    switch (wmMessageCode)
    {
    case WM_CREATE:
        break;
    case WM_MYMESSAGE:
        switch (lParam)
        {
        case WM_LBUTTONDBLCLK:
            MessageBox(NULL, L"Tray icon double clicked!", L"clicked", MB_OK);
            break;
        default:
            return DefWindowProc(windowHandle, wmMessageCode, wParam, lParam);
        };
        break;
    default:
        return DefWindowProc(windowHandle, wmMessageCode, wParam, lParam);
    }

}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    NOTIFYICONDATA notificationData;
    notificationData.cbSize = sizeof(NOTIFYICONDATA);
    notificationData.hWnd = NULL;
    notificationData.uID = 100;
    notificationData.uVersion = NOTIFYICON_VERSION;
    notificationData.uCallbackMessage = WM_MYMESSAGE;
    notificationData.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcscpy_s(notificationData.szTip, L"Tray Icon");
    notificationData.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;

    Shell_NotifyIcon(NIM_ADD, &notificationData);

	int messageBoxAlarm = IDOK;
	
	//int sleepTime = DialogBox(NULL, MAKEINTRESOURCE(ID_PASSWORD), NULL, DlgProc);
	ifstream friendFile;
	friendFile.open ("messages.txt");
	
	if (friendFile.fail())
	{
		MessageBox(NULL, L"Could not find file \"messages.txt\"", L"Error", MB_SETFOREGROUND | MB_ICONERROR | MB_DEFBUTTON2 | MB_OK);
	}
	else
	{
		string lines = "";
		int numberOfLines = 0;

		std::vector<std::wstring> messages;

		while (getline(friendFile, lines))
		{
			wstring wideLine = wstring(lines.begin(), lines.end());
			LPCWSTR line = wideLine.c_str();
			messages.push_back(line);
			numberOfLines++;
		}

		while (messageBoxAlarm == IDOK)
		{
			Sleep(1000);
			int chosenLineNumber = rand() % numberOfLines;
			LPCWSTR chosenLine = messages[chosenLineNumber].c_str();
			messageBoxAlarm = MessageBox(NULL, chosenLine, L"Microbreak Timer", MB_SETFOREGROUND | MB_ICONINFORMATION | MB_DEFBUTTON2 | MB_OKCANCEL);
		}
	}

	return 0;
}