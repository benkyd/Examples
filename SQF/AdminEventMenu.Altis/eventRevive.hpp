class Life_Admin_EventRevive {
    idd = 9220;
    name= "Life_Admin_EventRevive";
    movingEnable = 0;
    enableSimulation = 1;

    class controlsBackground {
        class Life_RscTitleBackground: RscText {
            colorBackground[] = {0,0,0,0};
            idc = -1;
            x = 0.1;
            y = 0.2;
            w = 0.5;
            h = (1 / 25);
        };

        class MainBackground: RscText {
            colorBackground[] = {0, 0, 0, 0.7};
            idc = -1;
            x = 0.1;
            y = 0.2 + (11 / 250);
            w = 0.5;
            h = 0.3 - (22 / 250);
        };
    };

    class controls {
        class InfoMsg: RscStructuredText {
            idc = 9221;
            sizeEx = 0.020;
            text = "";
            x = 0.1;
            y = 0.25;
            w = 0.5;
            h = 0.11;
        };

        class Title: RscText {
            colorBackground[] = {0, 0, 0, 0};
            idc = -1;
            text = "Select Revive Radius";
            x = 0.1;
            y = 0.2;
            w = 0.5;
            h = (1 / 25);
        };

        class AdminCloseComp: RscButtonMenu {
            idc = -1;
            text = "Close";
			colorBackground[] = {0.6,0,0,1};
            onButtonClick = "closeDialog 0;";
            x = -0.06 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.5 - (1 / 25);
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class AdminCompensVer: RscButtonMenu {
            idc = -1;
            text = "Revive";
			colorBackground[] = {0.6,0,0,1};
            onButtonClick = "";
            x = 0.27;
            y = 0.40;
            w = (6.25 / 40);
            h = (1 / 25);
        };

        class AdminCompensTex: RscEdit {
            idc = 9222;
            text = "";
            x = 0.04 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
            y = 0.35;
            w = (13 / 40);
            h = (1 / 25);
        };
    };
};
