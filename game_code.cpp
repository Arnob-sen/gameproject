#include<bits/stdc++.h>
#include<graphics.h>
/*/#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
/*/
using namespace std;
typedef long long ll;

int endfunc(int e, int a);

int main(){
    //direction
    int gd,gm,food_x=200,food_y=200,snake_x[200]={0},snake_y[200]={0},d;

    //Food eaten
    ll score=1;
    ll  chk = 600;
    //directions
    ll dir=1;
    ll snake_length=2;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    setfillstyle(1,1);//(style,color)
    snake_x[0]=200,snake_y[0]=200;
    d=1;


while(1){
    setfillstyle(1,0);
    bar(0,0,640,480);
    setfillstyle(1,3);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
       // food taken?
   if(snake_x[0]==food_x && snake_y[0]==food_y ){
    snake_length ++;
    score++;
    setfillstyle(1,0);
    bar(food_x,food_y,food_x+10,food_y+10);

    //make food
    do{
	food_x = (1+rand()%630);
	food_y = (1+rand()%470);
    }while(getpixel(food_x,food_y)!=0 && food_x > 10 && food_y > 10);

    food_x=food_x/10;
    food_x=food_x*10;
    food_y=food_y/10;
    food_y=food_y*10;
    setfillstyle(1,2);
     }
    bar(food_x,food_y,food_x+10,food_y+10);
    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
    else if(GetAsyncKeyState(VK_UP)){ d=3;}
    else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
    else{d=0;}
    switch(d){
    case 0:
      if(dir==1){snake_x[0]=snake_x[0]+10;}
      else if(dir==2){snake_x[0]=snake_x[0]-10;}
      else if(dir==3){ snake_y[0]=snake_y[0]-10;}
      else if(dir==4) {snake_y[0]=snake_y[0]+10;}
      else{d=0;}
      break;
    case 1:
           snake_x[0]=snake_x[0]+10;
           dir=1;
           break;
    case 2:
         snake_x[0]-=10;
         dir=2;
          break;
    case 3:
        dir=3;
        snake_y[0]=snake_y[0]-10;
        break;
    case 4:
        dir=4;
       snake_y[0]+=10;
        break;
    }
    for(ll i = 0; i <snake_length;i++){
        bar(snake_x[i],snake_y[i],snake_x[i]+10,snake_y[i]+10);
    }
    for(int i= 199; i >0;i--){
        snake_x[i] = snake_x[i-1];
        snake_y[i] = snake_y[i -1];
    }
    delay(100);
    if(snake_x[0] >= 640 || snake_x[0]<=0|| snake_y[0]<=0 || snake_y[0]>=480){
    endfunc(score,0);
    break;
    }

    for(int i = 2; i < snake_length;i++){
        if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i]){
            chk = i;
            break;
            }
    }
    if(snake_x[0] == snake_x[chk] && snake_y[0] == snake_y[chk]){
    endfunc(score,1);
    break;
    }
}
}

int endfunc(int e,int a){
    setfillstyle(1,5);
    e=e-2;
    bar(0,0,640,470);
    system("cls");
    if(a == 0){
        cout<<"You died outside the boundary!!!\n"<<endl;;
    }
    else if(a== 1){
        cout<<"You died into yourself!!!\n"<<endl;
    }
    cout<<"Your score is : "<<e<<endl;
    getch();
    return 0;
}
