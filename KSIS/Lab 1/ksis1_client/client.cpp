#include <WinSock2.h>
#include <WS2tcpip.h>   
#include <iostream>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "rus");
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(1280);

    if (inet_pton(AF_INET, "127.0.0.1", &peer.sin_addr) <= 0) {
        std::cerr << "Ошибка inet_pton\n";
        WSACleanup();
        return 1;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(s, (sockaddr*)&peer, sizeof(peer)) == SOCKET_ERROR) {
        std::cerr << "Ошибка connect: " << WSAGetLastError() << "\n";
        closesocket(s);
        WSACleanup();
        return 1;
    }

    char buf[255], b[255];
    std::cout << "Введите номер дня недели: ";
    std::cin.getline(buf, sizeof(buf));

    send(s, buf, strlen(buf), 0);

    int received = recv(s, b, sizeof(b) - 1, 0);
    if (received > 0) {
        b[received] = '\0';
        std::cout << "Ответ сервера: " << b << std::endl;
    }

    closesocket(s);
    WSACleanup();
    return 0;
}


//#include <WinSock2.h>
//
//#include <iostream>
//#include <stdlib.h>
//
//int main() {
//	
//	WORD wVersionRequested;
//	WSADATA wsaData;
//	wVersionRequested = MAKEWORD(2, 2);
//	WSAStartup(wVersionRequested, &wsaData);
//
//	struct sockaddr_in peer;
//	peer.sin_family = AF_INET;
//	peer.sin_port = htons(1280);
//	peer.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
//	connect(s, (struct sockaddr*)&peer, sizeof(peer));
//	char buf[255], b[255];
//	std::cout << "Enter the string, please" << std::endl; 
//	std::cin.getline(buf, 100, '\n');
//
//	send(s, buf, sizeof(buf), 0);
//	if (recv(s, b, sizeof(b), 0) != 0) {
//		b[strlen(b)] = '\0';
//			std::cout << b << std::endl;
//	}
//	closesocket(s);
//	WSACleanup();
//	return 0;
//
//}