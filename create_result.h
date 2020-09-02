struct stu_info2{
	char name[30],add[40],stu_id2[15],stu_contact[15],dob[11],par_name[30],par_num[15],year[5];
};

struct academic{
	char stu_id[15], stu_sem[5];
	float gpa;
};

struct subjects{
		char sub_name[60],sub_grade[3];
		float sub_marks,sub_gpa;
};

void heading2(){
	printf("===================================================================================\n");
	printf("				   SchEMS\n");
	printf("			Examination Management System\n");
	printf("			       Pokhara University\n");
	printf("===================================================================================\n");
	return;
}

void enter_result(){
	system("cls");
	heading2();
	printf("\n			:::Create Marksheet:::\n\n");
	FILE *fp;
	
	int select_program;
	printf("  Select Program.\n\n  1. BCA (Bachelor of Computer Application)\n\n  2. BBA (Bachelor of Business Administration)\n\n  3. B.Sc. in Environmental Management\n\n  4. M.Sc. in Environmental Management\n\n\n  Answer : ");
	scanf("%d",&select_program);
	if(select_program==1){
		fp = fopen("BCA_academic_detail.dat","ab+");
	}	
	else if(select_program==2){
		fp = fopen("BBA_academic_detail.dat","ab+");
	}
	else if(select_program==3){
		fp = fopen("BSC_academic_detail.dat","ab+");
	}
	else if(select_program==4){
		fp = fopen("MSC_academic_detail.dat","ab+");
	}
	else{
		printf("\n	Invalid Answer\n");
		printf("\n\n	Press any key........");
		getch();
		return;
	}
		
	if(fp == NULL){
	        printf("Error in Opening file");
	}
	else{
        fflush(stdin);
        system("cls");
        heading2();
        struct academic aca;
        printf("\n			:::Create Marksheet:::\n\n");
		printf("	Student ID		: "); gets(aca.stu_id);
		printf("	Semester (1st, 2nd, 3rd.....)	: "); gets(aca.stu_sem );
        int n=6;
        struct subjects sub[n];
        int i=0;
        aca.gpa = 0;
        printf("\n	( MESSAGE: Use Subject Name as '-' & Subject Marks as '0' in case of absent )\n");
        while(i<n){
        	fflush(stdin);
        	printf("\n	%d. Subject Name		: ",i+1); gets(sub[i].sub_name );
        	printf("	   Obtained Marks	: "); scanf("%f",&sub[i].sub_marks );
        	if(sub[i].sub_marks>=90){
	            strcpy(sub[i].sub_grade, "A");
        		sub[i].sub_gpa =4.0;
			}
			else if(sub[i].sub_marks>=85 && sub[i].sub_marks<90){
        		strcpy(sub[i].sub_grade, "A-");
        		sub[i].sub_gpa =3.7;
			}
			else if(sub[i].sub_marks>=80 && sub[i].sub_marks<85){
        		strcpy(sub[i].sub_grade, "B+");
        		sub[i].sub_gpa =3.3;
			}
			else if(sub[i].sub_marks>=75 && sub[i].sub_marks<80){
        		strcpy(sub[i].sub_grade, "B");
        		sub[i].sub_gpa =3.0;
			}
			else if(sub[i].sub_marks>=70 && sub[i].sub_marks<75){
        		strcpy(sub[i].sub_grade, "B-");
        		sub[i].sub_gpa =2.7;
			}
			else if(sub[i].sub_marks>=65 && sub[i].sub_marks<70){
        		strcpy(sub[i].sub_grade, "C+");
        		sub[i].sub_gpa =2.3;
			}
			else if(sub[i].sub_marks>=60 && sub[i].sub_marks<65){
        		strcpy(sub[i].sub_grade, "C");
        		sub[i].sub_gpa =2.0;
			}
			else if(sub[i].sub_marks>=55 && sub[i].sub_marks<60){
        		strcpy(sub[i].sub_grade, "C-");
        		sub[i].sub_gpa =1.7;
			}
			else if(sub[i].sub_marks>=50 && sub[i].sub_marks<55){
        		strcpy(sub[i].sub_grade, "D+");
        		sub[i].sub_gpa =1.3;
			}
			else if(sub[i].sub_marks>=45 && sub[i].sub_marks<50){
        		strcpy(sub[i].sub_grade, "D");
        		sub[i].sub_gpa =1.0;
			}
			else if(strcmp(sub[i].sub_name,"-")==0){
				strcpy(sub[i].sub_grade, "-");
				sub[i].sub_gpa= 0;
			}
			else{
				strcpy(sub[i].sub_grade, "F");
				sub[i].sub_gpa= 0.0;
			}
			aca.gpa = aca.gpa + sub[i].sub_gpa ;
        	i++;
		}
		if(sub[5].sub_marks==0){
			aca.gpa = aca.gpa /5;
		}
		else{
			aca.gpa = aca.gpa /6;
		}
	    fwrite(&aca, sizeof(aca), 1, fp);
        fwrite(&sub, sizeof(sub), 1, fp);
		printf("\n	The record is sucessfully added.\n\n");   
	}
	fclose(fp);
	printf("\n\n\n	Press any key to continue........");
	getch();
	return;
    }
    
