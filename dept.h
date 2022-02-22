#ifndef DEPT_H_
#define DEPT_H_
#include <string>
#include <vector>
using namespace std;

class Department
{
private:
    // data varaibles.
    string ID;
    string deptname;
    string locationname;
    string mangID;
    string admrDepartID;
    bool emptysincestart;
    bool emptyafterremoval;
public:
    Department(); // constructors.

    int depthashfunction(int id, vector<Department> &hash_d); // hash function.
    // ----set functions----
    void setdeptname(string name);
    void setID(string id);
    void setlocation(string location);
    void setmangID(string id);
    void setadID(string id);
    void setess(bool value);
    void setear(bool value);
    // ----get functions----
    string getID() const;
    string getdeptName() const;
    string getlocation() const;
    string getmangID() const;
    string getadID() const;
    bool getess() const;
    bool getear() const;
    //--------------------
    void insert(vector<Department> &hash_d, string ID); // insert function.
    void read_insert(vector<Department> &hash_d, string id, string name, string location, string mangid, string asid);
    void display_departments(vector<Department> &hash_d, string d_title[], int size_d_title); // display function.
    void update_department(vector<Department> &hash_d, string id, string name, string location, string mangid, string asid); // update function.
    void select_department(vector<Department> &hash_d, string id, string name, string location, string mangid, string asid); // select function.
    void delete_department(vector<Department> &hash_d, string id, string name, string location, string mangid, string asid); // delete function.
    void write(vector<Department> &hash_d, string d_title[], int size_d_title); // write function.
    void print_specific(vector<Department> &hash_d, string d_title[], int size_d_title, string columns, string input); // bonus function.
};
#endif