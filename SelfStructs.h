int SelfDef = 0;
int fooddef = 0;

int FoodsForSelf = 0;
int comefromreserve = 0;
int latereserve = 0;

typedef struct SelfStructs
{
    int Selfid;                    //self id bara sefaresh -> mire to struct student (reserved_selfid)
    char SelfName[30];          //name

    char SelfLocation[20];      //taghir self

    int SelfCapacity;       //ba kharid azash capacity -1 mishe va ba pass dadan capacity +1 mishe

    char SelfType[10];          //bayad ba Gender check she 

    char SelfMeals[10];                //vaade ghazaii    nahar  sham    both

    char foods[5][20];
    int foodCount[5];
    int makeMealfoodscount;
    
    int mealplandefined;

    int lunchHour1;
    int lunchMinute1;
    int dinnerHour1;
    int dinnerMinute1;

    int lunchHour2;
    int lunchMinute2;
    int dinnerHour2;
    int dinnerMinute2;

    int selfyear;
    int selfmonth;
    int selfday;

    struct SelfStructs* next;

}Self;

typedef struct testfood     //define food menus joda dare
{
    char nameFood[20];                   //har ozve linked list ye ghazae hala mitoone desser bashe ya food
    int foodID;                                
    double foodPrice;
    //int foodCount;
    int foodtype;               //if 1 means food      if 2 means dessert

    struct testfood* next;

}food;

Self* selfhead;
food* foodhead;
