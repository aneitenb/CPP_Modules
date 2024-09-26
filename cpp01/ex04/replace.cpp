/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:36:31 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/26 16:53:33 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string	replace_strings(std::string long_line, std::string s1, std::string s2)
{
	std::string result;
	size_t pos;
	size_t s1_len;
	
	pos = 0;
	s1_len = s1.length();
	while ((pos = long_line.find(s1, pos)) && pos != std::string::npos) 
	{
		result.append(long_line.substr(0, pos));// Append the part before s1
		result.append(s2);						// Replace s1 with s2
		pos += s1_len;							// Move past the found s1
	}
	result.append(long_line.substr(pos));  // Append the remaining part of the line
	return (result);
}
