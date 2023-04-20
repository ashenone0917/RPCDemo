# RPCDemo
MyRPCServer project (x86 compilation) is the simplest RPC service program for getting started.

   MyRPCClient project (x86 compilation) is the simplest RPC client program, which sends HelloProc() request to MyRPCServer.
   
   The RPC_IDL project (x86 compilation) is only used to compile IDL files into STUB files.
   
   The RPCRunAdminProcess project (compiled in x86) is to create an administrator process through the RPC pop-up UAC window.
   
   MyRPCBreakPoint.txt is a windbg script file used to filter "interference items"
   
   Details on:https://bbs.kanxue.com/thread-276829.htm


**build order**
RPC_IDL->other
