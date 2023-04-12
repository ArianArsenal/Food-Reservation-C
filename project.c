#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> 
#include <conio.h> 
#include <time.h>

#include "selfStructs.h"
#include "struct.h"     //Our Student DATA are stored there

int stringCmpID(Node* current,char useridlogin[]);
int stringCmpPass(Node* current,char passwordlogin[]);
void print_list(Node *head);
void main();
void print_listMenu();
void reserveFood();
void ChargeMenu(char loginuserid[]);



void ChangePassAdmin()
{
    system("cls");
    char NewPass[20];
    char userID[20];


    printf("\nAll Users :\n------------\n\n");

    Node* c1 = head;
    int counter = 1;
    while (c1 != NULL)
    {
        
        printf("User ID %d: %s\n",counter,c1->user_id);
        counter++;
        c1 = c1->next;
    }

    printf("\n------------\n");

    printf("Enter a User ID\n");    
    scanf("%s",userID);

    Node* current = head;
    while (current != NULL)
    {
        if (stringCmpID(current,userID))   //current->user_id == loginuserid
        {
            printf("Enter Your New Password :\n");
            scanf("%s",NewPass);

            printf("\n\nUser \"%s\" Password Changed to \"%s\"\n",current->user_id,NewPass);
            Sleep(2000);

            if (strlen(current->password)<strlen(NewPass))
            {
                for (int i = strlen(current->password) ; i <= strlen(NewPass); i++)
                {
                    current->password[i] = '\0';
                }
            }
            
            else if(strlen(current->password)>strlen(NewPass))
            {
                for (int i = strlen(NewPass); i < strlen(current->password); i++)
                {
                    current->password[i] = '\0';
                }
            }

            strncpy(current->password,NewPass,strlen(NewPass));
            
            Sleep(1500);
            system("cls");

            return;
        }

        current = current->next;
    }

    printf("User Does Not Exist");
    Sleep(2000);
    return;
}

void ChangePass(char loginuserid[])     //Can Change Pass by giving the old pass and new pass
{

    char CheckPass[20];
    char NewPass[20];

    system("cls");
    printf("Your Current Password :\n");
    scanf("%s",CheckPass);

    Node* current = head;
    while (current != NULL)
    {
        if (stringCmpPass(current,CheckPass))   //current->user_id == loginuserid
        {
            printf("Enter Your New Password :\n");
            scanf("%s",NewPass);

            printf("\n\nYour Password Changed to \"%s\"\n",NewPass);
            Sleep(2000);

            if (strlen(current->password)<strlen(NewPass))
            {
                for (int i = strlen(current->password) ; i <= strlen(NewPass); i++)
                {
                    current->password[i] = '\0';
                }
            }
            
            else if(strlen(current->password)>strlen(NewPass))
            {
                for (int i = strlen(NewPass); i < strlen(current->password); i++)
                {
                    current->password[i] = '\0';
                }
            }

            strncpy(current->password,NewPass,strlen(NewPass));
            
            Sleep(1500);
            system("cls");

            return;
        }

        current = current->next;
    }

    printf("Wrong Pass !\n");
    Sleep(2000);

    system("cls");
    return;
}

struct tm* TimeHandle()             //a pointer to our local time structure
{

time_t now  = time(NULL);

char *string_now = ctime(&now);

struct tm *timePointer =localtime(&now);

return timePointer;
}

void showCurrentTime()   //when called anywhere can show you the time
{
    headtime = TimeHandle();        //use this line when you want to change the time

    if(godtime == 0)             //halate aadi godtime 0 e
    {
        printf("%d:",headtime->tm_hour);
        printf("%d\n",headtime->tm_min);
        printf("%d/",headtime->tm_year+1900);
        printf("%d/",headtime->tm_mon+1);
        printf("%d\n",headtime->tm_mday);
    }

    else if(godtime == 1)             //harja time o taghir midim godtime 1 mishe
    {
        printf("%d:",changeHour);
        printf("%d\n",changeMinute);
        printf("%d/",changeYear);
        printf("%d/",changeMonth);
        printf("%d\n",changeDay);
    }
}

void ChangeTime()
{   
    system("cls");

    showCurrentTime();
    printf("\n-------\n");
    printf("Enter The Desired Time (HH:MM YY/MM/DD):\n");
    scanf("%d:%d %d/%d/%d",&changeHour,&changeMinute,&changeYear,&changeMonth,&changeDay);

    godtime = 1;

    printf("Time Set to :\n");
    showCurrentTime();

    //
    // printf("Time Back to:\n");
    // godtime = 0;
    // showCurrentTime();

    return;
}

Self* newSelf(char SelfName[],char SelfLocation[],int SelfCapacity,char SelfType[],char SelfMeals[],int Selfid,
int lunchHour1, int lunchMinute1,int dinnerHour1,int dinnerMinute1
,int lunchHour2,int lunchMinute2,int dinnerHour2,int dinnerMinute2)
{
    Self*outself =(Self*) malloc(sizeof(Self));
    
    strcpy(outself->SelfName,SelfName);
    strcpy(outself->SelfLocation,SelfLocation);
    strcpy(outself->SelfType,SelfType);   
    strcpy(outself->SelfMeals,SelfMeals);
    outself->SelfCapacity = SelfCapacity;
    outself->Selfid = Selfid;
    
    outself->foods;

    for (int i = 0; i < 5; i++)
    {
        outself->foodCount[i] = 0;
    }
    
    // outself->foodCount[] = 0;
    outself->lunchHour1 = lunchHour1;
    outself->lunchMinute1 = lunchMinute1;
    outself->dinnerHour1 = dinnerHour1;
    outself->dinnerMinute1 = dinnerMinute1;

    outself->mealplandefined = 0;

    outself->lunchHour2 = lunchHour2;
    outself->lunchMinute2 = lunchMinute2;
    outself->dinnerHour2 = dinnerHour2;
    outself->dinnerMinute2 = dinnerMinute2;

    outself->selfyear = 0;
    outself->selfmonth = 0;
    outself->selfday = 0;

    outself->next = NULL;        

    return outself;

}

