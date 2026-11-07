#include <iostream>
using namespace std;
void hntower(int n, char fromRod, char toRod, char auxRod) {
    if(n == 0) {
        return;
    }
    hntower(n - 1, fromRod, auxRod, toRod);
    cout << fromRod << " " << "->" << " " <<toRod << "\n";
    hntower(n - 1, auxRod, toRod, fromRod);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    hntower(n, 'A', 'C', 'B');
    return 0;
}