void view_result(){
	system("cls");
	heading2();
    fflush(stdin);
	printf("\n			:::View Result:::\n\n");
	int select_program;
	printf("  Select Program.\n\n  1. BCA (Bachelor of Computer Application)\n\n  2. BBA (Bachelor of Business Administration)\n\n  3. B.Sc. in Environmental Management\n\n  4. M.Sc. in Environmental Management\n\n\n  Answer : ");
	scanf("%d",&select_program);
	char s_id[15], s_sem[5];
    int found = 0, found2 = 0;
    FILE *fp;
    FILE *fptr;
	if(select_program==1){
	    fp = fopen("BCAinfo.dat","rb");
		fptr = fopen("BCA_academic_detail.dat","rb");
	}
	else if(select_program==2){
	    fp = fopen("BBAinfo.dat","rb");
		fptr = fopen("BBA_academic_detail.dat","rb");
	}
	else if(select_program==3){
	    fp = fopen("BSCinfo.dat","rb");
		fptr = fopen("BSC_academic_detail.dat","rb");
	}
	else if(select_program==4){
	    fp = fopen("MSCinfo.dat","rb");
		fptr = fopen("MSC_academic_detail.dat","rb");
	}
	else{
		printf("\n  Invalid Answer!!!\n");
		printf("\n\n  Press any key........");
		getch();
		return;
	}
	
	system("cls");
	heading2();
	printf("\n			:::View Result:::\n\n");
	struct stu_info2 stuinfo;
	struct academic aca;
	int n=6;
    struct subjects sub[n];
    fflush(stdin);
	printf("\n	Enter ID to Search		: ");
    gets(s_id);
    printf("	Semester (1st, 2nd, 3rd.....)	: ");
    gets(s_sem);
	while(fread(&stuinfo,sizeof(stuinfo),1,fp) == 1){
        if(strcmp(s_id,stuinfo.stu_id2 ) == 0){
            found = 1;
            break;
        }
    }
    while((fread(&aca,sizeof(aca),1,fptr) == 1 ) && (fread(&sub,sizeof(sub),1,fptr) == 1)){
        if(strcmp(s_id,aca.stu_id ) == 0){
        	if(strcmp(s_sem,aca.stu_sem) == 0){
        		found2 = 1;
        	    break;
			}
        }
    }
    if(found == 1 && found2 == 1){
    	int failcheck;
    	system("cls");
		heading2();
        printf("\n	****************************************************************");
        printf("\n			:::::INTERNAL EXAMINATION RESULT:::::");
        printf("\n	****************************************************************");
        printf("\n\n	ID		:	%s",stuinfo.stu_id2);
        printf("\n	Name		:	%s",stuinfo.name);
        printf("\n	Semester	:	%s",aca.stu_sem);
        printf("\n	****************************************************************");

        int i=0;
        while(i<n){
        	printf("\n\n	%d. Subject Name	:	%s",i+1,sub[i].sub_name );
        //	printf("\n	Obtained Marks	:	%.2f",sub[i].sub_marks );
        	printf("\n	   Honor Point	:	%.2f",sub[i].sub_gpa );
        	printf("\n	   Grade	:	%s",sub[i].sub_grade );
        	if(strcmp(sub[i].sub_grade,"F")==0){
        		failcheck=1;
			}
        	i++;
		}
		if(failcheck==1){
			printf("\n\n	****************************************************************");
        	printf("\n		GPA	:	FAIL");
        	printf("\n	****************************************************************");
		}
		else{
        	printf("\n\n	****************************************************************");
       		printf("\n		GPA	:	%.2f",aca.gpa);
        	printf("\n	****************************************************************");
    	}
    }
	else{
        printf("\n	Sorry, No record found in the database!!!\n");
    }
	fclose(fp);
	fclose(fptr);
	printf("\n\n	Press any key to continue.......");
	getch();
	return;
}

