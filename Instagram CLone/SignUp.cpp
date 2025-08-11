#include "SignUp.h"
#include <windows.h>
#include "Register.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include "auth.h"	
using namespace System;
using namespace System::Windows::Forms;	
System::Void InstagramCLone::SignUp::label10_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	InstagramCLone::Register^ registerForm = gcnew InstagramCLone::Register();
	registerForm->Show();	
}
System::Void InstagramCLone::SignUp::login_Click(System::Object^ sender, System::EventArgs^ e) {
	string firstname = msclr::interop::marshal_as<std::string>(this->firstname->Text);
	string lastname = msclr::interop::marshal_as<std::string>(this->lastname->Text);
	string username = msclr::interop::marshal_as<std::string>(this->username->Text);
	string password = msclr::interop::marshal_as<std::string>(this->password->Text);
	if (firstname.empty() || lastname.empty() || username.empty() || password.empty()) {
		error->Text = "Please fill in all fields.";	
		error->Visible = true;
		return;
	}
	if (Authentication::userExists(username)) {
		error->Text = "Username already exists. Please choose a different\nusername.";	
		error->Visible = true;
		return;
	}
	if (Authentication::registerUser(firstname, lastname, username, password)) {
		error->Text = "Registration successful! You can now log in.";
		error->Visible = true;
	} 
}
System::Void InstagramCLone::SignUp::firstname_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	error->Visible = false;
}
System::Void InstagramCLone::SignUp::lastname_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	error->Visible = false;
}
System::Void InstagramCLone::SignUp::username_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	error->Visible = false;
}
System::Void InstagramCLone::SignUp::password_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	error->Visible = false;
}

