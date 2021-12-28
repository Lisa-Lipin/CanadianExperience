// MachineStartDlg.cpp : implementation file
//

#include "pch.h"
#include "CanadianExperience.h"
#include "MachineStartDlg.h"
#include "afxdialogex.h"


// CMachineStartDlg dialog

IMPLEMENT_DYNAMIC(CMachineStartDlg, CDialog)

/**create dialog
\param pParent parent*/
CMachineStartDlg::CMachineStartDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MACHINESTARTDLG, pParent)
	, mFrameToStart(0)
	, mFrameToStart2(0)
{

}

/**destructor*/
CMachineStartDlg::~CMachineStartDlg()
{
}

/**Set the picture
/param picture picture to set*/
void CMachineStartDlg::SetPicture(CPicture* picture)
{
	mPicture = picture;
	mFrameToStart = mPicture->GetMachineOneStart();
	mFrameToStart2 = mPicture->GetMachineTwoStart();
}

/**send new data to picture*/
void CMachineStartDlg::Take()
{
	mPicture->SetMachineOneStart(mFrameToStart);
	mPicture->SetMachineTwoStart(mFrameToStart2);
}
/**data exchange
\param pDX data exchange*/
void CMachineStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FRAMESTART, mFrameToStart);
	DDV_MinMaxInt(pDX, mFrameToStart, 0, 10000);
	DDX_Text(pDX, IDC_STARTFRAME, mFrameToStart2);
	DDV_MinMaxInt(pDX, mFrameToStart2, 0, 10000);
}


BEGIN_MESSAGE_MAP(CMachineStartDlg, CDialog)
	ON_EN_CHANGE(IDC_STARTFRAME, &CMachineStartDlg::OnEnChangeStartframe2)
END_MESSAGE_MAP()


// CMachineStartDlg message handlers

/**change*/
void CMachineStartDlg::OnEnChangeStartframe2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
