/** 
 * Copyright© Benjamin Kyd 2019
 *     loadConfig.sqf
 */

private _stops = getArray (missionConfigFile >> "cfgBus" >> "stops" >> "names");
hint format ["%1", _stops];
