//Matrix Game 
#include<stdio.h>
#include<conio.h>
#include <windows.h> 
#include <dos.h> 
int matrix[4][4]={{0,2,3,4},{1,6,7,8},{5,9,10,11},{13,14,15,12}};
int run=1,count=0;
int i,j,temp;
textcolor(RED);
char readKeyboard();
void displayMatrix();
int curserPosition(int key);
void checkState();

int main(){
	while(run==1){
		system("cls");
		printf("------ Matrix Game V1.0 ------\n");
		displayMatrix();
		printf("-------------------------------\n");
		curserPosition(readKeyboard());
		system("cls");
		printf("------ Matrix Game V1.0 ------\n");
		displayMatrix();
		printf("-------------------------------\n");
		checkState();
	}
	if(run==0){
		Beep(1000, 100); 
		printf("\nCONGRATULATIONS, YOU WON!!\n");
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
			temp=matrix[i][j];
			matrix[i][j]=matrix[i-1][j];
			matrix[i-1][j]=temp;
			i--;
			count++;
		}
		break;
		//left
		case 'a':
		if(j==0){
			j=0;
		}else{
			temp=matrix[i][j];
			matrix[i][j]=matrix[i][j-1];
			matrix[i][j-1]=temp;
			j--;
			count++;
		}
		break;
		//down
		case 's':
			if(i==3){
			i=3;
		}else{
			temp= matrix[i][j];
			matrix[i][j]=matrix[i+1][j];
			matrix[i+1][j]=temp;
			i++;
			count++;
		}
		break;
		//right
		case 'd':
		if(j==3){
			j=3;
		}else{
			temp=matrix[i][j];
			matrix[i][j]=matrix[i][j+1];
			matrix[i][j+1]=temp;
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
