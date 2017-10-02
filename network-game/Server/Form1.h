#pragma once
#include "helper.h"

bool serverStart = false;

namespace Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox_server;
	protected: 

	protected: 

	protected: 

	private: System::Windows::Forms::TextBox^  textBox_console;

	protected: 


	private: System::Windows::Forms::GroupBox^  Box_console;

	protected: 

	protected: 

	protected: 

	private: System::Windows::Forms::Label^  label_serverIP;
	private: System::Windows::Forms::TextBox^  textBox_serverIP;
	private: System::Windows::Forms::Button^  button_start;
	private: System::Windows::Forms::TextBox^  textBox_serverPort;
	private: System::Windows::Forms::Label^  label_serverPort;

	private: System::Windows::Forms::GroupBox^  groupBox_client;
	private: System::Windows::Forms::TextBox^  textBox_client;

	private: System::Windows::Forms::Label^  label_client;
	private: System::Windows::Forms::Label^  label_serverPortC;
	private: System::Windows::Forms::Label^  label_serverIPC;
	private: System::Windows::Forms::Button^  button_client;

	private: System::Windows::Forms::TextBox^  textBox_serverPortC;
	private: System::Windows::Forms::TextBox^  textBox_serverIPC;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->groupBox_server = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_serverPort = (gcnew System::Windows::Forms::TextBox());
			this->label_serverPort = (gcnew System::Windows::Forms::Label());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->textBox_serverIP = (gcnew System::Windows::Forms::TextBox());
			this->label_serverIP = (gcnew System::Windows::Forms::Label());
			this->textBox_console = (gcnew System::Windows::Forms::TextBox());
			this->Box_console = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox_client = (gcnew System::Windows::Forms::GroupBox());
			this->button_client = (gcnew System::Windows::Forms::Button());
			this->textBox_serverPortC = (gcnew System::Windows::Forms::TextBox());
			this->textBox_serverIPC = (gcnew System::Windows::Forms::TextBox());
			this->textBox_client = (gcnew System::Windows::Forms::TextBox());
			this->label_client = (gcnew System::Windows::Forms::Label());
			this->label_serverPortC = (gcnew System::Windows::Forms::Label());
			this->label_serverIPC = (gcnew System::Windows::Forms::Label());
			this->groupBox_server->SuspendLayout();
			this->Box_console->SuspendLayout();
			this->groupBox_client->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox_server
			// 
			this->groupBox_server->Controls->Add(this->textBox_serverPort);
			this->groupBox_server->Controls->Add(this->label_serverPort);
			this->groupBox_server->Controls->Add(this->button_start);
			this->groupBox_server->Controls->Add(this->textBox_serverIP);
			this->groupBox_server->Controls->Add(this->label_serverIP);
			this->groupBox_server->Location = System::Drawing::Point(12, 12);
			this->groupBox_server->Name = L"groupBox_server";
			this->groupBox_server->Size = System::Drawing::Size(218, 193);
			this->groupBox_server->TabIndex = 0;
			this->groupBox_server->TabStop = false;
			this->groupBox_server->Text = L"Server Settings";
			// 
			// textBox_serverPort
			// 
			this->textBox_serverPort->Location = System::Drawing::Point(6, 76);
			this->textBox_serverPort->Name = L"textBox_serverPort";
			this->textBox_serverPort->ReadOnly = true;
			this->textBox_serverPort->Size = System::Drawing::Size(100, 20);
			this->textBox_serverPort->TabIndex = 4;
			// 
			// label_serverPort
			// 
			this->label_serverPort->AutoSize = true;
			this->label_serverPort->Location = System::Drawing::Point(6, 60);
			this->label_serverPort->Name = L"label_serverPort";
			this->label_serverPort->Size = System::Drawing::Size(63, 13);
			this->label_serverPort->TabIndex = 3;
			this->label_serverPort->Text = L"Server Port:";
			// 
			// button_start
			// 
			this->button_start->Location = System::Drawing::Point(6, 102);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(100, 23);
			this->button_start->TabIndex = 2;
			this->button_start->Text = L"Start Server";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &Form1::button_start_Click);
			// 
			// textBox_serverIP
			// 
			this->textBox_serverIP->Location = System::Drawing::Point(6, 38);
			this->textBox_serverIP->Name = L"textBox_serverIP";
			this->textBox_serverIP->ReadOnly = true;
			this->textBox_serverIP->Size = System::Drawing::Size(100, 20);
			this->textBox_serverIP->TabIndex = 1;
			// 
			// label_serverIP
			// 
			this->label_serverIP->AutoSize = true;
			this->label_serverIP->Location = System::Drawing::Point(6, 22);
			this->label_serverIP->Name = L"label_serverIP";
			this->label_serverIP->Size = System::Drawing::Size(54, 13);
			this->label_serverIP->TabIndex = 0;
			this->label_serverIP->Text = L"Server IP:";
			// 
			// textBox_console
			// 
			this->textBox_console->Location = System::Drawing::Point(6, 19);
			this->textBox_console->Multiline = true;
			this->textBox_console->Name = L"textBox_console";
			this->textBox_console->ReadOnly = true;
			this->textBox_console->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox_console->Size = System::Drawing::Size(428, 134);
			this->textBox_console->TabIndex = 1;
			// 
			// Box_console
			// 
			this->Box_console->Controls->Add(this->textBox_console);
			this->Box_console->Location = System::Drawing::Point(12, 211);
			this->Box_console->Name = L"Box_console";
			this->Box_console->Size = System::Drawing::Size(440, 159);
			this->Box_console->TabIndex = 2;
			this->Box_console->TabStop = false;
			this->Box_console->Text = L"Console";
			// 
			// groupBox_client
			// 
			this->groupBox_client->Controls->Add(this->button_client);
			this->groupBox_client->Controls->Add(this->textBox_serverPortC);
			this->groupBox_client->Controls->Add(this->textBox_serverIPC);
			this->groupBox_client->Controls->Add(this->textBox_client);
			this->groupBox_client->Controls->Add(this->label_client);
			this->groupBox_client->Controls->Add(this->label_serverPortC);
			this->groupBox_client->Controls->Add(this->label_serverIPC);
			this->groupBox_client->Location = System::Drawing::Point(236, 12);
			this->groupBox_client->Name = L"groupBox_client";
			this->groupBox_client->Size = System::Drawing::Size(216, 193);
			this->groupBox_client->TabIndex = 3;
			this->groupBox_client->TabStop = false;
			this->groupBox_client->Text = L"Client Settings";
			// 
			// button_client
			// 
			this->button_client->Location = System::Drawing::Point(6, 141);
			this->button_client->Name = L"button_client";
			this->button_client->Size = System::Drawing::Size(99, 23);
			this->button_client->TabIndex = 6;
			this->button_client->Text = L"Send";
			this->button_client->UseVisualStyleBackColor = true;
			this->button_client->Click += gcnew System::EventHandler(this, &Form1::button_client_Click);
			// 
			// textBox_serverPortC
			// 
			this->textBox_serverPortC->Location = System::Drawing::Point(6, 76);
			this->textBox_serverPortC->Name = L"textBox_serverPortC";
			this->textBox_serverPortC->Size = System::Drawing::Size(100, 20);
			this->textBox_serverPortC->TabIndex = 5;
			// 
			// textBox_serverIPC
			// 
			this->textBox_serverIPC->Location = System::Drawing::Point(6, 37);
			this->textBox_serverIPC->Name = L"textBox_serverIPC";
			this->textBox_serverIPC->Size = System::Drawing::Size(100, 20);
			this->textBox_serverIPC->TabIndex = 4;
			// 
			// textBox_client
			// 
			this->textBox_client->Location = System::Drawing::Point(6, 115);
			this->textBox_client->Name = L"textBox_client";
			this->textBox_client->Size = System::Drawing::Size(100, 20);
			this->textBox_client->TabIndex = 3;
			// 
			// label_client
			// 
			this->label_client->AutoSize = true;
			this->label_client->Location = System::Drawing::Point(6, 99);
			this->label_client->Name = L"label_client";
			this->label_client->Size = System::Drawing::Size(53, 13);
			this->label_client->TabIndex = 2;
			this->label_client->Text = L"Message:";
			// 
			// label_serverPortC
			// 
			this->label_serverPortC->AutoSize = true;
			this->label_serverPortC->Location = System::Drawing::Point(3, 60);
			this->label_serverPortC->Name = L"label_serverPortC";
			this->label_serverPortC->Size = System::Drawing::Size(63, 13);
			this->label_serverPortC->TabIndex = 1;
			this->label_serverPortC->Text = L"Server Port:";
			// 
			// label_serverIPC
			// 
			this->label_serverIPC->AutoSize = true;
			this->label_serverIPC->Location = System::Drawing::Point(6, 21);
			this->label_serverIPC->Name = L"label_serverIPC";
			this->label_serverIPC->Size = System::Drawing::Size(54, 13);
			this->label_serverIPC->TabIndex = 0;
			this->label_serverIPC->Text = L"Server IP:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(464, 382);
			this->Controls->Add(this->groupBox_client);
			this->Controls->Add(this->Box_console);
			this->Controls->Add(this->groupBox_server);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Server";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox_server->ResumeLayout(false);
			this->groupBox_server->PerformLayout();
			this->Box_console->ResumeLayout(false);
			this->Box_console->PerformLayout();
			this->groupBox_client->ResumeLayout(false);
			this->groupBox_client->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		Helper ^help;
		Thread ^helperThread;
		Thread ^supporterThread;
		Supporter ^support;
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {		
		textBox_serverIP->AppendText("127.0.0.1");
		textBox_serverPort->AppendText("8080");

		groupBox_client->Enabled = false;
		textBox_serverIPC->AppendText("127.0.0.1");
		textBox_serverPortC->AppendText("8080");
		textBox_console->AppendText("GUI settings loaded.\r\n");
	}
	private: System::Void button_start_Click(System::Object^  sender, System::EventArgs^  e) {
		// Server started
		if(serverStart == false)
		{
			groupBox_client->Enabled = true;
			serverStart = true;
			button_start->Text = "Stop Server";
			// Create server 
			help = gcnew Helper(8080,textBox_console);

			// Create a thread and calls listen method
			helperThread = gcnew Thread(gcnew ThreadStart(help, &Helper::Listen));

			// Start the thread
			helperThread->Start();

			// Create client
			support = gcnew Supporter(8080,"127.0.0.1");

			// Create a thread and calls respond method
			//supporterThread = gcnew Thread(gcnew ThreadStart(support, &Supporter::Respond));

			// Start the thread
			//supporterThread->Start();
		}
		// Server stopped
		else
		{
			textBox_console->AppendText("Stopping server...");
			help->Quit();
			textBox_console->AppendText("Done.\r\n");
			groupBox_client->Enabled = false;
			serverStart = false;
			button_start->Text = "Start Server";
			exit(0);
		}
	}
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			 exit(0);
		 }
private: System::Void button_client_Click(System::Object^  sender, System::EventArgs^  e) {
			 support->Respond(textBox_client->Text+"\r\n");
		 }
};
}

