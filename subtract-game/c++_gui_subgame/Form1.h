#pragma once

namespace c_gui_subgame {

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
	private: System::Windows::Forms::TextBox^  textBox_output;
	protected: 
	private: System::Windows::Forms::Label^  label_start;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown;
	private: System::Windows::Forms::Button^  button_start;
	private: System::Windows::Forms::Button^  button_1;
	private: System::Windows::Forms::Button^  button_2;
	private: System::Windows::Forms::Button^  button_3;
	private: System::Windows::Forms::Label^  label_guess;

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
			this->textBox_output = (gcnew System::Windows::Forms::TextBox());
			this->label_start = (gcnew System::Windows::Forms::Label());
			this->numericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->button_1 = (gcnew System::Windows::Forms::Button());
			this->button_2 = (gcnew System::Windows::Forms::Button());
			this->button_3 = (gcnew System::Windows::Forms::Button());
			this->label_guess = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox_output
			// 
			this->textBox_output->Location = System::Drawing::Point(12, 70);
			this->textBox_output->Multiline = true;
			this->textBox_output->Name = L"textBox_output";
			this->textBox_output->ReadOnly = true;
			this->textBox_output->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox_output->Size = System::Drawing::Size(260, 180);
			this->textBox_output->TabIndex = 0;
			// 
			// label_start
			// 
			this->label_start->AutoSize = true;
			this->label_start->Location = System::Drawing::Point(12, 9);
			this->label_start->Name = L"label_start";
			this->label_start->Size = System::Drawing::Size(86, 13);
			this->label_start->TabIndex = 1;
			this->label_start->Text = L"Starting Number:";
			// 
			// numericUpDown
			// 
			this->numericUpDown->Location = System::Drawing::Point(152, 7);
			this->numericUpDown->Name = L"numericUpDown";
			this->numericUpDown->Size = System::Drawing::Size(120, 20);
			this->numericUpDown->TabIndex = 2;
			this->numericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			// 
			// button_start
			// 
			this->button_start->Location = System::Drawing::Point(12, 41);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(75, 23);
			this->button_start->TabIndex = 3;
			this->button_start->Text = L"Start Game";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &Form1::button_start_Click);
			// 
			// button_1
			// 
			this->button_1->Location = System::Drawing::Point(197, 41);
			this->button_1->Name = L"button_1";
			this->button_1->Size = System::Drawing::Size(21, 23);
			this->button_1->TabIndex = 4;
			this->button_1->Text = L"1";
			this->button_1->UseVisualStyleBackColor = true;
			this->button_1->Click += gcnew System::EventHandler(this, &Form1::button_1_Click);
			// 
			// button_2
			// 
			this->button_2->Location = System::Drawing::Point(224, 41);
			this->button_2->Name = L"button_2";
			this->button_2->Size = System::Drawing::Size(21, 23);
			this->button_2->TabIndex = 5;
			this->button_2->Text = L"2";
			this->button_2->UseVisualStyleBackColor = true;
			this->button_2->Click += gcnew System::EventHandler(this, &Form1::button_2_Click);
			// 
			// button_3
			// 
			this->button_3->Location = System::Drawing::Point(251, 41);
			this->button_3->Name = L"button_3";
			this->button_3->Size = System::Drawing::Size(21, 23);
			this->button_3->TabIndex = 6;
			this->button_3->Text = L"3";
			this->button_3->UseVisualStyleBackColor = true;
			this->button_3->Click += gcnew System::EventHandler(this, &Form1::button_3_Click);
			// 
			// label_guess
			// 
			this->label_guess->AutoSize = true;
			this->label_guess->Location = System::Drawing::Point(149, 46);
			this->label_guess->Name = L"label_guess";
			this->label_guess->Size = System::Drawing::Size(40, 13);
			this->label_guess->TabIndex = 7;
			this->label_guess->Text = L"Guess:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label_guess);
			this->Controls->Add(this->button_3);
			this->Controls->Add(this->button_2);
			this->Controls->Add(this->button_1);
			this->Controls->Add(this->button_start);
			this->Controls->Add(this->numericUpDown);
			this->Controls->Add(this->label_start);
			this->Controls->Add(this->textBox_output);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Subtraction Game";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		}
	private: 
		int number;
		System::Void button_start_Click(System::Object^  sender, System::EventArgs^  e) {
			number = int(numericUpDown->Value);
			textBox_output->Text = "Game Started.\r\n";
			textBox_output->Text += "Starting value: "+number.ToString()+".\r\n";
		}
		
		void userSelect(int n){
			bool valid = true;
			if(n <= number)
			{
				//Player Turn
				textBox_output->Text += "Player removed: "+n.ToString()+".\r\n";
				number -= n;
				if(number == 0)
				{
					textBox_output->Text += "Player lost.\r\n";
					valid = false;
				}
				//Computer Turn
				if(valid == true)
				{
					int AI=1;
					for(int i=1;i<=3;i++)
					{
						if((number-i)%4 == 1)
							AI = i;
					}

					textBox_output->Text += "Computer removed: "+AI.ToString()+".\r\n";
					number -= AI;
					if(number == 0)
						textBox_output->Text += "Computer lost.\r\n";
				}

				numericUpDown->Value = number;
				textBox_output->Text += number.ToString()+" remaining.\r\n";
			}
			else
				textBox_output->Text += "Invalid selection.\r\n";
			
			textBox_output->Select(textBox_output->Text->Length,0);
			textBox_output->ScrollToCaret();
		}

	private: 
		System::Void button_1_Click(System::Object^  sender, System::EventArgs^  e) {
			userSelect(1);
		}
	private: 
		System::Void button_2_Click(System::Object^  sender, System::EventArgs^  e) {
			userSelect(2);
		}
	private: 
		System::Void button_3_Click(System::Object^  sender, System::EventArgs^  e) {
			userSelect(3);
		}
};
}