food *new_food(int foodID,char foodName[],int foodtype,double foodprice)           
{
    food *output =(food *) malloc(sizeof(food));
    output->foodID = foodID;        
    
    output->foodtype = foodtype;
    output->foodPrice = foodprice;
    // output->foodCount = 0;
    
    strcpy(output->nameFood,foodName);
    output->next = NULL;        

    return output;
}

void add_food(food *headfood, food *new_food)            
{
    food *current = headfood;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_food;
}

void add_Self(Self *selfhead, Self *new_self)           //be akharesh ezafe mishe   //struct sakhte shode va head ro migire 
{
    Self *currentself = selfhead;

    while (currentself->next != NULL)
    {
        currentself = currentself->next;
    }

    currentself->next = new_self;
}

void readFilefunc()       //test case part
{
    //final_test_case_no_invalid_input
    FILE* fppointer = fopen("test8.txt","r");

    int casenumb;
    char casecomm[20];

    // while (feof(fppointer))
    // {
        
    // }
    fscanf(fppointer,"%[^#]%d%[^#]%s",&casenumb,casecomm);
    
    printf("%d",casenumb);
    printf("%s",casecomm);
    Sleep(5000);

    return;
}

void transmit()     //shows all the datas of charges
{
    system("cls");

    Node* c1 = head;
    if (c1 ==NULL)
    {
        printf("No User Stored");
        Sleep(2000);
        system("cls");
        return;
    }
    
    char ID[20];
    printf("\nAll Users :\n");

    int counter = 1;
    while (c1 != NULL)
    {
        
        printf("User %d: %s\n",counter,c1->user_id);
        counter++;
        c1 = c1->next;
    }
    
    printf("Enter a User ID :\n");
    
    scanf("%s",ID);

    system("cls");

    Node* current = head;

    while (current != NULL)
    {
        if (stringCmpID(current,ID))
        {
            printf("Charge :%d\n",current->charge);
            printf("Currently Reserved Self: %d\n\n\n",current->self_reserveId);
            printf("Currently Reserved Food: %d\n\n\n",current->foodoption);
           
            Sleep(5000);
        }

    current = current->next;
    }

    system("cls");
}

void showAdminMenu()
{
    system("cls");
    showCurrentTime();
    
    printf("\033[1;32m");
    printf("---------\n");
    printf("\033[0m");
    printf("Registered Counter = %d\n",RegisterCounter);
    printf("\n1.Show All Registered Data\n2.add news\n3.User's Transactions\n4.Logout\n");
    printf("5.Change User's Pass\n6.Change Time\n7.Charge Student Account\n8.Define Self\n9.Define Food\n10.Define Food Plan\n11.reserve transaction\n");
    printf("\033[1;32m");
    printf("---------\n");
    printf("\033[0m");
    
    return;
}

news *new_news(char head_title[],char head_body[],int head_year,int head_month,int head_day)
{        
    news *outnews =(news *) malloc(sizeof(news));
          
    strcpy(outnews->Title ,head_title);
    strcpy(outnews->body ,head_body);

    outnews->next = NULL;
    outnews->year = head_year;
    outnews->month = head_month;
    outnews->day = head_day;

    return outnews;
}

void addNews(news *head_news, news *new_news)           //be akharesh ezafe mishe   //struct sakhte shode va head ro migire 
{
    news *currentnew = head_news;

    while (currentnew->next != NULL)
    {
        currentnew = currentnew->next;
    }

    currentnew->next = new_news;
}

void makeNews()
{
    char head_title[50];
    char head_body[300];
    int head_year,head_month,head_day;

    system("cls");

    printf("Enter The News Title :");
    fgets (head_title, 50, stdin);
    scanf ("%[^\n]%*c", head_title);

    printf("Enter The News Text :");
    fgets (head_body, 300, stdin);
    scanf ("%[^\n]%*c", head_body);

    printf("Enter The News End Date (YY/MM/DD):\n");
    scanf("%d/%d/%d",&head_year,&head_month,&head_day);
    
    if (newspublished == 0)
    {
    
        head_news = new_news(head_title,head_body,head_year,head_month,head_day);
    }

    else addNews(head_news,new_news(head_title,head_body,head_year,head_month,head_day));
    
    newspublished++;
    
    return;
}

void makeSelf()
{
    system("cls");
    
    int Selfid;                    
    char SelfName[30];         
    char SelfLocation[20];      
    int SelfCapacity;       
    char SelfType[10];          
    char SelfMeals[10];

    int lunchHour1,lunchHour2;
    int lunchMinute1,lunchMinute2;
    int dinnerHour1,dinnerHour2;
    int dinnerMinute1,dinnerMinute2;


    printf("\nEnter Self's ID:\n");
    scanf("%d",&Selfid);

    system("cls");

    printf("\nEnter Self's Name:");
    fgets(SelfName, 30, stdin);
    scanf("%[^\n]%*c", SelfName);

    system("cls");

    printf("\nEnter Self's Location:");
    fgets(SelfLocation, 20, stdin);
    scanf("%[^\n]%*c", SelfLocation);

    system("cls");

    printf("Enter Self's Capacity:\n");
    scanf("%d",&SelfCapacity);

    system("cls");

    printf("\nEnter Self's Type (boyish - girlish):\n");
    scanf("%s",SelfType);

    system("cls");

    printf("\nEnter Self's Meal Plan (lunch - dinner - both):\n");
    scanf("%s",SelfMeals);

    if (strcmp(SelfMeals,"lunch") == 0)
    {
        printf("\nEnter lunch Limit HH:MM-HH:MM:\n");
        scanf("%d:%d-%d:%d",&lunchHour1,&lunchMinute1,&lunchHour2,&lunchMinute2);
    }

    else if (strcmp(SelfMeals,"dinner") == 0)
    {
        printf("\nEnter dinner Limit HH:MM-HH:MM:\n");
        scanf("%d:%d-%d:%d",&dinnerHour1,&dinnerMinute1,&dinnerHour2,&dinnerMinute2);
    }

    else if (strcmp(SelfMeals,"both") == 0)
    {
        printf("\nEnter lunch Limit HH:MM-HH:MM:\n");
        scanf("%d:%d-%d:%d",&lunchHour1,&lunchMinute1,&lunchHour2,&lunchMinute2);

        printf("\nEnter dinner Limit HH:MM-HH:MM:\n");
        scanf("%d:%d-%d:%d",&dinnerHour1,&dinnerMinute1,&dinnerHour2,&dinnerMinute2); 
    }
    
    system("cls");
    printf("Self ID %d Created\n",Selfid);
    Sleep(2000);
    system("cls");


    if (SelfDef == 0)
    {
    
        selfhead = newSelf(SelfName,SelfLocation,SelfCapacity,SelfType,SelfMeals,Selfid,
        lunchHour1,lunchMinute1,dinnerHour1,dinnerMinute1,
        lunchHour2,lunchMinute2,dinnerHour2,dinnerMinute2);
    }

    else add_Self(selfhead,newSelf(SelfName,SelfLocation,SelfCapacity,SelfType,SelfMeals,Selfid,
    lunchHour1,lunchMinute1,dinnerHour1,dinnerMinute1,
    lunchHour2,lunchMinute2,dinnerHour2,dinnerMinute2));
    
    SelfDef++;

}

