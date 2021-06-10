#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int size_of_file();

char fname[]={"questions.dat"};

struct question_t{
	char question[200];
	char a[30];
	char b[30];
	char c[30];
	char d[30];
	unsigned int answer;	
	unsigned int difficulty;
};

struct question_t rquestion_f(){
    
    FILE *fp;
    fp=fopen(fname,"rb");
    struct question_t q;
    int sizef = size_of_file();
    int rng = rand() % sizef;

    int j;
    for(j = 0; j != rng;j++){
        fread(&q,sizeof(q),1,fp);
    };
    return q;
}

//saving random 10 questions
struct question_t *sv_10q(){
    FILE *fp;
    

    struct question_t *fq;
    struct question_t arr[10];
    
    fp=fopen(fname,"rb");
    
    
    
    for(int i = 0; i < 10 ; ){
        
        
        struct question_t rq = rquestion_f();
        
        if(i < 3){
            if(rq.difficulty == 0){
                arr[i] = rq;
                i++;
            };
        };
                
        
        if(i >= 3 && i <= 5){
            if(rq.difficulty == 1){
                arr[i] = rq;
                i++;
            };
        };
        if(i >= 6 && i <= 9){
            if(rq.difficulty == 2){
                arr[i] = rq;
                i++;
            };
        };
    };
        
    fq = &arr[0];
    
    fclose(fp);
    
    return fq;
        

    
}

int size_of_file(){
    
    FILE *fp;
    int size = 0;
    struct question_t q;
    
    fp = fopen(fname,"rb");
    while(1){
        fread(&q,sizeof(q),1,fp);
        size++;
        if(feof(fp))
            break;
    };
    fclose(fp);
    
    return size - 1;
}

void display()
{
	FILE *fp;
	struct question_t q;

	fp=fopen(fname,"rb");

	printf("\n========================================================\n\n");
	printf("\t\t All question details\n\n");
	printf("========================================================\n\n");

	printf("Question\tA\tB\tC\tD\n\n");

	while(1){
		fread(&q,sizeof(q),1,fp);

		if(feof(fp)){
			break;
		}
		printf("%s\t",q.question);
		printf("%s\t",q.a);
		printf("%s\t",q.b);
		printf("%s\t",q.c);
		printf("%s\t\n\n",q.d);

	}
	printf("========================================================\n\n");
	fclose(fp);
}

void append_ui(){
	FILE *fp;
	struct question_t q;
	
	fp=fopen(fname,"ab");

	printf("\nEnter question:");
	fgets(q.question, sizeof(q.question),stdin);
	q.question[strlen(q.question)-1] = '\0';
	
	printf("\nEnter answer a:");
	fgets(q.a, sizeof(q.a),stdin);
	q.a[strlen(q.a)-1] = '\0';

	printf("\nEnter answer b:");
	fgets(q.b, sizeof(q.b),stdin);
	q.b[strlen(q.b)-1] = '\0';

	printf("\nEnter answer c:");
	fgets(q.c, sizeof(q.c),stdin);
	q.c[strlen(q.c)-1] = '\0';
	
	printf("\nEnter answer d:");
	fgets(q.d, sizeof(q.d),stdin);
	q.d[strlen(q.d)-1] = '\0';
	
	printf("\nEnter correct answer (1-4):");			
	scanf("%u",&q.answer);
	// todo: if diff != (1-3)
	printf("\nEnter difficulty (1-10):");			
	scanf("%u",&q.difficulty);

	fwrite(&q,sizeof(q),1,fp);
	fclose(fp);
}
void append(struct question_t *questions, int size){
	FILE *fp;
	
	fp=fopen(fname,"wb");
	for(int i=0;i<size;i++){
		fwrite(&questions[i],sizeof(questions[i]),1,fp);	
	}
	
	fclose(fp);
}




int main(){
    

	struct question_t questions[] = {
	{"VUPROS1", "OTGOVOR1A", "ORGOVOR1B", "OTGOVOR1G", "ORGOVOR1D", 2,0},
	{"VUPROS2", "OTGOVOR2A", "ORGOVOR2B", "OTGOVOR2G", "ORGOVOR2D", 1,1},	
	{"VUPROS3", "OTGOVOR3A", "ORGOVOR3B", "OTGOVOR3G", "ORGOVOR3D", 4,2},
	{"VUPROS4", "OTGOVOR4A", "ORGOVOR4B", "OTGOVOR4G", "ORGOVOR4D", 3,1},	
	{"VUPROS5", "OTGOVOR5A", "ORGOVOR5B", "OTGOVOR5G", "ORGOVOR5D", 2,2},
	{"VUPROS6", "OTGOVOR6A", "ORGOVOR6B", "OTGOVOR6G", "ORGOVOR6D", 1,0},	
	{"VUPROS7", "OTGOVOR7A", "ORGOVOR7B", "OTGOVOR7G", "ORGOVOR7D", 4,2},
	{"VUPROS8", "OTGOVOR8A", "ORGOVOR8B", "OTGOVOR8G", "ORGOVOR8D", 1,1},	
	{"VUPROS9", "OTGOVOR9A", "ORGOVOR9B", "OTGOVOR9G", "ORGOVOR9D", 2,2},
	{"VUPROS10", "OTGOVOR10A", "ORGOVOR10B", "OTGOVOR10G", "ORGOVOR10D", 3,2},	
	{"VUPROS11", "OTGOVOR11A", "ORGOVOR11B", "OTGOVOR11G", "ORGOVOR11D", 3,0},
	{"VUPROS12", "OTGOVOR12A", "ORGOVOR12B", "OTGOVOR12G", "ORGOVOR12D", 1,1},
    {"VUPROS13", "OTGOVOR13A", "ORGOVOR13B", "OTGOVOR13G", "ORGOVOR13D", 1,1},
	};
	append(questions, sizeof(questions)/sizeof(questions[0]));
	display();
    
    struct question_t *questions10 = sv_10q();
    
    for(int i = 0; i < 10;i++){
        printf("%s\n",(questions10+i)->question);
    }


}








