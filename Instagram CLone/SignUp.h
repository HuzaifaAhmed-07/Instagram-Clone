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
    /// Summary for SignUp
    /// </summary>
    public ref class SignUp : public System::Windows::Forms::Form
    {
    public:
        SignUp(void)
        {
            InitializeComponent();
            SendMessage((HWND)firstname->Handle.ToPointer(), 0x1501, 0, (LPARAM)L"First Name");
            password->UseSystemPasswordChar = true;
            SendMessage((HWND)lastname ->Handle.ToPointer(), 0x1501, 0, (LPARAM)L"Last Name");
            SendMessage((HWND)username->Handle.ToPointer(), 0x1501, 0, (LPARAM)L"Username or email");
            SendMessage((HWND)password->Handle.ToPointer(), 0x1501, 0, (LPARAM)L"Password");
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~SignUp()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ login;
    protected:
    private: System::Windows::Forms::TextBox^ lastname;
    public protected: System::Windows::Forms::TextBox^ firstname;
    private:

    private:
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ password;
    public protected: System::Windows::Forms::TextBox^ username;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ error;
    public protected:
    private:
    public protected:

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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignUp::typeid));
            this->login = (gcnew System::Windows::Forms::Button());
            this->lastname = (gcnew System::Windows::Forms::TextBox());
            this->firstname = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->password = (gcnew System::Windows::Forms::TextBox());
            this->username = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->error = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // login
            // 
            this->login->BackColor = System::Drawing::Color::RoyalBlue;
            this->login->FlatAppearance->BorderSize = 0;
            this->login->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->login->ForeColor = System::Drawing::SystemColors::Control;
            this->login->Location = System::Drawing::Point(39, 569);
            this->login->Name = L"login";
            this->login->Size = System::Drawing::Size(359, 42);
            this->login->TabIndex = 3;
            this->login->Text = L"Sign Up";
            this->login->UseVisualStyleBackColor = false;
            this->login->Click += gcnew System::EventHandler(this, &SignUp::login_Click);
            // 
            // lastname
            // 
            this->lastname->Location = System::Drawing::Point(39, 256);
            this->lastname->Name = L"lastname";
            this->lastname->Size = System::Drawing::Size(359, 26);
            this->lastname->TabIndex = 6;
            this->lastname->TextChanged += gcnew System::EventHandler(this, &SignUp::lastname_TextChanged_1);
            // 
            // firstname
            // 
            this->firstname->Location = System::Drawing::Point(39, 204);
            this->firstname->MaximumSize = System::Drawing::Size(30000, 30000);
            this->firstname->Name = L"firstname";
            this->firstname->Size = System::Drawing::Size(359, 26);
            this->firstname->TabIndex = 5;
            this->firstname->TextChanged += gcnew System::EventHandler(this, &SignUp::firstname_TextChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 22, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::SystemColors::ControlLight;
            this->label1->Location = System::Drawing::Point(85, 88);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(260, 79);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Instagram";
            // 
            // password
            // 
            this->password->Location = System::Drawing::Point(39, 352);
            this->password->Name = L"password";
            this->password->Size = System::Drawing::Size(359, 26);
            this->password->TabIndex = 8;
            this->password->TextChanged += gcnew System::EventHandler(this, &SignUp::password_TextChanged);
            // 
            // username
            // 
            this->username->Location = System::Drawing::Point(39, 307);
            this->username->MaximumSize = System::Drawing::Size(30000, 30000);
            this->username->Name = L"username";
            this->username->Size = System::Drawing::Size(359, 26);
            this->username->TabIndex = 7;
            this->username->TextChanged += gcnew System::EventHandler(this, &SignUp::username_TextChanged_1);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
            this->label2->Location = System::Drawing::Point(35, 455);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(342, 40);
            this->label2->TabIndex = 9;
            this->label2->Text = L"People who use our service may have uploaded\r\n your contact information to Instag"
                L"ram";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::Transparent;
            this->label3->ForeColor = System::Drawing::SystemColors::MenuHighlight;
            this->label3->Location = System::Drawing::Point(308, 475);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(90, 20);
            this->label3->TabIndex = 10;
            this->label3->Text = L"Learn more";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::Transparent;
            this->label4->ForeColor = System::Drawing::SystemColors::HighlightText;
            this->label4->Location = System::Drawing::Point(67, 508);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(278, 20);
            this->label4->TabIndex = 11;
            this->label4->Text = L"By signing up, you agree to our Terms ";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->BackColor = System::Drawing::Color::Transparent;
            this->label5->ForeColor = System::Drawing::SystemColors::MenuHighlight;
            this->label5->Location = System::Drawing::Point(85, 528);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(101, 20);
            this->label5->TabIndex = 12;
            this->label5->Text = L"Privacy policy";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::Color::Transparent;
            this->label6->ForeColor = System::Drawing::SystemColors::HighlightText;
            this->label6->Location = System::Drawing::Point(192, 528);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(36, 20);
            this->label6->TabIndex = 13;
            this->label6->Text = L"and";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(155, 528);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(0, 20);
            this->label7->TabIndex = 14;
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->BackColor = System::Drawing::Color::Transparent;
            this->label8->ForeColor = System::Drawing::SystemColors::MenuHighlight;
            this->label8->Location = System::Drawing::Point(228, 528);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(101, 20);
            this->label8->TabIndex = 15;
            this->label8->Text = L"Cookie policy";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->BackColor = System::Drawing::Color::Transparent;
            this->label9->ForeColor = System::Drawing::SystemColors::HighlightText;
            this->label9->Location = System::Drawing::Point(67, 677);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(196, 20);
            this->label9->TabIndex = 16;
            this->label9->Text = L"Already have an account \?\r\n";
            this->label9->Click += gcnew System::EventHandler(this, &SignUp::label9_Click);
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->BackColor = System::Drawing::Color::Transparent;
            this->label10->Cursor = System::Windows::Forms::Cursors::Hand;
            this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label10->ForeColor = System::Drawing::SystemColors::MenuHighlight;
            this->label10->Location = System::Drawing::Point(269, 677);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(60, 20);
            this->label10->TabIndex = 17;
            this->label10->Text = L"Log In";
            this->label10->Click += gcnew System::EventHandler(this, &SignUp::label10_Click);
            // 
            // error
            // 
            this->error->AutoSize = true;
            this->error->BackColor = System::Drawing::SystemColors::Control;
            this->error->ForeColor = System::Drawing::Color::Red;
            this->error->Location = System::Drawing::Point(35, 403);
            this->error->Name = L"error";
            this->error->Size = System::Drawing::Size(60, 20);
            this->error->TabIndex = 18;
            this->error->Text = L"label11";
            this->error->Visible = false;
            // 
            // SignUp
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(418, 724);
            this->Controls->Add(this->error);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->password);
            this->Controls->Add(this->username);
            this->Controls->Add(this->login);
            this->Controls->Add(this->lastname);
            this->Controls->Add(this->firstname);
            this->Controls->Add(this->label1);
            this->Name = L"SignUp";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"SignUp";
            this->Load += gcnew System::EventHandler(this, &SignUp::SignUp_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void SignUp_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void login_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void firstname_TextChanged(System::Object^ sender, System::EventArgs^ e);
    private: System::Void lastname_TextChanged_1(System::Object^ sender, System::EventArgs^ e);
    private: System::Void username_TextChanged_1(System::Object^ sender, System::EventArgs^ e);
    private: System::Void password_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
