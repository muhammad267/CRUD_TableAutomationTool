#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "dept.h"

Department::Department() // constructor.
{
    ID = "";
    deptname = "";
    locationname = "";
    mangID = "";
    admrDepartID = "";
    emptysincestart = true;
    emptyafterremoval = false;
}
int Department::depthashfunction(int id, vector<Department> &hash_d) // hash function.
{
    return id % hash_d.size();
}
void Department::setID(string id) // set id.
{
    ID = id;
}
void Department::setdeptname(string name) // set name func.
{
    deptname = name;
}
void Department::setlocation(string location) // set location func.
{
    locationname = location;
}
void Department::setmangID(string id) // set mang id func.
{
    mangID = id;
}
void Department::setadID(string id) // set ad id func.
{
    admrDepartID = id;
}
void Department::setess(bool state) // set empty since start func.
{
    emptysincestart = state;
}
void Department::setear(bool state) // set empty after removal.
{
    emptyafterremoval = state;
}

string Department::getID() const // get id function 
{
    return ID;
}
string Department::getdeptName() const // get name func.
{
    return deptname;
}
string Department::getlocation() const // get lovcation func.
{
    return locationname;
}
string Department::getmangID() const // get mang id func.
{
    return mangID;
}
string Department::getadID() const // get ad id func.
{
    return admrDepartID;
}
bool Department::getess() const // get empty since start func.
{
    return emptysincestart;
}
bool Department::getear() const // get empty after removal.
{
    return emptyafterremoval;
}

void Department::insert(vector<Department> &hash_d, string id) // insert function to add data to hash table.
{
    int position, intid, probe = 0;
    string name, location, mangid,asid;

    intid = stoi(id);
    Department d;
    position = d.depthashfunction(intid, hash_d);

    while(probe < hash_d.size())
    {
        if (hash_d[position].getID() == "")//if bucket is empty
        {
            hash_d[position].setID(id);
            cout << "enter name" << endl;
            cin >> name;
            hash_d[position].setdeptname(name);
            cout << "enter location" << endl;
            cin >> location;
            hash_d[position].setlocation(location);
            cout << "enter manager id" <<endl;
            cin >> mangid;
            hash_d[position].setmangID(mangid);
            cout << "enter admin id" << endl;
            cin >> asid;
            hash_d[position].setadID(asid);
            hash_d[position].setess(false);
            //inserted = true;
            break;
        }
        else
        {
            position = position + 1;
            if (position == hash_d.size())
            {
                position = 0;
            }
        }
        probe++;
    }
}
void Department::read_insert(vector<Department> &hash_d, string id, string name, string location, string mangid, string asid) // 
{
    int position, intid,intmid,intaid,probe = 0;

    intid = stoi(id);
    
    Department d;
    position = d.depthashfunction(intid, hash_d);

    while(probe < hash_d.size())
    {
        if (hash_d[position].getID() == "")//if bucket is empty
        {
            hash_d[position].setID(id);
            
            hash_d[position].setdeptname(name);
            
            hash_d[position].setlocation(location);
            
            hash_d[position].setmangID(mangid);
            
            hash_d[position].setadID(asid);
            hash_d[position].setess(false);
            //inserted = true;
            cout << "INSERTED (" << id << "," << name << "," << location << "," << mangid << "," << asid << ") into DEPARTMENT" << endl;
            break;
        }
        else
        {
            position = position + 1;
            if (position == hash_d.size())
            {
                position = 0;
            }
        }
        probe++;
    }
}
void Department::display_departments(vector<Department> &hash_d, string d_title[], int size_d_title)
{
    cout << "\n------------------------ Department -----------------------" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << d_title[1] << "\t";
    cout << d_title[2] << "\t";
    cout << d_title[3] << "\t";
    cout << d_title[4] << "\t";
    cout << d_title[5] << "\n";

    
    for(int i=0;i<hash_d.size();i++)
    {
        if (hash_d[i].getID() != "")
        {
            cout << hash_d[i].ID;
            cout << "\t" << hash_d[i].deptname;
            cout << "\t" << hash_d[i].locationname;
            cout << "\t" << hash_d[i].mangID;
            cout << "\t" << hash_d[i].admrDepartID << endl;
        }
    }
}
void Department::update_department(vector<Department> &hash_d, string id, string name, string location, string mangid, string asid) // update function. 
{
    int position,intid,intmid,intaid,probe = 0;
    bool updated = false;
    intid = stoi(id);
    
    Department d;
    position = d.depthashfunction(intid, hash_d);

    while(probe < hash_d.size())
    {
        if (hash_d[position].getID() == id)
        {
            hash_d[position].setID(id);
            
            hash_d[position].setdeptname(name);
            
            hash_d[position].setlocation(location);
            
            hash_d[position].setmangID(mangid);
            
            hash_d[position].setadID(asid);

            updated = true;
            cout << "UPDATED (" << id << "," << name << "," << location << "," << mangID << "," << asid << ") into DEPARTMENT" << endl;
            //hash_d[position].setess(false);
            //inserted = true;
            break;
        }
        else
        {
            position = position + 1;
            if (position == hash_d.size())
            {
                position = 0;
            }
        }
        probe++;
    }
    if (!updated)
        cout << "Failed to Update (" << id << "," << name << "," << location << "," << mangID << "," << asid << ") in DEPARTMENT" << endl;
}

