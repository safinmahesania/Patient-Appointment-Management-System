#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct patient
{
 int id;
 char name[30];
 char disease[30];
 int age;
}p;
struct doctors
{
    int id;
    char name[20];
    char speciality[20];
    int fpv;
}d;
struct appointment
{
    int id;
    char pname[20];
    char dname[20];
    int time;
    char date[30];
}a;

void print_intro()
{
    printf("\n\t\t\tPatient Appointment Management System\n\n");
    printf("Course: Fundamental Of Programming\n");
    printf("Course Instructor: Adeel Ahmed\n");
    printf("Group Members:\n");
    printf("1. Safin Noordin Mahesania 1912282\n2. Moin Amir Dauva 1912355\n3. Nabil Nooruddin Kadiwal 1912277\n");
    printf("Press any key to continue");
    getch();
    system("cls");
}

void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void loader()
{
    printf("\n\t\t\t\tWelcome to Shaheed Zulfiqar Ali Bhutto Hospital\n");
    int i;
	gotoxy(45,10);
	printf("Please Wait Loading System...");
	gotoxy(19,12);
	for (i=0;i<78;i++)
	{
		Sleep(15);
		printf("%c",219);
	}
	gotoxy(45,14);
	printf("System Loaded Successfully");
	gotoxy(45,18);
	printf("Press Any Key To Continue");
	getch();
	system("cls");
}

void print_menu()
{
    printf("\n\t\t\t\t\tShaheed Zulfiqar Ali Bhutto Hospital\n");
    printf("\nPlease select the Option\n");
    printf("1. Patients\n2. Doctors\n3. Appointments\n4. Exit\n");
}

int menu_choice()
{
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice<1||choice>4)
    {
        printf("Invalid Choice ");
    }
    return choice;
}

void print_inner_menu()
{
    printf("\n\n1. View\n2. Insert\n3. Update\n4. Search\n5. Delete\n6. Back\n");
}

int inner_menu_choice()
{
    int choice;
    scanf("%d",&choice);
    if(choice<1||choice>6)
    {
        printf("Invalid Choice ");
        inner_menu_choice();
    }
    return choice;
}

void view(int menuchoice)
{
	if(menuchoice==1)
	{
	 	FILE *pat;
	 	pat = fopen("Patient.txt", "r");
	 	printf("\nID\tName\tDisease\tAge\n\n");
	 	while (!feof(pat))
	 	{
	    	fscanf(pat,"%d%s%s%d",&p.id,p.name,p.disease,&p.age);
	    	printf("%d\t%s\t%s\t%d\n",p.id,p.name,p.disease,p.age);
	 	}
	 	fclose(pat);
	}
	if(menuchoice==2)
	{
	 	FILE *doc;
        doc = fopen("Doctor.txt", "r");
	 	printf("\nID\tName\tSpeciality\tFees Per Visit\n\n");
	 	while (!feof(doc))
	 	{
	    	fscanf(doc,"%d%s%s%d",&d.id,d.name,d.speciality,&d.fpv);
	    	printf("%d\t%s\t%s\t%d\n",d.id,d.name,d.speciality,d.fpv);
	 	}
	 	fclose(doc);
	}
	if(menuchoice==3)
	{
	 	FILE *app;
        app = fopen("Appointment.txt", "r");
	 	printf("\nID\tPatient Name\tDoctor Name\tDate\tTime\n\n");
	 	while (!feof(app))
	 	{
	    	fscanf(app,"%d%s%s%s%d",&a.id,a.pname,a.dname,a.date,&a.time);
	    	printf("%d\t%s\t%s\t%s\t%d\n",a.id,a.pname,a.dname,a.date,a.time);
	 	}
	 	fclose(app);
	}
}

