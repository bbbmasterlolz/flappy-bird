#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>


typedef char str[128];
typedef char push[3000];


int main() {
	const int xbb=82, ybb=19, jml_m=4, pred = 20, trace=20;
	int x, y, now, p, i, j, score=0, hit=0, cekj=0, maxh, maxm, maxmy, au=0, index; 
	float grav=0, Tgrav, ayf=5, Tayf, Dgrav=0.07;
	char key, tl = 201, bl = 200, tr = 187, br = 188, v = 186, h = 205, bm=202, tm=203;
	push out;
	str temp;
	int ax = 10, ay, Tay, tempx;
	int arr[xbb][ybb];
	int met[jml_m][2];
	int pre[pred][2];
	int tra[trace][2];
	
	srand(time(NULL));
	printf("\033[?25l");
	fflush(stdout);
	
	getch();
	
	for(i=0;i<jml_m;i++){
		met[i][0]=xbb-3+(20*i);
		met[i][1]=(rand()%(ybb-6))+3;
	}
	
	
	
	do{
		if(!kbhit()){
			if(grav<0.05&&grav>-0.05){
        		grav-=0.02;
			}
            grav-=Dgrav;
        }else{
        	
        	if(grav<0){
        		grav=0;
			}
        	grav+=0.5;
            key = getch();
        }
        
        if(maxmy<=maxh+1&&au==1){
			grav+=0.5;
		}
		
        ayf -= grav;
        ay = round(ayf);
        
        if(key=='p'){
        	if(au==0){
        		au=1;
			}else{
				au=0;
			}
		}
        
        
        
        
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
		
		Tgrav=grav;
		Tayf=ayf;
		for(i=0;i<trace;i++){
        	if(Tgrav<0.05&&Tgrav>-0.05){
        		Tgrav-=0.02;
			}
            Tgrav-=Dgrav;
            
            Tayf -= Tgrav;
        	Tay = round(Tayf);
        	
        	if(Tayf>ybb-2.2){
        		Tayf=ybb-2.2;
        		Tgrav=0;
        	
			}else if(Tayf<1.2){
        		Tayf=1.2;
        		Tgrav=-0;
			}
			//arr[ax+1+i][Tay]=10;
        	tra[i][1]=Tay;
        	tra[i][0]=ax+1+i;
		}
		
		Tgrav=grav+0.5;
		Tayf=ayf;
		for(i=0;i<pred;i++){
        	if(Tgrav<0.05&&Tgrav>-0.05){
        		Tgrav-=0.02;
			}
            Tgrav-=Dgrav;
            
            Tayf -= Tgrav;
        	Tay = round(Tayf);
        	
        	if(Tayf>ybb-2.2){
        		Tayf=ybb-2.2;
        		Tgrav=0;
        		break;
        	
			}else if(Tayf<1.2){
        		Tayf=1.2;
        		Tgrav=-0;
			}
        	//arr[ax+1+i][Tay]=11;
        	pre[i][1]=Tay;
        	pre[i][0]=ax+1+i;
		}
		
		maxm=xbb;
		for(i=0;i<jml_m;i++){
			if(met[i][0]<maxm&&met[i][0]>ax){
        		maxm=met[i][0]; 
        		maxmy=met[i][1]; 
			}
		}
				
		maxh=ybb;
		for(i=0;i<jml_m;i++){
			for(j=0;j<pred;j++){
        		if(pre[j][1]<maxh&&j<maxm){
        			maxh=pre[j][1];
        			index=i;
				}
			}
		}

		if(pre[index][1]+2<=ay&&grav<Dgrav*2){
        	if(au==1){
				grav+=0.5;
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
				cekj=0;
			}else if(ax==met[x][0]){
				hit++;
				cekj=0;
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
					case 10: sprintf(out+p, " "); break;
					case 11: sprintf(out+p, " "); break;
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
		printf("\n maxh   : %d", maxh);
		printf("\n maxm   : %d", maxm);
		
		printf("\033[H");
	}while(key!='0');
	
	
	return 0;
}

