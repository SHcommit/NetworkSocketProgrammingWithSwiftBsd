#pragma comment (lib, "ws2_32.lib")
#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>

//���� ����� 2�ε� �غ��� �����غ���
#define BUFSIZE 5
// ��Ʈ��ȣ�� 1023 ���Ϸ� �غ�
//��Ʈ��ȣ�� 7���̻����ε��غ�
#define PORT 9000

int main() {
	int recval;
	SOCKET clientSocket;
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("WSAStartup Error \n");
	}

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	if (clientSocket == INVALID_SOCKET) {
		printf("socket() Error \n");
	}

	SOCKADDR_IN clientAddr;
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(PORT);
	clientAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	printf("client Addr %d\n", clientAddr.sin_addr.S_un.S_addr);
	// 1. ����
	recval = connect(clientSocket, (SOCKADDR*)&clientAddr, sizeof(clientAddr));
	if (recval == SOCKET_ERROR) {
		printf("connect()");
	}

	char readBuffer[BUFSIZE + 1];
	int length;

	while (true) {
		ZeroMemory(readBuffer, sizeof(readBuffer));
		printf("\n [���� ������]");
		if (fgets(readBuffer, BUFSIZE + 1, stdin) == NULL) {
			break;
		}
		//�Է� �ް�
		length = strlen(readBuffer);
		if (readBuffer[length - 1] == '\n') {
			readBuffer[length - 1] = '\0';
		}
		if (strlen(readBuffer) == 0) {
			break;
		}
		//send�� ����
		recval = send(clientSocket, readBuffer, strlen(readBuffer), 0);
		if (recval == SOCKET_ERROR ){
			printf("send()");
			break;
		}
		printf("[TCP Ŭ���̾�Ʈ] %d ����Ʈ�� ���½��ϴ�.\n", recval);
		recval = recv(clientSocket, readBuffer, recval, 0);
		if (recval == 0) {
			break;
		}
		readBuffer[BUFSIZE] = '\0';
		printf("[TCP Ŭ���̾�Ʈ] %d ����Ʈ�� �޾ҽ��ϴ�.\n", recval);
		printf("[����������] %s\n", readBuffer);
	}
	closesocket(clientSocket);
	WSACleanup();

	return 0;
}