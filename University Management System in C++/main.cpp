#include<string>
#include <fstream>
#include <iostream>


using namespace std;

    string stID ="0";
    string fName ="";
    string lName ="";
    string age ="";
    string phoneNumber ="0";
    //  string studentupdate = "";
   // string Searchcourse="";
    string courseId="0";
    char course [64];
    char address [256];

    void addStudent();
    void searchStudent();
    void updateStudent();
    //void Searchcourse();
    //void courseRecords();
    void AllStudentRecord();
   // void deletestudentrecord();

int main() {

    int operation = 0;


    do{
            cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n";
            cout << "|                *  University Management System  *                  |\n";
            cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n";
            cout << "|                                                                    |\n";
            cout << "|                                                                    |\n";
            cout << "|                                                                    |\n";
            cout << "|             - Press (1) To Add Student Records                     |\n";
            cout << "|             - Press (2) To Search Student Records                  |\n";
            cout << "|             - press (3) To Updata Student Records                  |\n";
            cout << "|             - press (4) To Search Coures Records                   |\n";
            cout << "|             - Press (5) To Search The Student List And Course      |\n";
            cout << "|             - Press (6) To Delete A Student Record                 |\n";
            cout << "|             - Press (7) To Exit                                    |\n";
            cout << "|                                                                    |\n";
            cout << "|                                                                    |\n";
            cout << "|                                                                    |\n";
            cout << "|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|\n";

            reopr:
            cin >> operation;

            switch (operation){
                case 1:
                    system("CLS");
                    addStudent();
                    break;
                case 2:
                    system("CLS");
                    searchStudent();
                    break;
                case 3:
                    system("CLS");
                     updateStudent();
                case 4:
                    system("CLS");
                  // Searchcourse();
                    break;
                case 5:
                    system("CLS");
                    AllStudentRecord();
                case 6:
                    system("CLS");
                   // deletestudentrecord();
                case 7:
                    cout << "Exiting program \n";
                    break;
                default:
                    cerr << "Invalid Operation, Try Again \n"<<endl;
                    goto reopr;

            }
    }while(operation != 7);

    return 0;

}


    void addStudent() {

        fstream fileSt;
        fileSt.open("ums.txt", ios::out | ios::app);

        cout << "Enter Student ID\n";
        cin >> stID;
        cout << "Enter Student First Name \n";
        cin >> fName;
        cout << "Enter Student Last Name \n";
        cin >> lName;
        cout << "Enter Student Age\n";
        cin >> age;
        cout << "Enter Student Coures\n";
        cin.ignore();
        cin.getline(course, 64);
        cout << "Enter Student Phone Number\n";
        cin >> phoneNumber;
        cout << "Enter Student Home Address\n";
        cin.ignore();
        cin.getline(address, 256);


        fileSt << "\n\n" << stID << "\n" << fName << "\n" << lName << "\n" << age << "\n" << course << "\n"
               << phoneNumber << "\n" << address << endl;
        fileSt.close();

        system("CLS");
        cout << "Successfully Added" << endl;

    }

    void searchStudent() {
        string searchID = "";
        int chno = 0;
        cout << "Enter the Student ID: ";
        cin >> searchID;

        fstream fileSt;
        fileSt.open("ums.txt", ios::in);


        while (!fileSt.eof()) {

            fileSt >> stID;

            if (stID == searchID) {
                fileSt >> fName;
                fileSt >> lName;
                fileSt >> age;
                fileSt.ignore();
                fileSt.getline(course, 64);
                fileSt >> phoneNumber;
                fileSt.ignore();
                fileSt.getline(address, 256);

                cout << " * Student ID: " << stID << "\n * Student Name: " << fName << " " << lName
                     << "\n * Age: " << age << "\n * Course: " << course << "\n * Phone Number: " << phoneNumber
                     << "\n * Home Address: " << address << endl;
                chno++;
                system("PAUSE");
                system("CLS");
            }
        }


    }
    void AllStudentRecord(){

            fstream fileSt;
        fileSt.open("ums.txt", ios::in);

            while (!fileSt.eof()) {

                fileSt >> stID;
                fileSt >> fName;
                fileSt >> lName;
                fileSt >> age;
                fileSt >> course;
                fileSt.ignore();
                fileSt.getline(course, 64);
                fileSt>> phoneNumber;
                fileSt.ignore();
                fileSt.getline(address, 256);



                cout << "Student ID: " << stID << "\nFirst Name: " << fName << "\nLast Name" << lName << "\nAge: " << age << "\nCourse ID" << course << "\nCourse Name"<< course<< "\nPhone Number: " << phoneNumber << "\nHome Address: " << address << endl;
                cout <<"\n";
            }
            system("pause");
            system ("cls");
        }





