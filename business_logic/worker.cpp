#include "stdafx.h"
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <mysql.h>
#include<stdio.h>

using namespace System::Data::SqlClient;

// класс данных
class Data(){
    public:
	    SqlConnection^ Con;
	    DataTable ^dtTags;
	    bool UpdatingTags;
	    int id_tag;
};

// класс формы отображения данных
class Form(){
    public:
		Form1(void)
		{
			InitializeComponent();

			try {
				Con = gcnew SqlConnection("Data Source=.\\...");
				Con->Open();
			} catch (SqlException ^e) {
				MessageBox::Show("Ошибка при подключении к базе данных: " + e->Message);
				Application::Exit();
			}
            dtTag = gcnew DataTable();

		 dgvFirms->DataSource = dtTag;
    		 dgvFirms->AutoGenerateColumns = false;
		}
};