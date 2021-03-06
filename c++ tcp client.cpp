#include <stdlib.h>
#include <stdio.h>
#include <WinSock2.h>

// 버퍼 크기 정의
#define BUFSIZE 4096

// 경고 제어
#pragma warning(disable:4996)

// 윈속 사용을 위한 라이브러리 링킹
#pragma comment(lib, "Ws2_32.lib")

int main()
{

	// 윈속 객체 선언 및 초기화
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return -1;

	// 클라이언트 소켓 초기화
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	// 클라이언트 소켓을 서버에 연결
	SOCKADDR_IN servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(9000);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// 보낼 파일 설정
	printf("파일 경로: 다운로드\\Download\\File Tcp\\...\n보낼 파일 이름 입력: \n");
	char myFile[256] = { 0 };
	char Filedirectory[256] = "C:\\Users\\USER\\Downloads\\Download\\File Tcp\\";
	scanf("%s", &myFile);
	strcat(Filedirectory, myFile);

	// 서버에 연결 시도
	connect(sock, (SOCKADDR*)&servaddr, sizeof(servaddr));
	printf("서버에 접속 성공 : IP = %s, Port = %d\n", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));

	// 파일 열기
	FILE* fp = fopen(Filedirectory, "rb");

	// 파일 이름 변수
	char filename[256];
	ZeroMemory(filename, 256);
	sprintf(filename, myFile);

	// 소켓으로 파일 이름을 전송
	send(sock, filename, 256, 0);

	// 파일 크기 얻기
	fseek(fp, 0, SEEK_END);
	int totalbytes = ftell(fp);

	// 파일 크기 소켓으로 보내기
	send(sock, (char*)&totalbytes, sizeof(totalbytes), 0);

	// 파일 데이터 전송에 사용할 변수
	char buf[BUFSIZE];
	int numread;
	int numtotal = 0;

	// 파일 포인터를 제일 앞으로 이동
	rewind(fp);

	// 반복적으로 파일 데이터 보내기
	while (1) {

		// 파일의 내용을 버퍼에 담음
		numread = fread(buf, 1, BUFSIZE, fp);

		// 파일 데이터가 조금이라도 남은 경우
		if (numread > 0) {
			send(sock, buf, numread, 0);
			numtotal += numread;
		}

		// 파일을 모두 전송한 경우
		else if (numread == 0 && numtotal == totalbytes) {
			printf("총 %d 바이트 파일 전송을 완료했습니다.\n", numtotal);
			break;
		}
	}
	fclose(fp);

	// 소켓 폐기
	closesocket(sock);
	printf("서버에 접속 종료 : IP = %s, Port = %d", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));

	// 윈속 종료
	WSACleanup();
	return 0;
}
