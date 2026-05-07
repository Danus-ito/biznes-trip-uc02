#pragma once
#pragma execution_character_set("utf-8")

#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

#include "DashboardForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace BiznesTrip {

    public ref class LoginForm : public Form
    {
    private:
        Label^ lblTitle;
        Label^ lblSubtitle;
        Label^ lblLogin;
        Label^ lblPassword;
        TextBox^ tbLogin;
        TextBox^ tbPassword;
        Button^ btnLogin;
        LinkLabel^ lblForgot;
        LinkLabel^ lblRegister;

    public:
        LoginForm()
        {
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            this->Text = L"BизнесТрип – Вход";
            this->ClientSize = Drawing::Size(1365, 903);
            this->BackColor = Color::White;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;

            String^ uiFont = L"Numans";

            lblTitle = gcnew Label();
            lblTitle->Text = L"BизнесТрип";
            lblTitle->Font = gcnew Drawing::Font(uiFont, 28, FontStyle::Regular);
            lblTitle->TextAlign = ContentAlignment::MiddleCenter;
            lblTitle->Location = Drawing::Point(608, 91);
            lblTitle->Size = Drawing::Size(224, 50);
            lblTitle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

            lblSubtitle = gcnew Label();
            lblSubtitle->Text = L"Учёт командировок и служебных поездок";
            lblSubtitle->Font = gcnew Drawing::Font(uiFont, 14, FontStyle::Regular);
            lblSubtitle->TextAlign = ContentAlignment::MiddleCenter;
            lblSubtitle->Location = Drawing::Point(512, 166);
            lblSubtitle->Size = Drawing::Size(415, 28);

            lblLogin = gcnew Label();
            lblLogin->Text = L"Логин";
            lblLogin->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Regular);
            lblLogin->Location = Drawing::Point(503, 250);
            lblLogin->AutoSize = true;

            tbLogin = gcnew TextBox();
            tbLogin->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Regular);
            tbLogin->Location = Drawing::Point(481, 286);
            tbLogin->Size = Drawing::Size(446, 40);
            tbLogin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            tbLogin->Text = L"admin";

            lblPassword = gcnew Label();
            lblPassword->Text = L"Пароль";
            lblPassword->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Regular);
            lblPassword->Location = Drawing::Point(501, 385);
            lblPassword->AutoSize = true;

            tbPassword = gcnew TextBox();
            tbPassword->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Regular);
            tbPassword->Location = Drawing::Point(481, 421);
            tbPassword->Size = Drawing::Size(446, 40);
            tbPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            tbPassword->UseSystemPasswordChar = true;
            tbPassword->Text = L"admin";

            btnLogin = gcnew Button();
            btnLogin->Text = L"Войти";
            btnLogin->Font = gcnew Drawing::Font(uiFont, 16, FontStyle::Regular);
            btnLogin->ForeColor = Color::White;
            btnLogin->BackColor = Color::FromArgb(83, 143, 255);
            btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            btnLogin->FlatAppearance->BorderSize = 1;
            btnLogin->FlatAppearance->BorderColor = Color::Black;
            btnLogin->Location = Drawing::Point(481, 548);
            btnLogin->Size = Drawing::Size(446, 63);
            btnLogin->Click += gcnew EventHandler(this, &LoginForm::btnLogin_Click);

            lblForgot = gcnew LinkLabel();
            lblForgot->Text = L"Забыли пароль?";
            lblForgot->Font = gcnew Drawing::Font(uiFont, 14, FontStyle::Regular);
            lblForgot->LinkColor = Color::FromArgb(16, 28, 255);
            lblForgot->TextAlign = ContentAlignment::MiddleCenter;
            lblForgot->Location = Drawing::Point(311, 656);
            lblForgot->Size = Drawing::Size(176, 28);

            lblRegister = gcnew LinkLabel();
            lblRegister->Text = L"Регистрация";
            lblRegister->Font = gcnew Drawing::Font(uiFont, 14, FontStyle::Regular);
            lblRegister->LinkColor = Color::FromArgb(16, 28, 255);
            lblRegister->TextAlign = ContentAlignment::MiddleCenter;
            lblRegister->Location = Drawing::Point(925, 661);
            lblRegister->Size = Drawing::Size(160, 28);

            this->Controls->Add(lblTitle);
            this->Controls->Add(lblSubtitle);
            this->Controls->Add(lblLogin);
            this->Controls->Add(tbLogin);
            this->Controls->Add(lblPassword);
            this->Controls->Add(tbPassword);
            this->Controls->Add(btnLogin);
            this->Controls->Add(lblForgot);
            this->Controls->Add(lblRegister);
        }

        void btnLogin_Click(Object^ sender, EventArgs^ e)
        {
            if (tbLogin->Text == L"admin" && tbPassword->Text == L"admin")
            {
                this->Hide();
                DashboardForm^ dash = gcnew DashboardForm();
                dash->FormClosed += gcnew FormClosedEventHandler(this, &LoginForm::onDashClosed);
                dash->Show();
            }
            else
            {
                MessageBox::Show(L"Неверный логин или пароль.\nДемо-доступ: admin / admin",
                    L"Ошибка авторизации", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void onDashClosed(Object^ sender, FormClosedEventArgs^ e)
        {
            Application::Exit();
        }
    };
}