void insert(int menuchoice)
{
	if(menuchoice==1)
	{
		FILE *pat;
		pat = fopen("Patient.txt", "a");
		printf("Enter the ID: ");
		fflush(stdin);
		scanf("%d",&p.id);
		printf("Enter the Name: ");
		fflush(stdin);
		gets(p.name);
		printf("Enter the disease: ");
		fflush(stdin);
		gets(p.disease);
		printf("Enter the age: ");
		fflush(stdin);
		scanf("%d",&p.age);
		fprintf(pat,"\n%d\t\t%s\t\t%s\t\t%d",p.id,p.name,p.disease,p.age);
		fclose(pat);
	}
	if(menuchoice==2)
	{
		FILE *doc;
		doc = fopen("Doctor.txt", "a");
		printf("Enter the ID: ");
		fflush(stdin);
		scanf("%d",&d.id);
		printf("Enter the Name: ");
		fflush(stdin);
		gets(d.name);
		printf("Enter the Speciality: ");
		fflush(stdin);
		gets(d.speciality);
		printf("Enter the Fees Per Visit: ");
		fflush(stdin);
		scanf("%d",&d.fpv);
		fprintf(doc,"\n%d\t\t%s\t\t%s\t\t%d",d.id,d.name,d.speciality,d.fpv);
		fclose(doc);
	}
	if(menuchoice==3)
	{
		FILE *app,*pat,*doc;
        app = fopen("Appointment.txt", "a");
		printf("Enter the ID: ");
		fflush(stdin);
		scanf("%d",&a.id);
		printf("Enter the Patient Id: ");
		int id,pid,did,avl;
		scanf("%d",&id);
		avl = avlid(id);
	 	if (avl == 0)
	  	printf("ID %d is not available in the file\n",id);
	 	else
	 	{
	  		pat = fopen("Patient.txt", "r");
	  		while (!feof(pat))  //fread(&p, sizeof(p), 1, pat)
	  		{
	    		fscanf(pat,"%d%s%s%d",&p.id,p.name,p.disease,&p.age);
	   			pid = p.id;
	   			if (pid == id)
			   	{
			    	strcpy(a.pname,p.name);
			   	}
	  		}
	  		fclose(pat);
	 	}
		printf("Enter the Doctor Doctor Id: ");
		scanf("%d",&id);
        avl = avlid(id);
	 	if (avl == 0)
	  	printf("ID %d is not available in the file\n",id);
	 	else
	 	{
	  		doc = fopen("Doctor.txt", "r");
	  		while (!feof(doc))
	  		{
	    		fscanf(doc,"%d%s%s%d",&d.id,d.name,d.speciality,&d.fpv);
	   			did = d.id;
	   			if (did == id)
			   	{
			    	strcpy(a.dname,d.name);
			   	}
	  		}
	  		fclose(doc);
	 	}
		printf("Enter Date: ");
		fflush(stdin);
		gets(a.date);
		printf("Enter Time: ");
		fflush(stdin);
		scanf("%d",&a.time);
		fprintf(app,"\n%d\t\t%s\t\t%s\t\t%s\t\t%d",a.id,a.pname,a.dname,a.date,a.time);
		fclose(app);
	}
}

void search(int menuchoice)
{
	if(menuchoice==1)
	{
	 	FILE *pat;
	 	int id, pid, avl;
	 	printf("\nEnter the ID you want to search  :");
	 	scanf("%d", &id);
	 	avl = avlid(id);
	 	if (avl == 0)
	  	printf("ID %d is not available in the file\n",id);
	 	else
	 	{
	  		pat = fopen("Patient.txt", "r");
	  		while (!feof(pat))  //fread(&p, sizeof(p), 1, pat)
	  		{
	    		fscanf(pat,"%d%s%s%d",&p.id,p.name,p.disease,&p.age);
	   			pid = p.id;
	   			if (pid == id)
			   	{
			    	printf("\nID: %d",p.id);
			    	printf("\nName: %s",p.name);
			    	printf("\nDisease: %s",p.disease);
			    	printf("\nAge: %d",p.age);
			   	}
	  		}
	  		fclose(pat);
	 	}
	}
	if(menuchoice==2)
	{
	 	FILE *doc;
	 	int id, did, avl;
	 	printf("\nEnter the ID you want to search  :");
	 	scanf("%d", &id);
	 	avl = avlid(id);
	 	if (avl == 0)
	  	printf("ID %d is not available in the file\n",id);
	 	else
	 	{
	  		doc = fopen("Doctor.txt", "r");
	  		while (!feof(doc))
	  		{
	    		fscanf(doc,"%d%s%s%d",&d.id,d.name,d.speciality,&d.fpv);
	   			did = d.id;
	   			if (did == id)
			   	{
			    	printf("\nID: %d",d.id);
			    	printf("\nName: %s",d.name);
			    	printf("\nSpeciality: %s",d.speciality);
			    	printf("\nFees Per Visit: %d",d.fpv);
			   	}
	  		}
	  		fclose(doc);
	 	}
	}
	if(menuchoice==3)
	{
	 	FILE *app;
	 	int id, aid, avl;
	 	printf("\nEnter the ID you want to search  :");
	 	scanf("%d", &id);
	 	avl = avlid(id);
	 	if (avl == 0)
	  	printf("ID %d is not available in the file\n",id);
	 	else
	 	{
            app = fopen("Appointment.txt", "r");
	  		while (!feof(app))
	  		{
	    		fscanf(app,"%d%s%s%s%d",&a.id,a.pname,a.dname,a.date,&a.time);
	   			//aid = a.id;
	   			if (a.id == id)
			   	{
			    	printf("\nID: %d",a.id);
			    	printf("\nPatient Name: %s",a.pname);
			    	printf("\nDoctor Name: %s",a.dname);
			    	printf("\nDate: %s",a.date);
			    	printf("\nTime: %d",a.time);
			   	}
	  		}
	  		fclose(app);
	 	}
	}
}

