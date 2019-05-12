/** 
 * Copyright© Benjamin Kyd 2019
 *     init.sqf
 */


private _stops = getArray (missionConfigFile >> "cfgBus" >> "stops" >> "names");
private _locations = getArray (missionConfigFile >> "cfgBus" >> "stops" >> "locations");

private _signs = [_stops, _locations] call RR_fnc_setupSigns;
