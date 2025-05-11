/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:04:35 by nrey              #+#    #+#             */
/*   Updated: 2025/05/09 23:01:28 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Phonebook.hpp"

int main(void)
{
    PhoneBook   phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << "\nExiting." << std::endl;
            break;
        }
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contacts();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Unknown command. Try again." << std::endl;
    }
    return (0);
}