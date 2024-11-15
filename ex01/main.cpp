
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>


void    printCommands(void)
{
    std::cout << "Available commands :" << std::endl;
    std::cout << " \tADD - Add a new contact" << std::endl;
    std::cout << " \tSEARCH - search for a contact in the Phonebook" << std::endl;
    std::cout << " \tEXIT - exit the Phonebook" << std::endl;
}

int    promptIndex(void)
{
    int id; 
    std::cout << "Contact index: " << std::flush;
    std::cin >> id;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Index must be a valid number between 0 and 7." << std::endl;
        std::cout << "Contact index: " << std::flush;
        std::cin >> id;
    }
    return id;
}

void    commandLoop(PhoneBook &phonebook)
{
    std::string cmd;
    Contact contact;
    Contact *contactp;
    int size;
    while (true)
    {
        std::cin.clear();
        cmd = "";
        std::cout << "Command : " << std::flush;
        std::cin.ignore(256, '\n');
        std::cin >> cmd;
        if (cmd == "ADD")
        {
            if (!contact.promptFields())
                continue ;
            size = phonebook.addContact(contact);
            std::cout << "New contact added successfully" << std::endl;
            std::cout << "Size : " << size << std::endl; 
        }
        else if (cmd == "SEARCH")
        {
            contactp = phonebook.searchContact(promptIndex());
            if (!contactp)
                std::cout << "Contact not found." << std::endl;
            else
                contactp->print();
        }
        else if (cmd == "EXIT")
            break ;
        else
            std::cout << "Unknown command." << std::endl;
    }
}

int main(void)
{
    PhoneBook phonebook;
    std::cout << "\033c" << std::flush;
    std::cin >> std::noskipws;
    std::cout << "Welcome to Phonebook" << std::endl;
    printCommands();
    commandLoop(phonebook);
    return (0);
}