#pragma once
#include "worker.h"
#include "tuts.h"

namespace CogswellRegistrar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SQLite;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Threading;

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
		public: OpenFileDialog^ file_audit;
		public: OpenFileDialog^ file_master;
		public: SaveFileDialog^ file_save;
		public: bool sel_audit;
		public: bool sel_master;
		private: System::Windows::Forms::MenuStrip^  menu_strip;
		private: System::Windows::Forms::ToolStripMenuItem^  menu_file;
		private: System::Windows::Forms::ToolStripMenuItem^  menu_close;
		private: System::Windows::Forms::ToolStripMenuItem^  menu_about;
		private: System::Windows::Forms::ToolStripMenuItem^  menu_author;
		private: System::Windows::Forms::ToolStripMenuItem^  menu_version;
		private: System::Windows::Forms::ToolStripMenuItem^  menu_console;
		private: System::Windows::Forms::TextBox^  textBox_status;
		private: System::Windows::Forms::StatusStrip^  status_strip;
		private: System::Windows::Forms::ToolStripStatusLabel^  status_text;
		private: System::Windows::Forms::DataGridView^  data_grid;
		private: System::Windows::Forms::ToolStripButton^  tool_audit;
		private: System::Windows::Forms::ToolStripButton^  tool_master;
		private: System::Windows::Forms::ToolStripSeparator^  tool_seperator_1;
		private: System::Windows::Forms::ToolStripButton^  tool_run;
		private: System::Windows::Forms::ToolStripSeparator^  tool_seperator_2;
		private: System::Windows::Forms::ToolStripTextBox^  tool_text_search;
		private: System::Windows::Forms::ToolStripButton^  tool_search;
		private: System::Windows::Forms::ToolStrip^  tool_strip;
		private: System::Windows::Forms::ToolStripMenuItem^  menu_save;
		private: System::Windows::Forms::ToolStripMenuItem^  instructionsToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  menu_source;
		private: System::ComponentModel::IContainer^  components;
		private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menu_strip = (gcnew System::Windows::Forms::MenuStrip());
			this->menu_file = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_console = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_close = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instructionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_about = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_author = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_version = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_source = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox_status = (gcnew System::Windows::Forms::TextBox());
			this->status_strip = (gcnew System::Windows::Forms::StatusStrip());
			this->status_text = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->data_grid = (gcnew System::Windows::Forms::DataGridView());
			this->tool_audit = (gcnew System::Windows::Forms::ToolStripButton());
			this->tool_master = (gcnew System::Windows::Forms::ToolStripButton());
			this->tool_seperator_1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tool_run = (gcnew System::Windows::Forms::ToolStripButton());
			this->tool_seperator_2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tool_text_search = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->tool_search = (gcnew System::Windows::Forms::ToolStripButton());
			this->tool_strip = (gcnew System::Windows::Forms::ToolStrip());
			this->menu_strip->SuspendLayout();
			this->status_strip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->data_grid))->BeginInit();
			this->tool_strip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu_strip
			// 
			this->menu_strip->BackColor = System::Drawing::SystemColors::Control;
			this->menu_strip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->menu_file, this->instructionsToolStripMenuItem, 
				this->menu_about});
			this->menu_strip->Location = System::Drawing::Point(0, 0);
			this->menu_strip->Name = L"menu_strip";
			this->menu_strip->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menu_strip->Size = System::Drawing::Size(624, 24);
			this->menu_strip->TabIndex = 2;
			this->menu_strip->Text = L"Menu";
			// 
			// menu_file
			// 
			this->menu_file->BackColor = System::Drawing::SystemColors::Control;
			this->menu_file->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->menu_file->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->menu_save, 
				this->menu_console, this->menu_close});
			this->menu_file->Name = L"menu_file";
			this->menu_file->Size = System::Drawing::Size(37, 20);
			this->menu_file->Text = L"File";
			// 
			// menu_save
			// 
			this->menu_save->Name = L"menu_save";
			this->menu_save->Size = System::Drawing::Size(149, 22);
			this->menu_save->Text = L"Save";
			this->menu_save->Click += gcnew System::EventHandler(this, &Form1::menu_save_Click);
			// 
			// menu_console
			// 
			this->menu_console->BackColor = System::Drawing::SystemColors::Control;
			this->menu_console->ForeColor = System::Drawing::SystemColors::ControlText;
			this->menu_console->Name = L"menu_console";
			this->menu_console->Size = System::Drawing::Size(149, 22);
			this->menu_console->Text = L"Show Console";
			this->menu_console->Click += gcnew System::EventHandler(this, &Form1::menu_console_Click);
			// 
			// menu_close
			// 
			this->menu_close->Name = L"menu_close";
			this->menu_close->Size = System::Drawing::Size(149, 22);
			this->menu_close->Text = L"Close";
			this->menu_close->Click += gcnew System::EventHandler(this, &Form1::menu_close_Click);
			// 
			// instructionsToolStripMenuItem
			// 
			this->instructionsToolStripMenuItem->Name = L"instructionsToolStripMenuItem";
			this->instructionsToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->instructionsToolStripMenuItem->Text = L"Instructions";
			this->instructionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::instructionsToolStripMenuItem_Click);
			// 
			// menu_about
			// 
			this->menu_about->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->menu_author, 
				this->menu_version, this->menu_source});
			this->menu_about->Name = L"menu_about";
			this->menu_about->Size = System::Drawing::Size(52, 20);
			this->menu_about->Text = L"About";
			// 
			// menu_author
			// 
			this->menu_author->Name = L"menu_author";
			this->menu_author->Size = System::Drawing::Size(179, 22);
			this->menu_author->Text = L"By: Jared De La Cruz";
			// 
			// menu_version
			// 
			this->menu_version->Name = L"menu_version";
			this->menu_version->Size = System::Drawing::Size(179, 22);
			this->menu_version->Text = L"Version 0.1.0";
			// 
			// menu_source
			// 
			this->menu_source->Name = L"menu_source";
			this->menu_source->Size = System::Drawing::Size(179, 22);
			this->menu_source->Text = L"Github: source";
			this->menu_source->Click += gcnew System::EventHandler(this, &Form1::menu_source_Click);
			// 
			// textBox_status
			// 
			this->textBox_status->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_status->Location = System::Drawing::Point(12, 52);
			this->textBox_status->Multiline = true;
			this->textBox_status->Name = L"textBox_status";
			this->textBox_status->ReadOnly = true;
			this->textBox_status->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox_status->Size = System::Drawing::Size(600, 365);
			this->textBox_status->TabIndex = 0;
			this->textBox_status->Visible = false;
			// 
			// status_strip
			// 
			this->status_strip->BackColor = System::Drawing::SystemColors::Control;
			this->status_strip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->status_text});
			this->status_strip->Location = System::Drawing::Point(0, 420);
			this->status_strip->Name = L"status_strip";
			this->status_strip->Size = System::Drawing::Size(624, 22);
			this->status_strip->TabIndex = 4;
			this->status_strip->Text = L"status_strip";
			// 
			// status_text
			// 
			this->status_text->Name = L"status_text";
			this->status_text->Size = System::Drawing::Size(39, 17);
			this->status_text->Text = L"Status";
			// 
			// data_grid
			// 
			this->data_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->data_grid->BackgroundColor = System::Drawing::SystemColors::ControlLight;
			this->data_grid->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->data_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->data_grid->EnableHeadersVisualStyles = false;
			this->data_grid->Location = System::Drawing::Point(12, 52);
			this->data_grid->Name = L"data_grid";
			this->data_grid->RowHeadersVisible = false;
			this->data_grid->Size = System::Drawing::Size(600, 365);
			this->data_grid->TabIndex = 5;
			// 
			// tool_audit
			// 
			this->tool_audit->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tool_audit.Image")));
			this->tool_audit->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tool_audit->Name = L"tool_audit";
			this->tool_audit->Size = System::Drawing::Size(56, 22);
			this->tool_audit->Text = L"Audit";
			this->tool_audit->Click += gcnew System::EventHandler(this, &Form1::tool_audit_Click);
			// 
			// tool_master
			// 
			this->tool_master->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tool_master.Image")));
			this->tool_master->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tool_master->Name = L"tool_master";
			this->tool_master->Size = System::Drawing::Size(63, 22);
			this->tool_master->Text = L"Master";
			this->tool_master->Click += gcnew System::EventHandler(this, &Form1::tool_master_Click);
			// 
			// tool_seperator_1
			// 
			this->tool_seperator_1->Name = L"tool_seperator_1";
			this->tool_seperator_1->Size = System::Drawing::Size(6, 25);
			// 
			// tool_run
			// 
			this->tool_run->Enabled = false;
			this->tool_run->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tool_run.Image")));
			this->tool_run->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tool_run->Name = L"tool_run";
			this->tool_run->Size = System::Drawing::Size(67, 22);
			this->tool_run->Text = L"Process";
			this->tool_run->Click += gcnew System::EventHandler(this, &Form1::tool_run_Click);
			// 
			// tool_seperator_2
			// 
			this->tool_seperator_2->Name = L"tool_seperator_2";
			this->tool_seperator_2->Size = System::Drawing::Size(6, 25);
			// 
			// tool_text_search
			// 
			this->tool_text_search->Name = L"tool_text_search";
			this->tool_text_search->Size = System::Drawing::Size(100, 25);
			// 
			// tool_search
			// 
			this->tool_search->Enabled = false;
			this->tool_search->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tool_search.Image")));
			this->tool_search->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tool_search->Name = L"tool_search";
			this->tool_search->Size = System::Drawing::Size(62, 22);
			this->tool_search->Text = L"Search";
			this->tool_search->Click += gcnew System::EventHandler(this, &Form1::tool_search_Click);
			// 
			// tool_strip
			// 
			this->tool_strip->AutoSize = false;
			this->tool_strip->BackColor = System::Drawing::SystemColors::Control;
			this->tool_strip->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->tool_strip->Dock = System::Windows::Forms::DockStyle::None;
			this->tool_strip->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->tool_strip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->tool_audit, this->tool_master, 
				this->tool_seperator_1, this->tool_run, this->tool_seperator_2, this->tool_text_search, this->tool_search});
			this->tool_strip->Location = System::Drawing::Point(0, 24);
			this->tool_strip->Name = L"tool_strip";
			this->tool_strip->Padding = System::Windows::Forms::Padding(0);
			this->tool_strip->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->tool_strip->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tool_strip->Size = System::Drawing::Size(405, 25);
			this->tool_strip->TabIndex = 3;
			this->tool_strip->Text = L"tool_strip";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 442);
			this->Controls->Add(this->data_grid);
			this->Controls->Add(this->status_strip);
			this->Controls->Add(this->tool_strip);
			this->Controls->Add(this->textBox_status);
			this->Controls->Add(this->menu_strip);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menu_strip;
			this->Name = L"Form1";
			this->Text = L"Cogswell Student Audit";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menu_strip->ResumeLayout(false);
			this->menu_strip->PerformLayout();
			this->status_strip->ResumeLayout(false);
			this->status_strip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->data_grid))->EndInit();
			this->tool_strip->ResumeLayout(false);
			this->tool_strip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		Worker ^work;
		Thread ^workerThread;
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			this->textBox_status->Text += L"Application loaded.\r\n";
			this->textBox_status->Select(textBox_status->Text->Length,0);
			this->textBox_status->ScrollToCaret();

			this->status_text->Text = L"Ready, please select an audit file and master file.";
		}
		private: System::Void menu_close_Click(System::Object^  sender, System::EventArgs^  e) {
			exit(0);
		}
		private: System::Void menu_console_Click(System::Object^  sender, System::EventArgs^  e) {
			if(this->textBox_status->Visible == true) 
			{
				this->textBox_status->Visible = false;
				this->data_grid->Visible = true;
			}
			else
			{
				this->textBox_status->Visible = true;
				this->data_grid->Visible = false;
			}
					
		}
		private: System::Void tool_audit_Click(System::Object^  sender, System::EventArgs^  e) {
			file_audit = gcnew OpenFileDialog();
			file_audit->Filter = "CSV Files|*.csv|All Files|*.*";
			if(file_audit->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				return;
			}
			sel_audit = true;
			this->textBox_status->Text += L"Audit file selected: "+file_audit->FileName+"\r\n";

			//Check to see if files where submitted
			if(sel_audit && sel_master) 
			{
				this->tool_run->Enabled = true;
				this->status_text->Text = L"Ready to process, press the process button to run.";
			}
		}
		private: System::Void tool_master_Click(System::Object^  sender, System::EventArgs^  e) {
			file_master = gcnew OpenFileDialog();
			file_master->Filter = "CSV Files|*.csv|All Files|*.*";
			if(file_master->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				return;
			}
			sel_master = true;
			this->textBox_status->Text += L"Master file selected: "+file_master->FileName+"\r\n";

			//Check to see if files where submitted
			if(sel_audit && sel_master) 
			{
				this->tool_run->Enabled = true;
				this->status_text->Text = L"Ready to process, press the process button to run.";
			}
		}
		private: System::Void tool_run_Click(System::Object^  sender, System::EventArgs^  e) {
			// enable search button
			this->tool_search->Enabled = true;

			// initialize worker class
			work = gcnew Worker(textBox_status, status_text, data_grid, file_audit->FileName, file_master->FileName);

			// Create a thread and calls work method
			workerThread = gcnew Thread(gcnew ThreadStart(work, &Worker::Work));

			// Start the thread
			workerThread->Start();
		}
		private: System::Void tool_search_Click(System::Object^  sender, System::EventArgs^  e) {

			String^ str;
			// check to see if something was entered
			if(this->tool_text_search->TextLength > 0)
			{
				// get the text
				str = this->tool_text_search->ToString();
			}
			else
			{
				// set the text to blank
				str = "";
			}
			// create thread and call search method
			workerThread = gcnew Thread(gcnew ParameterizedThreadStart(work, &Worker::search));

			// Start the thread
			workerThread->Start(str);
		}
		private: System::Void menu_save_Click(System::Object^  sender, System::EventArgs^  e) {
			file_save = gcnew SaveFileDialog();
			file_save->Filter = "CSV Files|*.csv|All Files|*.*";
			if(file_save->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				return;
			}
			this->textBox_status->Text += L"Save file selected: "+file_save->FileName+"\r\n";

			// create thread and call search method
			workerThread = gcnew Thread(gcnew ParameterizedThreadStart(work, &Worker::saveFile));

			// Start the thread
			workerThread->Start(file_save->FileName);
		}
		private: System::Void instructionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			tuts^ instructions = gcnew tuts;

			// Show testDialog as a modal dialog and determine if DialogResult = OK. 
			if( instructions->ShowDialog(this) == ::DialogResult::OK)
			{

			}
			delete instructions;
		}
		private: System::Void menu_source_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Diagnostics::Process::Start("https://github.com/jareddlc/CogswellRegistrar");
		}
	};
}
