#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<limits.h>
#define peoples 6
#define MAX_WORD_LEN 20
#define MAX_MEANING_LEN 200

struct value
{
    char w[20];
    char m[200];
};

typedef struct value ED;
ED data[20];

///Storing the existed data i.e the  user added data in the form of Binary tree
///input:takes the data from the user and description about it
///output : Gives the required output asked by the user .
///Different data types of the structure node

typedef struct node {
    char word[MAX_WORD_LEN];
    char meaning[MAX_MEANING_LEN];
    struct node *right, *left;
} DIC;

DIC *root=NULL;

///Allocating the memory to the node which is present within the tree
DIC* create_node(const char *word, const char *meaning) {
    DIC *newnode = (DIC*)malloc(sizeof(DIC));
    if (!newnode) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    strncpy(newnode->word, word, MAX_WORD_LEN - 1);
    strncpy(newnode->meaning, meaning, MAX_MEANING_LEN - 1);
    newnode->word[MAX_WORD_LEN - 1] = '\0';
    newnode->meaning[MAX_MEANING_LEN - 1] = '\0';
    newnode->right = newnode->left = NULL;
    return newnode;
}

///Deleting the node on the request of the user

DIC* delete_node(DIC *root, const char *word) {
    if (!root) return NULL;
    int cmp = strcmp(root->word, word);
    if (cmp > 0) {
        root->left = delete_node(root->left, word);
    } else if (cmp < 0) {
        root->right = delete_node(root->right, word);
    } else {
        if (!root->left) {
            DIC *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            DIC *temp = root->left;
            free(root);
            return temp;
        }
        DIC *successor = root->right;
        while (successor->left) successor = successor->left;
        strncpy(root->word, successor->word, MAX_WORD_LEN - 1);
        strncpy(root->meaning, successor->meaning, MAX_MEANING_LEN - 1);
        root->right = delete_node(root->right, successor->word);
    }
    return root;
}

void delete_(const char *word) {
    root = delete_node(root, word);
}

///Insert the value within a tree if the user requested

void insert(const char *word, const char *meaning) {
    DIC **curr = &root;
    while (*curr) {
        int cmp = strcmp((*curr)->word, word);
        if (cmp == 0) {
            printf("Word already exists. Updating meaning.\n");
            strncpy((*curr)->meaning, meaning, MAX_MEANING_LEN - 1);
            return;
        }
        curr = cmp > 0 ? &((*curr)->left) : &((*curr)->right);
    }
    *curr = create_node(word, meaning);
}

///Traversal with the data present in the tree

void inorderTraversal(DIC *node) {
    if (!node) return;
    inorderTraversal(node->left);
    printf("Word: %s\t Meaning: %s\n", node->word, node->meaning);
    inorderTraversal(node->right);
}

void find_elements(const char *word) {
    DIC *temp = root;
    while (temp) {
        int cmp = strcmp(temp->word, word);
        if (cmp == 0) {
            printf("Meaning of '%s': %s\n", temp->word, temp->meaning);
            return;
        }
        temp = cmp > 0 ? temp->left : temp->right;
    }
    printf("Word not found\n");
}

/**
Function Name: load from file
Input Parameter: NILL
Return Type: void
Description: loads all the data available with search engine into appropriate data structure
**/

void load_from_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("File open failed");
        return;
    }
    char word[MAX_WORD_LEN], meaning[MAX_MEANING_LEN];
    while (fscanf(fp, "%19s %[^"]199[^"]", word, meaning) == 2) {
        insert(word, meaning);
    }
    fclose(fp);
}

void mini_dictionary() {
    int choice;
    char word[MAX_WORD_LEN], meaning[MAX_MEANING_LEN];
    load_from_file("dictionary.txt");
    while (1) {
        printf("\n1. Add Word\n2. Delete Word\n3. Search Word\n4. Display All Words\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%19s", word);
                getchar(); // Consume newline
                printf("Enter meaning: ");
                fgets(meaning, MAX_MEANING_LEN, stdin);
                meaning[strcspn(meaning, "\n")] = 0;
                insert(word, meaning);
                break;
            case 2:
                printf("Enter word to delete: ");
                scanf("%19s", word);
                delete_(word);
                break;
            case 3:
                printf("Enter word to search: ");
                scanf("%19s", word);
                find_elements(word);
                break;
            case 4:
                inorderTraversal(root);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void rahul1()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    fp=fopen("rahul.txt","r");
    if(fp==NULL)
    {
        printf("file not opened\n\a");
        return;
    }
    printf("THE MESSAGE RECEIVED BY RAHUL :");
    while(!feof(fp))
    {
        fscanf(fp,"%[^\n]s",msg);
        printf("%s",msg);
    }

    fclose(fp);
}

void james1()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    fp=fopen("james.txt","r");
    if(fp==NULL)
    {
        printf("file not opened\n\a");
        return;
    }
    printf("THE MESSAGE RECEIVED BY JAMES :");
    while(!feof(fp))
    {
        fscanf(fp,"%[^\n]s",msg);
        printf("%s",msg);
    }

    fclose(fp);
}

void abdul1()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    fp=fopen("abdul.txt","r");
    if(fp==NULL)
    {
        printf("file not opened\n\a");
        return;
    }

    printf("THE MESSAGE RECEIVED BY ABDUL :");
    while(!feof(fp))
    {
        fscanf(fp,"%[^\n]s",msg);
        printf("%s",msg);
    }

    fclose(fp);
}

void reeta1()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    fp=fopen("reeta.txt","r");
    if(fp==NULL)
    {
        printf("file not opened\n\a");
        return;
    }
    printf("THE MESSAGE SENT TO REETA :");
    while(!feof(fp))
    {
        fscanf(fp,"%[^\n]s",msg);
        printf("%s",msg);
    }
    fclose(fp);
}

void mihit1()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    fp=fopen("mihit.txt","r");
    if(fp==NULL)
    {
        printf("file not opened\n\a");
        return;
    }

    printf("THE MESSAGE RECEIVED BY MIHIT :");
    while(!feof(fp))
    {
        fscanf(fp,"%[^\n]s",msg);
        printf("%s",msg);
    }

    fclose(fp);
}

void check_sent_msg()
{
    int choice;

    while(1)
    {
        printf("Read sent messages\n");
        printf("\nEnter 1 to read message of RAHUL\nEnter 2 to read message of JAMES\nEnter 3 to read message of ABDUL\nEnter 4 to read message of REETA\nEnter 5 to read message of MIHIT\nEnter 6 to exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            rahul1();
            break;

        case 2:
            james1();
            break;

        case 3:
            abdul1();
            break;

        case 4:
            reeta1();
            break;

        case 5:
            mihit1();
            break;

        case 6:
            return;
        }

    }
}

struct con
{
    char name[10];
    int no;
};

///FOLLOWING 5 FUNCTIONS INDICATE CONTACT INFORMATIONS AND TEXT MESSAGE OPERATIONS
///INPUT :NULL
///OUTPUT :NULL

