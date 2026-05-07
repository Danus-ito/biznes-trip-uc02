#pragma once
#pragma execution_character_set("utf-8")

#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace BiznesTrip {

    public ref class AdvancePaymentForm : public Form
    {
    private:
        String^ uiFont;

    public:
        AdvancePaymentForm()
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

        void InitializeComponent()
        {
            this->Text = L"BизнесТрип – Выдача аванса";
            this->ClientSize = Drawing::Size(1100, 750);
            this->BackColor = Color::White;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;

            Label^ title = gcnew Label();
            title->Text = L"Выдача аванса";
            title->Font = gcnew Drawing::Font(uiFont, 22, FontStyle::Regular);
            title->TextAlign = ContentAlignment::MiddleCenter;
            title->Location = Drawing::Point(360, 20);
            title->Size = Drawing::Size(380, 50);
            title->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->Controls->Add(title);

            this->Controls->Add(MakeLabel(L"Заявка", 80, 90, 100, 14, FontStyle::Bold));

            Panel^ pInfo = gcnew Panel();
            pInfo->Location = Drawing::Point(80, 125);
            pInfo->Size = Drawing::Size(940, 50);
            pInfo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            Label^ inf = MakeLabel(L"   № 123 от 15.05.2025  (Пащенко Д.В.)", 0, 10, 940, 14, FontStyle::Regular);
            pInfo->Controls->Add(inf);
            this->Controls->Add(pInfo);

            this->Controls->Add(MakeLabel(L"Расчёт аванса", 80, 200, 300, 14, FontStyle::Bold));

            int rowY = 245;
            this->Controls->Add(MakeLabel(L"Проезд",                    80,  rowY,    250, 14, FontStyle::Regular));
            this->Controls->Add(MakeLabel(L"8 000 ₽",                   600, rowY,    150, 14, FontStyle::Regular));
            this->Controls->Add(MakeLabel(L"Проживание",                80,  rowY+40, 250, 14, FontStyle::Regular));
            this->Controls->Add(MakeLabel(L"12 000 ₽",                  600, rowY+40, 150, 14, FontStyle::Regular));
            this->Controls->Add(MakeLabel(L"Суточные (3 дн. × 1 200 ₽)",80,  rowY+80, 350, 14, FontStyle::Regular));
            this->Controls->Add(MakeLabel(L"3 600 ₽",                   600, rowY+80, 150, 14, FontStyle::Regular));

            Label^ total = gcnew Label();
            total->Text = L"Итого к выдаче:        23 600 ₽";
            total->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Bold);
            total->Location = Drawing::Point(80, rowY+135);
            total->Size = Drawing::Size(700, 35);
            this->Controls->Add(total);

            this->Controls->Add(MakeLabel(L"Способ выдачи", 80, 470, 200, 14, FontStyle::Regular));
            ComboBox^ cb = gcnew ComboBox();
            cb->Font = gcnew Drawing::Font(uiFont, 14);
            cb->Location = Drawing::Point(80, 505);
            cb->Size = Drawing::Size(303, 40);
            cb->Items->Add(L"На банковскую карту");
            cb->Items->Add(L"Наличными");
            cb->Items->Add(L"На корпоративную карту");
            cb->SelectedIndex = 0;
            cb->DropDownStyle = ComboBoxStyle::DropDownList;
            this->Controls->Add(cb);

            this->Controls->Add(MakeLabel(L"Дата выдачи", 500, 470, 200, 14, FontStyle::Regular));
            DateTimePicker^ dt = gcnew DateTimePicker();
            dt->Font = gcnew Drawing::Font(uiFont, 14);
            dt->Location = Drawing::Point(500, 505);
            dt->Size = Drawing::Size(220, 40);
            dt->Format = DateTimePickerFormat::Custom;
            dt->CustomFormat = L"dd.MM.yyyy";
            dt->Value = DateTime(2025, 5, 13);
            this->Controls->Add(dt);

            Button^ btnPay = gcnew Button();
            btnPay->Text = L"Выдать аванс";
            btnPay->Font = gcnew Drawing::Font(uiFont, 14);
            btnPay->BackColor = Color::FromArgb(133, 218, 159);
            btnPay->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnPay->FlatAppearance->BorderSize = 0;
            btnPay->Location = Drawing::Point(700, 620);
            btnPay->Size = Drawing::Size(330, 70);
            btnPay->Cursor = Cursors::Hand;
            btnPay->Click += gcnew EventHandler(this, &AdvancePaymentForm::btnPay_Click);
            this->Controls->Add(btnPay);
        }

        void btnPay_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show(L"Аванс 23 600 ₽ выдан сотруднику Пащенко Д.В.\nПлатёжное поручение № АП-0142.",
                L"BизнесТрип", MessageBoxButtons::OK, MessageBoxIcon::Information);
            this->Close();
        }
    };
}
