#include <cmath>

#pragma once

#include "Pic.h"

const short WHITE = 255;

namespace ExpressPhotostudio {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::ToolStrip^  toolStripMain;
	private: System::Windows::Forms::ToolStripButton^  toolStripLightness;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonHue;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonSaturation;



	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonBrightness;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonContrast;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonOpen;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonSvae;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonClear;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonLeftRotate;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonghtRotate;



	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonBlackAndWhite;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonNegative;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonNightSeek;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonSepia;




	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonKeying;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonChannels;


	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonAuthor;


	private: System::Windows::Forms::Panel^  panelAdd;



	private: System::Windows::Forms::Button^  buttonSelect;
	private: System::Windows::Forms::GroupBox^  groupBoxInfo;



	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;
	private: System::Windows::Forms::GroupBox^  groupBoxBackground;

	private: System::Windows::Forms::PictureBox^  pictureBoxBackImage;
	private: System::Windows::Forms::PictureBox^  pictureBoxBackground;
	private: System::Windows::Forms::Label^  labelY;
	public:
	private: System::Windows::Forms::Label^  labelX;
	private: System::Windows::Forms::TextBox^  textBoxX;

	private: System::Windows::Forms::Label^  labelB;
	private: System::Windows::Forms::Label^  labelG;
	private: System::Windows::Forms::Label^  labelR;
	public:

	public:
		Pic* pic = new Pic(0, 0, 0, 0, 0);
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	public:

		Bitmap^ startImage;

		void restoreBrigtnessSets();

		void restoreHueSets();

		void restoreSaturationSets();

		void restoreContrastSets();

		void restoreLightnessSets();

		void restorePicture();

		void assignBitmap();

		void changeBrightness(int propertyValue);

		float getHueFromRgb(Byte *pos);

		float getSaturationFromRgb(Byte *pos);

		float getLightnessFromRgb(Byte *pos);

		void changeHue(int propertyValue);

		void changeSaturation(int propertyValue);

		void changeContrast(int propertyValue);

		void changeLightness(int propertyValue);

		void createBlueAlphaMask(int treshold);

		void createGreenAlphaMask(int treshold);

		void enableMenu();

		void disableMenu();

		void changeChannels(int valueR, int valueG, int valueB);

		void changeRedChannel(int value, Bitmap^ currImage);

		void changeGreenChannel(int value, Bitmap^ currImage);

		void changeBlueChannel(int value, Bitmap^ currImage);
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::Windows::Forms::StatusStrip^  statusStrip;
protected:


	public:
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabelBounds;

	private: System::Windows::Forms::Label^  labelColor;
	public:

	private: System::Windows::Forms::TextBox^  textBoxY;
	public:

	private: System::Windows::Forms::TextBox^  textBoxB;



	private: System::Windows::Forms::TextBox^  textBoxG;

