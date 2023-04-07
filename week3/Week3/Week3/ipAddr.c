#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <stdio.h>
#include <ws2tcpip.h>

/*
	������ ���� 1.
	inet_addr()�� ����ߴµ� ������ �߻��ߴ�. ������ ����1����.
	�׷��� ��� ������� inet_addr()������� �ʰ� inet_pton()�� ����ϱ�� �ߴ�.
	�� �Լ���
	#include <arpa/inet.h> �� ������Ͽ� ���� �Ǿ� �־ �߰��� ���������.
	�׷��� ������ ���� �� ������ϸ��� �ҷ������� �ʴ´�.
	�׷��� #include <ws2tcpip.h>�� ����ߴ�.

	������ ����2.
	inet_ntoa �� �Լ��� ���̻� ������� ����� ����Ǽ�
	inet_ntop()�Լ��� ����϶�� inet_ntop()�� ����϶�� ����Ǿ��ִ�.
*/

int main(void) {
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		return -1;
	}

	//ip �ּ� ���
	char* servIP = "192.169.1.100";
	IN_ADDR temp;

	printf("IP �ּ� = %s\n", servIP);

	//inet_addr() ip-v4
	//inet_addr(servIP)
	printf("IP ��ȯ�ּ� 0x%x\n", inet_pton(AF_INET, servIP, &temp));
	printf("%x", temp.S_un.S_addr);
	//inet_ntoa()

	//temp.S_un.S_addr = inet_pton(AF_INET, servIP, &temp);
	//printf("IP ��ȯ�ּ� =  %s\n", inet_ntop(AF_INET,temp,NULL,0));

	//���� ����
	WSACleanup();
}