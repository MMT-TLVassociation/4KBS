
// 4KGUIcpp.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMy4KGUIcppApp:
// このクラスの実装については、4KGUIcpp.cpp を参照してください
//

class CMy4KGUIcppApp : public CWinApp
{
public:
	CMy4KGUIcppApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMy4KGUIcppApp theApp;
