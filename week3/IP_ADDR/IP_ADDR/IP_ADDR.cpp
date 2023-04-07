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
	const char* servIP = "0.000.000.100";
	printf("IP �ּ� = %s\n", servIP);

	//inet_addr() �Լ�
	printf("IP ��ȯ�ּ� = 0x%x\n", inet_addr(servIP)); // sdl�˻� �ƿ�
	//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=luckywjd7&logNo=220872794096
	
	//inet_ntoa()
	IN_ADDR temp;
	temp.S_un.S_addr = inet_addr(servIP);
	printf("IP ��ȯ �ּ� = %s\n", inet_ntoa(temp));

	//���� ����
	WSACleanup();
	return 0;
}