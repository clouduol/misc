#include<iostream>
#include<cmath>

using namespace std;

void int2array(int, int*);
void sync2stdout(int*);
bool islegal(int*);

int p2[4]={2,3,0,1};
int p3[4]={2,5,1,3};
int p4[4][2]={{0,4},{1,6},{0,8},{5,9}};
int p5[4]={7,3,8,6};
int p6[4][2]={{1,3},{0,5},{2,9},{4,8}};
int p7[4]={2,1,0,3};
int p8[4]={6,4,1,9};
int p9[4]={5,9,1,8};
int p10[4]={3,2,4,1};

int main() {
	int Min=0,Max=pow(4,10);
	int ans[10],n;
	for(n=Min; n<Max; n++){
		int2array(i,ans);
	}
	if(n==Max){
		cout<<"no answer found"<<end;
	}else
		sync2stdout(ans);
}

void int2array(int n,int* ans){
	// clear ans
	for(int i=0;i<10;i++)
		ans[i]=0;
	
	int c=0;
	while(n) {
		ans[c++]=n%4;
		n=n/4;
	}
}

void sync2stdout(int* ans){
	for(int i=0;i<10;i++)
		cout<<char('A'+ans[i]);
	cout<<endl;
}

bool islegal(int* ans) {
	//p2
	if(p2[ans[1]] != ans[4])
		return false;
	//p3
	int o1,o2,o3;
	switch(ans[2]){
		case 0: o1=1,o2=2,o3=3;
		case 1: o1=0,o2=2,o3=3;
		case 2: o1=0,o2=1,o3=3;
		case 3: o1=0,o2=1,o3=2;
	}
	if(!( ans[p2[o1]] == ans[p2[o2]] && ans[p2[o2]] == ans[p2[o3]] ))
		return false;
	if( ans[p2[ans[2]]] == ans[p2[o1]]  )
		return false;
	
	//p4
	if( ans[p3[ans[3]][0]] != ans[p3[ans[3]][1]]  )
		return false;
	
	//p5
	if( ans[4] != ans[p5[ans[4]]]  )
		return false;
	
	//p6
	if(!( ans[7] == ans[p6[ans[5]][0]] && ans[7] == ans[p6[ans[5]][1]]  ))
		return false;
	
	//p7
	int c[4]={0,0,0,0};
	for(int i=0;i<10;i++){
		c[ans[i]]++;
	}
	if(!( c[p7[ans[6]]] <= c[0] && c[p7[ans[6]]] <= c[1] && c[p7[ans[6]]] <= c[2] && c[p7[ans[6]]] <=c[3]  ))
		return false;
	
	//p8
	if( abs(ans[0]-ans[p8[ans[7]]])==1  )
		return false;
	
	//p9
	int t1=0,t2=0;
	if( ans[0]==ans[5]  )
		t1=1;
	else
		t1=-1;
	if( ans[p9[ans[8]]] == ans[4]  )
		t2=1;
	else
		t2=-1;
	
	//p10
	if( max(c[0],c[1],c[2],c[3])-min(c[0],c[1],c[2],c[3])!=p10[ans[9]]  )
		return false;
	
	return true;
}
