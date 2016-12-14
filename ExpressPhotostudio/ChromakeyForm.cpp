#include "ChromakeyForm.h"

namespace ExpressPhotostudio
{

	void ChromakeyForm::selectColor()
	{
		switch (comboBoxColor->SelectedIndex)
		{
		case 1:
			parentForm->assignBitmap();
			parentForm->createGreenAlphaMask(treshold);
			textBoxTreshold->Enabled = true;
			trackBarTreshold->Enabled = true;
			break;
		case 0:
			parentForm->assignBitmap();
			parentForm->createBlueAlphaMask(treshold);
			textBoxTreshold->Enabled = true;
			trackBarTreshold->Enabled = true;
			break;
		case 2:
			parentForm->restorePicture();
			textBoxTreshold->Enabled = false;
			trackBarTreshold->Enabled = false;
		}
	}

	System::Void ChromakeyForm::comboBoxColor_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{	
		selectColor();
		trackBarTreshold->Value = 0;
		textBoxTreshold->Text = "0";
	}

	System::Void ChromakeyForm::trackBarTreshold_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		treshold = trackBarTreshold->Value + 100;
		textBoxTreshold->Text = trackBarTreshold->Value.ToString();
		selectColor();
	}

	System::Void ChromakeyForm::buttonApply_Click(System::Object^  sender, System::EventArgs^  e)
	{
		parentForm->startImage = nullptr;
		this->Close();
	}

	System::Void ChromakeyForm::buttonCancel_Click(System::Object^  sender, System::EventArgs^  e)
	{
		parentForm->restorePicture();
		this->Close();
	}

	System::Void ChromakeyForm::textBoxTreshold_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8)
			return;
		else
			e->KeyChar = 0;
	}

	bool ChromakeyForm::checkNumber(String^ number)
	{
		for (int i = 0; i < number->Length; i++)
		{
			if ((number[i] >= 'a' && number[i] <= 'z') || (number[i] >= 'A' && number[i] <= 'Z'))
				return false;
		}
		return true;
	}

	System::Void ChromakeyForm::textBoxTreshold_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!checkNumber(textBoxTreshold->Text))
		{
			MessageBox::Show("Your input is not a number!", "Incorrect value", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxTreshold->Text = "0";
		}
		if (textBoxTreshold->Text != "")
		{
			if (Int32::Parse(textBoxTreshold->Text) >= 0 && Int32::Parse(textBoxTreshold->Text) <= 150)
			{
				trackBarTreshold->Value = Int32::Parse(textBoxTreshold->Text);
			}
		}
	}

	System::Void ChromakeyForm::trackBarTreshold_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		textBoxTreshold->Text = trackBarTreshold->Value.ToString();
	}

	System::Void ChromakeyForm::textBoxTreshold_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBoxTreshold->Text == "")
		{
			textBoxTreshold->Text = "0";
		}
		if (Int32::Parse(textBoxTreshold->Text) > 150)
		{
			MessageBox::Show("The maximum acceptable value is 150!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			textBoxTreshold->Text = "150";
		}
		else if (Int32::Parse(textBoxTreshold->Text) < 0)
		{
			MessageBox::Show("The minimum acceptable value is 0!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			textBoxTreshold->Text = "0";
		}
		textBoxTreshold->Text = Int32::Parse(textBoxTreshold->Text).ToString();
		treshold = trackBarTreshold->Value + 100;
		selectColor();
	}

	System::Void ChromakeyForm::ChromakeyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		parentForm->restorePicture();
	}
}