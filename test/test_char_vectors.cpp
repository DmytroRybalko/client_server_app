#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int last_position(const std::vector<char>& buffer) 
{
    return distance(buffer.begin(), find(buffer.begin(), buffer.end(), '\0'));
}

int main(void)
{
    const short BUFF_SIZE = 100;
    vector <char> server(BUFF_SIZE), client(BUFF_SIZE);			// Buffers for sending and receiving data

    // add data into clientBuff
    cout << "1) Enter your message from client: ";
	//fgets(clientBuff.data(), clientBuff.size(), stdin);
    std::cin.getline(client.data(), client.size());
    std::cout << "Your message from client: " << client.data() << endl;

    cout << "Server data before swap: " << server.data() << endl;
    // swap data between buffers
    server.swap(client);
    cout << "2) Check server data after swap: " << server.data() << endl;
    cout << "Client data after swap: " << client.data() << endl;
    
    // client's buffer is empty now, but apply clear() method to make sure
    //client.clear();
    //client.resize(BUFF_SIZE);
    
    cout << "3) Enter data need to be added into server: ";
    // we will use client buffer to store data for adding into server buffer
    cin.getline(client.data(), client.size());
    cout << "3) Data for additing into server entered from console: " << client.data() << endl;
    
    // find position of the last character in server and insert space symbol: ";
    server[last_position(server)] = ' ';
    
    //size_t serverInPos = distance(server.begin(), find(server.begin(), server.end(), '\0'));
    // insert space symbol after the last character
    //server[serverInPos] = ' ';
    
    // calulate new position of the last character in server
    int serverInPos = last_position(server);
    //serverInPos = distance(server.begin(), find(server.begin(), server.end(), '\0'));

    // find position of the last character in client buffer
    int clientOutPos = last_position(client);

    // copy data from client buffer into server buffer to the position after space symbol
    //copy(client.begin(), client.begin() + clientOutPos, server.begin() + serverInPos);
    copy(client.begin(), client.begin() + last_position(client), server.begin() + last_position(server));
    cout << "Server buffer data: " << server.data() << endl;
    cout << "Server buffer size: " << server.size() << endl;
    
    //cout << "Server last symbol position: " << server[last_position(server)-1] << endl;
    // Clear the client buffer after copying
    //fill(client.begin(), client.end(), '\0');
    //cout << "Client buffer data: " << client.data() << endl;
    
    return 0;
}