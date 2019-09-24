```cpp
// Assignment P01  1063Dr Griffin
//Leila Kalantari

#include "pch.h"
#include <iostream>


#include <string>
#include <iostream>
#include <fstream>

using namespace std;


struct Employee {
	string emp_id;
	string first_name;
	string last_name;
	string gender;
	string email;
	double hourly_pay;
	Employee *Next;

	Employee() {
		emp_id = "";
		first_name = "";
		last_name = "";
		gender = "";
		email = "";
		hourly_pay = 0.0;
		Next = NULL;
	}

	Employee(string id, string first, string last, string sex, string mail, double pay) {
		emp_id = id;
		first_name = first;
		last_name = last;
		gender = sex;
		email = mail;
		hourly_pay = pay;
		Next = NULL;
	}
};

class LinkedList {
private:
	Employee* Head;

public:
	LinkedList() {
		Head = NULL;
	}


		void frontSert(string id, string first, string last, string sex, string mail, double pay) {
			Employee* Temp = new Employee(id, first, last, sex, mail, pay);

			if (Head == NULL) {
				Head = Temp;
				Head->Next = NULL;
			}
			else {
				Temp->Next = Head;
				Head = Temp;
			}

		}


		void print() {
			ofstream outfile;
			outfile.open("output.txt", ofstream::app);
			Employee* Temp = Head;

			while (Temp != NULL) {
				outfile << Temp->emp_id << ", " << Temp->first_name << ", " << Temp->last_name << ", " << Temp->email << ", " << Temp->gender << ", " << Temp->hourly_pay << endl;

				if (Temp->Next) {
					cout << "->";
				}
				Temp = Temp->Next;
			}
			outfile.close();
		}

		//this function  adds an employee to the front of the list
		void push(string id, string first, string last, string sex, string mail, double pay) {
			Employee *AddNewEploy = new Employee(id, first, last, sex, mail, pay); // making new node with new employee
			if (Head == NULL) {
				Head = AddNewEploy;
			}
			else {
				AddNewEploy->Next = Head;
				Head = AddNewEploy;
				cout << AddNewEploy->emp_id << ", " << AddNewEploy->first_name << ", " << AddNewEploy->last_name << ", " << AddNewEploy->email << ", " << AddNewEploy->gender << ", " << AddNewEploy->hourly_pay << endl;
			}
		}
		//this function removes an employee from the front of the list 
		void pop() {
			if (Head == NULL) {
				cout << "listEmpty";
			}
			else
			{
				Employee *removEmp = Head;//Head has address of first node,when Employee *removEmp = Head; means removEmp is pointing to the first nood.
				Head = Head->Next;// Head->Next(first nood ,part Next) has address of second nood. Head = Head->Next; means Heed is connecting to second nood.
				delete(removEmp); //remove an employee from the front
			}

		}

		//this function returns a boolean true/false if emaili is in the list
		bool find(string e) {
			Employee* Temp = Head;
			while (Temp != NULL) {
				if (Temp->email == e) {//finding email
					cout << Temp->email << endl;
					return true;
					
				}
				Temp = Temp->Next;
			}
			return false;
		}

		//this function  removes an item from anywhere in the list
		void delet(string e) {
			Employee* now = Head;
			Employee* prv = NULL;

			while (now != NULL) { //loop till reach to the end
				if (now->email == e) {
					if (prv == NULL) {
						Head = now->Next;
						return;
					}

					prv->Next = now->Next;
					return;

				}
				else {
					prv = now;
					now = now->Next;
				}
			}
		}

		//finding first 30 Ids:
		void wrtFrst30Ids() {
			ofstream fout("outfile.txt", ofstream::app);
			Employee *now = Head;
			int i = 0;
			while (now != NULL && i < 30) {
				//for (int i = 0; i < 30; i++) {
					fout << now->emp_id << endl;
					now = now->Next;
				//}
					i++;
			}
			fout.close();
		}

		//This function is serching "salon":
		void Searchsalon(string key)
		{
			ofstream fout("outfile.txt", ofstream::app);
			cout << "in search" << endl;
	
			Employee* Now = Head;
			while (Now != NULL) {
				if (Now->email.find(key) != std::string::npos) {//finfing salon in emails addresses
					fout << "Found!" << '\n';
				}
				else {
					fout << "Not Found" << endl;
				}
				Now = Now->Next;//updating Now
			}

			fout.close();
		}

		

	};

	int main() {

		LinkedList EmpList;
		string empid;
		string first;
		string last;
		string email;
		string gender;
		double pay;

		ofstream fout("outfile.txt");
		fout.close();

		ifstream fin("employees.dat");

		string line;
		//string *tokens;
		
		//read till end of file
		while (!fin.eof()) {

			fin >> empid >> first >> last >> gender >> email >> pay;

			EmpList.frontSert(empid, first, last, gender, email, pay);

		}
		//calling all functions:
		EmpList.delet("cpetkens0@engadget.com");
		EmpList.pop();//calling pop function
		EmpList.print();


		EmpList.Searchsalon("salon");
		cout << "done with search" << endl;
		EmpList.wrtFrst30Ids();
		cout << "done with 30" << endl;
	
		EmpList.find("mcolclough2@ning.com ");
		cout << "done with find" << endl;

		EmpList.push("11-2381366", "Luci", "Johnson", "F", "lc.jon@gmail.com", 76.90); //calling push function 
		return 0;
	}


```
