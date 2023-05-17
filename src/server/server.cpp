// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "Project2.h"
#include "afxsock.h"
#include "function.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

#include <iostream>
#include <stdio.h>
#include <string>



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

            // khoi tao socket
            AfxSocketInit(NULL);

            // Socket server và client
            CSocket server;
            CSocket client;
            
            // khoi tao socket voi port la 8080
            server.Create(8080);

            // lang nghe tu client
            server.Listen();

            cout << "waiting for client connection ... " << endl;

            if (server.Accept(client))
            {
                cout << "client connected" << endl;
            }

            //bat dau noi chuyen
            while (true){
                // nhap thong diep tu client
                chat_socket(client);   
            }

            client.Close();
            server.Close();
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
