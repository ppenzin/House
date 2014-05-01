#include <windows.h>
#include "errors.h"
#include "win32debug.h"
#include "finalizers.h"
#include "HsFFI.h"
extern UINT prim_gENERIC_NONE();
extern UINT prim_gENERIC_READ();
extern UINT prim_gENERIC_WRITE();
extern UINT prim_gENERIC_EXECUTE();
extern UINT prim_gENERIC_ALL();
extern UINT prim_dELETE();
extern UINT prim_rEAD_CONTROL();
extern UINT prim_wRITE_DAC();
extern UINT prim_wRITE_OWNER();
extern UINT prim_sYNCHRONIZE();
extern UINT prim_sTANDARD_RIGHTS_REQUIRED();
extern UINT prim_sTANDARD_RIGHTS_READ();
extern UINT prim_sTANDARD_RIGHTS_WRITE();
extern UINT prim_sTANDARD_RIGHTS_EXECUTE();
extern UINT prim_sTANDARD_RIGHTS_ALL();
extern UINT prim_sPECIFIC_RIGHTS_ALL();
extern UINT prim_aCCESS_SYSTEM_SECURITY();
extern UINT prim_mAXIMUM_ALLOWED();
extern UINT prim_fILE_SHARE_NONE();
extern UINT prim_fILE_SHARE_READ();
extern UINT prim_fILE_SHARE_WRITE();
extern UINT prim_cREATE_NEW();
extern UINT prim_cREATE_ALWAYS();
extern UINT prim_oPEN_EXISTING();
extern UINT prim_oPEN_ALWAYS();
extern UINT prim_tRUNCATE_EXISTING();
extern UINT prim_fILE_ATTRIBUTE_READONLY();
extern UINT prim_fILE_ATTRIBUTE_HIDDEN();
extern UINT prim_fILE_ATTRIBUTE_SYSTEM();
extern UINT prim_fILE_ATTRIBUTE_DIRECTORY();
extern UINT prim_fILE_ATTRIBUTE_ARCHIVE();
extern UINT prim_fILE_ATTRIBUTE_NORMAL();
extern UINT prim_fILE_ATTRIBUTE_TEMPORARY();
extern UINT prim_fILE_ATTRIBUTE_COMPRESSED();
extern UINT prim_fILE_FLAG_WRITE_THROUGH();
extern UINT prim_fILE_FLAG_OVERLAPPED();
extern UINT prim_fILE_FLAG_NO_BUFFERING();
extern UINT prim_fILE_FLAG_RANDOM_ACCESS();
extern UINT prim_fILE_FLAG_SEQUENTIAL_SCAN();
extern UINT prim_fILE_FLAG_DELETE_ON_CLOSE();
extern UINT prim_fILE_FLAG_BACKUP_SEMANTICS();
extern UINT prim_fILE_FLAG_POSIX_SEMANTICS();
extern UINT prim_sECURITY_ANONYMOUS();
extern UINT prim_sECURITY_IDENTIFICATION();
extern UINT prim_sECURITY_IMPERSONATION();
extern UINT prim_sECURITY_DELEGATION();
extern UINT prim_sECURITY_CONTEXT_TRACKING();
extern UINT prim_sECURITY_EFFECTIVE_ONLY();
extern UINT prim_sECURITY_SQOS_PRESENT();
extern UINT prim_sECURITY_VALID_SQOS_FLAGS();
extern DWORD prim_mOVEFILE_REPLACE_EXISTING();
extern DWORD prim_mOVEFILE_COPY_ALLOWED();
extern DWORD prim_mOVEFILE_DELAY_UNTIL_REBOOT();
extern DWORD prim_fILE_BEGIN();
extern DWORD prim_fILE_CURRENT();
extern DWORD prim_fILE_END();
extern UINT prim_dRIVE_UNKNOWN();
extern UINT prim_dRIVE_NO_ROOT_DIR();
extern UINT prim_dRIVE_REMOVABLE();
extern UINT prim_dRIVE_FIXED();
extern UINT prim_dRIVE_REMOTE();
extern UINT prim_dRIVE_CDROM();
extern UINT prim_dRIVE_RAMDISK();
extern DWORD prim_dDD_RAW_TARGET_PATH();
extern DWORD prim_dDD_REMOVE_DEFINITION();
extern DWORD prim_dDD_EXACT_MATCH_ON_REMOVE();
extern DWORD prim_sCS_32BIT_BINARY();
extern DWORD prim_sCS_DOS_BINARY();
extern DWORD prim_sCS_WOW_BINARY();
extern DWORD prim_sCS_PIF_BINARY();
extern DWORD prim_sCS_POSIX_BINARY();
extern DWORD prim_sCS_OS216_BINARY();
extern DWORD prim_fILE_NOTIFY_CHANGE_FILE_NAME();
extern DWORD prim_fILE_NOTIFY_CHANGE_DIR_NAME();
extern DWORD prim_fILE_NOTIFY_CHANGE_ATTRIBUTES();
extern DWORD prim_fILE_NOTIFY_CHANGE_SIZE();
extern DWORD prim_fILE_NOTIFY_CHANGE_LAST_WRITE();
extern DWORD prim_fILE_NOTIFY_CHANGE_SECURITY();
extern DWORD prim_fILE_TYPE_UNKNOWN();
extern DWORD prim_fILE_TYPE_DISK();
extern DWORD prim_fILE_TYPE_CHAR();
extern DWORD prim_fILE_TYPE_PIPE();
extern DWORD prim_fILE_TYPE_REMOTE();
extern void* prim_deleteFile(char * arg1);
extern int access_prim_deleteFile_gc_failed(HsPtr);
extern void* access_prim_deleteFile_gc_failstring(HsPtr);
extern void* prim_copyFile(char * arg1,char * arg2,int arg3);
extern int access_prim_copyFile_gc_failed(HsPtr);
extern void* access_prim_copyFile_gc_failstring(HsPtr);
extern void* prim_moveFile(char * arg1,char * arg2);
extern int access_prim_moveFile_gc_failed(HsPtr);
extern void* access_prim_moveFile_gc_failstring(HsPtr);
extern void* prim_moveFileEx(char * arg1,char * arg2,DWORD arg3);
extern int access_prim_moveFileEx_gc_failed(HsPtr);
extern void* access_prim_moveFileEx_gc_failstring(HsPtr);
extern void* prim_setCurrentDirectory(char * arg1);
extern int access_prim_setCurrentDirectory_gc_failed(HsPtr);
extern void* access_prim_setCurrentDirectory_gc_failstring(HsPtr);
extern void* prim_createDirectory(char * arg1,void * arg2);
extern int access_prim_createDirectory_gc_failed(HsPtr);
extern void* access_prim_createDirectory_gc_failstring(HsPtr);
extern void* prim_createDirectoryEx(char * arg1,char * arg2,void * arg3);
extern int access_prim_createDirectoryEx_gc_failed(HsPtr);
extern void* access_prim_createDirectoryEx_gc_failstring(HsPtr);
extern void* prim_removeDirectory(char * arg1);
extern int access_prim_removeDirectory_gc_failed(HsPtr);
extern void* access_prim_removeDirectory_gc_failstring(HsPtr);
extern void* prim_getBinaryType(char * arg1);
extern DWORD access_prim_getBinaryType_res1(HsPtr);
extern int access_prim_getBinaryType_gc_failed(HsPtr);
extern void* access_prim_getBinaryType_gc_failstring(HsPtr);
extern void* prim_createFile(char * arg1,UINT arg2,UINT arg3,void * arg4,UINT arg5,UINT arg6,HANDLE arg7);
extern HANDLE access_prim_createFile_res1(HsPtr);
extern int access_prim_createFile_gc_failed(HsPtr);
extern void* access_prim_createFile_gc_failstring(HsPtr);
extern void* prim_closeHandle(HANDLE arg1);
extern int access_prim_closeHandle_gc_failed(HsPtr);
extern void* access_prim_closeHandle_gc_failstring(HsPtr);
extern DWORD prim_getFileType(HANDLE arg1);
extern void* prim_flushFileBuffers(HANDLE arg1);
extern int access_prim_flushFileBuffers_gc_failed(HsPtr);
extern void* access_prim_flushFileBuffers_gc_failstring(HsPtr);
extern void* prim_setEndOfFile(HANDLE arg1);
extern int access_prim_setEndOfFile_gc_failed(HsPtr);
extern void* access_prim_setEndOfFile_gc_failstring(HsPtr);
extern void* prim_setFileAttributes(char * arg1,UINT arg2);
extern int access_prim_setFileAttributes_gc_failed(HsPtr);
extern void* access_prim_setFileAttributes_gc_failstring(HsPtr);
extern void* prim_getFileAttributes(char * arg1);
extern UINT access_prim_getFileAttributes_res1(HsPtr);
extern int access_prim_getFileAttributes_gc_failed(HsPtr);
extern void* access_prim_getFileAttributes_gc_failstring(HsPtr);
extern void* prim_win32_ReadFile(HANDLE arg1,void * arg2,DWORD arg3,LPOVERLAPPED arg4);
extern DWORD access_prim_win32_ReadFile_res1(HsPtr);
extern int access_prim_win32_ReadFile_gc_failed(HsPtr);
extern void* access_prim_win32_ReadFile_gc_failstring(HsPtr);
extern void* prim_win32_WriteFile(HANDLE arg1,void * arg2,DWORD arg3,LPOVERLAPPED arg4);
extern DWORD access_prim_win32_WriteFile_res1(HsPtr);
extern int access_prim_win32_WriteFile_gc_failed(HsPtr);
extern void* access_prim_win32_WriteFile_gc_failstring(HsPtr);
extern void* prim_findFirstChangeNotification(char * arg1,int arg2,DWORD arg3);
extern HANDLE access_prim_findFirstChangeNotification_res1(HsPtr);
extern int access_prim_findFirstChangeNotification_gc_failed(HsPtr);
extern void* access_prim_findFirstChangeNotification_gc_failstring(HsPtr);
extern void* prim_findNextChangeNotification(HANDLE arg1);
extern int access_prim_findNextChangeNotification_gc_failed(HsPtr);
extern void* access_prim_findNextChangeNotification_gc_failstring(HsPtr);
extern void* prim_findCloseChangeNotification(HANDLE arg1);
extern int access_prim_findCloseChangeNotification_gc_failed(HsPtr);
extern void* access_prim_findCloseChangeNotification_gc_failstring(HsPtr);
extern void* prim_defineDosDevice(DWORD arg1,char * arg2,char * arg3);
extern int access_prim_defineDosDevice_gc_failed(HsPtr);
extern void* access_prim_defineDosDevice_gc_failstring(HsPtr);
extern int prim_areFileApisANSI();
extern void prim_setFileApisToOEM();
extern void prim_setFileApisToANSI();
extern UINT prim_setHandleCount(UINT arg1);
extern void* prim_getLogicalDrives();
extern DWORD access_prim_getLogicalDrives_res1(HsPtr);
extern int access_prim_getLogicalDrives_gc_failed(HsPtr);
extern void* access_prim_getLogicalDrives_gc_failstring(HsPtr);
extern void* prim_getDiskFreeSpace(char * s);
extern DWORD access_prim_getDiskFreeSpace_res1(HsPtr);
extern DWORD access_prim_getDiskFreeSpace_res2(HsPtr);
extern DWORD access_prim_getDiskFreeSpace_res3(HsPtr);
extern DWORD access_prim_getDiskFreeSpace_res4(HsPtr);
extern int access_prim_getDiskFreeSpace_gc_failed(HsPtr);
extern void* access_prim_getDiskFreeSpace_gc_failstring(HsPtr);
extern void* prim_setVolumeLabel(char * arg1,char * arg2);
extern int access_prim_setVolumeLabel_gc_failed(HsPtr);
extern void* access_prim_setVolumeLabel_gc_failstring(HsPtr);