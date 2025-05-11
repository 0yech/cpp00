/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:39:54 by nrey              #+#    #+#             */
/*   Updated: 2025/05/11 20:02:23 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

bool Contact::set_contact()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);

    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);

    if (first_name.empty() || last_name.empty() || nickname.empty() ||
        phone_number.empty() || darkest_secret.empty())
    {
        std::cout << "Error: All fields must be filled." << std::endl;
		return false;
    }
	for (int i = 0; i < (int)phone_number.length(); i++)
	{
		if (!isdigit(phone_number[i]))
		{
			std::cout << "Error: Phone number must be numerical" << std::endl;
			return false;
		}
	}
	return true;
}

std::string format_string(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::display_short(int index) const
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << format_string(first_name) << "|";
    std::cout << std::setw(10) << format_string(last_name) << "|";
    std::cout << std::setw(10) << format_string(nickname) << std::endl;
}

void Contact::display_full() const
{
    std::cout << "First name: " << first_name << std::endl;
    std::cout << "Last name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl; 
}