void ChargeByadmin()
{
    system("cls");

    Node* current = head;
    int counter = 1;
    while (current != NULL)
    {
        printf("\033[1;32m");
        printf("=== User %d ===",counter);
        printf("\033[0m");

        printf("\nID: %s\n",current->user_id);
        printf("Charge :%lf\n",current->charge);

        printf("\033[1;32m");
        printf("==============");
        printf("\033[0m");

        current = current->next;
        counter++;
    }
    
    char getid[20];
    printf("\n\nEnter The User's ID :\n");
    scanf("%s",getid);
    system("cls");

    double chargeamount;
    Node* Search = head;
    while (Search != NULL)
    {
        if (stringCmpID(Search,getid))
        {
            printf("Enter Charge Amount :\n");
            scanf("%lf",&chargeamount);
            system("cls");
            
            Search->charge += chargeamount;
            printf("\033[0;32m");
            printf("User");
            printf("\033[1;33m");
            printf("\" %s \"",Search->user_id);
            printf("\033[0;32m");
            printf("has been successfully charged ");
            printf("\033[1;33m");
            printf("%lf",chargeamount);
            printf("\033[0;32m");
            printf("Amount\n");
            printf("\033[0m");

            // //test
            // printf("\n\n%llu",Search->charge);
            // //teste

            Sleep(5000);
            system("cls");
            return;
        }
        
        Search= Search->next;
    }
    
    printf("User Not Found !\n");
    Sleep(2000);
    return;
}

void DefineFood()
{
    system("cls");
    int foodID;
    char foodName[20];
    int foodtype;
    double foodprice;

    printf("Enter Food ID :\n");
    scanf("%d",&foodID);

    printf("Enter Food Name :\n");
    scanf("%s",foodName);

    printf("\nEnter Food Type ( 1.Food  2.Dessert ) :\n");
    scanf("%d",&foodtype);

    printf("\nEnter Food Price :\n");
    scanf("%lf",&foodprice);

    if (fooddef == 0)
    {
    
        foodhead = new_food(foodID,foodName,foodtype,foodprice);
    }

    else add_food(foodhead,new_food(foodID,foodName,foodtype,foodprice));
    
    fooddef++;
    
    system("cls");
    printf("Food ID %d Created\n",foodID);
    Sleep(2000);
    system("cls");

    return;
}

void DefineMealPlan()
{
    int selfid;
    system("cls");

    if (selfhead == NULL )
    {
        printf("No Self Is Defined!\n");
        Sleep(2000);
        system("cls");
        return;
    }

    int counter = 1;
    Self* current = selfhead;
    while (current != NULL)
    {
        
        printf("\033[1;32m");
        printf("======");
        printf("\033[0m");

        printf("Self %d",counter);

        printf("\033[1;32m");
        printf("======");
        printf("\033[0m");

        
        printf("\nID:%d\n",current->Selfid);
        printf("Name :%s\n",current->SelfName);
        
        counter++;
        current = current->next;
    }

    printf("\n\nEnter Self ID :\n");
    scanf("%d",&selfid);
    system("cls");

    
    Self* current1 = selfhead;
    while (current1 != NULL)
    {
        if (current1->Selfid == selfid)
        {
            printf("Choose Date YY/MM/DD :\n");               //ye tarikh ke to oon tarikh oon self ke id dadim bayad ghazaye zire ro dashte bashe
            scanf("%d/%d/%d",&current1->selfyear,&current1->selfmonth,&current1->selfday);

            printf("Choose Meal Type (lunch - dinner - both):\n");
            scanf("%s",current1->SelfMeals);

            int cnt = 1;
            food* c2 = foodhead;
            system("cls");
            while (c2 != NULL)
            {
                printf("=== Food %d =====\n",cnt);
                printf("ID:%d\n",c2->foodID);
                printf("Name :%s\n",c2->nameFood);
                c2 = c2->next;
                cnt++;
            }
            
            int getfood;
            int i = 0;
            int option;

            while (option != 2)
            {
                printf("\nChoose a Food ID:\n");
                scanf("%d",&getfood);

                food* c3 = foodhead;
                while (c3 != NULL)
                {
                    if (c3->foodID == getfood)
                    {
                        printf("Enter %s Count :\n",c3->nameFood);
                    
                        strcpy(current1->foods[i],c3->nameFood);
                    
                        // scanf("%d",&c3->foodCount);
                        scanf("%d",&current1->foodCount[i]);

                        FoodsForSelf++;
                        printf("Do You want to add more food? \n1.Yes\n2.No?\n");
                        scanf("%d",&option);
                    }
                
                    c3 = c3->next;
                }
                i++;
            }
            system("cls");
            printf("Meal Plan For Self %d Created For %d/%d/%d",selfid,current1->selfyear,current1->selfmonth,current1->selfday);
            current1->mealplandefined = 1;
            Sleep(7000);
            system("cls");
            return;
        }
        

        current1 = current1->next;
    }

    system("cls");
}

