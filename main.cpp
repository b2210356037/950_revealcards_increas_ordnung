#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        deque<int> q;
        for (int card : deck) {
            if (!q.empty()) {
                q.push_front(q.back());
                q.pop_back();
            }
            q.push_front(card);
        }
        return vector<int>(q.begin(), q.end());
    }
};

int main() {
    Solution s;
    vector<int> deck{17,13,11,2,3,5,7};
    vector<int> res;
    res = s.deckRevealedIncreasing(deck);
    for(auto& i: res) cout << i << " ";
    return 0;
}
