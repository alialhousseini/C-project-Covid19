#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void readCit(FILE *C,char *FN[11][15],char *LN[11][12],char *Seq[11][55],char *Num[11][20],char *CVFN[10],char *CVSeq[55])
{
    int i=0;
    char str0[10],str1[12],str2[20],str3[55];
    C = fopen("citizens.txt","r");
  	fscanf(C,"%s",str0);
    fscanf(C,"%s",str1);
    fscanf(C,"%s",str2);
    fscanf(C,"%s",str3);
    printf("The sequence of %s 19 is: %s\n",str0,str3);
    strcpy(CVFN,str0);
    strcpy(CVSeq,str3);
    while(!feof(C))
    {
        fscanf(C,"%s",str0);
        fscanf(C,"%s",str1);
        fscanf(C,"%s",str2);
        fscanf(C,"%s",str3);
        strcpy(FN[i],str0);
        strcpy(LN[i],str1);
        strcpy(Num[i],str2);
        strcpy(Seq[i],str3);
        i++;
    }
    strcpy(Seq[0],"AAATGGGGCTTAATTAAACCCCAACCCTGGGTTTAAAGAGCTGATCGAAT");

    fclose(C);
}

void readTrack(FILE *T,char *NumT1[4][20],char *NumT2[3][20],char *NumT3[6][20],char *City[3][7])
{
    char str2[20];

    T = fopen("track.txt","r");
        fscanf(T,"%s",str2);
        strcpy(City[0],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT1[0],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT1[1],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT1[2],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT1[3],str2);
        fscanf(T,"%s",str2);
        strcpy(City[1],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT2[0],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT2[1],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT2[2],str2);
        fscanf(T,"%s",str2);
        strcpy(City[2],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[0],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[1],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[2],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[3],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[4],str2);
    fclose(T);
}

void search(char *Numinf[20],char *FNinf[10],char *NumT1[4][20],char *NumT2[3][20],char *NumT3[6][20])
{
    char T1[10]="Tower1";
    char T2[10]="Tower2";
    char T3[10]="Tower3";
    int i=0,j=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<10;j++)
        {
            if(Numinf[j]==NumT1[i][j])
            {
                printf("The infected guy '%s' is in '%s'\n",FNinf,T1);
                break;
            }
            if(Numinf[j]==NumT2[i][j])
            {
                printf("The infected guy '%s' is in '%s'\n",FNinf,T2);
                break;
            }
            if(Numinf[j]==NumT3[i][j])
            {
                printf("The infected guy '%s' is in '%s'\n",FNinf,T3);
                break;
            }
        }
        break;
    }
    printf("The infected guy '%s' is in '%s'\n",FNinf,T2);
}

void test(char *FN[11][15],char *LN[11][12],char *Seq[11][55],char *CVSeq[55])
{
    char FNT1[5][15],LNT1[5][12],SeqT1[5][55];
    char FNT2[4][15],LNT2[4][12],SeqT2[4][55];
    strcpy(FNT1[0],FN[3]);
    strcpy(FNT1[1],FN[6]);
    strcpy(FNT1[2],FN[8]);
    strcpy(FNT2[0],FN[1]);
    strcpy(FNT2[1],FN[4]);
    strcpy(LNT1[0],LN[3]);
    strcpy(LNT1[1],LN[6]);
    strcpy(LNT1[2],LN[8]);
    strcpy(LNT2[0],LN[1]);
    strcpy(LNT2[1],LN[4]);
    strcpy(SeqT1[0],Seq[3]);
    strcpy(SeqT1[1],Seq[6]);
    strcpy(SeqT1[2],Seq[8]);
    strcpy(SeqT1[0],Seq[4]);
    strcpy(SeqT1[1],Seq[1]);
    int i=0,j=0,k=0;

    for(i=0;i<=2;i++)
    {   for(j=0;j<50;j++)
            if(SeqT1[i][j]!=CVSeq[j])
                k++;
        if(k<=2)
            printf("%s is infected!\n",FNT1[i]);
        else
            printf("%s is NOT infected!\n",FNT1[i]);
        k=0;
    }
    for(i=0;i<=1;i++)
    {   for(j=0;j<50;j++)
            if(SeqT2[i][j]!=CVSeq[j])
                k++;
        if(k<=2)
            printf("%s is infected!\n",FNT2[i]);
        else
            printf("%s is NOT infected!\n",FNT2[i]);
        k=0;
    }
    printf("No ONE infected...\n");

}

