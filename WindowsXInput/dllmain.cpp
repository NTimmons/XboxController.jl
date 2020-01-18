// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <iostream>
#include <GamePad.h>
std::unique_ptr<DirectX::GamePad> m_gamePad;

#define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

EXTERN_DLL_EXPORT int Initialise(int a)
{
	m_gamePad = std::make_unique<DirectX::GamePad>();
	std::cout << "Created gamepad object...\n";
	m_gamePad->Resume();

	bool found = false;
	while (found == false)
	{
		auto state = m_gamePad->GetState(0);
		if (state.IsConnected())
		{
			std::cout << "Connected controller 0...\n";
			found = true;
		}
		Sleep(50);
	}

	m_gamePad->Suspend();
	std::cout << "Setup finished.\n";
	return 1;
}

EXTERN_DLL_EXPORT int BeginControllerInput(int a)
{
	m_gamePad->Resume();
	return 0;
}

EXTERN_DLL_EXPORT void EndControllerInput()
{
	m_gamePad->Suspend();
}

EXTERN_DLL_EXPORT DirectX::GamePad::State GetControllerState(int _controller)
{
	return m_gamePad->GetState(_controller);
}


