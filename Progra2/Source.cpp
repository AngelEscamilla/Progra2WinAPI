#include <windows.h>
#include <fstream>
#include <CommDlg.h>
#include <mmsystem.h>
#include "resource.h"

using namespace std;

HINSTANCE hIns;
HWND hWnd;
BOOL CALLBACK Login(HWND hSign, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Tienda(HWND hTienda, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Carrito(HWND hCarrito, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Producto(HWND hProducto, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Promociones(HWND hPromociones, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR, int hShowCmd) {
	hIns = hInst;
	hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Login), NULL, Login);

	ShowWindow(hWnd, hShowCmd);
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (GetMessage(&msg, NULL, 0, 0)>0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

BOOL CALLBACK Login(HWND hSign, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
	case WM_INITDIALOG: {}
	case WM_COMMAND: {
		switch (wParam) {
			case IDC_Logon: {

				DialogBox(hIns, MAKEINTRESOURCE(IDD_Tienda), hWnd, Tienda);

				return true;
			}break;
		}break;
	}break;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		DestroyWindow(hSign);
		PostQuitMessage(0);
	}break;
	}return 0;


};

BOOL CALLBACK Tienda(HWND hTienda, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
	case WM_INITDIALOG: {}
	case WM_COMMAND: {
		switch (wParam) {
		}break;
	}break;
	case WM_CLOSE: {
		DestroyWindow(hWnd);
		DestroyWindow(hTienda);
		PostQuitMessage(0);
	}break;
	}return 0;


};