/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_applyBlindfold.sqf
 *
 *  Applies blindfold to player
 */

params [
    ["_unit",Objnull,[Objnull]]
];

if (RR_Blindfolded) exitWith {};

if (!(player getVariable ["RR_restrained",false])) exitWith {};

cutText["You are blindfolded and can not see.","BLACK FADED"];
0 cutFadeOut 9999999;

_goggles = Goggles player;
player unassignItem _goggles;
player linkItem "G_Balaclava_lowprofile";

RR_Blindfolded = true;
