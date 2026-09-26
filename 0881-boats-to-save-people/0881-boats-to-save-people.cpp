static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size()-1, boats = 0;
        while (left <= right) {
            if (people[left]+people[right] <= limit) left++;
            right--; boats++;
        }
        return boats;
    }
};