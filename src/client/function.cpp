#include "pch.h"
#include"function.h"
#include <stdio.h>
#include <string.h>

void receive_image(CSocket& client,const char* filename) {
    char buffer[1024];
    ofstream outfile(filename, ios::out | ios::binary);

    while (1)
    {
        int bytes_recv = client.Receive(buffer, 1024, 0);
        //cout << bytes_recv <<  " " << strlen(buffer) << " " << sizeof(buffer) << endl;
        string temp = buffer;
        if (strcmp(filename, "output.txt") == 0) cout << temp.substr(0, bytes_recv);
        if (bytes_recv < sizeof(buffer)) {
            outfile.close();
            return;
        }
        if (bytes_recv <= 0) {
            outfile.close();
            return;
        }
        outfile.write(buffer, bytes_recv);
    }
    return;

}