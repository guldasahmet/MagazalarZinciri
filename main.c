#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define S 5
#define P 10
#define W 4

struct worker{
    char name[50];
    char surname[50];
    int age;

};

struct product{
    long ref_code;
    int price;

};

typedef struct{
  char name[50];
  char street[50];
  char nbhood[50];
  char gsm[25];
  long earned_money;
  struct product products[10];
  struct worker workers[4];

}shop_data;


void shop_create(shop_data *s);
void product_create(struct product *p);
void worker_create(struct worker *w);
void show_data(shop_data *s);

int main()
{
    shop_data *shops;
    shops = (shop_data *)calloc(S, sizeof(shop_data));

    strcpy(shops[0].name,"NIKE");
    strcpy(shops[1].name,"ADIDAS");
    strcpy(shops[2].name,"PUMA");
    strcpy(shops[3].name,"HUMMEL");
    strcpy(shops[4].name,"REEBOK");

    srand(time(NULL));
    for(int i=0;i<S;i++)
    {
        shop_create(&shops[i]);
    }

    int n;
    printf("1 --> NIKE\n2 --> ADIDAS\n3 --> PUMA\n4 --> HUMMEL\n5 --> REEBOK\n");
    printf("Please, enter the shop number: ");
    scanf("%d",&n);

    printf("\n\n\n");
    show_data(&shops[n-1]);

    return 0;
}
void product_create(struct product *p)
{
    p->ref_code = rand()+1000;
    p->price = rand()%200 + 50;
}

void worker_create(struct worker *w)
{
    for(int i=0;i<10;i++)
    {
        w->name[i] = 'a' + rand()%26;
        w->surname[i] = 'a' + rand()%26;
    }
    w->age = (rand()%22)+18;
}

void shop_create(shop_data *s)
{
    for(int i=0;i<20;i++)
    {
        s->street[i] = 'z' - rand()%26;
        s->nbhood[i] = 'z' - rand()%26;
    }

    for(int i=0;i<11;i++)
    {
        s->gsm[i] = '9' - rand()%10;
    }

    s->earned_money = rand()%20000+30000;

    for(int i=0;i<P;i++)
    {
        product_create(&s->products[i]);
    }

    for(int i=0;i<W;i++)
    {
        worker_create(&s->workers[i]);
    }

}

void show_data(shop_data *s)
{
    printf("SHOP NAME: %s\n\n",s->name);
    printf("STREET: %s\n",s->street);
    printf("NEIGHBOURHOOD: %s\n",s->nbhood);
    printf("GSM: %s\n",s->gsm);
    printf("EARNED MONEY: %ld$",s->earned_money);

    printf("\n\nWORKERS LIST:\n");
    for(int i=0;i<W;i++)
    {
        printf("Worker %d:\n",i+1);
        printf("\tName: %s\n",s->workers[i].name);
        printf("\tSurname: %s\n",s->workers[i].surname);
        printf("\tAge: %d\n",s->workers[i].age);
    }

    printf("\n\nPRODUCTS:\n");
    for(int i=0;i<P;i++)
    {
        printf("\tReferance code: %ld\n",s->products[i].ref_code);
        printf("\tPrice: %d$\n",s->products[i].price);
    }
}



