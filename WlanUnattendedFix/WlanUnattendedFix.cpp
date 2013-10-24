// WlanUnattendedFix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "regext.h"

int _tmain(int argc, _TCHAR* argv[])
{
	DWORD dwResuming = 4, dwSuspend = 4, dwUnattended = 4;
	RegistryGetDWORD(HKEY_LOCAL_MACHINE,	L"System\\CurrentControlSet\\Control\\Power\\State\\Resuming\\{98C5250D-C29A-4985-AE5F-AFE5367E5006}", 
											L"Default",
											&dwResuming);
	RegistryGetDWORD(HKEY_LOCAL_MACHINE,	L"System\\CurrentControlSet\\Control\\Power\\State\\Suspend\\{98C5250D-C29A-4985-AE5F-AFE5367E5006}", 
											L"Default",
											&dwSuspend);
	RegistryGetDWORD(HKEY_LOCAL_MACHINE,	L"System\\CurrentControlSet\\Control\\Power\\State\\Unattended\\{98C5250D-C29A-4985-AE5F-AFE5367E5006}", 
											L"Default",
											&dwUnattended);

	if (dwResuming == 0)
		dwResuming = 1;
	if (dwSuspend == 0)
		dwSuspend = 1;
	if (dwUnattended == 0)
		dwUnattended = 1;
	DWORD dwKeepWifi = 0;
	if (dwResuming == 1 && dwSuspend == 1 && dwUnattended == 1)
	{
		dwKeepWifi = 1;
	}
	RegistrySetDWORD(HKEY_LOCAL_MACHINE, L"Comm\\BCMSDDHD1\\Parms", L"HTCKeepWifiOnWhenUnattended", dwKeepWifi);
	return 0;
}

