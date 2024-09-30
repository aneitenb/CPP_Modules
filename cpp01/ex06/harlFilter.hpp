/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:32:53 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/30 14:39:23 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP

# define HARLFILTER_HPP
# include <string>

class harlFilter
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		harlFilter();
		~harlFilter();

		void complain(std::string level);
};

#endif
