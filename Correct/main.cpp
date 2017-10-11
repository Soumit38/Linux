#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005

vector<int> allo[MAXN],need[MAXN],avl;
int r,p;
bool f[MAXN];

int main(){
        freopen("in.txt","r",stdin);
        printf("Enter number of resources and processes:\n");
        cin>>r>>p;
        printf("Available resources:\n");
        for(int i=0;i<r;i++){
                int x;
                scanf("%d",&x);
                avl.push_back(x);
        }
        for(int i=0;i<p;i++){
                printf("Allocation for process %d:\n",i);
                for(int j=0;j<r;j++){
                        int x; scanf("%d",&x);
                        allo[i].push_back(x);
                }
                printf("Need for process %d:\n",i);
                for(int j=0;j<r;j++){
                        int x; scanf("%d",&x);
                        need[i].push_back(x);
                }
        }
        int x=p;
        int it=p;
        vector<int> ans;
        while(it--&&x){
                for(int i=0;i<p;i++){
                        if(f[i]==1){
                                continue;
                        }
                        vector<int> t;
                        for(int j=0;j<r;j++){
                                t.push_back(need[i][j]-allo[i][j]);
                        }
                        int is=1;
                        for(int j=0;j<r;j++){
                                if(avl[j]<t[j]){
                                        is=0;
                                        break;
                                }
                        }
                        if(is){
                                x--;
                                f[i]=1;
                                for(int j=0;j<r;j++){
                                        avl[j]+=allo[i][j];
                                }
                                ans.push_back(i);
                        }
                }
        }
        printf("\n");
        if(x!=0) printf("NOT SAFE\n");
        else{
                printf("SAFE\n");
                for(int i=0;i<ans.size();i++){
                        printf("%d'th comes process %d\n",i+1,ans[i]);
                }
        }
}

