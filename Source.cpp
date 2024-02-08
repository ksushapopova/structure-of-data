#include "queue.h"

#include <iostream>   
#include <string> 

std::string doubling(Queue& qtext)
{
    Queue letters;
    std::string result = "";
    int len = qtext.size();
    if (len % 2 != 0)
    {
        for (int i = 0; i <= len - 1; i++)
        {
            letters.enqueue(qtext.peek());
            if (i == len / 2)
            {
                letters.enqueue(qtext.peek());

            }
            qtext.dequeue();
        }
        while (!letters.is_empty())
        {
            result += letters.peek();
            letters.dequeue();
        }

    }
    else
    {
        while (!qtext.is_empty())
        {
            result += qtext.peek();
            qtext.dequeue();
        }
                
    }

    return result;
}

int main()
{
    std::string text = "The weather is good today";
    std::cout << text << std::endl;
    Queue qtext;
    for (char c : text)
    {
        if (c != ' ')
        {
            qtext.enqueue(c);
        }
        else
        {
            std::cout << doubling(qtext) << " ";
            while (!qtext.is_empty())
            {
                qtext.dequeue();
                
            }
        }

    }
    std::cout << doubling(qtext) << " ";
    
    return 0;
}