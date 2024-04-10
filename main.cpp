#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

  //declaring variables
  double gross_pay, state_tax, federal_tax, fica, net_pay;
  double total_gross, total_state, total_fed, total_fica;
  int employ_num = 0;
  int payroll_records = 0;
  ifstream infile;

  //opening file
  infile.open("payroll.dat");
  
  //checks if file is open
  if(!infile){
    cout << "File open failure!";
  }

  //commands with file
  if (infile){
    while(infile >> employ_num >> gross_pay >> state_tax
          >> federal_tax >> fica){
      if(employ_num >=0 && state_tax < gross_pay && federal_tax < gross_pay
         && fica < gross_pay){
        if(gross_pay > 0 && state_tax > 0 && federal_tax > 0 && fica > 0){
          if((state_tax+federal_tax+fica)<=gross_pay){
            payroll_records++;
            total_gross+=gross_pay;
            total_state+=state_tax;
            total_fed+=federal_tax;
            total_fica+=fica;
            net_pay+= gross_pay -(state_tax+federal_tax+fica);
            
          }
        }
      }
    }
  }
  //close file
  infile.close();


  //print results
  cout << endl;
  cout << setw(40) << left << "Valid payroll records: " << setw(30) << right
       << payroll_records << endl;
  cout << setw(40) << left << "Total gross pay: " << setw(20) << right << '$'
       << setw(10) << fixed << setprecision (2) << total_gross << endl;
  cout << setw(40) << left << "Total state tax: " << setw(20) << right << '$'
       << setw(10) << total_state << endl;
  cout << setw(40) << left << "Total federal tax: " << setw(20) << right << '$'
       << setw(10)<< total_fed <<endl;
  cout << setw(40) << left << "Total FICA withholdings: " << setw(20) << right
       << '$' << setw(10) << total_fica << endl;
  cout << setw(40) << left << "Total net pay: " << setw(20) << right << '$'
       << setw(10) << net_pay << endl;
  cout << endl;
}
