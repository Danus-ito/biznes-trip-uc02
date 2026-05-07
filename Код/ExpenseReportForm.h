#pragma once
#pragma execution_character_set("utf-8")

#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace BiznesTrip {

    public ref class ExpenseReportForm : public Form
    {
    private:
        String^ uiFont;

    public:
        ExpenseReportForm()
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
            this->Text = L"BизнесТрип – Авансовый отчёт";
            this->ClientSize = Drawing::Size(1100, 800);
            this->BackColor = Color::White;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;

            Label^ title = gcnew Label();
            title->Text = L"Авансовый отчёт";
            title->Font = gcnew Drawing::Font(uiFont, 22, FontStyle::Regular);
            title->TextAlign = ContentAlignment::MiddleCenter;
            title->Location = Drawing::Point(360, 20);
            title->Size = Drawing::Size(380, 50);
            title->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->Controls->Add(title);

            this->Controls->Add(MakeLabel(L"Командировка", 80, 90, 200, 14, FontStyle::Bold));
            Panel^ pTrip = gcnew Panel();
            pTrip->Location = Drawing::Point(80, 125);
            pTrip->Size = Drawing::Size(940, 50);
            pTrip->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            pTrip->Controls->Add(MakeLabel(L"   № 123 от 15.05.2025 – 18.05  (Санкт-Петербург)",
                0, 10, 940, 14, FontStyle::Regular));
            this->Controls->Add(pTrip);

            this->Controls->Add(MakeLabel(L"Фактические расходы", 80, 200, 350, 14, FontStyle::Bold));

            int rowY = 245;
            this->Controls->Add(MakeLabel(L"Проезд",                       80, rowY,     200, 14, FontStyle::Regular));
            this->Controls->Add(MakeTextBox(420, rowY-5, 220, L"9 100"));
            this->Controls->Add(MakeLabel(L"Проживание",                   80, rowY+50,  200, 14, FontStyle::Regular));
            this->Controls->Add(MakeTextBox(420, rowY+45, 220, L"11 500"));
            this->Controls->Add(MakeLabel(L"Суточные (3 дн. × 1 200 ₽)",   80, rowY+100, 300, 14, FontStyle::Regular));
            this->Controls->Add(MakeLabel(L"3 600 ₽",                      420, rowY+100, 220, 14, FontStyle::Regular));
            this->Controls->Add(MakeLabel(L"Прочие расходы",                80, rowY+150, 250, 14, FontStyle::Regular));
            this->Controls->Add(MakeTextBox(420, rowY+145, 220, L"1 200"));

            Label^ total = gcnew Label();
            total->Text = L"Итого:                        25 400 ₽";
            total->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Bold);
            total->Location = Drawing::Point(80, rowY+205);
            total->Size = Drawing::Size(700, 35);
            this->Controls->Add(total);

            this->Controls->Add(MakeLabel(L"Подтверждающие документы", 80, 540, 350, 14, FontStyle::Bold));
            Button^ btnFile = gcnew Button();
            btnFile->Text = L"+ Добавить файл";
            btnFile->Font = gcnew Drawing::Font(uiFont, 14);
            btnFile->ForeColor = Color::FromArgb(39, 100, 255);
            btnFile->BackColor = Color::White;
            btnFile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnFile->FlatAppearance->BorderColor = Color::FromArgb(132, 132, 132);
            btnFile->FlatAppearance->BorderSize = 1;
            btnFile->Location = Drawing::Point(80, 580);
            btnFile->Size = Drawing::Size(280, 45);
            btnFile->Cursor = Cursors::Hand;
            btnFile->Click += gcnew EventHandler(this, &ExpenseReportForm::btnFile_Click);
            this->Controls->Add(btnFile);

            this->Controls->Add(MakeLabel(L"Комментарий", 480, 540, 200, 14, FontStyle::Bold));
            TextBox^ tbComment = gcnew TextBox();
            tbComment->Font = gcnew Drawing::Font(uiFont, 14);
            tbComment->Location = Drawing::Point(480, 580);
            tbComment->Size = Drawing::Size(540, 45);
            tbComment->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            tbComment->Text = L"Все расходы подтверждены документами";
            this->Controls->Add(tbComment);

            Button^ btnSend = gcnew Button();
            btnSend->Text = L"Отправить на проверку";
            btnSend->Font = gcnew Drawing::Font(uiFont, 14);
            btnSend->BackColor = Color::FromArgb(133, 218, 159);
            btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnSend->FlatAppearance->BorderSize = 0;
            btnSend->Location = Drawing::Point(680, 680);
            btnSend->Size = Drawing::Size(340, 70);
            btnSend->Cursor = Cursors::Hand;
            btnSend->Click += gcnew EventHandler(this, &ExpenseReportForm::btnSend_Click);
            this->Controls->Add(btnSend);
        }

        void btnFile_Click(Object^ sender, EventArgs^ e)
        {
            OpenFileDialog^ dlg = gcnew OpenFileDialog();
            dlg->Filter = L"Все документы (*.pdf;*.jpg;*.png)|*.pdf;*.jpg;*.png";
            dlg->Multiselect = true;
            if (dlg->ShowDialog() == ::DialogResult::OK)
            {
                MessageBox::Show(L"Загружено файлов: " + dlg->FileNames->Length,
                    L"BизнесТрип", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }

        void btnSend_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show(L"Авансовый отчёт направлен на проверку руководителю и в бухгалтерию.",
                L"BизнесТрип", MessageBoxButtons::OK, MessageBoxIcon::Information);
            this->Close();
        }
    };
}
