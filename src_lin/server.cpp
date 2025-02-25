// Server part of Server-Client chat. Developed by Mr_Dezz

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include "user_library.hpp"


using namespace std;


int main(void)
{
    //Key constants
    const char IP_SERV[] = "127.0.0.1";      // Enter local Server IP address
    const int PORT_NUM = 8080;               // Enter Open working server port
    const short BUFF_SIZE = 1024;            // Maximum size of buffer for exchange info between server and client

    // Key variables for all program
    int erStat;                              // Keeps socket errors status

    //IP in string format to numeric format for socket functions. Data is in "ip_to_num"
    in_addr ip_to_num;
    erStat = inet_pton(AF_INET, IP_SERV, &ip_to_num);

    if (erStat <= 0) {
        cout << "Error in IP translation to special numeric format" << endl;
        return 1;
    }

    // Server socket initialization
    int ServSock = socket(AF_INET, SOCK_STREAM, 0);

    if (ServSock == -1) {
        cout << "Error initialization socket" << endl;
        close(ServSock);
        return 1;
    } else {
        cout << "Server socket initialization is OK" << endl;
    }

    // Server socket binding
    sockaddr_in servInfo;
    memset(&servInfo, 0, sizeof(servInfo));  // Initializing servInfo structure

    servInfo.sin_family = AF_INET;
    servInfo.sin_addr = ip_to_num;
    servInfo.sin_port = htons(PORT_NUM);

    erStat = bind(ServSock, (sockaddr*)&servInfo, sizeof(servInfo));

    if (erStat != 0) {
        cout << "Error Socket binding to server info. Error #" << endl;
        close(ServSock);
        return 1;
    } else {
        cout << "Binding socket to Server info is OK" << endl;
    }

    // Starting to listen to any Clients
    erStat = listen(ServSock, SOMAXCONN);

    if (erStat != 0) {
        cout << "Can't start to listen to. Error #" << endl;
        close(ServSock);
        return 1;
    } else {
        cout << "Listening..." << endl;
    }

    // Client socket creation and acception in case of connection
    sockaddr_in clientInfo;
    memset(&clientInfo, 0, sizeof(clientInfo));  // Initializing clientInfo structure

    socklen_t clientInfo_size = sizeof(clientInfo);

    int ClientConn = accept(ServSock, (sockaddr*)&clientInfo, &clientInfo_size);

    if (ClientConn == -1) {
        cout << "Client detected, but can't connect to a client. Error #" << endl;
        close(ServSock);
        close(ClientConn);
        return 1;
    } else {
        cout << "Connection to a client established successfully" << endl;
        char clientIP[INET_ADDRSTRLEN];

        inet_ntop(AF_INET, &clientInfo.sin_addr, clientIP, INET_ADDRSTRLEN);  // Convert connected client's IP to standard string format

        cout << "Client connected with IP address " << clientIP << endl;
    }
    
    // Exchange text data between Server and Client. Disconnection if a client sends "xxx"
    vector<char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);  // Creation of buffers for sending and receiving data
    short packet_size = 0;  // The size of sending / receiving packet in bytes

    while (true) {
        packet_size = recv(ClientConn, servBuff.data(), servBuff.size(), 0);  // Receiving packet from client. Program is waiting (system pause) until receive
        cout << "Client's message: " << servBuff.data() << endl;

        // Add functionality to send message to client
        user_library::server_insert_name(clientBuff, servBuff);

        // finished adding functionality to send message to client

        // Check whether server would like to stop chatting
        if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
            shutdown(ClientConn, SHUT_RDWR);
            close(ServSock);
            close(ClientConn);
            return 0;
        }

        packet_size = send(ClientConn, clientBuff.data(), clientBuff.size(), 0);

        if (packet_size == -1) {
            cout << "Can't send message to Client. Error #" << endl;
            close(ServSock);
            close(ClientConn);
            return 1;
        }
    }

    close(ServSock);
    close(ClientConn);

    return 0;
}

