#include "net.h"
#include <Windows.h>

Net::Net(string name, NetPlayer *netP)
{
	netPlayer = netP;
	unique = name;
}

void Net::Init()
{
	// Starts time
	timeStart = SDL_GetTicks();

	// Initialize SDL_net
	if(SDLNet_Init()==-1)
	{
		OutputDebugStringA("SDLNet_Init: ");
		OutputDebugStringA(SDLNet_GetError());
		OutputDebugStringA("\n");
		error = -1;
	}

	// Connects to IP and Port
	if(SDLNet_ResolveHost(&ip,"127.0.0.1",8080) == -1)
	{
		OutputDebugStringA("SDLNet_ResolveHost: ");
		OutputDebugStringA(SDLNet_GetError());
		OutputDebugStringA("\n");
		error -1;
	}

	// Open socket
	tcpSocket = SDLNet_TCP_Open(&ip);
	if(!tcpSocket)
	{
		OutputDebugStringA("SDLNet_TCP_Open: ");
		OutputDebugStringA(SDLNet_GetError());
		OutputDebugStringA("\n");
		error = -1;
	}
	// Close socket
	SDLNet_TCP_Close(tcpSocket);
}

void Net::Update()
{
	timeCurrent = SDL_GetTicks() - timeStart;
	if(timeCurrent >= 50)
	{
		timeStart = SDL_GetTicks();
		OutputDebugStringA("50ms \n");
		//OutputDebugStringA(localPlayer.c_str());
		this->SendMsg(localPlayer);
	}
}

void Net::Quit()
{
	SDLNet_TCP_Close(tcpSocket);
}

void Net::SendMsg(string msg)
{
	int length,recieve,send;
	const int rlength = 256;
	
	if(error != -1)
	{

		// Open socket
		tcpSocket = SDLNet_TCP_Open(&ip);
		if(!tcpSocket)
		{
			OutputDebugStringA("SDLNet_TCP_Open:\n");
			OutputDebugStringA(SDLNet_GetError());
			error = -1;
		}

		// Add one for the terminating NULL
		length = msg.length();

		// Send Msg
		send = SDLNet_TCP_Send(tcpSocket,msg.c_str(),length);
		if(send < length)
		{
			OutputDebugStringA("SDLNet_TCP_Send Error:\n");
			OutputDebugStringA(SDLNet_GetError());
		}

		// Recieve Msg
		char rmsg[rlength];
		recieve = SDLNet_TCP_Recv(tcpSocket,rmsg,rlength);
		if(recieve <= 0)
		{
			OutputDebugStringA("SDLNet_TCP_Recv Error:\n");
			OutputDebugStringA(SDLNet_GetError());
		}

		/*
		OutputDebugStringA("SDLNet_TCP_Recv: ");
		OutputDebugStringA(rmsg);
		*/

		// Send recieve data to extract players
		this->getData(rmsg);

		// Close socket
		SDLNet_TCP_Close(tcpSocket);
	}
}

int Net::Error()
{
	return error;
}

void Net::setData(int x, int y)
{
	// Creates string for server
	string temp = unique;
	temp += ",";
	temp += to_string(x);
	temp += ",";
	temp += to_string(y);
	temp += "\n";

	// Sets localPlayer
	localPlayer = temp;
}

void Net::getData(char *msg)
{

	string name1 = "";
	string x1 = "";
	string y1 = "";
	string name2 = "";
	string x2 = "";
	string y2 = "";
	int it = 0;
	int cont = 0;
	string temp = "";

	// Nasty loop that parses my data due to time (fix this later)
	for(int i=0; i<strlen(msg); i++)
	{
		if(msg[i] == ',')
		{
				it += 1;
				if(it == 1)
					name1 = temp;
				if(it == 2)
					x1 = temp;
				if(it == 4)
					name2 = temp;
				if(it == 5)
					x2 = temp;
				if(it == 6)
					y2 = temp;
				temp = "";
		}
		else if(msg[i] == ':')
		{
			it += 1;
			if(it == 3)
					y1 = temp;
		}
		else if(i >= strlen(msg)-1)
		{
			it += 1;
			if(it == 6)
				y2 = temp;
			temp = "";
		}
		else
		{
			temp += msg[i];
		}
	}
	this->useData(name2,x2,y2);
}

void Net::useData(string name, string x, string y)
{
	OutputDebugStringA("name: ");
	OutputDebugStringA(name.c_str());
	OutputDebugStringA(" ");
	OutputDebugStringA("x: ");
	OutputDebugStringA(x.c_str());
	OutputDebugStringA(" ");
	OutputDebugStringA("y: ");
	OutputDebugStringA(y.c_str());
	OutputDebugStringA(" ");

	int tempX = atoi(x.c_str());
	int tempY = atoi(y.c_str());
	netPlayer->createPlayer("player2",tempX,tempY);
}

string Net::getLocal()
{
	return localPlayer;
}



NetPlayer::NetPlayer()
{
	coordinate.x = 0;
	coordinate.y = 0;
}

SDL_Rect NetPlayer::getCoordinate()
{
	return coordinate;
}

void NetPlayer::setX(int x)
{
	coordinate.x = x;
}

void NetPlayer::setY(int x)
{
	coordinate.y = y;
}

void NetPlayer::createPlayer(string n, int x, int y)
{
	name = n;
	coordinate.x = x;
	coordinate.y = y;
}

void returnPlayer(){}