	private: System::Windows::Forms::TextBox^  textBoxR;
	private: System::Windows::Forms::MenuStrip^  menuStripMain;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colorToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  lightnessToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  hueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saturationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  shadesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  contrastToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  brightnessToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  filtersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blackAndWhiteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  negativeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pixelsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sepiaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  chromakeyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  greenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  authorToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBoxImage;

	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rotateOnLeftToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rotateOnRightToolStripMenuItem;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStripMain = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rotateOnLeftToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rotateOnRightToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lightnessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saturationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shadesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->brightnessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contrastToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filtersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blackAndWhiteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->negativeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pixelsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepiaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chromakeyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->blueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->greenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->authorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBoxImage = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->toolStripMain = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButtonOpen = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonSvae = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonClear = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonLeftRotate = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonghtRotate = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLightness = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonHue = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonSaturation = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonBrightness = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonContrast = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonBlackAndWhite = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonNegative = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonNightSeek = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonSepia = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonKeying = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonChannels = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonAuthor = (gcnew System::Windows::Forms::ToolStripButton());
			this->panelAdd = (gcnew System::Windows::Forms::Panel());
			this->groupBoxBackground = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSelect = (gcnew System::Windows::Forms::Button());
			this->pictureBoxBackImage = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxInfo = (gcnew System::Windows::Forms::GroupBox());
			this->labelColor = (gcnew System::Windows::Forms::Label());
			this->textBoxY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->textBoxG = (gcnew System::Windows::Forms::TextBox());
			this->textBoxR = (gcnew System::Windows::Forms::TextBox());
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->labelB = (gcnew System::Windows::Forms::Label());
			this->labelG = (gcnew System::Windows::Forms::Label());
			this->labelR = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pictureBoxBackground = (gcnew System::Windows::Forms::PictureBox());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabelBounds = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStripMain->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxImage))->BeginInit();
			this->toolStripMain->SuspendLayout();
			this->panelAdd->SuspendLayout();
			this->groupBoxBackground->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBackImage))->BeginInit();
			this->groupBoxInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBackground))->BeginInit();
			this->statusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStripMain
			// 
			resources->ApplyResources(this->menuStripMain, L"menuStripMain");
			this->menuStripMain->BackColor = System::Drawing::SystemColors::Window;
			this->menuStripMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->colorToolStripMenuItem, this->shadesToolStripMenuItem, this->filtersToolStripMenuItem, this->chromakeyToolStripMenuItem,
					this->aboutToolStripMenuItem
			});
			this->menuStripMain->Name = L"menuStripMain";
			// 
			// fileToolStripMenuItem
			// 
			resources->ApplyResources(this->fileToolStripMenuItem, L"fileToolStripMenuItem");
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			// 
			// openToolStripMenuItem
			// 
			resources->ApplyResources(this->openToolStripMenuItem, L"openToolStripMenuItem");
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			resources->ApplyResources(this->saveToolStripMenuItem, L"saveToolStripMenuItem");
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			resources->ApplyResources(this->editToolStripMenuItem, L"editToolStripMenuItem");
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->clearToolStripMenuItem,
					this->rotateOnLeftToolStripMenuItem, this->rotateOnRightToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			// 
			// clearToolStripMenuItem
			// 
			resources->ApplyResources(this->clearToolStripMenuItem, L"clearToolStripMenuItem");
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::clearToolStripMenuItem_Click);
			// 
			// rotateOnLeftToolStripMenuItem
			// 
			resources->ApplyResources(this->rotateOnLeftToolStripMenuItem, L"rotateOnLeftToolStripMenuItem");
			this->rotateOnLeftToolStripMenuItem->Name = L"rotateOnLeftToolStripMenuItem";
			this->rotateOnLeftToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::rotateOnLeftToolStripMenuItem_Click);
			// 
			// rotateOnRightToolStripMenuItem
			// 
			resources->ApplyResources(this->rotateOnRightToolStripMenuItem, L"rotateOnRightToolStripMenuItem");
			this->rotateOnRightToolStripMenuItem->Name = L"rotateOnRightToolStripMenuItem";
			this->rotateOnRightToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::rotateOnRightToolStripMenuItem_Click);
			// 
			// colorToolStripMenuItem
			// 
			resources->ApplyResources(this->colorToolStripMenuItem, L"colorToolStripMenuItem");
			this->colorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->lightnessToolStripMenuItem,
					this->hueToolStripMenuItem, this->saturationToolStripMenuItem
			});
			this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
			// 
			// lightnessToolStripMenuItem
			// 
			resources->ApplyResources(this->lightnessToolStripMenuItem, L"lightnessToolStripMenuItem");
			this->lightnessToolStripMenuItem->Name = L"lightnessToolStripMenuItem";
			this->lightnessToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::lightnessToolStripMenuItem_Click);
			// 
			// hueToolStripMenuItem
			// 
			resources->ApplyResources(this->hueToolStripMenuItem, L"hueToolStripMenuItem");
			this->hueToolStripMenuItem->Name = L"hueToolStripMenuItem";
			this->hueToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::hueToolStripMenuItem_Click);
			// 
			// saturationToolStripMenuItem
			// 
			resources->ApplyResources(this->saturationToolStripMenuItem, L"saturationToolStripMenuItem");
			this->saturationToolStripMenuItem->Name = L"saturationToolStripMenuItem";
			this->saturationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saturationToolStripMenuItem_Click);
			// 
			// shadesToolStripMenuItem
			// 
			resources->ApplyResources(this->shadesToolStripMenuItem, L"shadesToolStripMenuItem");
			this->shadesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->brightnessToolStripMenuItem,
					this->contrastToolStripMenuItem
			});
			this->shadesToolStripMenuItem->Name = L"shadesToolStripMenuItem";
			// 
			// brightnessToolStripMenuItem
			// 
			resources->ApplyResources(this->brightnessToolStripMenuItem, L"brightnessToolStripMenuItem");
			this->brightnessToolStripMenuItem->Name = L"brightnessToolStripMenuItem";
			this->brightnessToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::brightnessToolStripMenuItem_Click);
			// 
			// contrastToolStripMenuItem
			// 
			resources->ApplyResources(this->contrastToolStripMenuItem, L"contrastToolStripMenuItem");
			this->contrastToolStripMenuItem->Name = L"contrastToolStripMenuItem";
			this->contrastToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::contrastToolStripMenuItem_Click);
			// 
			// filtersToolStripMenuItem
			// 
			resources->ApplyResources(this->filtersToolStripMenuItem, L"filtersToolStripMenuItem");
			this->filtersToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->blackAndWhiteToolStripMenuItem,
					this->negativeToolStripMenuItem, this->pixelsToolStripMenuItem, this->sepiaToolStripMenuItem
			});
			this->filtersToolStripMenuItem->Name = L"filtersToolStripMenuItem";
			// 
			// blackAndWhiteToolStripMenuItem
			// 
			resources->ApplyResources(this->blackAndWhiteToolStripMenuItem, L"blackAndWhiteToolStripMenuItem");
			this->blackAndWhiteToolStripMenuItem->Name = L"blackAndWhiteToolStripMenuItem";
			this->blackAndWhiteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::blackAndWhiteToolStripMenuItem_Click);
			// 
			// negativeToolStripMenuItem
			// 
			resources->ApplyResources(this->negativeToolStripMenuItem, L"negativeToolStripMenuItem");
			this->negativeToolStripMenuItem->Name = L"negativeToolStripMenuItem";
			this->negativeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::negativeToolStripMenuItem_Click);
			// 
			// pixelsToolStripMenuItem
			// 
			resources->ApplyResources(this->pixelsToolStripMenuItem, L"pixelsToolStripMenuItem");
			this->pixelsToolStripMenuItem->Name = L"pixelsToolStripMenuItem";
			this->pixelsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::pixelsToolStripMenuItem_Click);
			// 
			// sepiaToolStripMenuItem
			// 
			resources->ApplyResources(this->sepiaToolStripMenuItem, L"sepiaToolStripMenuItem");
			this->sepiaToolStripMenuItem->Name = L"sepiaToolStripMenuItem";
			this->sepiaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::sepiaToolStripMenuItem_Click);
			// 
			// chromakeyToolStripMenuItem
			// 
			resources->ApplyResources(this->chromakeyToolStripMenuItem, L"chromakeyToolStripMenuItem");
			this->chromakeyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->blueToolStripMenuItem,
					this->greenToolStripMenuItem
			});
			this->chromakeyToolStripMenuItem->Name = L"chromakeyToolStripMenuItem";
			// 
			// blueToolStripMenuItem
			// 
			resources->ApplyResources(this->blueToolStripMenuItem, L"blueToolStripMenuItem");
			this->blueToolStripMenuItem->Name = L"blueToolStripMenuItem";
			this->blueToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::blueToolStripMenuItem_Click);
			// 
			// greenToolStripMenuItem
			// 
			resources->ApplyResources(this->greenToolStripMenuItem, L"greenToolStripMenuItem");
			this->greenToolStripMenuItem->Name = L"greenToolStripMenuItem";
			this->greenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::greenToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			resources->ApplyResources(this->aboutToolStripMenuItem, L"aboutToolStripMenuItem");
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->authorToolStripMenuItem });
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			// 
			// authorToolStripMenuItem
			// 
			resources->ApplyResources(this->authorToolStripMenuItem, L"authorToolStripMenuItem");
			this->authorToolStripMenuItem->Name = L"authorToolStripMenuItem";
			this->authorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::authorToolStripMenuItem_Click);
			// 
			// pictureBoxImage
			// 
			resources->ApplyResources(this->pictureBoxImage, L"pictureBoxImage");
			this->pictureBoxImage->BackColor = System::Drawing::Color::Silver;
			this->pictureBoxImage->Name = L"pictureBoxImage";
			this->pictureBoxImage->TabStop = false;
			this->pictureBoxImage->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pictureBoxImage_MouseMove);
			// 
			// openFileDialog
			// 
			resources->ApplyResources(this->openFileDialog, L"openFileDialog");
			// 
			// toolStripMain
			// 
			resources->ApplyResources(this->toolStripMain, L"toolStripMain");
			this->toolStripMain->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->toolStripMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(23) {
				this->toolStripButtonOpen,
					this->toolStripButtonSvae, this->toolStripSeparator3, this->toolStripButtonClear, this->toolStripButtonLeftRotate, this->toolStripButtonghtRotate,
					this->toolStripSeparator4, this->toolStripLightness, this->toolStripButtonHue, this->toolStripButtonSaturation, this->toolStripSeparator2,
					this->toolStripButtonBrightness, this->toolStripButtonContrast, this->toolStripSeparator1, this->toolStripButtonBlackAndWhite,
					this->toolStripButtonNegative, this->toolStripButtonNightSeek, this->toolStripButtonSepia, this->toolStripSeparator5, this->toolStripButtonKeying,
					this->toolStripButtonChannels, this->toolStripSeparator6, this->toolStripButtonAuthor
			});
			this->toolStripMain->Name = L"toolStripMain";
			// 
			// toolStripButtonOpen
			// 
			resources->ApplyResources(this->toolStripButtonOpen, L"toolStripButtonOpen");
			this->toolStripButtonOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonOpen->Name = L"toolStripButtonOpen";
			this->toolStripButtonOpen->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonOpen_Click);
			// 
			// toolStripButtonSvae
			// 
			resources->ApplyResources(this->toolStripButtonSvae, L"toolStripButtonSvae");
			this->toolStripButtonSvae->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonSvae->Name = L"toolStripButtonSvae";
			this->toolStripButtonSvae->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonSvae_Click);
			// 
			// toolStripSeparator3
			// 
			resources->ApplyResources(this->toolStripSeparator3, L"toolStripSeparator3");
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			// 
			// toolStripButtonClear
			// 
			resources->ApplyResources(this->toolStripButtonClear, L"toolStripButtonClear");
			this->toolStripButtonClear->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonClear->Name = L"toolStripButtonClear";
			this->toolStripButtonClear->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonClear_Click);
			// 
			// toolStripButtonLeftRotate
			// 
			resources->ApplyResources(this->toolStripButtonLeftRotate, L"toolStripButtonLeftRotate");
			this->toolStripButtonLeftRotate->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonLeftRotate->Name = L"toolStripButtonLeftRotate";
			this->toolStripButtonLeftRotate->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonLeftRotate_Click);
			// 
			// toolStripButtonghtRotate
			// 
			resources->ApplyResources(this->toolStripButtonghtRotate, L"toolStripButtonghtRotate");
			this->toolStripButtonghtRotate->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonghtRotate->Name = L"toolStripButtonghtRotate";
			this->toolStripButtonghtRotate->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonghtRotate_Click);
			// 
			// toolStripSeparator4
			// 
			resources->ApplyResources(this->toolStripSeparator4, L"toolStripSeparator4");
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			// 
			// toolStripLightness
			// 
			resources->ApplyResources(this->toolStripLightness, L"toolStripLightness");
			this->toolStripLightness->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripLightness->Name = L"toolStripLightness";
			this->toolStripLightness->Click += gcnew System::EventHandler(this, &MainForm::toolStripLightness_Click);
			// 
			// toolStripButtonHue
			// 
			resources->ApplyResources(this->toolStripButtonHue, L"toolStripButtonHue");
			this->toolStripButtonHue->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonHue->Name = L"toolStripButtonHue";
			this->toolStripButtonHue->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonHue_Click);
			// 
			// toolStripButtonSaturation
			// 
			resources->ApplyResources(this->toolStripButtonSaturation, L"toolStripButtonSaturation");
			this->toolStripButtonSaturation->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonSaturation->Name = L"toolStripButtonSaturation";
			this->toolStripButtonSaturation->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonSaturation_Click);
			// 
			// toolStripSeparator2
			// 
			resources->ApplyResources(this->toolStripSeparator2, L"toolStripSeparator2");
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			// 
			// toolStripButtonBrightness
			// 
			resources->ApplyResources(this->toolStripButtonBrightness, L"toolStripButtonBrightness");
			this->toolStripButtonBrightness->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonBrightness->Name = L"toolStripButtonBrightness";
			this->toolStripButtonBrightness->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonBrightness_Click);
			// 
			// toolStripButtonContrast
			// 
			resources->ApplyResources(this->toolStripButtonContrast, L"toolStripButtonContrast");
			this->toolStripButtonContrast->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonContrast->Name = L"toolStripButtonContrast";
			this->toolStripButtonContrast->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonContrast_Click);
			// 
			// toolStripSeparator1
			// 
			resources->ApplyResources(this->toolStripSeparator1, L"toolStripSeparator1");
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			// 
			// toolStripButtonBlackAndWhite
			// 
			resources->ApplyResources(this->toolStripButtonBlackAndWhite, L"toolStripButtonBlackAndWhite");
			this->toolStripButtonBlackAndWhite->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonBlackAndWhite->Name = L"toolStripButtonBlackAndWhite";
			this->toolStripButtonBlackAndWhite->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonBlackAndWhite_Click);
			// 
			// toolStripButtonNegative
			// 
			resources->ApplyResources(this->toolStripButtonNegative, L"toolStripButtonNegative");
			this->toolStripButtonNegative->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonNegative->Name = L"toolStripButtonNegative";
			this->toolStripButtonNegative->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonNegative_Click);
			// 
			// toolStripButtonNightSeek
			// 
			resources->ApplyResources(this->toolStripButtonNightSeek, L"toolStripButtonNightSeek");
			this->toolStripButtonNightSeek->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonNightSeek->Name = L"toolStripButtonNightSeek";
			this->toolStripButtonNightSeek->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonNightSeek_Click);
			// 
			// toolStripButtonSepia
			// 
			resources->ApplyResources(this->toolStripButtonSepia, L"toolStripButtonSepia");
			this->toolStripButtonSepia->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonSepia->Name = L"toolStripButtonSepia";
			this->toolStripButtonSepia->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonSepia_Click);
			// 
			// toolStripSeparator5
			// 
			resources->ApplyResources(this->toolStripSeparator5, L"toolStripSeparator5");
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			// 
			// toolStripButtonKeying
			// 
			resources->ApplyResources(this->toolStripButtonKeying, L"toolStripButtonKeying");
			this->toolStripButtonKeying->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonKeying->Name = L"toolStripButtonKeying";
			this->toolStripButtonKeying->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonKeying_Click);
			// 
			// toolStripButtonChannels
			// 
			resources->ApplyResources(this->toolStripButtonChannels, L"toolStripButtonChannels");
			this->toolStripButtonChannels->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonChannels->Name = L"toolStripButtonChannels";
			this->toolStripButtonChannels->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonChannels_Click);
			// 
			// toolStripSeparator6
			// 
			resources->ApplyResources(this->toolStripSeparator6, L"toolStripSeparator6");
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			// 
			// toolStripButtonAuthor
			// 
			resources->ApplyResources(this->toolStripButtonAuthor, L"toolStripButtonAuthor");
			this->toolStripButtonAuthor->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonAuthor->Name = L"toolStripButtonAuthor";
			this->toolStripButtonAuthor->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtonAuthor_Click);
			// 
			// panelAdd
			// 
			resources->ApplyResources(this->panelAdd, L"panelAdd");
			this->panelAdd->BackColor = System::Drawing::SystemColors::Control;
			this->panelAdd->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelAdd->Controls->Add(this->groupBoxBackground);
			this->panelAdd->Controls->Add(this->groupBoxInfo);
			this->panelAdd->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panelAdd->Name = L"panelAdd";
			// 
			// groupBoxBackground
			// 
			resources->ApplyResources(this->groupBoxBackground, L"groupBoxBackground");
			this->groupBoxBackground->Controls->Add(this->buttonSelect);
			this->groupBoxBackground->Controls->Add(this->pictureBoxBackImage);
			this->groupBoxBackground->Name = L"groupBoxBackground";
			this->groupBoxBackground->TabStop = false;
			// 
			// buttonSelect
			// 
			resources->ApplyResources(this->buttonSelect, L"buttonSelect");
			this->buttonSelect->Name = L"buttonSelect";
			this->buttonSelect->UseVisualStyleBackColor = true;
			this->buttonSelect->Click += gcnew System::EventHandler(this, &MainForm::buttonSelect_Click);
			// 
			// pictureBoxBackImage
			// 
			resources->ApplyResources(this->pictureBoxBackImage, L"pictureBoxBackImage");
			this->pictureBoxBackImage->Name = L"pictureBoxBackImage";
			this->pictureBoxBackImage->TabStop = false;
			// 
			// groupBoxInfo
			// 
			resources->ApplyResources(this->groupBoxInfo, L"groupBoxInfo");
			this->groupBoxInfo->Controls->Add(this->labelColor);
			this->groupBoxInfo->Controls->Add(this->textBoxY);
			this->groupBoxInfo->Controls->Add(this->textBoxB);
			this->groupBoxInfo->Controls->Add(this->textBoxG);
			this->groupBoxInfo->Controls->Add(this->textBoxR);
			this->groupBoxInfo->Controls->Add(this->labelY);
			this->groupBoxInfo->Controls->Add(this->labelX);
			this->groupBoxInfo->Controls->Add(this->textBoxX);
			this->groupBoxInfo->Controls->Add(this->labelB);
			this->groupBoxInfo->Controls->Add(this->labelG);
			this->groupBoxInfo->Controls->Add(this->labelR);
			this->groupBoxInfo->Name = L"groupBoxInfo";
			this->groupBoxInfo->TabStop = false;
			// 
			// labelColor
			// 
			resources->ApplyResources(this->labelColor, L"labelColor");
			this->labelColor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelColor->Name = L"labelColor";
			// 
			// textBoxY
			// 
			resources->ApplyResources(this->textBoxY, L"textBoxY");
			this->textBoxY->Name = L"textBoxY";
			this->textBoxY->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxY_TextChanged);
			this->textBoxY->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBoxY_KeyPress);
			this->textBoxY->Leave += gcnew System::EventHandler(this, &MainForm::textBoxY_Leave);
			// 
			// textBoxB
			// 
			resources->ApplyResources(this->textBoxB, L"textBoxB");
			this->textBoxB->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->ReadOnly = true;
			// 
			// textBoxG
			// 
			resources->ApplyResources(this->textBoxG, L"textBoxG");
			this->textBoxG->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxG->Name = L"textBoxG";
			this->textBoxG->ReadOnly = true;
			// 
			// textBoxR
			// 
			resources->ApplyResources(this->textBoxR, L"textBoxR");
			this->textBoxR->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxR->Name = L"textBoxR";
			this->textBoxR->ReadOnly = true;
			// 
			// labelY
			// 
			resources->ApplyResources(this->labelY, L"labelY");
			this->labelY->Name = L"labelY";
			// 
			// labelX
			// 
			resources->ApplyResources(this->labelX, L"labelX");
			this->labelX->Name = L"labelX";
			// 
			// textBoxX
			// 
			resources->ApplyResources(this->textBoxX, L"textBoxX");
			this->textBoxX->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxX->Name = L"textBoxX";
			this->textBoxX->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxX_TextChanged);
			this->textBoxX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBoxX_KeyPress);
			this->textBoxX->Leave += gcnew System::EventHandler(this, &MainForm::textBoxX_Leave);
			// 
			// labelB
			// 
			resources->ApplyResources(this->labelB, L"labelB");
			this->labelB->Name = L"labelB";
			// 
			// labelG
			// 
			resources->ApplyResources(this->labelG, L"labelG");
			this->labelG->Name = L"labelG";
			// 
			// labelR
			// 
			resources->ApplyResources(this->labelR, L"labelR");
			this->labelR->Name = L"labelR";
			// 
			// saveFileDialog
			// 
			resources->ApplyResources(this->saveFileDialog, L"saveFileDialog");
			// 
			// pictureBoxBackground
			// 
			resources->ApplyResources(this->pictureBoxBackground, L"pictureBoxBackground");
			this->pictureBoxBackground->Name = L"pictureBoxBackground";
			this->pictureBoxBackground->TabStop = false;
			// 
			// statusStrip
			// 
			resources->ApplyResources(this->statusStrip, L"statusStrip");
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabelBounds });
			this->statusStrip->Name = L"statusStrip";
			// 
			// toolStripStatusLabelBounds
			// 
			resources->ApplyResources(this->toolStripStatusLabelBounds, L"toolStripStatusLabelBounds");
			this->toolStripStatusLabelBounds->Name = L"toolStripStatusLabelBounds";
			// 
			// MainForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->panelAdd);
			this->Controls->Add(this->toolStripMain);
			this->Controls->Add(this->pictureBoxImage);
			this->Controls->Add(this->menuStripMain);
			this->Controls->Add(this->pictureBoxBackground);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStripMain;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStripMain->ResumeLayout(false);
			this->menuStripMain->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxImage))->EndInit();
			this->toolStripMain->ResumeLayout(false);
			this->toolStripMain->PerformLayout();
			this->panelAdd->ResumeLayout(false);
			this->groupBoxBackground->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBackImage))->EndInit();
			this->groupBoxInfo->ResumeLayout(false);
			this->groupBoxInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBackground))->EndInit();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	void alignImage();

	void setDefaultImageBounds();

	void setDefaultPanelBounds();

	void getInfo(int x, int y);

	void setInfo();

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e);

	void enableActions();

	void disableActions();

	void openImage();

	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void clearToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	int getMaxRgbValue(Byte *pos);

	int getMinRgbValue(Byte *pos);

	private: System::Void blackAndWhiteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void negativeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void sepiaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void rotateOnLeftToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void rotateOnRightToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void pixelsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void authorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	void setHue();

	private: System::Void hueToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	
	void setSaturation();

	private: System::Void saturationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	void setLightness();

	private: System::Void lightnessToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	
	void setBrightness();

	private: System::Void brightnessToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	
	void setContrast();

	private: System::Void contrastToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void blueToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void greenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	void saveImage();

	private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonOpen_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonSvae_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripLightness_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonHue_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonSaturation_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonBrightness_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonContrast_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void MainForm::buttonSelect_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void pictureBoxImage_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

	private: System::Void textBoxX_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	private: System::Void textBoxY_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	private: System::Void textBoxX_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxX_Leave(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxY_TextChanged(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void textBoxY_Leave(System::Object^  sender, System::EventArgs^  e);

	bool checkNumber(String^ number);

	void applyBlackAndWhiteFilter();

	void applyNegativeFilter();

	void applyNightSeekFilter();

	void applySepiaFilter();

	void clearPicture();

	void setKeying();

	void setChannels();

	void showInfo();

	void rotateImage(int direction);

	private: System::Void toolStripButtonBlackAndWhite_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonNegative_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonNightSeek_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void toolStripButtonSepia_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonClear_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void toolStripButtonLeftRotate_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonghtRotate_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void toolStripButtonKeying_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonChannels_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void toolStripButtonAuthor_Click(System::Object^  sender, System::EventArgs^  e);
};
}
