private _r = (sliderPosition 100) / 50;
private _g = (sliderPosition 101) / 50;
private _b = (sliderPosition 102) / 50;

// This is soooo broken, the colours flash n shit
Car setObjectTextureGlobal [ 0, format [ "#(rgb,8,8,3)color(%1,%2,%3,1)", _r, _g, _b ] ]
