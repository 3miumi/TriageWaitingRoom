// Ziwen Ming
// Patient.cpp
// May 31, 2022
// Implement a Patient class used to create patient object. It
// has overload functions of priority comparison and getter functions

#ifndef P3_PATIENT_H
#define P3_PATIENT_H


#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Patient{

public:
    Patient(string ="",string="");
    // Input: name, prioritycode
    // constructor that takes in the input
    // precondition: none
    // postcondition:create name, prioritycode will be assigned,count is increment

    Patient(string,string,int);
    // Input: name, prioritycode, arrival number
    // constructor that takes in the input
    // precondition: none
    // postcondition:create name, prioritycode, and arrivalorder will be assigned

    Patient & operator=(const Patient &);
    // Overloaded = operator
    // Input: the Patient object
    // precondition: none
    // postcondition: a Patient that the passed in Patient object will be assigned to



    bool operator <(const Patient &);
    // Overloaded < operator
    // Input: the Patient object
    // precondition: none
    // postcondition: return if the passed in patient priority is higher or lower than this.

    string getName() const;
    // Input: None
    // precondition: none
    // postconditon: return the name string


    string getPriCode() const;
    // Input: None
    // precondition: none
    // postconditon: return the name string


    int getArrivalOrder() const;
    // Input: None
    // precondition: none
    // postconditon: return the arrival order

    string to_string() const;
    // returns string representation of the list
    // precondition: none
    // postcondition: returns string

private:
    string name; //patient's full name
    string priorityCode; // patient's assigned priority
    int arrivalOrder;// patient's arrival Order
    static int count; //assigned arrival number
    const  vector<string> V = {"immediate","emergency","urgent","minimal"}; // for restricting constructor and check priority

    int getCompareListIndex(string);
    // returns index in V vector
    // precondition: none
    // postcondition: returns index
};



int Patient ::count = 0;
Patient :: Patient(string name ,string priorityCode){
    if(find(V.begin(), V.end(), priorityCode) != V.end()){
        this->name= name;
        this->priorityCode = priorityCode;
        count += 1;
        arrivalOrder = count;
    }
}

Patient &Patient::operator=(const Patient &obj) {
    if (this != &obj) {
        this->name = obj.name;
        this->priorityCode = obj.priorityCode;
        this->arrivalOrder = obj.arrivalOrder;
    }
    return *this;
}




bool Patient :: operator <(const Patient &patient){
    if (getCompareListIndex(this->priorityCode) < getCompareListIndex(patient.priorityCode) ||( getCompareListIndex(this->priorityCode) == getCompareListIndex(patient.priorityCode) && this->arrivalOrder < patient.arrivalOrder))
        return true;
    else
        return false;
}


string Patient :: getName() const{
    return this->name;
}
string Patient :: getPriCode() const{
    return this->priorityCode;
}
int Patient :: getArrivalOrder() const{
    return this->arrivalOrder;
}




string Patient:: to_string() const{
    stringstream ss;
    ss << this->name << " {pri=" << this->priorityCode << ", arrive = " << arrivalOrder <<"}" << endl;
    return ss.str();
}

int  Patient :: getCompareListIndex(string priorityCode){
    auto it = find(V.begin(), V.end(), priorityCode);
    // If element was found
    if (it != V.end())
    {
        // calculating the index
        // of K
        int index = it - V.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}

#endif //P3_PATIENT_H