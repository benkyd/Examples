/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_endDelivery.sqf
 *
 *  Does some checks and ends the delivery part of the mission.
 */

// Will always be passed so no need for defaults
params [
    ["_target", objNull, [objNull]],
    ["_caller", objNull, [objNull]],
	["_id", 0, [0]],
	["_args", [], [[]]]
];


if (!gMissionStarted) exitWith { };


private _closeObjects = nearestObjects [_target, [], 50];

if (!(gMissionDelivery in _closeObjects)) exitWith { };

// private _isFound = false;
// {
// 	if (_x isEqualTo gMissionDelivery) then { 
// 		_isFound = true; 
// 	}
// } forEach _closeObjects;

// if (!_isFound) exitWith { };

deleteVehicle gMissionDelivery;

["RR_Delivery_Task", "SUCCEEDED"] call BIS_fnc_taskSetState;

// Discustingly hardcoded coordinate for spawm again
[
	player, "RR_Return_Task", 
	["Return helicopter too base", "Return Heli", "Deliver Here"], 
	[10085.967, 12044.893, 0.00141716], "ASSIGNED", 1, 
	true, "ASSIGNED", true
] call BIS_fnc_taskCreate;

// Remove map markers
deleteMarkerLocal "RR_Delivery_Radius";
deleteMarkerLocal "RR_Delivery_Point";

gMissionCompleted = true;

hint "Congradulations, you have delivered the package, now return the helicopter to recive your payment!";
