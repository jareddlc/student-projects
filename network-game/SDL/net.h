#pragma once
#include <string>
#include <vector>
#include "SDL_net.h"

using namespace std;

class NetPlayer{
	string name;
	int x;
	int y;
	SDL_Rect coordinate;
	vector<NetPlayer> netPlayer;
public:
	NetPlayer();
	void createPlayer(string name, int x, int y);
	void returnPlayer();
	void setX(int x);
	void setY(int y);
	SDL_Rect getCoordinate();
};

class Net{
	IPaddress ip;
	TCPsocket tcpSocket;
	Uint32 timeStart;
	Uint32 timeCurrent;
	string localPlayer;
	string unique;
	string *lastMsg;
	int error;
	NetPlayer *netPlayer;
public:
	Net(string name, NetPlayer *netPlayer);
	void Init();
	void Update();
	void Quit();
	void SendMsg(string msg);
	void setData(int x, int y);
	void getData(char *msg);
	void useData(string name, string x, string y);
	string getLocal();
	int Error();
};



