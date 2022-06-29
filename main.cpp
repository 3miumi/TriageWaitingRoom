#include <iostream>

#include "Patient.h"
#include "PatientPriorityQueue.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Patient P1("Wilford Hatheway","urgent");
    Patient P2("Brenton Jamison","immediate");
    Patient P3("Jayson Ashworth","immediate");
    Patient P4("Maxim Platt","minimal");
    Patient P5("Kylie Carter","emergency");
    Patient P6("Peta Smedley","minimal");
    Patient P7("Orson Parish","immediate");
    Patient P8("Rodger Ness","minimal");
    Patient P9("Burton Aston","emergency");
    Patient P10("Emery Pearson","immediate");
    Patient P11("Jeremiah Evered","minimal");
    Patient P12("Ethelbert Stringer","emergency");
    Patient P13("Terrence Huddleston","emergency");
    cout << P1.to_string()<<endl;

    PatientPriorityQueue pq1;
    pq1.add(P1);
    pq1.add(P2);
    pq1.add(P3);
    pq1.add(P4);
    pq1.add(P5);
    pq1.add(P6);
    pq1.add(P7);
    pq1.add(P8);
    pq1.add(P9);
    pq1.add(P10);
    pq1.add(P11);
    pq1.add(P12);
    pq1.add(P13);

    cout <<pq1.to_string()<<endl;
    return 0;
}
