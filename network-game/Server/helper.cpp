#include "stdafx.h"
#include "helper.h"

Helper::Helper(int localPort, TextBox ^textBox)
{
	bufferSize = 4096;
	port = localPort;
	outputBox = textBox;
	player1 = "";
	player2 = "";
	outputDelegate = gcnew setTextBoxText(this, &Helper::setTextBoxMethod);
	outputBox->Invoke (outputDelegate, outputBox, "Initializing Server...\r\n");
}

void Helper::Listen()
{
	// Set IPAddress to localhost.
	outputBox->Invoke (outputDelegate, outputBox, "Setting up IP Address...");
	localAddr = IPAddress::Parse("127.0.0.1");
	outputBox->Invoke (outputDelegate, outputBox, "Done.\r\n");

	// Create TCP listener
	outputBox->Invoke (outputDelegate, outputBox, "Setting up TCP Listener...");
	listener = gcnew TcpListener(localAddr,port);
	outputBox->Invoke (outputDelegate, outputBox, "Done.\r\n");

	// Start listener
	listener->Start();

	outputBox->Invoke(outputDelegate, outputBox, "Server listening...\r\n");
	while(true)
	{
		// Create a socket 
		sock = listener->AcceptSocket();

		//client2 = listener->AcceptTcpClient();
		
		// Create a array buffer
		array<Byte> ^recievedBytes = gcnew array<Byte>(bufferSize);
		array<Byte> ^sentBytes = Text::Encoding::ASCII->GetBytes("Permission granted\r\n\0");

		// Recieve the message
		int n = sock->Receive(recievedBytes, bufferSize, SocketFlags::None);
		// Send server recieved to GUI
		outputBox->Invoke(outputDelegate, outputBox, "Server recieved: "+Text::Encoding::ASCII->GetString(recievedBytes, 0, n));
		// Sets localPlayer
		this->Parse(Text::Encoding::ASCII->GetString(recievedBytes, 0, n));

		// Check for initial client connection
		if(Text::Encoding::ASCII->GetString(recievedBytes, 0, n)->Contains("Requesting Connection..."))
		{
			// Send the permission granted message
			int m = sock->Send(sentBytes,sentBytes->Length, SocketFlags::None);
			// Send server sent to GUI
			outputBox->Invoke(outputDelegate, outputBox, "Server sent: "+Text::Encoding::ASCII->GetString(sentBytes, 0, m));
		}
		else
		{
			// Send the message
			sentBytes = Text::Encoding::ASCII->GetBytes(this->Response());
			int m = sock->Send(sentBytes, sentBytes->Length, SocketFlags::None);
			// Send server sent to GUI
			outputBox->Invoke(outputDelegate, outputBox, "Server sent: "+Text::Encoding::ASCII->GetString(recievedBytes, 0, n));
			outputBox->Invoke(outputDelegate, outputBox, "R:  "+this->Response()+" :R\r\n");
		}
	}
}

void Helper::Quit()
{
	//listener->Stop();
}

void Helper::setTextBoxMethod(System::Windows::Forms::TextBox ^T, String ^str)
{
	T->AppendText(str); 
}

void Helper::Parse(String ^parse)
{
	localPlayer = parse;

	// Inserts into vector
	if(localPlayer->Contains("player1"))
	{
		player1 = localPlayer;
	}
	if(localPlayer->Contains("player2"))
	{
		player2 = localPlayer;
	}
}

String^ Helper::Response()
{
	String ^temp = "";

	temp += player1;
	temp += ":";
	temp += player2;

	return temp;
}

Supporter::Supporter(int localPort, String ^localserver)
{
	port = localPort;
	server = localserver;
}

void Supporter::Respond()
{

}

void Supporter::Respond(String ^message)
{
	// Create TCP client
	client = gcnew TcpClient(server,port);

	// Convert string into ASCII and store it as a Byte array. 
	array<Byte> ^data = Text::Encoding::ASCII->GetBytes(message);

	// Create stream
	stream = client->GetStream();

	// Send the message to the connected TcpServer. 
	stream->Write(data, 0, data->Length);

}