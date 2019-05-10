/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_triggerStart.sqf
 *
 *  Triggers the start of the mission and starts
 *  all neccesary systems for the mission
 */

// Throws missing ';' error at compiletime
if (gMissionStarted) exitWith {
	hint "You have already started a mission! Complete that first!";
};

gMissionStarted = true;

private _deliveryPoint = [] call RR_fnc_getDeliveryPoint;

private _deliveryPointMarkerR = createMarkerLocal ["RR_Delivery_Radius", _deliveryPoint];
_deliveryPointMarkerR setMarkerShapeLocal "ELLIPSE";
_deliveryPointMarkerR setMarkerSizeLocal [500, 500];
_deliveryPointMarkerR setMarkerColorLocal "ColorRed";

private _deliveryPointMarker = createMarkerLocal ["RR_Delivery_Point", _deliveryPoint];
_deliveryPointMarker setMarkerTypeLocal "mil_objective";
_deliveryPointMarker setMarkerTextLocal "Delivery Point";

// Get distance to mission from player, update while mission goes on
private _distanceToPoint = 0;

// Heli spawm (Hard coded eww) [10064.9,12045.4,0.00141716]

// Lookup table of available shit
private _helis = [
	["B_Heli_Transport_03_unarmed_F",       "Huron"],
	["B_Heli_Transport_03_unarmed_green_F", "Huron"]
];

private _missionHeliIndex = floor random count _helis;
private _missionHeliClass = _helis select _missionHeliIndex select 0;
private _missionHeliName = _helis select _missionHeliIndex select 1;
gMissionHeli = createVehicle [_missionHeliClass, [10064.9,12045.4,0.00141716], [], 0];

gMissionHeli setVariable ["RR_Mission_Heli", gMissionHeli];

// Transport Item spawm (Hard coded eewwwwwwwww) [10085.4,12076.8,0.00141335]

private _items = [
	["O_T_Quadbike_01_ghex_F", "Quadbike"],
	["C_Hatchback_01_F",       "Hatchback"],
	["C_Hatchback_01_sport_F", "Hatchback Sport"],
	["C_SUV_01_F",             "SUV"],
	["C_Offroad_02_unarmed_F", "Unarmed Offroad"],
	["C_Van_01_box_F",         "Truck Boxer"],
	["C_Van_01_transport_F",   "Truck"],
	["B_MRAP_01_F",            "Hunter"],
	["O_MRAP_02_F",            "IFRIT"],
	["IG_supplyCrate_F",       "Ammo Box"]
];

private _missionItemIndex = floor random count _items;
private _missionItemClass = _items select _missionItemIndex select 0;
private _missionItemName = _items select _missionItemIndex select 1;
gMissionDelivery = createVehicle [_missionItemClass, [10085.4,12076.8,0.00141335], [], 0];

gMissionDelivery setVariable ["RR_Mission_Item", gMissionDelivery];

// Sling to vehicle
gMissionHeli setSlingLoad gMissionDelivery;

[
	player, "RR_Delivery_Task", 
	[format ["Deliver %1 to the marker", _missionItemName], "Delivery Mission", "Deliver Here"], 
	_deliveryPoint, "ASSIGNED", 1, 
	true, "ASSIGNED", true
] call BIS_fnc_taskCreate;


hint format ["Delivery Mission Started! Deliver the %1 to the marker on the map!", _missionItemName];
