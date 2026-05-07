#pragma once
#pragma execution_character_set("utf-8")

#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace BiznesTrip {

    public ref class NewRequestForm : public Form
    {
    private:
        String^ uiFont;

    public:
        NewRequestForm()
        {
            uiFont = L"Numans";
            InitializeComponent();
        }

    private:
        Label^ MakeLabel(String^ text, int x, int y, int w, float size, FontStyle st)
        {
            Label^ l = gcnew Label();
            l->Text = text;
            l->Font = gcnew Drawing::Font(uiFont, size, st);
            l->Location = Drawing::Point(x, y);
            l->Size = Drawing::Size(w, 30);
            return l;
        }

        TextBox^ MakeTextBox(int x, int y, int w, String^ value)
        {
            TextBox^ t = gcnew TextBox();
            t->Font = gcnew Drawing::Font(uiFont, 14);
            t->Location = Drawing::Point(x, y);
            t->Size = Drawing::Size(w, 40);
            t->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            t->Text = value;
            return t;
        }

        void InitializeComponent()
        {
            this->Text = L"BизнесТрип – Новая заявка";
            this->ClientSize = Drawing::Size(1100, 903);
            this->BackColor = Color::White;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;

            Label^ title = gcnew Label();
            title->Text = L"Новая заявка на командировку";
            title->Font = gcnew Drawing::Font(uiFont, 22, FontStyle::Regular);
            title->TextAlign = ContentAlignment::MiddleCenter;
            title->Location = Drawing::Point(220, 30);
            title->Size = Drawing::Size(660, 50);
            this->Controls->Add(title);

            this->Controls->Add(MakeLabel(L"Цель поездки", 80, 130, 200, 14, FontStyle::Regular));
            this->Controls->Add(MakeTextBox(80, 165, 400, L"Участие в конференции"));

            this->Controls->Add(MakeLabel(L"Город", 80, 230, 200, 14, FontStyle::Regular));
            this->Controls->Add(MakeTextBox(80, 265, 400, L"Санкт-Петербург"));

            this->Controls->Add(MakeLabel(L"Дата начала", 80, 330, 200, 14, FontStyle::Regular));
            DateTimePicker^ dtStart = gcnew DateTimePicker();
            dtStart->Font = gcnew Drawing::Font(uiFont, 14);
            dtStart->Location = Drawing::Point(80, 365);
            dtStart->Size = Drawing::Size(180, 40);
            dtStart->Format = DateTimePickerFormat::Custom;
            dtStart->CustomFormat = L"dd.MM.yyyy";
            dtStart->Value = DateTime(2025, 5, 15);
            this->Controls->Add(dtStart);

            this->Controls->Add(MakeLabel(L"Дата окончания", 480, 330, 200, 14, FontStyle::Regular));
            DateTimePicker^ dtEnd = gcnew DateTimePicker();
            dtEnd->Font = gcnew Drawing::Font(uiFont, 14);
            dtEnd->Location = Drawing::Point(480, 365);
            dtEnd->Size = Drawing::Size(180, 40);
            dtEnd->Format = DateTimePickerFormat::Custom;
            dtEnd->CustomFormat = L"dd.MM.yyyy";
            dtEnd->Value = DateTime(2025, 5, 18);
            this->Controls->Add(dtEnd);

            Label^ exp = gcnew Label();
            exp->Text = L"Планируемые расходы";
            exp->Font = gcnew Drawing::Font(uiFont, 14, FontStyle::Bold);
            exp->Location = Drawing::Point(80, 430);
            exp->Size = Drawing::Size(280, 30);
            this->Controls->Add(exp);

            this->Controls->Add(MakeLabel(L"Проезд",     80, 470, 150, 14, FontStyle::Regular));
            this->Controls->Add(MakeTextBox(80, 505, 200, L"8000"));

            this->Controls->Add(MakeLabel(L"Проживание", 320, 470, 200, 14, FontStyle::Regular));
            this->Controls->Add(MakeTextBox(320, 505, 200, L"12000"));

            this->Controls->Add(MakeLabel(L"Суточные",   560, 470, 200, 14, FontStyle::Regular));
            this->Controls->Add(MakeTextBox(560, 505, 200, L"3600"));

            Label^ total = gcnew Label();
            total->Text = L"Итого: 23 600 ₽";
            total->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Bold);
            total->Location = Drawing::Point(80, 580);
            total->Size = Drawing::Size(400, 30);
            this->Controls->Add(total);

            Button^ btnSave = gcnew Button();
            btnSave->Text = L"Сохранить";
            btnSave->Font = gcnew Drawing::Font(uiFont, 14, FontStyle::Regular);
            btnSave->BackColor = Color::FromArgb(224, 148, 61);
            btnSave->ForeColor = Color::White;
            btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnSave->FlatAppearance->BorderSize = 0;
            btnSave->Location = Drawing::Point(80, 700);
            btnSave->Size = Drawing::Size(206, 70);
            btnSave->Cursor = Cursors::Hand;
            btnSave->Click += gcnew EventHandler(this, &NewRequestForm::btnSave_Click);
            this->Controls->Add(btnSave);

            Button^ btnSend = gcnew Button();
            btnSend->Text = L"Отправить на согласование";
            btnSend->Font = gcnew Drawing::Font(uiFont, 14, FontStyle::Regular);
            btnSend->BackColor = Color::FromArgb(133, 218, 159);
            btnSend->ForeColor = Color::Black;
            btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnSend->FlatAppearance->BorderSize = 0;
            btnSend->Location = Drawing::Point(420, 700);
            btnSend->Size = Drawing::Size(414, 70);
            btnSend->Cursor = Cursors::Hand;
            btnSend->Click += gcnew EventHandler(this, &NewRequestForm::btnSend_Click);
            this->Controls->Add(btnSend);
        }

        void btnSave_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show(L"Заявка сохранена как черновик.",
                L"BизнесТрип", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void btnSend_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show(L"Заявка отправлена на согласование руководителю.",
                L"BизнесТрип", MessageBoxButtons::OK, MessageBoxIcon::Information);
            this->Close();
        }
    };
}
