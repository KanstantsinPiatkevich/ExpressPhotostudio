#ifndef PIC_H
#define PIC_H

class Pic
{
public:
	Pic(int, int, int, int, int);

	void setBrightness(int);
	void setContrast(int);
	void setHue(int);
	void setSaturation(int);
	void setLightness(int);
	int getBrightness();
	int getHue();
	int getSaturation();
	int getContrast();
	int getLightness();
private:
	int brightness;
	int contrast;
	int hue;
	int saturation;
	int lightness;
};

#endif