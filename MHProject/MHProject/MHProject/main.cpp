#include<windows.h>

int WINAPI WinMain(
			_In_ HINSTANCE hInstance,
			_In_opt_ HINSTANCE hPrevInstance,
			_In_ LPSTR lpCmdLine,
			_In_ int nCmdshow) {
	HWND hwnd;
	WNDCLASS winc;
	MSG msg;

	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = DefWindowProc;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("MH");

	if (!RegisterClass(&winc)) return 0;

	hwnd = CreateWindow(
		TEXT("MH"), TEXT("MHProject"),
		WS_OVERLAPPEDWINDOW ,
		100, 100, 200, 200, NULL, NULL,
		hInstance, NULL
	);

	if (hwnd == NULL) return 0;

	ShowWindow(hwnd, SW_SHOW);
	while (TRUE) {
		GetMessage(&msg, NULL, 0, 0);
		if (msg.message == WM_LBUTTONUP)break;
		DispatchMessage(&msg);
	}
	return 0;
}