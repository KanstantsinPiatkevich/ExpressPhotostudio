#pragma once

#include "MainForm.h"

namespace ExpressPhotostudio {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ChromakeyForm
	/// </summary>
	public ref class ChromakeyForm : public System::Windows::Forms::Form
	{
	public:
		ChromakeyForm(MainForm^ parent)
		{
			InitializeComponent();
			parentForm = parent;
			comboBoxColor->SelectedIndex = 2;
			treshold = 100;
			trackBarTreshold->Value = 0;
			textBoxTreshold->Text = "0";
			parentForm->disableMenu();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ChromakeyForm()
		{
			if (components)
			{
				delete components;
			}
			parentForm->enableMenu();
		}
	private: MainForm^ parentForm;
	private: int treshold;

	protected:

	private: System::Windows::Forms::Button^  buttonApply;

	private: System::Windows::Forms::Label^  labelColor;
	private: System::Windows::Forms::ComboBox^  comboBoxColor;
	private: System::Windows::Forms::TrackBar^  trackBarTreshold;
	private: System::Windows::Forms::Label^  labelTreshold;
	private: System::Windows::Forms::TextBox^  textBoxTreshold;
	private: System::Windows::Forms::Button^  buttonCancel;




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
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			this->comboBoxColor = (gcnew System::Windows::Forms::ComboBox());
			this->labelColor = (gcnew System::Windows::Forms::Label());
			this->trackBarTreshold = (gcnew System::Windows::Forms::TrackBar());
			this->labelTreshold = (gcnew System::Windows::Forms::Label());
			this->textBoxTreshold = (gcnew System::Windows::Forms::TextBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarTreshold))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonApply
			// 
			this->buttonApply->Location = System::Drawing::Point(151, 40);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(96, 21);
			this->buttonApply->TabIndex = 2;
			this->buttonApply->Text = L"Apply";
			this->buttonApply->UseVisualStyleBackColor = true;
			this->buttonApply->Click += gcnew System::EventHandler(this, &ChromakeyForm::buttonApply_Click);
			// 
			// comboBoxColor
			// 
			this->comboBoxColor->DisplayMember = L"mnkk";
			this->comboBoxColor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxColor->FormattingEnabled = true;
			this->comboBoxColor->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->comboBoxColor->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Blue", L"Green", L"None" });
			this->comboBoxColor->Location = System::Drawing::Point(12, 40);
			this->comboBoxColor->Name = L"comboBoxColor";
			this->comboBoxColor->Size = System::Drawing::Size(121, 21);
			this->comboBoxColor->TabIndex = 3;
			this->comboBoxColor->SelectedIndexChanged += gcnew System::EventHandler(this, &ChromakeyForm::comboBoxColor_SelectedIndexChanged);
			// 
			// labelColor
			// 
			this->labelColor->AutoSize = true;
			this->labelColor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelColor->Location = System::Drawing::Point(12, 17);
			this->labelColor->Name = L"labelColor";
			this->labelColor->Size = System::Drawing::Size(92, 15);
			this->labelColor->TabIndex = 4;
			this->labelColor->Text = L"Select key color";
			// 
			// trackBarTreshold
			// 
			this->trackBarTreshold->Location = System::Drawing::Point(12, 105);
			this->trackBarTreshold->Maximum = 150;
			this->trackBarTreshold->Name = L"trackBarTreshold";
			this->trackBarTreshold->Size = System::Drawing::Size(235, 45);
			this->trackBarTreshold->TabIndex = 5;
			this->trackBarTreshold->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBarTreshold->Scroll += gcnew System::EventHandler(this, &ChromakeyForm::trackBarTreshold_Scroll);
			this->trackBarTreshold->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ChromakeyForm::trackBarTreshold_MouseUp);
			// 
			// labelTreshold
			// 
			this->labelTreshold->AutoSize = true;
			this->labelTreshold->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTreshold->Location = System::Drawing::Point(12, 81);
			this->labelTreshold->Name = L"labelTreshold";
			this->labelTreshold->Size = System::Drawing::Size(55, 15);
			this->labelTreshold->TabIndex = 6;
			this->labelTreshold->Text = L"Treshold";
			// 
			// textBoxTreshold
			// 
			this->textBoxTreshold->Location = System::Drawing::Point(73, 81);
			this->textBoxTreshold->MaxLength = 7;
			this->textBoxTreshold->Name = L"textBoxTreshold";
			this->textBoxTreshold->Size = System::Drawing::Size(30, 20);
			this->textBoxTreshold->TabIndex = 7;
			this->textBoxTreshold->TextChanged += gcnew System::EventHandler(this, &ChromakeyForm::textBoxTreshold_TextChanged);
			this->textBoxTreshold->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ChromakeyForm::textBoxTreshold_KeyPress);
			this->textBoxTreshold->Leave += gcnew System::EventHandler(this, &ChromakeyForm::textBoxTreshold_Leave);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(151, 65);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(96, 23);
			this->buttonCancel->TabIndex = 8;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &ChromakeyForm::buttonCancel_Click);
			// 
			// ChromakeyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(270, 143);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->textBoxTreshold);
			this->Controls->Add(this->labelTreshold);
			this->Controls->Add(this->trackBarTreshold);
			this->Controls->Add(this->labelColor);
			this->Controls->Add(this->comboBoxColor);
			this->Controls->Add(this->buttonApply);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"ChromakeyForm";
			this->Text = L"Chromakey";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ChromakeyForm::ChromakeyForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarTreshold))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	void selectColor();

	bool checkNumber(String^ number);

	private: System::Void comboBoxColor_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void trackBarTreshold_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

	private: System::Void buttonApply_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxTreshold_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);
	
	private: System::Void textBoxTreshold_TextChanged(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void trackBarTreshold_Scroll(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxTreshold_Leave(System::Object^  sender, System::EventArgs^  e);

	private: System::Void ChromakeyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e);
};
}
