# Bishop-Lohman-303
There are two child classes, for Non-professional employee and professional employee, both derived from a parent employee class<br />
- Non-professional employee
  - CalculatePay()
    - Updates the employeePay variable as the product of timeWorked as hours and the hourly payrate
  - HealCareContribution()
    - Updates the healthCareAmount variable as the product of healthCareContributions which is the contribution per hour worked and the timeWorked in hours
  - VacationCalculation()
    - Updates the vacationTime variable as the timeWorked as hours and the vacationTimeRate
    - The vacationTimeRate is the amount of vacation for a given amount of hours
- Professional employee
 - CalculatePay()
   - Updates the employeePay variable as the product of timeWorked as hours, the hourly payrate, and workWeekHours as the hours worked per week
   - monthlyPay is also calculated which is the employeePay divided by months worked
 - HealCareContribution()
   - Updates the healthCareAmount variable as the product of healthCareContributions which is the contribution per months worked and the months worked
 - VacationCalculation()
   - Updates the vacationTime variable as the months worked and the vacationTimeRate
   - The vacationTimeRate is the amount of vacation for each month worked
 
An instance of each child class is created. For both CalculatePay(), HealCareContribution(), and VacationCalculation() are called. Then the output function on each is called showing the employee information.<br />
<img src="https://user-images.githubusercontent.com/90850429/196584452-1483a0f5-59a3-48d7-9266-5436d32e056c.png"><br />
