// RPCTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <Windows.h>
#include <Shlwapi.h>
#include <string.h>
#include <stdio.h>

#pragma comment(lib,"ntdll.lib")
#include"..\RPC_IDL\AppInfo_h.h"
#pragma comment(lib, "RpcRT4.lib")

BOOL RPCRunAdminProcess()
{
    BOOL bRet = FALSE;
    RPC_WSTR StringBinding = 0;
    RPC_BINDING_HANDLE UacBinding = 0;
    RPC_STATUS status;

    STARTUPINFOW* StartInfo = 0;
    WCHAR wcsExePath[] = { L"C:\\Windows\\system32\\notepad.exe" };
    WCHAR wcsParam[] = { L"\"C:\\Windows\\system32\\notepad.exe\" aabbcc.txt" };
    DWORD dwNumber = 0x11;
    DWORD dwNumber2 = 0x04080414;
    WCHAR wcsDir[] = L"D:\\data";
    WCHAR wcsDesktop[] = { L"WinSta0\\Default" };
    Struct_22_t Struct22;
    memset(&Struct22, 0, sizeof(Struct_22_t));
    Struct22.StructMember8 = 1;
    Struct22.StructMember9 = 5;
    DWORD64 dwNumber3 = 0;
    DWORD dwNumber4 = -1;
    PROCESS_INFORMATION ProcInfo;
    memset(&ProcInfo, 0, sizeof(PROCESS_INFORMATION));
    long nNumberOut = 6;

    status = RpcStringBindingComposeW((RPC_WSTR)L"201ef99a-7fa0-444c-9399-19ba84f12a1a", (RPC_WSTR)L"ncalrpc", 0i64, 0i64, 0i64, &StringBinding);
    if (RPC_S_OK != status)
    {
        goto _FUNC_END;
    }

    status = RpcBindingFromStringBindingW(StringBinding, &UacBinding);
    if (RPC_S_OK != status)
    {
        goto _FUNC_END;
    }
    
    __try
    {
        LaunchAdminProcess(UacBinding,
            wcsExePath, wcsParam,
            dwNumber, dwNumber2,
            wcsDir, wcsDesktop,
            &Struct22, dwNumber3, dwNumber4,
            (Struct_56_t*)&ProcInfo, &nNumberOut);
    }
    __except (1) {
        goto _FUNC_END;
    }
    if (ProcInfo.hThread)
    {
        ResumeThread(ProcInfo.hThread);
        CloseHandle(ProcInfo.hThread);
    }
    if (ProcInfo.hProcess)
    {
        CloseHandle(ProcInfo.hProcess);
    }

    bRet = TRUE;
_FUNC_END:
    if (StringBinding)
    {
        RpcStringFreeW(&StringBinding);
    }
    if (UacBinding)
    {
        RpcBindingFree(&UacBinding);
    }
    return bRet;
}
unsigned char pMapData[0x42] = {
    0x04, 0x00, 0x13, 0x00, 0x0D, 0x9A, 0xF9, 0x1E, 0x20, 0xA0, 0x7F, 0x4C, 0x44, 0x93, 0x99, 0x19,
    0xBA, 0x84, 0xF1, 0x2A, 0x1A, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x0D, 0x04, 0x5D,
    0x88, 0x8A, 0xEB, 0x1C, 0xC9, 0x11, 0x9F, 0xE8, 0x08, 0x00, 0x2B, 0x10, 0x48, 0x60, 0x02, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0C, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x02, 0x00,
    0x00, 0x00
};

int main()
{
    RPCRunAdminProcess();
    return 1;

}
void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR* ptr)
{
    free(ptr);
}