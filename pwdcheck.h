	 // This is to check user password
int pwdchecker(user){
	char admin_pass[17], staff_pass[17], stu_pass[17];
	int i;
	switch(user){
		
		case 1:
		printf("\n\n\n\n\n		Enter Admin Password: ");
 		for(i=0;i<5;i++){
		   admin_pass[i]=getch();
		   printf("*");
		}
  		admin_pass[i]='\0';	
  		
  		if(strcmp(admin_pass,"admin")==0){
		  return 1;
		}
		else{
			printf("\a\a");
			return 0;
		}
		break;
		
		
		case 2:
		printf("\n\n\n\n\n		Enter Teacher Password: ");
 		for(i=0;i<12;i++){
		   staff_pass[i]=getch();
		   printf("*");
		}
  		staff_pass[i]='\0';	
  		
  		if(strcmp(staff_pass,"teacher")==0){
			return 2;
		}
		else{
			printf("\a");
			return 0;
		}
		break;
		
		
		case 3:
		printf("\n\n\n\n\n		Enter Student Password: ");
 		for(i=0;i<14;i++){
		   stu_pass[i]=getch();
		   printf("*");
		}
  		stu_pass[i]='\0';	
  		
  		if(strcmp(stu_pass,"student")==0){
			return 3;
		}
		else{
			printf("\a");
			return 0;
		}
		break;
		
		
		case 4:
		printf("\n\n\n\n\n\n\t\t\t       DEVELOPED BY:\n\t\t\t        SNEHA RAI\n\t\t\t      RABI SHIWAKOTI\n\n\n\n\n\n*********************************Program Closed**********************************");
		return 4;
		break;
		
		 
		default:
			printf("\a");
		return 0;
	} 
	
	return 0;
}

