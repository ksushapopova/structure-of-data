#include "Double_list.h"
#include <fstream>

int main()
{
    setlocale(LC_ALL, "RU");
    Cellular sub[5] = {};
    Node* list = nullptr;
    Node* tail = nullptr;

    std::string house, flat, balance;
    std::ifstream file("Subscribes.txt");

    for (int i = 0; i < 5; i++)
    {
        std::getline(file, sub[i].name, ' ');
        std::getline(file, sub[i].surname, ' ');
        std::getline(file, sub[i].patronymic, ' ');
        std::getline(file, sub[i].home.street, ' ');
        std::getline(file, house, ' ');
        std::getline(file, flat, ' ');
        std::getline(file, sub[i].number, ' ');
        std::getline(file, balance, '\n');
        sub[i].home.house = std::stoi(house);
        sub[i].home.flat = std::stoi(flat);
        sub[i].balance = std::stoi(balance);
    }
    
    file.close();

    Cellular temp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sub[j].balance > sub[j+1].balance)
            {
                temp = sub[j];
                sub[j] = sub[j+1];
                sub[j+1] = temp;

            }
        }
    }
    for (int i = 0; i < 5; i++)
    {   if (list == nullptr)
            {
                AddToHead(list, tail, sub[0]);
            }
    else
    {
        AddToTail(list, tail, sub[i]);
    }
    }

    Print(list);
    std::cout << "______________________________________________________________________________" << "\n";
    delete_search_value(list, tail, 100); // void
    Print(list);
    }