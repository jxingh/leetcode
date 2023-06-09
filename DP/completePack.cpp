#include <bits/stdc++.h>
using namespace std;

// 先遍历物品，在遍历背包
void test1_CompletePack() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++) {           // 遍历物品
        for (int j = weight[i]; j <= bagWeight; j++) {  // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}

// 先遍历背包，再遍历物品
void test2_CompletePack() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    vector<int> dp(bagWeight + 1, 0);

    for (int j = 1; j <= bagWeight; j++) {         // 遍历背包容量
        for (int i = 0; i < weight.size(); i++) {  // 遍历物品
            if (j - weight[i] >= 0)
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}

int main() {
    // test1_CompletePack();
    test2_CompletePack();
    return 0;
}