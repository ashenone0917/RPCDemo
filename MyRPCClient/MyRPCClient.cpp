// RPCTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <Windows.h>
#include <Shlwapi.h>
#include <string.h>
#include <stdio.h>

#pragma comment(lib,"ntdll.lib")

#include "..\RPC_IDL\hello_h.h"

#pragma comment(lib, "RpcRT4.lib")



BOOL RPCClientTest(void)
{
    BOOL bRet = FALSE;
    BOOL ExecFuncFailed = FALSE;
    RPC_STATUS status;
    RPC_BINDING_HANDLE TestBindingHandle = NULL;
    RPC_WSTR wcsUuid = NULL;

    WCHAR pszProtocolSequence[] = { L"ncalrpc" };
    WCHAR* pszNetworkAddress = NULL;
    WCHAR pszEndpoint[] = { L"MyFirstRPC" };
    WCHAR* pszOptions = NULL;


    RPC_WSTR pszStringBinding = NULL;
    CHAR pszString[] = {"123456789"};
    WCHAR wcsString[] = { L"12344321" };
    DWORD dwLen = (DWORD)strlen(pszString);
    status = RpcStringBindingComposeW(wcsUuid,
        (RPC_WSTR)pszProtocolSequence,
        (RPC_WSTR)pszNetworkAddress,
        (RPC_WSTR)pszEndpoint,
        (RPC_WSTR)pszOptions,
        &pszStringBinding);
    if (RPC_S_OK != status)
    {
        goto _FUNC_END;
    }

    status = RpcBindingFromStringBindingW(pszStringBinding, &TestBindingHandle);
    if (RPC_S_OK != status)
    {
        goto _FUNC_END;
    }

//    __try
//    {
        HelloProc(TestBindingHandle, (unsigned char *)pszString, wcsString, 0x87654321, 0x123456789ABCDEF0); 
//    }
 //   __except (1) {
//        goto _FUNC_END;
 //   }

    bRet = TRUE;
_FUNC_END:
    if (pszStringBinding)
    {
        RpcStringFreeW(&pszStringBinding);
    }
    if (TestBindingHandle)
    {
        RpcBindingFree(&TestBindingHandle);
    }


    return bRet;

}

int main()
{
    RPCClientTest();
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