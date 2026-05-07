#pragma once
#pragma execution_character_set("utf-8")

#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace BiznesTrip {

    public ref class ApprovalForm : public Form
    {
    private:
        String^ uiFont;

    public:
        ApprovalForm()
        {
            uiFont = L"Numans";
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            this->Text = L"BизнесТрип – Согласование заявок";
            this->ClientSize = Drawing::Size(1200, 700);
            this->BackColor = Color::White;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;

            Label^ title = gcnew Label();
            title->Text = L"Заявки на согласование";
            title->Font = gcnew Drawing::Font(uiFont, 22, FontStyle::Regular);
            title->TextAlign = ContentAlignment::MiddleCenter;
            title->Location = Drawing::Point(300, 30);
            title->Size = Drawing::Size(600, 50);
            title->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->Controls->Add(title);

            DataGridView^ dgv = gcnew DataGridView();
            dgv->Location = Drawing::Point(40, 110);
            dgv->Size = Drawing::Size(1120, 400);
            dgv->BackgroundColor = Color::White;
            dgv->Font = gcnew Drawing::Font(uiFont, 12, FontStyle::Regular);
            dgv->ColumnHeadersDefaultCellStyle->Font =
                gcnew Drawing::Font(uiFont, 12, FontStyle::Bold);
            dgv->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(170, 208, 215);
            dgv->EnableHeadersVisualStyles = false;
            dgv->RowHeadersVisible = false;
            dgv->AllowUserToAddRows = false;
            dgv->ReadOnly = true;
            dgv->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            dgv->ColumnHeadersHeight = 40;
            dgv->RowTemplate->Height = 50;

            dgv->ColumnCount = 5;
            dgv->Columns[0]->Name = L"№ заявки";
            dgv->Columns[1]->Name = L"Сотрудник";
            dgv->Columns[2]->Name = L"Цель";
            dgv->Columns[3]->Name = L"Даты";
            dgv->Columns[4]->Name = L"Сумма, ₽";

            for (int i = 0; i < 5; i++)
                dgv->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

            cli::array<String^>^ row1 = { L"123", L"Пащенко Д.В.", L"Конференция", L"15.05 – 18.05", L"23 600" };
            cli::array<String^>^ row2 = { L"122", L"Петров П.П.",  L"Переговоры",  L"22.05 – 24.05", L"14 200" };
            cli::array<String^>^ row3 = { L"121", L"Сидоров А.А.", L"Обучение",    L"03.06 – 05.06", L"10 500" };
            dgv->Rows->Add(row1);
            dgv->Rows->Add(row2);
            dgv->Rows->Add(row3);

            this->Controls->Add(dgv);

            Button^ btnApprove = gcnew Button();
            btnApprove->Text = L"Утвердить";
            btnApprove->Font = gcnew Drawing::Font(uiFont, 14);
            btnApprove->BackColor = Color::FromArgb(133, 218, 159);
            btnApprove->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnApprove->FlatAppearance->BorderSize = 0;
            btnApprove->Location = Drawing::Point(40, 540);
            btnApprove->Size = Drawing::Size(220, 60);
            btnApprove->Cursor = Cursors::Hand;
            btnApprove->Click += gcnew EventHandler(this, &ApprovalForm::btnApprove_Click);
            this->Controls->Add(btnApprove);

            Button^ btnReject = gcnew Button();
            btnReject->Text = L"Отклонить";
            btnReject->Font = gcnew Drawing::Font(uiFont, 14);
            btnReject->BackColor = Color::FromArgb(238, 175, 175);
            btnReject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnReject->FlatAppearance->BorderSize = 0;
            btnReject->Location = Drawing::Point(290, 540);
            btnReject->Size = Drawing::Size(220, 60);
            btnReject->Cursor = Cursors::Hand;
            btnReject->Click += gcnew EventHandler(this, &ApprovalForm::btnReject_Click);
            this->Controls->Add(btnReject);

            Button^ btnRework = gcnew Button();
            btnRework->Text = L"Вернуть на доработку";
            btnRework->Font = gcnew Drawing::Font(uiFont, 14);
            btnRework->BackColor = Color::FromArgb(255, 226, 159);
            btnRework->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnRework->FlatAppearance->BorderSize = 0;
            btnRework->Location = Drawing::Point(540, 540);
            btnRework->Size = Drawing::Size(280, 60);
            btnRework->Cursor = Cursors::Hand;
            btnRework->Click += gcnew EventHandler(this, &ApprovalForm::btnRework_Click);
            this->Controls->Add(btnRework);
        }

        void btnApprove_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show(L"Заявка утверждена. Уведомление направлено сотруднику и в бухгалтерию.",
                L"BизнесТрип", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void btnReject_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show(L"Заявка отклонена.",
                L"BизнесТрип", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void btnRework_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show(L"Заявка возвращена сотруднику на доработку.",
                L"BизнесТрип", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    };
}
