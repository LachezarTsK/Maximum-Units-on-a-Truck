
public class Solution {

    private static final int MAX_UNITS_PER_BOX = 1000;

    public int maximumUnits(int[][] boxTypes, int truckSize) {

        int[] unitsPerBox = new int[MAX_UNITS_PER_BOX + 1];
        for (int i = 0; i < boxTypes.length; ++i) {
            unitsPerBox[boxTypes[i][1]] += boxTypes[i][0];
        }

        int spaceInTruck = truckSize;
        int unitsInTruck = 0;

        for (int units = unitsPerBox.length - 1; units >= 1 && spaceInTruck > 0; --units) {
            unitsInTruck += (spaceInTruck >= unitsPerBox[units]) ? (unitsPerBox[units] * units) : (spaceInTruck * units);
            spaceInTruck -= unitsPerBox[units];
        }
        return unitsInTruck;
    }
}
