#include "Pic.h"

Pic::Pic(int brightness, int hue, int saturation, int contrast, int lightness)
{
	this->brightness = brightness;
	this->hue = hue;
	this->saturation = saturation;
	this->contrast = contrast;
	this->lightness = lightness;
}

void Pic::setBrightness(int value)
{
	brightness = value;
}

void Pic::setContrast(int value)
{
	contrast = value;
}
void Pic::setHue(int value)
{
	hue = value;
}

void Pic::setSaturation(int value)
{
	saturation = value;
}
	
void Pic::setLightness(int value)
{
	lightness = value;
}

int Pic::getBrightness()
{
	return brightness;
}

int Pic::getHue()
{
	return hue;
}

int Pic::getSaturation()
{
	return saturation;
}

int Pic::getContrast()
{
	return contrast;
}

int Pic::getLightness()
{
	return contrast;
}
