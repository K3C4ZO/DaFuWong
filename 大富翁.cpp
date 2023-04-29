#include <bits/stdc++.h>

using namespace std;


void board(int a[10],int house[10]){
	cout<<"地0: "<<a[0]<<" ,"<<house[0]<<"  "<<"地1: "<<a[1]<<" ,"<<house[1]<<"  "
	<<"地2: "<<a[2]<<" ,"<<house[2]<<"  "<<"地3: "<<a[3]<<" ,"<<house[3]<<"  "
	<<"地4: "<<a[4]<<" ,"<<house[4]<<"  "<<"地5: "<<a[5]<<" ,"<<house[5]<<"  "
	<<"地6: "<<a[6]<<" ,"<<house[6]<<"  "<<"地7: "<<a[7]<<" ,"<<house[7]<<"  "
	<<"地8: "<<a[8]<<" ,"<<house[8]<<"  "<<"地9: "<<a[9]<<" ,"<<house[9]<<"  "<<endl;
}
p2Land(int a){
	if(a==0){
		return 0;
	}
	else if (a==2){
		return 20;
	}
	else if (a==22){
		return 60;
	}
	else if (a==222){
		return 120;
	}
}
p1Land(int a){
	if(a==0){
		return 0;
	}
	else if (a==1){
		return 20;
	}
	else if (a==11){
		return 60;
	}
	else if (a==111){
		return 120;
	}
}


int main()
{
	int a[10],house[10];
	for(int i=0;i<10;i++){
		a[i]=0;
		house[i]=0;
	}
	int dice1,dice2,play;
	int p1=0,p2=0,moneyOne=100,moneyTwo=100;
	while(true){
		if(moneyTwo<=0 || moneyOne>=2000){
			cout<<"1號玩家勝利"<<endl;
			break; 
		}
		else if(moneyOne<=0 || moneyTwo>=2000){
			cout<<"2號玩家勝利"<<endl;
			break; 
		}
		
		dice1=0,play=0;
		cout<<"1號玩家的回合: ";
		cin>>play;
		if(play==0){
			break;
		}
		else{
			cout<<"1號玩家的錢: "<<moneyOne<<endl; 
			dice1=rand()%3;
			cout<<"你骰的點數為: "<<dice1<<endl; 
			p1+=dice1;
			if(p1>9){
				p1-=9;
				moneyOne+=100;
			}
			for(int i=0;i<10;i++){
				if(p1==i){
					if(a[i]==2){
						a[i]=21;
					}
					else{
						a[i]=1;
					}
				}
			}
			board(a,house);
			if(house[p1]==0){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					house[p1]=1;
					moneyOne-=50;
				}
			}
			else if(house[p1]==1){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					house[p1]=11;
					moneyOne-=50;
				}
			}
			else if(house[p1]==11){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					house[p1]=111;
					moneyOne-=50;
				}
			}
			if(house[p1!=0]){
				moneyOne-=p2Land(house[p1]);
				moneyTwo+=p2Land(house[p1]);
			}
			cout<<"1號玩家的錢: "<<moneyOne<<endl; 
			cout<<"2號玩家的錢: "<<moneyTwo<<endl; 
	
		}
		cout<<endl;
		///////////////
		dice2=0,play=0;
		cout<<"2號玩家的回合: ";
		cin>>play;
		if(play==0){
			break;
		}
		else{
			cout<<"2號玩家的錢: "<<moneyTwo<<endl; 
			dice2=rand()%3;
			cout<<"你骰的點數為: "<<dice2<<endl; 
			p2+=dice2;
			if(p2>9){
				p2-=9;
				moneyTwo+=100;
			}
			for(int i=0;i<10;i++){
				if(p2==i){
					if(a[i]==1){
						a[i]=12;
					}
					else{
						a[i]=2;
					}
				}
			}
			board(a,house);
			if(house[p2]==0){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					house[p2]=2;
					moneyTwo-=50;
				}
			}
			else if(house[p2]==2){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					house[p2]=22;
					moneyTwo-=50;
				}
			}
			else if(house[p2]==22){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					house[p2]=222;
					moneyTwo-=50;
				}
			}
	
		}
		if(house[p2!=0]){
				moneyOne-=p1Land(house[p2]);
				moneyTwo+=p1Land(house[p2]);
			}
		cout<<"2號玩家的錢: "<<moneyTwo<<endl;
		cout<<"1號玩家的錢: "<<moneyOne<<endl;  
		
		//////////
		for(int i=0;i<10;i++){
			a[i]=0;
		}
		cout<<endl;
		
	}
    return 0;
}