void reservetransaction()
{
    system("cls");

    Self* current = selfhead;
    int cnt = 1;
    while (current != NULL)
    {
        if (current->mealplandefined == 0)
        {
            current = current->next;
        }

        printf("\n==== Self %d ====\n",cnt);
        printf("Name : %s\n",current->SelfName);
        printf("ID : %d\n",current->Selfid);
        printf("Meal Type : %s\n",current->SelfMeals);
        printf("Capacity :%d\n",current->SelfCapacity);

        for (int i = 0; i < FoodsForSelf; i++)
        {
            printf("Food %s Left:%d\n",current->foods[i],current->foodCount[i]);
            
        }
        
        current = current->next;
        cnt++;
    }

    if (current == NULL)
    {
        system("cls");
        printf("No Data Stored");
        Sleep(2000);
        system("cls");
        return;
    }

    Sleep(10000);
    system("cls");
    return;
}

void menu2()
{
    int menu2;

    system("cls");

    while (1)
    {
        system("cls");
        showAdminMenu();
        scanf("%d",&menu2);
        
        if (menu2 == 1)
        {
            if (head == NULL)
            {
                system("cls");
                printf("No Data is Stored.\n");
                Sleep(3500);
                system("cls");
                continue;
            }
            
            print_list(head);
            //approve statue
            print_listMenu();
        }
        
        else if (menu2 == 2)
        {
            makeNews();
        }

        else if (menu2 == 3)
        {
            transmit();
        }

        else if (menu2 == 4)
        {
            system("cls");
            printf("Logout Succesfull\n");
            adminStatus = 0;
            admin2Status = 0;
            Sleep(2000);
            system("cls");
            main();
        }

        else if (menu2 == 5)
        {
            ChangePassAdmin();
        }

        else if (menu2 == 6)
        {
            ChangeTime();
        }

        else if (menu2 == 7)
        {
            ChargeByadmin();
        }

        else if (menu2 == 8)
        {
            makeSelf();
        }

        else if (menu2 == 9)
        {
            DefineFood();
        }

        else if (menu2 == 10)
        {
            DefineMealPlan();
        }

        else if (menu2 == 11)
        {
            reservetransaction();
        }
        
    }
}

int checkReserveGender(char genderUser[],char genderSelf[])
{
    if (strcmp(genderSelf,"boyish")== 0 && strcmp(genderUser,"male") == 0)
    {
        return 1;
    }
    else if(strcmp(genderSelf,"girlish")== 0 && strcmp(genderUser,"female") == 0)
    {
        return 1;
    }
    else return 0;

}

int checkreservetime(Self* now)
{
    if (godtime == 1)
    {
        if ( ( (changeDay + 2 <= now->selfday) && (changeMonth <= now->selfmonth) && (changeYear == now->selfyear ) && (now->selfday - changeDay <= 14) ) )
        {
            return 1;
        }
        else return 0;
    }

    else if (godtime == 0)
    {   
        if ( ( (headtime->tm_mday + 2 <= now->selfday) && (headtime->tm_mon + 1 <= now->selfmonth) && (headtime->tm_year +1900 == now->selfyear ) && (now->selfday - headtime->tm_mday <= 14) ) )
        {
            return 1;
        }
        else return 0;
    }

    else return 0;
    
}

void checkIfreserve(Node* current,Self* now,food* alan)
{
    if ((current->charge >= alan->foodPrice ))
    {
        if ((checkReserveGender(current->gender,now->SelfType) == 1 ))
        {
            if ((checkreservetime(now) == 1))
            {
                if (latereserve == 1)
                {
                    if (godtime == 0 &&( now->dinnerMinute1 - 30 >= headtime->tm_min || now->lunchMinute1 -30 >= headtime->tm_min)
                     ||(godtime == 1 &&( now->dinnerMinute1 - 30 >= changeMinute || now->lunchMinute1 -30 >= changeMinute ) ))
                    {
                        current->charge -= 2 * alan->foodPrice;
                    }
                }
                

                else current->charge -= alan->foodPrice;

                current->self_reserveId = now->Selfid;
                current->foodoption = alan->foodID;
                now->SelfCapacity -= 1;

                int i = 0;
                while (strcmp(now->foods[i],alan->nameFood) != 0)
                {
                    i++;
                }
                
                now->foodCount[i] -= 1;
                
                // //
                // printf("Count %s:%d\n",now->foods[i],now->foodCount[i]);
                // Sleep(5000);
                // //

                latereserve = 0;
                system("cls");
                printf("Reserve Successful\n");
                Sleep(5000);
                return ;
            }
            
            else
            { 
                latereserve = 0;
                printf("Can't Reserve at this time\n");
                Sleep(3000);
                return;
            }
        }

        else
        { 
            printf("This Self Doesn't Match Your Gender\n");
            Sleep(3000);
            return;
        }
    }

    else {
        printf("You Don't Have Enough Credit\n");
        Sleep(3000);
        comefromreserve = 1;
        ChargeMenu(current->user_id);
    }
}
    
void reserveFood(char loginuserid[])
{   
    system("cls");
    int cnt = 1;
    char chooseFoodOption[20];
    int chooseSelfID;

    Self* current = selfhead;
    system("cls");
    while (current != NULL)
    {   
        if (current->mealplandefined == 0)
        {
            current = current->next;
        }
        
        printf("\n==== Self %d ====\n",cnt);
        printf("Name : %s\n",current->SelfName);
        printf("ID : %d\n",current->Selfid);
        printf("Meal Type : %s\n",current->SelfMeals);

        printf("Food Options :\n");
        
        for (int i = 0; i < FoodsForSelf; i++)
        {
            if (current->foods[i] == NULL)
            {
                break;
            }
            
            printf("Option %d:%s\n",i+1,current->foods[i]);
        }

        cnt++;
        current = current->next;
    }

    printf("\n\nChoose Self:\n");
    scanf("%d",&chooseSelfID);

    system("cls");

    Self* now = selfhead;
    while (now!= NULL)
    {
        if(now->Selfid == chooseSelfID)
        {
            Self* test = selfhead;
            for (int i = 0; i < FoodsForSelf; i++)
            {
                if (test->foods[i] == NULL)
                {
                    break;
                }
            
                printf("Option :%s\n",test->foods[i]);
            }

            printf("\nEnter Food Name :\n");
            scanf("%s",chooseFoodOption);

            food* furrent = foodhead;
            while (furrent != NULL)
            {
                if (strcmp(chooseFoodOption,furrent->nameFood) == 0)
                {
                    Node* id = head;
                    while (id != NULL)
                    {
                        if (stringCmpID(id,loginuserid))
                        {
                            id->self_reserveId = now->Selfid;
                            checkIfreserve(id,now,furrent);
                        }

                        id = id->next;
                    }
                    
                }

                furrent = furrent->next;
            }

        }

        now = now->next;
    }
}