void rahul()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    int i,key,time;
    fp=fopen("rahul.txt","a");
    if(fp==NULL)
    {
        printf("SERVER NOT FOUND!\n\a");
        return;
    }
    printf("ENTER MESSAGE TO RAHUL :");
    char d;
    d=getchar();
    scanf("%[^\n]c",msg);

    printf("Enter 1 for normal message and 2 for scheduled message:");
    scanf("%d",&key);

    if(key==2)
    {
        printf("Enter the scheduled time in second:",time);
        scanf("%d",&time);

        for(i=time; i>=0; i--)
        {
            printf("\n%d....",i);

            sleep(1);
        }

        printf("\nScheduled message sent\n");
    }

    fprintf(fp,msg);
    fclose(fp);
}

void james()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    int i,key,time;
    fp=fopen("james.txt","a");
    if(fp==NULL)
    {
        printf("SERVER NOT FOUND!\n\a");
        return;
    }
    printf("ENTER MESSAGE TO JAMES :");
    char d;
    d=getchar();
    scanf("%[^\n]c",msg);

    printf("Enter 1 for normal message and 2 for scheduled message:");
    scanf("%d",&key);

    if(key==2)
    {
        printf("Enter the scheduled time in second:",time);
        scanf("%d",&time);

        for(i=time; i>=0; i--)
        {
            printf("\n%d....",i);

            sleep(1);
        }

        printf("\nScheduled message sent\n");
    }

    fprintf(fp,msg);
    fclose(fp);
}

void abdul()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    int i,key,time;
    fp=fopen("abdul.txt","a");
    if(fp==NULL)
    {
        printf("SERVER NOT FOUND!\n\a");
        return;
    }
    printf("ENTER MESSAGE TO ABDUL:");
    char d;
    d=getchar();
    scanf("%[^\n]c",msg);

    printf("Enter 1 for normal message and 2 for scheduled message:");
    scanf("%d",&key);

    if(key==2)
    {
        printf("Enter the scheduled time in second:",time);
        scanf("%d",&time);

        for(i=time; i>=0; i--)
        {
            printf("\n%d....",i);

            sleep(1);
        }

        printf("\nScheduled message sent\n");
    }

    fprintf(fp,msg);
    fclose(fp);
}

void reeta()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    int i,key,time;
    fp=fopen("reeta.txt","a");
    if(fp==NULL)
    {
        printf("SERVER NOT FOUND!\n\a");
        return;
    }
    printf("ENTER MESSAGE TO REETA :");
    char d;
    d=getchar();
    scanf("%[^\n]c",msg);

    printf("Enter 1 for normal message and 2 for scheduled message:");
    scanf("%d",&key);

    if(key==2)
    {
        printf("Enter the scheduled time in second:",time);
        scanf("%d",&time);

        for(i=time; i>=0; i--)
        {
            printf("\n%d....",i);

            sleep(1);
        }

        printf("\nScheduled message sent\n");
    }

    fprintf(fp,msg);
    fclose(fp);
}

void mihit()
{
    printf("\n\n");
    FILE *fp;
    char msg[100];
    int i,key,time;
    fp=fopen("mihit.txt","a");
    if(fp==NULL)
    {
        printf("SERVER NOT FOUND!\n\a");
        return;
    }
    printf("ENTER MESSAGE TO MIHIT :");
    char d;
    d=getchar();
    scanf("%[^\n]c",msg);

    printf("Enter 1 for normal message and 2 for scheduled message:");
    scanf("%d",&key);

    if(key==2)
    {
        printf("Enter the scheduled time in second:",time);
        scanf("%d",&time);

        for(i=time; i>=0; i--)
        {
            printf("\n%d....",i);

            sleep(1);
        }

        printf("\nScheduled message sent\n");
    }

    fprintf(fp,msg);
    fclose(fp);
}

///HASH FUNCTION TO MATCH PASSWORD
int hash(int a)
{
    for(int i=0; i<4; i++)
    {
        a=a+a*pow(4,i);
    }
    return a;
}

struct con d[10];

typedef struct movie
{
    char m_name[100];
    float m_size;
    float m_duration;

} MOVIE;

typedef struct music
{
    char mu_name[100];
    float mu_size;
    float mu_duration;

} MUSIC;

typedef struct files
{
    char f_name[100];
    float f_size;
    float f_duration;

} FILES;

typedef struct videos
{
    char v_name[100];
    float v_size;
    float v_duration;

} VIDEOS;

MOVIE *M;
MUSIC *MU;
FILES *F;
VIDEOS *V;

///FOLLOWING FOUR FUNCTIONS IINCLUDE FILE OPERATIONS AND DOWNLOAD OPERATIONS
///INPUT : NULL
///OUTPUT: SEARCHS AND FIND WHETHER THE GIVEN CATEGORY TYPE IS THERE OR NOT

void movie_file()
{
    printf("\n\n");
    FILE *fp,*fp1;
    char movie_string[100];
    int flag=0,choice;
    fp = fopen("movie.txt","r");
    if (fp == NULL)
    {
        printf("SERVER NOT FOUND!\n\a");
        return;
    }

    printf("ENTER NAME OF THE MOVIE TO BE SEARCHED\n");
    scanf("%s",movie_string);
    while(fscanf(fp,"%s %f %f", M->m_name,&M->m_size,&M->m_duration) != EOF)
    {
        if(strcmp(movie_string,M->m_name)==0)
        {
            flag=1;
            printf("Name\tSize\tDuration\n");
            printf("%s\t%0.1f\t%0.1f\n",M->m_name,M->m_size,M->m_duration);
            printf("ENTER 1 TO CONFIRM\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("Downloading...\n");
                sleep(5);
                printf("YOUR MOVIE %s IS DOWNLOADED SUCCESSFULLY\n",M->m_name);
                fp1 = fopen("downloaded.txt","a");
                if(fp1==NULL)
                {
                    printf("SERVER NOT FOUND!\n\a");
                }
                fprintf(fp1,"\n");
                fprintf(fp1, M->m_name);
                fclose(fp1);
            }
            else
            {
                printf("Denial of downloading movie\n\a");
            }
            break;
        }
    }

    if(flag==0)
    {
        printf("Movie not found\n\a");
    }

    fclose(fp);
}

void music_file()
{
    printf("\n\n");
    FILE *fp,*fp1;
    char music_string[100];
    int flag=0,choice;
    fp = fopen("music.txt","r");
    if (fp == NULL)
    {
        printf("SERVER NOT FOUND!\n\a");
        return;
    }
    printf("ENTER NAME OF MUSIC TO BE SEARCHED\n");
    scanf("%s",music_string);
    while(fscanf(fp,"%s %f %f", MU->mu_name,&MU->mu_size,&MU->mu_duration) != EOF)
    {
        if(strcmp(music_string,MU->mu_name)==0)
        {
            flag=1;
            printf("Name\tSize\tDuration\n");
            printf("%s\t%0.1f\t%0.1f\n",MU->mu_name,MU->mu_size,MU->mu_duration);
            printf("ENTER 1 TO CONFIRM\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("Downloading...\n");
                sleep(5);
                printf("YOUR MUSIC %s IS DOWNLOADED SUCCESSFULLY\n",MU->mu_name);
                fp1 = fopen("downloaded.txt","a");
                fprintf(fp1,"\n");
                fprintf(fp1, MU->mu_name);
                fclose(fp1);
            }

            else
            {
                printf("Denial of downloading music\n\a");
            }
            break;
        }
    }

    if(flag==0)
    {
        printf("Music not found\n\a");
    }

    fclose(fp);
}

