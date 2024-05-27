#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>


typedef char str[128];
typedef char push[3000];


int main() {
	const int xbb=82, ybb=19, jml_m=4;
	int x, y, now, p, i, j, key=0, score=0, hit=0; 
	float grav=0, ayf=5;
	char tl = 201, bl = 200, tr = 187, br = 188, v = 186, h = 205, bm=202, tm=203;
	push out;
	str temp;
	int ax = 10, ay, tempx;
	int arr[xbb][ybb];
	int met[jml_m][2];
	
	srand(time(NULL));
	printf("\033[?25l");
	fflush(stdout);
	
	getch();
	
	for(i=0;i<jml_m;i++){
		met[i][0]=xbb-3+(20*i);
		met[i][1]=(rand()%(ybb-6))+3;
	}
	
	
	
	do{
		if (!kbhit()) {
			if(grav<0.05&&grav>-0.05){
        		grav-=0.02;
			}
            grav-=0.05;
        } else {
        	if(grav<0){
        		grav=0;
			}
        	grav+=0.5;
            getch();
        }
        
        ayf -= grav;
        ay = round(ayf);
        
        if(ayf>ybb-2.2){
        	ayf=ybb-2.2;
        	grav=0;
		}else if(ayf<1.2){
        	ayf=1.2;
        	grav=-0;
		}
		
		for(i=0;i<jml_m;i++){
			if(met[i][0]>1){
				met[i][0]--;
			}else{
				met[i][0]=xbb-3;
				met[i][1]=(rand()%(ybb-6))+2;
			}
		}
		
        
        Sleep(30);
		for(x=0;x<xbb;x++){
			for(y=0;y<ybb;y++){
				if(x==ax&&y==ay){
					arr[x][y]=0;
				}else if(x==0&&y==0){
					arr[x][y]=2;
				}else if(x==xbb-1&&y==0){
					arr[x][y]=3;
				}else if(x==0&&y==ybb-1){
					arr[x][y]=4;
				}else if(x==xbb-1&&y==ybb-1){
					arr[x][y]=5;
				}else if(x==0||x==xbb-1){
					arr[x][y]=6;
				}else if(y==0||y==ybb-1){
					arr[x][y]=7;
				}else{
					arr[x][y]=-1;
				}
			}
		} 
		
		for(x=0;x<jml_m;x++){
			for(i=0;i<ybb;i++){
				if(met[x][0]>xbb-1){
					continue;
				}else if(i==0||i==met[x][1]+2){
					arr[met[x][0]][i]=8;
				}else if(i==ybb-1||i==met[x][1]-2){
					arr[met[x][0]][i]=9;
				}else if(i>met[x][1]-2&&i<met[x][1]+2){
					continue;
				}else{
					arr[met[x][0]][i]=6;
				}
				
				
			}
			if(ax==met[x][0]&&ay>met[x][1]-2&&ay<met[x][1]+2){
				score++;
			}else if(ax==met[x][0]){
				hit++;
			}
        }
		
		p=0;
		for(y=0;y<ybb;y++){
			for(x=0;x<xbb;x++){
				now = arr[x][y];
				switch(now){
					case 0: sprintf(out+p, ">"); break;
					case 1: sprintf(out+p, "#"); break;
					case 2: sprintf(out+p, "%c", tl); break;
					case 3: sprintf(out+p, "%c", tr); break;
					case 4: sprintf(out+p, "%c", bl); break;
					case 5: sprintf(out+p, "%c", br); break;
					case 6: sprintf(out+p, "%c", v); break;
					case 7: sprintf(out+p, "%c", h); break;
					case 8: sprintf(out+p, "%c", tm); break;
					case 9: sprintf(out+p, "%c", bm); break;
					case 10: sprintf(out+p, "X"); break;
					case -1: sprintf(out+p, " "); break;
					default: sprintf(out+p, "?"); break;
				}
				p++;
			}
			sprintf(out+p, "\n");
			p++;
		} 
		
		printf(out);
		printf("\n grav  : %.2f", grav);
		printf("\n ayf   : %.2f", ayf);
		printf("\n score : %d", score);
		printf("\n hit   : %d", hit);
		printf("\033[H");
	}while(key!='0');
	
	
	return 0;
}

