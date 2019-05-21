/** 
 * Copyright© Benjamin Kyd 2019
 *     fn_removeBlindfold.sqf
 *
 *  Removes blindfold from player
 */

if (!RR_Blindfolded) exitWith {};

player unlinkItem "G_Balaclava_lowprofile";
0 cutFadeOut 1;

RR_Blindfolded = false;
