#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace msclr::interop;
namespace InstagramCLone {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Home_Feed
	/// </summary>
	public ref class Home_Feed : public System::Windows::Forms::Form
	{
		void OnFormLoad(System::Object^ sender, System::EventArgs^ e) {
			LoadDummyPosts();
		}
	public:
		Home_Feed(void)
		{
			InitializeComponent();
			this->Load += gcnew System::EventHandler(this, &InstagramCLone::Home_Feed::OnFormLoad);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Home_Feed()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ flowfeed;
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
			this->flowfeed = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// flowfeed
			// 
			this->flowfeed->AutoScroll = true;
			this->flowfeed->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowfeed->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowfeed->Location = System::Drawing::Point(0, 0);
			this->flowfeed->Name = L"flowfeed";
			this->flowfeed->Size = System::Drawing::Size(438, 724);
			this->flowfeed->TabIndex = 0;
			this->flowfeed->WrapContents = false;
			this->flowfeed->HorizontalScroll->Enabled = false;
			this->flowfeed->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Home_Feed::flowfeed_Paint);
			// 
			// Home_Feed
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(438, 724);
			this->Controls->Add(this->flowfeed);
			this->MaximumSize = System::Drawing::Size(460, 780);
			this->Name = L"Home_Feed";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Home_Feed";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void flowfeed_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	public: 
        void LoadDummyPosts() {
            std::string username, caption, path, line;
            std::ifstream ifile("posts.txt");
            while (getline(ifile, line))
            {
                stringstream ss(line);
                getline(ss, username, '|');
                getline(ss, path, '|');
                getline(ss, caption);

                Panel^ postPanel = gcnew Panel();
                postPanel->Size = Drawing::Size(400, 350);
                postPanel->BorderStyle = BorderStyle::FixedSingle;
                postPanel->Margin = Windows::Forms::Padding(10);
                postPanel->Width = this->flowfeed->ClientSize.Width - 40;

                // Username label
                Label^ usernameLabel = gcnew Label();
                usernameLabel->Text = marshal_as<String^>(username);
                usernameLabel->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
                usernameLabel->Dock = DockStyle::Top;
                usernameLabel->Height = 30;
                usernameLabel->TextAlign = ContentAlignment::MiddleLeft;

                // Image
                PictureBox^ imageBox = gcnew PictureBox();
                imageBox->Image = Image::FromFile(marshal_as<String^>(path)); 
                imageBox->SizeMode = PictureBoxSizeMode::Zoom;
                imageBox->Height = 250;
                imageBox->Dock = DockStyle::Top;

                // Caption label
                Label^ captionLabel = gcnew Label();
                captionLabel->Text = marshal_as<String^>(caption); 
                captionLabel->Dock = DockStyle::Bottom;
                captionLabel->Height = 50;
                captionLabel->Font = gcnew Drawing::Font("Segoe UI", 9);
                captionLabel->Padding = Windows::Forms::Padding(5);
                captionLabel->TextAlign = ContentAlignment::TopLeft;

                // Add to panel
                postPanel->Controls->Add(captionLabel);
                postPanel->Controls->Add(imageBox);
                postPanel->Controls->Add(usernameLabel);

                // Add to feed
                flowfeed->Controls->Add(postPanel);
            }
        }

	};
}
