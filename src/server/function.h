#pragma once
#include <iostream>
#include <fstream>
#include "afxsock.h"
#include "pch.h"
#include "framework.h"
#include "Project2.h"
#include <winsock2.h>
using namespace std;

void chat_socket(CSocket &client);
void send_image(CSocket& client,const char* filename);
