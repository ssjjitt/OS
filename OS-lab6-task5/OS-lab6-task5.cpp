﻿#include <iostream>
#include <Windows.h>

using namespace std;

PROCESS_INFORMATION createProcess(LPCWSTR path)
{
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;

	ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
	startupInfo.cb = sizeof(STARTUPINFO);

	if (CreateProcessW(path, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &startupInfo, &processInfo))
		cout << "Process created.\n";
	else
		cout << "Error CreateProcessW\n";

	return processInfo;
}


int main()
{
	int pid = GetCurrentProcessId();
	const int size = 2;
	HANDLE event;
	HANDLE processes[size];

	processes[0] = createProcess(L"D:\\univer\\!ОС\\OS-lab6\\x64\\Debug\\OS-lab6-task5-A.exe").hProcess;
	processes[1] = createProcess(L"D:\\univer\\!ОС\\OS-lab6\\x64\\Debug\\OS-lab6-task5-B.exe").hProcess;

	event = CreateEvent(NULL, FALSE, FALSE, L"OS-lab6-task5");

	for (int i = 1; i <= 90; i++)
	{
		if (i == 15)
			SetEvent(event);

		printf("6-5 %d. PID = %d\n", i, pid);
		Sleep(100);
	}

	WaitForMultipleObjects(size, processes, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
		CloseHandle(processes[i]);

	CloseHandle(event);
	system("pause");
	return 0;
}