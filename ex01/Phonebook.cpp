/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 05:04:12 by nrey              #+#    #+#             */
/*   Updated: 2025/05/09 22:57:31 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : count(0), oldest(0) {}

void PhoneBook::add_contact()
{
    std::cout << "Adding a new contact..." << std::endl;
    if (!list[oldest].set_contact())
        return ;
    std::cout << "Added new contact: " << std::endl;
    oldest = (oldest + 1) % 8;
    if (count < 8)
        ++count;
}

void PhoneBook::search_contacts() const
{
    std::string input;
    int index;

    if (count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < count; ++i)
        list[i].display_short(i);
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, input);
    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    index = input[0] - '0';
    if (index < 0 || index >= count)
    {
        std::cout << "Index out of range." << std::endl;
        return;
    }
    list[index].display_full();
}
