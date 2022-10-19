#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Employee::Employee() {
	//default values set for when nothing is entered
	this->employeeFirstName = "None";
	this->employeeLastName = "None";
	this->employeeID = "None";
	this->payRate = 0;
	this->timeWorked = 0;
}

Employee::Employee(string employeeFirstName, string employeeLastName, string employeeID, double payRate, int timeWorked) {
	this->employeeFirstName = employeeFirstName;
	this->employeeLastName = employeeLastName;
	this->employeeID = employeeID;
	this->payRate = payRate;
	this->timeWorked = timeWorked;
}

void Employee::CalculatePay() {
	employeePay = timeWorked * payRate;
}

void Employee::OutputEmployee() {
	cout << setfill('-') << setw(20) << ""  << "Employee #" << employeeID << setw(20) << "" << endl << setfill(' ');
	cout << setw(4) << "" << employeeFirstName << " " << employeeLastName << endl;
}

Professional::Professional() : Employee() {
	this->healthCareContributions = 0;
	this->vacationTimeRate = 0;
	this->workWeekHours = 0;
	monthsWorked = 0;
}

Professional::Professional(string employeeFirstName, string employeeLastName, string employeeID, double payRate, int timeWorked, double healthCareContributions, double vacationTimeRate, int workWeekHours) : Employee(employeeFirstName, employeeLastName, employeeID, payRate, timeWorked){
	this->healthCareContributions = healthCareContributions;
	this->vacationTimeRate = vacationTimeRate;
	this->workWeekHours = workWeekHours;
	monthsWorked = timeWorked / 4;
}

void Professional::OutputEmployee() {
	//The output for the base class is called
	Employee::OutputEmployee();
	cout << setw(4) << "" << "Professional Employee" << endl;
	cout << setw(4) << "" << "Time Worked: " << workWeekHours << " Hours Per Week at " << timeWorked << " Weeks" << endl;
	cout << setw(4) << "" << "Current Pay: $" << employeePay << " -- $" << monthlyPay << " Per Month" << endl;
	cout << setw(4) << "" << "Health Care: $" << healthCareAmount << " -- $" << healthCareContributions << " Per Month" << endl;
	cout << setw(4) << "" << "Vacation Time: " << vacationTime << " Days -- " << vacationTimeRate << " Days Per Month" << endl << endl;
}

void Professional::CalculatePay() {
	//Employee pay is the product of time worked which is weeks, the work week hours, and the hourly rate which is pay rate
	employeePay = timeWorked * workWeekHours * payRate;
	monthlyPay = employeePay / monthsWorked;
	
}

void Professional::HealthCareContribution() {
	//The health care amount is based off a dollar amount per month
	healthCareAmount = healthCareContributions * monthsWorked;
}

void Professional::VacationCalculation() {
	//Vacation time is given for how ever many months are worked
	vacationTime = vacationTimeRate * monthsWorked;
}

NonProfessional::NonProfessional() : Employee() {
	this->healthCareContributions = 0;
	this->vacationTimeRate = 0;
}

NonProfessional::NonProfessional(string employeeFirstName, string employeeLastName, string employeeID, double payRate, int timeWorked, double healthCareContributions, double vacationTimeRate) : Employee(employeeFirstName, employeeLastName, employeeID, payRate, timeWorked) {
	//the constructor of the base clas is called
	this->healthCareContributions = healthCareContributions;
	this->vacationTimeRate = vacationTimeRate;
}

void NonProfessional::OutputEmployee() {
	Employee::OutputEmployee();
	cout << setw(4) << "" << "Non-Professional Employee" << endl;
	cout << setw(4) << "" << "Time Worked: " << timeWorked << " Hours this Week" << endl;
	cout << setw(4) << "" << "Current Pay: $" << employeePay << " -- $" << payRate << " Per Hour" << endl;
	cout << setw(4) << "" << "Health Care: $" << healthCareAmount << " -- $" << healthCareContributions << " Per Hour" << endl;
	cout << setw(4) << "" << "Vacation Time: " << vacationTime << " Hours -- One Hour for Every " << vacationTimeRate << endl << endl;
}

void NonProfessional::CalculatePay() {
	//Pay is the product of hours worked and the hourly rate which is pay rate
	employeePay = timeWorked * payRate;
}

void NonProfessional::HealthCareContribution() {
	//The health care amount is based off a dollar amount per hour
	healthCareAmount = healthCareContributions * timeWorked;
}

void NonProfessional::VacationCalculation() {
	//Vacation time is given for every so many hours which is the vacation time rate
	vacationTime = timeWorked / vacationTimeRate;
}