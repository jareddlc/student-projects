#include "stdafx.h"
#include "worker.h"

Worker::Worker(TextBox ^textBox, ToolStripStatusLabel^ statusLabel, DataGridView^ dataGrid, String ^audit, String ^master)
{
	// textBox
	status_console = textBox;
	consoleDelegate = gcnew setTextBoxText(this, &Worker::setTextBoxMethod);
	status_console->Invoke(consoleDelegate, status_console, "Initializing...");

	// status
	status_text = statusLabel;
	status_text->Text = "Initializing...";

	// initialize cols
	col_studentId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	col_course = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());

	// column studentId
	col_studentId->HeaderText = L"Student ID";
	col_studentId->Name = L"studentId";
	col_studentId->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

	// column course
	col_course->HeaderText = L"Course";
	col_course->Name = L"course";
	col_course->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;

	// columns app
	columns = gcnew array<System::Windows::Forms::DataGridViewTextBoxColumn^> (2);
	columns[0] = col_studentId;
	columns[1] = col_course;

	// dataGrid
	data_grid = dataGrid;
	colDelegate = gcnew addCols(this, &Worker::addColsMethod);
	rowDelegate = gcnew addRow(this, &Worker::addRowMethod);
	clearDelegate = gcnew clearRow(this, &Worker::clearRowMethod);
	data_grid->Invoke(colDelegate, data_grid, columns);
	data_grid->Invoke(clearDelegate, data_grid);


	// excluded lists
	excluded =  gcnew array<String^> {"MATH010", "MATH003", "MATH115", "MATH116", "MATH143", "MATH144", "MATH133", "MATH134"};

	// input files
	this->file_audit = audit;
	this->file_master = master;

	// database queries
	this->dbQuery = (gcnew SQLiteCommand());
	this->dbQuery->CommandText = nullptr;

	// database connection
	this->dbConnection = (gcnew SQLiteConnection());
	this->dbConnection->ConnectionString = L"Data Source=Students.db";
	this->dbConnection->DefaultTimeout = 30;
	this->dbConnection->Flags = static_cast<SQLiteConnectionFlags>((SQLiteConnectionFlags::LogCallbackException | SQLiteConnectionFlags::LogModuleException));
	this->dbConnection->ParseViaFramework = false;

	status_console->Invoke(consoleDelegate, status_console, "Done.\r\n");
}

void Worker::setTextBoxMethod(System::Windows::Forms::TextBox^ t, String^ str)
{
	t->AppendText(str); 
}

void Worker::addColsMethod(DataGridView^ d, array<System::Windows::Forms::DataGridViewTextBoxColumn^>^ a)
{
	d->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn^>(2) {
		a[0], a[1]
	});
}

void Worker::addRowMethod(DataGridView^ d)
{
	d->Rows->Add();
}

void Worker::clearRowMethod(DataGridView^ d)
{
	d->Rows->Clear();
}

void Worker::Work()
{
	status_console->Invoke(consoleDelegate, status_console, "Connecting to Students.db...");
	status_text->Text = "Connecting to database...";
	dbConnection->Open();
	status_console->Invoke(consoleDelegate, status_console, "Done.\r\n");

	status_console->Invoke(consoleDelegate, status_console, "Dropping tables...");
	status_text->Text = "Cleaning up database...";
	this->dropTables();
	status_console->Invoke(consoleDelegate, status_console, "Done.\r\n");

	status_console->Invoke(consoleDelegate, status_console, "Inserting data...");
	status_text->Text = "Inserting files...";
	this->insertAudit();
	this->insertMaster();
	status_console->Invoke(consoleDelegate, status_console, "Done.\r\n");

	status_console->Invoke(consoleDelegate, status_console, "Creating tables...");
	status_text->Text = "Creating tables...";
	this->createTables();
	status_console->Invoke(consoleDelegate, status_console, "Done.\r\n");

	status_console->Invoke(consoleDelegate, status_console, "Calculating...");
	status_text->Text = "Processing...";
	this->createCanTake();
	status_console->Invoke(consoleDelegate, status_console, "Done.\r\n");

	status_console->Invoke(consoleDelegate, status_console, "Populating...");
	status_text->Text = "Displaying rows...";
	//this->populateTable();
	this->search("");
	status_console->Invoke(consoleDelegate, status_console, "Done.\r\n");

	/*status_console->Invoke(consoleDelegate, status_console, "Closing Students.db...");
	status_text->Text = "Closing database...";
	dbConnection->Close();
	status_console->Invoke(consoleDelegate, status_console, "Done.\r\n");*/

	status_text->Text = "Process complete.";
	status_console->Invoke(consoleDelegate, status_console, "Process complete.\r\n");
}

