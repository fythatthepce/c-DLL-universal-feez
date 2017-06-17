#include <iostream> 
#include <windows.h> 
#include <TlHelp32.h> 
#include <tchar.h>
#include <string>


DWORD dwGetModuleBaseAddress(DWORD dwProcessIdentifier, TCHAR *lpszModuleName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessIdentifier);
	DWORD dwModuleBaseAddress = 0;
	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 ModuleEntry32 = { 0 };
		ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &ModuleEntry32))
		{
			do
			{
				if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0)
				{
					dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnapshot, &ModuleEntry32));
		}
		CloseHandle(hSnapshot);
	}
	return dwModuleBaseAddress;
}



DWORD FindDmaAddy(int PointerLevel, HANDLE hProcHandle, DWORD Offsets[], DWORD BaseAddress)
{
	//DECLARE BASE ADDRESS
	DWORD pointer = BaseAddress;             // Declare a pointer of DWORD
	//USED TO output the contents in the pointer
	DWORD pTemp;

	DWORD pointerAddr;
	for (int i = 0; i < PointerLevel; i++)
	{
		if (i == 0)
		{
			ReadProcessMemory(hProcHandle, (LPCVOID)pointer, &pTemp, 4, NULL);
		}
		//add first offset to that address
		pointerAddr = pTemp + Offsets[i];   // Set p1 to content of p + offset

		//Read memory one more time and exit the loop
		ReadProcessMemory(hProcHandle, (LPCVOID)pointerAddr, &pTemp, 4, NULL);
	}
	return pointerAddr;
}

void WriteToMemory(DWORD addressToWrite, char* valueToWrite, int byteNum)
{
	//used to change our file access type, stores the old
	//access type and restores it after memory is written
	unsigned long OldProtection;
	//give that address read and write permissions and store the old permissions at oldProtection
	VirtualProtect((LPVOID)(addressToWrite), byteNum, PAGE_EXECUTE_READWRITE, &OldProtection);

	//write the memory into the program and overwrite previous value
	memcpy((LPVOID)addressToWrite, valueToWrite, byteNum);

	//reset the permissions of the address back to oldProtection after writting memory
	VirtualProtect((LPVOID)(addressToWrite), byteNum, OldProtection, NULL);
}



//1. GreenbaseAddress + offset + offset + ...   from cheat engine

//Unlimit Ammo
#define ADDR_BASE_AMMO 0x00509B74
#define AMMO_OFFSET1 0x0
#define AMMO_OFFSET2 0x14
#define AMMO_OFFSET3 0x374

void INC_AMMO()
{
   //multi offset
	DWORD AMMO_1 = (DWORD)(*(DWORD*)ADDR_BASE_AMMO + AMMO_OFFSET3);
	DWORD AMMO_2 = (DWORD)(*(DWORD*)AMMO_1 + AMMO_OFFSET2);
	*(DWORD*)(*(DWORD*)AMMO_2 + AMMO_OFFSET1) = 9999;   //value 9999

	//1 offset
	//*(DWORD*)(ADDR_BASE_AMMO + AMMO_OFFSET1) = 99999;

	Sleep(1);
}




//2. ["ac_client.exe" + 0010A280]  + offset + offset+ ....  from cheat engine

//HP >> "ac_client.exe" + 0010A280  offset   8  790  34  A4 488
void INC_HP()
{

	HWND window = FindWindow(NULL, _T("AssaultCube"));
	DWORD pID = 0;
	GetWindowThreadProcessId(window, &pID);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);


	//HP >> "ac_client.exe" + 0010A280  offset   8  790  34  A4 488
	DWORD baseAddr = dwGetModuleBaseAddress(pID, _T("ac_client.exe"));
	//DWORD baseAddr2 = dwGetModuleBaseAddress(pID, _T("client.dll"));

	int instance_handle_id = baseAddr;
	int Final_BaseAddr3 = instance_handle_id + 0x0010A280;
	DWORD HpOffsets[] = { 0x8, 0x790, 0x34, 0xA4, 0x488 };  //last to first offset from ce
	int Hp_value_offsets = 5;  //number of SmallOffsets[]
	int HpValue = 9999;

	DWORD AmmoAddressToWrite3 = FindDmaAddy(Hp_value_offsets, handle, HpOffsets, Final_BaseAddr3);
	WriteProcessMemory(handle, (BYTE*)AmmoAddressToWrite3, &HpValue, sizeof(HpValue), NULL);
	Sleep(1);
    //end

	
}
//End Unlimit HP

//3. asm Auto Fire from Ollydbg
DWORD Auto_ADD = 0x463716;
char AutoOpCode[] = "\xEB\x09";
char AutoDefaultOpCode[] = "\x75\x09";
int num_AutoOpCode = 2;
int num_AutoDefaultOpCode = 2;

void AUTO_FIRE_ON()
{
	WriteToMemory(Auto_ADD, AutoOpCode, num_AutoOpCode);
}

void AUTO_FIRE_OFF()
{
	WriteToMemory(Auto_ADD, AutoDefaultOpCode, num_AutoDefaultOpCode);
}
//End Autofire






void INC_BOMB()
{

	HWND window = FindWindow(NULL, _T("AssaultCube"));
	DWORD pID = 0;
	GetWindowThreadProcessId(window, &pID);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);


	//HP >> "ac_client.exe" + 0010A280  offset   8  790  34  A4 488
	DWORD baseAddr = dwGetModuleBaseAddress(pID, _T("ac_client.exe"));
	int instance_handle_id = baseAddr;
	int Final_BaseAddr3 = instance_handle_id + 0x00109B74;
	DWORD BOffsets[] = { 0x158 };  //last to first offset from ce
	int B_value_offsets = 1;  //number of SmallOffsets[]
	int BValue = 9999;

	DWORD AmmoAddressToWrite3 = FindDmaAddy(B_value_offsets, handle, BOffsets, Final_BaseAddr3);
	WriteProcessMemory(handle, (BYTE*)AmmoAddressToWrite3, &BValue, sizeof(BValue), NULL);
	Sleep(1);
}
//End Unlimit HP