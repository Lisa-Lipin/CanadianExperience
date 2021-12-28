#pragma once

#include <memory>
#include "Picture.h"
class CMachineDrawable;
/** CMachineStartDlg dialog*/

class CMachineStartDlg : public CDialog
{
	DECLARE_DYNAMIC(CMachineStartDlg)

public:
	CMachineStartDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMachineStartDlg();
    /**set the picture
    \param picture to set*/
    void SetPicture(CPicture* picture);
    void Take();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MACHINESTARTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
    int mFrameToStart;     ///< Number of frames to start machine 1
    /// The picture we are editing
    CPicture* mPicture = nullptr;
    int mFrameToStart2;   ///< Number of framesto start machine 2
public:
    afx_msg void OnEnChangeStartframe2();
};
