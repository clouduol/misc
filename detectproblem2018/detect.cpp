#include<iostream>
#include<cmath>
#include<algorithm>

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
	int count=0;
	for(n=Min; n<Max; n++){
		int2array(n,ans);
		if (islegal(ans)){
			sync2stdout(ans);
			count++;
		}
	}
	if(count==0)
		cout<<"no answer found"<<endl;
	else
		cout<<"count: "<<count<<endl;
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
	//cout<<"p2"<<endl;
	if(p2[ans[1]] != ans[4])
		return false;
	//p3
	//cout<<"p3"<<endl;
	int o1,o2,o3;
	switch(ans[2]){
		case 0: o1=1,o2=2,o3=3; break;
		case 1: o1=0,o2=2,o3=3; break;
		case 2: o1=0,o2=1,o3=3; break;
		case 3: o1=0,o2=1,o3=2; break;
	}
	//cout<<ans[2]<<"\t"<<o1<<"\t"<<o2<<"\t"<<o3<<endl;
	//cout<<ans[p3[ans[2]]]<<"\t"<<ans[p3[o1]]<<"\t"<<ans[p3[o2]]<<"\t"<<ans[p3[o3]]<<endl;
	if(!( ans[p3[o1]] == ans[p3[o2]] && ans[p3[o2]] == ans[p3[o3]] ))
		return false;
	if( ans[p3[ans[2]]] == ans[p3[o1]]  )
		return false;
	
	//p4
	//cout<<"p4"<<endl;
	if( ans[p4[ans[3]][0]] != ans[p4[ans[3]][1]]  )
		return false;
	
	//p5
	//cout<<"p5"<<endl;
	if( ans[4] != ans[p5[ans[4]]]  )
		return false;
	
	//p6
	//cout<<"p6"<<endl;
	if(!( ans[7] == ans[p6[ans[5]][0]] && ans[7] == ans[p6[ans[5]][1]] ))
		return false;
	
	//p7
	//cout<<"p7"<<endl;
	int c[4]={0,0,0,0};
	for(int i=0;i<10;i++){
		c[ans[i]]++;
	}
	if(!( c[p7[ans[6]]] <= c[0] && c[p7[ans[6]]] <= c[1] && c[p7[ans[6]]] <= c[2] && c[p7[ans[6]]] <=c[3]  ))
		return false;
	
	//p8
	//cout<<"p8"<<endl;
	if( abs(ans[0]-ans[p8[ans[7]]])==1  )
		return false;
	
	//p9
	//cout<<"p9"<<endl;
	int t1=0,t2=0;
	if( ans[0]==ans[5]  )
		t1=1;
	else
		t1=-1;
	if( ans[p9[ans[8]]] == ans[4]  )
		t2=1;
	else
		t2=-1;
	if(t1*t2==1)
		return false;
	
	//p10
	//cout<<"p10"<<endl;
	int m1=0,m2=10;
	for(int i=0;i<4;i++){
		m1=max(m1,c[i]);
		m2=min(m2,c[i]);
	}
	if( m1-m2 != p10[ans[9]]  )
		return false;
	
	return true;
}
