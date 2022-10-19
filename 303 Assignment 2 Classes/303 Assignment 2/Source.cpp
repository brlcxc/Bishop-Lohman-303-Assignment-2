#include "Employee.h"

using namespace std;

void main() {
	Professional* employee = new Professional("Bishop", "Lohman", "001", 16.47, 12, 459.67, 1.2, 45);
	employee->CalculatePay();
	employee->HealthCareContribution();
	employee->VacationCalculation();
	employee->OutputEmployee();

	NonProfessional* employee2 = new NonProfessional("Jacob", "Williams", "002", 16.47, 47, 2.34, 40);
	employee2->CalculatePay();
	employee2->HealthCareContribution();
	employee2->VacationCalculation();
	employee2->OutputEmployee();
}