void files()
{
    printf("\n\n");
    FILE *fp,*fp1;
    char file_string[100];
    int flag=0,choice;
    fp = fopen("files.txt","r");
    if (fp == NULL)
    {
        printf("SERVER NOT FOUND!\n\a");
        return;
    }

    printf("ENTER NAME OF FILE TO BE SEARCHED\n");
    scanf("%s",file_string);
    while(fscanf(fp,"%s %f", F->f_name,&F->f_size) != EOF)
    {
        if(strcmp(file_string,F->f_name)==0)
        {
            flag=1;
            printf("Name\tSize\tDuration\n");
            printf("%s\t%0.1f\t%0.1f\n",F->f_name,F->f_size);
            printf("Enter the choice as 1 of whether to be downloaded else 0\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("Downloading...\n");
                sleep(5);
                printf("FILE %s DOWNLOADED SUCCESSFULLY\n",F->f_name);
                fp1 = fopen("downloaded.txt","a");
                fprintf(fp1,"\n");
                fprintf(fp1, F->f_name);
                fclose(fp1);
            }
            else
            {
                printf("Denial of downloading file\n\a");
            }
            break;
        }
    }

    if(flag==0)
    {
        printf("SERVER NOT FOUND!\n\a");
    }

    fclose(fp);
}

void videos_file()
{
    printf("\n\n");
    FILE *fp,*fp1;
    char videos_string[100];
    int flag=0,choice;
    fp = fopen("videos.txt","r");
    if (fp == NULL)
    {
        printf("SERVER NOT FOUND!\n\a");
        return;
    }

    printf("ENTER NAME OF VIDEO TO BE SEARCHED\n");
    scanf("%s",videos_string);
    while(fscanf(fp,"%s %f %f", V->v_name,&V->v_size,&V->v_duration) != EOF)
    {
        if(strcmp(videos_string,V->v_name)==0)
        {
            flag=1;
            printf("Name\tSize\tDuration\n");
            printf("%s\t%0.1f\t%0.1f\n",V->v_name,V->v_size,V->v_duration);
            printf("ENTER 1 TO CONFIRM\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("Downloading...\n");
                sleep(5);
                printf("VIDEO %s is DOWNLOADED SUCCESSFULLY\n",V->v_name);
                fp1 = fopen("downloaded.txt","a");
                fprintf(fp1,"\n");
                fprintf(fp1, V->v_name);
                fclose(fp1);
            }

            else
            {
                printf("Denial of downloading video\n\a");
            }
            break;
        }
    }

    if(flag==0)
    {
        printf("Video not found\n\a");
    }

    fclose(fp);
}

struct info
{
    char naam[10];
};

typedef struct info INFO;

///FUNCTION FOR AUTO SUGGESTIONS
///INPUT :A 2D ARRAY
///OUT PUT :NULL

void suggestion(INFO arr[])
{
    printf("\n\n");
    int i,j;
    strcpy(arr[1].naam,"Rahul");
    strcpy(arr[2].naam,"James");
    strcpy(arr[3].naam,"Abdul");
    strcpy(arr[4].naam,"Reeta");
    strcpy(arr[5].naam,"Mihit");
    strcpy(arr[6].naam,"Rajat");
    strcpy(arr[7].naam,"Rohit");
    strcpy(arr[8].naam,"Prashant");
    strcpy(arr[9].naam,"Ganesh");
    strcpy(arr[10].naam,"Santosh");
    strcpy(arr[11].naam,"medha");
    strcpy(arr[12].naam,"Jagadeesh");
    strcpy(arr[13].naam,"Shivaguru");
    int mat[6][14]= {{0,1,1,1,1,1,0,0,0,0,0,0,0,0},{1,0,1,0,0,1,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,1,0,0,0},{1,0,0,0,0,0,1,1,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,1,1,0,0,0,0},{1,1,0,0,0,0,0,0,0,0,0,1,0,0}};

    printf("\n AUTO SUGGESTIONS BASED ON YOUR CONTACT LIST :\n");
    for(i=1; i<6; i++)
    {
        for(j=6; j<14; j++)
        {
            if(mat[i][j]==1)
            {
                printf("\nYOU MAY KNOW  %s AS %s KNOWS HIM/HER .\n",arr[j].naam,arr[i].naam );
            }
        }
    }
    printf("Buffering.....");
    sleep(10);
}

int not_busy(int a[],int m,int n,int k)
{
    int c=1000,d,i=1;
    while(i<10)
    {
        if(i!=m && i!=n &&i!=k)
        {
            if(c>a[i])
            {
                c=a[i];
                d=i;
            }
        }
        i++;
    }
    return d;
}

struct infor
{
    char naam[10];
};

typedef struct infor INFOR;

///PART OF DIJKTRA'S ALGORITHM

int m(int a[],int v[])
{
    int t=9999,i,min=0;
    for(i=0; i<10; i++)
    {

        if(v[i]!=1)
        {
            if((a[i]<t) )
            {

                t=a[i];
                min=i;
            }
        }
    }
    return min;
}

///DIJKTSTRA'S ALGORITHM TO FIND NEAREST PERSOIN WITH HELP OF CURRENT LOCATION
///INPUT :NULL
///OUTPUT: AN INTEGER REPRESENTING PERSSON WHO IS NEARENS(SHORTEST NODE)

int nearest_person()
{
    int z=1000;
    printf("\n\n");
    int n=10;
    int i,u=0,cost,j,c,d;
    int v[n],dist[n];
    int mat[10][10]= {{0,1,z,2,z,4,4,15,10,z},{1,0,z,2,1,3,z,z,z,z},{z,z,0,z,z,z,z,10,11,4},{2,2,z,0,z,z,5,z,z,z},{z,1,z,z,z,5,z,z,z,z},{4,3,z,z,5,0,z,9,z,z},{4,z,z,5,z,z,0,z,8,15},{15,z,10,z,z,9,z,0,2,z},{10,z,11,z,z,z,8,2,0,5},{z,z,4,z,z,z,15,z,5,0}};
    for(i=0; i<10; i++)
    {
        v[i]=0;
        dist[i]=mat[u][i];
    }
    for(i=0; i<10; i++)
    {
        u=m(dist,v);
        v[u]=1;
        cost=dist[u];
        for(j=0; j<10; j++)
        {
            if(v[j]==0)
            {
                if (dist[j] >(cost + mat[u][j]))
                {
                    dist[j] = (cost + mat[u][j]);
                }
            }
        }
    }
    INFOR arr[11];

    ///Each person Representing a particular node
    ///Assuming there to be a server
    strcpy(arr[1].naam,"Rahul"); //
    strcpy(arr[2].naam,"James");
    strcpy(arr[3].naam,"Abdul");
    strcpy(arr[4].naam,"Reeta");
    strcpy(arr[5].naam,"Mihit");
    strcpy(arr[6].naam,"Rajat");
    strcpy(arr[7].naam,"Rohit");
    strcpy(arr[8].naam,"Prashant");
    strcpy(arr[9].naam,"Ganesh");
    strcpy(arr[10].naam,"Santosh");
    printf("\n MOST NEAREST PERSON TO YOUR CURRECNT LOCATION WHO IS ACTUALLY FREE IS %s\n",arr[not_busy(dist,1,2,3)].naam);
    printf("Buffering.....");
    sleep(10);
}

