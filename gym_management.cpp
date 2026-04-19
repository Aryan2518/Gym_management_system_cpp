#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Member {
public:
    string fname, lname;
    int id;
    char sex;
    int age;
    double weight;
    int height;
    string health, phone, email, blood_grp, address;

    void searchid(vector<Member> &members, int id) {
        for (int i = 0; i < members.size(); i++) {
            if (members[i].id == id) {
                cout << "\n===== MEMBER DETAILS =====\n";
                cout << "ID: " << members[i].id << endl;
                cout << "Name: " << members[i].fname << " " << members[i].lname << endl;
                cout << "Sex: " << members[i].sex << endl;
                cout << "Age: " << members[i].age << endl;
                cout << "Weight: " << members[i].weight << " kg\n";
                cout << "Height: " << members[i].height << " cm\n";
                cout << "Medical Condition: " << members[i].health << endl;
                cout << "Phone: " << members[i].phone << endl;
                cout << "Email: " << members[i].email << endl;
                cout << "Blood Group: " << members[i].blood_grp << endl;
                cout << "Address: " << members[i].address << endl;
                return;
            }
        }
        cout << "Member not found!\n";
    }

    void calculateEndDate(int day, int month, int year, int duration) {
        month += duration;
        while (month > 12) {
            month -= 12;
            year++;
        }
        cout << "Subscription ends on: ";
        cout << day << "/" << month << "/" << year << endl;
    }

    void startmembership() {
        int mem, day, month, year;

        cout << "\n===== MEMBERSHIP PLANS =====\n";
        cout << "1. 1 Month  - Rs.2999\n";
        cout << "2. 4 Months - Rs.5999\n";
        cout << "3. 12 Months - Rs.12999\n";
        cout << "Enter your choice: ";
        cin >> mem;

        cout << "Enter start date (DD MM YYYY): ";
        cin >> day >> month >> year;

        if (mem == 1) {
            cout << "1 Month Membership Selected\n";
            calculateEndDate(day, month, year, 1);
        }
        else if (mem == 2) {
            cout << "4 Months Membership Selected\n";
            calculateEndDate(day, month, year, 4);
        }
        else if (mem == 3) {
            cout << "12 Months Membership Selected\n";
            calculateEndDate(day, month, year, 12);
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
};

class trackprg : public Member {
public:
    double newweight;
    int newheight;

    void updateweight() {
        cout << "Weight changed by " << newweight - weight << endl;
        weight = newweight;
    }

    void updateheight() {
        cout << "Height changed by " << newheight - height << endl;
        height = newheight;
    }

    void checkbmi() {
        double bmi = weight / ((height / 100.0) * (height / 100.0));
        cout << "BMI: " << bmi << endl;

        if (bmi < 18.5) cout << "Underweight\n";
        else if (bmi < 25) cout << "Normal\n";
        else if (bmi < 30) cout << "Overweight\n";
        else cout << "Obese\n";
    }
};

class routine : public Member {
public:
    string monday, tuesday, wednesday, thursday, friday, saturday, sunday;

    void searchroutine(vector<routine> &routines, int id) {
        bool found = false;

        for (int i = 0; i < routines.size(); i++) {
            if (routines[i].id == id) {
                found = true;

                cout << "\n===== ROUTINE =====\n";
                cout << "Monday: " << routines[i].monday << endl;
                cout << "Tuesday: " << routines[i].tuesday << endl;
                cout << "Wednesday: " << routines[i].wednesday << endl;
                cout << "Thursday: " << routines[i].thursday << endl;
                cout << "Friday: " << routines[i].friday << endl;
                cout << "Saturday: " << routines[i].saturday << endl;
                cout << "Sunday: " << routines[i].sunday << endl;
            }
        }

        if (!found) cout << "No routine found!\n";
    }
};

int main() {
    int choice = 0;
    Member m;
    trackprg t;
    routine r;

    vector<Member> members;
    vector<routine> routines;

    while (choice != 6) {
        cout << "\n1. Add Member\n2. Search Member\n3. Track Progress\n4. Add Routine\n5. View Routine\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter First Name: ";
            cin >> m.fname;

            cout << "Enter Last Name: ";
            cin >> m.lname;

            cout << "Enter Sex (M/F): ";
            cin >> m.sex;

            cout << "Enter Age: ";
            cin >> m.age;

            cout << "Enter Weight(KG's): ";
            cin >> m.weight;

            cout << "Enter Height(cm): ";
            cin >> m.height;

            cout << "Medical condition (yes/no): ";
            cin >> m.health;

            if (m.health == "yes") {
                cout << "Enter condition: ";
                cin >> m.health;
            } else m.health = "None";

            cout << "Phone: ";
            cin >> m.phone;
            
            
            cout << "Email: ";
            cin >> m.email;
            

            cout << "Blood Group: ";
            cin >> m.blood_grp;

            cout << "Address: ";
            cin >> m.address;

            static int regno = 1000;
            m.id = regno++;

            members.push_back(m);

            cout << "Member added! ID: " << m.id << endl;

            m.startmembership();
        }

        else if (choice == 2) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            m.searchid(members, id);
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;

            for (int i = 0; i < members.size(); i++) {
                if (members[i].id == id) {
                    t.weight = members[i].weight;
                    t.height = members[i].height;

                    int ch;
                    cout << "1.Weight 2.Height 3.BMI: ";
                    cin >> ch;

                    if (ch == 1) {
                        cout<<"Whats your new weight : ";
                        cin >> t.newweight;
                        t.updateweight();
                        members[i].weight = t.weight;
                    }
                    else if (ch == 2) {
                        cout<<"Whats your new height : ";
                        cin >> t.newheight;
                        t.updateheight();
                        members[i].height = t.height;
                    }
                    else t.checkbmi();
                }
            }
        }

        else if (choice == 4) {
            int id;
            cout << "Enter Member ID: ";
            cin >> id;

            r.id = id;

            cout << "Mon: "; cin >> r.monday;
            cout << "Tue: "; cin >> r.tuesday;
            cout << "Wed: "; cin >> r.wednesday;
            cout << "Thu: "; cin >> r.thursday;
            cout << "Fri: "; cin >> r.friday;
            cout << "Sat: "; cin >> r.saturday;
            cout << "Sun: "; cin >> r.sunday;

            routines.push_back(r);
        }

        else if (choice == 5) {
            cout<<"To view routine enter your id : ";
            int id;
            cin >> id;
            r.searchroutine(routines, id);
        }
    }

    return 0;
}