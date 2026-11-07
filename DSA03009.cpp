#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool highest(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int largest_slot = 0;
        vector<pair<int, int>> DLP(n);
        for(int i = 0; i < n; i++) {
            int id;
            cin >> id >> DLP[i].first >> DLP[i].second;
            largest_slot = max(largest_slot, DLP[i].first);
        } 
        sort(DLP.begin(), DLP.end(), highest);
        vector<bool> slots(largest_slot + 1, false);
        int totalprofit = 0;
        int jobcount = 0;
        for(int i = 0; i < n; i++) {
            int x = DLP[i].first;
            while(x >= 1 && slots[x]) x--;
            if(x >= 1) {
                jobcount++;
                totalprofit += DLP[i].second;
                slots[x] = true;
            }
        }
        cout << jobcount << " " << totalprofit << "\n";
    }
    return 0;
}