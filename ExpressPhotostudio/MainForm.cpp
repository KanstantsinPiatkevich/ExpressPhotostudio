#include "MainForm.h"
#include "ToolOptionsForm.h"
#include "ChromakeyForm.h"
#include "LevelsForm.h"

namespace ExpressPhotostudio{
	
	const short RED_INC = 49;
	const short GREEN_DEC = 14;
	const short GREEN_INC = 60;
	const short BLUE_DEC = 56;

	int getMaxValue(int value1, int value2)
	{
		if (value1 > value2)
			return value1;
		else
			return value2;
	}

	void MainForm::restorePicture()
	{
		if (startImage != nullptr)
		{
			pictureBoxImage->Image = startImage;
		}
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	void MainForm::restoreBrigtnessSets()
	{
		restorePicture();
		pic->setBrightness(0);
	}

	void MainForm::restoreHueSets()
	{
		restorePicture();
		pic->setHue(0);
	}

	void MainForm::restoreSaturationSets()
	{
		restorePicture();
		pic->setSaturation(0);
	}

	void MainForm::restoreContrastSets()
	{
		restorePicture();
		pic->setContrast(0);
	}

	void MainForm::restoreLightnessSets()
	{
		restorePicture();
		pic->setLightness(0);
	}

	void MainForm::assignBitmap()
	{
		if (startImage == nullptr)
		{
			startImage = gcnew Bitmap(pictureBoxImage->Image);
		}
	}

	void MainForm::changeBrightness(int propertyValue)
	{
		Bitmap^ image = gcnew Bitmap(startImage);
		int r, g, b;
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		IntPtr position;
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				if (*pos + propertyValue <= WHITE && *pos + propertyValue >= 0)
					b = *pos + propertyValue;
				else if (*pos + propertyValue > WHITE)
					b = WHITE;
				else
					b = 0;
				*pos = b;

				if (*(pos + 1) + propertyValue <= WHITE && *(pos + 1) + propertyValue >= 0)
					g = *(pos + 1) + propertyValue;
				else if (*(pos + 1) + propertyValue > WHITE)
					g = WHITE;
				else
					g = 0;
				*(pos + 1) = g;
			
				if (*(pos + 2) + propertyValue <= WHITE && *(pos + 2) + propertyValue >= 0)
					r = *(pos + 2) + propertyValue;
				else if (*(pos + 2) + propertyValue > WHITE)
					r = WHITE;
				else
					r = 0;
				*(pos + 2) = r;
				
				pos += 4;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		pic->setBrightness(propertyValue);
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	float MainForm::getHueFromRgb(Byte *pos)
	{
		int max = getMaxRgbValue(pos);
		int min = getMinRgbValue(pos);
		
		if (max == min)
		{
			return 400;
		}
		else if (*(pos + 2) == max)
		{
			if (*(pos + 1) >= *pos)
				return 60 * (*(pos + 1) - *pos) / (max - min);
			else
				return 60 * (*(pos + 1) - *pos) / (max - min) + 360;
		}
		else if (*(pos + 1) == max)
		{
			return 60 * (*pos - *(pos + 2)) / (max - min) + 120;
		}
		else if (*pos == max)
		{
			return 60 * (*(pos + 2) - *(pos + 1)) / (max - min) + 240;
		}
	}

	float MainForm::getSaturationFromRgb(Byte *pos)
	{
		float max = (float)getMaxRgbValue(pos) / 255;
		float min = (float)getMinRgbValue(pos) / 255;
		if (max == min)
			return 0;
		else
			return (float)(max - min) / (1 - abs(1 - (max + min)));
	}

	float MainForm::getLightnessFromRgb(Byte *pos)
	{
		float max = (float)getMaxRgbValue(pos) / WHITE;
		float min = (float)getMinRgbValue(pos) / WHITE;
		return (float)(max + min) / 2;
	}

	int getColor(float q, float l, float h)
	{
		if (h < 0.0)
			h = h + 1.0;
		if (h > 1.0)
			h = h - 1.0;
		if (((float)(h) < (1.0 / 6.0)))
			return (int)(((2 * l - q) + ((q - (2 * l - q)) * 6 * (h))) * 255.0);
		else if ((float)(h) >= (1.0 / 6.0) && ((float)(h) < (1.0 / 2.0)))
			return (int)(q * 255.0);
		else if ((float)(h) >= (1.0 / 2.0) && ((float)(h) < (2.0 / 3.0)))
			return (int)(((2 * l - q) + ((q - (2 * l - q)) * 6 * ((2.0 / 3.0) - h))) * 255.0);
		else
			return (int)((2 * l - q) * 255.0);
	}

	int setRgbRange(int value)
	{
		if (value < 0)
		{
			return 0;
		}
		else if (value > WHITE)
		{
			return WHITE;
		}
		return value;
	}

	void MainForm::changeHue(int propertyValue)
	{
		Bitmap^ image = gcnew Bitmap(startImage);
		int r, g, b;
		float saturation, lightness, hue;
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				hue = getHueFromRgb(pos);
				saturation = getSaturationFromRgb(pos);
				lightness = getLightnessFromRgb(pos);
				if (hue != 400)
				{
					if (hue + propertyValue <= 360 && hue + propertyValue >= 0)
						hue = hue + propertyValue;
					else if (hue + propertyValue > 360)
						hue = 360;
					else
						hue = 0;
					float q;
					if (lightness < 0.5)
						q = lightness * (1 + saturation);
					else
						q = lightness + saturation - (lightness * saturation);

					hue = hue / 360;
					r = getColor(q, lightness, hue + (float)(1.0 / 3.0));
					g = getColor(q, lightness, hue);
					b = getColor(q, lightness, hue - (float)(1.0 / 3.0));

					r = setRgbRange(r);
					g = setRgbRange(g);
					b = setRgbRange(b);

					*pos = b;
					*(pos + 1) = g;
					*(pos + 2) = r;
				}
				pos += 4;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		pic->setHue(propertyValue);
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	void MainForm::changeSaturation(int propertyValue)
	{
		Bitmap^ image = gcnew Bitmap(startImage);
		int r, g, b;
		float saturation, lightness, hue;
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		IntPtr position;
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				hue = getHueFromRgb(pos);
				saturation = getSaturationFromRgb(pos);
				lightness = getLightnessFromRgb(pos);
				if (hue != 400)
				{
					if (saturation + (float)(propertyValue / 100.0) <= 1.0 && saturation + (float)(propertyValue / 100.0) >= 0.0)
						saturation = saturation + (float)(propertyValue / 100.0);
					else if (saturation + (float)(propertyValue / 100.0) > 1.0)
						saturation = 1.0;
					else
						saturation = 0.0;
					float q;
					if (lightness < 0.5)
						q = lightness * (1 + saturation);
					else
						q = lightness + saturation - (lightness * saturation);

					hue = hue / 360;
					r = getColor(q, lightness, hue + (float)(1.0 / 3.0));
					g = getColor(q, lightness, hue);
					b = getColor(q, lightness, hue - (float)(1.0 / 3.0));
					
					r = setRgbRange(r);
					g = setRgbRange(g);
					b = setRgbRange(b);
					
					*pos = b;
					*(pos + 1) = g;
					*(pos + 2) = r;
				}
				pos += 4;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		pic->setSaturation(propertyValue);
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	void MainForm::changeContrast(int propertyValue)
	{
		Bitmap^ image = gcnew Bitmap(startImage);
		int r, g, b;
		float pixel;
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		IntPtr position;
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				pixel = (float)(*(pos + 2) / 255.0);
				pixel = pixel - 0.5;
				pixel = pixel * (float)((propertyValue + 100) / 100.0) * (float)((propertyValue + 100) / 100.0);
				pixel = pixel + 0.5;
				r = (int)(pixel * 255);

				pixel = (float)(*(pos + 1) / 255.0);
				pixel = pixel - 0.5;
				pixel = pixel * (float)((propertyValue + 100) / 100.0) * (float)((propertyValue + 100) / 100.0);
				pixel = pixel + 0.5;
				g = (int)(pixel * 255);

				pixel = (float)(*pos / 255.0);
				pixel = pixel - 0.5;
				pixel = pixel * (float)((propertyValue + 100) / 100.0) * (float)((propertyValue + 100) / 100.0);
				pixel = pixel + 0.5;
				b = (int)(pixel * 255);
				
				*(pos + 2) = setRgbRange(r);
				*(pos + 1) = setRgbRange(g);
				*pos = setRgbRange(b);
				
				pos += 4;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		pic->setContrast(propertyValue);
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	void MainForm::changeLightness(int propertyValue)
	{
		Bitmap^ image = gcnew Bitmap(startImage);
		int r, g, b;
		float saturation, lightness, hue;
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				hue = getHueFromRgb(pos);
				saturation = getSaturationFromRgb(pos);
				lightness = getLightnessFromRgb(pos);
				if (hue != 400)
				{
					if (lightness + (float)(propertyValue / 100.0) <= 1.0 && lightness + (float)(propertyValue / 100.0) >= 0.0)
						lightness = lightness + (float)(propertyValue / 100.0);
					else if (lightness + (float)(propertyValue / 100.0) > 1.0)
						lightness = 1.0;
					else
						lightness = 0.0;
					float q;
					if (lightness < 0.5)
						q = lightness * (1 + saturation);
					else
						q = lightness + saturation - (lightness * saturation);

					hue = hue / 360;
					r = getColor(q, lightness, hue + (float)(1.0 / 3.0));
					g = getColor(q, lightness, hue);
					b = getColor(q, lightness, hue - (float)(1.0 / 3.0));
					
					r = setRgbRange(r);
					g = setRgbRange(g);
					b = setRgbRange(b);
					
					*pos = b;
					*(pos + 1) = g;
					*(pos + 2) = r;
				}
				pos += 4;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		pic->setLightness(propertyValue);
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	void MainForm::createBlueAlphaMask(int threshold)
	{
		Bitmap^ image = gcnew Bitmap(startImage);
		int r, g, b, alpha = 255;
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				r = *(pos + 2);
				g = *(pos + 1);
				b = *pos;
				alpha = *(pos + 3);
				if (255 - *pos + getMaxValue(*(pos + 2), *(pos + 1)) >= threshold && alpha != 0)
				{
					alpha = 255 - *pos + getMaxValue(*(pos + 2), *(pos + 1));
					if (alpha > *(pos + 3))
						alpha = *(pos + 3);
					if (alpha > 255)
						alpha = 255;
				}
				else
					alpha = 0;
				*(pos + 3) = alpha;
				
				pos += 4;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	void MainForm::createGreenAlphaMask(int threshold)
	{
		Bitmap^ image = gcnew Bitmap(startImage);
		int alpha = 255;
		int r, g, b;
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				r = *(pos + 2);
				g = *(pos + 1);
				b = *pos;
				alpha = *(pos + 3);
				if (255 - *(pos + 1) + getMaxValue(*(pos + 2), *pos) >= threshold && alpha != 0)
				{
					alpha = 255 - *(pos + 1) + getMaxValue(*(pos + 2), *pos);
					if (alpha > *(pos + 3))
						alpha = *(pos + 3);
					if (alpha > 255)
						alpha = 255;
				}
				else
				{
					alpha = 0;
				}
				*(pos + 3) = alpha;
				
				pos += 4;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	void MainForm::enableMenu()
	{
		menuStripMain->Enabled = true;
		toolStripMain->Enabled = true;
	}

	void MainForm::disableMenu()
	{
		menuStripMain->Enabled = false;
		toolStripMain->Enabled = false;
	}

	void MainForm::changeChannels(int valueR, int valueG, int valueB)
	{
		Bitmap^ currImage = gcnew Bitmap(startImage);
		changeRedChannel(valueR, currImage);
		changeGreenChannel(valueG, currImage);
		changeBlueChannel(valueB, currImage);
		pictureBoxImage->Image = currImage;
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	void MainForm::changeRedChannel(int value, Bitmap^ currImage)
	{
		int red;
		System::Drawing::Imaging::BitmapData^ bmpData = currImage->LockBits(Rectangle(0, 0, currImage->Width, currImage->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				red = *(pos + 2);
				if (red + value > 255)
					red = 255;
				else if (red + value < 0)
					red = 0;
				else
					red = red + value;
				*(pos + 2) = red;
				pos += 4;
			}
		}
		currImage->UnlockBits(bmpData);
	}

	void MainForm::changeGreenChannel(int value, Bitmap^ currImage)
	{
		int green;
		System::Drawing::Imaging::BitmapData^ bmpData = currImage->LockBits(Rectangle(0, 0, currImage->Width, currImage->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				green = *(pos + 1);
				if (green + value > 255)
					green = 255;
				else if (green + value < 0)
					green = 0;
				else
					green = green + value;
				*(pos + 1) = green;
				pos += 4;
			}
		}
		currImage->UnlockBits(bmpData);
	}

	void MainForm::changeBlueChannel(int value, Bitmap^ currImage)
	{
		Bitmap^ image = gcnew Bitmap(pictureBoxImage->Image);
		int blue;
		System::Drawing::Imaging::BitmapData^ bmpData = currImage->LockBits(Rectangle(0, 0, currImage->Width, currImage->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format32bppArgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				blue = *pos;
				if (blue + value > 255)
					blue = 255;
				else if (blue + value < 0)
					blue = 0;
				else
					blue = blue + value;
				*pos = blue;
				
				pos += 4;
			}
		}
		currImage->UnlockBits(bmpData);
	}

	void MainForm::setDefaultImageBounds()
	{
		pictureBoxImage->Left = 15;
		pictureBoxImage->Top = 70;
		pictureBoxImage->Width = this->Width - panelAdd->Width - pictureBoxImage->Left * 3;
		pictureBoxImage->Height = this->Height - (pictureBoxImage->Top * 5) / 2;
	}

	void MainForm::setDefaultPanelBounds()
	{
		panelAdd->Width = this->Width / 10;
		panelAdd->Left = this->Left + this->Width - panelAdd->Width;
		panelAdd->Height = this->Height - panelAdd->Top - statusStrip->Height - 39;
		groupBoxInfo->Top = panelAdd->Height / 4 - groupBoxInfo->Height / 2;
		groupBoxBackground->Top = panelAdd->Height * 3 / 4 - groupBoxBackground->Height / 2;
	}

	void MainForm::getInfo(int x, int y)
	{
		Bitmap^ image = gcnew Bitmap(pictureBoxImage->Image);
		Color color = image->GetPixel(x, y);
		textBoxR->Text = color.R.ToString();
		textBoxG->Text = color.G.ToString();
		textBoxB->Text = color.B.ToString();
		labelColor->BackColor = color.FromArgb(color.A, color.R, color.G, color.B);
	}

	void MainForm::setInfo()
	{
		textBoxX->Text = "0";
		textBoxY->Text = "0";
		getInfo(0, 0);
	}

	void MainForm::alignImage()
	{
		if (pictureBoxImage->Image->Width < pictureBoxImage->Width && pictureBoxImage->Image->Height < pictureBoxImage->Height)
		{
			pictureBoxImage->SizeMode = PictureBoxSizeMode::Normal;
			pictureBoxImage->Width = pictureBoxImage->Image->Width;
			pictureBoxImage->Left = ((this->Width - panelAdd->Width) / 2) - (pictureBoxImage->Width / 2);
			pictureBoxImage->Height = pictureBoxImage->Image->Height;
			pictureBoxImage->Top = (this->Height / 2) - (pictureBoxImage->Height / 2);
		}
		else
		{
			pictureBoxImage->SizeMode = PictureBoxSizeMode::Zoom;
			if (pictureBoxImage->Image->Height < pictureBoxImage->Image->Width && pictureBoxImage->Image->Height > pictureBoxImage->Height)
			{
				pictureBoxImage->Width = (float)(pictureBoxImage->Height * pictureBoxImage->Image->Width) / (pictureBoxImage->Image->Height);
				pictureBoxImage->Left = ((this->Width - panelAdd->Width) / 2) - (pictureBoxImage->Width / 2);
			}
			else
			{
				pictureBoxImage->Width = (float)(pictureBoxImage->Height * pictureBoxImage->Image->Width) / (pictureBoxImage->Image->Height);
				pictureBoxImage->Left = ((this->Width - panelAdd->Width) / 2) - (pictureBoxImage->Width / 2);
				pictureBoxImage->Height = (float)(pictureBoxImage->Width * pictureBoxImage->Image->Height) / (pictureBoxImage->Image->Width);
				pictureBoxImage->Top = (this->Height / 2) - (pictureBoxImage->Height / 2);
			}
		}
	}

	System::Void MainForm::MainForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		setDefaultImageBounds();
		setDefaultPanelBounds();
	}

	void MainForm::enableActions()
	{
		toolStripButtonSvae->Enabled = true;
		toolStripButtonClear->Enabled = true;
		toolStripButtonLeftRotate->Enabled = true;
		toolStripButtonghtRotate->Enabled = true;
		toolStripLightness->Enabled = true;
		toolStripButtonHue->Enabled = true;
		toolStripButtonSaturation->Enabled = true;
		toolStripButtonBrightness->Enabled = true;
		toolStripButtonContrast->Enabled = true;
		toolStripButtonBlackAndWhite->Enabled = true;
		toolStripButtonNegative->Enabled = true;
		toolStripButtonNightSeek->Enabled = true;
		toolStripButtonSepia->Enabled = true;
		toolStripButtonKeying->Enabled = true;
		toolStripButtonChannels->Enabled = true;

		saveToolStripMenuItem->Enabled = true;
		clearToolStripMenuItem->Enabled = true;
		rotateOnLeftToolStripMenuItem->Enabled = true;
		rotateOnRightToolStripMenuItem->Enabled = true;
		lightnessToolStripMenuItem->Enabled = true;
		hueToolStripMenuItem->Enabled = true;
		saturationToolStripMenuItem->Enabled = true;
		brightnessToolStripMenuItem->Enabled = true;
		contrastToolStripMenuItem->Enabled = true;
		blackAndWhiteToolStripMenuItem->Enabled = true;
		negativeToolStripMenuItem->Enabled = true;
		pixelsToolStripMenuItem->Enabled = true;
		sepiaToolStripMenuItem->Enabled = true;
		blueToolStripMenuItem->Enabled = true;
		greenToolStripMenuItem->Enabled = true;

		panelAdd->Enabled = true;
	}

	void MainForm::disableActions()
	{
		toolStripButtonSvae->Enabled = false;
		toolStripButtonClear->Enabled = false;
		toolStripButtonLeftRotate->Enabled = false;
		toolStripButtonghtRotate->Enabled = false;
		toolStripLightness->Enabled = false;
		toolStripButtonHue->Enabled = false;
		toolStripButtonSaturation->Enabled = false;
		toolStripButtonBrightness->Enabled = false;
		toolStripButtonContrast->Enabled = false;
		toolStripButtonBlackAndWhite->Enabled = false;
		toolStripButtonNegative->Enabled = false;
		toolStripButtonNightSeek->Enabled = false;
		toolStripButtonSepia->Enabled = false;
		toolStripButtonKeying->Enabled = false;
		toolStripButtonChannels->Enabled = false;
	
		saveToolStripMenuItem->Enabled = false;
		clearToolStripMenuItem->Enabled = false;
		rotateOnLeftToolStripMenuItem->Enabled = false;
		rotateOnRightToolStripMenuItem->Enabled = false;
		lightnessToolStripMenuItem->Enabled = false;
		hueToolStripMenuItem->Enabled = false;
		saturationToolStripMenuItem->Enabled = false;
		brightnessToolStripMenuItem->Enabled = false;
		contrastToolStripMenuItem->Enabled = false;
		blackAndWhiteToolStripMenuItem->Enabled = false;
		negativeToolStripMenuItem->Enabled = false;
		pixelsToolStripMenuItem->Enabled = false;
		sepiaToolStripMenuItem->Enabled = false;
		blueToolStripMenuItem->Enabled = false;
		greenToolStripMenuItem->Enabled = false;

		panelAdd->Enabled = false;
	}

	void MainForm::openImage()
	{
		pictureBoxImage->Invalidate();
		openFileDialog->Filter = "PNG(*.png)|*.png|JPEG(*.jpg, *.jpeg)|*.jpg;*.jpeg|BMP(*.bmp)|*.bmp|Image files(*.png;*.jpg;*.jpeg;*.bmp)|*.png;*.jpg;*.jpeg;*.bmp";
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (openFileDialog->FileName != "")
			{
				setDefaultImageBounds();
				pictureBoxImage->Image = Image::FromFile(openFileDialog->FileName);
				alignImage();
				setInfo();
				toolStripStatusLabelBounds->Text = pictureBoxImage->Image->Width.ToString() + " x " + pictureBoxImage->Image->Height.ToString();
				enableActions();
			}
		}
	}

	System::Void MainForm::openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		openImage();
	}

	void MainForm::saveImage()
	{
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (saveFileDialog->FileName != "")
			{
				if (!saveFileDialog->FileName->Contains(".bmp") || saveFileDialog->FileName->Contains(".bmp") && MessageBox::Show("Transparence will be lost. Continue?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
				{
					Bitmap^ result = gcnew Bitmap(pictureBoxImage->Image);
					result->Save(saveFileDialog->FileName);
				}
			}
		}
	}

	System::Void MainForm::saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		saveImage();
	}

	void MainForm::clearPicture()
	{
		if (MessageBox::Show("Are you sure you want to clear picture?", "Clear", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			setDefaultImageBounds();
			pictureBoxImage->BackgroundImage = nullptr;
			pictureBoxImage->Image = nullptr;
			toolStripStatusLabelBounds->Text = "No image loaded";
			disableActions();
		}
	}

	System::Void MainForm::clearToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		clearPicture();
	}

	int MainForm::getMaxRgbValue(Byte *pos)
	{
		int max = *(pos + 2);
		if (max < *(pos + 1))
		{
			max = *(pos + 1);
		}
		if (max < *pos)
		{
			max = *pos;
		}
		return max;
	}

	int MainForm::getMinRgbValue(Byte *pos)
	{
		int min = *(pos + 2);
		if (min > *(pos + 1))
		{
			min = *(pos + 1);
		}
		if (min > *pos)
		{
			min = *pos;
		}
		return min;
	}

	void MainForm::applyBlackAndWhiteFilter()
	{
		Bitmap^ image = gcnew Bitmap(pictureBoxImage->Image);
		Bitmap^ startImage = gcnew Bitmap(pictureBoxImage->Image);
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				int tone = *(pos + 2) * 0.299 + *(pos + 1) * 0.587 + *pos * 0.114;
				tone = setRgbRange(tone);
				*(pos + 2) = tone;
				*(pos + 1) = tone;
				*pos = tone;
				pos += 3;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		if (MessageBox::Show("Are you sure you want to apply this filter", "Black and white", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
			pictureBoxImage->Image = startImage;
		else
			getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::blackAndWhiteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		applyBlackAndWhiteFilter();
	}

	void MainForm::applyNegativeFilter()
	{
		Bitmap^ image = gcnew Bitmap(pictureBoxImage->Image);
		Bitmap^ startImage = gcnew Bitmap(pictureBoxImage->Image);
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				*(pos + 2) = WHITE - *(pos + 2);
				*(pos + 1) = WHITE - *(pos + 1);
				*pos = WHITE - *pos;
				pos += 3;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		if (MessageBox::Show("Are you sure you want to apply this filter", "Negative", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
			pictureBoxImage->Image = startImage;
		else
			getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::negativeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		applyNegativeFilter();
	}

	void MainForm::applySepiaFilter()
	{
		Bitmap^ image = gcnew Bitmap(pictureBoxImage->Image);
		Bitmap^ startImage = gcnew Bitmap(pictureBoxImage->Image);
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		int r, g, b;
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				int tone = *(pos + 2) * 0.299 + *(pos + 1) * 0.587 + *pos * 0.114;
				if (tone > WHITE - RED_INC)
					r = WHITE;
				else
					r = tone + RED_INC;
				if (tone < GREEN_DEC)
					g = 0;
				else
					g = tone - GREEN_DEC;
				if (tone < BLUE_DEC)
					b = 0;
				else
					b = tone - BLUE_DEC;
				*(pos + 2) = r;
				*(pos + 1) = g;
				*pos = b;
				pos += 3;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		if (MessageBox::Show("Are you sure you want to apply this filter", "Sepia", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
		{
			pictureBoxImage->Image = startImage;
		}
		else
		{
			getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
		}
	}

	System::Void MainForm::sepiaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		applySepiaFilter();
	}

	const int LEFT = 0;
	const int RIGHT = 1;

	void MainForm::rotateImage(int direction)
	{
		Bitmap^ image = gcnew Bitmap(pictureBoxImage->Image);
		if (direction == LEFT)
			image->RotateFlip(RotateFlipType::Rotate90FlipXY);
		else
			image->RotateFlip(RotateFlipType::Rotate270FlipXY);
		pictureBoxImage->Invalidate();
		setDefaultImageBounds();
		pictureBoxImage->Image = image;
		alignImage();
	}

	System::Void MainForm::rotateOnLeftToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		rotateImage(LEFT);
	}

	System::Void MainForm::rotateOnRightToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		rotateImage(RIGHT);
	}

	int setNightRgbValue(int tone)
	{
		if (tone > (WHITE - GREEN_INC * 2))
		{
			tone = WHITE - GREEN_INC * 2;
		}
		return tone;
	}

	void MainForm::applyNightSeekFilter()
	{
		Bitmap^ image = gcnew Bitmap(pictureBoxImage->Image);
		Bitmap^ startImage = gcnew Bitmap(pictureBoxImage->Image);
		System::Drawing::Imaging::BitmapData^ bmpData = image->LockBits(Rectangle(0, 0, image->Width, image->Height), System::Drawing::Imaging::ImageLockMode::ReadWrite, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		for (int y = 0; y < pictureBoxImage->Image->Height; y++)
		{
			IntPtr position = ((IntPtr)bmpData->Scan0) + y * bmpData->Stride;
			Byte *pos = ((Byte *)position.ToPointer());
			for (int x = 0; x < pictureBoxImage->Image->Width; x++)
			{
				int tone = *(pos + 2) * 0.299 + *(pos + 1) * 0.587 + *pos * 0.114;
				tone = setNightRgbValue(tone);
				if (y % 6 == 0)
				{
					*(pos + 2) = tone;
					*(pos + 1) = tone + GREEN_INC * 2;
					*pos = tone;
				}
				else
				{
					*(pos + 2) = tone;
					*(pos + 1) = tone + GREEN_INC;
					*pos = tone;
				}
				pos += 3;
			}
		}
		image->UnlockBits(bmpData);
		pictureBoxImage->Image = image;
		if (MessageBox::Show("Are you sure you want to apply this filter", "Night seek", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No)
			pictureBoxImage->Image = startImage;
		else
			getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::pixelsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		applyNightSeekFilter();
	}

	void MainForm::setLightness()
	{
		startImage = nullptr;
		ToolOptionsForm^ form = gcnew ToolOptionsForm(this);
		form->Text = "Lightness";
		form->property = Lightness;
		form->setProperty(*pic);
		form->Show();
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::lightnessToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setLightness();
	}

	void MainForm::setHue()
	{
		startImage = nullptr;
		ToolOptionsForm^ form = gcnew ToolOptionsForm(this);
		form->Text = "Hue";
		form->property = Hue;
		form->setProperty(*pic);
		form->Show();
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::hueToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setHue();
	}

	void MainForm::setSaturation()
	{
		startImage = nullptr;
		ToolOptionsForm^ form = gcnew ToolOptionsForm(this);
		form->Text = "Saturation";
		form->property = Saturation;
		form->setProperty(*pic);
		form->Show();
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::saturationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setSaturation();
	}

	void MainForm::setBrightness()
	{
		startImage = nullptr;
		ToolOptionsForm^ form = gcnew ToolOptionsForm(this);
		form->Text = "Brightness";
		form->property = Brightness;
		form->setProperty(*pic);
		form->Show();
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::brightnessToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setBrightness();
	}

	void MainForm::setContrast()
	{
		startImage = nullptr;
		ToolOptionsForm^ form = gcnew ToolOptionsForm(this);
		form->Text = "Contrast";
		form->property = Contrast;
		form->setProperty(*pic);
		form->Show();
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::contrastToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setContrast();
	}

	void MainForm::setKeying()
	{
		startImage = nullptr;
		ChromakeyForm^ form = gcnew ChromakeyForm(this);
		form->Show();
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::blueToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setKeying();
	}

	void MainForm::setChannels()
	{
		startImage = nullptr;
		LevelsForm^ form = gcnew LevelsForm(this);
		form->Show();
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::greenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setChannels();
	}

	System::Void MainForm::toolStripButtonOpen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		openImage();
	}

	System::Void MainForm::toolStripButtonSvae_Click(System::Object^  sender, System::EventArgs^  e)
	{
		saveImage();
	}

	System::Void MainForm::toolStripLightness_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setLightness();
	}

	System::Void MainForm::toolStripButtonHue_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setHue();
	}

	System::Void MainForm::toolStripButtonSaturation_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setSaturation();
	}

	System::Void MainForm::toolStripButtonBrightness_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setBrightness();
	}

	System::Void MainForm::toolStripButtonContrast_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setContrast();
	}

	System::Void MainForm::buttonSelect_Click(System::Object^  sender, System::EventArgs^  e)
	{
		pictureBoxBackground->Invalidate();
		pictureBoxBackground->SetBounds(pictureBoxImage->Left, pictureBoxImage->Top, pictureBoxImage->Width, pictureBoxImage->Height);
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (openFileDialog->FileName != "")
			{
				pictureBoxImage->BackgroundImage = Image::FromFile(openFileDialog->FileName);
			}
		}
	}

	System::Void MainForm::pictureBoxImage_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{

	}

	bool MainForm::checkNumber(String^ number)
	{
		for (int i = 0; i < number->Length; i++)
		{
			if ((number[i] >= 'a' && number[i] <= 'z') || (number[i] >= 'A' && number[i] <= 'Z'))
				return false;
		}
		return true;
	}

	System::Void MainForm::textBoxX_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8)
			return;
		else
			e->KeyChar = 0;
	}

	System::Void MainForm::textBoxY_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar >= '0' && e->KeyChar <= '9') || e->KeyChar == 8)
			return;
		else
			e->KeyChar = 0;
	}

	System::Void MainForm::textBoxX_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!checkNumber(textBoxX->Text))
		{
			MessageBox::Show("Your input is not a number!", "Incorrect value", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxX->Text = "0";
		}
		if (textBoxX->Text == "")
		{
			textBoxX->Text = "0";
		}
		if (Int32::Parse(textBoxX->Text) > pictureBoxImage->Image->Width - 1)
		{
			MessageBox::Show("The maximum acceptable value is " + (pictureBoxImage->Image->Width - 1).ToString() + "!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxX->Text = (pictureBoxImage->Image->Width - 1).ToString();
		}
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::textBoxX_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		textBoxX->Text = Int32::Parse(textBoxX->Text).ToString();
	}

	System::Void MainForm::textBoxY_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (!checkNumber(textBoxY->Text))
		{
			MessageBox::Show("Your input is not a number!", "Incorrect value", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxY->Text = "0";
		}
		if (textBoxY->Text == "")
		{
			textBoxY->Text = "0";
		}
		if (Int32::Parse(textBoxY->Text) > pictureBoxImage->Image->Height - 1)
		{
			MessageBox::Show("The maximum acceptable value is " + (pictureBoxImage->Image->Height - 1).ToString() + "!", "Value out of range", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBoxY->Text = (pictureBoxImage->Image->Height - 1).ToString();
		}
		getInfo(Int32::Parse(textBoxX->Text), Int32::Parse(textBoxY->Text));
	}

	System::Void MainForm::textBoxY_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		textBoxY->Text = Int32::Parse(textBoxY->Text).ToString();
	}

	void MainForm::showInfo()
	{
		MessageBox::Show("Made by Piakevich Konstantsin, student of BSUIR, group 551001.\nVersion Release 1.0.0\n2016, All rights reserved", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void MainForm::authorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		showInfo();
	}

	System::Void MainForm::toolStripButtonBlackAndWhite_Click(System::Object^  sender, System::EventArgs^  e)
	{
		applyBlackAndWhiteFilter();
	}

	System::Void MainForm::toolStripButtonNegative_Click(System::Object^  sender, System::EventArgs^  e)
	{
		applyNegativeFilter();
	}

	System::Void MainForm::toolStripButtonNightSeek_Click(System::Object^  sender, System::EventArgs^  e)
	{
		applyNightSeekFilter();
	}

	System::Void MainForm::toolStripButtonSepia_Click(System::Object^  sender, System::EventArgs^  e)
	{
		applySepiaFilter();
	}

	System::Void MainForm::toolStripButtonClear_Click(System::Object^  sender, System::EventArgs^  e)
	{
		clearPicture();
	}

	System::Void MainForm::toolStripButtonLeftRotate_Click(System::Object^  sender, System::EventArgs^  e)
	{
		rotateImage(LEFT);
	}

	System::Void MainForm::toolStripButtonghtRotate_Click(System::Object^  sender, System::EventArgs^  e)
	{
		rotateImage(RIGHT);
	}

	System::Void MainForm::toolStripButtonKeying_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setKeying();
	}

	System::Void MainForm::toolStripButtonChannels_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setChannels();
	}

	System::Void MainForm::toolStripButtonAuthor_Click(System::Object^  sender, System::EventArgs^  e)
	{
		showInfo();
	}

}

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ExpressPhotostudio::MainForm form;
	Application::Run(%form);
}
