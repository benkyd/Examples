hint "This is pretty neat";

waitUntil {isDedicated || (!isNull player)};
if (local player) then {
	player addAction ["Admin Event Menu","menuGUI.sqf",1];
};
