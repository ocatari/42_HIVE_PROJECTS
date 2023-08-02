/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:12:07 by tpoho             #+#    #+#             */
/*   Updated: 2023/08/02 16:58:20 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wordle.hpp"
#include <iostream>

int	main(void)
{
	Wordle wordle;
	std::string input_line;

	if (!wordle.readDictionary())
	{
		std::cout << "Could not read words from words.txt" << std::endl;
		return (1);
	}

	wordle.printWordsAvailable();

	while (!wordle.hasGameEnded())
	{
		std::cout << "Give input word: ";
		std::getline (std::cin, input_line);
		wordle.checkWord(input_line);
		wordle.printStatus();
		std::cout << std:: endl;
	}

	wordle.printEndText();
	return (0);
}
