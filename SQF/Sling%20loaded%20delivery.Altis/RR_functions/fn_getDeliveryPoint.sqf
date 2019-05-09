/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_getDeliveryPoint.sqf
 *
 *  Returns "random" coordinate as delivery point for the mission
 *
 * TODO: Make it actually random and _only_ available to spawn on land
 */


private _numItems = 22; // Number of elements in _deliveryPointArray - microoptimization
private _deliveryPointArray = [
	[21770,4911.36,0.681143],
	[23203.9,7446.1,0.012188],
	[11704,22809,0],
	[2844,20279.7,0],
	[14504.4,23426.4,0.0445493],
	[3030.39,10216,0.602249],
	[6357,2082,0.1],
	[7198,2533,0.1],
	[7226,2187,0.1],
	[8045,2835,0.1],
	[8577,2320,0.1],
	[9286,1902,0.1],
	[9840,1786,0.1],
	[10466,1886,0.1],
	[10243,1576,0.1],
	[10857,2275,0.1],
	[11939,3402,0.1],
	[11105,3009,0.1],
	[13509,6166,0.1],
	[13081,7804,0.1],
	[12940,9326,0.1],
	[13170,10292,0.1]
];

private _ret = _deliveryPointArray select floor random _numItems;

_ret;
