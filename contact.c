#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

//function for listing
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    int k=0;
    printf("---------------------------------------------------------------------------------------\n");
    printf("%-8s %-20s %-15s %-30s\n","si.no","name","phone","email"); //printing list heading
    printf("---------------------------------------------------------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%-8d %-20s %-15s %-30s\n",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        k++;
    } 
    printf("---------------------------------------------------------------------------------------");
}

void initialize(AddressBook *addressBook) {    //function for initialize
    //addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);  //function call
}

void saveAndExit(AddressBook *addressBook) {   //function to save and exit
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    namecorrect:
    printf("enter name\n");
    char nname[30];
    getchar();  //clearing element from buffer
    scanf("%[^\n]",nname);
    if(namevalidation(nname))  //function call for name validation
    {
    strcpy(addressBook->contacts[addressBook->contactCount].name,nname); //copying if name is valid 
    }
    else
    {
        printf("enter valid name\n"); //error message
        goto namecorrect; //goto statement
    }

    validnumber:
    char nphone[10];
    printf("enter phone:\n");
    getchar();  //clearing element from buffer
    scanf("%[^\n]",nphone);
    if(phonevalidation(addressBook,nphone))  //phone validation
    {
        strcpy(addressBook->contacts[addressBook->contactCount].phone,nphone); //copying if phonenumber is valid
    }
    else
    {
        printf("enter valid number\n"); //error message
        goto validnumber; //goto statement
    } 

    validemail:
    char nemail[40];
    printf("enter new email\n");  //prompt message
    while(getchar()!='\n');  //clearing buffer until \n (if string is enterd with spaces)
    scanf("%s",nemail);
    if(emailvalidation(nemail,addressBook))   //email validation
    {
      strcpy(addressBook->contacts[addressBook->contactCount].email,nemail); //copying if email is valid     
    }
    else
    {
        printf("enter valid email\n");  //error message
        goto validemail;  //goto statement
    }
    addressBook->contactCount++;  //incrementing countactCount after creating one contact for next contact to be created
    //saveAndExit(addressBook);   
}


