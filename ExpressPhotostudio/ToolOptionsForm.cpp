#include "ToolOptionsForm.h"

namespace ExpressPhotostudio
{

	void ToolOptionsForm::setProperty(Pic pic)
	{
		trackBarValue->Value = 0;
		switch (property)
		{
			case Brightness:
			{
				//::Drawing::Icon^ icon = gcnew System::Drawing::Icon("D:\\Прога\\ЯП\\Курсовая\\Файлы программы\\AdditionalFiles\\Brightness.png");
				//this->Icon = icon;
				labelProperty->Text = "Brightness";
				trackBarValue->Maximum = 100;
				trackBarValue->Minimum = -100;
				textBoxValue->Text = pic.getBrightness().ToString();
				textBoxValue->Left = labelProperty->Left + labelProperty->Width + 6;
				break;
			}
			case Hue:
			{
				labelProperty->Text = "Hue";
				trackBarValue->Maximum = 180;
				trackBarValue->Minimum = -180;
				textBoxValue->Text = pic.getHue().ToString();
				textBoxValue->Left = labelProperty->Left + labelProperty->Width + 6;
				break;
			}
			case Saturation:
			{
				labelProperty->Text = "Saturation";
				trackBarValue->Maximum = 100;
				trackBarValue->Minimum = -100;
				textBoxValue->Text = pic.getSaturation().ToString();
				textBoxValue->Left = labelProperty->Left + labelProperty->Width + 6;
				break;
			}
			case Contrast:
			{
				labelProperty->Text = "Contrast";
				trackBarValue->Maximum = 100;
				trackBarValue->Minimum = -100;
				textBoxValue->Text = pic.getContrast().ToString();
				textBoxValue->Left = labelProperty->Left + labelProperty->Width + 6;
				break;
			}
			case Lightness:
			{
				labelProperty->Text = "Lightness";
				trackBarValue->Maximum = 100;
				trackBarValue->Minimum = -100;
				textBoxValue->Text = pic.getLightness().ToString();
				textBoxValue->Left = labelProperty->Left + labelProperty->Width + 6;
				break;
			}
		}
	}

	System::Void ToolOptionsForm::trackBarValue_Scroll(System::Object^  sender, System::EventArgs^  e) 
	{
		textBoxValue->Text = trackBarValue->Value.ToString();
	}

	System::Void ToolOptionsForm::buttonApply_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		switch (this->property)
		{
		case Brightness:
			parentForm->pic->setBrightness(0);
			break;
		case Hue:
			parentForm->pic->setHue(0);
			break;
		case Saturation:
			parentForm->pic->setSaturation(0);
			break;
		case Lightness:
			parentForm->pic->setLightness(0);
			break;
		case Contrast:
			parentForm->pic->setContrast(0);
			break;
		}
		parentForm->startImage = nullptr;
		this->Close();
	}

	void ToolOptionsForm::cancelChanges()
	{
		switch (this->property)
		{
		case Brightness:
			parentForm->restoreBrigtnessSets();
			break;
		case Contrast:
			parentForm->restoreContrastSets();
			break;
		case Hue:
			parentForm->restoreHueSets();
			break;
		case Lightness:
			parentForm->restoreLightnessSets();
			break;
		case Saturation:
			parentForm->restoreSaturationSets();
			break;
		}
	}

	System::Void ToolOptionsForm::buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		cancelChanges();
		this->Close();
	}

	void ToolOptionsForm::changePicture()
	{
		parentForm->assignBitmap();
		switch (this->property)
		{
		case Brightness:
			parentForm->changeBrightness(trackBarValue->Value);
			break;
		case Hue:
			parentForm->changeHue(trackBarValue->Value);
			break;
		case Saturation:
			parentForm->changeSaturation(trackBarValue->Value);
			break;
		case Contrast:
			parentForm->changeContrast(trackBarValue->Value);
			break;
		case Lightness:
			parentForm->changeLightness(trackBarValue->Value);
			break;
		}
	}

	System::Void ToolOptionsForm::trackBarValue_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		changePicture();
	}

	System::Void ToolOptionsForm::textBoxValue_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == '-')
			return;
		else
			e->KeyChar = 0;
	}

	bool ToolOptionsForm::checkNumber(String^ number)
	{
		for (int i = 0; i < number->Length; i++)
		{
			if ((number[i] >= 'a' && number[i] <= 'z') || (number[i] >= 'A' && number[i] <= 'Z'))
				return false;
		}
		return true;
	}

	bool ToolOptionsForm::checkNegNumber(String^ number)
	{
		for (int i = 0; i < number->Length; i++)
		{
			if (number[i] == '-' && (i != 0 || number->Length == 1))
				return false;
		}
		return true;
	}

	System::Void ToolOptionsForm::textBoxValue_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!checkNumber(textBoxValue->Text))
		{
			MessageBox::Show("Your input is not a number!", "Incorrect value", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxValue->Text = "0";
		}
		if (textBoxValue->Text != "" && checkNegNumber(textBoxValue->Text))
		{
			switch (property)
			{
			case Brightness:
			case Saturation:
			case Lightness:
			case Contrast:
				if (Int32::Parse(textBoxValue->Text) >= -100 && Int32::Parse(textBoxValue->Text) <= 100)
				{
					trackBarValue->Value = Int32::Parse(textBoxValue->Text);
				}
				break;
			case Hue:
				if (Int32::Parse(textBoxValue->Text) >= -180 && Int32::Parse(textBoxValue->Text) <= 180)
				{
					trackBarValue->Value = Int32::Parse(textBoxValue->Text);
				}
				break;
			}
		}
	}

	System::Void ToolOptionsForm::textBoxValue_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBoxValue->Text == "")
		{
			textBoxValue->Text = "0";
		}
		if (checkNegNumber(textBoxValue->Text))
		{
			switch (property)
			{
			case Brightness:
			case Saturation:
			case Lightness:
			case Contrast:
				if (Int32::Parse(textBoxValue->Text) > 100)
				{
					MessageBox::Show("The maximum acceptable value is 100!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Error);
					textBoxValue->Text = "100";
				}
				else if (Int32::Parse(textBoxValue->Text) < -100)
				{
					MessageBox::Show("The minimum acceptable value is -100!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Error);
					textBoxValue->Text = "-100";
				}
				break;
			case Hue:
				if (Int32::Parse(textBoxValue->Text) > 180)
				{
					MessageBox::Show("The maximum acceptable value is 180!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Error);
					textBoxValue->Text = "180";
				}
				if (Int32::Parse(textBoxValue->Text) < -180)
				{
					MessageBox::Show("The minimum acceptable value is -180!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Error);
					textBoxValue->Text = "-180";
				}
				break;
			}
		}
		else
		{
			MessageBox::Show("Your input is not a number!", "Incorrect value", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxValue->Text = "0";
		}
		textBoxValue->Text = Int32::Parse(textBoxValue->Text).ToString();
		changePicture();
	}

	System::Void ToolOptionsForm::ToolOptionsForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		cancelChanges();
	}

}

