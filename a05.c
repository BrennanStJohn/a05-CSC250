#include <stdio.h>

struct empData {
	
	char firstName;
	char lastName;
	int empNumber;
	int empDept;
	int empSalary;
	
};

int main(argc, argv[]){
	
	struct empData;
	int userInput;

	if (argc != 2) {
		
		printf("\n\tUsage: '%s filename'\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	FILE *empFile;
	
	empFile = fopen(argv[1], "r");
	
	int numOfEmp;
	
	fscanf(empFile, "%d", &numOfEmp);
	
	while ( userInput != 0) {
		
		puts("Welcome to the Employee Database!");
		puts("---------------------------------");
		puts("Choose an option:");
		puts("1:   Print Employee ID");
		puts("2:   Print ALL Employees");
		puts("3:   Show all employees in a department");
		puts("-1:  QUIT");
		
		scanf("%d", &userInput);
		
		
		
		
		
		
		
		
	}

}