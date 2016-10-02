// 20MinuteTimer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MicrobreakTimer.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	int messageBoxAlarm = IDOK;
	
	//int sleepTime = DialogBox(NULL, MAKEINTRESOURCE(ID_PASSWORD), NULL, DlgProc);
	ifstream friendFile;
	friendFile.open ("messages.txt");
	
	//if (friendFile.is_open())
	//{
		//cout << "File is open";
	//}

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
	return 0;
}