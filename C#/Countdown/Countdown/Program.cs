using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Countdown
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("How long to launch?");

            int lost = 0; //declare lost value at 0 - rocket is intact
            int time = int.Parse(Console.ReadLine()); //declare and define the countdown timer length 
            Console.Clear();

            Random crash = new Random(); //declare the random chance of crashing

            Console.WriteLine("t-{0} secconds to launch", time); //confirms the countdown timer
            System.Threading.Thread.Sleep(1500); //waits for 1.5 seconds
            Console.Clear();

            while (time > 0) //while the time is greater than 0
            {
                if (time != 3) //if the time is not 3 then write this
                {
                    Console.WriteLine("t-{0}", time);
                }
                else //if the time is 3 write this
                {
                    Console.WriteLine("Main engines start");
                }

                time--; //keeps counting down every second
                System.Threading.Thread.Sleep(1000);
                Console.Clear();

                if (time == 0 && lost == 0) //once the time is 0 the rocket lifts off
                {
                    if (crash.Next(1, 100) < 20) //20% chance of exploding on pad
                    {
                        lost = 1;
                        break;
                    }
                    else //carys on with launch sequence
                    {
                        Console.WriteLine("We have liftoff");
                        System.Threading.Thread.Sleep(1000);
                        Console.Clear();
                        break;
                    }
                }

                if (lost == 1) //checks to see if the rocket was lost, if so breaks out of the loops
                {
                    break;
                }
            }
                time = 1; //sets the time to 1, so it can count up

                while (time >= 0) 
                {
                    if (time != 5) //if the time is not 5 then write this 
                    {
                        Console.WriteLine("t+{0}", time);
                    }
                    else //if the time is 5 then write this 
                    {
                        Console.WriteLine("We have Cleared the tower");
                    }

                    time++; //keeps counting up every second
                    System.Threading.Thread.Sleep(1000);
                    Console.Clear();

                    if (time < 40) //while the rocket has been in the air for less than 40 secconds there is a 5% chance each seccond of exploding
                    {
                        if (crash.Next(1, 100) < 5)
                        {
                            lost = 1;
                            break;
                        }
                    }
                }
            
            Console.WriteLine("We have lost the rocket at t+{0}", time); //lost message along with time lost
            Console.ReadKey(); //keeps console open
        }
    }
}
