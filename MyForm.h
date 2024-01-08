#pragma once

#include "genetic.h"

namespace imagesComparer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addFirstToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addSecondToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearFirstToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearSecondToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ calculateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addFirstToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addSecondToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearFirstToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearSecondToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->calculateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(900, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->addFirstToolStripMenuItem,
					this->addSecondToolStripMenuItem, this->clearFirstToolStripMenuItem, this->clearSecondToolStripMenuItem, this->calculateToolStripMenuItem,
					this->exitToolStripMenuItem, this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// addFirstToolStripMenuItem
			// 
			this->addFirstToolStripMenuItem->Name = L"addFirstToolStripMenuItem";
			this->addFirstToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->addFirstToolStripMenuItem->Text = L"Add first";
			this->addFirstToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addFirstToolStripMenuItem_Click);
			// 
			// addSecondToolStripMenuItem
			// 
			this->addSecondToolStripMenuItem->Name = L"addSecondToolStripMenuItem";
			this->addSecondToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->addSecondToolStripMenuItem->Text = L"Add second";
			this->addSecondToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addSecondToolStripMenuItem_Click);
			// 
			// clearFirstToolStripMenuItem
			// 
			this->clearFirstToolStripMenuItem->Name = L"clearFirstToolStripMenuItem";
			this->clearFirstToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->clearFirstToolStripMenuItem->Text = L"Clear first";
			this->clearFirstToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearFirstToolStripMenuItem_Click);
			// 
			// clearSecondToolStripMenuItem
			// 
			this->clearSecondToolStripMenuItem->Name = L"clearSecondToolStripMenuItem";
			this->clearSecondToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->clearSecondToolStripMenuItem->Text = L"Clear second";
			this->clearSecondToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearSecondToolStripMenuItem_Click);
			// 
			// calculateToolStripMenuItem
			// 
			this->calculateToolStripMenuItem->Name = L"calculateToolStripMenuItem";
			this->calculateToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->calculateToolStripMenuItem->Text = L"Calculate";
			this->calculateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::calculateToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(36, 47);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(239, 299);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(310, 47);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(240, 299);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(587, 47);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(239, 299);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(36, 370);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(156, 20);
			this->textBox1->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(900, 518);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addFirstToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->Filter = "Images (bmp, jpg, jpeg) | *.jpg;*.bmp;*.jpeg";
		openFileDialog1->Title = "Select image file";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox1->Image = Bitmap::FromFile(openFileDialog1 -> FileName);
		}
	}
	private: System::Void addSecondToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog2->Filter = "Images (bmp, jpg, jpeg) | *.jpg;*.bmp;*.jpeg";
		openFileDialog2->Title = "Select image file";
		if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox2->Image = Bitmap::FromFile(openFileDialog2->FileName);
		}
	}
	private: System::Void clearFirstToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Image = nullptr;
	}
	private: System::Void clearSecondToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox2->Image = nullptr;
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void calculateToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		calculate();
	}
	void calculate() {
		// Получение матриц исходных изображений
		img* image1 = new img(); // ТИ
		image1->width = pictureBox1->Image->Width;
		image1->height = pictureBox1->Image->Height;
		image1->image = new unsigned int [image1->width * image1->height];

		img* image2 = new img(); // ЭИ
		image2->width = pictureBox2->Image->Width;
		image2->height = pictureBox2->Image->Height;
		image2->image = new unsigned int[image2->width * image2->height];

		Bitmap^ bitmap1 = gcnew Bitmap(pictureBox1->Image);
		for (int i = 0; i < image1->height; i++)
			for (int j = 0; j < image1->width; j++)
				image1->image[j + i * image1->width] = bitmap1->GetPixel(j, i).ToArgb();

		Bitmap^ bitmap2 = gcnew Bitmap(pictureBox2->Image);
		for (int i = 0; i < image2->height; i++)
			for (int j = 0; j < image2->width; j++)
				image2->image[j + i * image2->width] = bitmap2->GetPixel(j, i).ToArgb();

		size_t imageWidth1 = image1->width;
		size_t imageHeight1 = image1->height;

		size_t imageWidth2 = image2->width;
		size_t imageHeight2 = image2->height;

		// Получение матрицы цветного ТИ
		Bitmap^ bmpInputColorfullImage1 = gcnew Bitmap(pictureBox1->Image);
		// Получение матриц изображений
		Bitmap^ bmpInputImage1 = gcnew Bitmap(pictureBox1->Image);
		Bitmap^ bmpInputImage2 = gcnew Bitmap(pictureBox2->Image);

		uint8** matrImage1 = new uint8* [imageHeight1];
		for (int i = 0; i < imageHeight1; i++)
			matrImage1[i] = new uint8[imageWidth1];

		uint8** matrImage2 = new uint8 * [imageHeight2];
		for (int i = 0; i < imageHeight2; i++)
			matrImage2[i] = new uint8[imageWidth2];


		int pix1 = 0, pix2 = 0;
		double sum1 = 0.0, sum2 = 0.0;



		for (int i = 0; i < imageHeight1; i++) {
			for (int j = 0; j < imageWidth1; j++) { 
				// Получение цвета пикселя
				Color rgb = bmpInputImage1->GetPixel(j, i);
				// заполнение матрицы цветного формата
				bmpInputColorfullImage1->SetPixel(j, i, rgb);
				// вычисление среднего - серого
				float medSum = (rgb.R + rgb.G + rgb.B) / 3; 
				Color newColor = Color::FromArgb(medSum, medSum, medSum);
				bmpInputImage1->SetPixel(j, i, newColor);
				matrImage1[i][j] = newColor.R;
			} 
		}  
		pictureBox1->Image = bmpInputImage1;
		// для 2-й матрицы
		for (int i = 0; i < imageHeight2; i++)  {
			for (int j = 0; j < imageWidth2; j++)   {
				// Получение цвета пикселя    
				Color rgb = bmpInputImage2->GetPixel(j, i);
				// вычисление среднего - серого
				float medSum = (rgb.R + rgb.G + rgb.B) / 3; 
				Color newColor = Color::FromArgb(medSum, medSum, medSum);
				bmpInputImage2->SetPixel(j, i, newColor);
				matrImage2[i][j] = newColor.R;
			}
		}  
		pictureBox2->Image = bmpInputImage2;

		// Вычисления

		// Вычисление максимальных точек для проверки по x и по y
		int dx = imageWidth2;
		int dy = imageHeight2;
		int xMax = imageWidth1 - dx;
		int yMax = imageHeight1 - dy;


		Model population[POPULATION_SIZE];
		// Первая популяция формируется случайным образом
		for (int i = 0; i < POPULATION_SIZE; i++) {
			Model model = population[i];
			model.x = randomize(0,xMax);
			model.y = randomize(0,yMax);
			model.relevantForCrossOver = false;
		}
		// Начало эволюции
		for (int i = 0; i < NUMBER_OF_POPULATIONS; i++) {
			// оценивание особей по значенинию функции корреляции
			fitting(population,image1,image2);
			// сортировка популяции по убыванию значения функции корреляции
			merge_sort(population,POPULATION_SIZE);
			// отбор
			selection(population);
			cross_over(population);
			mutation(population);
		}
		fitting(population, image1, image2);
		merge_sort(population, POPULATION_SIZE);
		
		int xBest = population[0].x , yBest = population[0].y;
		double sum = population[0].fxy;


		// Вывод значения максимальной корреляции


//		textBox1->Text = roundNumber(sum, 5).c_str();
		textBox1->Text = sum.ToString();
		
		// Формирование итогового изображения из ТИ на основе максимальной корреляции
		Bitmap^ bitmap3 = gcnew Bitmap(imageWidth2, imageHeight2);
		for (int i = 0; i < imageHeight2; i++)
			for (int j = 0; j < imageWidth2; j++)
				bitmap3->SetPixel(j, i, Color::FromArgb(image1->image[(i+yBest)*imageWidth1+(j+xBest)]));

		pictureBox3->Image = bitmap3;
	}

private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->Title = "Save image";
	saveFileDialog1->Filter = "Images (*.bmp, *.jpg, *.jpeg) | *.jpg;*.bmp;*.jpeg";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		Bitmap^ bitmap = gcnew Bitmap(pictureBox3->Image);
		bitmap->Save(saveFileDialog1->FileName);
	}
}
};
}
