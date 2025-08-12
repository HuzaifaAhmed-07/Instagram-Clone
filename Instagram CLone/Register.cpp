#include "Register.h"
#include "SignUp.h"
#include <string>
#include "auth.h"
#include "Home_Feed.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::Windows::Forms;
using namespace InstagramCLone; 
[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    InstagramCLone::Register^ form = gcnew InstagramCLone::Register();
    Application::Run(form);
    return 0;
}
System::Void InstagramCLone::Register::signup_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Hide();
    InstagramCLone::SignUp^ signupForm = gcnew InstagramCLone::SignUp();
    signupForm->Show();
}
System::Void InstagramCLone::Register::login_Click(System::Object^ sender, System::EventArgs^ e) {
    string username = msclr::interop::marshal_as<std::string>(this->username->Text);
    string password = msclr::interop::marshal_as<std::string>(this->password->Text);
    if (username.empty() || password.empty()) {
		Error->Text = "Please fill in all fields.";
		Error->Visible = true;
        return;
	}
    if (Authentication::login(username, password)) {
        this->Hide();
        InstagramCLone::Home_Feed^ homeFeed = gcnew InstagramCLone::Home_Feed();
		homeFeed->Show();
    } else {
		Error->Text = "Invalid username or password.";
        Error->Visible = true;
        return;
	}
}
System::Void InstagramCLone::Register::username_TextChanged(System::Object^ sender, System::EventArgs^ e)
{ 
	Error->Visible = false;
}
System::Void InstagramCLone::Register::password_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    Error->Visible = false;
}
