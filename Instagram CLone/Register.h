#pragma once
#include <windows.h>
namespace InstagramCLone {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Register
	/// </summary>
	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(void)
		{
			InitializeComponent();
			this->Text = "Register";
			this->Size = System::Drawing::Size(360, 600);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->MaximizeBox = false;
			SendMessage((HWND)username->Handle.ToPointer(), 0x1501, 0, (LPARAM)L"Username or email ");
			password->UseSystemPasswordChar = true;
			SendMessage((HWND)this->password->Handle.ToPointer(), 0x1501, 0, (LPARAM)L"Password");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	public protected: System::Windows::Forms::TextBox^ username;
	private:

	private: System::Windows::Forms::TextBox^ password;

	private: System::Windows::Forms::Button^ login;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ signup;
	private: System::Windows::Forms::Label^ Error;

	protected:

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Register::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->login = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->signup = (gcnew System::Windows::Forms::Label());
			this->Error = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 22, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Location = System::Drawing::Point(74, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(260, 79);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Instagram";
			// 
			// username
			// 
			this->username->Location = System::Drawing::Point(28, 248);
			this->username->MaximumSize = System::Drawing::Size(30000, 30000);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(359, 26);
			this->username->TabIndex = 1;
			this->username->TextChanged += gcnew System::EventHandler(this, &Register::username_TextChanged);
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(28, 306);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(359, 26);
			this->password->TabIndex = 2;
			this->password->TextChanged += gcnew System::EventHandler(this, &Register::password_TextChanged);
			// 
			// login
			// 
			this->login->BackColor = System::Drawing::Color::RoyalBlue;
			this->login->FlatAppearance->BorderSize = 0;
			this->login->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->login->ForeColor = System::Drawing::SystemColors::Control;
			this->login->Location = System::Drawing::Point(28, 403);
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(359, 42);
			this->login->TabIndex = 0;
			this->login->Text = L"Log In";
			this->login->UseVisualStyleBackColor = false;
			this->login->Click += gcnew System::EventHandler(this, &Register::login_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::SystemColors::Control;
			this->label2->Location = System::Drawing::Point(57, 663);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(185, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Don\'t have an account \? ";
			// 
			// signup
			// 
			this->signup->AutoSize = true;
			this->signup->BackColor = System::Drawing::Color::Transparent;
			this->signup->Cursor = System::Windows::Forms::Cursors::Hand;
			this->signup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->signup->ForeColor = System::Drawing::Color::RoyalBlue;
			this->signup->Location = System::Drawing::Point(248, 661);
			this->signup->Name = L"signup";
			this->signup->Size = System::Drawing::Size(81, 22);
			this->signup->TabIndex = 4;
			this->signup->Text = L"Sign Up";
			this->signup->Click += gcnew System::EventHandler(this, &Register::signup_Click);
			// 
			// Error
			// 
			this->Error->AutoSize = true;
			this->Error->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Error->ForeColor = System::Drawing::Color::Red;
			this->Error->Location = System::Drawing::Point(33, 356);
			this->Error->Name = L"Error";
			this->Error->Size = System::Drawing::Size(51, 20);
			this->Error->TabIndex = 5;
			this->Error->Text = L"label3";
			this->Error->Visible = false;
			// 
			// Register
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(418, 724);
			this->Controls->Add(this->Error);
			this->Controls->Add(this->signup);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->login);
			this->Controls->Add(this->password);
			this->Controls->Add(this->username);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(440, 780);
			this->MinimizeBox = false;
			this->Name = L"Register";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register";
			this->Load += gcnew System::EventHandler(this, &Register::Register_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Register_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ActiveControl = this->label2;
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void signup_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void login_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void username_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void password_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
