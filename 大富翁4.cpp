#include <bits/stdc++.h>

using namespace std;

struct Land{
	int player;
	int owner;
	int house;
	int value;
	int price;
};

struct Player{
   int money;
   vector<int> asset;
   int jail;
};


void board(Land*land){
	cout<<"地0: "<<land[0].player<<" ,"<<land[0].owner<<" ,"<<land[0].house<<" "
	<<"地1: "<<land[1].player<<" ,"<<land[1].owner<<" ,"<<land[1].house<<" "
	<<"地2: "<<land[2].player<<" ,"<<land[2].owner<<" ,"<<land[2].house<<" "
	<<"地3: "<<land[3].player<<" ,"<<land[3].owner<<" ,"<<land[3].house<<" "
	<<"地4: "<<land[4].player<<" ,"<<land[4].owner<<" ,"<<land[4].house<<" "
	<<"監獄: "<<land[5].player<<" "
	<<"地6: "<<land[6].player<<" ,"<<land[6].owner<<" ,"<<land[6].house<<" "
	<<"地7: "<<land[7].player<<" ,"<<land[7].owner<<" ,"<<land[7].house<<" "
	<<"地8: "<<land[8].player<<" ,"<<land[8].owner<<" ,"<<land[8].house<<" "
	<<"地9: "<<land[9].player<<" ,"<<land[9].owner<<" ,"<<land[9].house<<" "
	<<"地10: "<<land[10].player<<" ,"<<land[10].owner<<" ,"<<land[10].house<<" "<<endl;
}
//////////////