///FUNCTION TO HANDLE DOWNLOAD OPERATIONS
///INPUT: NULL
///OUTPUT : NULL, BUT IT HANDLES ALL DOWNLOADING OPERATIONS

void To_download()
{
    printf("\n\n");
    int N,choice;
    M=(MOVIE*)malloc(N*sizeof(struct movie));
    MU=(MUSIC*)malloc(N*sizeof(struct music));
    F=(FILES*)malloc(N*sizeof(struct files));
    V=(VIDEOS*)malloc(N*sizeof(struct videos));
    printf("DOWNLOAD LIST\n");
    int num=1;
    while(num)
    {
        printf("1-movie\n2-music\n3-files\n4-videos\n5-audio\n6-exit\n");
        printf("ENTER CATEGORY YOU WANT TO DOWNLOAD\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            movie_file();
            break;
        case 2:
            music_file();
            break;
        case 3:
            files();
            break;
        case 4:
            videos_file();
            break;
        case 5:
            return;
        }
    }
}

///WATCH DOWNLOAD FUNCTION
///IT DISPLAYS ALL MEDIA WHICH ARE ALREADY DOWNLOADED

void watch_downloads()
{
    printf("\n\n");
    FILE *fp;
    char name[20];
    fp=fopen("downloaded.txt","r");
    while( fscanf(fp,"%s",name)!=EOF)
    {
        printf("%s\n", name);
    }
    fclose(fp);
}

///Function:Alters the contact list based on Recently contacted to display to the end user
///doubly linked list is used here
///INPUT :null
///OUTPUT :NULL (BUT manages all the functionality)

typedef struct list
{
    struct list *e;
    struct list *f;
    int n;
    char names[10];

} ABCD;

ABCD *head=NULL;

void read1()
{
    ABCD *temp;
    int i=1;
    while(i<=peoples)
    {
        ABCD *newnode=(ABCD*)malloc(sizeof(ABCD));
        newnode->e=NULL;
        newnode->f=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->e=newnode;
            newnode->f=temp;
            temp=newnode;
        }
        newnode->n=i;
        if(i==1)
        {
            strcpy(newnode->names,"Rahul");
        }
        else if(i==2)
        {
            strcpy(newnode->names,"James");
        }

        else if(i==3)
        {
            strcpy(newnode->names,"Abdul");
        }

        else if(i==4)
        {
             strcpy(newnode->names,"Reeta");
        }

        else if(i==5)
        {
                 strcpy(newnode->names,"Mihit");
        }

        else if(i==5)
        {
              strcpy(newnode->names," ");
        }

        i++;
    }
}

void print()
{
    ABCD *curr=head;
    int i=1;
    for(i=1; i<=5; i++)
    {
        printf("%s %d\n",curr->names,curr->n);
        curr=curr->e;
    }
    printf("6- for exit");
    printf("\n");
}

void shuffle(int a)
{
    int i;
    if(a==1)
        return;
    ABCD *temp=head;
    while(temp->n !=a)
    {
        temp=temp->e;
    }
    temp->f->e=temp->e;
    temp->e->f=temp->f;
    temp->e=head;
    head->f=temp;
    temp->f=NULL;
    head=temp;

}

///FUNCTION TO HANDLE CONTACT OPERATIONS
///INPUT :NULL
///OUTPUT : NULL, BUT IT MANAGES ALL CONTACT FUNCTION

void contact()
{
    printf("\n\n");
    int choice,i;
    char contact0[10]="rahul";
    char contact1[10]="james";
    char contact2[10]="abdul";
    char contact3[10]="reeta";
    char contact4[10]="mihit";
    strcpy(d[0].name,contact0);
    strcpy(d[1].name,contact1);
    strcpy(d[2].name,contact2);
    strcpy(d[3].name,contact3);
    strcpy(d[4].name,contact4);
    read1();
    for(i=0; i<4; i++)
    {
        d[i].no=i+1;
    }
    ///Every time it shuffles based on newly typed data;
    while(1)
    {
        print();
        printf("ENTER WHITH WHOM DO YOU WANT TO MESSAGE\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            rahul();
            shuffle(choice);
            break;
        case 2:
            james();
            shuffle(choice);
            break;
        case 3:
            abdul();
            shuffle(choice);
            break;
        case 4:
            reeta();
            shuffle(choice);
            break;
        case 5:
            mihit();
            shuffle(choice);
            break;
        case 6:
            return;
        }
    }
}

///CHECKING USERNAME WITH HELP OF RABIN CARP STRING SEARCH
///INPUT : A STRING
///OUTPUT :AN INTEGER FOR CONFIRMATION

int check(char username[])
{
    char name[]="prakash";
    int val1=0,val2=0,i,k,j;
    for(i=0; i<5; i++)
    {
        k=5*name[i];
        val1=val1+k;
    }
    for(i=0; i<5; i++)
    {
        k=5*username[i];
        val2=val2+k;
    }
    i=0;
    if(val1==val2)
    {
        while(i<5 && username[i]==name[i])
        {
            i=i+1;
        }
        if(i==5)
        {
            return 1;
        }
    }
    return -1;
}

typedef struct city
{
    char name[10];

} CITY;

///FINDING CITY MATCH BY USING BRUTE FORCE STRING SEARCH APPRAOCH
///INPUT : A TEXT AND A PATTERN
///OUTPUT :AN INTEGER TO CONFIRM MATCH

int substring(char T[],char P[],int k)
{
    int i,j,n,m;
    n=strlen(T);
    m=strlen(P);
    for(i=0; i<n-m; i++)
    {
        j=0;
        while(j<m && P[j]==T[i+j])
        {
            j=j+1;
            if(j==m)
            {

                return k;
            }
        }
    }
    return -1;
}

///FLOYEDS ALGORITHM TO FIND SHOTEST PATH BETWEEN ALL NODES
///INPUT : NULL
///OUTPUT :SHORTEST PATH MATRIX

