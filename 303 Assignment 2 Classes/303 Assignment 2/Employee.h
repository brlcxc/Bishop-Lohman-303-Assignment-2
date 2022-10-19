#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iomanip>
#include <string>

using namespace std;

class Employee {
	public:
		Employee();
		Employee(string employeeFirstName, string employeeLastName, string employeeID, double payRate, int timeWorked);
		virtual void OutputEmployee();
		virtual void CalculatePay();
		virtual void HealthCareContribution() = 0;
		virtual void VacationCalculation() = 0;

	protected:
		string employeeFirstName;
		string employeeLastName;
		string employeeID;
		double payRate;
		double employeePay;
		int timeWorked;
		double healthCareContributions;
		double vacationTimeRate;
		double vacationTime;
		double healthCareAmount = 0;
};

class Professional : public Employee {
	public:
		Professional();
		Professional(string employeeFirstName, string employeeLastName, string employeeID, double payRate, int timeWorked, double healthCareContributions, double vacationTimeRate, int workWeekHours);
		void OutputEmployee();
		/* The monthly pay for a professional employee is calculated
		   pre: the class instance has valid member data
		   post: the values of employee pay and monthly pay are updated
		*/
		void CalculatePay();
		/* The total health care amount for a professional employee is calculated
			pre: the class instance has valid member data
			post: the values of health care contribution is updated
		*/
		void HealthCareContribution();
		/* The vacation time for a professional employee is calculated
			pre: the class instance has valid member data
			post: the values of vacation time is updated
		*/
		void VacationCalculation();
	private:
		double monthsWorked = 0;
		double monthlyPay = 0;
		int workWeekHours;
};

class NonProfessional : public Employee {
public:
	NonProfessional();
	NonProfessional(string employeeFirstName, string employeeLastName, string employeeID, double payRate, int timeWorked, double healthCareContributions, double vacationTimeRate);
	void OutputEmployee();
	/* The monthly pay for a non-professional employee is calculated
	   pre: the class instance has valid member data
	   post: the value of employee pay is updated
	*/
	void CalculatePay();
	/* The total health care amount for a non-professional employee is calculated
		pre: the class instance has valid member data
		post: the values of health care contribution is updated
	*/
	void HealthCareContribution();
	/* The vacation time for a non-professional employee is calculated
		pre: the class instance has valid member data
		post: the values of vacation time is updated
	*/
	void VacationCalculation();
};

#endif