void Department::select_department(vector<Department> &hash_d, string id, string name, string location, string mangid, string asid) // select function.
{
    bool found = false;
    for (int i=0;i < hash_d.size();i++)
    {
        if (((id == hash_d[i].getID())||(id == "*")) && ((name == hash_d[i].getdeptName())||(name == "*")) && ((location == hash_d[i].getlocation())||(location == "*")) && ((mangid == hash_d[i].getmangID())||(mangid == "*")) && ((asid == hash_d[i].getadID())||(asid == "*")))
        {
            cout << hash_d[i].ID << "\t"<< hash_d[i].deptname<<"\t\t" << hash_d[i].locationname << "\t\t" << hash_d[i].mangID << "\t\t" << hash_d[i].admrDepartID << endl;
            cout << "FOUND (" << id << "," << name << "," << location << "," << mangid << "," << asid << ") in DEPARTMENT" << endl;
            found = true;
        }
    }
    if(!found)
        cout << "No entries match query (" << id << "," << name << "," << location << "," << mangid << "," << asid << ") in DEPARTMENT" << endl;
    
}
void Department::delete_department(vector<Department> &hash_d, string id, string name, string location, string mangid, string asid) // delete function.
{ 
    bool found = false;
    for (int i=0; i<hash_d.size(); i++)
    {
        if ((id == hash_d[i].getID() || id == "*") && (name == hash_d[i].getdeptName() || name == "*") && (location == hash_d[i].getlocation() || location == "*") && (mangid == hash_d[i].getmangID() || mangid == "*") && (asid == hash_d[i].getmangID() || asid == "*"))
        {
            cout << "Deleted (" << hash_d[i].getID() << "," << hash_d[i].getdeptName() << "," << hash_d[i].getlocation() << "," << hash_d[i].getmangID() << "," << hash_d[i].getadID() << ") from PROJECT" << endl;
            hash_d[i].setID("");
            hash_d[i].setdeptname("");
            hash_d[i].setlocation("");
            hash_d[i].setmangID("");
            hash_d[i].setadID("");
            hash_d[i].setear(true);
            found = true;
        }
    }
    if(!found)
        cout << "Failed to Delete (" << id << "," << name << "," << location << "," << mangid << "," << asid << ") from Department" << endl;
}
void Department::write(vector<Department> &hash_d, string d_title[], int size_d_title) // write function.
{
    ofstream write_file; // open file.
    write_file.open("department_out.csv");
    if(!write_file.good()) // check to see if the file open.
    {
        cout << "Write File failed" << endl;
    }

    write_file << d_title[0] << "\n";
    write_file << d_title[1] << ",";
    write_file << d_title[2] << ",";
    write_file << d_title[3] << ",";
    write_file << d_title[4] << ",";
    write_file << d_title[5] << "\n";

    for (int i=0; i<hash_d.size(); i++) // Loop through the hash table and display entries
    {
        if (hash_d[i].getID() != "") // Output the values of the index only if something is inserted
        {
            write_file << hash_d[i].getID() << ",";
            write_file << hash_d[i].getdeptName() << ",";
            write_file << hash_d[i].getlocation() << ",";
            write_file << hash_d[i].getmangID() << ",";
            write_file << hash_d[i].getadID() << "\n";        
        }
    }
}
void Department::print_specific(vector<Department> &hash_d, string d_title[], int size_d_title, string columns, string input) // print file function.
{
    string id, name, location, mangid, asid;
    regex pattern1("(.*),(.*),(.*),(.*),(.*)");
    regex pattern3("\\(|\\)");
    smatch match;
    string newpiece;

    regex_search(input, match, pattern1);
    newpiece = match[0];
    newpiece = regex_replace(newpiece, pattern3, "");

    stringstream sstream(newpiece);
    getline(sstream, id, ',');
    getline(sstream, name, ',');
    getline(sstream, location, ',');
    getline(sstream, mangid, ',');
    getline(sstream, asid, ',');

    string column1, column2;
    stringstream stream(columns);
    getline(stream, column1, ',');
    getline(stream, column2, '\0');
    
    cout << endl;
    for(int i= 1; i<=size_d_title; i++) // 
    {
        if (column1 == d_title[i])
            cout << d_title[i] << "\t\t";
    }
    for(int i= 1; i<=size_d_title; i++)
    {
        if (column2 == d_title[i])
            cout << d_title[i] << "\t\t";
    }
    cout << endl;

    for (int i=0; i<hash_d.size(); i++)
    {
        if (((id == hash_d[i].getID())||(id == "*")) && ((name == hash_d[i].getdeptName())||(name == "*")) && ((location == hash_d[i].getlocation())||(location == "*")) && ((mangid == hash_d[i].getmangID())||(mangid == "*")) && ((asid == hash_d[i].getadID())||(asid == "*")))
        {
            if (hash_d[i].getID() != "")
            {
                if ((d_title[1] == column1) || (d_title[1] == column2)) // checks to see if the data matches the hash table.
                {
                    cout << hash_d[i].getID() << "\t\t"; // outputs
                }
                if ((d_title[2] == column1) || (d_title[2] == column2)) // checks to see if the data matches the hash table.
                {
                    cout << hash_d[i].getdeptName() << "\t\t";// outputs
                }
                if ((d_title[3] == column1) || (d_title[3] == column2)) // checks to see if the data matches the hash table.
                {
                    cout << hash_d[i].getlocation() << "\t\t";// outputs
                }
                if ((d_title[4] == column1) || (d_title[4] == column2)) // checks to see if the data matches the hash table.
                {
                    cout << hash_d[i].getmangID() << "\t\t";// outputs
                }
                if ((d_title[5] == column1) || (d_title[5] == column2)) // checks to see if the data matches the hash table.
                {
                    cout << hash_d[i].getadID() << "\t\t";// outputs
                }
                cout << endl;
            }
        }
    }
}