#include <stdio.h>             // 載入標準函式庫
typedef unsigned long long ll; // 定義unsigned long long 為 ll (方便閱讀)

ll fibonacci(ll n);            // 宣告recursive函式 fibonacci

int main()                          // main
{
    int runTimes, inputData;                // runTimes代表要資料的個數  |  inputData代表要輸入的資料
    scanf("%d%*c",&runTimes);               // 輸入資料的個數
    for(int i=0; i<runTimes; ++i)           // 進入迴圈(次數為運行次數為runTimes)
    {
        scanf("%d%*c",&inputData);          // 輸入資料
        printf("%d ", fibonacci(inputData));// 輸出 n! 答案
    }
    
    return 0;                               // 結束
}

ll fibonacci(ll n)                  // 費式數列 函式
{
    if ( n == 0 ) return 0;                 // n == 0時 結束recursive並return 0
    else if ( n == 1 ) return 1;            // n == 1時 結束recursive並return 1
    return fibonacci(n-1) + fibonacci(n-2); // 以recursive的方式去疊代 f(i) = f(i-1) + f(i-2)
}