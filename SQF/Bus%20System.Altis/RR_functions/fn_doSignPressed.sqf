/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_doSignPressed.sqf
 *
 *  Bus sign was pressed, prepair to teleport
 *  player and do other such tasks
 */

params [
    ["_target", objNull, [objNull]],
    ["_caller", objNull, [objNull]],
	["_id", 0, [0]],
	["_args", [], [[]]]
];

private _dest = _args select 0;
private _price = _args select 1;

private _stops = getArray (missionConfigFile >> "cfgBus" >> "stops" >> "names");
private _locations = getArray (missionConfigFile >> "cfgBus" >> "stops" >> "locations");

private _positionInStops = 0;

if (!(_dest in _stops)) exitWith { };

private _i = 0;
{
	if (_x isEqualTo _dest) then { _positionInStops = _i; };
	_i = _i + 1; 
} forEach _stops;

// Take money from bank account

hint "Your bus will arrive in 10 seconds";
uiSleep 10;
hint "All aboard!";
uiSleep 1;

[(_locations select _positionInStops)] call RR_fnc_doTeleport;

hint format ["You have arrived at %1! Enjoy your stay", _dest];
