#pragma once

ref class Worker {
	SQLiteCommand^ dbQuery;
	SQLiteConnection^ dbConnection;
	String^ file_audit;
	String^ file_master;
	TextBox^ status_console;
	ToolStripStatusLabel^  status_text;
	DataGridView^ data_grid;
	DataGridViewTextBoxColumn^ col_studentId;
	DataGridViewTextBoxColumn^ col_course;
	delegate void setTextBoxText(TextBox^, String^);
	delegate void addCols(DataGridView^, array<System::Windows::Forms::DataGridViewTextBoxColumn^>^);
	delegate void addRow(DataGridView^);
	delegate void clearRow(DataGridView^);
	setTextBoxText^ consoleDelegate;
	addCols^ colDelegate;
	addRow^ rowDelegate;
	clearRow^ clearDelegate;
	array<String^>^ excluded;
	array<System::Windows::Forms::DataGridViewTextBoxColumn^>^ columns;
	cliext::vector<String^> init; // init vector to avoid error LNK2022
	cliext::vector<String^> save;
	
public:
	Worker(TextBox^, ToolStripStatusLabel^, DataGridView^, String^, String^);
	void Work();
	void dropTables();
	void createTables();
	void insertAudit();
	void insertMaster();
	void createCanTake();
	bool checkPrerequisite(String^);
	cliext::vector<String^> parseFormula(String^);
	void search(Object^ str);
	void saveFile(Object^ str);
	// GUI
	void setTextBoxMethod(TextBox^, String^);
	void addColsMethod(DataGridView^, array<System::Windows::Forms::DataGridViewTextBoxColumn^>^);
	void addRowMethod(DataGridView^);
	void clearRowMethod(DataGridView^);
};