void Worker::dropTables()
{
	dbQuery = dbConnection->CreateCommand();

	dbQuery = gcnew SQLiteCommand("BEGIN", dbConnection);
	dbQuery->ExecuteNonQuery();

	dbQuery = gcnew SQLiteCommand("DROP TABLE IF EXISTS raw_master;", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("DROP TABLE IF EXISTS raw_audit;", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("DROP TABLE IF EXISTS letterGrades;", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("DROP TABLE IF EXISTS audit;", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("DROP TABLE IF EXISTS master;", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("DROP TABLE IF EXISTS standing;", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("DROP TABLE IF EXISTS needs;", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("DROP TABLE IF EXISTS canTake;", dbConnection);
	dbQuery->ExecuteNonQuery();

	dbQuery = gcnew SQLiteCommand("END", dbConnection);
	dbQuery->ExecuteNonQuery();
}

void Worker::createTables()
{
	dbQuery = dbConnection->CreateCommand();

	dbQuery = gcnew SQLiteCommand("BEGIN", dbConnection);
	dbQuery->ExecuteNonQuery();

	dbQuery = gcnew SQLiteCommand("CREATE TABLE `letterGrades` (`letter` varchar(2) not null, `number` decimal(2,1) not null, primary key (`letter`, `number`));", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('A+', '4.0');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('A', '4.0');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('A-', '3.7');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('B+', '3.3');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('B', '3.0');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('B-', '2.7');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('C+', '2.3');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('C', '2.0');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('C-', '1.7');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('D+', '1.3');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('D', '1.0');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('D-', '0.0');", dbConnection);
	dbQuery->ExecuteNonQuery();
	dbQuery = gcnew SQLiteCommand("INSERT INTO letterGrades VALUES('F', '0.0');", dbConnection);
	dbQuery->ExecuteNonQuery();

	dbQuery = gcnew SQLiteCommand("CREATE TABLE `audit` AS select `studentInfo` AS `studentID`, `courseID`, `completionStatus`, `number` AS `numericalGrade` FROM `raw_audit` left join `letterGrades` on `letterGrade` = `letter`	WHERE `courseID` != '';", dbConnection);
	dbQuery->ExecuteNonQuery();

	dbQuery = gcnew SQLiteCommand("CREATE TABLE `master` AS select * FROM (select replace(`courseID`,' ', '') AS `courseID`, `prereq` FROM `raw_master`);", dbConnection);
	dbQuery->ExecuteNonQuery();

	dbQuery = gcnew SQLiteCommand("CREATE TABLE `standing` AS select distinct `studentID`, 'Senior' AS `collegeLevel` FROM `audit`;", dbConnection);
	dbQuery->ExecuteNonQuery();

	dbQuery = gcnew SQLiteCommand("CREATE TABLE `needs` AS select `studentID`, `courseID` FROM `audit` WHERE `completionStatus` = 'R';", dbConnection);
	dbQuery->ExecuteNonQuery();

	dbQuery = gcnew SQLiteCommand("END", dbConnection);
	dbQuery->ExecuteNonQuery();
}

void Worker::insertAudit()
{
	// vars
	int insertedRows = 0, currentRow = 0;
	Regex^ regexStudentId = gcnew Regex("^[A][0-9]{10}$", RegexOptions::IgnoreCase);
	Match^ match;

	// create table
	dbQuery = dbConnection->CreateCommand();
	dbQuery->CommandText = "CREATE TABLE `raw_audit` (`studentInfo` text, `courseID` text, `courseDesc` text, `letterGrade` text, `completionStatus` text);";
	dbQuery->ExecuteNonQuery();

	// create transaction for faster insertion
	dbQuery = gcnew SQLiteCommand("BEGIN", dbConnection);
	dbQuery->ExecuteNonQuery();

	try 
	{
		StreamReader^ sr = gcnew StreamReader(this->file_audit);
		try	
		{
			String^ row;
			String^ id;
			array<String^>^ column;

			while(row = sr->ReadLine())
			{
				currentRow++;

				// split the columns (comma seperated file)
				column = row->Split(',');
				
				// look at first column for student ID
				match = regexStudentId->Match(column[0]);
				if(match->Success)
				{
					id = match->ToString();
				}
				column[0] = id;
				// Insert the data. expected audit csv file should have 6 columns
				if(column->Length >= 6)
				{
					dbQuery = gcnew SQLiteCommand("INSERT INTO raw_audit VALUES('"+column[0]+"', '"+column[1]+"', '"+column[2]+"', '"+column[5]+"', '"+column[7]+"');", dbConnection);
					dbQuery->ExecuteNonQuery();
					insertedRows++;
				}
			}
			// close transaction and perform the queries
			dbQuery = gcnew SQLiteCommand("END", dbConnection);
			dbQuery->ExecuteNonQuery();
			status_console->Invoke(consoleDelegate, status_console, "\r\nInserted into audit: "+insertedRows+" of "+currentRow+".\r\n");
		}
		finally
		{
			if(sr)
				delete(IDisposable^)sr;
		}
	}
	catch(Exception^ e) 
	{
		// Output the error
		status_console->Invoke(consoleDelegate, status_console, "The file could not be read.\r\n");
		status_console->Invoke(consoleDelegate, status_console, "Error at: "+currentRow+"\r\n");
		status_console->Invoke(consoleDelegate, status_console, e->Message);
	}
}

void Worker::insertMaster()
{
	// vars
	int insertedRows = 0, currentRow = 0;

	// create table
	dbQuery = dbConnection->CreateCommand();
	dbQuery->CommandText = "CREATE TABLE `raw_master` (`courseID` text, `credits` text, `prereq` text, `coreq` text);";
	dbQuery->ExecuteNonQuery();

	// create transaction for faster insertion
	dbQuery = gcnew SQLiteCommand("BEGIN", dbConnection);
	dbQuery->ExecuteNonQuery(); 
	try 
	{
		StreamReader^ sr = gcnew StreamReader(this->file_master);
		try	
		{
			String^ row;
			array<String^>^ column;

			while(row = sr->ReadLine())
			{
				currentRow++;

				// split the columns (comma seperated file)
				column = row->Split(',');

				// Insert the data. expected master csv file should have 14 columns
				if(column->Length >= 14)
				{
					dbQuery = gcnew SQLiteCommand("INSERT INTO raw_master VALUES('"+column[0]+"', '"+column[1]+"', '"+column[3]+"', '"+column[4]+"');", dbConnection);
					dbQuery->ExecuteNonQuery();
					insertedRows++;
				}
			}
			// close transaction and perform the queries
			dbQuery = gcnew SQLiteCommand("END", dbConnection);
			dbQuery->ExecuteNonQuery();
			status_console->Invoke(consoleDelegate, status_console, "Inserted into master: "+insertedRows+" of "+currentRow+".\r\n");
		}
		finally
		{
			if(sr)
				delete(IDisposable^)sr;
		}
	}
	catch (Exception^ e) 
	{
		// Output the error
		status_console->Invoke(consoleDelegate, status_console, "The file could not be read.\r\n");
		status_console->Invoke(consoleDelegate, status_console, "Error at:"+currentRow+"\r\n");
		status_console->Invoke(consoleDelegate, status_console, e->Message);
	}
}

void Worker::createCanTake()
{
	// create table
	dbQuery = dbConnection->CreateCommand();
	dbQuery->CommandText = "CREATE TABLE canTake ( `StudentID`  text, `CourseID` text)";
	dbQuery->ExecuteNonQuery();

	// select student and course from needs
	dbQuery->CommandText = "SELECT `studentID`, `courseID` FROM `needs`;";
	SQLiteDataReader^ reader = dbQuery->ExecuteReader();
	String^ row;

	// create transaction for faster insertion
	dbQuery = gcnew SQLiteCommand("BEGIN", dbConnection);
	dbQuery->ExecuteNonQuery();

	while(reader->Read())
    {
		// build the string StudentID,CourseID
		for(int col = 0; col < reader->FieldCount; ++col)
        {
			row += reader->GetValue(col)->ToString();
			if(col == 0)
				row += ",";
        }

		// check to see if student is able to take the course, if true insert
		if(this->checkPrerequisite(row))
		{
			// take[0] = student ID, take[1] = course ID
			array<String^>^ take;
			take = row->Split(',');

			dbQuery = gcnew SQLiteCommand("INSERT INTO canTake VALUES('"+take[0]+"', '"+take[1]+"');", dbConnection);
			dbQuery->ExecuteNonQuery();
		}
		row = "";
    }
	// close transaction and perform the queries
	dbQuery = gcnew SQLiteCommand("END", dbConnection);
	dbQuery->ExecuteNonQuery();
}

bool Worker::checkPrerequisite(String^ str)
{
	// vars
	bool requirement = false;
	String^ row;
	String^ status;
	cliext::vector<String^> courses;
	cliext::vector<String^> formula;
	Regex^ regexCourse = gcnew Regex("[A-Z]{1,4}[0-9]{3}[A-Z]{0,2}", RegexOptions::IgnoreCase);
	MatchCollection^ matches;

	// need[0] = student ID, need[1] = course ID
	array<String^>^ need;
	need = str->Split(',');

	// select prerequisites for the course
	dbQuery = dbConnection->CreateCommand();
	dbQuery->CommandText = "SELECT `prereq` FROM `master` WHERE `courseID` = \""+need[1]+"\";";

	SQLiteDataReader^ reader = dbQuery->ExecuteReader();
	
	while(reader->Read())
    {
		// grab the prereq string
		for(int col = 0; col < reader->FieldCount; ++col)
        {
			row += reader->GetValue(col)->ToString();

			// print the student and the course it needs along with the prerequisites of that course
			status_console->Invoke(consoleDelegate, status_console, "Student: "+need[0]+", needs: "+need[1]+", prerequisites: "+row+"\r\n");

			matches = regexCourse->Matches(row);

			// for each course in prereq string
			for each (Match^ match in matches)
			{
				// lookup the completetion status of the prereq course
				dbQuery = dbConnection->CreateCommand();
				dbQuery->CommandText = "SELECT `completionStatus` FROM `audit` WHERE `studentID` = \""+need[0]+"\" AND `courseID` = \""+match->ToString()+"\";";

				SQLiteDataReader^ lookup = dbQuery->ExecuteReader();

				// no completion found
				if(lookup->HasRows == false)
				{
					courses.push_back(match->ToString()+",TC");
				}

				// found the completion
				while(lookup->Read())
				{
					// push the status to the vector
					for(int i = 0; i < lookup->FieldCount; ++i)
					{
						status = lookup->GetValue(i)->ToString();
						courses.push_back(match->ToString()+","+status);
					}
				}
			} // end of courses vector 

			// parse the forumula
			formula = this->parseFormula(row);

			// build boolean stack
			int j = 0;
			Stack^ stack = gcnew Stack;
			status_console->Invoke(consoleDelegate, status_console, "Completion status("+formula.size()+"): ");

			for(int i = 0; i < formula.size(); i++)
			{
				if(formula.at(i) == "(")
				{
					stack->Push("(");
				}
				else if(formula.at(i) == ")")
				{
					stack->Push(")");
				}
				else if(formula.at(i) == "AND")
				{
					stack->Push("&");
				}
				else if(formula.at(i) == "OR")
				{
					stack->Push("|");
				}
				else if(formula.at(i) == "College")
				{
					// do nothing
				}
				else if(formula.at(i) == "Level=Junior")
				{
					// do nothing
				}
				else if(formula.at(i) == "Level=Senior")
				{
					// do nothing
				}
				else 
				{
					if(courses.size() > j)
					{
						array<String^>^ course; // course[0] = course, course[1] = completion status
						course = courses.at(j)->Split(',');

						if(course[1] == "C" || course[1] == "TC" || course[1] == "E")
						{
							stack->Push("true");
						}
						else
						{
							stack->Push("false");
						}

						// print course and status
						status_console->Invoke(consoleDelegate, status_console, courses.at(j)+" ");
						j++;
					}
				}// else
				
			}// for loop
			
			status_console->Invoke(consoleDelegate, status_console, "\r\n");

			// no stack. assume no prereqs
			if(formula.size() == 0)
			{
				requirement = true;
			}

			// do the logic (invert logic due to stack)
			cliext::vector<bool> operand;
			cliext::vector<bool> storeOperand;
			cliext::vector<String^> operate;
			cliext::vector<String^> storeOperate;
			for(int k = 0; k = stack->Count; k ++)
			{
				// inverted parenthesis
				if(stack->Peek() == ")") // start paren
				{
					// check for operator vector, push to store vector, clear
					if(operate.size() > 0)
					{
						storeOperate.push_back(operate.at(0));
						operate.clear();
					}
				}
				else if(stack->Peek() == "(") // end paren
				{
				}
				else if(stack->Peek() == "&" || stack->Peek() == "|")
				{
					// push operator to vector
					operate.push_back(stack->Peek()->ToString());
					// check for operand vector to push operator
					if(storeOperand.size() > 0)
					{
						storeOperate.push_back(stack->Peek()->ToString());
					}
				}
				else if(stack->Peek() == "true" || stack->Peek() == "false")
				{	
					// push operand to vector
					operand.push_back(stack->Peek() == "true" ? true : false);
					//status_console->Invoke(consoleDelegate, status_console, "pushed:"+stack->Peek()+"\r\n");
				}

				// check to see if we have 1 operator and 2 operands
				bool operation;
				if(operate.size() >= 1 && operand.size() >= 2)
				{
					// do the boolean operation
					if(operate.at(0) == "&")
					{
						operation = (operand.at(0) && operand.at(1));
					}
					else if(operate.at(0) == "|")
					{
						operation = (operand.at(0) || operand.at(1));
					}
					status_console->Invoke(consoleDelegate, status_console, operand.at(0)+" "+operate.at(0)+" "+operand.at(1)+" = "+ operation+"\r\n");

					// store the operation
					storeOperand.push_back(operation);
					// clear vector
					operand.clear();
					operate.clear();
				}
				
				// check to see if we have operations stored
				if(storeOperate.size() >= 1 && storeOperand.size() >= 2)
				{
					// do the boolean operation
					if(storeOperate.at(0) == "&")
					{
						operation = (storeOperand.at(0) && storeOperand.at(1));
					}
					else if(storeOperate.at(0) == "|")
					{
						operation = (storeOperand.at(0) || storeOperand.at(1));
					}
					status_console->Invoke(consoleDelegate, status_console, storeOperand.at(0)+" "+storeOperate.at(0)+" "+storeOperand.at(1)+" = "+ operation+"\r\n");
					// clear vector
					storeOperand.clear();
					storeOperate.clear();
					// store operation
					storeOperand.push_back(operation);
				}
				// pop
				stack->Pop();
			}// for loop

			//status_console->Invoke(consoleDelegate, status_console, "storeOperand:"+storeOperand.size()+" storeOperate:"+storeOperate.size()+" operate:"+operate.size()+" operand:"+operand.size()+"\r\n");
			// out of loop check for operations one last time
			bool operation;
			if(storeOperate.size() >= 1 && storeOperand.size() >= 2)
			{
				// do the boolean operation
				if(storeOperate.at(0) == "&")
				{
					operation = (storeOperand.at(0) && storeOperand.at(1));
				}
				else if(storeOperate.at(0) == "|")
				{
					operation = (storeOperand.at(0) || storeOperand.at(1));
				}
				status_console->Invoke(consoleDelegate, status_console, storeOperand.at(0)+" "+storeOperate.at(0)+" "+storeOperand.at(1)+" = "+ operation+"\r\n");
				// clear vector
				storeOperand.clear();
				storeOperate.clear();

				requirement = operation;
			}
			else if(storeOperate.size() >= 1 && storeOperand.size() >= 1 && operand.size() >= 1)
			{
				// do the boolean operation
				if(storeOperate.at(0) == "&")
				{
					operation = (storeOperand.at(0) && operand.at(0));
				}
				else if(storeOperate.at(0) == "|")
				{
					operation = (storeOperand.at(0) || operand.at(0));
				}
				status_console->Invoke(consoleDelegate, status_console, storeOperand.at(0)+" "+storeOperate.at(0)+" "+operand.at(0)+" = "+ operation+"\r\n");
				// clear vector
				storeOperand.clear();
				storeOperate.clear();

				requirement = operation;
			}
			else if(storeOperand.size() >= 1)
			{
				requirement = storeOperand.at(0);
			}
			else if(operand.size() >= 1)
			{
				requirement = operand.at(0);
			}

			status_console->Invoke(consoleDelegate, status_console, "returning: "+requirement+"\r\n");
			return requirement;
        }
		// while
		return requirement;
    }
	return requirement;
}

cliext::vector<String^> Worker::parseFormula(String ^formula)
{
	String^ buffer;
	cliext::vector<String^> stack;
	
	// iterate over entire formula
	for(int i = 0; i < formula->Length; i++)
	{
		if(formula[i] == '(')
		{
			stack.push_back("(");
		}
		else if(formula[i] == ')')
		{
			stack.push_back(buffer);
			stack.push_back(")");
			buffer = "";
		}
		else if(formula[i] == ' ')
		{
			if(buffer != "")
			{
				stack.push_back(buffer);
			}
			buffer = "";
		}
		else if(i == formula->Length-1)
		{
			buffer += formula[i];
			stack.push_back(buffer);
			buffer = "";
		}
		else
		{
			buffer += formula[i];
		}
	}
	return stack;
}

void Worker::search(Object^ str)
{
	data_grid->Invoke(clearDelegate, data_grid);
	save.clear();
	status_console->Invoke(consoleDelegate, status_console, "Searching for: "+str+"\r\n");
	// select student and course from can take
	dbQuery = dbConnection->CreateCommand();	
	dbQuery->CommandText = "SELECT `studentID`, `courseID` FROM `canTake` WHERE `studentID` LIKE '%"+str+"%' OR `courseID` LIKE '%"+str+"%';";
	SQLiteDataReader^ reader = dbQuery->ExecuteReader();
	String^ row;
	int i = 0;
	while(reader->Read())
    {
		// build the string StudentID,CourseID
		String^ temp = "";
		data_grid->Invoke(rowDelegate, data_grid);
		for(int col = 0; col < reader->FieldCount; ++col)
        {
			row = reader->GetValue(col)->ToString();
			if(col == 0)
			{
				data_grid->Rows[i]->Cells["studentId"]->Value = row;
			}
			else if(col == 1)
			{
				temp += ",";
				data_grid->Rows[i]->Cells["course"]->Value = row;
			}
			temp += row;
        }
		save.push_back(temp);
		i++;
    }
}

void Worker::saveFile(Object^ str)
{
	StreamWriter^ sw = gcnew StreamWriter(str->ToString());
	sw->WriteLine("Student ID, Course");
	for(int i = 0; i < save.size(); i++)
	{
		array<String^>^ column;
		column = save.at(i)->Split(',');
		sw->WriteLine(column[0]+","+column[1]);
	}
	sw->Close();
}
