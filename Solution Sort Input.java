
import java.util.Arrays;

public class Solution {

    public int maximumUnits(int[][] boxTypes, int truckSize) {

        Arrays.sort(boxTypes, (boxOne, boxTwo) -> sortByUnitsPerBox(boxOne, boxTwo));
        int spaceInTruck = truckSize;
        int unitsInTruck = 0;

        for (int i = boxTypes.length - 1; i >= 0 && spaceInTruck > 0; --i) {
            unitsInTruck += (spaceInTruck >= boxTypes[i][0]) ? (boxTypes[i][0] * boxTypes[i][1]) : (spaceInTruck * boxTypes[i][1]);
            spaceInTruck -= boxTypes[i][0];
        }
        return unitsInTruck;
    }

    private int sortByUnitsPerBox(int[] boxOne, int[] boxTwo) {
        return boxOne[1] - boxTwo[1];
    }
}
