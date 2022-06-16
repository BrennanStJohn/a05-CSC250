#include <stdio.h>
#include <stdlib.h>

struct empData {
	
	char firstName[100];
	char lastName[100];
	int empNumber[100];
	int empDept[100];
	float empSalary[100];
	
};

void getRecs(int numOfEmp, FILE *empFile, struct empData);
void printID(int numOfEmp, int userInput);

int main(int argc, char *argv[]){
	
	struct empData db;
	int userInput;

	if (argc != 2) {
		
		printf("\n\tUsage: '%s filename'\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	FILE *empFile;
	
	empFile = fopen(argv[1], "r");
	
	if (empFile == NULL) {
		
		printf("The file could not be opened.\n");
		exit(EXIT_FAILURE);
	}
	
	int numOfEmp;
	
	fscanf(empFile, "%d", &numOfEmp);
	
	while ( userInput != -1) {
		
		
		puts("Welcome to the Employee Database!");
		puts("---------------------------------");
		puts("Choose an option:");
		puts("1:   Print Employee ID");
		puts("2:   Print ALL Employees");
		puts("3:   Show all employees in a department");
		puts("4:   Show salaries from highest to lowest");
		puts("-1:  QUIT");
		
		printf("%s", "Input: ");
		
		scanf("%d", &userInput);
		
		puts("");
		
		if (userInput == 1) {
		
		getRecs(numOfEmp, empFile, db);
		
		printID(numOfEmp, userInput);
		
		}
		
		else if (userInput == 2) {
			
			/*
			for (int i = 0; i < numOfEmp; i++) {	
			fscanf(empFile, "%d%s%s%d%f", &db.empNumber[i], &db.firstName[i], &db.lastName[i], &db.empDept[i], db.empSalary[i]);
			}
			*/
			for(int i = 0; i < numOfEmp; i++){
			
			printf("ID: %10s %d\n", db.empNumber[i]);
			printf("First Name: %10s %s\n", db.firstName[i]);
			printf("Last Name: %10s %s\n", db.lastName[i]);
			printf("Department: %10s %d\n", db.empDept[i]);
			printf("Salary: %10s %.2f\n", db.empSalary[i]);
			
			}
			
		}
		else if (userInput == 3) {
			
			
			
		}
		
		else if (userInput == 4) {
			
			
			
		}
		else if (userInput == 0) {
			
			printf("Please enter a valid number!\n");
			puts("");
			
		}
		else if (userInput < -1 || userInput > 4) {
			
			printf("Please enter a valid number!\n");
			puts("");
			
		}
		else if (userInput == -1) {
			
			printf("Exiting...");
			break;
			
		}
		
		
		
		
		
		
		
		
	}

	fclose(empFile);

}

void getRecs(int numOfEmp, FILE *empFile, struct empData) {

	struct empData db;

	for (int i = 0; i < numOfEmp; i++) {	
		fscanf(empFile, "%d%s%s%d%f", &db.empNumber[i], &db.firstName[i], &db.lastName[i], &db.empDept[i], db.empSalary[i]);
		}
	
}

void printID(int numOfEmp, int userInput){

	struct empData db;
	
	int ID;
	
		printf("%s", "Which employee ID to print? ");
		scanf("%d", &ID);
			
		/*
		for (int i = 0; i < numOfEmp; i++) {	
		fscanf(empFile, "%d%s%s%d%f", &db.empNumber[i], &db.firstName[i], &db.lastName[i], &db.empDept[i], db.empSalary[i]);
		}
		*/
			
		for(int i = 0; i < numOfEmp; i++){
		
			if (ID = db.empNumber[i]) {
				
				printf("ID: %10s %d\n", db.empNumber[i]);
				printf("First Name: %10s %s\n", db.firstName[i]);
				printf("Last Name: %10s %s\n", db.lastName[i]);
				printf("Department: %10s %d\n", db.empDept[i]);
				printf("Salary: %10s %.2f\n", db.empSalary[i]);
				
			}
			else {
				
				printf("Employee %d not found!", userInput);
				
			}
		
		}
			
			
}