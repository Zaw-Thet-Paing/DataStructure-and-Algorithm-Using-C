#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define StackMaxSize 100

struct XMLTags{
    int tagCount;
    char tags[50][10];
};

struct String{
    char text[1000];
};

struct Stack{
    int top;
    char text[StackMaxSize][10];
};

typedef struct XMLTags XMLTags;
typedef struct String String;

typedef struct Stack Stack;

String readTextFromFile(char fileName[]);
String trimSlash(char text[]);

XMLTags getXMLTags(char xmlText[]);

Stack* initStack();
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, char text[]);
String pop(Stack* stack);
String peek(Stack* stack);


int main()
{
    char xmlTextFromFile[1000];
    memset(xmlTextFromFile, '\0', sizeof(xmlTextFromFile));

    strcpy(xmlTextFromFile, readTextFromFile("note.xml").text);

    Stack* stack = initStack();

    XMLTags xmlTags = getXMLTags(xmlTextFromFile);
    for(int i = 0; i<xmlTags.tagCount; i++){
        if(xmlTags.tags[i][0] != '/'){
            push(stack, xmlTags.tags[i]);
        }else{
            String str = trimSlash(xmlTags.tags[i]);
            if(strcmp(str.text, peek(stack).text) == 0){
                pop(stack);
            }else{
                printf("XML is invalid\n");
                exit(1);
            }
        }
    }

    if(isEmpty(stack)){
        printf("XML is valid\n");
    }else{
        printf("XML is invalid\n");
    }

    free(stack);
    return 0;
}

String readTextFromFile(char fileName[])
{
    char ch;
    String text;
    memset(text.text, '\0', sizeof(text.text));
    FILE* fptr;
    fptr = fopen(fileName, "r");

    if(fptr == NULL){
        printf("File reading error!\n");
        exit(1);
    }

    int i = 0;
    while((ch = fgetc(fptr)) != EOF){
        if(ch != ' ' && ch != '\n'){
            text.text[i++] = ch;
        }
    }

    fclose(fptr);

    return text;
}

String trimSlash(char text[])
{
    String str;
    if(text[0] == '/'){
        for(int i = 0; i<strlen(text); i++){
            str.text[i] = text[i+1];
        }
    }else{
        strcpy(str.text, text);
    }
    return str;
}

XMLTags getXMLTags(char xmlText[])
{
    XMLTags xmlTags;
    memset(xmlTags.tags, '\0', sizeof(xmlTags.tags));
    xmlTags.tagCount = 0;
    int xmlTagIndex = 0;
    int oXMLIndex = 0;
    int cXMLIndex = 0;
    for(int i = 0; i<strlen(xmlText); i++){
        
        if(xmlText[i] == '<'){
            //for opening tags
            if(xmlText[i+1] != '/'){
                for(int j = i; j<i+10; j++){
                    if(xmlText[j] == '>'){
                        oXMLIndex = i;
                        cXMLIndex = j;
                        int z = 0;
                        for(int k = (oXMLIndex+1); k<cXMLIndex; k++){
                            xmlTags.tags[xmlTagIndex][z] = xmlText[k];
                            xmlTags.tags[xmlTagIndex][z+1] = '\0';
                            z++;
                        }
                        xmlTagIndex++;
                        break;
                    }
                }
            }
            //for closing address
            if(xmlText[i+1] == '/'){
                for(int j = (i+1); j<(i+1)+10; j++){
                    if(xmlText[j] == '>'){
                        oXMLIndex = i;
                        cXMLIndex = j;
                        int z = 0;
                        for(int k = oXMLIndex+1; k<cXMLIndex;  k++){
                            xmlTags.tags[xmlTagIndex][z] = xmlText[k];
                            xmlTags.tags[xmlTagIndex][z+1] = '\0';
                            z++;
                        }
                        xmlTagIndex++;
                        break;
                    }
                }
            }
            xmlTags.tagCount++;
        }

    }

    return xmlTags;
}

Stack* initStack()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isFull(Stack* stack)
{
    return stack->top == StackMaxSize - 1;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

void push(Stack* stack, char text[])
{
    if(isFull(stack)){
        printf("Stack Overflow\n");
        exit(1);
    }

    strcpy(stack->text[++stack->top], text);
    
}

String pop(Stack* stack)
{
    String str;
    if(isEmpty(stack)){
        printf("Stack is empty!\n");
        strcpy(str.text, "NULL");
        return str;
    }

    strcpy(str.text, stack->text[stack->top--]);
    return str;
}

String peek(Stack* stack)
{
    String str;
    if(isEmpty(stack)){
        printf("Stack is empty!\n");
        strcpy(str.text, "NULL");
        return str;
    }

    strcpy(str.text, stack->text[stack->top]);
    return str;
}