#include "task1.h"

int main(int argc, char *argv[])
{
    FILE *infile=fopen(argv[1],"rt");
    FILE *outfile=fopen(argv[2],"wt");
    int N;
    double randammed = 0.0, volatil = 0.0, ShapeRatio = 0.0;
    Node *head=NULL;
    if (argc < 2)
        exit(-1);
    
    if (infile == NULL) {
        fclose(outfile);
        exit(-1);
    }
    if (outfile == NULL) {
        fclose(infile);
        exit(-1);
    }
    
    fscanf(infile,"%d",&N);
    for(int i=0;i<N;i++)
    {
        double value;
        fscanf(infile,"%lf",&value);
        addAtEnd(&head,value);
    }
    Node *prev= head;
    Node *current= head->next;
    while(current !=NULL)
    {
        current->randam= (current->valoare -prev->valoare)/prev->valoare;
        randammed+=current->randam;
        prev= current;
        current= current->next;
    }
    randammed=randammed/(N-1);
    head->randam = 0.0;
    Node *temp = head->next;
    while(temp !=NULL)
   {
     volatil+=(temp->randam-randammed)*(temp->randam-randammed);
     temp=temp->next;
   } 
    volatil=sqrt(volatil/(N-1));
    ShapeRatio=randammed/volatil;
    randammed=trunc(1000.0*randammed)/1000.0;
    volatil=trunc(1000.0*volatil)/1000.0;
    ShapeRatio=trunc(1000.0*ShapeRatio)/1000.0;
   fprintf(outfile,"%.3lf\n%.3lf\n%.3lf\n",randammed,volatil,ShapeRatio);
    fclose(infile);
    fclose(outfile);
    free_list(head);
    return 0;
}