// SpeechDlg.cpp : implementation file
//

#include "pch.h"
#include "CanadianExperience.h"
#include "SpeechDlg.h"
#include "afxdialogex.h"


// CSpeechDlg dialog

IMPLEMENT_DYNAMIC(CSpeechDlg, CDialog)

CSpeechDlg::CSpeechDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SPEECHDLG, pParent)
	, mShow(0)
	, mText(_T(""))
{

}

CSpeechDlg::~CSpeechDlg()
{
}

void CSpeechDlg::SetActor(CSpeechActor* actor)
{
	mActor = actor;
	bool show = mActor->IsEnabled();
	if (show) {
		mShow = 1;
	}
	else {
		mShow = 0;
	}
	mText = mActor->GetDialogue().c_str();
}

void CSpeechDlg::Take()
{
	if (mShow == 1)
	{
		mActor->SetEnabled(true);
	}
	else {
		mActor->SetEnabled(false);
	}
	std::wstring text(mText);
	mActor->SetDialogue(text);
}

void CSpeechDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHOWBOX, mShow);
	DDV_MinMaxInt(pDX, mShow, 0, 1);
	DDX_Text(pDX, IDC_TEXTSHOW, mText);
}


BEGIN_MESSAGE_MAP(CSpeechDlg, CDialog)
END_MESSAGE_MAP()


// CSpeechDlg message handlers
