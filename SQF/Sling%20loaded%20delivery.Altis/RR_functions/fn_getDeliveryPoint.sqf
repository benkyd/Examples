/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_getDeliveryPoint.sqf
 *
 *  Returns "random" coordinate as delivery point for the mission
 *
 * TODO: Make it actually random and _only_ available to spawn on land
 */

// These are hardcoded for reasons that i forgot
// I could have easily named the objects on the map and 
// Done a getPos on the object
// But whatever it is what it is
private _deliveryPointArray = [
	[4882.485, 20331.756, 0.0],
	[12982.635, 20233.861, 0.0],
	[13860.438, 15573.917, 0.0],
	[14607.452, 16738.375, 0.0],
	[23147.25, 18668.283, 0.0],
	[21285.926, 13470.976, 0.0],
	[3741.44, 13358.252, 0.0]
];

private _ret = _deliveryPointArray select floor random count _deliveryPointArray;

_ret;
