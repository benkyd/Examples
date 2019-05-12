/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_distance3D.sqf
 *
 *  Calculate 3D distance between 2 points in
 *  3D space
 */

params [
    ["_distance", 0, [0]]
];

private _fare = floor _distance * 3;

_fare;
