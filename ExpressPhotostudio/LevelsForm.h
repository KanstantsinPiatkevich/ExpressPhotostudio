#include "MainForm.h"

#pragma once

namespace ExpressPhotostudio {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ LevelsForm
	/// </summary>
	public ref class LevelsForm : public System::Windows::Forms::Form
	{
	public:
		LevelsForm(MainForm^ form)
		{
			InitializeComponent();
			parentForm = form;
			parentForm->disableMenu();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~LevelsForm()
		{
			if (components)
			{
				delete components;
			}
			parentForm->enableMenu();
		}
	private: MainForm^ parentForm;
	private: System::Windows::Forms::TrackBar^  trackBarR;
	protected:
	private: System::Windows::Forms::TrackBar^  trackBarG;
	private: System::Windows::Forms::TrackBar^  trackBarB;
	private: System::Windows::Forms::TextBox^  textBoxR;
	private: System::Windows::Forms::TextBox^  textBoxG;
	private: System::Windows::Forms::TextBox^  textBoxB;
	private: System::Windows::Forms::Label^  labelR;
	private: System::Windows::Forms::Label^  labelG;
	private: System::Windows::Forms::Label^  labelB;
	private: System::Windows::Forms::Button^  buttonApply;
	private: System::Windows::Forms::Button^  buttonCancel;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->trackBarR = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarG = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarB = (gcnew System::Windows::Forms::TrackBar());
			this->textBoxR = (gcnew System::Windows::Forms::TextBox());
			this->textBoxG = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->labelR = (gcnew System::Windows::Forms::Label());
			this->labelG = (gcnew System::Windows::Forms::Label());
			this->labelB = (gcnew System::Windows::Forms::Label());
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarB))->BeginInit();
			this->SuspendLayout();
			// 
			// trackBarR
			// 
			this->trackBarR->BackColor = System::Drawing::SystemColors::Control;
			this->trackBarR->Location = System::Drawing::Point(12, 53);
			this->trackBarR->Maximum = 127;
			this->trackBarR->Minimum = -127;
			this->trackBarR->Name = L"trackBarR";
			this->trackBarR->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarR->Size = System::Drawing::Size(45, 185);
			this->trackBarR->TabIndex = 0;
			this->trackBarR->TabStop = false;
			this->trackBarR->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBarR->Scroll += gcnew System::EventHandler(this, &LevelsForm::trackBarR_Scroll);
			this->trackBarR->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &LevelsForm::trackBarR_MouseUp);
			// 
			// trackBarG
			// 
			this->trackBarG->Location = System::Drawing::Point(80, 53);
			this->trackBarG->Maximum = 127;
			this->trackBarG->Minimum = -127;
			this->trackBarG->Name = L"trackBarG";
			this->trackBarG->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarG->Size = System::Drawing::Size(45, 185);
			this->trackBarG->TabIndex = 1;
			this->trackBarG->TabStop = false;
			this->trackBarG->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBarG->Scroll += gcnew System::EventHandler(this, &LevelsForm::trackBarG_Scroll);
			this->trackBarG->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &LevelsForm::trackBarG_MouseUp);
			// 
			// trackBarB
			// 
			this->trackBarB->Location = System::Drawing::Point(149, 53);
			this->trackBarB->Maximum = 127;
			this->trackBarB->Minimum = -127;
			this->trackBarB->Name = L"trackBarB";
			this->trackBarB->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarB->Size = System::Drawing::Size(45, 185);
			this->trackBarB->TabIndex = 2;
			this->trackBarB->TabStop = false;
			this->trackBarB->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBarB->Scroll += gcnew System::EventHandler(this, &LevelsForm::trackBarB_Scroll);
			this->trackBarB->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &LevelsForm::trackBarB_MouseUp);
			// 
			// textBoxR
			// 
			this->textBoxR->Location = System::Drawing::Point(12, 27);
			this->textBoxR->MaxLength = 7;
			this->textBoxR->Name = L"textBoxR";
			this->textBoxR->Size = System::Drawing::Size(30, 20);
			this->textBoxR->TabIndex = 0;
			this->textBoxR->Text = L"0";
			this->textBoxR->TextChanged += gcnew System::EventHandler(this, &LevelsForm::textBoxR_TextChanged);
			this->textBoxR->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &LevelsForm::textBoxR_KeyPress);
			this->textBoxR->Leave += gcnew System::EventHandler(this, &LevelsForm::textBoxR_Leave);
			// 
			// textBoxG
			// 
			this->textBoxG->Location = System::Drawing::Point(80, 27);
			this->textBoxG->MaxLength = 7;
			this->textBoxG->Name = L"textBoxG";
			this->textBoxG->Size = System::Drawing::Size(30, 20);
			this->textBoxG->TabIndex = 1;
			this->textBoxG->Text = L"0";
			this->textBoxG->TextChanged += gcnew System::EventHandler(this, &LevelsForm::textBoxG_TextChanged);
			this->textBoxG->Leave += gcnew System::EventHandler(this, &LevelsForm::textBoxG_Leave);
			// 
			// textBoxB
			// 
			this->textBoxB->Location = System::Drawing::Point(149, 27);
			this->textBoxB->MaxLength = 7;
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(30, 20);
			this->textBoxB->TabIndex = 2;
			this->textBoxB->Text = L"0";
			this->textBoxB->TextChanged += gcnew System::EventHandler(this, &LevelsForm::textBoxB_TextChanged);
			this->textBoxB->Leave += gcnew System::EventHandler(this, &LevelsForm::textBoxB_Leave);
			// 
			// labelR
			// 
			this->labelR->AutoSize = true;
			this->labelR->Location = System::Drawing::Point(16, 11);
			this->labelR->Name = L"labelR";
			this->labelR->Size = System::Drawing::Size(15, 13);
			this->labelR->TabIndex = 6;
			this->labelR->Text = L"R";
			// 
			// labelG
			// 
			this->labelG->AutoSize = true;
			this->labelG->Location = System::Drawing::Point(85, 11);
			this->labelG->Name = L"labelG";
			this->labelG->Size = System::Drawing::Size(15, 13);
			this->labelG->TabIndex = 7;
			this->labelG->Text = L"G";
			// 
			// labelB
			// 
			this->labelB->AutoSize = true;
			this->labelB->Location = System::Drawing::Point(155, 11);
			this->labelB->Name = L"labelB";
			this->labelB->Size = System::Drawing::Size(14, 13);
			this->labelB->TabIndex = 8;
			this->labelB->Text = L"B";
			// 
			// buttonApply
			// 
			this->buttonApply->Location = System::Drawing::Point(209, 27);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(95, 23);
			this->buttonApply->TabIndex = 9;
			this->buttonApply->Text = L"Apply";
			this->buttonApply->UseVisualStyleBackColor = true;
			this->buttonApply->Click += gcnew System::EventHandler(this, &LevelsForm::buttonApply_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(209, 56);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(95, 23);
			this->buttonCancel->TabIndex = 10;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &LevelsForm::buttonCancel_Click);
			// 
			// LevelsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 250);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonApply);
			this->Controls->Add(this->labelB);
			this->Controls->Add(this->labelG);
			this->Controls->Add(this->labelR);
			this->Controls->Add(this->textBoxB);
			this->Controls->Add(this->textBoxG);
			this->Controls->Add(this->textBoxR);
			this->Controls->Add(this->trackBarB);
			this->Controls->Add(this->trackBarG);
			this->Controls->Add(this->trackBarR);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"LevelsForm";
			this->Text = L"Channels";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &LevelsForm::LevelsForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarB))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void changeChannels();

	private: System::Void trackBarR_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

	private: System::Void trackBarG_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);	

	private: System::Void trackBarB_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	
	bool checkNumber(String^ number);

	bool checkNegNumber(String^ number);

	void checkChannelData(TextBox^ textBox);

	private: System::Void textBoxR_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void trackBarR_Scroll(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxR_Leave(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxG_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void trackBarG_Scroll(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxG_Leave(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxB_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxB_Leave(System::Object^  sender, System::EventArgs^  e);

	private: System::Void trackBarB_Scroll(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxR_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonApply_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void LevelsForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
