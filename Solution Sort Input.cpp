
#include <vector>
using namespace std;

class Solution {
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        const auto sortByUnitsPerBox = [](const vector<int>& boxOne, const vector<int>& boxTwo) {
            return boxOne[1] < boxTwo[1];
        };

        sort(boxTypes.begin(), boxTypes.end(), sortByUnitsPerBox);
        int spaceInTruck = truckSize;
        int unitsInTruck = 0;

        for (int i = boxTypes.size() - 1; i >= 0 && spaceInTruck > 0; --i) {
            unitsInTruck += (spaceInTruck >= boxTypes[i][0]) ? (boxTypes[i][0] * boxTypes[i][1]) : (spaceInTruck * boxTypes[i][1]);
            spaceInTruck -= boxTypes[i][0];
        }
        return unitsInTruck;
    }
};
