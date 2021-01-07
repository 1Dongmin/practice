#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <io.h>
#include <cstring>

#define SERVER_IP "1.247.151.93" // 1.247.151.93 으로 주소 수정해주세요

int main()
{
	_finddata_t fd;
	long handle;
	int result = 1, sourse_fd;
	char filename[1024];


	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;
	const int port = 5556; //함수 안에서 서버 포트 설정

	std::ifstream myfile;
	std::string file_name(fd.name); // 전송할 파일이름 fd.name
	char* file_data;
	char sign;
	char file_size_ch[4] = { 0, };
	int file_size;
	char UserFileExist[260] = {};

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cout << "WSAStartup() error" << std::endl;
		return 0;
	}

	hSocket = socket(PF_INET, SOCK_STREAM, 0);

	if (hSocket == INVALID_SOCKET) {
		std::cout << "socket() error" << std::endl;
		return 0;
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(port);

	inet_pton(AF_INET, SERVER_IP, &servAddr.sin_addr.s_addr);

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
		std::cout << "connect() error" << std::endl;
		return 0;
	}





	std::cout << "메시지 대기중." << std::endl;
	std::cout << "이미 존재하는 유저면 1 을 보내주세요." << std::endl;
	std::cin >> UserFileExist;
	std::cout << UserFileExist << std::endl;
	//--------------------------파일 받아오기 모드 (로그인시 최초 확인합니다. 1을 입력받았을 때 서버로부터 세이브를 다운받습니다.)
	if (strcmp(UserFileExist, "1") == 0) {
		char get_file_size_ch[4] = { 0, };
		int get_file_size;

		send(hSocket, UserFileExist, 1, 0);

		std::cout << "파일이름 입력" << std::endl;
		std::cin >> UserFileExist;
		send(hSocket, UserFileExist, 260, 0);

		std::string FN(UserFileExist);
		std::ofstream outfile("C:\\Users\\seodm\\Desktop\\server\\Client SaveFile\\" + FN, std::ios::out | std::ios::binary); //세이브파일 다운받는곳입니다. 세이브폴더로 옮겨주세요.
		std::cout << "저장할 파일명 : " << FN << std::endl;
		recv(hSocket, get_file_size_ch, sizeof(get_file_size_ch), 0);
		get_file_size = *((int*)get_file_size_ch);
		std::cout << "파일 크기 얻음. (" << get_file_size << ")" << std::endl;

		send(hSocket, "1", 1, 0);

		file_data = new char[get_file_size];
		recv(hSocket, file_data, get_file_size, 0);
		std::cout << "파일 데이터 얻음." << std::endl;

		outfile.write(file_data, get_file_size);
		outfile.close();
		std::cout << "받기 완료" << std::endl;
		Sleep(100);
		send(hSocket, "1", 1, 0);

		myfile.close();
		

	}
	closesocket(hSocket);
	//-------------------------최초 1회 확인 끝-----
	while (1) {
		_finddata_t fd;
		long handle;
		int result = 1, sourse_fd;
		char filename[1024];
	Fileserch:
		handle = _findfirst("C:\\Users\\seodm\\Desktop\\server\\Client SaveFile\\*.sav", &fd); //폴더 위치 안의 .sav파일이 있는지 없는지 확인함. 게임세이브 위치로 바꿔주세요
		if (handle == -1)
		{
			printf("파일 없음.\n");
			Sleep(2000);
			goto Fileserch;
		}


		while (result != -1) {
			
			
			

			WSADATA wsaData;
			SOCKET hSocket;
			SOCKADDR_IN servAddr;
			const int port = 5556; //함수 안에서 서버 포트 설정

			std::ifstream myfile;
			std::string file_name(fd.name); // 전송할 파일 fd.name
			char* file_data;
			char sign;
			char file_size_ch[4] = { 0, };
			int file_size;
			char UserFileExist[260] = {};

			myfile.open("C:\\Users\\seodm\\Desktop\\server\\Client SaveFile\\"+file_name, std::ios::in | std::ios::binary); //폴더 위치 안의 file_name 이름의 파일을 엶. 게임세이브 위치로 바꿔주세요

			if (myfile.fail())
			{
				std::cout << "전송할 파일 읽기 실패" << std::endl;
				return 0;
			}

			myfile.seekg(0, std::ios::end);
			file_size = myfile.tellg();
			myfile.seekg(0, std::ios::beg);
			*((int*)file_size_ch) = file_size;

			file_data = new char[file_size];
			myfile.read(file_data, file_size);

			if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
				std::cout << "WSAStartup() error" << std::endl;
				return 0;
			}

			hSocket = socket(PF_INET, SOCK_STREAM, 0);

			if (hSocket == INVALID_SOCKET) {
				std::cout << "socket() error" << std::endl;
				return 0;
			}

			memset(&servAddr, 0, sizeof(servAddr));
			servAddr.sin_family = AF_INET;
			servAddr.sin_port = htons(port);

			inet_pton(AF_INET, SERVER_IP, &servAddr.sin_addr.s_addr);

			if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR) {
				std::cout << "connect() error" << std::endl;
				return 0;
			}
			/*
			std::cout << "메시지 대기중." << std::endl;
			std::cout << "이미 존재하는 유저면 1 를 보내주세요." << std::endl;
			std::cin >> UserFileExist;
			std::cout << UserFileExist << std::endl;
			if (strcmp(UserFileExist, "1") == 0) {
				char get_file_size_ch[4] = { 0, };
				int get_file_size;

				send(hSocket, UserFileExist, 1, 0);

				std::cout << "파일이름 입력" << std::endl;
				std::cin >> UserFileExist;
				send(hSocket, UserFileExist, 260, 0);

				std::string FN(UserFileExist);
				std::ofstream outfile("C:\\Users\\seodm\\Desktop\\server\\Client SaveFile\\" + FN, std::ios::out | std::ios::binary);
				std::cout << "저장할 파일명 : " << FN << std::endl;
				recv(hSocket, get_file_size_ch, sizeof(get_file_size_ch), 0);
				get_file_size = *((int*)get_file_size_ch);
				std::cout << "파일 크기 얻음. (" << get_file_size << ")" << std::endl;

				send(hSocket, "1", 1, 0);

				file_data = new char[get_file_size];
				recv(hSocket, file_data, get_file_size, 0);
				std::cout << "파일 데이터 얻음." << std::endl;

				outfile.write(file_data, get_file_size);
				outfile.close();
				Sleep(100);
				send(hSocket, "1", 1, 0);
				
			}*/
			
			Sleep(100);


			send(hSocket, fd.name, 260, 0);
			recv(hSocket, &sign, 1, 0);
			
			
			
			
			std::cout << "파일 크기 값 보내는 중 (" << file_size << ")" << std::endl;
			send(hSocket, file_size_ch, sizeof(file_size_ch), 0);

			recv(hSocket, &sign, 1, 0);

			std::cout << "파일 데이터 보내는 중" << std::endl;
			send(hSocket, file_data, file_size, 0);

			recv(hSocket, &sign, 1, 0); //**********받고 잘 썼는지 꼭꼭꼭 확인******
			Sleep(100);

			myfile.close();
			closesocket(hSocket);
			delete[] file_data;
			
			
			result = _findnext(handle, &fd);
		}
		Sleep(3000); //3초에 한번씩 무한반복 실시간 저장
		_findclose(handle);
	}
	return 0;
}