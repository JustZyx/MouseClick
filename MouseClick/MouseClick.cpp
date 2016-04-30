#pragma once
#include "stdafx.h"
#include "main_wnd.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
    CPaintManagerUI::SetInstance(hInstance);
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

    CMainWnd* pFrame = new CMainWnd();
    if( pFrame == NULL ) return 0;
    pFrame->Create(NULL, _T("Êó±êÁ¬µãÆ÷"), UI_WNDSTYLE_DIALOG | WS_MINIMIZEBOX,  WS_EX_WINDOWEDGE);
    //pFrame->SetIcon(IDR_MAINFRAME);
    pFrame->ShowWindow(true);
    pFrame->CenterWindow();
    pFrame->ShowModal();
    CPaintManagerUI::MessageLoop();

    return 0;
}
