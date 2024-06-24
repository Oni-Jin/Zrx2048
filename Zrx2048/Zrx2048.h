// Zrx2048.h : main header file for the Zrx2048 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CZrx2048App
// See Zrx2048.cpp for the implementation of this class
//

class CZrx2048App : public CWinApp
{
public:
	CZrx2048App();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
