/**
 * PROGRAM TO MAKE A DIAMOND
 */
using System;

namespace practice1
{
    class practice1
    {
        static void Main(string[] args)
        {
            Console.Write("Enter number of rows: ");
            int rows = Convert.ToInt32(Console.ReadLine());

            // Top Half
            for(int i = 0; i < rows; i++)
            {
                // Spaces
                for(int j = 1; j < rows - i; j++)
                {
                    Console.Write(" ");
                }

                // Asterisks
                for(int l = (i * 2) + 1; l > 0 ; l--)
                {
                    Console.Write("*");
                }
                
                Console.WriteLine();
            }

            // Bottom half
            for(int i = rows - 1; i >= 0; i--)
            {
                // Spaces
                for(int j = rows - i; j > 0; j--)
                {
                    Console.Write(" ");
                }

                // Asterisks
                for(int l = (i * 2) - 1; l > 0; l--)
                {
                    Console.Write("*");
                }

                Console.WriteLine();
            }
        }
    }
}