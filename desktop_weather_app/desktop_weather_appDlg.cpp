
// desktop_weather_appDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "desktop_weather_app.h"
#include "desktop_weather_appDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>
using namespace std;


// CdesktopweatherappDlg dialog



CdesktopweatherappDlg::CdesktopweatherappDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DESKTOP_WEATHER_APP_DIALOG, pParent)
	, input_value(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdesktopweatherappDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, input, input_value);
	DDX_Control(pDX, input, input_ctrl);
	DDX_Control(pDX, IDC_test, test_ctrl);
}

BEGIN_MESSAGE_MAP(CdesktopweatherappDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(input, &CdesktopweatherappDlg::OnEnChangeinput)
	ON_STN_CLICKED(IDC_test, &CdesktopweatherappDlg::OnStnClickedtest)
END_MESSAGE_MAP()


// CdesktopweatherappDlg message handlers

BOOL CdesktopweatherappDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CdesktopweatherappDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CdesktopweatherappDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// search input onchange
void CdesktopweatherappDlg::OnEnChangeinput()
{
	// get the input value
	input_ctrl.GetWindowTextW(input_value);
	test_ctrl.SetWindowTextW(input_value);
	// if input is empty don't fetch
	if (input_value == "") return;
}


void CdesktopweatherappDlg::OnStnClickedtest()
{
	// TODO: Add your control notification handler code here
}
