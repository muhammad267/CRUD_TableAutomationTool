#ifndef PROJECT_H_
#define PROJECT_H_
#include <string>
#include <vector>
using namespace std;

class Project
{
private:
    // data varaibles to be stored in hash tables.
    string project_ID;
    string employee_ID;
    string project_name;
    string start_date;
    string end_date;
    string project_time;
    bool emptysincestart;
    bool emptyafterremoval;

public:
    Project(); // Constructor, sets proj id to "-"

    // Set methods
    void set_projID(string projID);
    void set_empID(string empID);
    void set_projName(string projName);
    void set_startDate(string startDate);
    void set_endDate(string endDate);
    void set_projTime(string projTime);
    void setess(bool value);
    void setear(bool value);

    // Get methods
    string get_projID() const;
    string get_empID() const;
    string get_projName() const;
    string get_startDate() const;
    string get_endDate() const;
    string get_projTime() const;
    bool getess() const;
    bool getear() const;


    // Hash table functions
    int hashFunc1(vector<Project> &hash_p, int size, int id); // hash func
    int hashFunc2(vector<Project> &hash_p, int size, int id); // hash func
    void insert(vector<Project> &hash_p, int size, string, string, string, string, string, string); // insert func.
    void display(vector<Project> &hash_p, int size, string p_title[], int size_p_title); // display func.
    void select(vector<Project> &hash_p, int size, string, string, string, string, string, string); // select func.
    void delete_project(vector<Project> &hash_p, int size, string, string, string, string, string, string); // delete func.
    void update(vector<Project> &hash_p, int size, string, string, string, string, string, string); // update func.
    void write(vector<Project> &hash_p, int size, string p_title[], int size_p_title); // write func.
    void print_specific(vector<Project> &hash_p, int size, string p_title[], int size_p_title, string, string); // bonus func.
};
#endif