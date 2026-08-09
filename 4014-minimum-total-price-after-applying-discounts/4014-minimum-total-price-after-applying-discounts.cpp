class Solution {
public:
    static bool mycmp(const int& a, const int& b) { return a > b; }
    double minPrice(vector<int>& pri, vector<int>& dis) {
        double d = 0;
        sort(pri.begin(), pri.end(), mycmp);
        sort(dis.begin(), dis.end(), mycmp);

        int i = 0, j = 0;

        while (i < pri.size() && j < dis.size()) {
            d = d + (pri[i] * (100.0 - dis[j])) / 100.0;
            i++;
            j++;
        }
        while (i < pri.size()) {
            d = d + pri[i];
            i++;
        }
        return d;
    }
};