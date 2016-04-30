#pragma once

#define WIN32_LEAN_AND_MEAN	
#define _CRT_SECURE_NO_DEPRECATE

#include <windows.h>
#include <objbase.h>
#include "main_wnd.h"
#include <atlbase.h>
#include <atlapp.h>
#include <atluser.h>

#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "..\\lib\\DuiLib_ud.lib")
#   else
#       pragma comment(lib, "..\\lib\\DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "..\\lib\\DuiLib_u.lib")
#   else
#       pragma comment(lib, "..\\lib\\DuiLib.lib")
#   endif
#endif

#define WM_MYMESSAGE WM_USER+101 //�����Զ�����Ϣ���ӵ����ֵһ�㶼Ҫ����100
#define WM_ONSHOW WM_USER+104 //�����Զ�����Ϣ���ӵ����ֵһ�㶼Ҫ����100
#define WM_ONCLOSE WM_USER+105 //�����Զ�����Ϣ���ӵ����ֵһ�㶼Ҫ����100

LPCTSTR CMainWnd::GetWindowClassName() const {
    return _T("DUIMainFrame"); 
}
CDuiString CMainWnd::GetSkinFile() {   
    return _T("main.xml"); 
}
CDuiString CMainWnd::GetSkinFolder() {  
    return _T(""); 
}

void CMainWnd::Notify(TNotifyUI& msg){
    if( msg.sType == DUI_MSGTYPE_SELECTCHANGED ) {
        if(msg.pSender->GetName() == _T("mouse")) {
            CEditUI* edit1 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edit1")));
            CLabelUI* label1 = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("label1")));
            CComboUI* combo1 = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("combo1")));
            CComboUI* combo2 = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("combo2")));
            if(edit1 && label1 && combo1 && combo2){        
                edit1->SetBorderColor(RGB(167,220,183));
                edit1->SetTextColor(RGB(167,220,183));
                edit1->SetEnabled(0);
                label1->SetTextColor(RGB(167,220,183));
                combo1->SetSelectedItemTextColor(RGB(255,255,255));
                combo1->SetEnabled(1);
                combo2->SetSelectedItemTextColor(RGB(167,220,183));
                combo2->SetEnabled(0);
            }
        }
        else if(msg.pSender->GetName() == _T("fixed")) {
            CComboUI* combo3 = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("combo3")));
            CEditUI* edit2 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edit2")));
            CEditUI* edit3 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edit3")));
            CLabelUI* label3 = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("label3")));
            if(edit2 && edit3 && label3 && combo3) {
                label3->SetTextColor(RGB(167,220,183));
                combo3->SetSelectedItemTextColor(RGB(255,255,255));
                combo3->SetEnabled(1);
                edit2->SetEnabled(0);
                edit2->SetBorderColor(RGB(167,220,183));
                edit2->SetTextColor(RGB(167,220,183));
                edit3->SetEnabled(0);
                edit3->SetBorderColor(RGB(167,220,183));
                edit3->SetTextColor(RGB(167,220,183));
            }
        }
    }
    else if( msg.sType == DUI_MSGTYPE_CLICK ) {
        if( msg.pSender->GetName() == _T("closebtn") ) {
            OnClose();
        }
        else if( msg.pSender->GetName() == _T("minbtn")) {
            OnMin();
        }
        /*else if(msg.pSender->GetName() == _T("close")){
            OnClose();
        }*/
        else if(msg.pSender->GetName() == _T("feedback")) {
            OnFeedback();
        }
        else if(msg.pSender->GetName() == _T("officialsite")) {
            OnOfficialSite();
        }
        else if(msg.pSender->GetName() == _T("keyboard")) {
            CEditUI* edit1 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edit1")));
            CLabelUI* label1 = static_cast<CLabelUI*>(m_PaintManager.FindControl(_T("label1")));
            CComboUI* combo1 = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("combo1")));
            CComboUI* combo2 = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("combo2")));
            if(edit1 && label1 && combo1){        
                edit1->SetBorderColor(RGB(255,255,255));
                edit1->SetTextColor(RGB(255,255,255));
                edit1->SetEnabled(1);
                label1->SetTextColor(RGB(255,255,255));
                combo1->SetSelectedItemTextColor(RGB(167,220,183));
                combo1->SetEnabled(0);
                combo2->SetSelectedItemTextColor(RGB(255,255,255));
                combo2->SetEnabled(1);
            }
        }   
        else if(msg.pSender->GetName() == _T("random")) {
            CComboUI* combo3 = static_cast<CComboUI*>(m_PaintManager.FindControl(_T("combo3")));
            CEditUI* edit2 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edit2")));
            CEditUI* edit3 = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edit3")));
            if(edit2 && edit3 && combo3){
                combo3->SetSelectedItemTextColor(RGB(167,220,183));
                combo3->SetEnabled(0);
                edit2->SetEnabled(1);
                edit3->SetEnabled(1);
                edit2->SetTextColor(RGB(255,255,255));
                edit3->SetTextColor(RGB(255,255,255));
            }
        }
    }
}

