/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:36:31 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/28 14:28:08 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string	replace_strings(const std::string& long_line, const std::string& s1, const std::string& s2)
{
	std::string result;
    size_t pos = 0;     
    size_t found_pos;	// Position where s1 is found

    // find returns position of s1 in the string, or npos if not found
    found_pos = long_line.find(s1, pos);
    
    while (found_pos != std::string::npos) 
    {
		// Append the part of the string before s1 into result string
		result.append(long_line, pos, found_pos - pos);
		
		// Append s2 into result string
		result.append(s2);
		
		pos = found_pos + s1.length();
    	found_pos = long_line.find(s1, pos);
    }
	// Append the rest of the string after the last s1 occurrence
	result.append(long_line, pos);

	return result;
}
