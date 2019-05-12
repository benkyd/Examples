/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_distance3D.sqf
 *
 *  Calculate 3D distance between 2 points in
 *  3D space
 */

params [
    ["_x", [], [[]]],
    ["_y", [], [[]]]
];

private _result = 0;

_xD = (_y select 0) - (_x select 0);
_yD = (_y select 1) - (_x select 1);
_zD = (_y select 2) - (_x select 2);

_xD = _xD * _xD;
_yD = _yD * _yD;
_zD = _zD * _zD;

private _d = _xD + _yD + _zD;

if (!(_d isEqualTo 0)) then {
    _result = sqrt _d;
};

_result;
