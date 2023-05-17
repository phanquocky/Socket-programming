
#include "pch.h"
#include "function.h"
#include <iostream>
#include <windows.h>

void chat_socket(CSocket &client) {
    int len = 0;
    client.Receive(&len, sizeof(int), 0);
    
    string res = "> output.txt";
    len = len + res.length();
    char* temp = new char[len + 1];
    client.Receive(temp, len - res.length(), 0);
    for (int i = 0; i < res.length(); i++) {
        temp[i + len - res.length()] = res[i];
    }
    temp[len] = '\0';
    cout << "Client say: " << temp << endl;

    if (strcmp(temp, "screen_shot> output.txt") == 0) {
        system("nircmd.exe savescreenshot screen.png");
        char msg[100] = "ss";
        len = strlen(msg);
        client.Send(&len, sizeof(int), 0);
        client.Send(msg, len, 0);
        send_image(client, "screen.png");
    }
    else if (system(temp) == 0) {
        char msg[100] = "0";
        len = strlen(msg);
        client.Send(&len, sizeof(int), 0);
        client.Send(msg, len, 0);
        send_image(client, "output.txt");
    }
    else {
        char msg[100] = "error syntax \n";
        len = strlen(msg);
        client.Send(&len, sizeof(int), 0);
        client.Send(msg, len, 0);
    }


    //server gui cho client

    delete []temp;
}

void send_image(CSocket& client,const char* filename) {

    ifstream file(filename, ios::in | ios::binary);
    
    char buffer[1024];
    while (!file.eof())
    {
        file.read(buffer, 1024);
        int bytes_send = client.Send(buffer, file.gcount(), 0);
        /*cout << bytes_send << " " << file.gcount() << " " << strlen(buffer) <<  endl;*/
        if (bytes_send < 0) {
            cout << "bytes_send < 0";
            perror("Send error");
            return;
        }
    }
    cout << "send a = 0 " << endl;
    client.Send(buffer, 1, 0);
    return;

}