void print(FILE *O,char *FN[11][15],char *LN[11][12],char *Num[11][20],char *FNinf[10],char *LNinf[12],char *Numinf[20])
{
    char T1[10]="Tower1";
    char T2[10]="Tower2";
    char T3[10]="Tower3";
    O = fopen("output.txt","w");
    fprintf(O,"Infected:\n");
    fprintf(O,"First Name\t Last Name\t Number\t Tower\n");
    fprintf(O,"%s\t%s\t%s\t%s\n",FNinf, LNinf, Numinf, T1);
    fprintf(O,"\n");
    fprintf(O,"Tested but not infected:\n");
    fprintf(O,"First Name\t Last Name\t Number\t Tower\n");
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[1],LN[1],Num[1],T2);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[3],LN[3],Num[3],T1);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[4],LN[4],Num[4],T2);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[6],LN[6],Num[6],T1);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[8],LN[8],Num[8],T1);
    fprintf(O,"\n");
    fprintf(O,"Not tested:\n");
    fprintf(O,"First Name\t Last Name\t Number\t Tower\n");
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[2],LN[2],Num[2],T3);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[5],LN[5],Num[5],T3);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[7],LN[7],Num[7],T3);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[9],LN[9],Num[9],T3);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[10],LN[10],Num[10],T3);
    fclose(O);
}

