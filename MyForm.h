#pragma once

#include <vector>
#include <cmath>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <sstream>
#include <stdexcept>
using namespace std;

// Додаємо код функцій із файлів   
#include "Function.h"
#include "SimilarSlogans.h"

// Тіло програми
namespace Kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ radioButton1;
	protected:
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RadioButton^ radioButton3;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(596, 12);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(153, 29);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Калькулятор";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(596, 56);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(138, 29);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Порівняння";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(17, 47);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(552, 38);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(171, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Введіть приклад:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(596, 154);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(138, 55);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Обчислити";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(596, 226);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(138, 55);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Стерти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Відповідь:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(122, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 25);
			this->label3->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(73, 105);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(496, 38);
			this->textBox2->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(11, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(57, 32);
			this->label4->TabIndex = 9;
			this->label4->Text = L"X =";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(11, 108);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 32);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Y =";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton3->Location = System::Drawing::Point(596, 103);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(161, 29);
			this->radioButton3->TabIndex = 11;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Подібні члени";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(777, 314);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Name = L"MyForm";
			this->Text = L"Курсова робота (Сургай Р. КИУКИу-21-1)";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton1->Checked) {
			textBox1->Location = Point(13, 38);
			textBox1->Size = System::Drawing::Size(415, 38);
			textBox2->Visible = false;
			textBox2->Clear();
			textBox1->Clear();
			label4->Visible = false;
			label5->Visible = false;
			label2->Location = Point(9, 80);
			label3->Location = Point(97, 80);
			label3->Text = "";
		}
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton2->Checked) {
			label4->Visible = true;
			label5->Visible = true;
			textBox2->Visible = true;
			textBox1->Location = Point(55, 38);
			textBox1->Size = System::Drawing::Size(373, 38);
			label2->Location = Point(9, 150);
			label3->Location = Point(97, 150);
			label3->Text = "";
		}
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton3->Checked) {
			textBox1->Location = Point(13, 38);
			textBox1->Size = System::Drawing::Size(415, 38);
			textBox2->Visible = false;
			textBox2->Clear();
			textBox1->Clear();
			label3->Text = "";
			label4->Visible = false;
			label5->Visible = false;
			label2->Location = Point(9, 80);
			label3->Location = Point(97, 80);

		}
	}
	// Один клік на кнопку "Розрахунок"
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Якщо флаг стоїть на "Калькулятор"...
		if (radioButton1->Checked) {
			// Якщо немає виразу, виводимо іконку про помилку
			if (textBox1->Text == "") {
				MessageBox::Show("Будь ласка, заповніть поле!",
					"Помилка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
			else {
				string formula;
				ostringstream result;
				msclr::interop::marshal_context context;
				formula = context.marshal_as<string>(textBox1->Text);
				formula = deleteSpace(formula);
				
				// Якщо маємо помилку введення, виводимо відповідне повідомленя
				if (inputError(formula)) {
					label3->Text = "INPUT ERROR";
				}
				else {
					result << calculus(formula);
					// Преобразование double в std::string. Преобразование std::string в System::String
					label3->Text = gcnew String(result.str().c_str());
				}
			}
		}

		// Якщо флаг стоїть на "Порівняння"
		if (radioButton2->Checked) {
			if (textBox1->Text == "" || textBox2->Text == "") {
				MessageBox::Show("Будь ласка, заповніть усі поля!",
					"Помилка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
			else {
				string x, y;
				msclr::interop::marshal_context context;
				x = context.marshal_as<string>(textBox1->Text);
				y = context.marshal_as<string>(textBox2->Text);
				x = deleteSpace(x);
				y = deleteSpace(y);

				if (inputError(x) || inputError(y)) {
					label3->Text = "INPUT ERROR";
				}
				else {
					if (compare(x, y) == 0) label3->Text = "X = Y";
					if (compare(x, y) == 1) label3->Text = "X > Y";
					if (compare(x, y) == 2) label3->Text = "X < Y";
				}
			}
		}

		// Якщо флаг стоїть на "Подібні члени"
		if (radioButton3->Checked) {
			if (textBox1->Text == "") {
				MessageBox::Show("Будь ласка, заповніть поле!",
					"Помилка",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
			else {
				string formula;
				msclr::interop::marshal_context context;
				formula = context.marshal_as<string>(textBox1->Text);
				formula = deleteSpace(formula);

				if (inputErrorSS(formula)) {
					label3->Text = "INPUT ERROR";
				}
				else {
					formula = similarSlogans(formula);
					label3->Text = gcnew String(formula.c_str());
				}
			}
		}
	}
	// Один клік на кнопку "Стерти"
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Clear();
		textBox2->Clear();
		label3->Text = "";
	}
};
}
