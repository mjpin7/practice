using System;

namespace practice2
{
    class practice2
    {
        static bool isPrime(int n)
        {           
            int tally = 0;

            // Check the divisors
            for(int i = 2; i < n; i++)
            {
                if(n % i == 0)
                {
                    tally++;
                    break;
                }
                    
            }

            // If it found another number that is divisible or the number is 1, false
            if(tally > 0 || n == 1)
                return false;
            
            return true;
        }

        static void Main(string[] args)
        {
            string prime = " is a prime number.";
            string notPrime = " is not a prime number.";

            // Get user input
            Console.Write("Enter a number: ");
            int num = Convert.ToInt32(Console.ReadLine());

            // Handle whether prime or not
            if(isPrime(num))
            {
                Console.WriteLine(num + prime);
            }
            else
            {
                Console.WriteLine(num + notPrime);
            }
        }
    }
}