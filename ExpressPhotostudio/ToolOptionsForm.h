#include <stdlib.h>
#include <string>
#include "MainForm.h"

#pragma once

enum prop { Brightness, Hue, Saturation, Contrast, Lightness };

namespace ExpressPhotostudio {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ToolOptionsForm
	/// </summary>
	public ref class ToolOptionsForm : public System::Windows::Forms::Form
	{
	public:
		prop property;
		ToolOptionsForm(MainForm^ parent)
		{
			InitializeComponent();
			parentForm = parent;
			parentForm->disableMenu();
			//
			//TODO: добавьте код конструктора
			//
		}

		void setProperty(Pic pic);
		
	private: System::Windows::Forms::Button^  buttonApply;
	public:
	private: System::Windows::Forms::Button^  buttonCancel;

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ToolOptionsForm()
		{
			if (components)
			{
				delete components;
			}
			parentForm->enableMenu();
		}
	private: MainForm^ parentForm;
	private: System::Windows::Forms::TrackBar^  trackBarValue;
	private: System::Windows::Forms::Label^  labelProperty;
	private: System::Windows::Forms::TextBox^  textBoxValue;

	protected:

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
			this->trackBarValue = (gcnew System::Windows::Forms::TrackBar());
			this->labelProperty = (gcnew System::Windows::Forms::Label());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarValue))->BeginInit();
			this->SuspendLayout();
			// 
			// trackBarValue
			// 
			this->trackBarValue->Location = System::Drawing::Point(12, 60);
			this->trackBarValue->Maximum = 100;
			this->trackBarValue->Minimum = -100;
			this->trackBarValue->Name = L"trackBarValue";
			this->trackBarValue->Size = System::Drawing::Size(267, 45);
			this->trackBarValue->TabIndex = 0;
			this->trackBarValue->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBarValue->Scroll += gcnew System::EventHandler(this, &ToolOptionsForm::trackBarValue_Scroll);
			this->trackBarValue->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ToolOptionsForm::trackBarValue_MouseUp);
			// 
			// labelProperty
			// 
			this->labelProperty->AutoSize = true;
			this->labelProperty->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelProperty->Location = System::Drawing::Point(18, 34);
			this->labelProperty->Name = L"labelProperty";
			this->labelProperty->Size = System::Drawing::Size(65, 15);
			this->labelProperty->TabIndex = 1;
			this->labelProperty->Text = L"Brightness";
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(89, 34);
			this->textBoxValue->MaxLength = 7;
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(30, 20);
			this->textBoxValue->TabIndex = 2;
			this->textBoxValue->TextChanged += gcnew System::EventHandler(this, &ToolOptionsForm::textBoxValue_TextChanged);
			this->textBoxValue->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ToolOptionsForm::textBoxValue_KeyPress);
			this->textBoxValue->Leave += gcnew System::EventHandler(this, &ToolOptionsForm::textBoxValue_Leave);
			// 
			// buttonApply
			// 
			this->buttonApply->Location = System::Drawing::Point(293, 31);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(102, 23);
			this->buttonApply->TabIndex = 3;
			this->buttonApply->Text = L"Apply";
			this->buttonApply->UseVisualStyleBackColor = true;
			this->buttonApply->Click += gcnew System::EventHandler(this, &ToolOptionsForm::buttonApply_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(293, 60);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(102, 23);
			this->buttonCancel->TabIndex = 4;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &ToolOptionsForm::buttonCancel_Click);
			// 
			// ToolOptionsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(411, 106);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonApply);
			this->Controls->Add(this->textBoxValue);
			this->Controls->Add(this->labelProperty);
			this->Controls->Add(this->trackBarValue);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"ToolOptionsForm";
			this->Text = L"ToolOptionsForm";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ToolOptionsForm::ToolOptionsForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarValue))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void trackBarValue_Scroll(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void buttonApply_Click(System::Object^  sender, System::EventArgs^  e);
	
	void cancelChanges();

	private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e);

	void changePicture();
	
	private: System::Void trackBarValue_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	
	private: System::Void textBoxValue_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
		
	private: System::Void textBoxValue_TextChanged(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void textBoxValue_Leave(System::Object^  sender, System::EventArgs^  e);

	bool checkNumber(String^ number);

	bool checkNegNumber(String^ number);

	private: System::Void ToolOptionsForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};

}