// DuilibTutor.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "DuilibTutor.h"

using namespace DuiLib;
class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const	{ return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile()	{ return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder()	{ return _T(""); }
};
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIFRame"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();
	return 0;
}