void fullaccess(){
	system("cls");
	heading2();
    fflush(stdin);
	printf("\n			:::View Result:::\n\n");
	int select_program;
	printf("  Select Program.\n\n  1. BCA (Bachelor of Computer Application)\n\n  2. BBA (Bachelor of Business Administration)\n\n  3. B.Sc. in Environmental Management\n\n  4. M.Sc. in Environmental Management\n\n\n  Answer : ");
	scanf("%d",&select_program);
    FILE *fptr;
	if(select_program==1){
		fptr = fopen("BCA_academic_detail.dat","rb");
	}
	else if(select_program==2){
		fptr = fopen("BBA_academic_detail.dat","rb");
	}
	else if(select_program==3){
		fptr = fopen("BSC_academic_detail.dat","rb");
	}
	else if(select_program==4){
		fptr = fopen("MSC_academic_detail.dat","rb");
	}
	else{
		printf("\n  Invalid Answer!!!\n");
		printf("\n\n  Press any key........");
		getch();
		return;
	}
	
	system("cls");
	heading2();
	printf("\n			:::All Smester Marksheet:::\n\n");
	struct stu_info2 stuinfo;
	struct academic aca;
	int n=6;
    struct subjects sub[n];
    fflush(stdin);
	system("cls");
	heading2();
    while((fread(&aca,sizeof(aca),1,fptr) == 1 ) && (fread(&sub,sizeof(sub),1,fptr) == 1)){
    	int failcheck;-
        printf("\n	****************************************************************");
        printf("\n			:::::INTERNAL EXAMINATION RESULT:::::");
        printf("\n	****************************************************************");
        printf("\n\n	ID		:	%s",aca.stu_id);
        printf("\n	Semester	:	%s\n",aca.stu_sem);
        printf("\n	****************************************************************");
        int i=0;
        while(i<n){
        	printf("\n\n	%d. Subject Name	 :	%s",i+1,sub[i].sub_name );
        	printf("\n	   Obtained Marks:	%.2f",sub[i].sub_marks );
        	printf("\n	   Honor Point	 :	%.2f",sub[i].sub_gpa );
        	printf("\n	   Grade	 :	%s",sub[i].sub_grade );
        	if(strcmp(sub[i].sub_grade,"F")==0){
        		failcheck=1;
			}
        	i++;
		}
		if(failcheck==1){
			printf("\n\n	****************************************************************");
        	printf("\n		GPA	:	FAIL");
        	printf("\n	****************************************************************");
		}
		else{
        	printf("\n\n	****************************************************************");
       		printf("\n		GPA	:	%.2f",aca.gpa);
        	printf("\n	****************************************************************");
    	}
    	printf("\n\n\n\n\n\n");
    }
	fclose(fptr);
	printf("\n\n	Press any key to continue.......");
	getch();
	return;
}
