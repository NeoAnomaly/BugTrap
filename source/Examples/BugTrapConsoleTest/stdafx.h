// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <process.h>
#include <stdio.h>
#include <tchar.h>
#include <eh.h>                 // include set_terminate() declaration

// BugTrap includes //////////////////////////////////////////////////////////////

// Include main BugTrap header.
#include <BugTrap.h>

#define _QUOUTE(x) #x
#define _PASTE(x) x

#ifdef _UNICODE
#	define UNICODE_POSTFIX "U"
#else
#	define UNICODE_POSTFIX ""
#endif

#ifdef _DEBUG
#	define DEBUG_POSTFIX "D"
#else
#	define DEBUG_POSTFIX ""
#endif

#if defined _M_IX86
#	define ARCHITECTURE_POSTFIX ""
#elif defined _M_X64
#	define ARCHITECTURE_POSTFIX "-x64"
#else
#	error CPU architecture is not supported.
#endif

// Make BugTrap library name
#define BUGTRAP_LIB_NAME "BugTrap"##_PASTE(UNICODE_POSTFIX)##_PASTE(DEBUG_POSTFIX)##_PASTE(ARCHITECTURE_POSTFIX)##".lib"
#define LINK_WITH_MSG message("Link with: "##BUGTRAP_LIB_NAME)
#define LINK_WITH comment(lib, BUGTRAP_LIB_NAME)

// Link with one of BugTrap libraries.
#pragma LINK_WITH_MSG
#pragma LINK_WITH

// Enable Common Controls support

#if defined _M_IX86
 #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
 #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
 #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
 #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
