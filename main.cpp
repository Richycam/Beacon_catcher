#include <winsock2.h>   // This must come first!
#include <windows.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

using namespace std;

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

// Function to return the banner text
string main_background_top() {
    return "__________________________________________________________________________\n"
           "                        BEACON CATCHER (win)\n";
}

// Banner class
class Banners {
public:
    string Background;
};

int main() {
    // Set up the banner
    Banners banner;
    banner.Background = main_background_top();

    int run = 1;

    while (run = 1) {
        // Display banner
        cout << banner.Background;

        // Variables for TCP table
        PMIB_TCPTABLE tcpTable;
        DWORD size = 0;

        // Ask OS how much space we need
        if (GetTcpTable(nullptr, &size, TRUE) == ERROR_INSUFFICIENT_BUFFER) {
            tcpTable = (PMIB_TCPTABLE)malloc(size);
            if (tcpTable && GetTcpTable(tcpTable, &size, TRUE) == NO_ERROR) {
                cout << "\nActive TCP Connections:\n";
                for (DWORD i = 0; i < tcpTable->dwNumEntries; ++i) {
                    IN_ADDR localAddr;
                    localAddr.S_un.S_addr = tcpTable->table[i].dwLocalAddr;
                    IN_ADDR remoteAddr;
                    remoteAddr.S_un.S_addr = tcpTable->table[i].dwRemoteAddr;

                    cout << "Local: " << inet_ntoa(localAddr)
                         << ":" << ntohs((u_short)tcpTable->table[i].dwLocalPort)
                         << " -> Remote: " << inet_ntoa(remoteAddr)
                         << ":" << ntohs((u_short)tcpTable->table[i].dwRemotePort)
                         << "\n";
                }
            }
            free(tcpTable);
        } else {
            cerr << "Failed to determine buffer size for TCP table.\n";
        }
    }
    return 0;
}

