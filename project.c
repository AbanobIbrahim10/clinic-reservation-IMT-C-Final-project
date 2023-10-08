#include <stdio.h>
#include <stdlib.h>
typedef struct Node PatientInfo;
struct Node
{
	short int id;
	short int age;
	char gender[10];
	char name[10];
	PatientInfo *link;
};
PatientInfo *CreatFirstNode(void);
void CreatNodeInBack(PatientInfo *np);
void EDIT(int id, PatientInfo *ptr);
void SHOW(int id, PatientInfo *ptr, char a);
int check_id(int id, PatientInfo *ptr, char a);
int main()
{
	int x;
	int pass;
	int pp;
	int check = 0;
	int action;
	PatientInfo *start = NULL;
	char FirstPatient = 1;
	int GPV;
	char a = 1, b = 1, c = 1, d = 1, e = 1, l;
	int arr[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int count = 0, counter = 0;
	printf("		->WELCOME DEAR<-\n->please enter (1) for admin mode  OR (2) for user mode \n");
	scanf("%d", &x);
	switch (x)
	{
	case 1: // admin mode
		printf("please enter the password:");
		for (int i = 3; i > 0; i--)
		{
			scanf("%d", &pass);
			if (pass == 1234)
			{

				while (1)
				{

					printf("\nwelcome sir \nwhat are you want to do \n1-Add new patient record\n2-Edit patient record\n3-Reserve a slot with the doctor\n4-Cancel reservation\n5-Exit\n");
					scanf("%d", &action);
					if (action == 1)
					{
						if (FirstPatient)
						{
							start = CreatFirstNode();
							FirstPatient = 0;
						}
						else
						{
							CreatNodeInBack(start);
						}
					}
					else if (action == 2)
					{
						if (FirstPatient)
						{
							printf("->you didn't add any patient");
							printf("\n->you must add at least one patient first\n");
						}
						else
						{
							printf("\nplease enter patient ID : ");
							scanf("%d", &GPV);
							EDIT(GPV, start);
						}
					}
					else if (action == 3)
					{
						if ((a == 1 || b == 1 || c == 1 || d == 1 || e == 1))
						{

							printf("the available slots are : \n");
							if (a)
							{
								printf("1- 2 pm to 2:30 pm\n");
							}
							if (b)
							{
								printf("2- 2:30 pm to 3 pm\n");
							}
							if (c)
							{
								printf("3- 3 pm to 3:30 pm\n");
							}
							if (d)
							{
								printf("4- 4 pm to 4:30 pm\n");
							}
							if (e)
							{
								printf("5- 4:30 pm to 5 pm\n");
							}

							if (counter == 10)
							{
								printf("please enter patient ID : ");
								scanf("%d", &arr[10]);
								pp = check_id(arr[10], start, FirstPatient);

								if (pp)
								{

									printf("please enter the desired slot :");
									scanf("%d", &arr[11]);
									for (count = 0; count < 10; count += 2)
									{
										if (arr[count] == arr[11])
										{
											arr[count - 1] = arr[10];
										}
									}
								}

								else
								{
									arr[10] = 0;
								}
							}
							else
							{

								printf("please enter patient ID : ");
								scanf("%d", &arr[counter]);

								pp = check_id(arr[counter], start, FirstPatient);

								if (pp)
								{
									printf("please enter the desired slot :");
									scanf("%d", &arr[counter + 1]);
								}
								else
								{
									arr[counter] = 0;
								}
							}
							if (pp)
							{
								switch (arr[counter + 1])
								{
								case 1:
									a = 0;
									break;
								case 2:
									b = 0;
									break;
								case 3:
									c = 0;
									break;
								case 4:
									d = 0;
									break;
								case 5:
									e = 0;
									break;
								}

								counter += 2;
								if (counter == 12)
									counter -= 2;
							}
							else
							{
								printf("\nthere is no ID match your input please try aagain ");
							}
						}
					}
					else if (action == 4)
					{
						printf("please enter the id : ");
						scanf("%d", &l);
						for (count = 0; count < 10; count += 2)
						{
							if (arr[count] == l)
							{
								break;
							}
						}

						switch (arr[count + 1])
						{
						case 1:
							a = 1;
							break;
						case 2:
							b = 1;
							break;
						case 3:
							c = 1;
							break;
						case 4:
							d = 1;
							break;
						case 5:
							e = 1;
							break;
						}
						if (a)
						{
							printf("1- 2 pm to 2:30 pm\n");
						}
						if (b)
						{
							printf("2- 2:30 pm to 3 pm\n");
						}
						if (c)
						{
							printf("3- 3 pm to 3:30 pm\n");
						}
						if (d)
						{
							printf("4- 4 pm to 4:30 pm\n");
						}
						if (e)
						{
							printf("5- 4:30 pm to 5 pm\n");
						}
					}
					else if (action == 5)
					{
						i = 0;
						break;
					}
					else
					{
						printf("wrong choice please enter number from 1 to 5 ");
					}
				}
			}
			else
			{
				check++;
				if (check == 3)
					continue;
				printf("please try again ");
			}
		}

	case 2:
		if (x == 1)
		{
			printf("do you need to access user mode if yes enter (2)");
			scanf("%d", &x);
		}
		while (1)
		{
			if (x == 2)
			{
				printf("\nto show your information please enter (1)\nto show reservation table enter (2)\nto exit enter (3)");
				scanf("%d", &GPV);
				if (GPV == 1)
				{
					printf("please enter you ID : ");
					scanf("%d", &GPV);

					SHOW(GPV, start, FirstPatient);
				}
				else if (GPV == 2)
				{

					printf("1- 2 pm to 2:30 pm\n");
					printf("2- 2:30 pm to 3 pm\n");
					printf("3- 3 pm to 3:30 pm\n");
					printf("4- 4 pm to 4:30 pm\n");
					printf("5- 4:30 pm to 5 pm\n\n");
					printf("NOTE: if there is a repeated id the least one is the true\n");

						for (int o = 0; o < 10; o += 2)
					{
						printf("id : %d -->> reserve (%d) \n", arr[o], arr[o + 1]);
					}
				}
				else
				{
					break;
				}
			}

			else
			{
				break;
			}
		}
		break;
	default:
		printf("not allowed");
	}

	if (check == 3)
	{
		printf("you are not the admin");
	}

	// PatientInfo* start= CreatFirstNode();

	return 0;
}

PatientInfo *CreatFirstNode(void)
{
	PatientInfo *p = (PatientInfo *)malloc(sizeof(PatientInfo));
	if (p != NULL)
	{
		p->link = NULL;
		printf("enter patient name : ");
		scanf("%s", &(p->name));
		printf("enter patient ID : ");
		scanf("%d", &(p->id));
		printf("enter patient age : ");
		scanf("%d", &(p->age));
		printf("enter the gender : ");
		scanf("%s", &(p->gender));

		return p;
	}
	else
	{
		printf("memory is full ");
		return NULL;
	}
}
void CreatNodeInBack(PatientInfo *np)
{
	PatientInfo *st = np;
	PatientInfo *sts = np;
	int id;
	while (np->link != NULL)
	{
		np = np->link;
	}
	PatientInfo *ptr1 = (PatientInfo *)malloc(sizeof(PatientInfo));
	if (ptr1 != NULL)
	{

		np->link = ptr1;
		ptr1->link = NULL;
		printf("enter patient name : ");
		scanf("%s", &(ptr1->name));
		printf("enter patient ID : ");
		scanf("%d", &(id));
		while (1)
		{
			st = sts;
			while (st->id != id && st->link != NULL)
			{ // to check that it is unique id
				st = st->link;
			}
			if (st->id == id)
			{
				printf("the ID is already exisit try another ID : ");
				scanf("%d", &id);
			}
			else
			{
				ptr1->id = id;
				break;
			}
		}
		printf("enter patient age : ");
		scanf("%d", &(ptr1->age));
		printf("enter the gender : ");
		scanf("%s", &(ptr1->gender));
	}
	else
	{
		printf("memory is full ");
	}
}

PatientInfo *FreeNode(short int id, PatientInfo *ptr)
{
	if (ptr->id == id)
	{
		PatientInfo *Nstrart = ptr->link;
		free(ptr);
		return Nstrart; // return the new start
	}
	else
	{
		while (ptr->link->id != id && ptr->link->link != NULL)
		{
			ptr = ptr->link;
		}
		if (ptr->link->id == id)
		{
			ptr->link = ptr->link->link;
			free(ptr->link);
		}
		else
		{
			printf("it is invalid id ");
		}
		return ptr; // address of node which previous deleted one
	}
}

void EDIT(int id, PatientInfo *ptr)
{
	while (ptr->id != id && ptr->link != NULL)
	{ // to check that it is unique id
		ptr = ptr->link;
	}
	if (ptr->id == id)
	{
		printf("patient ID : %d\npatient name : %s\npatient age : %d\npatient gender : %s\nkindly you can update this data by entering patient new information\n", ptr->id, ptr->name, ptr->age, ptr->gender);
		printf("enter patient name : ");
		scanf("%s", &(ptr->name));
		printf("enter patient age : ");
		scanf("%d", &(ptr->age));
		printf("enter the gender : ");
		scanf("%s", &(ptr->gender));
	}
	else
	{
		printf("Incorrect Id ");
	}
}

void SHOW(int id, PatientInfo *ptr, char a)
{
	if (a == 0)
	{
		while (ptr->id != id && ptr->link != NULL)
		{ // to check that it is unique id
			ptr = ptr->link;
		}
		if (ptr->id == id)
		{
			printf("patient ID : %d\npatient name : %s\npatient age : %d\npatient gender : %s\n", ptr->id, ptr->name, ptr->age, ptr->gender);
		}
		else
		{
			printf("Incorrect Id ");
		}
	}

	else
	{
		printf("\nyou must record at least one patient first\n");
	}
}

int check_id(int id, PatientInfo *ptr, char a)
{

	if (a == 0)
	{
		while (ptr->id != id && ptr->link != NULL)
		{ // to check that it is unique id
			ptr = ptr->link;
		}
		if (ptr->id == id)
		{
			// printf("patient ID : %d\npatient name : %s\npatient age : %d\npatient gender : %s\nkindly you can update this data by entering patient new information\n",ptr->id,ptr->name,ptr->age,ptr->gender);
			return 1;
		}
		else
		{
			printf("Incorrect Id ");
			return 0;
		}
	}
	else
	{
		printf("\nyou must record at least one patient first\n");
	}
}
