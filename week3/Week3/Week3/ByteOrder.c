#pragma comment (lib, "ws2_32.lib")

#include <WinSock2.h>
#include <stdio.h>

int main12() {
	
	WSADATA wsa;
	
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		return -1;
	}

	u_short x = 0x1234, x2;
	u_long y = 0x12345678, y2;

	printf("ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ\n");
	printf("0x%x -> 0x%x\n", x, x2 = htons(x));
	printf("0x%x -> 0x%x\n", y, y2 = htonl(y));

	printf("��Ʈ��ũ ����Ʈ -> ȣ��Ʈ ����Ʈ\n");
	printf("0x%x -> 0x%x\n", x, x2 = ntohs(x2));
	printf("0x%x -> 0x%x\n", y, y2 = ntohl(y2));
	
	WSACleanup();
	return 0;
}
