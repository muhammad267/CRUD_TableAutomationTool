#include "employee.h"
#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

EMPL::EMPL() // employee constructor
{
    emp_id = "";
    employee_name_f = "";
    employee_name_l = "";
    employee_phone = "";
    employee_salary = "";
    employee_job = "";
    employee_email = "";
    employee_id = "";
    empty_start = true;
    empty_removal = false;
}
void EMPL::setEmpID(string num) // set employee ID
{
    emp_id = num;
}
void EMPL::setNamef(string namef) // set first name
{
    employee_name_f = namef;
}
void EMPL::setNamel(string namel) // set last name
{
    employee_name_l = namel;
}
void EMPL::setPhone(string phone) // set phone number
{
    employee_phone = phone;
}
void EMPL::setSalary(string salary) // set salary
{
    employee_salary = salary;
}
void EMPL::setJob(string job) // set job title
{
    employee_job = job;
}
void EMPL::setEmail(string email) // set email 
{
    employee_email = email;
}
void EMPL::setID(string ID) // set department ID
{
    employee_id = ID;
}
void EMPL::setStart(bool state) // set empty bucket check
{
    empty_start = state;
}
void EMPL::setRemove(bool state) // set remove bucket check
{
    empty_removal = state;
}

string EMPL::getEmpID() const // get employee ID
{
    return emp_id;
}
string EMPL::getNamef() const // get frist name
{
    return employee_name_f;
}
string EMPL::getnamel() const // get last name.
{
    return employee_name_l;
}
string EMPL::getPhone() const // get phone number
{
    return employee_phone;
}
string EMPL::getSalary() const // get salary
{
    return employee_salary;
}
string EMPL::getJob() const // get job title
{
    return employee_job;
}
string EMPL::getEmail() const // get email
{
    return employee_email;
}
string EMPL::getID() const // get department ID
{
    return employee_id;
}
bool EMPL::getStart() const // get empty bucket check
{
    return empty_start;
}
bool EMPL::getRemove() const // get remove bucket check
{
    return empty_removal;
}

int EMPL::hash_f(string namef, int size) // hash func takes name to create hash key.
{
    int key=0;
    for(int i=0; i < namef.length(); i++)
    {
        key = key + (int)namef[i];
    }
    return key % size;
}
int EMPL::hash_probe(vector<EMPL> &hash_e, string namef) // quadratic func if collision happens.
{
    int key = hash_f(namef, hash_e.size());
    int i =0;

    while(hash_e[(key+(i*i)%10)].getStart() != true || hash_e[(key+(i*i)%10)].getRemove() != false)
    {
        i++;
    }
    key = (key+(i*i)%10);
    return key;
}

