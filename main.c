//Address book project
//name:muhammed juraige
//date:29/10/2025
//description:create an address book to create,edit search and list all the contacts

#include <stdio.h>
#include<ctype.h>
#include "contact.h"

int main() {
    int choice;
    int sortChoice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        label5:
        printf("Enter your choice: \n");
        
        if(scanf("%d", &choice)!=1)  //if entered element is anything other than number
        {
            printf("invalid input\n"); //print error message
            while(getchar()!='\n');  //clearing everything from input buffer
            continue;  //continue 
        }
       
         switch (choice)
          {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;    
            default:
               printf("Invalid choice. Please try again.\n");
               
           }
        
       
    } while (choice != 7);
    
       return 0;
}
