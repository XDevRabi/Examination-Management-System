#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"pwdcheck.h"
#include"create_result.h"
struct stu_info{
	char name[30],add[40],stu_id[15],stu_contact[15],dob[11],par_name[30],par_num[15],year[5];
};

// list of functions.
int admin();
int staff();
int student();
void add_stu();
void search_stu();
void enter_result();
void view_result();
void mod_stu();
void heading();
void fullaccess();

void heading(){
	printf("===================================================================================\n");
	printf("				   SchEMS\n");
	printf("			Examination Management System\n");
	printf("			       Pokhara University\n");
	printf("===================================================================================\n");
	return;
}

int main(){
	int user_type, rtnval_admin, rtnval_stu, rtnval_staff, rtnval_pwdcheck;
	login_again:
	system("cls");
	heading();
	printf("\n**********************************LOGIN PANEL**************************************\n\n");
	printf("  :::Choose the user type (1,2 or 3):::\n\n  1. Admin\n\n  2. Teacher\n\n  3. Student\n\n  4. Exit Program\n\n\n  Answer : ");
 	scanf("%d",&user_type);
 	system("cls");
 	heading();
 	rtnval_pwdcheck= pwdchecker(user_type);		// checking password by calling pwdchecking function.
 	//		after checking pwd, give access to the user to specific user_type.
 	if(rtnval_pwdcheck==1){
 		rtnval_admin=admin();	// give access to admin's function to the user
	 }
	else if(rtnval_pwdcheck==2){
	 	rtnval_staff= staff();	// give access to teacher's function to the user
	 }
	else if(rtnval_pwdcheck==3){
	 	rtnval_stu= student();		// give access to student's function to the user
	 }
	else if(rtnval_pwdcheck==4){
	 	exit(0);				// to exit program
	 }
	else{
	 	goto login_again;
	 }
	 printf("\n\n");
	goto login_again;
	 return 0;
}


int admin(){
	int program;
	choose_again:
	system("cls");
	heading();
	printf("\n\n  	::::Menu::::\n\n  1. Add Student\n\n  2. Modify Student Record\n\n  3. Search Student\n\n  4. Create Marksheet\n\n  5. View Marksheet\n\n  6. View All Student Marksheet\n\n  7. LOG OUT\n\n\n  Answer : ");
	scanf("%d",&program);
		switch (program){
		case 1:
			add_stu();
			break;
		case 2:
			mod_stu();
			break;
		case 3:
			search_stu();
			break;
		case 4:
			enter_result();
			break;
		case 5:
			view_result();
			break;
		case 6:
			fullaccess();
			break;
		case 7:
			return 0;
			break;
		default:
			printf("	Invalid Option!!!\n\n");
	}
	goto choose_again;
}

int staff(){
	int program;
	choose_again:
	system("cls");
	heading();
	printf("\n\n	::::Menu::::\n\n  1. Search Student\n\n  2. Create Marksheet\n\n  3. View Marksheet\n\n  4. View All Student Marksheet\n\n  5. LOG OUT\n\n\n  Answer : ");
	scanf("%d",&program);
		switch (program){
		case 1:
			search_stu();
			break;
		case 2:
			enter_result();
			break;
		case 3:
			view_result();
			break;
		case 4:
			fullaccess();
			break;
		case 5:
			return 0;
			break;
		default:
			printf("	Invalid Option!!!\n\n");
	}
	goto choose_again;
}

int student(){
	int program;
	choose_again:
	system("cls");
	heading();
	printf("\n\n		Press 1 to View Result.......\n\n		Press 2 to LOG OUT\n\n		");
	scanf("%d",&program);
		switch (program){
		case 1:
			view_result();
			break;
		case 2:
			return 0;
			break;
		default:
			printf("	Invalid Option!!!\n\n");
	}
	goto choose_again;
}

void add_stu(){
	system("cls");
	heading();
	printf("\n			::::Add Student Record::::\n\n");
	struct stu_info stuinfo;
	FILE *fp;
	
	int select_program;
	printf("  Select Program.\n\n  1. BCA (Bachelor of Computer Application)\n\n  2. BBA (Bachelor of Business Administration)\n\n  3. B.Sc. in Environmental Management\n\n  4. M.Sc. in Environmental Management\n\n\n  Answer : ");
	scanf("%d",&select_program);
	if(select_program==1){
		fp = fopen("BCAinfo.dat","ab+");
	}	
	else if(select_program==2){
		fp = fopen("BBAinfo.dat","ab+");
	}
	else if(select_program==3){
		fp = fopen("BSCinfo.dat","ab+");
	}
	else if(select_program==4){
		fp = fopen("MSCinfo.dat","ab+");
	}
	else{
		printf("\n  Invalid Answer!!!\n");
		printf("\n  Press any key........");
		getch();
		return;
	}
	
	
	if(fp == NULL){
	        printf("Error in Opening file");
	}
	else{
        fflush(stdin);
        system("cls");
        heading();
        printf("\n			::::Add Student Record::::\n\n");
        printf("	Student ID	: "); gets(stuinfo.stu_id );
        printf("\n	Full Name	: "); gets(stuinfo.name );
        printf("\n	Address		: "); gets(stuinfo.add );
		printf("\n	DOB (dd/mm/yyyy): "); gets(stuinfo.dob );
		printf("\n	Phone Number	: "); gets(stuinfo.stu_contact);
		printf("\n	Guardian's Name	: "); gets(stuinfo.par_name);
		printf("\n	Guardian's Ph.no: "); gets(stuinfo.par_num);
		printf("\n	Academic Year	: "); gets(stuinfo.year);
        fwrite(&stuinfo, sizeof(stuinfo), 1, fp);
        printf("\n\n	The record is sucessfully added.\n\n");
    }
    fclose(fp);	
	printf("\n\n	Press any key to continue........");
	getch();
	return;
}