int checkCharge(char loginuserid[],int inputcharge)     //to check if the charge is enough or not
{
    Node* current = head;

    while (current != NULL)
    {
        if (stringCmpID(current,loginuserid))
        {
            if (current->charge >= inputcharge)
            {
                return 1;       //1 == charge is enough
            }
            else return 0;    //0 yani charge to hesab kamtar az inpute
        }
        
        current = current->next;
    }
}

void ChargeMenu(char loginuserid[])
{
    system("cls");
    int chargeOption;
    printf("Choose Option :\n--------\n");
    printf("1.Charge My Account\n2.Charge Other Accounts\n");
    scanf("%d",&chargeOption);

    Node* c2 = head;

    while (c2 != NULL)
    {
        if (stringCmpID(c2,loginuserid))
        {
            break;
        }
        c2 = c2->next;
    }

    if (chargeOption == 1)
    {
        system("cls");
        printf("Enter The Charge Price :\n");
        double chargeget;
        scanf("%lf",&chargeget);

        printf("Enter Credit Card info :\n");
        char card[20];
        scanf("%s",card);
        system("cls");

        printf("Your Account was successfully Charged %lf Toman\n",chargeget);
        Sleep(2000);
        system("cls");

        c2->charge += chargeget;

        if (comefromreserve == 1)
        {
            return;
        }
        
    }
    
    else if (chargeOption == 2)
    {
        system("cls");
        printf("Enter the User You want to send Charge to\n");

        char getuserid[20];

        scanf("%s",getuserid);

        Node* current = head;

        while (current != NULL)
        {
            if (stringCmpID(current,getuserid)) //peyda kardan oon user to user ha
            {
                printf("Type the amount of Charge You want to send:\n");
                double getcharge;
                scanf("%lf",&getcharge);
                system("cls");

                if(checkCharge(loginuserid,getcharge))
                {
                    printf("Successful\n");
                    current->charge += getcharge;
                    c2->charge -= getcharge;
                    
                    printf("The Sent User:\n");
                    printf("%s",current->user_id);
                    printf("%s %s",current->name,current->lastname);

                    printf("\033[1;32m");
                    printf("----------------\n");
                    printf("\033[0m");
                    printf("Your Charge Left:%lf\n",c2->charge);

                    Sleep(7500);
                    return;
                }

                else
                {
                    printf("Not Enough Charge\n");
                    Sleep(2000);
                    system("cls");
                }
            }

            current = current->next;
        }

        printf("\nUser Does Not Exist!\n");
        Sleep(2000);
        system("cls");
        return;
    }
    
    else 
    {
        printf("Wrong Input\n");
        Sleep(2000);
        return;
    }

}

void showCurrentCharge(char loginuserid[])
{
    Node* current = head;

    while (current != NULL)
    {
        if (stringCmpID(current,loginuserid))
        {
            printf("Charge :%lf\n",current->charge);
            return;
        }
        current = current->next;
    }
}

void takefood(char loginuserid[])
{

    Node * student = head;
    int wanttotake;

    while (student != NULL)
    {
        if (stringCmpID(student,loginuserid))
        {
            Self* current = selfhead;
            while (current != NULL)
            {
                if (current->Selfid == student->self_reserveId)
                {
                    printf("Do you want to take your food?\n1.Yes\n2.No\n");
                    scanf("%d",&wanttotake);

                    if (wanttotake == 1)
                    {
                        system("cls");
                        printf("Enjoy");
                        Sleep(2000);
                        system("cls");
                        student->self_reserveId = 0;
                        return;
                    }
                    else return;
                }
                else
                { 
                    system("cls");
                    printf("No reserved Plan");
                    Sleep(2000);
                    return;
                }

                current = current->next;
            }
            
        }
        student = student->next;
    }
    
    printf("No reserved Plan");
    Sleep(2000);
    return;
    

}

void showreserveplan(char loginuserid[],Node* student)
{
    int cnt = 1;
    Self* current = selfhead;
    while (current != NULL)
    {


        printf("\n\n=== Self %d ===\n",cnt);
        printf("Name : %s\n",current->SelfName);
        printf("ID : %d\n",current->Selfid);
        printf("Date : %d/%d/%d\n",current->selfyear,current->selfmonth,current->selfday);

        if (student->self_reserveId == current->Selfid)
        {
            printf("Reserve Status : 1");
        }
        else printf("Reserve Status : 0");
    
        cnt++;
        current = current->next;
    }

    Sleep(7000);
    system("cls");
    return;
    
}

void takefoodReport()
{   
    system("cls");
    int garbage;
    char trash[20];
    printf("Enter The Self you reserved");
    scanf("%d",&garbage);

    printf("Enter The Time you ordered your food");
    scanf("%d:%d",&garbage,&garbage);
    printf("Enter The food you ordered");
    scanf("%s",trash);

    printf("Thank You");
    Sleep(2000);
    system("cls");
    return;

}

void showStudentMenu(char loginuserid[])
{
    system("cls");

    showCurrentTime();

    showCurrentCharge(loginuserid);

    printf("\033[1;32m");
    printf("---------\n");
    printf("\033[0m");
    printf("1.Reserve Food\n2.Take Food\n3.Change Password\n4.Charge\n");   //charge and send charge

    printf("5.Show Reserved Plan\n6.Check News\n7.Cancel reserve\n8.daily reserve\n9.Logout");

    printf("\n10.Change Time\n11.Take Food Report\n");
    printf("\033[1;32m");
    printf("---------\n");
    printf("\033[0m");

    return;
}

