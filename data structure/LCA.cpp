int n,m,s;
int a[N];
int dep[N];
int fa[M][M];  //fa[i][x] i点上的2^x级父亲
vector<int>e[N];
void dfs(int x,int f){
	fa[x][0] = f;  //x的零级父亲就是他的父亲
	dep[x] = dep[fa[x][0]] +1; //x的深度是x父亲的深度+1
	for(int i=1;i<20;i++){
		fa[x][i] = fa[fa[x][i-1]][i-1];  
		//基本的倍增思想
		//好好体会一下
		//x的i级父亲 是 x的2^(i-1)级父亲 的 2^(i-1)级父亲
		//可以理解为  pow(2,i) = pow(2,i-1)+pow(2,i-1) = 2*pow(2,i-1) = pow(2,i)
	}
	for(auto v:e[x]){
		if(v == f) continue;
		else dfs(v,x);
	}
}
int query(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=20;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]) u = fa[u][i]; 
	}
	if(u==v) return v;
	for(int i=20;i>=0;i--){
		//从大到小开始尝试跳跃
		//刚开始两个点必然重合（根节点及以上）
		//i逐渐减小，跳的步数越来越小，就会分开
		//找到那个分开的边界值
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	//注意返回的是分开点的父亲
	//从这一位开始往上跳就一直重合
	return fa[u][0]; 
}
