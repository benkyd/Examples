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

_xD = (_x select 0) - (_y select 0);
_yD = (_x select 1) - (_y select 1);
_zD = (_x select 2) - (_y select 2);

_result = sqrt [_xD + _yD + _zD];

_result;
