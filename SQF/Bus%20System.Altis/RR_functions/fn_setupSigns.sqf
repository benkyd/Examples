/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_setupSigns.sqf
 *
 *  Spawns and sets up signs at every location
 */

params [
    ["_stops", [], [[]] ],
    ["_locations", [], [[]] ]
];


private _signs = [];

private _i = 0;
{
    private _location = _locations select _i;
    // Create sign at location
    private _sign = createVehicle ["Land_InfoStand_V1_F", _location];
    
    // Add shit to sign
    private _j = 0;
    {
        private _destLocation = _locations select _j;
        private _distance = [_location, _destLocation] call RR_fnc_distance3D;

        private _price = [_distance] call RR_fnc_busFare;

        private _signName = format ["%1  £%2", _x, _price];

        _sign addAction [
            _signName, RR_fnc_doSignPressed, [_x, _price]
        ];
        _j = _j + 1;
    } forEach _stops;

    // Add sign to the array of signs
    _signs pushBack _sign;

    _i = _i + 1;
} forEach _stops;


// return signs
_signs;
