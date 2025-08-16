#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace msclr::interop;
struct Post {
	std::string username;
	std::string path;
	std::string caption;
	int likes;
};
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
			LoadFeed(flowfeed, "posts.txt");
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
	private: void OnLikeButtonClick(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ likeButton = safe_cast<Button^>(sender);
		Label^ likesLabel = safe_cast<Label^>(likeButton->Tag);
		int likes = Int32::Parse(likesLabel->Text->Substring(7)); // "Likes: " is 7 characters
		likesLabel->Text = "Likes: " + likes.ToString();
		if (likeButton->Text == L"♡")
		{
			likeButton->Text = L"♥";
			likesLabel->Text = "Likes: " + (++likes).ToString();
			SavePostsToFile("posts.txt", LoadPostsFromFile("posts.txt")); 
		}
		else
		{
			likeButton->Text = L"♡";
			likesLabel->Text = "Likes: " + (--likes).ToString();
		}
	}

	public: 
		std::vector<Post> LoadPostsFromFile(const std::string& filename) {
			std::vector<Post> posts;
			std::ifstream ifile(filename);
			std::string line;
			while (getline(ifile, line)) {
				std::stringstream ss(line);
				Post p;
				std::string likesStr;
				getline(ss, p.username, '|');
				getline(ss, p.path, '|');
				getline(ss, p.caption, '|');
				getline(ss, likesStr);
				p.likes = std::stoi(likesStr);
				posts.push_back(p);
			}
			return posts;
		}
		void SavePostsToFile(const std::string& filename, const std::vector<Post>& posts) {
			std::ofstream ofile(filename, std::ios::trunc);
			for (auto& p : posts) {
				ofile << p.username << "|" << p.path << "|" << p.caption << "|" << p.likes << "\n";
			}
		}
		void LoadFeed(FlowLayoutPanel^ flowfeed, const std::string& filename) {
			flowfeed->Controls->Clear();

			// Load all posts into memory
			std::vector<Post> posts = LoadPostsFromFile(filename);

			for (int i = 0; i < posts.size(); i++) {
				Post& post = posts[i];

                Panel^ postPanel = gcnew Panel();
                postPanel->Size = Drawing::Size(400, 350);
                postPanel->BorderStyle = BorderStyle::FixedSingle;
                postPanel->Margin = Windows::Forms::Padding(10);
                postPanel->Width = this->flowfeed->ClientSize.Width - 35;

                // Username label
                Label^ usernameLabel = gcnew Label();
                usernameLabel->Text = marshal_as<String^>(post.username);
                usernameLabel->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
                usernameLabel->Dock = DockStyle::Top;
                usernameLabel->Height = 30;
                usernameLabel->TextAlign = ContentAlignment::MiddleLeft;

                // Image
                PictureBox^ imageBox = gcnew PictureBox();
                imageBox->Image = Image::FromFile(marshal_as<String^>(post.path)); 
                imageBox->SizeMode = PictureBoxSizeMode::Zoom;
                imageBox->Height = 250;
                imageBox->Dock = DockStyle::Top;
				//likePanel
				Panel^ likePanel = gcnew Panel();
				likePanel->Dock = DockStyle::Bottom;
				likePanel->Height = 50;
				likePanel->Padding = Windows::Forms::Padding(5);
				likePanel->BackColor = Color::WhiteSmoke;
				FlowLayoutPanel^ likeContainer = gcnew FlowLayoutPanel();
				likeContainer->Dock = DockStyle::Left;
				likeContainer->AutoSize = true;
				likeContainer->FlowDirection = FlowDirection::LeftToRight;
				likeContainer->WrapContents = false;
				likeContainer->Padding = Windows::Forms::Padding(0);
				likeContainer->Margin = Windows::Forms::Padding(0);
				likeContainer->Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Bottom;

				// Like button
				Button^ likeButton = gcnew Button();
				likeButton->Text = L"♡";
				likeButton->Width = 25;
				likeButton->Height = 25; 
				likeButton->Margin = Windows::Forms::Padding(0, 10, 5, 10);

				Label^ likesLabel = gcnew Label();
				likesLabel->Text = "Likes: 0";
				likesLabel->AutoSize = true;
				likesLabel->Font = gcnew Drawing::Font("Segoe UI", 9);
				likesLabel->TextAlign = ContentAlignment::MiddleLeft;
				likesLabel->Margin = Windows::Forms::Padding(0, 15, 0, 0);

				likeButton->Tag = likesLabel;
				likeButton->Click += gcnew EventHandler(this, &Home_Feed::OnLikeButtonClick);

				likeContainer->Controls->Add(likeButton);
				likeContainer->Controls->Add(likesLabel);

				likePanel->Controls->Add(likeContainer);

                // Caption label
                Label^ captionLabel = gcnew Label();
                captionLabel->Text = marshal_as<String^>(post.caption); 
                captionLabel->Dock = DockStyle::Bottom;
                captionLabel->Height = 50;
                captionLabel->Font = gcnew Drawing::Font("Segoe UI", 9);
                captionLabel->Padding = Windows::Forms::Padding(5);
                captionLabel->TextAlign = ContentAlignment::TopLeft;

                // Add to panel
                postPanel->Controls->Add(captionLabel);
				postPanel->Controls->Add(likePanel);
                postPanel->Controls->Add(imageBox);
                postPanel->Controls->Add(usernameLabel);
				

                // Add to feed
                flowfeed->Controls->Add(postPanel);
            }
        }
	};

}
