hint "Okay, this is epic";

private _dialouge = createDialog "MyDialog";

private _carTextures; // Get available textures of car

waitUntil { !_dialouge };
hint "closed";

// Car setObjectTexture [ 0, "#(rgb,8,8,3)color(1,0,0,1)" ]
