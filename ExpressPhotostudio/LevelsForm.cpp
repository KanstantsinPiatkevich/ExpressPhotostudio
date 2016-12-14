#include "LevelsForm.h"

namespace ExpressPhotostudio
{

	void LevelsForm::changeChannels()
	{
		parentForm->assignBitmap();
		parentForm->changeChannels(trackBarR->Value, trackBarG->Value, trackBarB->Value);
	}

	System::Void LevelsForm::trackBarR_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		changeChannels();
	}

	System::Void LevelsForm::trackBarG_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		changeChannels();
	}	

	System::Void LevelsForm::trackBarB_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		changeChannels();
	}

	bool LevelsForm::checkNumber(String^ number)
	{
		for (int i = 0; i < number->Length; i++)
		{
			if ((number[i] >= 'a' && number[i] <= 'z') || (number[i] >= 'A' && number[i] <= 'Z'))
				return false;
		}
		return true;
	}

	bool LevelsForm::checkNegNumber(String^ number)
	{
		for (int i = 0; i < number->Length; i++)
		{
			if ((number[i] == '-' && (i != 0 || number->Length == 1)) || ((number[i] < '0' || number[i] > '9') && number[i] != '-'))
				return false;
		}
		return true;
	}

	void LevelsForm::checkChannelData(TextBox^ textBox)
	{
		if (textBox->Text == "")
		{
			textBox->Text = "0";
		}
		if (checkNegNumber(textBox->Text))
		{
			if (Int32::Parse(textBox->Text) > 127)
			{
				MessageBox::Show("The maximum acceptable value is 127!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				textBox->Text = "127";
			}
			else if (Int32::Parse(textBox->Text) < -127)
			{
				MessageBox::Show("The minimum acceptable value is -127!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				textBox->Text = "-127";
			}
		}
		else
		{
			MessageBox::Show("Your input is not a number!", "Incorrect value", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox->Text = "0";
		}
	}

	System::Void LevelsForm::textBoxR_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == '-')
			return;
		else
			e->KeyChar = 0;
	}

	System::Void LevelsForm::textBoxR_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!checkNumber(textBoxR->Text))
		{
			MessageBox::Show("Your input is not a number!", "Incorrect value", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxR->Text = "0";
		}
		if (textBoxR->Text != "" && checkNegNumber(textBoxR->Text))
		{
			if (Int32::Parse(textBoxR->Text) <= 127 && Int32::Parse(textBoxR->Text) >= -127)
			{
				trackBarR->Value = Int32::Parse(textBoxR->Text);
			}
		}
	}

	System::Void LevelsForm::trackBarR_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		textBoxR->Text = trackBarR->Value.ToString();
	}

	System::Void LevelsForm::textBoxR_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		checkChannelData(textBoxR);
		textBoxR->Text = Int32::Parse(textBoxR->Text).ToString();
		changeChannels();
		trackBarR->Value = Int32::Parse(textBoxR->Text);
	}

	System::Void LevelsForm::textBoxG_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!checkNumber(textBoxG->Text))
		{
			MessageBox::Show("Your input is not a number!", "Incorrect value", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxG->Text = "0";
		}
		if (textBoxG->Text != "" && checkNegNumber(textBoxG->Text))
		{
			if (Int32::Parse(textBoxG->Text) <= 127 && Int32::Parse(textBoxG->Text) >= -127)
			{
				trackBarG->Value = Int32::Parse(textBoxG->Text);
			}
		}
	}

	System::Void LevelsForm::trackBarG_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		textBoxG->Text = trackBarG->Value.ToString();
	}

	System::Void LevelsForm::textBoxG_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		checkChannelData(textBoxG);
		textBoxG->Text = Int32::Parse(textBoxG->Text).ToString();
		changeChannels();
		trackBarG->Value = Int32::Parse(textBoxG->Text);
	}

	System::Void LevelsForm::textBoxB_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!checkNumber(textBoxB->Text))
		{
			MessageBox::Show("Your input is not a number!", "Incorrect value", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxB->Text = "0";
		}
		if (textBoxB->Text != "" && checkNegNumber(textBoxB->Text))
		{
			if (Int32::Parse(textBoxB->Text) <= 127 && Int32::Parse(textBoxB->Text) >= -127)
			{
				trackBarB->Value = Int32::Parse(textBoxB->Text);
			}
		}
	}

	System::Void LevelsForm::trackBarB_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		textBoxB->Text = trackBarB->Value.ToString();
	}

	System::Void LevelsForm::textBoxB_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		checkChannelData(textBoxB);
		textBoxB->Text = Int32::Parse(textBoxB->Text).ToString();
		changeChannels();
		trackBarB->Value = Int32::Parse(textBoxB->Text);
	}

	System::Void LevelsForm::buttonCancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		parentForm->restorePicture();
		this->Close();
	}

	System::Void LevelsForm::buttonApply_Click(System::Object^  sender, System::EventArgs^  e)
	{
		parentForm->startImage = nullptr;
		this->Close();
	}
	System::Void LevelsForm::LevelsForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		parentForm->restorePicture();
	}
}