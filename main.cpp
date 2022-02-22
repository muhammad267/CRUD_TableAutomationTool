#include "dept.h"
#include "project.h"
#include "employee.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

const int SIZE_d = 10; // department vector array size.
vector <Department> hash_d(SIZE_d); // vector array for department class.
const int SIZE_p = 10; // project vector array size.
vector <Project> hash_p(SIZE_p); // vector array for project class.
const int SIZE_e=10; // employee vector array size.
vector <EMPL> hash_e(SIZE_e); // vector array for employee class.

const int size_e_title = 9; // employee array size.
string e_title[size_e_title]; //  array to store employee title. 
const int size_d_title = 6; // department array size.
string d_title[size_d_title]; // array to store department title.
const int size_p_title = 7; // project array size.
string p_title[size_p_title]; // array to store project title.

EMPL e; // instance for employee.
Department d; // instance for department.
Project p; // instance for project.

void open_employee(string filename_e) // opens employees file and prossecs.
{
    ifstream file_e(filename_e); // opens file
    EMPL e;
    
    if(!file_e.good())  // check to see if the file open.
    {
        cout << "File failed." << endl;
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    string namef, namel, job, email,num, phone, salary, id ; // temp varaibles
    string t_title, t_e_id, t_namef, t_namel, t_phone, t_salary,t_job, t_email, t_d_id; // temp title.
    cout << filename_e << endl;
    cout << "Processing Employee table." << endl;

    getline(file_e, t_title); // inputs the table title.
    // inputs the data coloumn varaibles.
    getline(file_e, t_e_id, ',');
    getline(file_e, t_namef, ',');
    getline(file_e, t_namel, ',');
    getline(file_e, t_phone, ',');
    getline(file_e, t_salary, ',');
    getline(file_e, t_job, ',');
    getline(file_e, t_email, ',');
    getline(file_e, t_d_id, '\n');
    // stores titles in the employee title array.
    e_title[0] = t_title;
    e_title[1] = t_e_id;
    e_title[2] = t_namef;
    e_title[3] = t_namel;
    e_title[4] = t_phone;
    e_title[5] = t_salary;
    e_title[6] = t_job;
    e_title[7] = t_email;
    e_title[8] = t_d_id;

    while(!file_e.eof()) // loop runs and store info from file to class array.
    {
        getline(file_e, num, ',');
        getline(file_e, namef, ',');
        getline(file_e, namel, ',');
        getline(file_e, phone, ',');
        getline(file_e, salary, ',');
        getline(file_e, job, ',');
        getline(file_e, email, ',');
        getline(file_e, id, '\n');

        e.insert(hash_e,num, namef, namel, phone, salary, job, email, id); // insert the data in hash table.
    }
}
void open_dept(string filename) // opens department file and process it.
{
    ifstream file1(filename); // opens the file.
    Department d; // instance for department class.
    //cout << filename.length();
    if(!file1.good())  // check to see if the file open.
    {
        cout << "File failed." << endl;
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    string file_title, temp_id, temp_dept, temp_location, temp_mang_id, temp_admin_id; // temp title varaibles.
    cout << filename << endl; // outputs the file name.
    cout << "Processing Department table." << endl;

    getline(file1, file_title, '\n'); // inputs the title of the table from the file.
    // inputs the title from the file.
    getline(file1, temp_id, ',');
    getline(file1, temp_dept, ',');
    getline(file1, temp_location, ',');
    getline(file1, temp_mang_id, ',');
    getline(file1, temp_admin_id, '\n');
    // stores the title in the string department array.
    d_title[0] = file_title;
    d_title[1] = temp_id;
    d_title[2] = temp_dept;
    d_title[3] = temp_location;
    d_title[4] = temp_mang_id;
    d_title[5] = temp_admin_id;

    //for(int i=0; i<SIZE_d; i++) // loop runs and store info from file to class array.
    while(!file1.eof()) // takes the input data from the file.
    {
        getline(file1, temp_id, ',');
        getline(file1, temp_dept, ',');
        getline(file1, temp_location, ',');
        getline(file1, temp_mang_id, ',');
        getline(file1, temp_admin_id, '\n');

        d.read_insert(hash_d,temp_id,temp_dept, temp_location, temp_mang_id, temp_admin_id); // calls the insert data function.
    }
}
void open_project(string file_name) // opens project file and process it.
{
    ifstream file1(file_name); // opens the project file.
    if(!file1.good())  // check to see if the file open.
    {
        cout << "File failed." << endl;
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    string temp, proj_id, emp_id, proj_name, startDate, endDate, time; // string data variables.
    string file_title, p_projID, p_empID, p_projName, p_startDate, p_endDate, p_time; // string title variables.
    cout << file_name << endl;
    cout << "Processing Project table." << endl;
    
    getline(file1, file_title); // inputs the file title.
    // inputs title of the data table.
    getline(file1, p_projID, ',');
    getline(file1, p_empID, ',');
    getline(file1, p_projName, ',');
    getline(file1, p_startDate, ',');
    getline(file1, p_endDate, ',');
    getline(file1, p_time, '\n');
    // store the titles in the project title array.
    p_title[0] = file_title;
    p_title[1] = p_projID;
    p_title[2] = p_empID;
    p_title[3] = p_projName;
    p_title[4] = p_startDate;
    p_title[5] = p_endDate;
    p_title[6] = p_time;

    while(!file1.eof()) // loop runs and store info from file to class array.
    {
        getline(file1, proj_id, ',');
        getline(file1, emp_id, ',');
        getline(file1, proj_name, ',');
        getline(file1, startDate, ',');
        getline(file1, endDate, ',');
        getline(file1, time, '\n');

        p.insert(hash_p, SIZE_p, proj_id, emp_id, proj_name, startDate, endDate, time); // calls the project insert function.
    }
}

void employee(string line) // function process the Insert update select delete and bonus project.
{
    string input = line; // stores the input into seprate stringline for later use.
    regex reg_project("PROJECT\\(SELECT\\(.*\\).*\\).*\\)\\s*"); // regex pattern to find pattern and select.
    regex project_pattern("PROJECT\\(SELECT\\(\\((.*)\\),.*\\),(.*)\\)\\s*"); // regex pattern match for *.
    string num,namef,namel,phone,salary,job,email,id; // temp variables to hold bouns data.
    bool in_project = false;

    if(regex_match(input, reg_project)) // regex matches for bouns.
    {
        smatch breakdown; // smatch breakdown.
        regex_search(input, breakdown, project_pattern); // regex searche for pattern.
        input = breakdown[1]; // stores data from smatch.
        string columns = breakdown[2]; // stores the from smatch.
        in_project = true;
        e.print_specific(hash_e, e_title, size_e_title, columns, input); // calls the print bonus function.
    }
    else
    {
        regex pattern2("\\((.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)\\)");
        regex pattern3("\\(|\\)");
        smatch matcher1,matcher2;
        string newpiece;
  
        regex_search(line, matcher2, pattern2);
        newpiece = matcher2[0];
        newpiece = regex_replace(newpiece, pattern3, "");

        stringstream sstream(newpiece);
        getline(sstream, num, ',');
        getline(sstream, namef, ',');
        getline(sstream, namel, ',');
        getline(sstream, phone, ',');
        getline(sstream, salary, ',');
        getline(sstream, job, ',');
        getline(sstream, email, ',');
        getline(sstream, id, ',');
    }

    regex reg_insert("^INSERT\\(.*\\)\\s*$"); // matches if the string consists insert.
    regex reg_update("^UPDATE\\(.*\\)\\s*$"); // matches if the string consists update.
    regex reg_select("^SELECT\\(.*\\)\\s*$"); // matches if the string consists select.
    regex reg_delete("^DELETE\\(.*\\)\\s*$"); // matches if the string consists delete.
    if(regex_match(line, reg_insert)) // regex match for insert.
    {
        e.insert(hash_e,num, namef, namel, phone, salary, job, email, id); // calls the insert func
    }
    else if(regex_match(line, reg_update)) // regex match for update.
    {
        e.update(hash_e,num, namef, namel, phone, salary, job, email, id); // calls the update func.
    }
    else if(regex_match(line, reg_select)) // regex match for select.
    {
        e.select(hash_e,num, namef, namel, phone, salary, job, email, id); // calls the select func.
    }
    else if(regex_match(line, reg_delete)) // regex match for delete.
    {
        e.delete_e(hash_e,num, namef, namel, phone, salary, job, email, id); // calls the match func.
    }  
}
void department(string line) // function process the Insert update select delete and bonus project.
{
    string input = line; // stores the input into line for later use.
    regex reg_project("PROJECT\\(SELECT\\(.*\\).*\\).*\\)\\s*"); // matches the project and select.
    regex project_pattern("PROJECT\\(SELECT\\(\\((.*)\\),.*\\),(.*)\\)\\s*"); // regex pattern for *.
    string departId,name,location,mgrId,admrDepartId; // temp varables for bonus.
    bool in_project = false;

    if(regex_match(input, reg_project)) // regex match for bonus.
    {
        smatch breakdown;
        regex_search(input, breakdown, project_pattern);
        input = breakdown[1];
        string columns = breakdown[2];
        in_project = true;
        d.print_specific(hash_d, d_title, size_d_title, columns, input);
    }
    else
    {        
        regex pattern2("\\((.*),(.*),(.*),(.*),(.*),(.*)\\)");
        regex pattern3("\\(|\\)");
        smatch matcher1,matcher2;
        string newpiece;
  
        regex_search(line, matcher2, pattern2);
        newpiece = matcher2[0];
        newpiece = regex_replace(newpiece, pattern3, "");
        // stores the data into temp varaibles.
        stringstream sstream(newpiece);
        getline(sstream, departId, ',');
        getline(sstream, name, ',');
        getline(sstream, location, ',');
        getline(sstream, mgrId, ',');
        getline(sstream, admrDepartId, ',');
    }

    regex reg_insert("^INSERT\\(.*\\)\\s*$"); // matches if the string consists insert.
    regex reg_update("^UPDATE\\(.*\\)\\s*$"); // matches if the string consists update.
    regex reg_select("^SELECT\\(.*\\)\\s*$"); // matches if the string consists select.
    regex reg_delete("^DELETE\\(.*\\)\\s*$"); // matches if the string consists select.
    
    if(regex_match(line, reg_insert)) // regex match for insert.
    {
        d.read_insert(hash_d,departId, name, location, mgrId, admrDepartId); // calls the insert func.
    }
    else if(regex_match(line, reg_update)) // regex match for update.
    {
        d.update_department(hash_d,departId, name, location, mgrId, admrDepartId); // calls the update func.
    }
    else if(regex_match(line, reg_select)) // regex match for select.
    {
        d.select_department(hash_d,departId, name, location, mgrId, admrDepartId); // calls the select func.
    }
    else if(regex_match(line, reg_delete)) // regex match for delete.
    {
        d.delete_department(hash_d, departId, name, location, mgrId, admrDepartId); // calls the delete func.
    }  
}
void project(string input_line) // function process the Insert update select delete and bonus project.
{
    string input = input_line; // stores the input into line variable for later use.
    regex reg_project("PROJECT\\(SELECT\\(.*\\).*\\).*\\)\\s*"); // regex pattern for project and select.
    regex project_pattern("PROJECT\\(SELECT\\(\\((.*)\\),.*\\),(.*)\\)\\s*"); // regex pattern for *.
    string proj_id,emp_id,proj_name,start_date,end_date,time; // temp varaibles.
    bool in_project = false;

    if(regex_match(input_line, reg_project)) // regex match for bonus.
    {
        smatch breakdown;
        regex_search(input, breakdown, project_pattern);
        input = breakdown[1];
        string columns = breakdown[2];
        in_project = true;
        p.print_specific(hash_p, SIZE_p, p_title, size_p_title, columns, input); // calls print bonus function.
    }
    else
    {
        regex pattern2("\\((.*),(.*),(.*),(.*),(.*),(.*),(.*)\\)"); // regex pattern
        regex pattern3("\\(|\\)");
        smatch match;
        string newpiece;

        regex_search(input, match, pattern2); // regex search.
        newpiece = match[0];
        newpiece = regex_replace(newpiece, pattern3, "");
        // stores the data into temp varaibles.
        stringstream sstream(newpiece);
        getline(sstream, proj_id, ',');
        getline(sstream, emp_id, ',');
        getline(sstream, proj_name, ',');
        getline(sstream, start_date, ',');
        getline(sstream, end_date, ',');
        getline(sstream, time, ',');
    }

    regex reg_insert("^INSERT\\(.*\\)\\s*$"); // matches if the string consists insert.
    regex reg_update("^UPDATE\\(.*\\)\\s*$"); // matches if the string consists update.
    regex reg_select("^SELECT\\(.*\\)\\s*$"); // matches if the string consists select.
    regex reg_delete("^DELETE\\(.*\\)\\s*$"); // matches if the string consists select.

    if(regex_match(input, reg_insert)) // regex match for insert.
    {
        p.insert(hash_p, SIZE_p, proj_id,emp_id, proj_name, start_date, end_date, time); // call the insert function.
    }
    else if(regex_match(input, reg_update)) // regex match for update.
    {
        p.update(hash_p, SIZE_p, proj_id,emp_id, proj_name, start_date, end_date, time); // call the update function.
    }
    else if(regex_match(input, reg_select)) // regex match for select.
    {
        p.select(hash_p, SIZE_p, proj_id, emp_id, proj_name, start_date, end_date, time); // call the update function.
    }  
    else if(regex_match(input, reg_delete)) // regex match for delete.
    {
        p.delete_project(hash_p, SIZE_p, proj_id, emp_id, proj_name, start_date, end_date, time); // call for the delete function.
    }
}

void file_intialize() // opens the input file and reads the data.
{
    string file_name, temp_file; // file varaibles.

    cout << "Please enter the .txt file name: ";
    cin >> file_name;

    ifstream file(file_name); // opens the user entered file.
    //ifstream file("input.txt");
    if(!file.good())  // check to see if the file open.
    {
        cout << "INPUT FILE DOES NOT EXIST....... EXITING" << endl;
        exit(EXIT_FAILURE);
    }
    int i;
    for( i=0; i<3 ; i++)
    {
        // following code opens employee project and department files.
        getline(file, temp_file);

        if (temp_file.length() == 26)
        {
            //temp_file.erase(temp_file.begin()+14, temp_file.end());
            int num = temp_file.length() - 14;
            temp_file.erase(14, num);
            open_dept(temp_file);

        }
        else if (temp_file.length() == 22) 
        {
            temp_file.erase(temp_file.begin()+12, temp_file.end());
            open_employee(temp_file);
        }
        else if (temp_file.length() == 20)
        {
            temp_file.erase(temp_file.begin()+11, temp_file.end());
            open_project(temp_file);
        }
        else
        {
            cout << "File not found." << endl; 
        }
    }
    getline(file, temp_file); // inputs empty line.
    
    while(!file.eof()) // reads the file for function commands until end of file.
    {
        string input_str;
        getline(file, input_str); // input from the file.

        regex reg_display("^DISPLAY\\(\\)\\s$"); // matches display from file.
        regex reg_write("WRITE\\(\\)\\s*"); // matches display from file.
        regex reg_project("PROJECT\\(.*\\(.*\\).*\\).*\\)\\s*"); // matches display from file.
        if(regex_match(input_str, reg_display)) // regex match for display.
        {
            e.print(hash_e, e_title, size_e_title); // call employee print function
            d.display_departments(hash_d, d_title, size_d_title); // call department print func
            p.display(hash_p, SIZE_p, p_title, size_p_title); // call project print func.
        }
        if(regex_match(input_str, reg_write)) // regex match for write.
        {
            e.write(hash_e, e_title, size_e_title); // calls write function for employee.
            d.write(hash_d, d_title, size_d_title); // calls department write function.
            p.write(hash_p, SIZE_p, p_title, size_p_title); // calls project write function.
            cout << "Processing complete!" << endl;
        }
        if(regex_match(input_str, reg_project)) // regex match for bonus.
        {
            smatch p_match;
            regex reg_ptable("\\),(.*)\\),"); // searches table name.
            regex_search(input_str,p_match, reg_ptable);
            
            if(p_match.str(1) == "employee")
            {
                employee(input_str);
            }
            if(p_match.str(1) == "department")
            {
                department(input_str);
            }
            if(p_match.str(1) == "project")
            {
                project(input_str);
            }
        }
        

        smatch match;
        regex reg_table("\\),(.*)\\)"); // searches table name.
        regex_search(input_str,match, reg_table);
            
        if(match.str(1) == "employee")
        {
            employee(input_str);
        }
        if(match.str(1) == "department")
        {
            department(input_str);
        }
        if(match.str(1) == "project")
        {
            project(input_str);
        }
    }
}

int main()
{
    file_intialize(); // call the file intalize function.
    return 0;
}