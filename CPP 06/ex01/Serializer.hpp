/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:23:00 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/22 19:35:28 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer (Serializer const &cpy);
		~Serializer();

		Serializer &operator= (Serializer const &op);
		uintptr_t serialize(Data *ptr);
		Data* deserialize(uintptr_t raw);
};

#endif