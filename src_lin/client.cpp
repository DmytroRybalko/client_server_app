// Client part for Server-Client chat. Developed by Mr_Dezz

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
    //Key constants
    const char SERVER_IP[] = "127.0.0.1";          // Enter IPv4 address of Server
    const short SERVER_PORT_NUM = 8080;            // Enter Listening port on Server side
    const short BUFF_SIZE = 1024;                  // Maximum size of buffer for exchange info between server and client

    // Key variables for all program
    int erStat;                                    // For checking errors in sockets functions

    //IP in string format to numeric format for socket functions. Data is in "ip_to_num"
    in_addr ip_to_num;        
    erStat = inet_pton(AF_INET, SERVER_IP, &ip_to_num);

    if (erStat <= 0) {
        cout << "Error in IP translation to special numeric format" << endl;
        return 1;
    }

    // Client socket initialization
    int ClientSock = socket(AF_INET, SOCK_STREAM, 0);

    if (ClientSock == -1) {
        cout << "Error initialization socket" << endl;
        close(ClientSock);
        return 1;
    } else {
        cout << "Client socket initialization is OK" << endl;
    }

    // Server connection initialization
    sockaddr_in servInfo;
    memset(&servInfo, 0, sizeof(servInfo));  // Initializing servInfo structure

    servInfo.sin_family = AF_INET;
    servInfo.sin_addr = ip_to_num;
    servInfo.sin_port = htons(SERVER_PORT_NUM);

    erStat = connect(ClientSock, (sockaddr*)&servInfo, sizeof(servInfo));

    if (erStat != 0) {
        cout << "Connection to Server failed. Error #" << endl;
        close(ClientSock);
        return 1;
    } else {
        cout << "Connection to Server established successfully" << endl;
    }

    // Exchange text data between Client and Server. Disconnection if a client sends "xxx"
    vector<char> clientBuff(BUFF_SIZE), servBuff(BUFF_SIZE);  // Creation of buffers for sending and receiving data
    short packet_size = 0;  // The size of sending / receiving packet in bytes

    while (true) {
        cout << "Your (client) message: ";
        fgets(clientBuff.data(), clientBuff.size(), stdin); 
		//cin.getline(clientBuff.data(), clientBuff.size());

        // Check whether client would like to stop chatting
        if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
            shutdown(ClientSock, SHUT_RDWR);
            close(ClientSock);
            return 0;
        }

        packet_size = send(ClientSock, clientBuff.data(), clientBuff.size(), 0);

        if (packet_size == -1) {
            cout << "Can't send message to Server. Error #" << endl;
            close(ClientSock);
            return 1;
        }

        packet_size = recv(ClientSock, servBuff.data(), servBuff.size(), 0);  // Receiving packet from server. Program is waiting (system pause) until receive
        cout << "Server's message: " << servBuff.data() << endl;
    }

    close(ClientSock);

    return 0;
}
