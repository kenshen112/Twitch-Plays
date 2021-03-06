#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Common.h"


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

class conection
{
private:
	WSADATA wsaData;
	int status = 0;
	std::string hostName;
	std::string service;
	state st;
	Keys key;
	char *port;
	char * pong = "PONG tmi.twitch.tv";
	struct addrinfo server, *result, *ptr;

public:
	conection();
	int receiveAll(int s, char *recievebuf);
	int initalize(SOCKET &connectSocket);
	void sendAll(int s, std::string buff, int *len);

	std::string setHostName(std::string h) { return hostName = h; }
	state setState(state s) { return st = s; }
	state getState() { return st; }
	bool findObject(char *ob, char recieve[]);
	char* setPort(char* p) { return port = p; }
	int getStatus() { return status; }
	int setStatus(int s) { return status = s; }

	~conection();
};