int arr[]={};  //globally declared array
int searchContact(AddressBook *addressBook) //function for search contact
{
    /* Define the logic for search */
    label:  //label
    printf("Enter Your Choice\n1.Name\n2.phone\n3.email\n4.exit\n"); //prompt to choose 
    int a;
    if(scanf("%d",&a)!=1) //validation if entered element is anything other than integer
    {
       printf("enter valid number choice\n");  //error message
       while(getchar()!='\n'); //clearing buffer
       goto label;  //goto statement
    } 
    else
    {
    switch(a)  //switch case
    {
        case 1:
        {
            char name[100];
            printf("enter name\n");
            getchar(); //clearing buffer
            scanf("%[^\n]",name);  //reading name to be searched
            int flag=0;
            int k=0;
            //running until contactCount times
            for(int i=0;i<addressBook->contactCount;i++)
            {
                //if(strcmp(name,addressBook->contacts[i].name)==0)
                if(strcasestr(addressBook->contacts[i].name,name)!=NULL) //checking if given name is present in list
                {
                    flag=1;  //incrementing flag
                    arr[k]=i; //storing that index value to globally declared array
                    printf("%d\t\t%s\t\t%s\t\t%s\n",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    k++;
                }  
            }
            if(flag==0) //checking flag if something is printed or not
                {
                    printf("contact not found\n"); //prompt message
                    goto label;  //goto statement
                }
                return k; //returning index value of the array;
                break;  //break statement
              
        }
        case 2:
        {
            char phone[10];
            printf("enter phone no: \n");
            getchar();  //clearing input buffer
            scanf(" %[^\n]",phone);  //reading input from user
            int flag=0; 
            int k=0;
            for(int i=0;i<addressBook->contactCount;i++)  //running loop from 0 to contactCount
            {
                //if(strstr(addressBook->contacts[i].phone,phone)!=NULL)  (using casestr)
            if(strcmp(addressBook->contacts[i].phone,phone)==0)  //comparing the full string with all the phone numbers in the addressBook
             {
                flag=1;
                arr[k]=i;//storing the index value into array.
                //printing all the numbers list matching
                printf("%d\t\t%s\t\t%s\t\t%s\n",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                k++;
             }
            }
            if(flag==0)  //checking if flag is updated
            {
                printf("Contact not found\n"); //printing prompt if list is not matched.
                goto label;  //goto statement
            }
            return k;  //returning index value
            break;
        }
        case 3:
        {
            char email[50];
            printf("Enter email id:\n");
            getchar();
            scanf("%[^\n]",email); //reading email from user
            int flag=0;
            int k=0;
            for(int i=0;i<addressBook->contactCount;i++) //running a loop until contactCount
            {
                
               // if(strstr(addressBook->contacts[i].email,email)!=NULL)
                if(strcmp(addressBook->contacts[i].email,email)==0) //checking if it is present in the list
                {
                    flag=1;
                    arr[k]=i; //stroing index value to the array.
                    //printing the list of matching emails.
                    printf("%d\t\t%s\t\t%s\t\t%s\n",k+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    k++;  //incrementing index of array
                }
            }
            if(flag==0)  //checking if flag is incremented
            {
                printf("contact not found"); //printing prompt if nothing is printed
                goto label;  //goto statements
            }
            return k;  //return  last index value
            break;
        }
        case 4:  //case 4 for break
        {
            return 0 ; //exit from function
        }
        default:  //default statement
        {
            printf("enter valid choice\n");  //prompt
            goto label;  //goto statement
        }
    }
    }

}

//function for edit statement
void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
                  int m=searchContact(addressBook);  //function call to searchContact
                  int choose;
                  if(m==0)  // condition if no element is returned index value is 0
                  {
                    return ;
                  }
                  if(m==1) //if only one index is present 
                  {
                    choose=1;
                    goto oneindex;  //to not ask the user to select the si number
                  }
                  //int choose;
                    printf("choose the si no\n");  //prompt to choose the si no
                     choose1: // label
                    while(getchar()!='\n');  //clearing input buffer
                    scanf("%d",&choose);  //reading si no from user
                     // 
                   if(choose<1 || choose>m) //condition to check if it is in range
                   {
                    printf("enter crct si no"); //if in range print error message
                    goto choose1; // goto label
                   }
                   else
                   { 
                    oneindex:  //label
                    int b;
                    label7:   //label
                    printf("Enter Your choice:\n1.Name\n2.Phone\n3.email\n4.exit");  //prompt to choose which to edit
                    while(getchar()!='\n');  //clearing input buffer
                    scanf("%d",&b);   // reading choice from user
                    switch (b)  //switch case
                    {
                        case 1:
                        {
                         newname:  //label
                         printf("enter new name\n");  //prompt message
                         char editname[30];
                         getchar();  //clearing input buffer 
                         scanf("%[^\n]",editname); //reading name from user
                         if(namevalidation(editname))  //function call to validate new name
                         {
                         strcpy(addressBook->contacts[arr[choose-1]].name,editname);  //if name valid copy new name to the choosen index
                         //print the edited contact  
                         printf("%s\t\t%s\t\t%s\n",addressBook->contacts[arr[choose-1]].name,addressBook->contacts[arr[choose-1]].phone,addressBook->contacts[arr[choose-1]].email);
                         }
                         else{
                            printf("enter valid name");  //if namevalidation is false print error message
                            goto newname;  //goto label
                         }
                         break;
                        }
                        case 2:
                        {
                         printf("enter new phone\n");
                         char editphone[30];
                         getchar();  //clearing input buffer
                         scanf("%[^\n]",editphone);  //reading phone from user
                         if(phonevalidation(addressBook,editphone))  //phone validation
                         {
                         strcpy(addressBook->contacts[arr[choose-1]].phone,editphone); //copying new phoneno to existing phone no
                         //printing edited contact 
                         printf("%s\t\t%s\t\t%s\n",addressBook->contacts[arr[choose-1]].name,addressBook->contacts[arr[choose-1]].phone,addressBook->contacts[arr[choose-1]].email);
                         }
                         else 
                         {
                            printf("enter valid no");  //if phone validation is false print error message
                         }
                         break;
                        }
                        case 3:
                        {
                         label3:  //label
                         printf("enter new mail\n");  //prompt
                         char editmail[30];
                         getchar(); //clear input buffer
                         scanf("%[^\n]",editmail); //read new email from user
                         if(emailvalidation(editmail,addressBook))  //emailvalidation
                         {
                         strcpy(addressBook->contacts[arr[choose-1]].email,editmail); //if valid email copy new email to existing email
                         //printing new contact
                         printf("%s\t\t%s\t\t%s\n",addressBook->contacts[arr[choose-1]].name,addressBook->contacts[arr[choose-1]].phone,addressBook->contacts[arr[choose-1]].email);
                         }
                         else
                         {
                            printf("enter correct email"); //if wrong email print error message
                            goto label3;  //goto label
                         }
                         break;
                        }
                        case 4: //case for exiting 
                        {
                            return; //exit from function
                        }
                        default:
                        {
                            printf("enter correct value\n"); //prompt for default case
                            goto label7;  //goto label
                        }
                    }
                    }        
}
//function for delete contact
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int b;
    int k=searchContact(addressBook);  //function call for searchcontact
    if(k==0) //condition if index is 0 
    {
        return; //exit
    }
    if(k==1) //if only one si no is present
    {
        b=1; 
    }
    else
    {
    label2:  //label
    printf("enter the si no you want to delete\n"); //prompt asking to reconfirm delete
    while(getchar()!='\n'); //clearing input buffer
    scanf("%d",&b); //reading the si no
    }
    if(b<1 || b>k) 
    {
        printf("enter correct si no\n");  //prompt error message
        goto label2;  //goto label
    }
    else
    {
    label3:  //label
    printf("do you want to delete (y/n)\n");  //prompt message to  reconfirm delete
    char c;
    while(getchar()!='\n');  //clearing buffer
    scanf("%c",&c);   //reading y or n from user
    {
        if(c=='y')  //if y
        {
          for(int j=arr[b-1];j<addressBook->contactCount;j++) //runing a loop until contactCount
          {
            addressBook->contacts[j]=addressBook->contacts[j+1]; //shifting indexes and deleting that contact
          } addressBook->contactCount--; //decrementing contactCount
        }
        else if(c=='n') //if n
        {
            printf("not deleted");  //prompt
            return ;  //exit from function
        }
        else
        {
            printf("enter y or n\n"); //prompt
            goto label3; //goto label
            return ; //exiting from function
        }   
    }
    }
}

//function for namevalidation
int namevalidation(char *editname)
{
    int i=0,f=0;
    if(strlen(editname)==0) //if nothing is given
    {
        return 0;
    }
    if(editname[i]==32)  //if space is given at first
    {
        return 0;
    }
    while(editname[i]!='\0')
    {
      if(isalpha(editname[i]) || editname[i]==32 ) //all elements should be alphabet, space can be present
      {
        f++;
      }
      i++;
    }
    if(f==i) //condition to check flag equals i
    {
        return 1;
    }
    else{
        return 0;
    }
}
//function for phone validation
int phonevalidation(AddressBook *addressBook ,char *editphone)
{
     int f=0;
     if(strlen(editphone)==10) //checking if string length is 10
     {
        int i=0;
        f=1;
        while(editphone[i]!='\0') 
        {
            if(editphone[0]=='0') //if first number is 0
            {
                return 0;
            }

            if(isdigit(editphone[i])) //all elements are digit
            {
                i++;
            }
            else
            {
               // printf("enter valid number");
                return 0;
            }   
        }
     }
     for(int i=0;i<addressBook->contactCount;i++) //running a loop to match it with the current list
     {
      if(!(strcmp(addressBook->contacts[i].phone,editphone)))  //condition
       {
        printf("Number already present in list\n");  //prompt message
        return 0;
       }
     } 
     if(f==0)
     {
        return 0;
     }
     return 1;  //returning  1
    
}


//function for email validation
int emailvalidation(char *editmail,AddressBook *addressBook)
{
    int i=0;
    int f=0;
   while(editmail[i]!='@') //running until @
   {
    if(islower(editmail[i]) || isdigit(editmail[i]))  //all numbers should be either lowercase or a digit
    {
        i++;
    } 
    else
    {
        return 0;
    }
   } 
   i++; //point to the next in dex after @
   for(int j=i;j<strlen(editmail);j++)  //running loop from after the @ to end
   {
    if(editmail[j]=='.')  //checking if '.' is present
    {
    f++;  //incrementing flag
    }
   }
   if(f!=1) //if flag either 0 or more than 1
   {
    return 0; 
   }
   while(editmail[i]!='.') //loop until .
   {
    if(islower(editmail[i])) //check if all elements are lower case
    {
        i++;
    }
    else
    {
        return 0;
    }
   }
    if((strcmp(&editmail[strlen(editmail)-4],".com")!=0))  //checking if the last 4 elements are not .com
    {
    return 0;
    }
    //running a loop to check if email already present in address book
    for(int i=0;i<addressBook->contactCount;i++)
     {
      if(!(strcmp(addressBook->contacts[i].email,editmail))) //comparing each contacts
       {
        printf("email already present in list\n"); //error message
        return 0;
       }
       
     } 
     return 1;  //returning 1 if every condition is met
   
}
  
