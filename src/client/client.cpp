// client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "client.h"
#include "afxsock.h"
#include "function.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: code your application's behavior here.
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: code your application's behavior here.

            // khai bao su dung socket
            AfxSocketInit(NULL);

            //Socket client
            CSocket client;


            // Socket cua client khong can port
            client.Create();

            client.Connect(_T("127.0.0.1"), 8080);

            //receive_image(client, "result.txt");
             //bat dau noi chuyen
            char msg[100];
            int len = 0;
            while (true) {
                cout << "Client: ";
                gets_s(msg);
                len = strlen(msg);

                // gui thong diep cho server
                client.Send(&len, sizeof(int), 0);
                client.Send(msg, len, 0);

                // nhap thong tin tu server
                client.Receive(&len, sizeof(int), 0);
                char* temp = new char[len + 1];
                client.Receive(temp, len, 0);
                temp[len] = '\0';

                if (strcmp(temp, "0") == 0) {
                    receive_image(client, "output.txt");
              
                }
                else if (strcmp(temp, "ss") == 0) {
                    receive_image(client, "screen.png");
                    cout << "Screenshot success!" << endl;
                }
                else {
                    cout << temp;
                }
               
                delete []temp;
            }
            client.Close();

        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
