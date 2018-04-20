using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TextAdventure1
{
    class Program
    {
        static void Main()
        {
            Console.BackgroundColor = ConsoleColor.White;
            Console.ForegroundColor = ConsoleColor.Black;

            Game c = new Game();
            c.start();
        }
    }


    class Game
    {
        public string Level { get; private set; } = "Introduction";
        public int Food { get; private set; } = 10;
        public int Water { get; private set; } = 10;
        public int Comfort { get; private set; } = 5;
        public int PlayerHunger { get; private set; } = 10;
        public int PlayerHealth { get; private set; } = 10;
        public int Radiation { get; private set; } = 10;
        public int TimePassed { get; private set; } = 0;
        public bool EatSuccess { get; private set; } = false;
        public bool RadiationSuit { get; private set; } = false;


        private void Save()
        {
            Console.Clear();

            string SaveGame = Level + "," + Food + "," + Water + "," + Comfort + ","
                + PlayerHealth + "," + PlayerHunger + "," + Radiation + "," + RadiationSuit;
             
            var SaveGameBytes = Encoding.UTF8.GetBytes(SaveGame);
            string SaveGame64 = Convert.ToBase64String(SaveGameBytes);

            Console.WriteLine("Saving the game will overwrite any existing saves, are you sure you want to continue? Y/N");
            var response = Console.ReadKey();
            Console.WriteLine();
            switch (response.KeyChar)
            {
                case 'Y':
                case 'y':
                    File.WriteAllText("Save.sav", SaveGame64);
                    return;
                case 'N':
                case 'n':
                    return;
            }
            return;
        }

        private void Load()
        {
            Console.Clear();

            if (File.Exists("Save.sav"))
            {
                int LoadSuccess = 1;

                while (LoadSuccess == 1)
                {
                    if (Food > 10)
                    {
                        LoadSuccess = 0;
                    }
                    else if (Water > 10)
                    {
                        LoadSuccess = 0;
                    }
                    else if (PlayerHealth > 10)
                    {
                        LoadSuccess = 0;
                    }
                    else if (Comfort > 10)
                    {
                        LoadSuccess = 0;
                    }
                    else
                    {
                        string content64 = File.ReadAllText("Save.sav");
                        var contentbytes = Convert.FromBase64String(content64);
                        string content = Encoding.UTF8.GetString(contentbytes);

                        string[] variables = content.Split(',');

                        string level = variables[0];
                        Food = int.Parse(variables[1]);
                        Water = int.Parse(variables[2]);
                        Comfort = int.Parse(variables[3]);
                        PlayerHealth = int.Parse(variables[4]);
                        PlayerHunger = int.Parse(variables[5]);
                        Radiation = int.Parse(variables[6]);
                        RadiationSuit = Convert.ToBoolean(variables[7]);

                        Console.WriteLine("Succesfully loaded the games state");
                        Console.WriteLine("Press enter to continue");
                        Console.ReadKey();

                        switch (level)
                        {
                            case "Introduction":
                                Introduction();
                                break;
                            case "GameStart":
                                GameStart();
                                break;
                            case "Branch_1_1":
                                Branch_1_1();
                                break; 
                            case "Branch_2_1":
                                Branch_2_1();
                                break;
                            case "Branch_3_1":
                                Branch_3_1();
                                break;
                            case "Branch_1_1_1":
                                Branch_1_1_1();
                                break;
                            case "Branch_1_1_2":
                                Branch_1_1_2();
                                break;
                            case "Branch_1_1_3":
                                Branch_1_1_3();
                                break;
                            case "Branch_2_1_1":
                                Branch_2_1_1();
                                break;
                            case "Branch_2_1_2":
                                Branch_2_1_2();
                                break;
                            case "Branch_2_1_3":
                                Branch_2_1_3();
                                break;
                            case "Branch_3_1_1":
                                Branch_3_1_1();
                                break;
                            case "Branch_3_1_2":
                                Branch_3_1_2();
                                break;
                            case "Branch_3_1_3":
                                Branch_3_1_3();
                                break;
                        }
                        return;
                    }
                }
                
                if (LoadSuccess == 0)
                {
                    Console.WriteLine("The load failed, maybe you eddited a value or there is an invalid entry");
                    Console.WriteLine("Press enter to continue");
                    Console.ReadKey();
                    Introduction();
                }
            }
            else
            {
                Console.WriteLine("There is no savegame available");
                Console.WriteLine("Press enter to continue");
                Console.ReadKey();
                Introduction();
            }
        }


        #region Engine

        private void NextLevelFunction()
        {
            Timepassed();

        }

        private void Timepassed()
        {
            //timepased based on moves, call at every function start
        }

        private string GetRadiation()
        {
            string radiation = null;

            radiation = Convert.ToString(Radiation);

            if (Radiation == 10)
            {
                YouDied("Radiation Poisoning");
            }

            return radiation;
        }

        public void RadiationZone(int FalloutLevel) //DO DIS WHERE IF THERE IS LESS FALLOUT THEN LESS RADIATION POISONING
        {   
            if (RadiationSuit == false)
            {
                if (FalloutLevel >= 8)
                {
                    Radiation++;
                    Radiation++;
                    Radiation++;
                }
                else if (FalloutLevel == 7 || FalloutLevel == 6)
                {
                    Radiation++;
                    Radiation++;
                }
                else if (FalloutLevel == 5 || FalloutLevel == 4 || FalloutLevel == 3)
                {
                    Radiation++;
                }
            }

            if (Radiation == 8 || Radiation == 7)
            {
                PlayerHealth--;
            }
            else if (Radiation > 9)
            {
                PlayerHealth--;
                PlayerHealth--;
            }

            if (Radiation == 10)
            {
                YouDied("Radiation Poisoning");
            }
        }

        public string HaveRadiationSuit()
        {
            string have = null;

            if (RadiationSuit)
            {
                have = "You have a radiation suit";
            }
            else
            {
                have = "You do not have a radiation suit";
            }

            return have;
        }

        private string GetComfort()
        {
            string localComfort = null;
            Comfort--;

            if (Comfort == 4 || Comfort == 5 || Comfort == 6)
            {
                localComfort = "You are comfortable, but could certainly be more comfterble";
            }


            if (Comfort <= 0)
            {
                YouDied("Bored to death");
            }

            return localComfort;
        }

        private string Hungry()
        {
            string Localhunger = null;

            if (PlayerHunger >= 10)
            {
                Localhunger = "You are not hungry";
            }
            else if (PlayerHunger == 9 || PlayerHunger == 8 || PlayerHunger == 7)
            {
                Localhunger = "Could do with a snack";
            }
            else if (PlayerHunger == 6 || PlayerHunger == 5)
            {
                Localhunger = "You are hungry now, but can go on for a while without food for a little while longer";
            }
            else if (PlayerHunger == 4)
            {
                Localhunger = "You are getting quite hungry now, you should probably think about eating";
            }
            else if (PlayerHunger == 3)
            {
                Localhunger = "You are getting really hungry now";
            }
            else if (PlayerHunger == 2)
            {
                Localhunger = "You are getting really hungry now, you cant go on much longer without food";
            }
            else if (PlayerHunger == 1)
            {
                Localhunger = "You are starving now, if you dont eat, you will surely die";
            }
            else
            {
                YouDied("Starvation");
            }

            return Localhunger;
        }

        private string Eat()
        {
            if (Food <= 0 || Water <= 0 || PlayerHunger >= 10)
            {
                EatSuccess = false;
            }
            else if (Food > 0 && Water > 0)
            {
                EatSuccess = true;
            }

            string eatstring = EatString();

            return eatstring;
        }
        private string EatString()
        {
            string EatString = null;

            if (EatSuccess)
            {
                EatString = "You have eaten";
                PlayerHunger++;
                Food--;
                Water--;
            }
            else
            {
                EatString = "You do not have enough food to do that";
            }

            return EatString;
        }

        public string GetHealth()
        {
            string health = "Your health is at " + PlayerHealth + "/10";

            if (PlayerHealth <= 0)
            {
                YouDied("Your health reached 0");
            }

            return health;
        }

        public void HungerDown()
        {
            Random rnd = new Random();
            int HungerDown = rnd.Next(1, 3);
            if (HungerDown == 1)
            {
                PlayerHunger--;
            }
            return;
        }

        public void YouDied(string CauseOfDeath)
        {
            Console.BackgroundColor = ConsoleColor.DarkRed;
            Console.Clear();
            Console.WriteLine("You died");
            Console.WriteLine("Cause of death: {0}", CauseOfDeath);
            Console.WriteLine("You can try (A)gain, or (Q)uit");
            var response = Console.ReadKey();
            Console.WriteLine();
            switch (response.KeyChar)
            {
                case 'A':
                case 'a':
                    Console.BackgroundColor = ConsoleColor.White;
                    Introduction();
                    break;
                case 'Q':
                case 'q':
                    Console.WriteLine("Thanks for playing");
                    Environment.Exit(0);
                    break;
            }
        }
        #endregion






        public void start()
        {
            Introduction();
        }

        public void Introduction()
        {
            GetHealth();
            Level = "Introduction";
            Console.Clear();
            Console.WriteLine("Welcome to this game about the boring apocolipse");
            Console.WriteLine("In this game you have to make decisions in order to progress though the game");
            Console.WriteLine("To load from a previous save press L");
            Console.WriteLine("You can press S to save at any point throughout the game");
            Console.WriteLine("Do you wish to continue?");

            Console.WriteLine();
            Console.WriteLine("(C)ontinue (Q)uit (L)oad");

            var response = Console.ReadKey();
            Console.WriteLine();
            switch (response.KeyChar)
            {
                case 'C':
                case 'c':
                    GameStart();
                    break;

                case 'Q':
                case 'q':
                    Console.WriteLine("Thanks for playing");
                    break;

                case 'L':
                case 'l':
                    Load();
                    break;

                case 'S':
                case 's':
                    Save();
                    Introduction();
                    break;
            }
        }

        private void GameStart()
        {
            Level = "GameStart";
            Console.Clear();
            Console.WriteLine("Our story starts in a suburb of New York");
            Console.WriteLine("You hear a nuclear siren, and your phone warns you off a possible nuclear strike at your location");
            Console.WriteLine("You are faced with a decision to either get to the nuclear bunker, hide in your house or do nothing");

            Console.WriteLine();
            Console.WriteLine("Neuclear bunker (1) Hide (2) Do nothing (3)");

            var response = Console.ReadKey();
            Console.WriteLine();
            switch (response.KeyChar)
            {
                case '1':
                    Console.WriteLine("You choose Get to the Bunker");
                    break;

                case '2':
                    Console.Clear();
                    Console.WriteLine("You choose Hide");
                    Console.WriteLine("Enter to continue");
                    Console.ReadKey();
                    YouDied("Nuclear annihilation");
                    break;

                case '3':
                    Console.Clear();
                    Console.WriteLine("You choose Do Nothing");
                    Console.WriteLine("Enter to continue");
                    Console.ReadKey();
                    YouDied("Nuclear annihilation");
                    break;

                case 'S':
                case 's':
                    Save();
                    GameStart();
                    break;
            }

            HungerDown();
            GetHealth();

            Eaten:
            Console.Clear();
            Console.WriteLine("You are now in the Nuclear Bunker");
            Console.WriteLine("You have survived the initial nuclear blast you now have to continue to survive");
            Console.WriteLine();
            Console.WriteLine("You managed to grab {0} food and {1} water before the blast", Food, Water);
            Console.WriteLine("F to eat 1 food (your hunger level is now at {0}/10)", PlayerHunger);
            Console.WriteLine(Hungry());
            Console.WriteLine();
            Console.WriteLine("From here, you can go outside and search for supplies, search the fallout bunker for a radiation suit or " +
                "rest and wait for the fallout to pass slightly, reducing the chance of radiation poisoning (this will consume 6 hunger)");

            Console.WriteLine();
            Console.WriteLine("Go outside (1) Search inside (2) Rest and wait (3)");

            response = Console.ReadKey();
            Console.WriteLine();
            switch (response.KeyChar)
            {
                case '1':
                    Branch_1_1();
                    break;

                case '2':
                    Branch_2_1();
                    break;

                case '3':
                    Branch_3_1();
                    break;

                case 'F':
                case 'f':
                    Eat();
                    goto Eaten;

                case 'S':
                case 's':
                    Save();
                    GameStart();
                    break;
            }
        }

        private void Branch_1_1()
        {
            Level = "Branch_1_1";
            RadiationZone(1); //THIS NEEDS TO CHANGE ONCE U DONE THE THING WITH CALCULATING FALLOUT BASED ON TIME PASSED
            HungerDown();
            GetHealth();

            Eaten:
            Console.Clear();
            Console.WriteLine("You choose to go outside and search for any possible supplies");
            Console.WriteLine("You currently have {0} water {1} food", Water, Food);
            Console.WriteLine();
            Console.WriteLine("You are outside of the bunker now, it is radioactive out here, your current radioactivity level is {0}/10." +
                "The higher it gets, the more dangerous it is. Bad stuff happens when your radioactivity level gains. The longer " +
                "you spend outside, the higher it will get. If you have a radiation suit, all radiation and damage will be " +
                "negated.", GetRadiation());
            Console.WriteLine();
            Console.WriteLine(HaveRadiationSuit());
            Console.WriteLine(GetHealth());
            Console.WriteLine();
            Console.WriteLine("F to eat 1 food (your hunger level is now at {0}/10)", PlayerHunger);
            Console.WriteLine(Hungry());
            Console.WriteLine();
            Console.WriteLine("From here, you can search for Food, Water or Comforts to make you more comfortable this will mean that you get less " +
                "bored and therefore are less likely to die, your current comfort level is {0}/10, the lower your health the lower your" +
                "comfort and a higher chance of death.", Comfort);

            Console.WriteLine();
            Console.WriteLine("Food (1) Water (2) Comforts (3)");

            var response = Console.ReadKey();
            Console.WriteLine();
            switch (response.KeyChar)
            {
                case '1':
                    Branch_1_1_1();
                    break;

                case '2':
                    Branch_1_1_2();
                    break;

                case '3':
                    Branch_1_1_3();
                    break;

                case 'F':
                case 'f':
                    Eat();
                    goto Eaten;

                case 'S':
                case 's':
                    Save();
                    Branch_1_1();
                    break;
            }

        }

        private void Branch_2_1()
        {
            Level = "Branch_2_1";
            HungerDown();
            GetHealth();

            Eaten:
            Console.Clear();
            Console.WriteLine("You choose to stay inside and search the fallout shelter for a radiation suit");
            Console.WriteLine("You currently have {0} water {1} food", Water, Food);
            Console.WriteLine();
            Console.WriteLine("You wonder the inside of the bunker in search for a radiation suit, this is a very mundane task, you are getting " +
                "quite bored, {0}, you should probably try and find comforts when you get out of the bunker.", GetComfort());
            Console.WriteLine("You can see a radiation suit in the distance. However it is smotherd in flames and there is no easy way to get it.");
            Console.WriteLine();
            Console.WriteLine(HaveRadiationSuit());
            Console.WriteLine(GetHealth());
            Console.WriteLine();
            Console.WriteLine("F to eat 1 food (your hunger level is now at {0}/10)", PlayerHunger);
            Console.WriteLine(Hungry());
            Console.WriteLine();
            Console.WriteLine("From here you can try and grab the radiation suit from the fire, try and use the water you have to extinguish" +
                "the flames, or disregard the radiation sut and go outside anyway.");

            Console.WriteLine();
            Console.WriteLine("Go for it (1) Extinguish flames (2) Disregard (3)");

            var response = Console.ReadKey();
            Console.WriteLine();
            switch (response.KeyChar)
            {
                case '1':
                    Branch_2_1_1();
                    break;

                case '2':
                    Branch_2_1_2();
                    break;

                case '3':
                    Branch_1_1();
                    break;

                case 'F':
                case 'f':
                    Eat();
                    goto Eaten;

                case 'S':
                case 's':
                    Save();
                    Branch_2_1();
                    break;
            }
        }

        private void Branch_3_1()
        {
            Level = "Branch_3_1";
            HungerDown();
            GetHealth();

            Eaten:
            Console.Clear();
            Console.WriteLine("You choose to");
            Console.WriteLine("You currently have {0} water {1} food", Water, Food);
            Console.WriteLine();
            Console.WriteLine("");
            Console.WriteLine("");
            Console.WriteLine();
            Console.WriteLine(HaveRadiationSuit());
            Console.WriteLine(GetHealth());
            Console.WriteLine();
            Console.WriteLine("F to eat 1 food (your hunger level is now at {0}/10)", PlayerHunger);
            Console.WriteLine(Hungry());
            Console.WriteLine();
            Console.WriteLine("From here you can ");

            Console.WriteLine();
            Console.WriteLine("Go for it (1) Extinguish flames (2) Disregard (3)");

            var response = Console.ReadKey();
            Console.WriteLine();
            switch (response.KeyChar)
            {
                case '1':
                    Branch_3_1_1();
                    break;

                case '2':
                    Branch_3_1_2();
                    break;

                case '3':
                    Branch_3_1_3();
                    break;

                case 'F':
                case 'f':
                    Eat();
                    goto Eaten;

                case 'S':
                case 's':
                    Save();
                    Branch_3_1();
                    break;
            }
        }


        private void Branch_1_1_1()
        {
            Level = "Branch_1_1_1";
            HungerDown();
        }

        private void Branch_1_1_2()
        {
            Level = "Branch_1_1_2";
            HungerDown();
        }

        private void Branch_1_1_3()
        {
            Level = "Branch_1_1_3";
            HungerDown();
        }



        private void Branch_2_1_1()
        {
            Level = "Branch_2_1_1";
            HungerDown();
        }

        private void Branch_2_1_2()
        {
            Level = "Branch_2_1_2";
            HungerDown();
        }
        private void Branch_2_1_3()
        {
            Level = "Branch_2_1_3";
            HungerDown();
        }



        public void Branch_3_1_1()
        {
            Level = "Branch_3_1_1";
            HungerDown();
        }

        public void Branch_3_1_2()
        {
            Level = "Branch_3_1_2";
            HungerDown();
        }

        public void Branch_3_1_3()
        {
            Level = "Branch_3_1_3";
            HungerDown();
        }
    }
}