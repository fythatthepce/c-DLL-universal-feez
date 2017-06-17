#pragma once

#include "mycheat.h"
#include <Windows.h>


namespace dll_mix_gui_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for user_interface
	/// </summary>
	public ref class user_interface : public System::Windows::Forms::Form
	{
	public:
		user_interface(void)
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
		~user_interface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::ProgressBar^  progressBar3;
	private: System::Windows::Forms::CheckBox^  checkBox2;
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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(user_interface::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(53, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(176, 102);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(50, 166);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"F1 / F2 ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(50, 188);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"(on/off)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(118, 166);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Unlimit HP";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(53, 222);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(91, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"ยิงออโต้ทุกปืน";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &user_interface::checkBox1_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &user_interface::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &user_interface::timer2_Tick);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(229, 166);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(31, 16);
			this->progressBar1->TabIndex = 6;
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(229, 223);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(31, 16);
			this->progressBar2->TabIndex = 7;
			// 
			// timer3
			// 
			this->timer3->Enabled = true;
			this->timer3->Tick += gcnew System::EventHandler(this, &user_interface::timer3_Tick);
			// 
			// progressBar3
			// 
			this->progressBar3->Location = System::Drawing::Point(229, 255);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(31, 16);
			this->progressBar3->TabIndex = 8;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(53, 255);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(89, 17);
			this->checkBox2->TabIndex = 9;
			this->checkBox2->Text = L"Unlimit Ammo";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &user_interface::checkBox2_CheckedChanged);
			// 
			// user_interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 292);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->progressBar3);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"user_interface";
			this->Text = L"ac_client dll";
			this->Load += gcnew System::EventHandler(this, &user_interface::user_interface_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void user_interface_Load(System::Object^  sender, System::EventArgs^  e) {
		//test bomb
		INC_BOMB();

		//init for wait input from hotkey
		timer1->Start();

		//init HP,Ammo : turn off
		timer2->Stop();
		timer3->Stop();

		//init progressBar
		progressBar1->Value = 0;
		progressBar2->Value = 0;
		progressBar3->Value = 0;
	}

	//loop HP
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		INC_HP();
	}

	//loop Ammo
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
		INC_AMMO();
	}

	//Action after get input from hotkey
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		//2.game.exe + base_in_offset
		if (GetAsyncKeyState(VK_F1) & 1){
			timer2->Start();
			progressBar1->Value = 100;
		}
		else if (GetAsyncKeyState(VK_F2) & 1){
			timer2->Stop();
			progressBar1->Value = 0;
		}
	}

    //check box1 >> 3.asm from ollbdg
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox1->Checked == true)
		{
			AUTO_FIRE_ON();
			progressBar2->Value = 100;
		}
		else if (checkBox1->Checked == false){
			AUTO_FIRE_OFF();
			progressBar2->Value = 0;
		}
	}

	//check box2 >> 1.greenbase pointer
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) { 
		if (checkBox1->Checked == true)
		{
			timer3->Start();
			progressBar3->Value = 100;
		}
		else if (checkBox1->Checked == false){
			timer3->Stop();
			progressBar3->Value = 0;
		}
	}
};
}