long long int foodprice(Node * student)
{
    food* current = foodhead;
    while (current != NULL)
    {
        if (student->foodoption == current->foodID)
        {
            return current->foodPrice;
        }
        current = current->next;
    }
}

int checkCancelTime(Self* cancel)
{
    if (godtime == 0)
    {
        if ((headtime->tm_hour <= cancel->lunchHour1 -1 ) || (headtime->tm_hour <= cancel->dinnerHour1 -1) )
        {
           return 1;
        }

        else return 0;
        
    }
    
    else if (godtime == 1)
    {
        if ((changeHour <= cancel->lunchHour1 -1)||(changeHour <= cancel->dinnerHour1 -1 ))
        {
            return 1;
        }
        
        else return 0;
    }

    else return 0;
}

void cancelreserve(char loginuserid[],Node* test)
{

    int cnt = 1;
    Self* current = selfhead;

    system("cls");

    while (current != NULL)
    {
        printf("\n\n=== Self %d ===\n",cnt);
        printf("Name : %s\n",current->SelfName);
        printf("ID : %d\n",current->Selfid);
        printf("Date : %d/%d/%d\n",current->selfyear,current->selfmonth,current->selfday);

        if (test->self_reserveId == current->Selfid)
        {
            printf("Reserve Status : 1");
        }
        cnt++;
        current = current->next;
    }

    int getid;
    printf("\n\nEnter The Self ID you want to Cancel :\n");
    scanf("%d",&getid);

    Self* cancel = selfhead;
    while (cancel != NULL)
    {
        if (cancel->Selfid == getid)
        {
            if (checkCancelTime(cancel))
            {
                test->self_reserveId = 0;
                test->charge += (9.0/10.0) * foodprice(test);
                printf("Meal %d Canceled",getid);
                printf("%.2lf Charge Returned to your account\n",(9.0/10.0) * foodprice(test));
                Sleep(5000);
                system("cls");
                return;
            }

            else 
            {
                system("cls");
                printf("You Can't Cancel at this time\n");
                Sleep(3000);
                system("cls");
                return;

            }
        }
        cancel = cancel->next;
    }

    printf("No Data Found");
    Sleep(7000);
    system("cls");
    return;
}

void dailyreserve(char loginuserid[])
{
    Node* current = head;   
    while(current!= NULL)
    {
        if (stringCmpID(current,loginuserid))
        {
            if (current->self_reserveId == 0)
            {
                latereserve = 1;
                reserveFood(loginuserid);
                latereserve = 0;
            }
        }
        current = current->next;
    }


}

void menu3(char loginuserid[])
{
    int menu3;

    system("cls");

    while (1)
    {
        showStudentMenu(loginuserid);
        scanf("%d",&menu3);
        
        if (menu3 == 1)
        {   
            reserveFood(loginuserid);
        }
        
        else if (menu3 == 2)
        {
            takefood(loginuserid);
        }

        else if (menu3 == 3)
        {
            ChangePass(loginuserid);
        }

        else if (menu3 == 4)
        {
            ChargeMenu(loginuserid);
        }

        else if(menu3 == 5)
        {
            system("cls");
            Node* student = head;
            while (student!=NULL)
            {
                if (stringCmpID(student,loginuserid))
                {
                    showreserveplan(loginuserid,student);
                }
                student = student->next;
            }
        }

        else if (menu3 == 6)
        {
            system("cls");

            news* currentnews = head_news;
            if (head_news->Title == NULL)
            {
                printf("There is No News For now ");
                Sleep(1000);
                system("cls");
                showStudentMenu(loginuserid);
            }

            else
            {   
                int newscnt = 1;
                while (currentnews != NULL)
                {
                    if ((headtime->tm_mon + 1 <= currentnews->month || (changeMonth <=currentnews->month && godtime == 1 ))
                    && (headtime->tm_mday <= currentnews->day || (changeDay <= currentnews->day && godtime == 1 )))
                    {
                        printf("\nNews %d :\n",newscnt);

                        printf("\033[1;31m");
                        printf("======%s======\n",currentnews->Title);
                        printf("\033[0m");

                        printf("%s\n",currentnews->body);

                        printf("\033[1;32m");
                        printf("\n\nEnd Date : %d/%d/%d\n\n=============\n\n",currentnews->year,currentnews->month,currentnews->day);
                        printf("\033[0m");
                    }
                    newscnt++;
                    currentnews = currentnews->next;
                }

                int newsReturn;
                printf("1.Return\n");
                scanf("%d",&newsReturn);
                if(newsReturn == 1)
                {  
                    Sleep(2000);
                    system("cls");
                    showStudentMenu(loginuserid);
                }
                else Sleep(3000);
            }
        }

        else if(menu3 == 7)
        {
            
            Node* test = head;
            while (test!=NULL)
            {
                if (stringCmpID(test,loginuserid))
                {
                    cancelreserve(loginuserid,test);
                }
                test = test->next;
            }

            
        }

        else if (menu3 == 8)
        {
            system("cls");
            dailyreserve(loginuserid);
        }

        else if (menu3 == 9)
        {
            system("cls");
            printf("Logout Succesfull\n");
            Sleep(2000);
            system("cls");
            main();
        }

        else if (menu3 == 10)
        {
            system("cls");
            ChangeTime();
        }

        else if (menu3 == 11)
        {
            system("cls");
            takefoodReport();
        }



    }
}

