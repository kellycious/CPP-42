/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:22:49 by khuynh            #+#    #+#             */
/*   Updated: 2023/10/22 19:22:50 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){};
Serializer::Serializer(Serializer const &cpy){*this = cpy;};
Serializer::~Serializer(){};

Serializer &Serializer::operator= (Serializer const &op)
{
	(void)op;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t retour;
	retour = reinterpret_cast<uintptr_t>(ptr);
	return retour;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}