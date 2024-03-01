#include "stdio.h"
#include "string.h"

typedef struct Person{
    int id;
    char name[50];
    int age;
    char address[50];
} Person;

Person people[100];
int user_index = 0;

void create();
void read();
void update();
void delete();

int main()
{

    int options = 0;

    do{
        printf("1. Create User\n2. Read All User\n3. Update User\n4. Delete User\n0. Exit\n");
        printf("Enter your option :->");
        scanf("%d", &options);

        if(options == 1){
            create();
        }else if(options == 2){
            read();
        }else if(options == 3){
            update();
        }else if(options == 4){
            delete();
        }else if(options == 0){
            printf("Program exit...\n");
        }else{
            printf("Invalid option!\n");
        }

    }while(options != 0);

    return 0;
}

void create()
{

    char c_name[50];
    int c_age = 0;
    char c_address[50];

    printf("Create User Page\n****************\n");
    printf("Enter name ::");
    scanf(" %[^\n]", &c_name);
    printf("Enter age ::");
    scanf("%d", &c_age);
    printf("Enter address ::");
    scanf(" %[^\n]", &c_address);

    people[user_index].id = user_index + 1;
    strcpy(people[user_index].name, c_name);
    people[user_index].age = c_age;
    strcpy(people[user_index].address, c_address);

    user_index++;
}

void read()
{
    printf("Reading All Users\n*****************\n");
    for(int i = 0; i<user_index; i++){
        printf("%d %s %d %s\n", people[i].id, people[i].name, people[i].age, people[i].address);
    }
    printf("\n");
}

void update()
{
    char u_name[50];
    int u_age = 0;
    char u_address[50];

    int searchId = 0;
    int foundIndex = -1;

    printf("Update User Page\n****************\n");

    // searchId should be found here. It is not good practice. The code are just raw.
    do{
        printf("Enter id to update ::");
        scanf("%d", &searchId);

        for(int i = 0; i<user_index; i++){
            if(people[i].id == searchId){
                foundIndex = i;
                break;
            }
        }

        if(foundIndex == -1){
            printf("Your provided id not found! Try again!\n");
        }else{
            printf("User found! Going to update...\n");
            break;
        }

    }while(1);

    printf("Enter name to update ::");
    scanf(" %[^\n]", &u_name);
    printf("Enter age to update ::");
    scanf("%d", &u_age);
    printf("Enter address to update ::");
    scanf(" %[^\n]", &u_address);

    strcpy(people[foundIndex].name, u_name);
    people[foundIndex].age = u_age;
    strcpy(people[foundIndex].address, u_address);

    printf("User id : %d Updated...\n", searchId);

}

void delete()
{
    int searchId = 0;
    int foundIndex = -1;
    printf("Delete User Page\n****************\n");

    do{
        printf("Enter id to delete ::");
        scanf("%d", &searchId);

        for(int i = 0; i<user_index; i++){
            if(people[i].id == searchId){
                foundIndex = i;
                break;
            }
        }

        if(foundIndex == -1){
            printf("Your provided id not found! Try again!\n");
        }else{
            break;
        }

    }while(1);

    for(int i = foundIndex; i<user_index; i++){
        people[i].id = people[i+1].id;
        strcpy(people[i].name, people[i+1].name);
        people[i].age = people[i+1].age;
        strcpy(people[i].address, people[i+1].address);
    }
    user_index--;

    printf("User id : %d Deleted...\n", searchId);

}