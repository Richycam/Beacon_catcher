#include <iostream>
#include <string>
#include <windows.h>
#include <iphlpapi.h>
#include <winsock2.h>


using namespace std;

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

void ListConnections() {
    PMIB_TCPTABLE tcpTable;
    DWORD size = 0;

}


class Banners{
    public:
    string Backround;
};



void main_backround_top(){
"__________________________________________________________________________";
"                        BEACON CATCHER (win)                              ";

};



int main() {
    
  
Banners.Backround = main_backround_top()
bool run = True;

while(run){
    cout << Banners.Backround;
    if (GetTcpTable(nullptr, &size, TRUE) == ERROR_INSUFFICIENT_BUFFER) {
        tcpTable = (PMIB_TCPTABLE)malloc(size);
        if (tcpTable && GetTcpTable(tcpTable, &size, TRUE) == NO_ERROR) {
            cout << "Active TCP Connections:\n";
            for (DWORD i = 0; i < tcpTable->dwNumEntries; i++) {
                cout << "Local: " << inet_ntoa(*(IN_ADDR*)&tcpTable->table[i].dwLocalAddr)
                          << ":" << ntohs((u_short)tcpTable->table[i].dwLocalPort)
                          << " -> Remote: " << inet_ntoa(*(IN_ADDR*)&tcpTable->table[i].dwRemoteAddr)
                          << ":" << ntohs((u_short)tcpTable->table[i].dwRemotePort)
                          << "\n";
                }
            }
        free(tcpTable);
        }
    }
return 0;    
}

  
