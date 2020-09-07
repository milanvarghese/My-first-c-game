//Matrix Game 
#include<stdio.h>
#include<conio.h>
#include <windows.h> 
#include <dos.h> 

int matrix[4][4]={{0,2,3,4},{1,6,7,8},{5,9,10,11},{13,14,15,12}};
int run=1,count=0;
int i,j,temp;
char readKeyboard();
void displayMatrix();
int curserPosition(int key);
void checkState();
void swap(int *a, int *b);
void shuffle();

int main(){
	run=0;
	if(run==0){
		printf("\n------ Matrix Game V1.1 ------\n");
		printf("\n------- How to Play: -------\n");
		printf("\n- Your Location is at 0");
		printf("\n- Press w,a,s,d keys to move (Up,Left,Down, Right) and swap the adjucent number");
		printf("\n- You have to swap the numbers until the numbers in matrix are in order from 1-15 with the last digit being 0");
		printf("\n- The number of moves you used will be printed as well ");
		printf("\n-------------------------------\n");
		printf("\nPress any key to continue");
		if(readKeyboard()){
			run=1;
		}
	}
	shuffle();
	while(run==1){
		system("cls");
		printf("------ Matrix Game V1.1 ------\n");
		displayMatrix();
		printf("\nCounter = %d\n",count);
		printf("-------------------------------\n");
		curserPosition(readKeyboard());
		system("cls");
		printf("------ Matrix Game V1.1 ------\n");
		displayMatrix();
		printf("\nCounter = %d\n",count);
		printf("-------------------------------\n");
		checkState();
	}
	if(run==0){
		Beep(1000, 100); 
		system("cls");
		printf("------ Matrix Game V1.0 ------\n");
		displayMatrix();
		printf("-------------------------------\n");
		printf("\nCONGRATULATIONS, YOU WON in %d Moves!!!\n", count);
	}
	return 0;
}

void displayMatrix(){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
}
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
char readKeyboard(){
	return getch();
}
int curserPosition(int key){
	Beep(700, 100); 
	int a,b;
	for(a=0;a<4;a++){
		for(b=0;(a==3)?b<3:b<4;b++){
			if(matrix[a][b]==0){
				i=a;
				j=b;
				goto a;
			}
		}
	}
	a:
	switch(key){
		//up
		case 'w':
		if(i==0){
			i=0;
		}else{
			swap(&matrix[i][j], &matrix[i-1][j]);
			i--;
			count++;
		}
		break;
		//left
		case 'a':
		if(j==0){
			j=0;
		}else{
			swap(&matrix[i][j], &matrix[i][j-1]);
			j--;
			count++;
		}
		break;
		//down
		case 's':
			if(i==3){
			i=3;
		}else{
			swap(&matrix[i][j], &matrix[i+1][j]);
			i++;
			count++;
		}
		break;
		//right
		case 'd':
		if(j==3){
			j=3;
		}else{
			swap(&matrix[i][j], &matrix[i][j+1]);
			j++;
			count++;
		}
		default:break;
	}
}
void checkState(){
	int a,b;
	int state=1,result=0;
	for(a=0;a<4;a++){
		for(b=0;(a==3)?b<3:b<4;b++){
			if(matrix[a][b]==state){
				state++;
				result=1;
			}
			else{
				result=2;
				break;
			}
		}
		if(result==2){
			break;
		}
	}
	if(result==1){
		run=0;
	}
}

//Fisher–Yates algorithm to shuffle
void shuffle(){
	int x,y;
	srand(time(NULL));
	for(x=3;x>=0;x--){
		int m=rand()%(x+1);
		for(y=3;y>=0;y--){
			int n=rand()%(x+1);
			swap(&matrix[x][y],&matrix[m][n]);
		}
	}
}

