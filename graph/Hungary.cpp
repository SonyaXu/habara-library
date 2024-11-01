#include <iostream>
#include <cstring>
using namespace std;

const int N = 505, M = 50005;
int n1, n2, m; // n1：左部集合中的点数，n2：右部集合中的点数， m边数 
int head[N], lnk[M], nxt[M], idx; // 只会用到从左部集合指向右部集合的边，所以这里只用存一个方向的边
bool flag[N]; // 判断右部集合是否考虑过，每个左部集的点匹配时，至多考虑1遍右部集的每个点 
int match[N]; // 右部集合匹配的左部集合的结点编号 

void add(int u, int v) {
	lnk[idx] = v;
	nxt[idx] = head[u];
	head[u] = idx ++ ;
}

bool find(int x) {
	for (int i = head[x]; i != -1; i = nxt[i]) {
		int y = lnk[i];
		if (!flag[y]) {
			flag[y] = true;
			if (!match[y] || find(match[y])) { // 如果y没被匹配，或者被匹配则考虑 match[y] 能否连其他右部集的点 
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d%d", &n1, &n2, &m);
	memset(head, -1, sizeof head);
	int u, v;
	for (int i = 1; i <= m; i ++ ) {
		
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	int res = 0;
	for (int i = 1; i <= n1; i ++ ) { // 枚举左部集的每个点 
		memset(flag, false, sizeof flag); // 每次都要考虑1遍右部集所有点 
		if (find(i)) res ++ ;
	}
	printf("%d\n", res);
	return 0;
}