void deletefile(int menuchoice)
{
	if(menuchoice==1)
	{
	 	FILE *pat;
	 	FILE *pat1;
	 	int id, pid;
	 	printf("Enter the ID you want to delete:");
	 	scanf("%d", &id);
	 	if (avlid(id) == 0)
	  	printf("ID %d is not available in the file\n", id);
	 	else
	 	{
	  		pat = fopen("Patient.txt", "r");
	  		pat1 = fopen("Patient1.txt", "w");
	  		while (!feof(pat))
	  		{
	    		fscanf(pat,"%d%s%s%d",&p.id,p.name,p.disease,&p.age);
	   			pid = p.id;
	   			if (pid != id)
	    		fprintf(pat1,"\n%d\t%s\t%s\t%d",p.id,p.name,p.disease,p.age);
	  		}
	  		fclose(pat);
	  		fclose(pat1);
	        remove("Patient.txt");
			rename("Patient1.txt","Patient.txt");
	    	printf("**Record Deleted**");
	 	}
	}
	if(menuchoice==2)
	{
	 	FILE *doc;
	 	FILE *doc1;
	 	int id, did;
	 	printf("Enter the ID you want to delete:");
	 	scanf("%d", &id);
	 	if (avlid(id) == 0)
	  	printf("ID %d is not available in the file\n", id);
	 	else
	 	{
	  		doc = fopen("Doctor.txt", "r");
	  		doc1 = fopen("Doctor1.txt", "w");
	  		while (!feof(doc))
	  		{
	    		fscanf(doc,"%d%s%s%d",&d.id,d.name,d.speciality,&d.fpv);
	   			did = d.id;
	   			if (did != id)
	    		fprintf(doc1,"\n%d\t%s\t%s\t%d\n",d.id,d.name,d.speciality,d.fpv);
	  		}
	  		fclose(doc);
	  		fclose(doc1);
	        remove("Doctor.txt");
			rename("Doctor1.txt","Doctor.txt");
	    	printf("**Record Deleted**");
	 	}
	}
	if(menuchoice==3)
	{
	 	FILE *app;
	 	FILE *app1;
	 	int id, aid;
	 	printf("Enter the ID you want to delete:");
	 	scanf("%d", &id);
	 	if (avlid(id) == 0)
	  	printf("ID %d is not available in the file\n", id);
	 	else
	 	{
	  		app = fopen("Appointment.txt", "r");
	  		app1 = fopen("Appointment1.txt", "w");
	  		while (!feof(app))
	  		{
	    		fscanf(app,"%d%s%s%s%d",&a.id,a.pname,a.dname,a.date,&a.time);
	   			aid = a.id;
	   			if (aid != id)
	    		fprintf(app1,"\n%d\t%s\t%s\t%s\t%d\n",a.id,a.pname,a.dname,a.date,a.time);
	  		}
	  		fclose(app);
	  		fclose(app1);
	        remove("Appointment.txt");
			rename("Appointment1.txt","Appointment.txt");
	    	printf("**Record Deleted**");
	 	}
	}
}

