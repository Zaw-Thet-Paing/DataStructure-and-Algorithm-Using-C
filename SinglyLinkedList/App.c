#include "App.h"
#include "LinkedList.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main_sector()
{
    int option = 0;

    printf("Main Sector\n***********\n");
    printf("1. Create User\n");
    printf("2. Show User Lists\n");
    printf("3. Update User by ID\n");
    printf("4. Delete User by ID\n");
    printf("0. Exit\n");

    printf("Enter your option :: ");
    scanf("%d", &option);

    if(option == 1){
        create_user();
    }else if(option == 2){
        read_users();
    }else if(option == 3){
        update_user();
    }else if(option == 4){
        delete_user();
    }else if(option == 0){
        printf("Program exit...\n");
        exit(0);
    }else{
        printf("Invalid Option! Try again!\n");
        main_sector();
    }

}

void create_user()
{
    char c_name[50];
    char c_email[50];
    char c_address[50];
    int lastUserId = getLastNodeId(head);
    Data data;
    printf("Create User Page\n****************\n");

    printf("Enter name :: ");
    scanf(" %[^\n]", &c_name);
    printf("Enter email :: ");
    scanf(" %[^\n]", &c_email);
    printf("Enter address :: ");
    scanf(" %[^\n]", &c_address);
    
    data.id = lastUserId + 1;
    strcpy(data.name, c_name);
    strcpy(data.email, c_email);
    strcpy(data.address, c_address);

    appendNode(&head, data);

    printf("User Created Success...\n");

    main_sector();

}

void read_users()
{
    printf("User Lists\n**********\n");
    if(head == NULL){
        printf("There is no users in the list\n\n");
    }else{
        showAllNode(head);
    }
    main_sector();
}

void update_user()
{
    Node* node = NULL;
    Data data;
    int searchIdToUpdate = 0;
    char u_name[50];
    char u_email[50];
    char u_address[50];
    printf("Update User Page\n****************\n");
    
    do{
        printf("Enter user id to update :: ");
        scanf("%d", &searchIdToUpdate);
        node = searchNode(head, searchIdToUpdate);
        if(node != NULL){
            printf("ID : %d found!\n", searchIdToUpdate);
            break;
        }else{
            printf("ID : %d not found! Try again with valid ID again\n", searchIdToUpdate);
        }
    }while(1);

    printf("Enter name to update :: ");
    scanf(" %[^\n]", &u_name);
    printf("Enter email to update :: ");
    scanf(" %[^\n]", &u_email);
    printf("Enter address to update :: ");
    scanf(" %[^\n]", &u_address);

    data.id = searchIdToUpdate;
    strcpy(data.name, u_name);
    strcpy(data.email, u_email);
    strcpy(data.address, u_address);

    updateNode(&head, searchIdToUpdate, data);

    printf("User Updated Success...\n");

    main_sector();

}

void delete_user()
{

    int searchIdToDelete = 0;
    Node* node = NULL;

    printf("Update User Page\n****************\n");
    
    do{
        printf("Enter user id to update :: ");
        scanf("%d", &searchIdToDelete);
        node = searchNode(head, searchIdToDelete);
        if(node != NULL){
            printf("ID : %d found!\n", searchIdToDelete);
            break;
        }else{
            printf("ID : %d not found! Try again with valid ID again\n", searchIdToDelete);
        }
    }while(1);

    deleteNode(&head, searchIdToDelete);

    printf("User Deleted Success...\n");

    main_sector();

}