#include "pch.h"
#include <iostream>
#include <Windows.h>

/*
  Name: Neko#8810
  Discord: https://discord.gg/TEttw3eS2b
  Github: https://github.com/Rustocia
  About Me: I am a programmer 13 years old
  Info: this dll base is just something simple so people can start making their first console cheat
*/

DWORD gameModule = (DWORD)GetModuleHandleA("Name.exe"); // change the Name.exe to whatever the process name is
DWORD localPlayer = *(DWORD*)(gameModule + 0x1234567890); // where the 0x1234567890 replace it with your local player

DWORD WINAPI MainThread(HMODULE hModule)
{
    AllocConsole(); // you can remove this if you do not want it to make a console on the game
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    while (true)
    {

      if (GetAsyncKeyState(VK_END) & 1)
      {
        fclose(f);
        FreeLibraryAndExitThread(hModule);
      }
      
    }

    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, hModule, NULL, NULL); // using createthread so we can use our mainthread to make the cheat
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
