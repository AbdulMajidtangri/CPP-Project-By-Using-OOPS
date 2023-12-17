#include<iostream>
#include<windows.h>
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;

class Login {
public:
  string username;
  string password;
   
};

class HospitalManagement {
public:
  static const int NUM_DOCTORS = 3;
  string doctors[NUM_DOCTORS];
  string schedules[NUM_DOCTORS];

  HospitalManagement() {
    // Initialize doctors and their schedules 
    doctors[0] = "Dr.Azher";
    schedules[0] = "*Monday to Friday: 9 am to 5 pm\n\t\t*Saturday: 9 am to 1 pm\n\t\t*Sunday: off";

    doctors[1] = "Dr.Babber";
    schedules[1] = "*Monday to Friday, 9 am to 1 pm\n\t\t*Saturday, 11 am to 6 pm\n\t\t*Sunday: off";

    doctors[2] = "Dr.Moazam";
    schedules[2] = "*Monday to Friday: 5 am to 3 pm\n\t\t*Saturday: 11 am to 7 pm\n\t\t*Sunday :off";
  }

  void viewDoctors() const {
    cout << "\n\n\n\t\t\t\t----------------------------------------------------------\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|     ^^^^^^^^^^^^^^DOCTORS^^^^^^^^^^^^                     |\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t|!!!!!!!!!!!!!!(three Doctors are Available)!!!!!!!!!!!!!   |\n";
    cout << "\t\t\t\t|                         	                                 |\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t| <<<<[information and timing are given Below]>>>>>>        |\n";
    cout << "\t\t\t\t|                                                           |\n";
    cout << "\t\t\t\t------------------------------------------------------------\n";

    for (int i = 0; i < NUM_DOCTORS; ++i) {
      cout << "\t\t\t\t**************" << doctors[i] << "*******************\n\n";
      cout << "\t[[timings]] : \n\n" << "\t\t" << schedules[i] << "\n";//loop to show the shedule of Docters 
      cout << "---------------------------------------------------------------------------------------------------------------------------\n";
    }
  }

  };

class Registration {
public:
  string name;
  string regDate;
  int age;
  int day;
  int month;
  int year;

  void registerPatient() {
    cout << "***********************************REGISTRATION OF PATIENTS**********************************************\n";
    cout << "\t\t\tEnter Patient name: ";
    cin >> name;
    cout << "\t\t\tEnter Patient age: ";
    cin >> age;
    cout << "\t\t\tEnter Registration Date (DD-MM-YYYY): ";
    cin >> day >> month >> year;
    cout << "\n\t\t\tPatient is registered.......\n";
    cout << "\nPress any key to continue";
    getch();
  }

  void viewPatientDetails() {
    cout << "+++++++++++++REGISTERED PATIENTS++++++++++++\n";
    cout << "\t\t\tPatient name: " << name << endl;
    cout << "\t\t\tEnter Patient age: " << age << endl;
    cout << "\t\t\tEnter Registration Date (DD-MM-YYYY) : " << day << "-" << month << "-" << year << endl;
  }

  void bookAppointment(const HospitalManagement& hospital) {
    int doctorIndex;
    cout << "Enter the index of the doctor you want to book an appointment with:\n ";
    cout << "\t\t\t\t0.DR.azher \n";
    cout << "\t\t\t\t1.DR.Babber\n";
    cout << "\t\t\t\t2.Dr.Moazam\n";
    cin >> doctorIndex;

    if (doctorIndex >= 0 && doctorIndex < HospitalManagement::NUM_DOCTORS) {//scope resolution use to access the static mewmber
	      cin.ignore(); //> Clear the newline character from the input 

      cout << "Enter appointment time: ";
      string appointmentTime;
      getline(cin, appointmentTime);

      hospital.viewDoctors(); //> Display doctors' information
      cout << "Appointment booked with " << hospital.doctors[doctorIndex] << " for " << name << " at " << appointmentTime << ".\n";
    } else {
      cout << "Invalid doctor index.\n";
    }
  }
};
void createLoginFile(const Login& log) {//this function create and store the username and password in text file
    ofstream file("login.txt");//file name login
    if (file.is_open()) {
        file << "Username: " << log.username << "\n";//store username
        file << "Password: " << log.password << "\n";//store password
        file.close();//close the file 
        cout << "Login details saved to 'login.txt'\n";
    }
    else {
        cout << "Unable to create login file.\n";
    }
}
int main() {
  system("color 71");
  Login log;

  cout << "\n\n\n\n\n\n\t\t\t\t------------------------------------------------------------\n";
  cout << "\t\t\t\t|                                                          |\n";
  cout << "\t\t\t\t|                                                          |\n";
  cout << "\t\t\t\t|                                                          |\n";
  cout << "\t\t\t\t| **********HOSPITAL**************                         |\n";
  cout << "\t\t\t\t|          MANAGMENT*******************                    |\n";
  cout << "\t\t\t\t|                                                          |\n";
  cout << "\t\t\t\t|                                                          |\n"; 
  cout << "\t\t\t\t|                                                          |\n";
  cout << "\t\t\t\t------------------------------------------------------------\n";
  
  cout << "\t\t\t\tEnter username: ";
 setw(50); cin >> log.username;
  cout << "\t\t\t\tEnter password: ";
 setw(50); cin >> log.password;
 createLoginFile(log);
  Registration reg;
  HospitalManagement hospital;

  int sel;
  do {  //do loop used to make my  project to work as sequence
    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t----------------------------------------------------------\n";
    cout << "\t\t\t\t|                                                         |\n";
    cout << "\t\t\t\t| **********HOSPITAL**************                        |\n";
    cout << "\t\t\t\t|          MANAGMENT*******************                   |\n";
    cout << "\t\t\t\t----------------------------------------------------------\n";
    cout << "\n\n\n\t\t\t\t----------------------------------------------------------\n";
    cout << "\t\t\t\t|     1: Register a patient:                               |\n";
    cout << "\t\t\t\t|     2: View Patient details:                             |\n";
    cout << "\t\t\t\t|     3: Book an appointment                               |\n";
    cout << "\t\t\t\t|     4: View Doctors                                      |\n";
    cout << "\t\t\t\t|     5: Exit                                              |\n";
    cout << "\t\t\t\t|      What do you want to d                               |\n";
    cout << "\t\t\t\t|                                                          |\n";
    cout << "\t\t\t\t|                                                          |\n"; 
    cout << "\t\t\t\t----------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t";
    cin >> sel;

    switch (sel) {
    case 1:
      system("cls");
      reg.registerPatient();
      break;
    case 2:
  system("cls");
  if (reg.name.empty()) {//when registration is empty then then this condition will show
    cout << "---------------------------------\n";
    cout << "\t\t\t\tNo patient registered yet...\n";
  } else {
    reg.viewPatientDetails();
  }
  cout << "\t\t\t\tpress any key to continue";
  cout << "---------------------------------------------------------------------------------------------------------------";
  getch();
  break;

    case 3:
  system("cls");
  if (reg.name.empty()) {//this condition will show when  there will no any bookedappoinmernt
    cout << "---------------------------------\n";
    cout << "\t\t\t\tNo patient registered yet. Register first, then book an appointment.\n";
  } else {
    reg.bookAppointment(hospital);
  }
  cout << "\t\t\t\tpress any key to continue";
  cout << "---------------------------------------------------------------------------------------------------------------";
  getch();
  break;

    case 4:
  system("cls");
  hospital.viewDoctors();
  cout << "\nPress any key to continue";
  getch(); 
  break;

    }
  }while (sel != 5);

  getch();

  return 0;
}