void CMainWnd::InitWindow() {
    pnid.hIcon =::LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1) );       //ͼ����
    COptionUI* mouse = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("mouse")));
    mouse->Selected(true);
    COptionUI* fixed = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("fixed")));
    fixed->Selected(true);
}

LRESULT CMainWnd::OnDestroy( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled ) {
    LRESULT hr = __super::OnDestroy(uMsg, wParam, lParam, bHandled);
    ::PostQuitMessage(0);
    return hr;
}

LRESULT CMainWnd::OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {   
    bHandled = false;
	POINT pt = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };

	//�ƶ�ʱ�����״
	CControlUI* pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(pt));
	if (pControl && _tcscmp(pControl->GetClass(), _T("ControlUI")) == 0)
		::SetCursor(::LoadCursor(NULL, IDC_ARROW));
	else
		::SetCursor(::LoadCursor(NULL, IDC_ARROW));

	return 0;
}

LRESULT CMainWnd::HandleCustomMessage( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled ) {
    if (WM_LBUTTONDOWN == uMsg) {
		//�϶�����
		::SetCursor(::LoadCursor(NULL, IDC_ARROW));
    }
    //�����ͼ���е��������ԭ
    if( lParam == WM_LBUTTONDOWN ){             
		Shell_NotifyIcon(NIM_DELETE,&pnid);//ɾ������ͼ��
		ShowWindow(SW_SHOWNORMAL);//��ʾ������
	}
	if(lParam == WM_KILLFOCUS){
		int a = 0;
	}
    //�����ͼ���е����Ҽ��򵯳�����ʽ�˵�
	if( lParam == WM_RBUTTONDOWN ){             
		LPPOINT lpoint = new tagPOINT;  
		::GetCursorPos(lpoint);
		SetForegroundWindow(m_hWnd); //�һ�����ؿ���������һ������Ĳ˵���

		CMenu menu;  
		menu.CreatePopupMenu();  //��������һ������ʽ�˵�  
		menu.AppendMenu(MF_STRING,WM_ONSHOW,L"��ʾҳ��");
		menu.AppendMenu(MF_STRING,WM_ONCLOSE,L"�˳�");  

		//�˵���ʾ����Ļλ��
		menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x,lpoint->y+8,m_hWnd); 
		HMENU hmenu=menu.Detach();  
		menu.DestroyMenu();  
		delete lpoint;  
	}
    if(wParam == WM_ONSHOW){
		ShowWindow(SW_SHOWNORMAL);  //��ʾ������
	}
    if(wParam == WM_ONCLOSE){
        ::PostQuitMessage(0);
        Shell_NotifyIcon(NIM_DELETE,&pnid);
    }

    return __super::HandleCustomMessage(uMsg, wParam, lParam, bHandled);
}

LPCTSTR CMainWnd::GetResourceID() const{
	return MAKEINTRESOURCE(IDR_ZIPRES1);
};

UILIB_RESOURCETYPE CMainWnd::GetResourceType() const{ 
    return UILIB_ZIPRESOURCE; 
};

void CMainWnd::OnMin() {
    ::ShowWindow(m_hWnd, SW_MINIMIZE);
}

void CMainWnd::OnClose() {
    pnid.cbSize=sizeof(NOTIFYICONDATA);
    pnid.hIcon =::LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1) );
    pnid.hWnd=m_hWnd;
    lstrcpy(pnid.szTip,_T("NotifyIcon Test"));
    pnid.uCallbackMessage = WM_MYMESSAGE;
    pnid.uFlags=NIF_ICON | NIF_MESSAGE | NIF_TIP;
    Shell_NotifyIcon(NIM_ADD,&pnid);
    ShowWindow(SW_HIDE);
}

void CMainWnd::OnFeedback() {
    ShellExecute(m_hWnd, _T("open"), _T("http://www.shudaxia.com/#feedback"), NULL, NULL, SW_SHOW);
}

void CMainWnd::OnOfficialSite() {
    ShellExecute(m_hWnd, _T("open"), _T("http://www.shudaxia.com/"), NULL, NULL, SW_SHOW);
}