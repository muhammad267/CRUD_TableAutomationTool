#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include "project.h"

// Constructor
Project::Project()
{
    project_ID = "-";
    employee_ID = "-";
    project_name = "-";
    start_date = "-";
    end_date = "-";
    project_time = "-";
    emptysincestart = true;
    emptyafterremoval = false;
}

// Set methods
void Project::set_projID(string projID) // set proj id func.
{
    project_ID = projID;
}
void Project::set_empID(string empID) // set emp id func.
{
    employee_ID = empID;
}
void Project::set_projName(string projName) // set proj name func.
{
    project_name = projName;
}
void Project::set_startDate(string startDate) // set start date func.
{
    start_date = startDate;
}
void Project::set_endDate(string endDate) // set end date func.
{
    end_date = endDate;
}
void Project::set_projTime(string projTime) // set proj time func.
{
    project_time = projTime;
}
void Project::setess(bool state) // set empty since start func.
{
    emptysincestart = state;
}
void Project::setear(bool state) // set empty after func.
{
    emptyafterremoval = state;
}


// Get methods
string Project::get_projID() const // gets proj id func.
{
    return project_ID;
}
string Project::get_empID() const // gets emp id func.
{
    return employee_ID;
}
string Project::get_projName() const // gets proj name func.
{
    return project_name;
}
string Project::get_startDate() const // gets start date func.
{
    return start_date;
}
string Project::get_endDate() const // gets end date func.
{
    return end_date;
}
string Project::get_projTime() const // gets proj time func.
{
    return project_time;
}
bool Project::getess() const // gets empty since start func.
{
    return emptysincestart;
}
bool Project::getear() const // gets empty after func.
{
    return emptyafterremoval;
}


