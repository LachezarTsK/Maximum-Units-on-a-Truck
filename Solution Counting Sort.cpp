
#include <array>
#include <vector>
using namespace std;

class Solution {
    inline static const int MAX_UNITS_PER_BOX = 1000;

public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        array<int, MAX_UNITS_PER_BOX + 1 > unitsPerBox{};
        for (int i = 0; i < boxTypes.size(); ++i) {
            unitsPerBox[boxTypes[i][1]] += boxTypes[i][0];
        }

        int spaceInTruck = truckSize;
        int unitsInTruck = 0;

        for (int units = unitsPerBox.size() - 1; units >= 1 && spaceInTruck > 0; --units) {
            unitsInTruck += (spaceInTruck >= unitsPerBox[units]) ? (unitsPerBox[units] * units) : (spaceInTruck * units);
            spaceInTruck -= unitsPerBox[units];
        }
        return unitsInTruck;
    }
};