void EMPL::print(vector<EMPL> &hash_e, string e_title[], int size_e_title) // print hash table
{
    cout << "\n------------------------------------- Employee --------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << e_title[1] << "\t";
    cout << e_title[2] << "\t";
    cout << e_title[3] << "\t";
    cout << e_title[4] << "\t";
    cout << e_title[5] << "\t";
    cout << e_title[6] << "\t";
    cout << e_title[7] << "\t";
    cout << e_title[8] << "\n";

    for(int i=0; i<hash_e.size(); i++)
    {
        if (hash_e[i].getEmpID() != "")
        {
            cout << hash_e[i].getEmpID() << "\t";
            cout << hash_e[i].getNamef()<< " " << hash_e[i].getnamel() <<"\t";
            cout << hash_e[i].getPhone()<<"\t";
            cout << hash_e[i].getSalary()<<"\t";
            cout << hash_e[i].getJob()<<"\t";
            cout << hash_e[i].getEmail()<<"\t";
            cout << hash_e[i].getID()<< endl;
        }
    }
}
void EMPL::insert(vector <EMPL> &hash_e,string num, string namef, string namel, string phone, string salary, string job, string email, string id) // insert hash table.
{
    int key = hash_f(namef, hash_e.size());
    
    if(hash_e[key].getStart() == true || hash_e[key].getRemove() == true) // inserts if the position in the hash table is avaiable.
    {
        hash_e[key].setEmpID(num);
        hash_e[key].setNamef(namef);
        hash_e[key].setNamel(namel);
        hash_e[key].setPhone(phone);
        hash_e[key].setSalary(salary);
        hash_e[key].setJob(job);
        hash_e[key].setEmail(email);
        hash_e[key].setID(id);
        hash_e[key].setStart(false);
        cout << "INSERTED (" <<  num << "," << namef << "," <<  namel << "," << phone << "," <<  salary << "," << job  << "," << email << "," << id << " into EMPLOYEE.\n";
    }
    else // if position not avaliable call quadratic function and then insert date.
    {
        key = hash_probe(hash_e, namef);
        hash_e[key].setEmpID(num);
        hash_e[key].setNamef(namef);
        hash_e[key].setNamel(namel);
        hash_e[key].setPhone(phone);
        hash_e[key].setSalary(salary);
        hash_e[key].setJob(job);
        hash_e[key].setEmail(email);
        hash_e[key].setID(id);
        hash_e[key].setStart(false);
        cout << "INSERTED (" <<  num << "," << namef << "," <<  namel << "," << phone << "," <<  salary << "," << job  << "," << email << "," << id << " into EMPLOYEE.\n";
    }
    
}
void EMPL::update(vector <EMPL> &hash_e, string num,string namef, string namel, string phone, string salary, string job, string email, string id) // update function 
{
    bool found = false;
    for(int i=0; i<hash_e.size(); i++)
    {
        if(hash_e[i].getEmpID() == num) // check to see if the id exists in the hash table.
        {
            hash_e[i].setEmpID(num); // insert that data to update.
            hash_e[i].setNamef(namef);
            hash_e[i].setNamel(namel);
            hash_e[i].setPhone(phone);
            hash_e[i].setSalary(salary);
            hash_e[i].setJob(job);
            hash_e[i].setEmail(email);
            hash_e[i].setID(id);
            found = true;
            cout << "UPDATED (" <<  num << "," << namef << "," <<  namel << "," << phone << "," <<  salary << "," << job  << "," << email << "," << id << " into EMPLOYEE.\n";
        }
        
        
    }
    if(found == false)
    {
        cout << "Failed to Update (" <<  num << "," << namef << "," <<  namel << "," << phone << "," <<  salary << "," << job  << "," << email << "," << id << " into EMPLOYEE.\n";
    }
    
}
void EMPL::select(vector <EMPL> &hash_e, string num,string namef, string namel, string phone, string salary, string job, string email, string id) // select function
{
    bool found = false;
    for (int i=0; i<hash_e.size(); i++)
    {
        
       if(num == hash_e[i].getEmpID() || num == "*" && namef == hash_e[i].getNamef() || namef == "*" && namel == hash_e[i].getnamel() || namel == "*" && phone == "*" || phone == hash_e[i].getPhone() && salary == "*" || salary == hash_e[i].getSalary() && job == "*" || job == hash_e[i].getJob() && email == "*" || email == hash_e[i].getEmail() && id == "*" || id == hash_e[i].getID())
        {
            cout << "Found (" <<  hash_e[i].getEmpID() << "," << hash_e[i].getNamef() << "," <<  hash_e[i].getnamel() << "," << hash_e[i].getPhone() << "," <<  hash_e[i].getSalary() << "," << hash_e[i].getJob()  << "," << hash_e[i].getEmail() << "," << hash_e[i].getID() << ") into EMPLOYEE.\n";
            found = true;
        }
    }
    if(!found)
        cout << "No entries match query (" <<  num << "," << namef << "," <<  namel << "," << phone << "," <<  salary << "," << job  << "," << email << "," << id << ") into EMPLOYEE.\n";
}
void EMPL::delete_e(vector <EMPL> &hash_e, string num,string namef, string namel, string phone, string salary, string job, string email, string id) // update function 
{
    bool found = false;
    for(int i=0; i<hash_e.size(); i++)
    {
        if((num == hash_e[i].getEmpID() || num == "*" )&&( namef == hash_e[i].getNamef() || namef == "*" )&&( namel == hash_e[i].getnamel() || namel == "*" )&&( phone == "*" || phone == hash_e[i].getPhone() )&&( salary == "*" || salary == hash_e[i].getSalary() )&&( job == "*" || job == hash_e[i].getJob() )&&( email == "*" || email == hash_e[i].getEmail() )&&( id == "*" || id == hash_e[i].getID()))
        {
            cout << "Deleted (" <<  hash_e[i].getEmpID() << "," << hash_e[i].getNamef() << "," <<  hash_e[i].getnamel() << "," << hash_e[i].getPhone() << "," <<  hash_e[i].getSalary() << "," << hash_e[i].getJob()  << "," << hash_e[i].getEmail() << "," << hash_e[i].getID() << ") into EMPLOYEE.\n";
            hash_e[i].setEmpID("");
            hash_e[i].setNamef("");
            hash_e[i].setNamel("");
            hash_e[i].setPhone("");
            hash_e[i].setSalary("");
            hash_e[i].setJob("");
            hash_e[i].setEmail("");
            hash_e[i].setID("");
            hash_e[i].setRemove(true);
            found = true;
            
        }
        
    }
    if(found == false)
    {
        cout << "Failed to Delete (" <<  num << "," << namef << "," <<  namel << "," << phone << "," <<  salary << "," << job  << "," << email << "," << id << " into EMPLOYEE.\n";
    }
    
}
void EMPL::write(vector<EMPL> &hash_e, string e_title[], int size_e_title) // print hash table
{
    fstream file;
    file.open("employee_out.csv", ios::out);
    if(!file.good()) // check to see if the file open.
    {
        cout << "Write File failed" << endl;
    }
    
    file << e_title[0] << "\n";
    file << e_title[1] << ",";
    file << e_title[2] << ",";
    file << e_title[3] << ",";
    file << e_title[4] << ",";
    file << e_title[5] << ",";
    file << e_title[6] << ",";
    file << e_title[7] << ",";
    file << e_title[8] << "\n";

    for(int i=0; i<hash_e.size(); i++)
    {
        if (hash_e[i].getEmpID() != "")
        {
            file << hash_e[i].getEmpID() << ",";
            file << hash_e[i].getNamef()<< " " << hash_e[i].getnamel() <<",";
            file << hash_e[i].getPhone()<<",";
            file << hash_e[i].getSalary()<<",";
            file << hash_e[i].getJob()<<",";
            file << hash_e[i].getEmail()<<",";
            file << hash_e[i].getID()<< endl;
        }
    }
}
void EMPL::print_specific(vector<EMPL> &hash_e, string e_title[], int size_e_title, string columns, string input)
{
    string num, namef, namel, phone, salary, job, email, id;
    regex pattern1("(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)");
    regex pattern3("\\(|\\)");
    smatch match;
    string newpiece;

    regex_search(input, match, pattern1);
    newpiece = match[0];
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

    string column1, column2;
    stringstream stream(columns);
    getline(stream, column1, ',');
    getline(stream, column2, '\0');
    
    cout << endl;
    for(int i= 1; i<=size_e_title; i++) //outputs the specified data.
    {
        if (column1 == e_title[i])
            cout << e_title[i] << "\t\t";
    }
    for(int i= 1; i<=size_e_title; i++) // outputs the specified data.
    {
        if (column2 == e_title[i])
            cout << e_title[i] << "\t\t";
    }
    cout << endl;

    for (int i=0; i<hash_e.size(); i++) // outputs the needed data.
    {
        if((num == hash_e[i].getEmpID() || num == "*" )&&( namef == hash_e[i].getNamef() || namef == "*" )&&( namel == hash_e[i].getnamel() || namel == "*" )&&( phone == "*" || phone == hash_e[i].getPhone() )&&( salary == "*" || salary == hash_e[i].getSalary() )&&( job == "*" || job == hash_e[i].getJob() )&&( email == "*" || email == hash_e[i].getEmail() )&&( id == "*" || id == hash_e[i].getID()))
        {
            if (hash_e[i].getEmpID() != "")
            {
                if ((e_title[1] == column1) || (e_title[1] == column2)) // checks to see if the inputs matches the data.
                {
                    cout << hash_e[i].getEmpID() << "\t\t"; // output to the user.
                }
                if ((e_title[2] == column1) || (e_title[2] == column2)) // checks to see if the inputs matches the data.
                {
                    cout << hash_e[i].getNamef() << "\t\t"; // output to the user.
                }
                if ((e_title[3] == column1) || (e_title[3] == column2)) // checks to see if the inputs matches the data.
                {
                    cout << hash_e[i].getnamel() << "\t\t"; // output to the user.
                }
                if ((e_title[4] == column1) || (e_title[4] == column2)) // checks to see if the inputs matches the data.
                {
                    cout << hash_e[i].getPhone() << "\t\t"; // output to the user.
                }
                if ((e_title[5] == column1) || (e_title[5] == column2)) // checks to see if the inputs matches the data.
                {
                    cout << hash_e[i].getSalary() << "\t\t"; // output to the user.
                }
                if ((e_title[6] == column1) || (e_title[6] == column2)) // checks to see if the inputs matches the data.
                {
                    cout << hash_e[i].getJob() << "\t\t"; // output to the user.
                }
                if ((e_title[7] == column1) || (e_title[7] == column2)) // checks to see if the inputs matches the data.
                {
                    cout << hash_e[i].getEmail() << "\t\t"; // output to the user.
                }
                if ((e_title[8] == column1) || (e_title[8] == column2)) // checks to see if the inputs matches the data.
                {
                    cout << hash_e[i].getID() << "\t\t"; // output to the user.
                }
                cout << endl;
            }
        }
    }
}