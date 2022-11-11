// WindowsProject7.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Commctrl.h"
#include "WindowsProject7.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
HWND hCheckBox1,hCheckBox2,hEdit11,hEdit22,hSpin1,hSpin2;


ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}




ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    //wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT7));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT7);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
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

    case  WM_INITDIALOG:

        return TRUE;

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
        int Result= (RightAnswers * 100) / MaxRightAnswers;

        hSpin1 = GetDlgItem(hWnd, IDC_SPIN2);
        hSpin1 = GetDlgItem(hWnd, IDC_SPIN3);
        hEdit11 = GetDlgItem(hWnd, IDC_EDIT3);
        hEdit22 = GetDlgItem(hWnd, IDC_EDIT4);

        SendMessage(hSpin1, UDM_SETRANGE32, 1, 100);
        SendMessage(hSpin1, UDM_SETBUDDY, WPARAM(hEdit11), 0);
        SetWindowText(hEdit11, TEXT("100"));



        if (LOWORD(wp) == IDOK) {
            _stprintf_s(str, TEXT("Правильных ответов: %d, out of 100 percents "), Result);
            MessageBox(hWnd, str, TEXT("Результаты"), MB_OK | MB_ICONINFORMATION);
        }
        }
        return TRUE;
    }
    return FALSE;
}