int main()
{
	Land land[10];
	Player player[3];
	for(int i=0;i<11;i++){
	    land[i].player=0;
	    land[i].owner=0;
	    land[i].house=0;
	    land[i].value=0;
	    land[i].price=50;
	}
	for(int i=0;i<3;i++){
	    player[i].money=200;
	    player[i].jail=0;
	}
	int dice1,dice2,play;
	int p1=0,p2=0;
////////////////////////
	while(true){
		if(player[2].money<=0 || player[1].money>=2000){
			cout<<"1號玩家勝利"<<endl;
			break; 
		}
		else if(player[1].money<=0 || player[2].money>=2000){
			cout<<"2號玩家勝利"<<endl;
			break; 
		}
//////////////////////		
		dice1=0,play=0;
		cout<<"1號玩家的回合: ";
		cin>>play;
		if(play==0){
			break;
		}
		else if(player[1].jail>0){
			if(land[5].player==2 || land[5].player==21){
				land[5].player=21;
			}
			else{
				land[5].player=1;
			}
			board(land);
			cout<<"坐牢, 時常為:"<<player[1].jail<<endl;
		}
		else{
			cout<<"1號玩家的錢: "<<player[1].money<<endl; 
			dice1=1+rand()%3;
			cout<<"你骰的點數為: "<<dice1<<endl; 
			p1+=dice1;
			if(p1>10){
				p1-=10;
				player[1].money+=100;
			}
			if(p1==5){
				player[1].jail=2;
			}
			if(player[1].jail>0){
				if(land[5].player==1 || land[5].player==21){
					land[5].player=21;
				}
				else{
					land[5].player=1;
				}
				board(land);
				cout<<"坐牢, 時常為:"<<player[1].jail<<endl; 
			}
			else{
				for(int i=0;i<10;i++){
					if(p1==i){
						if(land[i].player==2){
							land[i].player=21;
						}
						else{
							land[i].player=1;
						}
					}
				}
				board(land);
				if(land[p1].owner==0){
					int buy;
					cout<<"是否買地: ";
					cin>>buy;
					if(buy==1){
						land[p1].owner=1;
						land[p1].value=20;
						player[1].money-=land[p1].price;
						player[1].asset.push_back(p1);
						board(land);
					}	
				}
				else if(land[p1].owner==1){
					int buy;
					cout<<"是否買房: ";
					cin>>buy;
					if(buy==1){
						land[p1].house=1;
						land[p1].value=60;
						player[1].money-=land[p1].price;
						board(land);
					}
				}
				else if(land[p1].house==1){
					int buy;
					cout<<"是否買房: ";
					cin>>buy;
					if(buy==1){
						land[p1].house=2;
						land[p1].value=120;
						player[1].money-=land[p1].price;
						board(land);
					}
				}
				if(land[p1].owner==2){
					player[1].money-=land[p1].value;
					player[2].money+=land[p1].value;
					
				}
			}
		}
		if(player[1].jail>0){
			player[1].jail-= 1;
		}
		cout<<"1號玩家的錢: "<<player[1].money<<"  "; 
		cout<<"1號玩家的財產: ";
		for(int i=0;i<player[1].asset.size();i++){
			cout<<player[1].asset[i];
		}
		cout<<endl;
		cout<<"2號玩家的錢: "<<player[2].money<<"  ";
		cout<<"2號玩家的財產: ";
		for(int i=0;i<player[2].asset.size();i++){
			cout<<player[2].asset[i];
		}
		cout<<endl;
		cout<<endl;
//////////////////////////////
		
		dice2=0,play=0;
		cout<<"2號玩家的回合: ";
		cin>>play;
		if(play==0){
			break;
		}
		else if(player[2].jail>0){
			if(land[5].player==1 || land[5].player==21){
				land[5].player=21;
			}
			else{
				land[5].player=2;
			}
			board(land);
			cout<<"坐牢, 時常為:"<<player[2].jail<<endl;
		}
		else{
			cout<<"2號玩家的錢: "<<player[2].money<<endl; 
			dice2=1+rand()%3;
			cout<<"你骰的點數為: "<<dice2<<endl; 
			p2+=dice2;
			if(p2>9){
				p2-=9;
				player[2].money+=100;
			}
			if(p2==5){
				player[2].jail=2;
			}
			if(player[2].jail>0){
				if(land[5].player==1 || land[5].player==21){
					land[5].player=21;
				}
				else{
					land[5].player=2;
				}
				board(land);
				cout<<"坐牢, 時常為:"<<player[2].jail<<endl; 
			}
			else{
				for(int i=0;i<10;i++){
					if(p2==i){
						if(land[i].player==1){
							land[i].player=12;
						}
						else{
							land[i].player=2;
						}
					}
				}
				board(land);
				
				if(land[p2].owner==0){
					int buy;
					cout<<"是否買地: ";
					cin>>buy;
					if(buy==1){
						land[p2].owner=2;
						land[p2].value=20;
						player[2].money-=land[p2].price;
						player[2].asset.push_back(p2);
						board(land);
					}
				}
				else if(land[p2].owner==2){
					int buy;
					cout<<"是否買房: ";
					cin>>buy;
					if(buy==1){
						land[p2].house=1;
						land[p2].value=60;
						player[2].money-=land[p2].price;
						board(land);
					}
				}
				else if(land[p2].house==1){
					int buy;
					cout<<"是否買房: ";
					cin>>buy;
					if(buy==1){
						land[p2].house=2;
						land[p2].value=120;
						player[2].money-=land[p2].price;
						board(land);
					}
				}
				if(land[p2].owner==1){
				player[1].money+=land[p2].value;
				player[2].money-=land[p2].value;
				
				}			
			}
			
		}
		if(player[2].jail>0){
			player[2].jail-= 1;
		}
		cout<<"1號玩家的錢: "<<player[1].money<<"  "; 
		cout<<"1號玩家的財產: ";
		for(int i=0;i<player[1].asset.size();i++){
			cout<<player[1].asset[i];
		}
		cout<<endl;
		cout<<"2號玩家的錢: "<<player[2].money<<"  ";
		cout<<"2號玩家的財產: ";
		for(int i=0;i<player[2].asset.size();i++){
			cout<<player[2].asset[i];
		}
		cout<<endl; 
		
		//////////
	
		cout<<endl;
		for(int i=0;i<11;i++){
	    	land[i].player=0;
		}
		
	}
    return 0;
}

