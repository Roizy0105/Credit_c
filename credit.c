#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //get credit card number
    long cardNumber = get_long("Please enter your credit card number:");
    //int length = strlen(cardNumber);
    
    //creating an array to store the digits in
    int array[16];
    //created this int to keep track where in the array we are
    int i = 0;
    
    //these variaubles will help to add and multipy the card number so that we know if it's valid or not
    int sum_one = 0;
    int sum_two = 0;
    int q = 0;
    
    //iterating through the int taking down the last digit
    while (cardNumber != 0)
    {
        //this formula will give me the last digit
        int n = (cardNumber % 10);
        //put the digits into the array in revers 
        array[i] = n;
        i++;
        sum_one += n;
        
        //devide the card number by 10 to get the next digit next time i loop
        cardNumber /= 10;
        
        if (cardNumber != 0)
        {
            //get the las digit of the card number
            int m = (cardNumber % 10);
            //add it to the array
            array[i] = m;
            i++;
            int p = m * 2;
            if (p > 9)
            {
                while (p != 0)
                {
                    q = (p % 10);
                    sum_two += q;
                    p /= 10;
                }
                
            }
            else 
            {
                sum_two += p;  
            }
            
            //this will make sure we get the next last digit next time w itterate
            cardNumber /= 10;
        }
        
    }
    
    //add the equestion from the card numbers together
    int total = sum_one + sum_two;
    //get the last number of the total
    int valid = total % 10;
    printf("%i\n", valid);
    //if its not 0 then exit 
    if (valid != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //check to see if it's american express
    if (i == 15)
    {
        if (array[i - 1] == 3 && (array[i - 2] == 4 || array[i - 2] == 7))
        {
            printf("AMEX\n");
            return 0;
        }
        
    }
    
    // check to see if it's mastercard or visa
    else if (i == 16)
    {
        if (array[i - 1] == 5 && (array[i - 2] == 1 || array[i - 2] == 2 || array[i - 2] == 3 || array[i - 2] == 4 || array[i - 2] == 5))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (array[i - 1] == 4)
        {
            printf("VISA\n");
            return 0;
        }
    }
    else if (i == 13)
    {
        if (array[i - 1] == 4)
        {
            printf("VISA\n");
            return 0;
        }
    }
    printf("INVALID\n");
    return 0;
  
}

