/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:19:47 by nrey              #+#    #+#             */
/*   Updated: 2025/05/09 22:49:30 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
    private :
        Contact list[8];
        int count;
        int oldest;

	public:
		PhoneBook();
		void	add_contact();
		void	search_contacts() const;
};

#endif