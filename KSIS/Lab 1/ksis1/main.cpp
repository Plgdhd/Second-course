#include <WinSock2.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale  (LC_ALL, "rus");
    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 2);

    if (WSAStartup(wVersionRequested, &wsaData) != 0) {
        std::cerr << "Ошибка WSAStartup\n";
        return 1;
    }

    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        std::cerr << "Ошибка socket: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }

    sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(1280);
    local.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(s, (struct sockaddr*)&local, sizeof(local)) == SOCKET_ERROR) {
        std::cerr << "Ошибка bind: " << WSAGetLastError() << "\n";
        closesocket(s);
        WSACleanup();
        return 1;
    }

    if (listen(s, 5) == SOCKET_ERROR) {
        std::cerr << "Ошибка listen: " << WSAGetLastError() << "\n";
        closesocket(s);
        WSACleanup();
        return 1;
    }

    std::cout << "Сервер запущен. Ожидание клиента...\n";

    while (true) {
        sockaddr_in remote_addr;
        int size = sizeof(remote_addr);

        SOCKET s2 = accept(s, (struct sockaddr*)&remote_addr, &size);
        if (s2 == INVALID_SOCKET) {
            std::cerr << "Ошибка accept: " << WSAGetLastError() << "\n";
            continue;
        }

        std::cout << "Клиент подключился!\n";

        char b[255];
        const char* res;

        while (true) {
            int received = recv(s2, b, sizeof(b) - 1, 0);
            if (received <= 0) {
                std::cout << "Клиент отключился.\n";
                break;
            }

            b[received] = '\0';

            int day = atoi(b);
            const char* res;

            switch (day) {
            case 1:
                res = "В понедельник ожидается дождь, 15 градусов";
                break;
            case 2:
                res = "Во вторник солнечно весь день, 22 градуса";
                break;
            case 3:
                res = "В среду пасмурно, 18 градусов";
                break;
            case 4:
                res = "В четверг переменная облачность, 20 градусов";
                break;
            case 5:
                res = "В пятницу жара, 27 градусов";
                break;
            case 6:
                res = "В субботу возможны грозы, 19 градусов";
                break;
            case 7:
                res = "В воскресенье ясно и прохладно, 16 градусов";
                break;
            default:
                res = "Некорректный номер дня! Введите число от 1 до 7.";
                break;
            }

            send(s2, res, strlen(res), 0);
        }

        closesocket(s2);

    }
}

//#include <WinSock2.h>
//
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	WORD wVersionRequested;
//	WSADATA wsaData;
//
//	wVersionRequested = MAKEWORD(2, 2);
//	WSAStartup(wVersionRequested, &wsaData);
//
//	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
//
//	struct sockaddr_in local;
//	local.sin_family = AF_INET;
//	local.sin_port = htons(1280);
//	local.sin_addr.s_addr = htonl(INADDR_ANY);
//
//	int c = bind(s, (struct sockaddr*)&local, sizeof(local));
//
//	int r = listen(s, 5);
//
//	SOCKET accept(
//		SOCKET s,
//		struct sockaddr* addr,
//		int* addrlen
//	);
//
//	while (true) {
//		char buf[255], res[100], b[255], * Res;
//		struct sockaddr_in remote_addr;
//		int size = sizeof(remote_addr);
//		SOCKET s2 = accept(s, (struct sockaddr*)&remote_addr, &size);
//		int send(SOCKET s, const char FAR * buf, int len, int flags);
//
//		while (true) {
//			int received = recv(s2, b, sizeof(b) - 1, 0);
//			if (received <= 0) {
//				break;
//			}
//
//			b[received] = '\0'; 
//
//			int i = 0;
//			for (int j = 0; j < received; j++) {
//				if (b[j] == 'a') i++;
//			}
//
//			_itoa(i, res, 10);
//
//			send(s2, res, strlen(res), 0);
//	}
//
//	closesocket(s2);
//	WSACleanup();
//}