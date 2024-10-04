/*
Student List (Add, Print, and Delete information from a vector of pointers)
Author: Ayan Masud
Date: 10/4/2024
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
  char fname[20];
  char lname[20];
  int id;
  float gpa;
};

void add(vector<Student*> &s);
void print(vector<Student*> &s);
void del(vector<Student*> &s);

int main()
{
  vector<Student*> students; // stores the struct Student as a pointer inside a vector
  
  cout << "'ADD' to add a student" << endl; // information as to what you can do
  cout << "'PRINT' to print students" << endl;
  cout << "'DELETE' to delete a student" << endl;
  cout << "'QUIT' to leave" << endl;

  
  bool doing = true;
  while (doing == true)
  {
    char cmd[7];
    cin.getline(cmd, 7); // get the command from the player
    
    if (strcmp(cmd, "ADD") == 0) { // adds a student
      add(students);
    }
    else if (strcmp(cmd, "PRINT") == 0) { // print the students in the list
      print(students);
    }
    else if (strcmp(cmd, "DELETE") == 0) { // delete a student
      del(students);
    }
    else if (strcmp(cmd, "QUIT") == 0) { // quit
      cout << endl << "Cya!" << endl;
      break;
    }
  }
  
  return 0;
}

void add(vector<Student*> &s) { // add a student to the list
  Student* student = new Student(); // adds a new struct Student to modify

  cout << "First Name: "; // gets the users input
  cin >> student->fname;
  cout << "Last Name: ";
  cin >> student->lname;
  cout << "Student ID: ";
  cin >> student->id;
  cout << "GPA: ";
  cin >> student->gpa;

  s.push_back(student); // adds the new information into the vector
}

void print(vector<Student*> &s) { // print all the students
  vector<Student*>::iterator i; // iterator is used as a for loop for vectors

  for (i = s.begin(); i < s.end(); i++) { // goes through all of the students and prints each of their informations in the correct format
    cout << (*i)->fname << " ";
    cout << (*i)->lname << ", ";
    cout << (*i)->id << ", ";
    cout << fixed << setprecision(2) << (*i)->gpa << endl; // fixed and set precision ensures that it will always be to 2 decimal places
  }
}

void del(vector<Student*> &s) { // delete a student from the list
  vector<Student*>::iterator i; // iterator is used as a for loop for vectors

  int iderase = -1;
  cout << "Enter the ID of the person to delete: ";
  cin >> iderase; // gets the id of the person to erase

  for (i = s.begin(); i<s.end(); i++) { // goes through all of the students to see if any have that id
    if ((*i)->id == iderase) {
      s.erase(i); // removes it from the vector
      return;
    }
  }

  cout << "Enter a valid ID to remove" << endl; // since it went passed the return, they user didnt input a valid id
}
