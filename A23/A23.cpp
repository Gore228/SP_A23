#include<Windows.h>
#include<tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
HINSTANCE hInst;

int APIENTRY _tWinMain(HINSTANCE This,
	HINSTANCE Prev,
	LPTSTR cmd,
	int mode)
{
	HWND hWnd;
	MSG msg;
	hInst = This;
	WNDCLASS wc;
	wc.hInstance = This;
	wc.lpszClassName = WinName;
	wc.lpfnWndProc = WndProc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 255));
	if (!RegisterClass(&wc)) return 0;
	hWnd = CreateWindow(WinName,
		_T("A23"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		HWND_DESKTOP,
		NULL,
		This,
		NULL);
	ShowWindow(hWnd, mode);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HBRUSH hBrush;
	PAINTSTRUCT ps;
	HDC hdc;
	static int sx, sy;
	HPEN hPen;

	switch (message)
	{
	case WM_SIZE:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hdc, hBrush);
		Chord(hdc, 215, 840, 1730, 1200, 1395, 1150, 555, 1150);
		hPen = CreatePen(1, 50, RGB(255, 0, 0));
		SelectObject(hdc, hPen);
		MoveToEx(hdc, 1255, 1000, NULL);
		LineTo(hdc, 1920, 0);
		MoveToEx(hdc, 1115, 1000, NULL);
		LineTo(hdc, 1440, 0);
		MoveToEx(hdc, 975, 1000, NULL);
		LineTo(hdc, 970, 0);
		MoveToEx(hdc, 835, 1000, NULL);
		LineTo(hdc, 480, 0);
		MoveToEx(hdc, 695, 1000, NULL);
		LineTo(hdc, 0, 0);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0); break;
		DeleteObject(hBrush);
		DeleteObject(hPen);
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}