Node *new_node(char Name[],char lastName[],char password[],char userID[],
char gender[],int birthYear,int birthMonth,int birthDay,
unsigned long long id)           
{
    Node *output =(Node *) malloc(sizeof(Node));

    strcpy(output->name,Name);

    strcpy(output->lastname,lastName);
    
    strcpy(output->user_id,userID);

    strcpy(output->password,password);
    
    strcpy(output->gender,gender);

    output->self_reserveId = 0;
    output->charge = 0;

    output->foodoption = 0;
    output->birth_year = birthYear;
    output->birth_month = birthMonth;
    output->birth_day = birthDay;
    output->approved = 0;       //if 0 means not registered if 1 means aprroved by admin
    output->id = id;
    output->next = NULL;

    FILE* fp2usersinput = fopen("studentsinfo.txt","r");

    if(feof(fp2usersinput))
    {
        FILE* fpusersinput = fopen("studentsinfo.txt","w");

        fprintf(fpusersinput,"%s\n",Name);
        fprintf(fpusersinput,"%s\n",lastName);
        fprintf(fpusersinput,"%s\n",password);
        fprintf(fpusersinput,"%s\n",userID);
        fprintf(fpusersinput,"%s\n",gender);
        fprintf(fpusersinput,"%d/%d/%d\n",birthYear,birthMonth,birthDay);

        fclose(fpusersinput);
    }
    else
    {
        FILE* fpusersinput = fopen("studentsinfo.txt","a");

        fprintf(fpusersinput,"%s\n",Name);
        fprintf(fpusersinput,"%s\n",lastName);
        fprintf(fpusersinput,"%s\n",password);
        fprintf(fpusersinput,"%s\n",userID);
        fprintf(fpusersinput,"%s\n",gender);
        fprintf(fpusersinput,"%d/%d/%d\n",birthYear,birthMonth,birthDay);

        fclose(fpusersinput);
    }

    return output;
}

void addNode(Node *head, Node *new_node)       
{
    Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;

    return;
}

int listLen(Node* head)                 //list length
{
    int len = 0;
    Node* current = head;

    while (current != NULL)
    {
        len++;

        current = current->next;
    }
    
    return len;
}

void removeIndex(Node** head ,int index)
{
    system("cls");
    Node* current = *head;

    if (index == 1)
    {
        *head = (*head)->next;
        free(current);
        return;
    }

    int counter = 0;
    while (counter < index)
    {
        if (current == NULL)
        {
            printf("Wrong Input");
            return;
        }
        current = current->next;
        counter++;
    }

    Node* hold = current->next;

    current->next = current->next->next;

    free(hold);

    return;
}

void print_listMenu()
{
    
    int printReturn;
    printf("\033[1;32m");
    printf("---------\n");
    printf("\033[0m");
    printf("1.Return\n");
    
    if (adminStatus != 0)
    {
        printf("\n---------\n");
        printf("Admin's Options\n\n");
        
        printf("2.Approve\n3.Remove Member\n4.Deactivate Member\n5.Approve as Admin\n");
        printf("---------\n");
    }
    
    scanf("\n%d",&printReturn);

    if (printReturn == 1)
    {
        system("cls");
        return;
    }

    else if (adminStatus != 0 && printReturn == 2)      //approve
    {
        
        char ID[20];
    
        printf("\nEnter The ID:\n");
        scanf("%s",ID);

        Node* current = head;

        while (current != NULL)
        {
            if (stringCmpID(current,ID))
            {
                current->approved = 1;
                system("cls");
                printf("Approved\n");
                Sleep(2000);
                break;
            }
            current = current->next;
        }

        system("cls");
    }

    else if (adminStatus != 0 && printReturn == 3)      // delete node
    {
        
        int index;
        printf("Enter The Index:\n");
        scanf("%d",&index);

        system("cls");
        printf("Are You Sure You Want to Remove User?\n");
        printf("1.Yes\n2.No\n");
        int yesNo;
        scanf("%d",&yesNo);

        if (yesNo == 1)
        {
            removeIndex(&head,index);
            RegisterCounter--;
        }

        else 
        {
            system("cls");
            return;
        }
    }

    else if (adminStatus != 0 && printReturn == 4)  //deactivate
    {
        
        char ID[20];
        system("cls");
        printf("Enter The ID:\n");
        scanf("%s",ID);
        
        Node* current = head;

        while (current != NULL)
        {
            if (stringCmpID(current,ID))
            {
                current->approved = -1;
                return;
            }
            current = current->next;
        }
        
    }

    else if (admin2Status = 0 && adminStatus != 0 && printReturn == 5)      //approve as admin
    {
        char ID[20];
        system("cls");
        printf("Enter The ID:\n");
        scanf("%s",ID);
        
        Node* current = head;

        while (current != NULL)
        {
            if (stringCmpID(current,ID))
            {
                current->approved = 2;
                return;
            }
            current = current->next;
        }
    }

    else
    {
        system("cls");
        return;
    }
}

int checkAdmin(char useridlogin[],char passwordlogin[])
{
    int i = strcmp(useridlogin,"admin");
    int j = strcmp(passwordlogin,"admin");

    if (i == 0 && j == 0)
    {
        return 1;
    }
    else return 0;
}

void print_list(Node *head)
{
    int counter = 1;
    

    Node *current = head;
    system("cls");

    if (head->user_id == NULL)
    {
        system("cls");
        printf("No Data is Stored.\n");
        Sleep(2000);
        system("cls");
        return;
    }
     
    while (current!= NULL)
    {

        if (current->approved == -2)
        {
            system("cls");
            //printf("test");
            if (current->next = NULL)
            {
                current = current->next;
            }
            else break;
        }
    
        printf("\033[1;32m");
        printf("\n=== Member");
        printf("\033[0m");
        printf("%d",counter);
        printf("\033[1;32m");
        printf("===\n");
        printf("\033[0m");

        printf("Name: %s\n",current->name);
        printf("Lastname: %s\n",current->lastname);

        printf("User ID: %s\n",current->user_id);

        //printf("password: %s\n",current->password);

        printf("Password:");
        for (int i = 0; i<strlen(current->password) ; i++)
        {
            printf("%c", current->password[i]);
        }
        //printf("%s",current->password);
    
        
        printf("\nGender: %s\n",current->gender);
        printf("Birth: %d/%d/%d\n",current->birth_year,current->birth_month,current->birth_day);
        printf("Approved Status: %d",current->approved);

        current = current->next;
        counter++;
        printf("\n");
    }
    
    printf("\n\n\n");
}

int checkIfApproved(char userID[])      //check if approved or not
{
    Node* current = head;

    while (current != NULL)
    {
        if (stringCmpID(current,userID) == 1)  //current->user_id == userID)
        {
            if (current->approved == 1)
            {
                return 1;
            }
            else return 0;
        }
        
        current = current->next;
    }

}

