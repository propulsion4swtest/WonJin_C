
// 2112.c
#include <stdio.h>
#define A 0
#define B 1
#define min(a,b) (a > b ? b : a)

int convert[25];
 
int mem[25][25];
int test(int map[25][25], int D, int W, int K)	{
    for (int j = 0; j < W; j++){
        int cnt = 1;
        int s = convert[0] != -1 ? convert[0] : map[0][j];
        for (int i = 1; i < D; i++){
            int nowS = convert[i] != -1 ? convert[i] : map[i][j];
            if (s == nowS){
                cnt++;
 
                if (cnt == K){
                    break;
                }
            }
            else{
                cnt = 1;
                s = nowS;
            }
        }
 
        if (cnt < K){
            return 0;
        }
    }
 
    return 1;
}
 
int checkConv(int r, int D, int W, int K, int depth, int max, int t)	{
    if (depth == max){
        return test(mem, D, W, K);
    } else  if (r >= D){
        return 0;
    }
 
    if (checkConv(r + 1, D, W, K, depth, max, t))	{
        return 1;
    }
 
    convert[r] = t;
    int result = checkConv(r + 1, D, W, K, depth + 1, max, t);
    convert[r] = -1;
     
    return result;
}
 
int dfs(int D, int W, int K, int left, int right, int t){           
    int ans = D - 1;
    if (t == B){
        if (checkConv(0, D, W, K, 0, right, t)){
            ans = right;
            right = (left + right) / 2 - 1;
        } else{
            return ans;
        }
    }
 
    while (left <= right){
        int mid = (left + right) / 2;
        if (checkConv(0, D, W, K, 0, mid, t)){
            if (ans > mid){
                ans = mid;
            }
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
     
    return ans;
}
 
int main(){
    int test_case, T;

		freopen("data.txt", "r", stdin);
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; test_case++){
        int D, W, K;
        scanf("%d %d %d", &D, &W, &K);
 
        for (int i = 0; i < D; i++){
            convert[i] = -1;
            for (int j = 0; j < W; j++){
                scanf("%d", &mem[i][j]);
            }
        }
 
         
        int ansA = dfs(D, W, K, 0, D - 1, A);
        int ans = min(ansA, dfs(D, W, K, 0, ansA - 1, B));
         
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}

