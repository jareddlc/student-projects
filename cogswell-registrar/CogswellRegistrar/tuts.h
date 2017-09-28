#pragma once

namespace CogswellRegistrar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for tuts
	/// </summary>
	public ref class tuts : public System::Windows::Forms::Form
	{
	public:
		tuts(void)
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
		~tuts()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  image_audit;
	private: System::Windows::Forms::PictureBox^  image_master;
	private: System::Windows::Forms::Label^  instruction;
	private: System::Windows::Forms::Label^  inst_audit;
	private: System::Windows::Forms::Label^  inst_master;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(tuts::typeid));
			this->image_audit = (gcnew System::Windows::Forms::PictureBox());
			this->image_master = (gcnew System::Windows::Forms::PictureBox());
			this->instruction = (gcnew System::Windows::Forms::Label());
			this->inst_audit = (gcnew System::Windows::Forms::Label());
			this->inst_master = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->image_audit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->image_master))->BeginInit();
			this->SuspendLayout();
			// 
			// image_audit
			// 
			this->image_audit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->image_audit->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"image_audit.Image")));
			this->image_audit->Location = System::Drawing::Point(12, 161);
			this->image_audit->Name = L"image_audit";
			this->image_audit->Size = System::Drawing::Size(294, 269);
			this->image_audit->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->image_audit->TabIndex = 0;
			this->image_audit->TabStop = false;
			// 
			// image_master
			// 
			this->image_master->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->image_master->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"image_master.Image")));
			this->image_master->Location = System::Drawing::Point(318, 161);
			this->image_master->Name = L"image_master";
			this->image_master->Size = System::Drawing::Size(294, 269);
			this->image_master->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->image_master->TabIndex = 1;
			this->image_master->TabStop = false;
			// 
			// instruction
			// 
			this->instruction->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->instruction->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->instruction->Location = System::Drawing::Point(8, 9);
			this->instruction->Name = L"instruction";
			this->instruction->Size = System::Drawing::Size(604, 133);
			this->instruction->TabIndex = 2;
			this->instruction->Text = resources->GetString(L"instruction.Text");
			// 
			// inst_audit
			// 
			this->inst_audit->AutoSize = true;
			this->inst_audit->BackColor = System::Drawing::SystemColors::Control;
			this->inst_audit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->inst_audit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inst_audit->ForeColor = System::Drawing::Color::Red;
			this->inst_audit->Location = System::Drawing::Point(15, 142);
			this->inst_audit->Name = L"inst_audit";
			this->inst_audit->Size = System::Drawing::Size(96, 24);
			this->inst_audit->TabIndex = 3;
			this->inst_audit->Text = L"Audit CSV";
			// 
			// inst_master
			// 
			this->inst_master->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->inst_master->AutoSize = true;
			this->inst_master->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inst_master->ForeColor = System::Drawing::Color::Red;
			this->inst_master->Location = System::Drawing::Point(318, 142);
			this->inst_master->Name = L"inst_master";
			this->inst_master->Size = System::Drawing::Size(109, 24);
			this->inst_master->TabIndex = 4;
			this->inst_master->Text = L"Master CSV";
			// 
			// tuts
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 442);
			this->Controls->Add(this->inst_master);
			this->Controls->Add(this->inst_audit);
			this->Controls->Add(this->instruction);
			this->Controls->Add(this->image_master);
			this->Controls->Add(this->image_audit);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"tuts";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Instructions";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->image_audit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->image_master))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
	};
}