void getInfo()
{
    char head_name[15];
    char head_lastname[15];
    char head_user_id[20];
    char head_password[20];
    char head_gender[6];

    int head_birth_year;
    int head_birth_month;
    int head_birth_day;
    unsigned long long head_id;

    // if (feof(fpusersinput) || fpusersinput == NULL)
    // {
    //     printf("yes");
    //     Sleep(3000);
    
    // }
    
        
    system("cls");

    printf("Enter Your information\n");
    
    printf("Name : \n");
    scanf("%s",head_name);

    printf("Lastname : \n");
    scanf("%s",head_lastname);

    system("cls");

    printf("Password: \n");         
    scanf("%s",head_password);

    printf("User ID: \n");
    scanf("%s",head_user_id);
    
    printf("Gender: \n");
    scanf("%s",head_gender);

    printf("Birth YY/MM/DD : \n");
    scanf("%d/%d/%d",&head_birth_year,&head_birth_month,&head_birth_day);

    printf("National ID :\n");
    scanf("%llu",&head_id);

    system("cls");

    
    if (RegisterCounter == 0)
    {
    
        head = new_node(head_name,head_lastname,head_password,head_user_id,
        head_gender,head_birth_year,head_birth_month,head_birth_day,
        head_id);
    }

    else addNode(head,new_node(head_name,head_lastname,head_password,head_user_id
    ,head_gender,head_birth_year,head_birth_month,head_birth_day,
    head_id));
    
    system("cls");

    printf("\nThanks for your time, you'll soon be confirmed ;)\n");

    RegisterCounter++;

    Sleep(5000);
    system("cls");

    return;
}

int stringCmpPass(Node* current,char passwordlogin[])
{

    int i = strncmp(current->password,passwordlogin,strlen(current->password));

    if (i == 0)
    {
        return 1;
    }
    
    else return 0;

}

int stringCmpID(Node* current,char useridlogin[])
{
    int i = strncmp(current->user_id,useridlogin,strlen(current->user_id));

    if (i == 0)
    {
        return 1;
    }
    
    else return 0;
}

void showMenuAll()
{
    printf("\033[1;32m");
    printf("---------\n");
    printf("\033[0m");
    printf("1.Register\n2.Login\n3.Exit\n");
    printf("\033[1;32m");
    printf("---------\n");
    printf("\033[0m");
    return;
}

int SearchInfoID(Node* head,char useridlogin[])         //find the index of a given value
{

    Node* current = head;

    while (current != NULL)
    {
        if ( stringCmpID(current,useridlogin) ) //current->user_id == useridlogin 
        {
            return 1;       //if returns 1 = user vojod dare
        }

        current = current->next;
    }

    return -1;          //if returns -1 = user nist asan  so kolan print mikone doesn't exist

}

int SearchInfoPassword(Node* head,char passwordlogin[])         //find the index of a given value
{
    Node* current = head;

    while (current != NULL)
    {
        if (stringCmpPass(current,passwordlogin) == 1)
        {
            return 1;       //if returns 1 = password doroste --> Login succsesful
        }
        

        current = current->next;
    }

    return -1;          //if returns -1 = Password ghalate --> Try Again
}

void Login(char useridlogin[],char passwordlogin[])
{
    system("cls");
    
    Node* current = head;

    if (checkAdmin(useridlogin,passwordlogin))
    {
        printf("Login Successful\n");
        adminStatus++;
        Sleep(3000);
        menu2();
    }

    else if (SearchInfoID(head,useridlogin) == 1 && SearchInfoPassword(head,passwordlogin) == 1)
    {
        
        if (checkIfApproved(useridlogin) == 1)
        {
            system("cls");
            printf("Logged in");
            Sleep(2000);
            menu3(useridlogin); //student menu
            //show menu
            //sends to page for checking if its student or admin
            //tabe menu login 
            //check if student or not
        }

        else if (current->approved == -1)
        {   
            printf("You Don't Have Permission to Log in");
            Sleep(2000);
            system("cls");
            return;
        }

        else if (current->approved == -2)
        {   
            printf("User Does Not Exist\n");
            Sleep(2000);
            system("cls");
            return;
        }

        else if (current->approved == 2)
        {
            printf("Logged in as admin\n");
            admin2Status++;
            Sleep(2000);
            menu2();
        }
    
        else printf("Sorry You Are Not Approved Yet.\n");
        Sleep(3500);
        return;
    }

    else if ( SearchInfoID(head,useridlogin) == 1 && SearchInfoPassword(head,passwordlogin) == -1)
    {
        printf("Wrong Password. Try Again\n");
        Sleep(2000);
        return;
    }

    else printf("User Does Not Exist !\nDo You Want to Register?\n1.Yes\n2.No\n");

    int wantToRegister;

    scanf("%d",&wantToRegister);

    if (wantToRegister == 1)
    {
        getInfo();
    }

    else return;
    
}

int k = 0;

void Begin()
{
    int begin;
    system("cls");
    
    printf("\033[1;32m");
    printf("---------\n");
    printf("\033[0m");

    printf("1.Menu\n2.Test Case\n");
    
    printf("\033[1;32m");
    printf("---------\n");
    printf("\033[0m");

    scanf("%d",&begin);

    if(begin == 2)
    {
        readFilefunc();
    }
    else k = 1;
    return;

}

void main()
{
    int menu;
    //readFileAdmin();
    if (k == 0){
    Begin();
    }
    
    system("cls");

    while (1)
    {   
        showCurrentTime();

        showMenuAll();

        scanf("%d",&menu);
    
        if (menu == 1)
        {
            getInfo();
        }

        //login menu sends us to the Login function
        else if (menu == 2)
        {
            system("cls");
            char useridlogin[20];
            char passwordlogin[20];

            printf("\nEnter Your Login Details\n");
            

            printf("User ID :");
            scanf("%s",useridlogin);

            printf("Password :");
            scanf("%s",passwordlogin);

            Login(useridlogin,passwordlogin);       //sends to check if exists
        }
       
        else if (menu == 3)
        {
            k = 0;
            main();
        }
        
        else 
        {
            system("cls"); 
            printf("Wrong Input ! Try Again"); 
            Sleep(2000);
        }

        system("cls");
    }

}

