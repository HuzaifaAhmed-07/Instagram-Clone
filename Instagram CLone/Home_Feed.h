#pragma once

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
	public:
		Home_Feed(void)
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
			this->flowfeed->Size = System::Drawing::Size(418, 724);
			this->flowfeed->TabIndex = 0;
			this->flowfeed->WrapContents = false;
			// 
			// Home_Feed
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 724);
			this->Controls->Add(this->flowfeed);
			this->Name = L"Home_Feed";
			this->Text = L"Home_Feed";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
