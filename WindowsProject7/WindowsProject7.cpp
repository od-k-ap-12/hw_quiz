// WindowsProject7.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Commctrl.h"
#pragma comment(lib,"comctl32")
#include "WindowsProject7.h"
#include <time.h>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
HWND hCheckBox1,hCheckBox2,hEdit11,hEdit22,hSpin1,hSpin2,hStatus,hProgress;


ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    INITCOMMONCONTROLSEX icc = { sizeof(INITCOMMONCONTROLSEX) };
    icc.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&icc);
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}


BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp)
{
    TCHAR str[100];
    int RightAnswers = 0;
    int MaxRightAnswers = 14;
    switch (message)
    {
    case WM_CLOSE:
        EndDialog(hWnd, 0);
        return TRUE;

    case  WM_INITDIALOG: {
        hStatus = CreateStatusWindow(WS_CHILD | WS_VISIBLE | CCS_BOTTOM | SBARS_TOOLTIPS | SBARS_SIZEGRIP, 0, hWnd, WM_USER);
        HMENU hMenu = LoadMenu(GetModuleHandle(NULL), MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hWnd, hMenu);
        hSpin1 = GetDlgItem(hWnd, IDC_SPIN2);
        hSpin2 = GetDlgItem(hWnd, IDC_SPIN3);
        hEdit11 = GetDlgItem(hWnd, IDC_EDIT3);
        hEdit22 = GetDlgItem(hWnd, IDC_EDIT4);

        SendMessage(hSpin1, UDM_SETRANGE, 0, MAKELPARAM(100, 0));
        SendMessage(hSpin2, UDM_SETRANGE, 1, 1000);

        SendMessage(hSpin1, UDM_SETBUDDY, WPARAM(hEdit11), 0);
        SendMessage(hSpin2, UDM_SETBUDDY, WPARAM(hEdit22), 0);

        SendMessage(hSpin1, UDM_SETBASE, 10, 0);

        srand(time(0));
        hProgress = GetDlgItem(hWnd, IDC_PROGRESS1);
        SendMessage(hProgress, PBM_SETRANGE, 0, MAKELPARAM(0, 14));
        SendMessage(hProgress, PBM_SETPOS, 0, 0);
        SendMessage(hProgress, PBM_SETBKCOLOR, 0, LPARAM(RGB(0, 0, 0)));
        SendMessage(hProgress, PBM_SETBARCOLOR, 0, LPARAM(RGB(255, 255, 0)));


        return TRUE;
    }

    case WM_COMMAND:{
        LRESULT result1 = SendDlgItemMessage(hWnd, IDC_RADIO1, BM_GETCHECK, 0, 0);
        LRESULT result2;
        if (result1 == BST_CHECKED)
            RightAnswers++;
        result1 = SendDlgItemMessage(hWnd, IDC_RADIO4, BM_GETCHECK, 0, 0);
        if (result1 == BST_CHECKED)
            RightAnswers++;
        result1 = SendDlgItemMessage(hWnd, IDC_RADIO7, BM_GETCHECK, 0, 0);
        if (result1 == BST_CHECKED)
            RightAnswers++;
        result1 = SendDlgItemMessage(hWnd, IDC_RADIO10, BM_GETCHECK, 0, 0);
        if (result1 == BST_CHECKED)
            RightAnswers++;
        result1 = SendDlgItemMessage(hWnd, IDC_RADIO13, BM_GETCHECK, 0, 0);
        if (result1 == BST_CHECKED)
            RightAnswers++;
        result1= SendDlgItemMessage(hWnd, IDC_RADIO16, BM_GETCHECK, 0, 0);
        if (result1== BST_CHECKED)
            RightAnswers++;
        result1 = SendDlgItemMessage(hWnd, IDC_RADIO19, BM_GETCHECK, 0, 0);
        if (result1 == BST_CHECKED)
            RightAnswers++;
        result1 = SendDlgItemMessage(hWnd, IDC_RADIO22, BM_GETCHECK, 0, 0);
        if (result1 == BST_CHECKED)
            RightAnswers++;
        hCheckBox1 = GetDlgItem(hWnd, IDC_CHECK1);
        hCheckBox2 = GetDlgItem(hWnd, IDC_CHECK2);
        result1 = SendMessage(hCheckBox1, BM_GETCHECK, 0, 0);
        result2 = SendMessage(hCheckBox2, BM_GETCHECK, 0, 0);
        if (result1 ==BST_CHECKED&&result2==BST_CHECKED) {
            RightAnswers++;
        }
        hCheckBox1 = GetDlgItem(hWnd, IDC_CHECK4);
        hCheckBox2 = GetDlgItem(hWnd, IDC_CHECK5);
        result1 = SendMessage(hCheckBox1, BM_GETCHECK, 0, 0);
        result2 = SendMessage(hCheckBox2, BM_GETCHECK, 0, 0);
        if (result1 == BST_CHECKED && result2 == BST_CHECKED) {
            RightAnswers++;
        }
        hEdit11 = GetDlgItem(hWnd, IDC_EDIT2);
        TCHAR Edit1[10],Edit2[10];
        GetWindowText(hEdit11, Edit1, 10);
        if (_tcscmp(Edit1,TEXT("Лампочка"))==0)
            RightAnswers++;
        hEdit11 = GetDlgItem(hWnd, IDC_EDIT1);
        GetWindowText(hEdit11, Edit2, 10);
        if (_tcscmp(Edit1, TEXT("15")) == 0)
            RightAnswers++;

        hEdit11 = GetDlgItem(hWnd, IDC_EDIT3);
        GetWindowText(hEdit11, Edit1, 10);
        if (_tcscmp(Edit1, TEXT("30")) == 0)
            RightAnswers++;
        hEdit11 = GetDlgItem(hWnd, IDC_EDIT4);
        GetWindowText(hEdit11, Edit2, 10);
        if (_tcscmp(Edit1, TEXT("10")) == 0)
            RightAnswers++;

        int Result= (RightAnswers * 100) / MaxRightAnswers;


        if (LOWORD(wp) == IDOK) {
            SendMessage(hProgress, PBM_SETPOS, RightAnswers, 0);
            _stprintf_s(str, TEXT("Правильных ответов: %d, из 100 "), Result);
            MessageBox(hWnd, str, TEXT("Результаты"), MB_OK | MB_ICONINFORMATION);
        }
        if(LOWORD(wp) == ID_EXIT_EXIT) {
            DestroyWindow(hWnd);
        }

        }
        return TRUE;
    }
    return FALSE;
}

