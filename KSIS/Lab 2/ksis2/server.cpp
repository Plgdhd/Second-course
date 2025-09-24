#include <winsock2.h>
#include <iostream>
#include <stdlib.h>
#include <process.h>

void main(void) {
	WORD wVersionRequested;
	WSADATA wsaData;
	int err; 
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);

	SOCKET s; 
	s = socket(AF_INET, SOCK_DGRAM, 0);
	
	struct sockaddr_in ad;
	ad.sin_port = htons(1024); 
	ad.sin_family = AF_INET;
	ad.sin_addr.s_addr = 0;
	bind(s, (struct sockaddr*)&ad , sizeof(ad));

	char b[200], tmp = '\0';
	int l; 
	l = sizeof(b);

	int recvfrom(SOCKET s, char FAR * buf, int len, int flags, struct sockaddr FAR * from, int FAR * fromlen);
	int rv = recvfrom(s, b, sizeof(b), 0, (struct sockaddr*)&ad, &l);

	b[rv] = '\0';
	std::cout << b << std::endl;
	char c[200];
	int j = 0;
	if (strlen(b) >= 15) {
		for (unsigned i = 0; b[i]; ++i) {
			if (b[i] >= 48 && b[i] <= 57) {
				continue;
			}
			c[j] = b[i];
			++j;
		}
	}
	else {
		for (unsigned i = 0; b[i]; ++i) {
			c[j] = b[i];
			++j;
		}
	}
	c[j] = '\0';

	int sendto(SOCKET s, const char FAR * buf, int len, int flags, const struct sockaddr FAR * to, int tolen);
	sendto(s, c, strlen(c), 0, (struct sockaddr*)&ad, l);
	
	closesocket(s);
	WSACleanup();
}
