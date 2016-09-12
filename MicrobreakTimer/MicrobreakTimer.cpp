// 20MinuteTimer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MicrobreakTimer.h"
#include <fstream>
#include <iostream>
#include <string>
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
	//ifstream friendFile("messages.txt");
	//friendFile.open;
	//string lines;
	//int numberOfLines = 0;

	//while (getline(friendFile, lines))
	//{
		//++numberOfLines;
	//}

	//int chosenLineNumber = rand() % numberOfLines;

	//for (int i = 0; i < chosenLineNumber; ++i)
		//getline(friendFile, lines);
	//getline(friendFile, lines);

	LPCWSTR messages[] = { L"You look really beautiful today. Why not give yourself a standing ovation?",
						   L"Remember to take a break and stretch.",
						   L"Your floor is feeling really lonely right now. Why not go visit the rest of it?",
						   L"Sometimes it helps to clear your head by taking a short walk. Why not right now?" };

	while (messageBoxAlarm == IDOK)
	{
		Sleep(1000);
		int chosenLineNumber = rand() % 4;
		LPCWSTR chosenLine = messages[chosenLineNumber];
		messageBoxAlarm = MessageBox(NULL, chosenLine, L"Microbreak Timer", MB_SETFOREGROUND | MB_ICONINFORMATION | MB_DEFBUTTON2 | MB_OKCANCEL);
	}
	return 0;
}