#pragma once
#include "SpeechActor.h"


// CSpeechDlg dialog

class CSpeechDlg : public CDialog
{
	DECLARE_DYNAMIC(CSpeechDlg)

public:
	CSpeechDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CSpeechDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPEECHDLG };
#endif
	void SetActor(CSpeechActor* actor);
	void Take();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	CSpeechActor* mActor = nullptr;

	int mShow;
	CString mText;
};
