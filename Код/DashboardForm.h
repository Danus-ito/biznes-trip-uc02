#pragma once
#pragma execution_character_set("utf-8")

#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

#include "NewRequestForm.h"
#include "ApprovalForm.h"
#include "AdvancePaymentForm.h"
#include "ExpenseReportForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace BiznesTrip {

    public ref class DashboardForm : public Form
    {
    private:
        Panel^ pnlSidebar;
        Panel^ pnlContent;
        Label^ lblBrand;
        Label^ lblHeader;
        Label^ lblWelcome;

        Button^ btnDashboard;
        Button^ btnRequests;
        Button^ btnAdvances;
        Button^ btnReports;
        Button^ btnApproval;
        Button^ btnProfile;
        Button^ btnExit;

        String^ uiFont;
        Color activeMenuColor;

    public:
        DashboardForm()
        {
            uiFont = L"Numans";
            activeMenuColor = Color::FromArgb(212, 224, 255);
            InitializeComponent();
        }

    private:
        Button^ MakeMenuButton(String^ text, int top, EventHandler^ handler)
        {
            Button^ b = gcnew Button();
            b->Text = text;
            b->Font = gcnew Drawing::Font(uiFont, 14, FontStyle::Regular);
            b->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            b->FlatAppearance->BorderSize = 0;
            b->BackColor = Color::White;
            b->ForeColor = Color::Black;
            b->TextAlign = ContentAlignment::MiddleCenter;
            b->Location = Drawing::Point(20, top);
            b->Size = Drawing::Size(200, 50);
            b->Cursor = Cursors::Hand;
            if (handler != nullptr) b->Click += handler;
            return b;
        }

        void InitializeComponent()
        {
            this->Text = L"BизнесТрип – Главная";
            this->ClientSize = Drawing::Size(1365, 903);
            this->BackColor = Color::White;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;

            pnlSidebar = gcnew Panel();
            pnlSidebar->BackColor = Color::White;
            pnlSidebar->Location = Drawing::Point(0, 0);
            pnlSidebar->Size = Drawing::Size(240, 903);
            pnlSidebar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

            lblBrand = gcnew Label();
            lblBrand->Text = L"BизнесТрип";
            lblBrand->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Regular);
            lblBrand->TextAlign = ContentAlignment::MiddleCenter;
            lblBrand->Location = Drawing::Point(20, 30);
            lblBrand->Size = Drawing::Size(200, 40);

            btnDashboard = MakeMenuButton(L"Дашборд", 117, nullptr);
            btnDashboard->BackColor = activeMenuColor;
            btnRequests  = MakeMenuButton(L"Мои заявки", 220,
                gcnew EventHandler(this, &DashboardForm::btnRequests_Click));
            btnAdvances  = MakeMenuButton(L"Авансы", 322,
                gcnew EventHandler(this, &DashboardForm::btnAdvances_Click));
            btnReports   = MakeMenuButton(L"Отчёты", 424,
                gcnew EventHandler(this, &DashboardForm::btnReports_Click));
            btnApproval  = MakeMenuButton(L"Согласование заявок", 526,
                gcnew EventHandler(this, &DashboardForm::btnApproval_Click));
            btnProfile   = MakeMenuButton(L"Профиль", 628, nullptr);
            btnExit      = MakeMenuButton(L"Выход", 730,
                gcnew EventHandler(this, &DashboardForm::btnExit_Click));

            pnlSidebar->Controls->Add(lblBrand);
            pnlSidebar->Controls->Add(btnDashboard);
            pnlSidebar->Controls->Add(btnRequests);
            pnlSidebar->Controls->Add(btnAdvances);
            pnlSidebar->Controls->Add(btnReports);
            pnlSidebar->Controls->Add(btnApproval);
            pnlSidebar->Controls->Add(btnProfile);
            pnlSidebar->Controls->Add(btnExit);

            pnlContent = gcnew Panel();
            pnlContent->Location = Drawing::Point(240, 0);
            pnlContent->Size = Drawing::Size(1125, 903);
            pnlContent->BackColor = Color::White;

            lblWelcome = gcnew Label();
            lblWelcome->Text = L"Добро пожаловать, Пащенко Д.В.!";
            lblWelcome->Font = gcnew Drawing::Font(uiFont, 22, FontStyle::Regular);
            lblWelcome->TextAlign = ContentAlignment::MiddleCenter;
            lblWelcome->Location = Drawing::Point(123, 60);
            lblWelcome->Size = Drawing::Size(539, 50);
            lblWelcome->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            pnlContent->Controls->Add(lblWelcome);

            CreateKpiCard(L"3", L"На согласовании", 38, 180, Color::FromArgb(170, 208, 215));
            CreateKpiCard(L"1", L"В поездке", 298, 180, Color::FromArgb(238, 175, 175));
            CreateKpiCard(L"2", L"С отчётом", 566, 180, Color::FromArgb(111, 210, 155));
            CreateKpiCard(L"12 500 ₽", L"Доступно аванса", 826, 180, Color::FromArgb(223, 168, 237));

            CreateTripsTable();

            this->Controls->Add(pnlSidebar);
            this->Controls->Add(pnlContent);
        }

        void CreateKpiCard(String^ value, String^ caption, int x, int y, Color bg)
        {
            Panel^ card = gcnew Panel();
            card->Location = Drawing::Point(x, y);
            card->Size = Drawing::Size(240, 182);
            card->BackColor = bg;
            card->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

            Label^ v = gcnew Label();
            v->Text = value;
            v->Font = gcnew Drawing::Font(uiFont, 36, FontStyle::Regular);
            v->TextAlign = ContentAlignment::MiddleCenter;
            v->Location = Drawing::Point(20, 30);
            v->Size = Drawing::Size(200, 70);
            v->BackColor = Color::Transparent;

            Label^ c = gcnew Label();
            c->Text = caption;
            c->Font = gcnew Drawing::Font(uiFont, 14, FontStyle::Regular);
            c->TextAlign = ContentAlignment::MiddleCenter;
            c->Location = Drawing::Point(10, 130);
            c->Size = Drawing::Size(220, 30);
            c->BackColor = Color::Transparent;

            card->Controls->Add(v);
            card->Controls->Add(c);
            pnlContent->Controls->Add(card);
        }

        void CreateTripsTable()
        {
            Label^ ttl = gcnew Label();
            ttl->Text = L"Мои ближайшие поездки";
            ttl->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Regular);
            ttl->TextAlign = ContentAlignment::MiddleCenter;
            ttl->Location = Drawing::Point(38, 420);
            ttl->Size = Drawing::Size(1040, 30);
            pnlContent->Controls->Add(ttl);

            DataGridView^ dgv = gcnew DataGridView();
            dgv->Location = Drawing::Point(38, 460);
            dgv->Size = Drawing::Size(1040, 280);
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
            dgv->RowTemplate->Height = 40;

            dgv->ColumnCount = 5;
            dgv->Columns[0]->Name = L"Город";
            dgv->Columns[1]->Name = L"Цель";
            dgv->Columns[2]->Name = L"Дата начала";
            dgv->Columns[3]->Name = L"Дата окончания";
            dgv->Columns[4]->Name = L"Статус";

            for (int i = 0; i < 5; i++)
                dgv->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

            cli::array<String^>^ row1 = { L"Санкт-Петербург", L"Конференция", L"15.05.2025", L"18.05.2025", L"В поездке" };
            cli::array<String^>^ row2 = { L"Казань",          L"Переговоры",  L"22.05.2025", L"24.05.2025", L"На согласовании" };
            cli::array<String^>^ row3 = { L"Новосибирск",     L"Обучение",    L"03.06.2025", L"05.06.2025", L"На согласовании" };
            dgv->Rows->Add(row1);
            dgv->Rows->Add(row2);
            dgv->Rows->Add(row3);

            pnlContent->Controls->Add(dgv);

            LinkLabel^ all = gcnew LinkLabel();
            all->Text = L"Все поездки";
            all->Font = gcnew Drawing::Font(uiFont, 14, FontStyle::Regular);
            all->LinkColor = Color::FromArgb(16, 28, 255);
            all->Location = Drawing::Point(38, 750);
            all->Size = Drawing::Size(150, 28);
            pnlContent->Controls->Add(all);
        }

        void btnRequests_Click(Object^ sender, EventArgs^ e)
        {
            (gcnew NewRequestForm())->ShowDialog();
        }

        void btnAdvances_Click(Object^ sender, EventArgs^ e)
        {
            (gcnew AdvancePaymentForm())->ShowDialog();
        }

        void btnReports_Click(Object^ sender, EventArgs^ e)
        {
            (gcnew ExpenseReportForm())->ShowDialog();
        }

        void btnApproval_Click(Object^ sender, EventArgs^ e)
        {
            (gcnew ApprovalForm())->ShowDialog();
        }

        void btnExit_Click(Object^ sender, EventArgs^ e)
        {
            this->Close();
        }
    };
}
