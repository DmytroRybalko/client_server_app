#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int last_position(const std::vector<char>& buffer, const char symbol) 
{
    return distance(buffer.begin(), find(buffer.begin(), buffer.end(), symbol));
}

int main(void)
{
    vector <char> client(5);
    cout << "Enter test message: ";
	//fgets(clientBuff.data(), clientBuff.size(), stdin);
    cin.getline(client.data(), client.size());
    cout << "Your message: " << client.data() << endl;
    // find position of the last character in server and insert space symbol: ";
    //const char sym = '\n';
    cout << "Position of \\n: " << last_position(client, '\n') << endl;
    cout << "Position of null: " << last_position(client, '\0') << endl;
    
    return 0;
}