using System;

namespace ConsoleApp2
{
    class Program
    {
        public static void Main()
        {
            int Correct = 0;
            int Remaining_lives = 5;
            string Life;

            Console.WriteLine("WHAT ARE THE TWO ASPECTS OF LIFE? YOU HAVE {0} LIVES", Remaining_lives);

            Life = Console.ReadLine();

            while (Correct == 0 & Remaining_lives >= 0)
                {
                if (Life.ToLower() == "tabletop lithium and sainsburys self checkout" || Life.ToLower() == "sainsburys self checkout and tabletop lithium")
                {
                    Console.WriteLine("YOU HAVE SUCCEDED AT LIFE");
                    Correct = 1;
                    Console.ReadKey();
                }

                else
                {
                    if (Remaining_lives == 1)
                    {
                        Console.WriteLine("YOU HAVE NO REMAINING LIVES, YOU HAVE FAILED AT LIFE");
                        Console.ReadLine();
                    }
                   else
                    {
                        if (Remaining_lives <= 1)
                        {
                         
                        }
                        else
                        {
                            Remaining_lives--;
                            Console.WriteLine("YOU HAVE FAILED AT LIFE, YOU HAVE {0} LIVES LEFT", Remaining_lives);
                            Life = Console.ReadLine();
                        }
                    }
                }
            }
        }
    }
}