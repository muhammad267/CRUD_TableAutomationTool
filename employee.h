#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
using namespace std;

class EMPL
{
private:
    //------employee filters-------
    string emp_id;
    string employee_name_f;
    string employee_name_l;
    string employee_phone;
    string employee_salary;
    string employee_job;
    string employee_email;
    string employee_id;
    bool empty_start;
    bool empty_removal;
public:
    EMPL();
    //---------set func for data------------
    void setEmpID(string num);
    void setNamef(string namef);
    void setNamel(string nmael);
    void setPhone(string phone);
    void setSalary(string salary);
    void setJob(string job);
    void setEmail(string email);
    void setID(string id);
    void setStart(bool state);
    void setRemove(bool state);
    //----------get func for data------------
    string getEmpID() const;
    string getNamef() const;
    string getnamel() const;
    string getPhone() const;
    string getSalary() const;
    string getJob() const;
    string getEmail() const;
    string getID() const;
    bool getStart() const;
    bool getRemove() const;

    int hash_f(string namef, int size); // hash func
    int hash_probe(vector<EMPL> &hash_e, string namef); // qudratic hash func
    void insert(vector <EMPL> &hash_e, string num,string namef, string namel, string phone, string salary, string job, string email, string id); // insert func
    void print(vector<EMPL> &hash_e, string e_title[], int size_e_title); // print fucn
    void update(vector <EMPL> &hash_e, string num,string namef, string namel, string phone, string salary, string job, string email, string id); // update function 
    void select(vector <EMPL> &hash_e, string num,string namef, string namel, string phone, string salary, string job, string email, string id); // select function
    void delete_e(vector <EMPL> &hash_e, string num,string namef, string namel, string phone, string salary, string job, string email, string id); // delete function 
    void write(vector<EMPL> &hash_e, string e_title[], int size_e_title); // write function.
    void print_specific(vector<EMPL> &hash_e, string e_title[], int size_e_title, string columns, string input); // bonus func.
};

#endif