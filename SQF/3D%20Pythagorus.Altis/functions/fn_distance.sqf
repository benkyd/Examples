/**
 * Function to calculate distance between 2 sets of coordinates
 *
 * Expects the first two args to be an array of coordinates (x, y, z)
 * The third arg is expected to be a flag for 3D calculation
 * If no flag is provided it is assumed 2D.
 *
 * @param {array} point a
 * @param {array} point b
 * @param [bool=false]
 */

params [
    ["_a", [0, 0, 0]],
    ["_b", [0, 0, 0]],
	["_3D", false, [false]]
];

hint "Called!";

_x = 10;
