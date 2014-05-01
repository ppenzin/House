#include <windows.h>
#include "errors.h"
#include "win32debug.h"
#include "finalizers.h"
#include "HsFFI.h"
extern void prim_copyMemory(void * arg1,void * arg2,DWORD arg3);
extern void prim_fillMemory(void * arg1,DWORD arg2,BYTE arg3);
extern HANDLE prim_getProcessHeap();
extern DWORD prim_getProcessHeaps(DWORD arg1,void * arg2);
extern UINT prim_gMEM_FIXED();
extern UINT prim_gMEM_MOVEABLE();
extern UINT prim_gPTR();
extern UINT prim_gHND();
extern UINT prim_gMEM_DDESHARE();
extern UINT prim_gMEM_SHARE();
extern UINT prim_gMEM_LOWER();
extern UINT prim_gMEM_NOCOMPACT();
extern UINT prim_gMEM_NODISCARD();
extern UINT prim_gMEM_NOT_BANKED();
extern UINT prim_gMEM_NOTIFY();
extern UINT prim_gMEM_ZEROINIT();
extern void* prim_globalAlloc(UINT arg1,DWORD arg2);
extern HGLOBAL access_prim_globalAlloc_res1(HsPtr);
extern int access_prim_globalAlloc_gc_failed(HsPtr);
extern void* access_prim_globalAlloc_gc_failstring(HsPtr);
extern void* prim_globalFlags(HGLOBAL arg1);
extern UINT access_prim_globalFlags_res1(HsPtr);
extern int access_prim_globalFlags_gc_failed(HsPtr);
extern void* access_prim_globalFlags_gc_failstring(HsPtr);
extern void* prim_globalFree(HGLOBAL arg1);
extern HGLOBAL access_prim_globalFree_res1(HsPtr);
extern int access_prim_globalFree_gc_failed(HsPtr);
extern void* access_prim_globalFree_gc_failstring(HsPtr);
extern void* prim_globalHandle(void * arg1);
extern HGLOBAL access_prim_globalHandle_res1(HsPtr);
extern int access_prim_globalHandle_gc_failed(HsPtr);
extern void* access_prim_globalHandle_gc_failstring(HsPtr);
extern void* prim_globalLock(HGLOBAL arg1);
extern void * access_prim_globalLock_res1(HsPtr);
extern int access_prim_globalLock_gc_failed(HsPtr);
extern void* access_prim_globalLock_gc_failstring(HsPtr);
extern void* prim_globalReAlloc(HGLOBAL arg1,DWORD arg2,UINT arg3);
extern HGLOBAL access_prim_globalReAlloc_res1(HsPtr);
extern int access_prim_globalReAlloc_gc_failed(HsPtr);
extern void* access_prim_globalReAlloc_gc_failstring(HsPtr);
extern void* prim_globalSize(HGLOBAL arg1);
extern DWORD access_prim_globalSize_res1(HsPtr);
extern int access_prim_globalSize_gc_failed(HsPtr);
extern void* access_prim_globalSize_gc_failstring(HsPtr);
extern void* prim_globalUnlock(HGLOBAL arg1);
extern int access_prim_globalUnlock_gc_failed(HsPtr);
extern void* access_prim_globalUnlock_gc_failstring(HsPtr);
extern DWORD prim_hEAP_GENERATE_EXCEPTIONS();
extern DWORD prim_hEAP_NO_SERIALIZE();
extern DWORD prim_hEAP_ZERO_MEMORY();
extern void* prim_heapAlloc(HANDLE arg1,DWORD arg2,DWORD arg3);
extern void * access_prim_heapAlloc_res1(HsPtr);
extern int access_prim_heapAlloc_gc_failed(HsPtr);
extern void* access_prim_heapAlloc_gc_failstring(HsPtr);
extern void* prim_heapCompact(HANDLE arg1,DWORD arg2);
extern UINT access_prim_heapCompact_res1(HsPtr);
extern int access_prim_heapCompact_gc_failed(HsPtr);
extern void* access_prim_heapCompact_gc_failstring(HsPtr);
extern void* prim_heapCreate(DWORD arg1,DWORD arg2,DWORD arg3);
extern HANDLE access_prim_heapCreate_res1(HsPtr);
extern int access_prim_heapCreate_gc_failed(HsPtr);
extern void* access_prim_heapCreate_gc_failstring(HsPtr);
extern void* prim_heapDestroy(HANDLE arg1);
extern int access_prim_heapDestroy_gc_failed(HsPtr);
extern void* access_prim_heapDestroy_gc_failstring(HsPtr);
extern void* prim_heapFree(HANDLE arg1,DWORD arg2,void * arg3);
extern int access_prim_heapFree_gc_failed(HsPtr);
extern void* access_prim_heapFree_gc_failstring(HsPtr);
extern void* prim_heapLock(HANDLE arg1);
extern int access_prim_heapLock_gc_failed(HsPtr);
extern void* access_prim_heapLock_gc_failstring(HsPtr);
extern void* prim_heapReAlloc(HANDLE arg1,DWORD arg2,void * arg3,DWORD arg4);
extern void * access_prim_heapReAlloc_res1(HsPtr);
extern int access_prim_heapReAlloc_gc_failed(HsPtr);
extern void* access_prim_heapReAlloc_gc_failstring(HsPtr);
extern void* prim_heapSize(HANDLE arg1,DWORD arg2,void * arg3);
extern DWORD access_prim_heapSize_res1(HsPtr);
extern int access_prim_heapSize_gc_failed(HsPtr);
extern void* access_prim_heapSize_gc_failstring(HsPtr);
extern void* prim_heapUnlock(HANDLE arg1);
extern int access_prim_heapUnlock_gc_failed(HsPtr);
extern void* access_prim_heapUnlock_gc_failstring(HsPtr);
extern int prim_heapValidate(HANDLE arg1,DWORD arg2,void * arg3);
extern void prim_moveMemory(void * arg1,void * arg2,DWORD arg3);
extern DWORD prim_mEM_COMMIT();
extern DWORD prim_mEM_RESERVE();
extern DWORD prim_pAGE_READONLY();
extern DWORD prim_pAGE_READWRITE();
extern DWORD prim_pAGE_EXECUTE();
extern DWORD prim_pAGE_EXECUTE_READ();
extern DWORD prim_pAGE_EXECUTE_READWRITE();
extern DWORD prim_pAGE_GUARD();
extern DWORD prim_pAGE_NOACCESS();
extern DWORD prim_pAGE_NOCACHE();
extern DWORD prim_mEM_DECOMMIT();
extern DWORD prim_mEM_RELEASE();
extern void* prim_virtualAlloc(void * arg1,DWORD arg2,DWORD arg3,DWORD arg4);
extern void * access_prim_virtualAlloc_res1(HsPtr);
extern int access_prim_virtualAlloc_gc_failed(HsPtr);
extern void* access_prim_virtualAlloc_gc_failstring(HsPtr);
extern void* prim_virtualFree(void * arg1,DWORD arg2,DWORD arg3);
extern int access_prim_virtualFree_gc_failed(HsPtr);
extern void* access_prim_virtualFree_gc_failstring(HsPtr);
extern void* prim_virtualLock(void * arg1,DWORD arg2);
extern int access_prim_virtualLock_gc_failed(HsPtr);
extern void* access_prim_virtualLock_gc_failstring(HsPtr);
extern void* prim_virtualProtect(void * arg1,DWORD arg2,DWORD arg3);
extern int access_prim_virtualProtect_gc_failed(HsPtr);
extern void* access_prim_virtualProtect_gc_failstring(HsPtr);
extern void* prim_virtualProtectEx(HANDLE arg1,void * arg2,DWORD arg3,DWORD arg4,void * arg5);
extern int access_prim_virtualProtectEx_gc_failed(HsPtr);
extern void* access_prim_virtualProtectEx_gc_failstring(HsPtr);
extern void* prim_virtualUnlock(void * arg1,DWORD arg2);
extern int access_prim_virtualUnlock_gc_failed(HsPtr);
extern void* access_prim_virtualUnlock_gc_failstring(HsPtr);
extern void prim_zeroMemory(void * arg1,DWORD arg2);