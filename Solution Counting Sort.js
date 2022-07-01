
/**
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
var maximumUnits = function (boxTypes, truckSize) {

    const MAX_UNITS_PER_BOX = 1000;
    const unitsPerBox = new Array(MAX_UNITS_PER_BOX + 1).fill(0);
    for (let i = 0; i < boxTypes.length; ++i) {
        unitsPerBox[boxTypes[i][1]] += boxTypes[i][0];
    }

    let spaceInTruck = truckSize;
    let unitsInTruck = 0;

    for (let units = unitsPerBox.length - 1; units >= 1 && spaceInTruck > 0; --units) {
        unitsInTruck += (spaceInTruck >= unitsPerBox[units]) ? (unitsPerBox[units] * units) : (spaceInTruck * units);
        spaceInTruck -= unitsPerBox[units];
    }
    return unitsInTruck;
};
