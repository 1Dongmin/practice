#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <io.h>
#include <cstring>

#define SERVER_IP "1.247.151.93" // 1.247.151.93 ���� �ּ� �������ּ���

int main()
{
	_finddata_t fd;
	long handle;
	int result = 1, sourse_fd;
	char filename[1024];


	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;
	const int port = 5556; //�Լ� �ȿ��� ���� ��Ʈ ����

	std::ifstream myfile;
	std::string file_name(fd.name); // ������ �����̸� fd.name
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





	std::cout << "�޽��� �����." << std::endl;
	std::cout << "�̹� �����ϴ� ������ 1 �� �����ּ���." << std::endl;
	std::cin >> UserFileExist;
	std::cout << UserFileExist << std::endl;
	//--------------------------���� �޾ƿ��� ��� (�α��ν� ���� Ȯ���մϴ�. 1�� �Է¹޾��� �� �����κ��� ���̺긦 �ٿ�޽��ϴ�.)
	if (strcmp(UserFileExist, "1") == 0) {
		char get_file_size_ch[4] = { 0, };
		int get_file_size;

		send(hSocket, UserFileExist, 1, 0);

		std::cout << "�����̸� �Է�" << std::endl;
		std::cin >> UserFileExist;
		send(hSocket, UserFileExist, 260, 0);

		std::string FN(UserFileExist);
		std::ofstream outfile("C:\\Users\\seodm\\Desktop\\server\\Client SaveFile\\" + FN, std::ios::out | std::ios::binary); //���̺����� �ٿ�޴°��Դϴ�. ���̺������� �Ű��ּ���.
		std::cout << "������ ���ϸ� : " << FN << std::endl;
		recv(hSocket, get_file_size_ch, sizeof(get_file_size_ch), 0);
		get_file_size = *((int*)get_file_size_ch);
		std::cout << "���� ũ�� ����. (" << get_file_size << ")" << std::endl;

		send(hSocket, "1", 1, 0);

		file_data = new char[get_file_size];
		recv(hSocket, file_data, get_file_size, 0);
		std::cout << "���� ������ ����." << std::endl;

		outfile.write(file_data, get_file_size);
		outfile.close();
		std::cout << "�ޱ� �Ϸ�" << std::endl;
		Sleep(100);
		send(hSocket, "1", 1, 0);

		myfile.close();
		

	}
	closesocket(hSocket);
	//-------------------------���� 1ȸ Ȯ�� ��-----
	while (1) {
		_finddata_t fd;
		long handle;
		int result = 1, sourse_fd;
		char filename[1024];
	Fileserch:
		handle = _findfirst("C:\\Users\\seodm\\Desktop\\server\\Client SaveFile\\*.sav", &fd); //���� ��ġ ���� .sav������ �ִ��� ������ Ȯ����. ���Ӽ��̺� ��ġ�� �ٲ��ּ���
		if (handle == -1)
		{
			printf("���� ����.\n");
			Sleep(2000);
			goto Fileserch;
		}


		while (result != -1) {
			
			
			

			WSADATA wsaData;
			SOCKET hSocket;
			SOCKADDR_IN servAddr;
			const int port = 5556; //�Լ� �ȿ��� ���� ��Ʈ ����

			std::ifstream myfile;
			std::string file_name(fd.name); // ������ ���� fd.name
			char* file_data;
			char sign;
			char file_size_ch[4] = { 0, };
			int file_size;
			char UserFileExist[260] = {};

			myfile.open("C:\\Users\\seodm\\Desktop\\server\\Client SaveFile\\"+file_name, std::ios::in | std::ios::binary); //���� ��ġ ���� file_name �̸��� ������ ��. ���Ӽ��̺� ��ġ�� �ٲ��ּ���

			if (myfile.fail())
			{
				std::cout << "������ ���� �б� ����" << std::endl;
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
			std::cout << "�޽��� �����." << std::endl;
			std::cout << "�̹� �����ϴ� ������ 1 �� �����ּ���." << std::endl;
			std::cin >> UserFileExist;
			std::cout << UserFileExist << std::endl;
			if (strcmp(UserFileExist, "1") == 0) {
				char get_file_size_ch[4] = { 0, };
				int get_file_size;

				send(hSocket, UserFileExist, 1, 0);

				std::cout << "�����̸� �Է�" << std::endl;
				std::cin >> UserFileExist;
				send(hSocket, UserFileExist, 260, 0);

				std::string FN(UserFileExist);
				std::ofstream outfile("C:\\Users\\seodm\\Desktop\\server\\Client SaveFile\\" + FN, std::ios::out | std::ios::binary);
				std::cout << "������ ���ϸ� : " << FN << std::endl;
				recv(hSocket, get_file_size_ch, sizeof(get_file_size_ch), 0);
				get_file_size = *((int*)get_file_size_ch);
				std::cout << "���� ũ�� ����. (" << get_file_size << ")" << std::endl;

				send(hSocket, "1", 1, 0);

				file_data = new char[get_file_size];
				recv(hSocket, file_data, get_file_size, 0);
				std::cout << "���� ������ ����." << std::endl;

				outfile.write(file_data, get_file_size);
				outfile.close();
				Sleep(100);
				send(hSocket, "1", 1, 0);
				
			}*/
			
			Sleep(100);


			send(hSocket, fd.name, 260, 0);
			recv(hSocket, &sign, 1, 0);
			
			
			
			
			std::cout << "���� ũ�� �� ������ �� (" << file_size << ")" << std::endl;
			send(hSocket, file_size_ch, sizeof(file_size_ch), 0);

			recv(hSocket, &sign, 1, 0);

			std::cout << "���� ������ ������ ��" << std::endl;
			send(hSocket, file_data, file_size, 0);

			recv(hSocket, &sign, 1, 0); //**********�ް� �� ����� ������ Ȯ��******
			Sleep(100);

			myfile.close();
			closesocket(hSocket);
			delete[] file_data;
			
			
			result = _findnext(handle, &fd);
		}
		Sleep(3000); //3�ʿ� �ѹ��� ���ѹݺ� �ǽð� ����
		_findclose(handle);
	}
	return 0;
}