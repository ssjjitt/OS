﻿#include <iostream>
#include <Windows.h>


int main()
{
	int pid = GetCurrentProcessId();
	HANDLE semaphore = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, L"OS-lab6-task4");

	for (int i = 0; i < 90; i++)
	{
		if (i == 30)
			WaitForSingleObject(semaphore, INFINITE);

		else if (i == 60)
			ReleaseSemaphore(semaphore, 1, NULL);


		printf("6-4-A %d. PID = %d\n", i, pid);
		Sleep(100);
	}

	CloseHandle(semaphore);
	system("pause");
	return 0;
}