// RPCServer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <windows.h>
#include <stdio.h>
#include "..\RPC_IDL\hello_h.h"
#pragma comment(lib, "RpcRT4.lib")
DWORD g_dwTimes = 0;
void HelloProc(RPC_BINDING_HANDLE prcHandle, unsigned char* psz, wchar_t* wcs, __int32 nCtx32, __int64 nCtx64)
{
    g_dwTimes = g_dwTimes + 1;
    printf("Time:%d String:%s wideString:%ls int32:0x%x int64:0x%I64x \r\n", g_dwTimes, psz, wcs, nCtx32, nCtx64);
}

void SrvStart(void)
{
    RPC_STATUS status;

    RPC_WSTR pszProtocolSequence = (RPC_WSTR)L"ncalrpc";
    RPC_WSTR pszSecurity = NULL;
    RPC_WSTR pszEndpoint = (RPC_WSTR)L"MyFirstRPC";

    unsigned int    cMinCalls = 1;
    unsigned int    fDontWait = FALSE;

    status = RpcServerUseProtseqEpW(pszProtocolSequence,
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        pszEndpoint,
        pszSecurity);

    if (status) exit(status);


    status = RpcServerRegisterIfEx(hello_v1_0_s_ifspec, NULL, NULL, RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH, RPC_C_LISTEN_MAX_CALLS_DEFAULT, NULL);

    if (status) exit(status);

    status = RpcServerListen(cMinCalls,
        RPC_C_LISTEN_MAX_CALLS_DEFAULT,
        fDontWait);

    if (status) exit(status);
}

int main()
{
    SrvStart();
}

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR* ptr)
{
    free(ptr);
}