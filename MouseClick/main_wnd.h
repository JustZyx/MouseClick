#pragma once
#define UILIB_STATIC
#include "..\DuiLib\UIlib.h"
using namespace DuiLib;
#include <ShellAPI.h>
#include "resource.h"

#define WM_MYMESSAGE WM_USER+101 //�����Զ�����Ϣ���ӵ����ֵһ�㶼Ҫ����100
#define WM_ONSHOW WM_USER+104 //�����Զ�����Ϣ���ӵ����ֵһ�㶼Ҫ����100
#define WM_ONCLOSE WM_USER+105 //�����Զ�����Ϣ���ӵ����ֵһ�㶼Ҫ����100

class CMainWnd : public WindowImplBase
{
public:
    virtual LPCTSTR GetWindowClassName() const;
    virtual CDuiString GetSkinFile();
    virtual CDuiString GetSkinFolder();
	virtual void InitWindow();
    virtual void Notify(TNotifyUI& msg);
    virtual LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
    virtual LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    virtual LRESULT HandleCustomMessage( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );

//����ѹ������Դ
public:
    virtual LPCTSTR GetResourceID() const;
	virtual UILIB_RESOURCETYPE GetResourceType() const;
    
public:
    void OnMin();
    void OnClose();
    void OnFeedback();
    void OnOfficialSite();

protected:
	NOTIFYICONDATA pnid;
	//CWHMenuCtrl* icon_rmenu_control_;	//�Ҽ��˵�
};


