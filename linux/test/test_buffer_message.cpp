#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(void)
{
    const short BUFF_SIZE = 100;
    vector <char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);			// Buffers for sending and receiving data
	short packet_size = 0;												// The size of sending / receiving packet in bytes

    // add data into clientBuff
    cout << "Your (Client) message to Server from console: ";
	fgets(clientBuff.data(), clientBuff.size(), stdin);

    // read data from client
    //cout << "Server message: " << servBuff.data() << endl;
    cout << "Your (Client) message to Server from buffer: " << clientBuff.data() << endl;
    /* for (auto i : clientBuff) {
        cout << i << endl;
    } */
    // read chunk of data from client's buffer
    servBuff.insert(servBuff.begin(), clientBuff.begin(), clientBuff.end());
    cout << "Copy message to Server from client's buffer: " << servBuff.data() << " size: " << servBuff.size() << endl;
    
    vector <char> buffer(BUFF_SIZE);
    cout << "Get data from Server: " << endl;
    fgets(buffer.data(), buffer.size(), stdin);
    cout << "Message from buffer for Server from console: " << buffer.data() << " size: " << buffer.size() << endl;

    servBuff.insert(servBuff.end(), buffer.begin(), buffer.end());
    cout << "Add data from Server to final aswer: " << servBuff.data() << " size: " << servBuff.size() << endl;

    return 0;
}