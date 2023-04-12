
int RegisterCounter = 0;
int adminStatus = 0;
int admin2Status = 0;
int newspublished = 0;

int changeHour;
int changeMinute;
int changeYear;
int changeMonth;
int changeDay;

int godtime = 0;        //aval 0 e


//Our Student's Information
typedef struct TestNew
{
    char name[15];
    char lastname[15];
    char user_id[20];
    
    char gender[6];

    char password[20];
    
    int birth_year;
    int birth_month;
    int birth_day;

    double charge;
    int self_reserveId;
    int foodoption;
    
    unsigned long long id;        //national id
    int approved;     //if 0 means not registered if 1 means aprroved by admin
                        //-1 means deactive //if -2 means removed
                        // 2 promote to admin
    struct TestNew * next;

}Node;

// news struct
// make with malloc size of news
typedef struct akhbar
{
    char Title[50];

    char body[300];

    int year;
    int month;
    int day;

    struct akhbar* next;

}news;

Node * head;
struct tm* headtime;
news* head_news;