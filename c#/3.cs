/**
 * Program that takes input a list of integers and lists the elements missing from the range
 */
using System;
using System.Collections.Generic;

namespace practice3
{
    class practice3
    {
        
        static List<int> checkList(int[] in_array)
        {
            // Sort array, find the range
            Array.Sort(in_array);
            int start = in_array[0];
            int end = in_array[in_array.Length - 1];

            List<int> myList = new List<int>();

            // Go through the range and if a number does not exist in the given array store that number in a list
            for(int i = start + 1; i < end; i++)
            {
                if(!(Array.Exists(in_array, element => element == i)))
                {
                    myList.Add(i);
                }
            }

            return myList;
        }

        static void Main(string[] args)
        {
            // Get the input
            Console.Write("Enter a list of numbers seperated by spaces: ");
            // Parse the input into a string array, split by spaces
            string[] input = Console.ReadLine().Split(' ');
            // Create new array to store the acual ints
            int[] inputNum = new int[input.Length];

            // Convert and store the strings to ints 
            for(int i = 0; i < input.Length; i++)
            {
                inputNum[i] = Convert.ToInt32(input[i]);
            }

            // Get the list of numbers missing
            List<int> endList = checkList(inputNum);
            Array.Sort(inputNum);

            // If the list was empty, no missing numbers were found
            if(endList.Count == 0)
            {
                Console.Write("There were no missing numbers in the range {0} to {1}.", inputNum[0], inputNum[inputNum.Length - 1]);
            }
            // Else, there were numbers missing. Print them out
            else
            {
                Console.Write("There were {0} missing number(s) in the range {1} to {2}, number(s) is/are: ", endList.Count, inputNum[0], inputNum[inputNum.Length - 1]);
                foreach(int num in endList)
                {
                    Console.Write("{0} ", num);
                }
            }  
        }
    }
}