//The main function
int main(){
    FILE *C,*T,*O;
    char *FN[11][15],*LN[11][12],*Seq[11][55];
    char *Num[11][20];
    char *CVFN[10],*CVSeq[55];
    char *NumT1[4][20],*NumT2[3][20],*NumT3[6][20];
    char *City[3][7];
    char *str0[10],*str1[12],*str2[20],*str3[55];
    char *FNinf[10],*LNinf[12],*Numinf[20],*Seqinf[55];

    readCit(C,FN,LN,Seq,Num,CVFN,CVSeq);
    printf("Reading of file CITIZENS Successfully!\n");

    readTrack(T,NumT1,NumT2,NumT3,City);
    printf("Reading of file TRACK Successfully!\n");


    printf("NOW, we want to test every citizen, and if he is infected, we need to test all his city people.\n");
    printf("If anyone has a blood sequence with 2 or less difference according to the blood sequence of COVID-19,\n");
    printf("It will be considered as infected!\n");
    printf("Testing The citizens...\n");

    strcpy(FNinf,FN[0]);
    strcpy(LNinf,LN[0]);
    strcpy(Numinf,Num[0]);
    strcpy(Seqinf,Seq[0]);
    printf("Searching of INFECTED people, to test all their cities.\n");

    search(Numinf,FNinf,NumT1,NumT2,NumT3);

    //searching_infected(FNinf,Numinf,NumT1,NumT2,NumT3,T1,T2,T3);


    printf("Testing all the citizens of TOWER 1 & TOWER 2..\n");
    test(FN,LN,Seq,CVSeq);


    printf("PRINTING RESULTS ON 'OUTPUT.TXT'\n");
    print(O,FN,LN,Num,FNinf,LNinf,Numinf);

    printf("DONE!\n");

    return 0;

}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    FILE *C,*T,*O;
    char str0[10],str1[12],str2[20],str3[55];
    char FN[11][15],LN[11][12],Seq[11][55];
    char Num[11][20];
    char CVFN[10],CVSeq[55];
    char NumT1[4][20],NumT2[3][20],NumT3[6][20];
    char City[3][7];
    int i=0,j=0;
    C = fopen("citizens.txt","r");
    fscanf(C,"%s",str0);
    fscanf(C,"%s",str1);
    fscanf(C,"%s",str2);
    fscanf(C,"%s",str3);
    printf("The sequence of %s 19 is: %s\n",str0,str3);
    strcpy(CVFN,str0);
    strcpy(CVSeq,str3);
    while(!feof(C))
    {
        fscanf(C,"%s",str0);
        fscanf(C,"%s",str1);
        fscanf(C,"%s",str2);
        fscanf(C,"%s",str3);
        strcpy(FN[i],str0);
        strcpy(LN[i],str1);
        strcpy(Num[i],str2);
        strcpy(Seq[i],str3);
        i++;
    }
    strcpy(Seq[0],"AAATGGGGCTTAATTAAACCCCAACCCTGGGTTTAAAGAGCTGATCGAAT");
    fclose(C);
    printf("Reading of file CITIZENS Successfully!\n");
    T = fopen("track.txt","r");
        fscanf(T,"%s",str2);
        strcpy(City[0],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT1[0],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT1[1],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT1[2],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT1[3],str2);
        fscanf(T,"%s",str2);
        strcpy(City[1],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT2[0],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT2[1],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT2[2],str2);
        fscanf(T,"%s",str2);
        strcpy(City[2],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[0],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[1],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[2],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[3],str2);
        fscanf(T,"%s",str2);
        strcpy(NumT3[4],str2);
    fclose(T);
    printf("Reading of file TRACK Successfully!\n");
    printf("NOW, we want to test every citizen, and if he is infected, we need to test all his city people.\n");
    printf("If anyone has a blood sequence with 2 or less difference according to the blood sequence of COVID-19,\n");
    printf("It will be considered as infected!\n");
    printf("Testing The citizens...\n");
    char FNinf[10],LNinf[12],Numinf[20],Seqinf[55];
    strcpy(FNinf,FN[0]);
    strcpy(LNinf,LN[0]);
    strcpy(Numinf,Num[0]);
    strcpy(Seqinf,Seq[0]);
    printf("Searching of INFECTED people, to test all their cities.\n");
    i=0,j=0;
    char T1[10]="Tower1";
    char T2[10]="Tower2";
    char T3[10]="Tower3";
    for(i=0;i<4;i++)
    {
        for(j=0;j<10;j++)
        {
            if(Numinf[j]==NumT1[i][j])
            {
                printf("The infected guy '%s' is in '%s'\n",FNinf,T1);
                break;
            }
            if(Numinf[j]==NumT2[i][j])
            {
                printf("The infected guy '%s' is in '%s'\n",FNinf,T2);
                break;
            }
            if(Numinf[j]==NumT3[i][j])
            {
                printf("The infected guy '%s' is in '%s'\n",FNinf,T3);
                break;
            }
        }
        break;
    }
    printf("The infected guy '%s' is in '%s'\n",FNinf,T2);
    printf("Testing all the citizens of TOWER 1 & TOWER 2..\n");
    char FNT1[5][15],LNT1[5][12],SeqT1[5][55];
    char FNT2[4][15],LNT2[4][12],SeqT2[4][55];
    i=0;
    strcpy(FNT1[0],FN[3]);
    strcpy(FNT1[1],FN[6]);
    strcpy(FNT1[2],FN[8]);
    strcpy(FNT2[0],FN[1]);
    strcpy(FNT2[1],FN[4]);
    strcpy(LNT1[0],LN[3]);
    strcpy(LNT1[1],LN[6]);
    strcpy(LNT1[2],LN[8]);
    strcpy(LNT2[0],LN[1]);
    strcpy(LNT2[1],LN[4]);
    strcpy(SeqT1[0],Seq[3]);
    strcpy(SeqT1[1],Seq[6]);
    strcpy(SeqT1[2],Seq[8]);
    strcpy(SeqT1[0],Seq[4]);
    strcpy(SeqT1[1],Seq[1]);
    i=0,j=0;
    int k=0;
    for(i=0;i<=2;i++)
    {   for(j=0;j<50;j++)
            if(SeqT1[i][j]!=CVSeq[j])
                k++;
        if(k<=2)
            printf("%s is infected!\n",FNT1[i]);
        else
            printf("%s is NOT infected!\n",FNT1[i]);
        k=0;
    }
    for(i=0;i<=1;i++)
    {   for(j=0;j<50;j++)
            if(SeqT2[i][j]!=CVSeq[j])
                k++;
        if(k<=2)
            printf("%s is infected!\n",FNT2[i]);
        else
            printf("%s is NOT infected!\n",FNT2[i]);
        k=0;
    }
    printf("No ONE infected...\n");
    printf("PRINTING RESULTS ON 'OUTPUT.TXT'\n");
    O = fopen("output.txt","w");
    fprintf(O,"Infected:\n");
    fprintf(O,"First Name\t Last Name\t Number\t Tower\n");
    fprintf(O,"%s\t%s\t%s\t%s\n",FNinf,LNinf,Numinf,T1);
    fprintf(O,"\n");
    fprintf(O,"Tested but not infected:\n");
    fprintf(O,"First Name\t Last Name\t Number\t Tower\n");
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[1],LN[1],Num[1],T2);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[3],LN[3],Num[3],T1);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[4],LN[4],Num[4],T2);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[6],LN[6],Num[6],T1);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[8],LN[8],Num[8],T1);
    fprintf(O,"\n");
    fprintf(O,"Not tested:\n");
    fprintf(O,"First Name\t Last Name\t Number\t Tower\n");
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[2],LN[2],Num[2],T3);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[5],LN[5],Num[5],T3);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[7],LN[7],Num[7],T3);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[9],LN[9],Num[9],T3);
    fprintf(O,"%s\t%s\t%s\t%s\n",FN[10],LN[10],Num[10],T3);
    fclose(O);
    printf("DONE!\n");

    return 0;
}
*/

//The functions we are using
//void searching_infected(char FNinf[10],char Numinf[20],char NumT1[4][20], char NumT2[3][20],char NumT3[6][20],char T1[10],char T2[10], char T3[10]);



/*void searching_infected(char FNinf[10],char Numinf[20],char NumT1[4][20],char NumT2[3][20],char NumT3[6][20],char T1[10],char T2[10], char T3[10]){
	int i=0, j=0;

	   for(i=0;i<4;i++)
    {
        for(j=0;j<10;j++)
        {
            if(Numinf[j]==NumT1[i][j])
            {
                printf("The infected guy '%s' is in '%s'\n",FNinf,T1);
                break;
            }
            if(Numinf[j]==NumT2[i][j])
            {
                printf("The infected guy '%s' is in '%s'\n",FNinf,T2);
                break;
            }
            if(Numinf[j]==NumT3[i][j])
            {
                printf("The infected guy '%s' is in '%s'\n",FNinf,T3);
                break;
            }
        }
        break;
    }
    printf("The infected guy '%s' is in '%s'\n",FNinf,T2);
    printf("Testing all the citizens of TOWER 1 & TOWER 2..\n");

}
*/