int Project::hashFunc1(vector<Project> &hash_p, int size, int id) // Primary hash function using basic mod hashing
{
    return id % size;
}
int Project::hashFunc2(vector<Project> &hash_p, int size, int id) // Secondary hash function if primary gives collision
{
    int index = hashFunc1(hash_p, size, id); // Call primary function for the initial index
    int i = 7;

    while (hash_p[((index+i)*i)%size].getess() != true || hash_p[((index+i)*i)%size].getear() != false) // try the new hash formula, if index not empty, add one to i
    {
        i++;
    }
    index = ((index+i)*i) % size;
    return index; // Send new empty index to insert
}
void Project::insert(vector<Project> &hash_p, int size, string proj_id, string emp_id, string proj_name, string start_date, string end_date, string time)
{
    int index = hashFunc1(hash_p, size, stoi(proj_id)); // Call primary hash function to get index

    if (hash_p[index].getess() == true || hash_p[index].getear() == true) // If index is empty, insert the instance
    {
        hash_p[index].set_projID(proj_id);
        hash_p[index].set_empID(emp_id);
        hash_p[index].set_projName(proj_name);
        hash_p[index].set_startDate(start_date);
        hash_p[index].set_endDate(end_date);
        hash_p[index].set_projTime(time);
        hash_p[index].setess(false); // Sets the index status as in use
        cout << "INSERTED (" << proj_id << "," << emp_id << "," << proj_name << "," << start_date << "," << end_date << "," << time << ") into PROJECT" << endl;
    }
    else // Otherwise, call the secondary hash function to find an empty cell and insert the instance there
    {
        index = hashFunc2(hash_p, size, stoi(proj_id));
        hash_p[index].set_projID(proj_id);
        hash_p[index].set_empID(emp_id);
        hash_p[index].set_projName(proj_name);
        hash_p[index].set_startDate(start_date);
        hash_p[index].set_endDate(end_date);
        hash_p[index].set_projTime(time);
        hash_p[index].setess(false); // Sets the index status as in use
        cout << "INSERTED (" << proj_id << "," << emp_id << "," << proj_name << "," << start_date << "," << end_date << "," << time << ") into PROJECT" << endl;
    }
}
void Project::display(vector<Project> &hash_p, int size, string p_title[], int size_p_title) // Displays Project hash table
{
    cout << "\n------------------------------- Project -------------------------------" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << p_title[1] << "\t";
    cout << p_title[2] << "\t";
    cout << p_title[3] << "\t";
    cout << p_title[4] << "\t";
    cout << p_title[5] << "\t";
    cout << p_title[6] << "\n";

    for (int i=0; i<size; i++) // Loop through the hash table and display entries
    {
        if (hash_p[i].get_projID() != "-") // Output the values of the index only if something is inserted
        {
            cout << hash_p[i].get_projID();
            cout << "\t" << hash_p[i].get_empID();
            cout << "\t" << hash_p[i].get_projName();
            cout << "\t\t" << hash_p[i].get_startDate();
            cout << "\t" << hash_p[i].get_endDate();
            cout << "\t" << hash_p[i].get_projTime() << endl;
        }
    }
    cout << "\n";
}
void Project::select(vector<Project> &hash_p, int size, string proj_id, string emp_id, string proj_name, string start_date, string end_date, string time)
{
    bool found = false;
    for (int i=0; i<size; i++)
    {
        if ((proj_id == hash_p[i].get_projID() || proj_id == "*") && (emp_id == hash_p[i].get_empID() || emp_id == "*") && (proj_name == hash_p[i].get_projName() || proj_name == "*") && (start_date == hash_p[i].get_startDate() || start_date == "*") && (end_date == hash_p[i].get_endDate() || end_date == "*") && (time == hash_p[i].get_projTime() || time == "*"))
        {
            cout << "Found (" << hash_p[i].get_projID() << "," << hash_p[i].get_empID() << "," << hash_p[i].get_projName() << "," << hash_p[i].get_startDate() << "," << hash_p[i].get_endDate() << "," << hash_p[i].get_projTime() << ") in PROJECT" << endl;
            found = true;
        }
    }
    if(!found)
        cout << "No entries match query (" << proj_id << "," << emp_id << "," << proj_name << "," << start_date << "," << end_date << "," << time << ") in PROJECT" << endl;
}
void Project::update(vector<Project> &hash_p, int size, string proj_id, string emp_id, string proj_name, string start_date, string end_date, string time)
{
    int index = hashFunc1(hash_p, size, stoi(proj_id)); // Call primary hash function to get index
    
    if (hash_p[index].getess() == false && hash_p[index].getear() == false && hash_p[index].get_projID() == proj_id) 
    {
        hash_p[index].set_projID(proj_id);
        hash_p[index].set_empID(emp_id);
        hash_p[index].set_projName(proj_name);
        hash_p[index].set_startDate(start_date);
        hash_p[index].set_endDate(end_date);
        hash_p[index].set_projTime(time);
        hash_p[index].setess(false); // Sets the index status as in use
        cout << "UPDATED (" << proj_id << "," << emp_id << "," << proj_name << "," << start_date << "," << end_date << "," << time << ") into PROJECT" << endl;
    }
    else if (hash_p[index].getess() == false && hash_p[index].getear() == false && hash_p[index].get_projID() != proj_id)  // Otherwise, call the secondary hash function to find an empty cell and insert the instance there
    {
        int i = 7;
        while (hash_p[((index+i)*i)%size].get_projID() != proj_id) // try the new hash formula, if index not empty, add one to i
        {
            i++;
        }
        index = ((index+i)*i) % size;

        hash_p[index].set_projID(proj_id);
        hash_p[index].set_empID(emp_id);
        hash_p[index].set_projName(proj_name);
        hash_p[index].set_startDate(start_date);
        hash_p[index].set_endDate(end_date);
        hash_p[index].set_projTime(time);
        hash_p[index].setess(false); // Sets the index status as in use
        cout << "UPDATED (" << proj_id << "," << emp_id << "," << proj_name << "," << start_date << "," << end_date << "," << time << ") into PROJECT" << endl;
    }
    else
        cout << "Failed to Updated (" << proj_id << "," << emp_id << "," << proj_name << "," << start_date << "," << end_date << "," << time << ") into PROJECT" << endl;
}
void Project::delete_project(vector<Project> &hash_p, int size, string proj_id, string emp_id, string proj_name, string start_date, string end_date, string time)
{
    bool found = false;
    for (int i=0; i<size; i++)
    {
        if ((proj_id == hash_p[i].get_projID() || proj_id == "*") && (emp_id == hash_p[i].get_empID() || emp_id == "*") && (proj_name == hash_p[i].get_projName() || proj_name == "*") && (start_date == hash_p[i].get_startDate() || start_date == "*") && (end_date == hash_p[i].get_endDate() || end_date == "*") && (time == hash_p[i].get_projTime() || time == "*"))
        {
            cout << "Deleted (" << hash_p[i].get_projID() << "," << hash_p[i].get_empID() << "," << hash_p[i].get_projName() << "," << hash_p[i].get_startDate() << "," << hash_p[i].get_endDate() << "," << hash_p[i].get_projTime() << ") from PROJECT" << endl;
            hash_p[i].set_projID("-");
            hash_p[i].set_empID("-");
            hash_p[i].set_projName("-");
            hash_p[i].set_startDate("-");
            hash_p[i].set_endDate("-");
            hash_p[i].set_projTime("-");
            hash_p[i].setear(true);
            found = true;
        }
    }
    if(!found)
        cout << "Failed to Delete (" << proj_id << "," << emp_id << "," << proj_name << "," << start_date << "," << end_date << "," << time << ") from PROJECT" << endl;
}
void Project::write(vector<Project> &hash_p, int size, string p_title[], int size_p_title) // Outputs Project hash table
{
    ofstream write_file;
    write_file.open("project_out.csv");
    if(!write_file.good()) // check to see if the file open.
    {
        cout << "Write File failed" << endl;
    }

    write_file << p_title[0] << "\n";
    write_file << p_title[1] << ",";
    write_file << p_title[2] << ",";
    write_file << p_title[3] << ",";
    write_file << p_title[4] << ",";
    write_file << p_title[5] << ",";
    write_file << p_title[6] << "\n";

    for (int i=0; i<size; i++) // Loop through the hash table and display entries
    {
        if (hash_p[i].get_projID() != "-") // Output the values of the index only if something is inserted
        {
            write_file << hash_p[i].get_projID() << ",";
            write_file << hash_p[i].get_empID() << ",";
            write_file << hash_p[i].get_projName() << ",";
            write_file << hash_p[i].get_startDate() << ",";
            write_file << hash_p[i].get_endDate() << ",";
            write_file << hash_p[i].get_projTime() << "\n";
        }
    }

    write_file.close();
}
void Project::print_specific(vector<Project> &hash_p, int size, string p_title[], int size_p_title, string columns, string input)
{
    string proj_id,emp_id,proj_name,start_date,end_date,time;
    regex pattern1("(.*),(.*),(.*),(.*),(.*),(.*)");
    regex pattern3("\\(|\\)");
    smatch match;
    string newpiece;

    regex_search(input, match, pattern1);
    newpiece = match[0];
    newpiece = regex_replace(newpiece, pattern3, "");

    stringstream sstream(newpiece);
    getline(sstream, proj_id, ',');
    getline(sstream, emp_id, ',');
    getline(sstream, proj_name, ',');
    getline(sstream, start_date, ',');
    getline(sstream, end_date, ',');
    getline(sstream, time, ',');

    string temp, column1, column2;
    stringstream stream(columns);
    getline(stream, column1, ',');
    getline(stream, column2, '\0');
    
    cout << endl;
    for(int i= 1; i<=size_p_title; i++)
    {
        if (column1 == p_title[i])
            cout << p_title[i] << "\t\t";
    }
    for(int i= 1; i<=size_p_title; i++)
    {
        if (column2 == p_title[i])
            cout << p_title[i] << "\t\t";
    }
    cout << endl;

    for (int i=0; i<size; i++)
    {
        if ((proj_id == hash_p[i].get_projID() || proj_id == "*") && (emp_id == hash_p[i].get_empID() || emp_id == "*") && (proj_name == hash_p[i].get_projName() || proj_name == "*") && (start_date == hash_p[i].get_startDate() || start_date == "*") && (end_date == hash_p[i].get_endDate() || end_date == "*") && (time == hash_p[i].get_projTime() || time == "*"))
        {
            if (hash_p[i].get_projID() != "-")
            {
                if ((p_title[1] == column1) || (p_title[1] == column2)) // checks if the input matches the hash table.
                {
                    cout << hash_p[i].get_projID() << "\t\t"; // output.
                }
                if ((p_title[2] == column1) ||(p_title[2] == column2)) // checks if the input matches the hash table.
                {
                    cout << hash_p[i].get_empID() << "\t\t"; // output.
                }
                if ((p_title[3] == column1) ||(p_title[3] == column2)) // checks if the input matches the hash table.
                {
                    cout << hash_p[i].get_projName() << "\t\t"; // output.
                }
                if ((p_title[4] == column1) ||(p_title[4] == column2)) // checks if the input matches the hash table.
                {
                    cout << hash_p[i].get_startDate() << "\t\t"; // output.
                }
                if ((p_title[5] == column1) ||(p_title[5] == column2)) // checks if the input matches the hash table.
                {
                    cout << hash_p[i].get_endDate() << "\t\t"; // output.
                }
                if ((p_title[6] == column1) ||(p_title[6] == column2)) // checks if the input matches the hash table.
                {
                    cout << hash_p[i].get_projTime() << "\t\t"; // output.
                }
                cout << endl;
            }
        }
    }
}