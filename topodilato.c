#include <stdio.h>
#include <stdlib.h>

struct pelates {
        int AM;
        char onoma[40];
        char epith[40];
        char dieu[50];
};

struct podilata {
        int AM;
        char type[50];
        char eteria[50];
        int megpl;
        int posot;
};





int main(int argc, char *argv[])
{
  struct pelates s1[10];
  struct podilata s2[10];
  
  char p;
  int i=0,j=0;
  int y,x,k,l;
  
  FILE *pel;
  FILE *pod;
  
  
  
  if ((pel=fopen("pelates.txt","r"))==NULL)
     printf("File could not be opened\n");
  else
  {
      while (!feof(pel)){
            fscanf(pel,"%d%s%s%s",&s1[i].AM,s1[i].onoma,s1[i].epith,s1[i].dieu);
            i++;
      }
  }    
  fclose(pel);
  
  if ((pod=fopen("podilata.txt","r"))==NULL)
     printf("File could not be opened\n");
  else
  {
      while (!feof(pod)){
            fscanf(pod,"%d%s%s%d%d",&s2[j].AM,s2[j].type,s2[j].eteria,&s2[j].megpl,&s2[j].posot);
            j++;
      }
  }
  fclose(pod);    
          
  printf("To sistima diaxirisis pelaton ke podilaton sou parexei tis parakato entoles:\na)Kataxorisi neou pelati\n");
  printf("b)Diagrafou kapiou pelati\nc)Probolis tis listas ton pelaton\nd)Isagogi kenourgiou proiontos\n");
  printf("e)Diagrafi kapiou proiontos\nf)Proboli tis listas ton proionton\ng)Auksisi tis posotitas kapiou proiontos\n");
  printf("h)Meiosi tis posotitas kapiou proiontos\nq)Na klisis to programma\nGia tin epilogi kapiou apo auta ta stixia epelekse to grama pou ksekinane!!\n");
  p=getchar();
  
  while ( p != EOF)
  {
        switch (p)
        {
               case 'a':   
                    printf("Dose mou to anagnoristiko tou pelati\n");
                    scanf("%d",&s1[i].AM);
                    printf("Dose mou to onoma tou pelati\n");
                    scanf("%s",s1[i].onoma);
                    printf("Dose mou to epitheto tou pelati\n");
                    scanf("%s",s1[i].epith);
                    printf("Dose mou tin dieuthinsi tou pelati\n");
                    scanf("%s",s1[i].dieu);
                    i++;
                    break;
               case 'b':
                    printf("Dose mou to anagnoristiko tou pelati oste na ton broume ke na ton diagrapsoume\n");
                    scanf("%d",&x);
                    for (i=0;i<100;i++)
                    {
                        if (x==s1[i].AM)
                        {
                        s1[i].AM=0;
                        s1[i].onoma[0]=' ';  
                        s1[i].epith[0]=' ';
                        s1[i].dieu[0]=' ';
                        break;
                        }
                    break;
                    }
               case 'c':
                   printf("Anagnoistiko\tonoma\tepitheto\tdieuthinsi\n");
                   for (i=0;i<100;i++)
                       printf("%d\t%s\t%s\t%s\n",s1[i].AM,s1[i].onoma[0],s1[i].epith[0],s1[i].dieu[0]);
                   break;
               case 'd':
                    printf("Dose mou to anagnoristiko tou podilatou\n");
                    scanf("%d",&s2[j].AM);
                    printf("dose mou ton tipo tou podilatou\n");
                    scanf("%s",s2[j].type);
                    printf("Dose mou tin eteria tou podilatou\n");
                    scanf("%s",s2[j].eteria);
                    printf("Dose mou to megethos plaisiou tou podilatou\n");
                    scanf("%d",&s2[j].megpl);
                    printf("Dose mou tin posotita tou podilatou\n");
                    scanf("%d",&s2[j].posot);
                    j++;
                    break;
               case 'e':
                    printf("Dose mou to anagnoristiko tou proion pou thes na diagrapsis\n");
                    scanf("%d",&y);
                    for (j=0;j<100;j++)
                    {
                        if (y==s2[j].AM)
                        {
                           s2[j].AM=0;
                           s2[j].type[0];
                           s2[j].eteria[0];
                           s2[j].megpl=0;
                           s2[j].posot=0;
                           break;         
                        }
                    }
                    break;
               case 'f':
                    printf("Anagnoistiko\ttipos\teteria\tmegethos plaisiou\tposotita\n");
                    for (j=0;j<100;j++)
                        printf("%d\t%s\t%s\t%d\t%d\n",s2[j].AM,s2[j].type[0],s2[j].eteria[0],s2[j].megpl,s2[j].posot);
                    break;
               case 'g':
                    printf("Dose mou to anagnoristiko oste na broume to proion\n");
                    scanf("%d",&k);
                    for (j=0;j<100;j++)
                    {
                        if (k==s2[j].AM)
                        {          
                                   printf("Dose mou ton aritho pou tha auksithi to proion\n");
                                   scanf("%d",&l);
                                   s2[j].posot = s2[j].posot + l;
                                   break;
                        }
                    }
                    break;
               case 'h':
                    printf("Dose mou to anagnoristiko oste na broume to proion\n");
                    scanf("%d",&k);
                    for (j=0;j<100;j++)
                    {
                        if (k==s2[j].AM)
                        {          
                                   printf("Dose mou ton aritho pou tha miothi to proion\n");
                                   scanf("%d",&l);
                                   s2[j].posot = s2[j].posot - l;
                                   break;
                        }
                    }
                    break;
               case 'q':
                    if ((pel=fopen("pelates.txt","w"))==NULL)
                       printf("File could not be opened\n");
                    else
                    {
                        for (i=0;i<100;i++)
                        fprintf(pel,"%d%s%s%s\n",s1[i].AM,s1[i].onoma,s1[i].epith,s1[i].dieu);
                    }    
                    fclose(pel);
                    if ((pod=fopen("podilata.txt","w"))==NULL)
                       printf("File could not be opened\n");
                    else
                    {
                        for (j=0;j<100;j++)
                        fprintf(pod,"%d%s%s%d%d",s2[j].AM,s2[j].type,s2[j].eteria,s2[j].megpl,s2[j].posot);
                    }
                    fclose(pod);
                    system("PAUSE");
                    return 0;
        }
        printf("\nTo sistima diaxirisis pelaton ke podilaton sou parexei tis parakato entoles:\na)Kataxorisi neou pelati\n");
        printf("b)Diagrafou kapiou pelati\nc)Probolis tis listas ton pelaton\nd)Isagogi kenourgiou proiontos\n");
        printf("e)Diagrafi kapiou proiontos\nf)Proboli tis listas ton proionton\ng)Auksisi tis posotitas kapiou proiontos\n");
        printf("h)Meiosi tis posotitas kapiou proiontos\nq)Na klisis to programma\nGia tin epilogi kapiou apo auta ta stixia epelekse to grama pou ksekinane!!\n");
        p=getchar();
  }
      
  
  system("PAUSE");	
  return 0;
}
