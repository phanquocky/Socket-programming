#pragma once
#include <iostream>
#include <fstream>
#include "afxsock.h"
#include "pch.h"
#include "framework.h"
#include "client.h"
#include <winsock2.h>
using namespace std;

void receive_image(CSocket& client, const char* filename);