void all_shortest_path()
{

    printf("\n\n");
    int i,j,k,m=999;
    CITY c[10];

    char c1[10]="HUBLI";
    char c2[10]="ALNAVAR";
    char c3[10]="DHARWAD";
    char c4[10]="KUSUGAL";
    char c5[10]="MUGAD";
    char c6[10]="UNKAL";
    char c7[10]="BIJAPUR";
    char c8[10]="RAYAPUR";
    char c9[10]="BELAGAVI";
    char c10[10]="SHIGGAV";

    strcpy(c[0].name,c1);
    strcpy(c[1].name,c2);
    strcpy(c[2].name,c3);
    strcpy(c[3].name,c4);
    strcpy(c[4].name,c5);
    strcpy(c[5].name,c6);
    strcpy(c[6].name,c7);
    strcpy(c[7].name,c8);
    strcpy(c[8].name,c9);
    strcpy(c[9].name,c10);

    int arr[10][10]= {{0,70,m,m,m,m,m,80,m,m},{70,0,48,90,m,m,m,m,m,m},{m,48,0,m,m,m,m,m,m,m},{m,90,m,0,m,50,m,m,m,m},{m,m,m,m,0,28,m,m,m,45},{m,m,m,50,28,0,m,m,100,30},{m,m,m,m,m,m,0,20,m,m},{80,m,m,m,m,m,20,0,10,m},{m,m,m,m,m,100,m,10,0,m},{m,m,m,m,45,30,m,m,m,0}};
    printf("ENTER THE NAME OF CITY FROM WHICH YOU WANT FIND MINIMUM DISTANCE FOR ALL CITIES\n");
    char p[10];
    int b,flag=0;
    scanf("%s",p);
    for(k=0; k<10; k++)
    {
        b=substring(c[k].name,p,k);
        if(b==k)
        {
            flag=1;
            break;
        }

    }

    if(flag==0)
    {
        printf("CITY  NOT FOUND \n");
        return;
    }

    int start;
    start=b;
    for(k=0; k<10; k++)
    {
        for(i=0; i<10; i++)
        {
            for(j=0; j<10; j++)
            {
                if(arr[i][j]>(arr[i][k]+arr[k][j]))
                {
                    arr[i][j]=(arr[i][k]+arr[k][j]);
                }
            }
        }
    }
    printf("ALL SHORTEST DISTANCES FROM %s ARE \n\n",c[start].name);
    for(i=0; i<10; i++)
    {
        if(start==i)
        {
            continue;
        }
        printf(" %s TO %s IS  %d  :\n",c[start].name,c[i].name,arr[start][i]);
    }
    printf("\n\n");
    printf("Buffering.....");
    sleep(10);
}

///FUNCTION :Search User by the name provided
///INPUT :NULL
///OUTPUT :NULL

int global_count=0;

struct username
{
    char nam[20];
    char user_name[20];
};
typedef struct username UN;

UN username_list[100];
UN result[100];

void load_from_file()
{
    FILE *fp;

    fp=fopen("username.txt","r");

    if(fp==NULL)
    {
        printf("SERVER NOT FOUND!\n");
        return;
    }

    while(!feof(fp))
    {
        fscanf(fp,"%s %s",username_list[global_count].user_name,username_list[global_count].nam);
        global_count++;
    }

    fclose(fp);
}

void  search_by_user_name()
{
    load_from_file();

    char str[50];
    int n,m,i,j,k,z=0;

    printf("\nENTER USERNAME TO FIND PEOPLE: ");
    scanf("%s",str);

    for(i=0; i<global_count; i++)
    {
        n=strlen(username_list[i].user_name);
        m=strlen(str);

        for(j=0; j<n-m; j++)
        {
            k=0;

            while((k<m)&&(str[k]==(username_list[i].user_name)[j+k]))
                k++;

            if(k==m)
            {
                strcpy(result[z].user_name,username_list[i].user_name);
                strcpy(result[z].nam,username_list[i].nam);
                z++;
                break;
            }
        }
    }
    z--;

    printf("\n");

    printf("Result:\n");

    for(i=0; i<=z; i++)
    {
          printf("%s %s\n",result[i].nam,result[i].user_name);
    }


    if(z==-1)
        printf("\nUser not found!!... Try searching for other contacts :-)\n");
}

///SET UP FOR USER INTERFACE
void setup()
{
    printf("\n\n");
    printf("00 :PROFILE OF USER\n");
    printf("01 :READS THE MESSAGES FROM THE USERS\n");
    printf("02 :TEXT MESSAGES \n");
    printf("03 :DOWNLOADING MEDIA \n");
    printf("04 :WATCHING DOWNLOADS \n");
    printf("05 :AUTO SUGGESTION FOR CONTACTS\n");
    printf("06 :TO FIND NEAREST PERSON)\n");
    printf("07 :TO FIND SHORTEST DISTANCE FROM A CITY TO ALL OTHER CITIES\n");
    printf("08 :SEARCH BY USERNAME \n");
    printf("09 :SEE THE NEARBY PEOPLE AROUND YOU\n");
    printf("10 :SORTING THE CELEBRITIES BASED ON FOLLOWERS\n");
    printf("11 :FINDING MINIMUM DISTANCE SOURCE TO DESTINATION\n");
    printf("12 :TRUE CALLER BOT\n");
    printf("13 :AUTO RECOMMENDATIONS OF MEDIA\n");
    printf("14 :TO VISIT NEW SITES\n");
    printf("15 :TO ENTER INTO MINI DICTIONARY \n");
    printf("16 :TO ENTER THE CHANNELS TO BE JOINED\n");
    printf("17 :EXIT \n");
    printf("\n\n");
}

int count=0;
int global_count1=0;
struct contact
{
    char name[20];
    long long int mob_no;
    int dist;
};

typedef struct contact cont;
cont contact_list[100];

void load_from_file2()
{
    FILE *fp;

    fp=fopen("cont.txt","r");

    if(fp==NULL)
    {
        printf("SERVER NOT FOUND!\n");
        return;
    }

    while(fscanf(fp,"%s %lld %d",contact_list[global_count1].name,&contact_list[global_count1].mob_no,&contact_list[global_count1].dist)!=EOF)
    {
        global_count1++;
    }

    count = global_count1;
    fclose(fp);
}

int nearby_people()
{
    load_from_file2();

    int i,j,min;
    cont temp;

    for(i=0; i<=count-2; i++)
    {
        min=i;
        for(j=i+1; j<=count-1; j++)
        {
            if(contact_list[j].dist<contact_list[min].dist)
            {
                min=j;
            }

        }

        temp=contact_list[i];
        contact_list[i]=contact_list[min];
        contact_list[min]=temp;
    }

    for(i=0; i<count; i++)
    {
        printf("%s\t%lld\t%d\n",contact_list[i].name,contact_list[i].mob_no,contact_list[i].dist);
    }
}

typedef struct celebrity
{
    char name[100];
    int posts;
    long int followers;
    int following;

} CELEBRITY;

CELEBRITY C[100];
int count1=0;

///Function name: Loads the file
///Input: Data stored in a File
///Output: All the data in a file is copied in an structured array

void load()
{
    FILE *fp;
    int k=0;
    fp = fopen("CELEBRITIES.txt","r");
    if(fp==NULL)
    {
        printf("SERVER NOT FOUND!\n");
        return;
    }

    while(fscanf(fp,"%s %d %ld %d",C[k].name,&C[k].posts,&C[k].followers,&C[k].following)!=EOF)
    {
        k++;
    }

    count1 = k;
    fclose(fp);
}

///Function name: Swap
///Swap two elements using a temporary variable

void swap(CELEBRITY *a,CELEBRITY *b)
{
    CELEBRITY t ;
    t = *a;
    *a = *b;
    *b = t;
}

///Function name: Partition
///Input: Structure array and pivot and end element
///Output: Sorts elements in ascending order with respect to a given element in structured array

int partition(CELEBRITY C[],int l,int r)
{
    int i = 1;
    int j = r + 1;
    long int  p = C[l].followers;
    do
    {
        do
        {
            i++;
        }
        while(C[i].followers < p);

        do
        {
            j--;
        }
        while(C[j].followers > p);

        swap(&C[i],&C[j]);

    }
    while(i<j);

    swap(&C[i],&C[j]);
    swap(&C[l],&C[j]);
    return j;

}