void mod_stu(){
	system("cls");
	heading();
	printf("\n			::::Modify Student Record::::\n\n");
	struct stu_info stuinfo;
	char s_id[15];
    int found = 0;
    FILE *fp;
    
	int select_program;
	printf("  Select Program.\n\n  1. BCA (Bachelor of Computer Application)\n\n  2. BBA (Bachelor of Business Administration)\n\n  3. B.Sc. in Environmental Management\n\n  4. M.Sc. in Environmental Management\n\n\n  Answer : ");
	scanf("%d",&select_program);
	if(select_program==1){
	    fp = fopen("BCAinfo.dat","rb+");
	}
	else if(select_program==2){
	    fp = fopen("BBAinfo.dat","rb+");
	}
	else if(select_program==3){
	    fp = fopen("BSCinfo.dat","rb+");
	}
	else if(select_program==4){
	    fp = fopen("MSCinfo.dat","rb+");
	}
	else{
		printf("\n  Invalid Answer!!!\n");
		printf("\n\n  Press any key........");
		getch();
		return;
	}
	
	system("cls");
	heading();
	printf("\n			::::Modify Student Record::::\n\n");
	printf("\n	Enter Student ID to Modify: ");
	fflush(stdin);
    gets(s_id);
	
	while(fread(&stuinfo, sizeof(stuinfo),1,fp) == 1){
        if(strcmp(s_id, stuinfo.stu_id ) == 0){
            fflush(stdin);
            printf("\n	Enter new information\n\n");
            printf("	ID		: "); gets(stuinfo.stu_id );
	        printf("\n	Name		: "); gets(stuinfo.name );
	        printf("\n	Address		: "); gets(stuinfo.add );
			printf("\n	DOB (dd/mm/yyyy): "); gets(stuinfo.dob);
			printf("\n	Phone Number	: "); gets(stuinfo.stu_contact);
			printf("\n	Guardian's Name	: "); gets(stuinfo.par_name);
			printf("\n	Guardian's Ph.no: "); gets(stuinfo.par_num);
			printf("\n	Academic Year	: "); gets(stuinfo.year);
            fseek(fp,-sizeof(stuinfo), 1);
            fwrite(&stuinfo,sizeof(stuinfo), 1, fp);
            printf("\n\n	Successfully Modified...!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        printf("\n\n	No Record Found\n\n");
    }
    fclose(fp);
	    
	printf("\n\n	Press any key to continue........");
	getch();
	return;
}

void search_stu(){
	system("cls");
	heading();
	printf("\n			::::Search Student Record::::\n\n");
	struct stu_info stuinfo;
	int select_program;
	printf("  Select Program.\n\n  1. BCA (Bachelor of Computer Application)\n\n  2. BBA (Bachelor of Business Administration)\n\n  3. B.Sc. in Environmental Management\n\n  4. M.Sc. in Environmental Management\n\n\n  Answer : ");
	scanf("%d",&select_program);
	char s_id[15];
    int found = 0;
    FILE *fp;
	if(select_program==1){
	    fp = fopen("BCAinfo.dat","rb");
	}
	else if(select_program==2){
	    fp = fopen("BBAinfo.dat","rb");
	}
	else if(select_program==3){
	    fp = fopen("BSCinfo.dat","rb");
	}
	else if(select_program==4){
	    fp = fopen("MSCinfo.dat","rb");
	}
	else{
		printf("\n  Invalid Answer!!!\n");
		printf("\n  Press any key........");
		getch();
		return;
	}
	
	system("cls");
	heading();
	printf("\n			::::Search Student Record::::\n\n");
	printf("\n	Enter ID to Search: ");
	fflush(stdin);
    gets(s_id);
    
	while(fread(&stuinfo,sizeof(stuinfo),1,fp) == 1){
        if(strcmp(s_id,stuinfo.stu_id ) == 0){
            found = 1;
            break;
        }
    }
    if(found == 1){
        printf("\n		The record is Found");
		printf("\n\n	****************************************************************");
        printf("\n\n	ID		:	%s",stuinfo.stu_id);
        printf("\n\n	Name		:	%s",stuinfo.name);
        printf("\n\n	Address		:	%s",stuinfo.add);
		printf("\n\n	DOB (dd/mm/yyyy):	%s",stuinfo.dob);
		printf("\n\n	Phone No	: 	%s",stuinfo.stu_contact);
		printf("\n\n  	Guardian's Name	:	%s",stuinfo.par_name);
		printf("\n\n  	Guardian's Ph.no:	%s",stuinfo.par_num);
        printf("\n\n	Academic Year	: 	%s",stuinfo.year);
		printf("\n\n	****************************************************************");

    }
	else{
        printf("\n	Sorry, No record found in the database!!!\n");
    }
	fclose(fp);
	printf("\n\n\n\n	Press any key to continue.......");
	getch();
	return;
}
