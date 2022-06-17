#include <stdio.h>
#include <stdlib.h>

struct empData {
	
	int empNumber;
	char firstName[15];
	char lastName[15];
	int empDept;
	float empSalary;
	
};

void getRecs(int numOfEmp, FILE *empFile, struct empData database[]);
void printID(int numOfEmp, struct empData database[]);
void printAll(int numOfEmp, struct empData database[]);
void printDept(int numOfEmp, struct empData database[]);

int main(int argc, char *argv[]){
	
	typedef struct empData empData;
	
	empData db[1000];
	
	int userInput;
	
	int i;

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
	
	getRecs(numOfEmp, empFile, db);
	
	puts("");
	
	while ( userInput != -1) {
		
		
		puts("Welcome to the Employee Database!");
		puts("---------------------------------");
		puts("Choose an option:");
		puts("1:   Print Employee ID");
		puts("2:   Print ALL Employees");
		puts("3:   Show all employees in a department");
		puts("-1:  QUIT");
		puts("");
		
		printf("%s", "Option: ");
		
		scanf("%d", &userInput);
		
		puts("");
		
		if (userInput == 1) {
		
		printID(numOfEmp, db);
		
		}
		
		else if (userInput == 2) {
		
		printAll(numOfEmp, db);
				
		}
		else if (userInput == 3) {
			
		printDept(numOfEmp, db);
			
		}
		
		else if (userInput == 0) {
			
			printf("Please enter a valid number!\n");
			puts("");
			
		}
		else if (userInput < -1 || userInput > 3) {
			
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

void getRecs(int numOfEmp,FILE *empFile, struct empData database[]){
	
	int i;
	
	for(i = 0; i < numOfEmp; i++) {
	fscanf(empFile, "%d", &database[i].empNumber);
	fscanf(empFile, "%s", &database[i].firstName);
	fscanf(empFile, "%s", &database[i].lastName);
	fscanf(empFile, "%d", &database[i].empDept);
	fscanf(empFile, "%f", &database[i].empSalary);
	}
	
	
}

void printID(int numOfEmp, struct empData database[]){

	int id;
	
	int i;
	
	printf("%s", "Which employee ID to print? ");
	scanf("%d", &id);
	puts("");
			
		for(i = 0; i < numOfEmp; i++){
		
			if (id == database[i].empNumber) {
				
				printf("%11s %10d\n", "ID:", database[i].empNumber);
				printf("%11s %10s\n", "First Name:", database[i].firstName);
				printf("%11s %10s\n", "Last Name:", database[i].lastName);
				printf("%11s %10d\n", "Department:", database[i].empDept);
				printf("%11s %10.2f\n", "Salary:", database[i].empSalary);
				puts("");
				break;
			}
		}
		if (id != database[i].empNumber) {
		printf("Employee %d does not exist!", id);
		puts("");
		puts("");
		}

}


void printAll(int numOfEmp, struct empData database[]){
	
		int i;
	
		for(i = 0; i < numOfEmp; i++){
				
		printf("%11s %10d\n", "ID:", database[i].empNumber);
		printf("%11s %10s\n", "First Name:", database[i].firstName);
		printf("%11s %10s\n", "Last Name:", database[i].lastName);
		printf("%11s %10d\n", "Department:", database[i].empDept);
		printf("%11s %10.2f\n", "Salary:", database[i].empSalary);
		puts("");
				
		}
	
}

void printDept(int numOfEmp, struct empData database[]){
	
	int dept;
	
	int i;
	
	printf("%s", "Which employee Department to print? ");
	scanf("%d", &dept);
	puts("");
			
		for(i = 0; i < numOfEmp; i++){
		
			if (dept == database[i].empDept) {
				
				printf("%11s %10d\n", "ID:", database[i].empNumber);
				printf("%11s %10s\n", "First Name:", database[i].firstName);
				printf("%11s %10s\n", "Last Name:", database[i].lastName);
				printf("%11s %10d\n", "Department:", database[i].empDept);
				printf("%11s %10.2f\n", "Salary:", database[i].empSalary);
				puts("");
			
			}

		}
	
}