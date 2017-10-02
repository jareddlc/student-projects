#pragma once


ref class Helper{
	Int32 bufferSize;
	int port;
	TextBox ^outputBox;
	IPAddress ^localAddr;
	TcpListener ^listener;
	Socket ^sock;
	TcpClient ^client;
	TcpClient ^client2;
	NetworkStream ^stream;
	delegate void setTextBoxText(System::Windows::Forms::TextBox ^, String ^);
	setTextBoxText ^outputDelegate;
	String ^localPlayer;
	String ^player1;
	String ^player2;
public:
	Helper(int localPort, TextBox ^textBox);
	void Listen();
	void Quit();
	void setTextBoxMethod(System::Windows::Forms::TextBox ^T, String ^str);
	void Parse(String ^parse);
	String ^Response();
};

ref class Supporter{
	int bufferSize;
	int port;
	String ^server;
	TcpClient ^client;
	NetworkStream ^stream;
public:
	Supporter(int localPort, String ^server);
	void Respond();
	void Respond(String ^message);
};