///Function name: Quick sort
///Recursively calls quick sort 2 times and partition also

void quicksort(CELEBRITY C[],int l,int r)
{
    if(l<r)
    {
        int s;
        s = partition(C,l,r);
        quicksort(C,l,s-1);
        quicksort(C,s+1,r);
    }
}

void celebrity_sort()
{
    FILE *fp;
    load();
    quicksort(C,0,count1-1);
    for(int i=0; i<count1; i++)
    {
        printf("%s %d %ld %d\n",C[i].name,C[i].posts,C[i].followers,C[i].following);
    }
    printf("\n THE SAME IS REFLECTED IN FILE\n");
    fp = fopen("CELEBRITIES.txt","w");
    for(int i=0; i<count1; i++)
    {
        fprintf(fp,"%s %d %ld %d\n",C[i].name,C[i].posts,C[i].followers,C[i].following);
    }
    fclose(fp);
}

typedef struct graph
{
    int u;
    int v;
    int w;

} GRAPH;

int cost = 0;
GRAPH array[100];

///Function name: Bubble Sort
///Sorts the distance between any two cities in Ascending Order
///Input: Array[0..N-1] and size of array
///Output: Results in distance sorted in Ascending order

void bubble_sort()
{
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < (13 - i); j++)
        {

            if (array[j].w > array[j + 1].w)
            {
                GRAPH temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

///Function name: Find
///Input: Array a[0..N-1]
///Output: returns the element of that array

int find(int a[],int x)
{
    int g;
    g = a[x];
    return g;
}

///Function name: Union Array
///Input: Given the second element and find that array'th element of it
///Output: Copying the element of the found array and storing the required element of that particular array index

int union_arr(int a[], int u, int v)
{
    int temp = a[v];
    for (int i = 0; i < 14; i++)
    {
        if (a[i] == temp)
        {
            a[i] = a[u];
        }
    }
}

///Function name: Minimum computation
///Input: Array a[0..N-1]
///Finds two elements and if two elements are same then that set is discarded
///Output: Computes the Minimum distance of the graph

void min3()
{
    int i, j, a[50];
    for (int k = 0; k < 14; k++)
    {
        a[k] = k; //Initial values of array from 0 to N
    }

    printf("He moved from source to destination using these cities\n");
    for (int h = 0; h < 14; h++)
    {
        i = find(a,array[h].u);
        j = find(a,array[h].v);

        if (i != j)
        {
            printf("(%d %d)\n", array[h].u, array[h].v);
            cost = cost + array[h].w;
            union_arr(a, array[h].u, array[h].v);
        }

    }

    printf("The Total minimum distance computed = %d km\n", cost);
}

///Function name: Minimum constraint distance
///Input: Array a[0...N-1]
///Output: It gives a set representing the distance sum which less than constraint distance

void min1()
{

    int i, j, a[50];
    cost = 0;
    for (int k = 0; k < 14; k++)
    {
        a[k] = k; ///Initial values of array from 0 to N
    }

    printf("\nHe can move from source to destination using constraint cost distance less than 30km\n");
    for (int h = 0; h < 14; h++)
    {
        i = find(a,array[h].u);
        j = find(a,array[h].v);

        if (i != j)
        {
            if(cost<30)
            {
                printf("(%d %d)\n", array[h].u, array[h].v);
                cost = cost + array[h].w;
                union_arr(a, array[h].u, array[h].v);
            }
        }
    }
}

void kruskal_com()
{
    array[0].u = 0,array[1].u = 1,array[2].u = 2,array[3].u = 3,array[4].u =4,array[5].u = 5,array[6].u = 6;
    array[7].u = 7,array[8].u = 1,array[9].u = 7,array[10].u = 6,array[11].u = 2,array[12].u = 2,array[13].u = 3;
    array[0].v = 1,array[1].v = 2,array[2].v = 3,array[3].v = 4,array[4].v = 5,array[5].v = 6,array[6].v = 7;
    array[7].v = 0,array[8].v = 7,array[9].v = 8,array[10].v = 8,array[11].v = 8,array[12].v = 5,array[13].v = 5;
    array[0].w = 8,array[1].w = 16,array[2].w = 14,array[3].w = 18,array[4].w = 20,array[5].w = 4,array[6].w = 2;
    array[7].w = 16,array[8].w = 22,array[9].w = 14,array[10].w = 12,array[11].w = 4,array[12].w = 8,array[13].w = 28;
    bubble_sort();
    min3();
    min1();
}

///Function name: Truecaller bot
///Algorithm/DS: Boyer Moore
///Input: Mobile/Phone/Contact number (Stored numbers: 9738265937, 8651240455, 6364283908, 7876543220, 9765434232)
///Output: Name of the user

int max1(int a,int b)
{
    if(a>b)
        return a;

    else
        return b;
}

void boyer_moore(char *str,int size,int badchar[300])
{
    int i;

    for(i=0; i<300; i++)
        badchar[i]=-1;

    for(i=0; i<size; i++)
        badchar[(int)str[i]]=i;
}

void search1(char *txt,char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[300];

    boyer_moore(pat,m,badchar);

    int s=0;

    while(s<=(n-m))
    {
        int j=m-1;

        while(j>=0&&pat[j]==txt[s+j])
            j--;

        if(j<0)
        {
            printf("This number is registered with the user: ");
            printf("Rahul");
            s+=(s+m<n)?m-badchar[txt[s+m]]:1;
        }

        else
            s+=max(1,j-badchar[txt[s+j]]);
    }
}

void search2(char *txt,char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[300];

    boyer_moore(pat,m,badchar);

    int s=0;

    while(s<=(n-m))
    {
        int j=m-1;

        while(j>=0&&pat[j]==txt[s+j])
            j--;

        if(j<0)
        {
            printf("This number is registered with the user: ");
            printf("James");
            s+=(s+m<n)?m-badchar[txt[s+m]]:1;
        }

        else
            s+=max(1,j-badchar[txt[s+j]]);
    }
}

void search3(char *txt,char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[300];

    boyer_moore(pat,m,badchar);

    int s=0;

    while(s<=(n-m))
    {
        int j=m-1;

        while(j>=0&&pat[j]==txt[s+j])
            j--;

        if(j<0)
        {
            printf("This number is registered with the user: ");
            printf("Abdul");
            s+=(s+m<n)?m-badchar[txt[s+m]]:1;
        }

        else
            s+=max(1,j-badchar[txt[s+j]]);
    }
}

void search4(char *txt,char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[300];

    boyer_moore(pat,m,badchar);

    int s=0;

    while(s<=(n-m))
    {
        int j=m-1;

        while(j>=0&&pat[j]==txt[s+j])
            j--;

        if(j<0)
        {
            printf("This number is registered with the user: ");
            printf("Reeta");
            s+=(s+m<n)?m-badchar[txt[s+m]]:1;
        }

        else
            s+=max(1,j-badchar[txt[s+j]]);
    }
}

void search5(char *txt,char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);

    int badchar[300];

    boyer_moore(pat,m,badchar);

    int s=0;

    while(s<=(n-m))
    {
        int j=m-1;

        while(j>=0&&pat[j]==txt[s+j])
            j--;

        if(j<0)
        {
            printf("This number is registered with the user: ");
            printf("Mihit");
            s+=(s+m<n)?m-badchar[txt[s+m]]:1;
        }

        else
            s+=max(1,j-badchar[txt[s+j]]);
    }

}

void read_caller()
{
    char txt1[]="9738265937";
    char txt2[]="8651240455";
    char txt3[]="6364283908";
    char txt4[]="7876543220";
    char txt5[]="9765434232";

    char pat[100];

    printf("Enter the unknown number to search their names: ");
    scanf("%s",pat);

    search1(txt1,pat);
    search2(txt2,pat);
    search3(txt3,pat);
    search4(txt4,pat);
    search5(txt5,pat);
}



typedef struct avengers
{
    char data[10];
    struct avengers *next;
} AV;
typedef struct category
{
    char name[10];
} category;

AV *arr[5];
///function for list creation and loading values form respected files
///input : head
///output : head
AV* create(AV *head,int k)
{
    AV *new_node,*temp;
    temp=head;
    FILE *fp;

    if(k==1)
    {
        fp=fopen("marvel.txt","r");
    }
    else if(k==2)
    {
        fp=fopen("horror.txt","r");
    }
    else if(k==3)
    {
        fp=fopen("comedy.txt","r");
    }
    else if(k==4)
    {
        fp=fopen("biography.txt","r");
    }
    if(fp==NULL)
    {
        printf("file not found\n");
    }
    int i;
    for(i=0; i<3; i++)
    {
        AV *new_node;

        if(fp==NULL)
        {
            printf("SERVER NOT FOUND!\n");
        }
        new_node=(AV*)malloc(sizeof(AV));
        new_node->next=NULL;
        fscanf(fp,"%s",new_node->data);
        if(head==NULL)
        {
            head=temp=new_node;
            temp->next=new_node;
        }
        else
        {
            temp->next=new_node;
            temp=temp->next;
        }
    }
    fclose(fp);
    return head;
}

///func to store and print values
void recommend()
{
    printf("RECOMMENDATIONS IN DIFFERENT CATEGORIES BASED ON YOUR INTEREST ARE\n\n");
    AV *temp;
    category c[5];
    int i;
    FILE *fp;
    fp=fopen("category.txt","r");
    if(fp==NULL)
    {
        printf("SERVER NOT FOUND!\n");
    }
    for(i=0; i<4; i++)
    {
        fscanf(fp,"%s",c[i].name);
    }
    printf("ROW WISE CATEGORY NAMES\n\n");
    for(i=0; i<4; i++)
    {
        printf("%s\n",c[i].name);
    }
    printf("\n\n");
    for(i=0; i<4; i++)
    {
        temp=arr[i];
        while(temp!=NULL)
        {
            printf("%s \t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    fclose(fp);
    return;
}

///using adjacency list to store data of user interest
///input : null
///creates roots and calls func
void auto_recommendations()

{
    AV *head_1;
    AV *head_2;
    AV *head_3;
    AV*head_4;
    head_1=head_2=head_3=head_4=NULL;
    head_1=create(head_1,1);
    arr[0]=head_1;
    head_2=create(head_2,2);
    arr[1]=head_2;
    head_3=create(head_3,3);
    arr[2]=head_3;
    head_4=create(head_4,4);
    arr[3]=head_4;
    recommend();

    return;
}

typedef struct profile
{
    char pname[100];
    long long int number;
    int DOB;
    char email[100];
    char gender[5];
    char about[100];

} PROFILE;

///user profile
void profile_status(PROFILE *P)
{
    strcpy(P->pname,"PRAKASH HEGADE");
    P->number = 9964437282;
    P->DOB = 1987;
    strcpy(P->email,"prakash_hegade@kletech.ac.in");
    strcpy(P->gender,"Male");
    strcpy(P->about,"Whoop");

}

///function to update user profile
///input : profile of user
///takes choice from user and changes accordingly

void update_profile(PROFILE *P)
{
    int c,c1,D;
    long long int no;
    char tname[100],temail[100],bio[100];
    printf("ENTER 0 TO CONFIRM\n");
    scanf("%d",&c1);
    if(c1==0)
    {
        printf("\n1-Name\n2-Number\n3-Email\n4-Bio\n");
        printf("ENTER CHOICE\n");
        scanf("%d",&c);

        if(c==1)
        {
            printf("ENTER NAME YOU WANT TO CHANGE\n");
            scanf("%s",tname);
            strcpy(P->pname,tname);
        }

        if(c==2)
        {
            printf("ENTER NUMBER TO BE CHANGED\n");
            scanf("%lld",&no);
            P->number = no;
        }

        if(c==3)
        {
            printf("ENTER EMAIL TO BE CHANGED\n");
            scanf(" %[^\n]s",temail);
            strcpy(P->email,temail);
        }

        if(c==4)
        {
            printf("ENTER ABOUT PHONE TO BE CHANGED\n");
            scanf("%s",bio);
            strcpy(P->about,bio);
        }
    }
}

///user profile function
///input: null
///sets all user initial data
int x=0;
PROFILE *P;
int N,choice;
void user_profile()
{
    if(x==0)
    {
        P = (PROFILE*)malloc(sizeof(PROFILE));
        profile_status(P);
        x++;
    }

    printf("INITIAL PROFILE IN TELEGRAM\n");
    printf("NAME: %s\n",P->pname);
    printf("PHONE NUMBER: %lld\n",P->number);
    printf("DATE OF BIRTH: %d\n",P->DOB);
    printf("EMAIL : %s\n",P->email);
    printf("GENDER: %s\n",P->gender);
    printf("BIO: %s\n",P->about);
    printf("\n\n");
    printf("ENTER 1 TO UPDATE PROFILE ELSE TYPE 2 TO CONTINUE::\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\nENTER THE PROFILE THINGS TO BE CHANGED\n");
        scanf("%d",&N);
        for(int i=0; i<N; i++)
        {
            update_profile(P);
        }

        printf("\nUPDATED PROFILE\n");
        printf("NAME: %s\n",P->pname);
        printf("PHONE NUMBER: %lld\n",P->number);
        printf("DATE OF BIRTH: %d\n",P->DOB);
        printf("EMAIL: %s\n",P->email);
        printf("GENDER: %s\n",P->gender);
        printf("BIO: %s\n",P->about);
    }

    return;
}


///INSERTING,DELETING AND DISPLAYING CHANNELS IN TELEGRAM
///REOMMENDED CHANNELS ARE MARVEL,HORROR,COMEDY AND SO ON
typedef struct channels
{
    char channel[100];
    long int subscribers;
    int latest_messages;
    struct channels *next;

} CHANNEL;

CHANNEL *push(CHANNEL *top)
{
    CHANNEL *newnode,*cur = top;
    newnode = (CHANNEL*)malloc(sizeof(CHANNEL));
    if(newnode==NULL)
    {
        printf("Memory Allocation failed\n");
        return top;
    }

    printf("Enter the name of channel,subscribers and latest messages uploaded\n");
    scanf("%s%ld%d",newnode->channel,&newnode->subscribers,&newnode->latest_messages);
    newnode->next = NULL;
    if(top == NULL)
    {
        top = newnode;
        printf("You have joined this %s channel\n",newnode->channel);
        return top;
    }

    newnode->next = top;
    top = newnode;
    printf("You have joined this %s channel\n",newnode->channel);
    return top;
}

CHANNEL *search_pop(CHANNEL *top)
{
    CHANNEL *cur = top;
    printf("You have left this %s channel\n",cur->channel);
    top = top->next;
    free(cur);
    return top;
}

void display(CHANNEL *top)
{
    CHANNEL *cur = top;
    if(top == NULL)
    {
        printf("Empty list of channels\n");
    }

    printf("Details\n");
    while(cur!=NULL)
    {
        printf("%s %ld %d\n",cur->channel,cur->subscribers,cur->latest_messages);
        cur = cur->next;
    }
}

///INSERTING,DELETING AND DISPLAYING CHANNELS IN TELEGRAM
///REOMMENDED CHANNELS ARE MARVEL,HORROR,COMEDY AND SO ON
void channel_telegram()
{
    CHANNEL *top = NULL;
    int N;
    printf("Welcome to Telegram Channeling\n");
    while(1)
    {
        printf("\n1-Join\n2-Leave\n3-Display\n4-Exit\n\n");
        printf("Enter the choice\n");
        scanf("%d",&N);
        switch(N)
        {
        case 1:
            top = push(top);
            break;

        case 2:
            top = search_pop(top);
            break;

        case 3:
            display(top);
            break;

        case 4:
            return;
        }

    }
}

///LINKS WHICH REDIRECTS TO WEB PAGE
void link1()
{
    printf("Redirecting to telegram download\n");
    sleep(2);
    system("start https://play.google.com/store/apps/details?id=org.telegram.messenger");
}

void link2()
{
    printf("Redirecting to telegram desktop\n");
    sleep(2);
    system("start https://telegram.org/");
}

void link3()
{
    printf("Redirecting to telegram Wiki\n");
    sleep(2);
    system("start https://en.wikipedia.org/wiki/Telegram_(software)");
}

void link4()
{
    printf("Redirecting to telegram twitter\n");
    sleep(2);
    system("start https://twitter.com/telegram");
}

void link5()
{
    printf("Redirecting to telegram gadgets\n");
    sleep(2);
    system("start https://gadgets.ndtv.com/tags/telegram");
}

void link6()
{
    printf("Redirecting to telegram github\n");
    sleep(2);
    system("start https://github.com/DrKLO/Telegram");
}

void link7()
{
    printf("Redirecting to telegram Logo\n");
    sleep(2);
    system("start https://commons.wikimedia.org/wiki/File:Telegram_logo.svg");
}

void system_call()
{
    int choice;

    while(1)
    {
        printf("WELCOME TO REDIRECTION SYSTEM\n");
        printf("\n1-Download Telegram\n2-Telegram Messenger\n3-Telegram Wikipedia\n4-Telegram Twitter\n5-Telegram Gadgets\n6-Telegram Github\n7-Telegram Logo\n8-exit\n");
        printf("\nENTER YOUR CHOICE \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            link1();
            break;
        case 2:
            link2();
            break;
        case 3:
            link3();
            break;
        case 4:
            link4();
            break;
        case 5:
            link5();
            break;
        case 6:
            link6();
            break;
        case 7:
            link7();
            break;
        case 8:
            return;
        }

    }

    return;
}

void enter()
{
    int choice;
    INFO arr[20];
    while(1)
    {
        setup();
        printf("ENTER WHICH FUNCTIONALITY DO YOU WANT TO PERFORM :\n");
        scanf(" %d",&choice);
        switch(choice)
        {
        case 0:
            system("color 0D");
            user_profile();
            break;
        case 1:
            system("color 0C");
            check_sent_msg();
            break;
        case 2:
            system("color 0A");
            contact();
            system("cls");
            break;
        case 3:
            system("color 0B");
            To_download();
            sleep(2);
            system("cls");
            break;
        case 4:
            system("color 0C");
            watch_downloads();
            system("cls");
            break;
        case 5:
            system("color 0E");
            suggestion(arr);
            system("cls");
            break;
        case 6:
            system("color 0F");
            nearest_person();
            system("cls");
            break;
        case 7:
            system("color 01");
            all_shortest_path();
            printf("Buffering...");
            sleep(10);
            system("cls");
            break;
        case 8:
            system("color 02");
            search_by_user_name();
            printf("Buffering...");
            sleep(10);
            system("cls");
            break;
        case 9:
            system("color 03");
            nearby_people();
            printf("Buffering...");
            sleep(10);
            system("cls");
            break;
        case 10:
            system("color 04");
            celebrity_sort();
            printf("Buffering...");
            sleep(10);
            system("cls");
            break;
        case 11:
            system("color 05");
            kruskal_com();
            printf("Buffering...");
            sleep(10);
            system("cls");
            break;
        case 12:
            system("color 06");
            read_caller();
            printf("Buffering...");
            sleep(10);
            system("cls");
            break;
        case 13:
            system("color 07");
            auto_recommendations();
            printf("Buffering...");
            sleep(10);
            system("cls");
            break;
        case 14 :
            system("color 08");
            system_call();
            printf("Buffering...");
            sleep(10);
            system("cls");
            break;
        case 15:
            system("color 09");
            mini_dictionery();
            system("cls");
            break;
        case 16:
            system("color 06");
            channel_telegram();
            system("cls");
            break;
        case 17:
            exit(0);
        }
    }
}

void forgot_pass()
{
    char birthplace[20];
    int dob;
    printf("PLEASE CONFIRM YOURSELF BY ANSWERING ANY TWO QUESTIONS \n");
    printf("WHAT IS YOUR BIRTHPLACE ?  : ");
    scanf("%s",birthplace);
    printf("ENTER YOUR birth year  :");
    scanf(" %d",&dob);
    if(dob==1983 && strcmp(birthplace,"hubballi")==0)
    {
        printf("WE CONFIRMED YOU!!,  YOU HAVE ACCESS \n");
        enter();
    }
    else
    {
        printf("NO YOU HAVE NOT PASSED CONFIRMATION TEST ....\n TRY AGAIN \a\n");
    }
}

///SIMPLE  FINCTION
///INCLUDES ALL FUNCTIONALITIES
void simple()
{
    printf("\n\n");
    int a=1234,password,k;
    char username[10];
    for(int i=0; i<4; i++)
    {
        a=a+a*pow(4,i);
    }
    COORD c;
    c.X=75;
    c.Y=0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    printf("::  TELEGRAM MESSEGING   ::\n");
    c.X=75;
    c.Y=5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    printf("ENTER USERNAME: ");
    scanf("%s",username);
    k=check(username);
    if(k==-1)
    {
        printf("USERNAME NOT FOUND\n");
        return ;
    }
    c.X=75;
    c.Y=10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    printf("Enter the password ::");
    scanf("%d",&password);
    if(hash(password)!=a)
    {
        forgot_pass();
    }
    else if(hash(password)==a)
    {
        enter();
    }

}

int main()
{
    simple();
    printf("\n\n");
    return 0;
}
