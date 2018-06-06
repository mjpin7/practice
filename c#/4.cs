/**
 * Basic LINQ
 */
using System;
using System.Collections.Generic;
using System.Linq;

namespace practice4
{
    class practice4
    {
        static void Main(string[] args)
        {
            bool end = false;

            // Have contiuous loop until user decides to exit
            while(!end)
            {
                // Get input
                Console.Write("What would you like to do?: ");
                string input = Console.ReadLine();

                // Do corresponding action
                if(input == "positive")
                {
                    Console.WriteLine("Finding positive numbers from list.");
                    Console.Write("\n");

                    // Get input for list, parse the string into an array
                    Console.Write("Enter the list seperated by spaces: ");
                    string[] inn = Console.ReadLine().Split(' ');
                    int[] myList = new int[inn.Length];

                    // Convert and store the strings to ints 
                    for(int i = 0; i < inn.Length; i++)
                    {
                        myList[i] = Convert.ToInt32(inn[i]);
                    }

                    // LINQ query 
                    var posQ = 
                    from x in myList
                    where x > 0
                    select x;

                    // If the query returns empty (no positive numbers)
                    if(!posQ.Any())
                    {
                        Console.WriteLine("There were no positive numbers in the list given.");
                    }
                    else
                    {
                        Console.Write("The poitive number(s) found is/are: ");

                        foreach(var x in posQ)
                        {
                            Console.Write("{0} ", x);
                        }
                        Console.Write("\n");
                    }
                }
                else if(input == "freq")
                {
                    Console.WriteLine("Finding frequencies of characters in a string\n");

                    // Get string input
                    Console.Write("Enter a string: ");
                    string freq_val = Console.ReadLine();

                    // LINQ query
                    var freq_q = 
                    from character in freq_val
                    group character by character into c
                    select c;

                    // Print the summary
                    foreach(var x in freq_q)
                    {
                        Console.WriteLine("The character {0} appeared {1} time(s)", x.Key, x.Count());
                    }
                    Console.Write("\n");
                }
                else if(input == "quit")
                {
                    Console.WriteLine("Goodbye.");
                    end = true;
                }
                else
                {
                   Console.WriteLine("Commands are \"positive\", \"freq\", and \"quit\"");
                }

                Console.Write("\n");
            }
        }
    }
}