void update(int menuchoice)
{
	if(menuchoice==1)
	{
		int avl;
	 	FILE *pat1;
		FILE *pat;
		int pid, id, ch;
		printf("Enter ID to update:");
		scanf("%d", &id);
		avl = avlid(id);
		if (avl == 0)
		{
			printf("ID %d is not Available in the file", id);
		}
		else
		{
			pat = fopen("Patient.txt", "r");
		  	pat1 = fopen("Patient1.txt", "w");
		  	while (!feof(pat))
		  	{
			    	fscanf(pat,"%d%s%s%d",&p.id,p.name,p.disease,&p.age);
			//   		pid = p.id;
			   		if (p.id != id)
			    	fprintf(pat1,"\n%d\t%s\t%s\t%d",p.id,p.name,p.disease,p.age);
			   	else
				{
				    printf("\n\t1. Update Name of ID %d", id);
				    printf("\n\t2. Update Age of ID %d", id);
				    printf("\n\t3. Update both Name and Age of ID %d", id);
				    printf("\nEnter your choice:");
				    scanf("%d", &ch);
				    switch (ch)
				    {
					    case 1:
					    printf("Enter Name:");
					    fflush(stdin);
					    gets(p.name);
					    break;
					    case 2:
					    printf("Enter Age: ");
					    fflush(stdin);
					    scanf("%d", &p.age);
					    break;
					    case 3:
					    printf("Enter Name: ");
					    fflush(stdin);
					    gets(p.name);
					    printf("Enter Age: ");
					    fflush(stdin);
					    scanf("%d", &p.age);
					    break;
					    default:
					    printf("Invalid Selection");
					    break;
			    	}
			    fprintf(pat1,"\n%d\t%s\t%s\%d",p.id,p.name,p.disease,p.age);
			   	}
		  	}
		  	fclose(pat);
		  	fclose(pat1);
		  	remove("Patient.txt");
		    rename("Patient1.txt","Patient.txt");
		  	printf("RECORD UPDATED");
		}
	}
	if(menuchoice==2)
	{
		int avl;
	 	FILE *doc1;
		FILE *doc;
		int did, id, ch;
		printf("Enter ID to update:");
		scanf("%d", &id);
		avl = avlid(id);
		if (avl == 0)
		{
			printf("ID %d is not Available in the file", id);
		}
		else
		{
			doc = fopen("Doctor.txt", "r");
		  	doc1 = fopen("Doctor1.txt", "w");
		  	while (!feof(doc))
		  	{
			    	fscanf(doc,"%d%s%s%d",&d.id,d.name,d.speciality,&d.fpv);
			   		did = d.id;
			   		if (did != id)
			    	fprintf(doc1,"\n%d\t%s\t%s\t%d",d.id,d.name,d.speciality,d.fpv);
			   	else
				{
				    printf("\n\t1. Update Name of ID %d", id);
				    printf("\n\t2. Update Fees Per Visit ");
				    printf("\n\t3. Update both Name and Fees Per Visit of ID %d", id);
				    printf("\nEnter your choice:");
				    scanf("%d", &ch);
				    switch (ch)
				    {
					    case 1:
					    printf("Enter Name:");
					    fflush(stdin);
					    gets(d.name);
					    break;
					    case 2:
					    printf("Enter Fees Per Visit: ");
					    fflush(stdin);
					    scanf("%d", &d.fpv);
					    break;
					    case 3:
					    printf("Enter Name: ");
					    fflush(stdin);
					    gets(d.name);
					    printf("Enter Fees per Visit: ");
					    fflush(stdin);
					    scanf("%d", &d.fpv);
					    break;
					    default:
					    printf("Invalid Selection");
					    break;
			    	}
			    fprintf(doc1,"\n%d\t%s\t%s\%d",d.id,d.name,d.speciality,d.fpv);
			   	}
		  	}
		  	fclose(doc);
		  	fclose(doc1);
		  	remove("Doctor.txt");
		    rename("Doctor1.txt","Doctor.txt");
		  	printf("RECORD UPDATED");
		}
	}
	if(menuchoice==3)
	{
		int avl;
	 	FILE *app1;
		FILE *app;
		int aid, id, ch;
		printf("Enter ID to update:");
		scanf("%d", &id);
		avl = avlid(id);
		if (avl == 0)
		{
			printf("ID %d is not Available in the file", id);
		}
		else
		{
			app = fopen("Appointment.txt", "r");
		  	app1 = fopen("Appointment1.txt", "w");
		  	while (!feof(app))
		  	{
			    	fscanf(app,"%d%s%s%s%d",&a.id,a.pname,a.dname,a.date,&a.time);
			   		//aid = a.id;
			   		if (a.id != id)
			    	fprintf(app1,"\n%d\t%s\t%s\t%s\t%d",a.id,a.pname,a.dname,a.date,a.time);
			   	else
				{
				    printf("\n\t1. Update Name of ID %d", id);
				    printf("\n\t2. Update Time ");
				    printf("\n\t3. Update both Name and Time of ID %d", id);
				    printf("\nEnter your choice:");
				    scanf("%d", &ch);
				    switch (ch)
				    {
					    case 1:
					    printf("Enter Name:");
					    fflush(stdin);
					    gets(a.pname);
					    break;
					    case 2:
					    printf("Enter Time: ");
					    fflush(stdin);
					    scanf("%d", &a.time);
					    break;
					    case 3:
					    printf("Enter Name: ");
					    fflush(stdin);
					    gets(a.pname);
					    printf("Enter Time: ");
					    fflush(stdin);
					    scanf("%d", &a.time);
					    break;
					    default:
					    printf("Invalid Selection");
					    break;
			    	}
			    fprintf(app1,"\n%d\t%s\t%s\t%s\%d",a.id,a.pname,a.dname,a.date,a.time);
			   	}
		  	}
		  	fclose(app);
		  	fclose(app1);
		  	remove("Appointment.txt");
		    rename("Appointment1.txt","Appointment.txt");
		  	printf("RECORD UPDATED");
		}
	}
}