void updateStudent(){
    string updateId;
    int temp;
    int check = 0;
    char vrfy;
    cout << "Insert Student ID to Delete: ";
    again:
    cin >> temp;
    if(temp < 1000){
        cout << "Invalid Search ID, Try Again: ";
        goto again;
    }
    updateId = to_string(temp);

    fstream fileSt;
    fileSt.open("ums.txt", ios::in);

    while (!fileSt.eof()){

        fileSt >> stID;
        if(updateId == stID) {
            fileSt >> fName;
            fileSt >> lName;
            fileSt >> age;
            fileSt.ignore();
            fileSt.getline(address, 256);
            fileSt >> phoneNumber;
            fileSt >> course;
            fileSt.ignore();
            fileSt.getline(course, 64);

            cout << "Match Found for the Student Number -" << updateId << "-" << endl;
            cout  << "* Student ID" << ": " << stID << endl  << "* Student Name" << ": " << fName << " " << lName << endl;

            cerr << "This action will permanently delete the record from database,\nDo you want to continue (y/n) ";
            cin >> vrfy;

            check++;
        }
    }
    fileSt.close();

    if(vrfy == 'y' || vrfy == 'Y'){

        string stID = "0";
        string fName = "";
        string lName = "";
        string age = "";
        string phone = "";
        char address [256];
        string courseId = "0";
        char course [64];

        fstream stData;
        fileSt.open("ums.txt", ios::in);

        ofstream temp;
        temp.open("temp.txt");

        while (!fileSt.eof()){
            fileSt >> stID;
            fileSt >> fName;
            fileSt >> lName;
            fileSt >> age;
            fileSt.ignore();
            fileSt.getline(address, 256);
            fileSt >> phoneNumber;
            fileSt >> course;
            fileSt.ignore();
            fileSt.getline(course, 64);

            if(updateId != stID){
                temp << "\n\n" << stID << "\n" << fName << "\n" << lName << "\n" << age << "\n" << address << "\n" << phoneNumber << "\n" << course << "\n" ;
            }

            if(updateId == stID){
                cout << "Enter Student ID: ";
                cin >> stID;
                cout << "Enter Student's First Name: ";
                cin >> fName;
                cout << "Enter Student's Last Name: ";
                cin >> lName;
                cout << "Enter Student's Age: ";
                cin  >> age;
                cout << "Enter Student's Address: ";
                cin.ignore();
                cin.getline(address, 256);
                cout << "Enter Student's Phone Number: ";
                cin >> phoneNumber;
                cout << "Enter the Registering Course ID: ";
                cin >> course;

                temp << "\n\n" << stID << "\n" << fName << "\n" << lName << "\n" << age << "\n" << address << "\n" << phoneNumber << "\n" << course <<  courseId <<"\n" ;

            }
        }
        fileSt.close();
        temp.close();

        remove("ums.txt");
        rename("temp.txt", "ums.txt");

        cout << "Student Record Removed From the Database" << endl;
    }
    if (check == 0){
        cout << "\nNo Record Found.\n" << endl;
    }
    system("pause");
    system("cls");
}


   //}
  //  void deletestudentrecord();

  /*  void Searchcourse();{

    string Searchcourse="";
        int chno = 0;
            cout << "*****************************************************************************\n";
            cout << "Enter The Id of the Course: ";
            cin >> Searchcourse;


            fstream fileSt;
            fileSt.open("ums.txt", ios::in);

            while (!fileSt.eof()){



            fileSt >> stID;
            fileSt >> fName;
            fileSt >> lName;
            fileSt >> age;
            fileSt >> course;
            fileSt.ignore();
            fileSt.getline(course, 64);
            fileSt>> phoneNumber;
            fileSt.ignore();
            fileSt.getline(address, 256);



            cout << "Student ID: " << stID << "\nFirst Name: " << fName << "\nLast Name" << lName << "\nAge: " << age << "\nCourse ID" << course << "\nCourse Name"<< course<< "\nPhone Number: " << phoneNumber << "\nHome Address: " << address << endl;

            cout <<"\n";
            find++;

            }
*/







