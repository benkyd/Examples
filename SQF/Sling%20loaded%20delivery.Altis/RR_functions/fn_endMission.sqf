/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_endDelivery.sqf
 *
 *  Ends mission with delivery of helicopter
 */

// Will always be passed so no need for defaults
params [
    ["_target", objNull, [objNull]],
    ["_caller", objNull, [objNull]],
	["_id", 0, [0]],
	["_args", [], [[]]]
];


if (!gMissionStarted) exitWith { };
if (!gMissionCompleted) exitWith { };


private _closeObjects = nearestObjects [_target, [], 50];

if (!(gMissionHeli in _closeObjects)) exitWith { };

// private _isFound = false;
// {
// 	if (_x isEqualTo gMissionHeli) then { 
// 		_isFound = true; 
// 	}
// } forEach _closeObjects;
//
// if (!_isFound) exitWith { };


deleteVehicle gMissionHeli;

["RR_Return_Task", "SUCCEEDED"] call BIS_fnc_taskSetState;

hint "You have recieved £xxx for your services";

gMissionStarted = false;
gMissionCompleted = false;
