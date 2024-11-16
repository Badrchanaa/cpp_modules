
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <limits>

void    printCommands(void)
{
    std::cout << "Available commands :" << std::endl;
    std::cout << "\tADD - Add a new contact" << std::endl;
    std::cout << "\tSEARCH - Search for a contact in the Phonebook" << std::endl;
    std::cout << "\tEXIT - Exit the Phonebook" << std::endl;
}

bool    promptIndex(int &id)
{
    std::cin >> std::noskipws;
    std::cout << "Index> " << std::flush;
    std::cin >> id;
    while (std::cin.fail() && !std::cin.eof())
    {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "Please enter a valid integer." << std::endl;
        std::cout << "Index> " << std::flush;
        std::cin >> id;
    }
    std::cin.ignore(1024, '\n');
    return std::cin.good();
}


void    handleSearch(PhoneBook &phonebook)
{
    Contact *contactp;
    int id;

    if (phonebook.getSize() == 0)
    {
        std::cout << "No contacts registered" << std::endl;
        return ;
    }
    phonebook.printContacts();
    contactp = NULL;
    while (!contactp)
    {
        if (!promptIndex(id))
            break ;
        contactp = phonebook.searchContact(id);
        if (!contactp)
        {
            std::cout << "Contact not found." << std::endl;
            continue;
        }
        else
            contactp->print();
    }
}

void    commandLoop(PhoneBook &phonebook)
{
    std::string cmd;
    Contact contact;
    int size;
    while (!std::cin.eof())
    {
        cmd = "";
        std::cout << "Command> " << std::flush;
        std::getline(std::cin, cmd);
        if (cmd.empty())
            continue ;
        if (cmd == "ADD")
        {
            if (!contact.promptFields())
                break ;
            size = phonebook.addContact(contact);
            std::cout << "New contact added successfully" << std::endl;
            std::cout << "Total contacts : " << size << std::endl; 
        }
        else if (cmd == "SEARCH")
            handleSearch(phonebook);
        else if (cmd == "EXIT")
            return ;
        else
            std::cout << "Unknown command" << std::endl;
    }
    std::cout << std::endl;
}


int main(void)
{
    PhoneBook phonebook;
    std::cout << "\033c" << std::flush;
    std::cout << "Welcome to Phonebook" << std::endl;
    printCommands();
    commandLoop(phonebook);
    return (0);
}