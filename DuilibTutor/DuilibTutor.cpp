// DuilibTutor.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "DuilibTutor.h"

using namespace DuiLib;

class CDuiFrameWind :public CWindowWnd,
	public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName()const{
		return _T("DUIMainFrame");
	}
	virtual void Notify(TNotifyUI& msg){
		if (msg.sType == _T("click")){
			if (msg.pSender->GetName() == _T("btnHello")){
				::MessageBox(NULL, _T("I am a button"), _T("click the button"), NULL);
			}
		}
	}
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam,
		LPARAM lParam){
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE){
			CControlUI* pWnd = new CButtonUI;
			pWnd->SetName(_T("btnHello"));
			pWnd->SetText(_T("Hello World"));
			pWnd->SetBkColor(0xFF00FF00);

			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			m_PaintManager.AddNotifier(this);
			return lRes;
		}
		else if (uMsg == WM_NCACTIVATE){
			if (!::IsIconic(m_hWnd)){
				return(wParam == 0) ? TRUE : FALSE;
			}
		}
		else if (uMsg == WM_NCCALCSIZE){
			return 0;
		}
		else if (uMsg == WM_NCPAINT){
			return 0;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes)){
			return lRes;
		}
		return __super::HandleMessage(uMsg, wParam, lParam);
	}
private:
	CPaintManagerUI m_PaintManager;

};


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CDuiFrameWind duiFrame;
	duiFrame.Create(NULL, _T("DUIFRame"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.ShowModal();
	return 0;
}