int avlid(int idno,int menuchoice)
{
 	if(menuchoice==1)
    {
        FILE *pat;
        int c = 0;
        pat = fopen("Patient.txt", "r");
        while (!feof(pat))
        {
            fscanf(pat,"%d%s%s%d",&p.id,p.name,p.disease,&p.age);
            if (idno == p.id)
            {
                fclose(pat);
                return 1;
            }
        }
        fclose(pat);
        return 0;
    }
    if(menuchoice==2)
    {
        FILE *doc;
        int c = 0;
        doc = fopen("Doctor.txt", "r");
        while (!feof(doc))
        {
            fscanf(doc,"%d%s%s%d",&d.id,d.name,d.speciality,&d.fpv);
            if (idno == d.id)
            {
                fclose(doc);
                return 1;
            }
        }
        fclose(doc);
        return 0;
    }
    if(menuchoice==3)
    {
        FILE *app;
        int c = 0;
        app = fopen("Appointment.txt", "r");
        while (!feof(app))
        {
            fscanf(app,"%d%s%s%s%d",&a.id,a.pname,a.dname,a.date,&a.time);
            if (idno == a.id)
            {
                fclose(app);
                return 1;
            }
        }
        fclose(app);
        return 0;
    }
}

void inner_execute(int menuchoice)
{
    system("cls");
    int innermenuchoice;
    print_inner_menu();
    innermenuchoice=inner_menu_choice();
    if(innermenuchoice==1)
    {
        system("cls");
        view(menuchoice);
        printf("\n\nPress Any Key To Continue");
        getch();
        inner_execute(menuchoice);
    }
    else if(innermenuchoice==2)
    {
        system("cls");
        insert(menuchoice);
        printf("\n\nPress Any Key To Continue");
        getch();
        inner_execute(menuchoice);
    }
    else if(innermenuchoice==3)
    {
        system("cls");
        update(menuchoice);
        printf("\n\nPress Any Key To Continue");
        getch();
        inner_execute(menuchoice);
    }
    else if(innermenuchoice==4)
    {
        system("cls");
        search(menuchoice);
        printf("\n\nPress Any Key To Continue");
        getch();
        inner_execute(menuchoice);
    }
    else if(innermenuchoice==5)
    {
        system("cls");
        deletefile(menuchoice);
        printf("\n\nPress Any Key To Continue");
        getch();
        inner_execute(menuchoice);
    }
    else if(innermenuchoice==6)
    {
        system("cls");
        execute();
    }
}

void execute()
{
    int menuchoice;
    do
    {
        print_menu();
        printf("Enter a corresponding number of your choice: ");
        menuchoice=menu_choice();
        if(menuchoice==1||menuchoice==2||menuchoice==3)
        {
            //system("cls");
            inner_execute(menuchoice);
        }
        else if(menuchoice==4)
        {
            exit(0);
        }
    }while(menuchoice!=5);
}

void printintro()
{
    print_intro();
    loader();
}

int main()
{
    printintro();
    execute();
}
