
/**
 * @param {number[][]} boxTypes
 * @param {number} truckSize
 * @return {number}
 */
var maximumUnits = function (boxTypes, truckSize) {
    const sortByUnitsPerBox = (x, y) => x[1] - y[1];
    boxTypes.sort(sortByUnitsPerBox);

    let spaceInTruck = truckSize;
    let unitsInTruck = 0;

    for (let i = boxTypes.length - 1; i >= 0 && spaceInTruck > 0; --i) {
        unitsInTruck += (spaceInTruck >= boxTypes[i][0]) ? (boxTypes[i][0] * boxTypes[i][1]) : (spaceInTruck * boxTypes[i][1]);
        spaceInTruck -= boxTypes[i][0];
    }
    return unitsInTruck;
};
