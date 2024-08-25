/*                Developed by : KIRO SAMEH               */
/*********************************************************/
//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//structures
struct student{
	char name[50];
	int id;
	int age;
	float gpa;
};

struct node{
	struct student *student ;
	struct node *next;
};

struct node *head = NULL;

//---------------------------------------------------------------------------------------------

//search for a student ,takes ID and return pointer to structure of type student
struct student* searchStudentByID(int new_id)
{
	struct node*current=head;
	struct student *stu=NULL;
	current=head;
	if(head==NULL){
		printf("the list is empty");
		return NULL;
	}
	while(current->student->id!=new_id)
	{
		current=current->next;
		if(current==NULL){
			break;
		}
	}
	if(current!=NULL){
		stu=current->student;
	}
	return stu;
}

//---------------------------------------------------------------------------------------------

//add a new student ,takes pointer to structure of type student
void add_Student(struct student *new_student){
	struct node *link =(struct node*)malloc(sizeof(struct node));
	struct node *current=head;
	link->student=new_student;
	link->next=NULL;
	if(head == NULL){
		head = link;
		printf("the student added successfully");
		return;
	}
	/*before the current go to the end to add new node if this node already
	exist it will not add and if it not exist it will continue*/
	if(searchStudentByID(new_student->id)!=NULL){
		printf("that student already exist");
		return;
	}
	while(current->next!=NULL){
		current=current->next;
	}
	current->next=link;
	printf("the student added successfully");
}

//---------------------------------------------------------------------------------------------

//Print all students data
void displayStudents(void){
	struct node*current=head;
	current=head;
	if(current==NULL){
		printf("\nthe list is empty ");
		return;
	}
	while(current !=NULL){
		printf("\nthe student name : ");
		printf("%s\n",current->student->name);
		printf("the student id : ");
		printf("%d\n",current->student->id);
		printf("the student age : ");
		printf("%d\n",current->student->age);
		printf("the student GPA : ");
		printf("%f\n",current->student->gpa);
		current=current->next;
		printf("\n");
	}
}

//---------------------------------------------------------------------------------------------

//Update the students data ,takes ID
void updateStudent(int id){
	struct student *s1=searchStudentByID(id);
	int temp_id=0;
	if(head==NULL){
		return ;
	}
	if(s1==NULL){
		printf("this student not found");
		return;
	}
	printf("enter the new student id :");
	scanf("%d",&temp_id);
	if(searchStudentByID(temp_id)!=NULL){
		printf("that id already exist");
		return;
	}
	s1->id=temp_id;
	printf("enter the new student name :");
	scanf("%s",s1->name);
	printf("enter the new student age :");
	scanf("%d",&s1->age);
	printf("enter the new student GPA :");
	scanf("%f",&s1->gpa);
	printf("the student is updated successfully");
}

//---------------------------------------------------------------------------------------------

//it Calculate the average GPA ,return average
float calculateAverageGPA(void){
	struct node*current=head;
	float sum=0;
	int count=0;
	float av=0.0;
	if(head==NULL){
		printf("the list is empty\n");
		return av;
	}
	while(current!=NULL){
		sum=sum+(current->student->gpa);
		count++;
		current=current->next;
	}
	av=sum/(float)count;
	return av;
}

//---------------------------------------------------------------------------------------------

//Search for the highest GPA
void searchHighestGPA(void){
	float max_gpa=0.0;
	struct student *max_student=NULL;
	struct node*current=head;
	if(head==NULL){
		printf("the list is empty\n");
		return ;
	}
	while(current!=NULL){
		if(current->student->gpa>max_gpa){
			max_gpa=current->student->gpa;
			max_student=current->student;
		}
		current=current->next;
	}
	printf("\nthe student that has max GPA:");
	printf("\nthe student name : ");
	printf("%s\n",max_student->name);
	printf("the student id : ");
	printf("%d\n",max_student->id);
	printf("the student age : ");
	printf("%d\n",max_student->age);
	printf("the student GPA : ");
	printf("%f\n",max_student->gpa);
}

//---------------------------------------------------------------------------------------------

// Delete Student data ,takes ID
void deleteStudent(int id){
	struct node *current = NULL;
	struct node *prev = NULL;
	struct node * del_node = NULL;
	if(head==NULL)
	{
		printf("Linked List is empty");
		return;
	}
	//if the node is in the first
	if(head->student->id == id)
	{
		del_node = head;
		head = head->next;
		free(del_node);
		return;
	}
	//if the node is in the middle
	current = head->next;
	prev = head;
	while(current != NULL)
	{
		if(current->student->id == id)
		{
			del_node = current;
			prev->next = current->next;
			free(del_node);
			return;
		}
		prev = current;
		current = current->next;
	}
	//if the id not found in the list
	if(del_node == NULL)
	{
		printf("not found in the List");
	}
}

//---------------------------------------------------------------------------------------------

//Print the Menu
void print_menu(void){
	printf("\n\t\t\t\tTHE MENU\n");
	printf("1. Add a student\t\t\t2. Display All Students\n");
	printf("3. Search for a Student by ID\t\t4. Update Student Information\n");
	printf("5. Delete a Student\t\t\t6. Calculate Average GPA\n");
	printf("7. Find Student with Highest GPA\t8. Exit\n");
	printf ("\nchoose a number from the menu :");
}

//---------------------------------------------------------------------------------------------

//Main
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	int Menu_Option;
	while(1){
		print_menu();
		scanf("%d",&Menu_Option);
		while(Menu_Option>8 || Menu_Option<1){
			printf("\nerror!\n");
			print_menu();
			scanf("%d",&Menu_Option);
		}
		if(Menu_Option==8){
			break;
		}
		else{
			switch(Menu_Option){
			case 1:
				struct student *s1 = (struct student*)malloc(sizeof(struct student));
				printf("enter the student name :");
				scanf("%s",s1->name);
				printf("enter the student id :");
				scanf("%d",&s1->id);
				printf("enter the student age :");
				scanf("%d",&s1->age);
				printf("enter the student GPA :");
				scanf("%f",&s1->gpa);
				add_Student(s1);
				break;
			case 2:
				displayStudents();
				break;
			case 3:
				int id;
				printf("enter the student id :");
				scanf("%d",&id);
				struct student*temp_stu = searchStudentByID(id);
				if(temp_stu==NULL){
					printf("this student not exist");
				}
				else{
					printf("\nthis student exist\n");
					printf("\nthe student name : ");
					printf("%s\n",temp_stu->name);
					printf("the student id : ");
					printf("%d\n",temp_stu->id);
					printf("the student age : ");
					printf("%d\n",temp_stu->age);
					printf("the student GPA : ");
					printf("%f\n",temp_stu->gpa);
				}
				break;
			case 4:
				int old_id;
				printf("enter the student id :");
				scanf("%d",&old_id);
				updateStudent(old_id);
				break;
			case 5:
				int del_id;
				printf("enter the student id :");
				scanf("%d",&del_id);
				deleteStudent(del_id);
				break;
			case 6:
				printf("the average is : %f",calculateAverageGPA());
				break;
			case 7:
				searchHighestGPA();
				break;
			}
		}
	}
	printf("program ended");
	return 0;
}
//the end
