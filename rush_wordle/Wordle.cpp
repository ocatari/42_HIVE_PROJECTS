/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:13:16 by tpoho             #+#    #+#             */
/*   Updated: 2023/08/02 17:03:27 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wordle.hpp"
#include <fstream>
#include <iostream>
#include <ctime>
#include <vector>

int Wordle::_how_many_words = 0;
int Wordle::_found_the_correct_word = 0;

Wordle::Wordle()
{
	// Empty on purpose
}

Wordle::~Wordle()
{
	_dictionary.clear();
}

int	Wordle::readDictionary()
{
	std::string input_line;

	std::ifstream input_file("words.txt");
	if (!input_file.good())
	{
		return (0);
	}

	while (std::getline(input_file, input_line))
	{
		if (input_line.size() == 5)
		{
			_dictionary.push_back(input_line);
		}
	}

	_how_many_words = _dictionary.size();
	if(_how_many_words)
	{
		chooseWord();
		return (1);
	}

	return (0);
}

void	Wordle::printWordsAvailable() const
{
	std::cout << "Total words available: " << _how_many_words << std::endl;
}

void	Wordle::checkWord(std::string &word)
{
	if (word.size() != 5)
	{
		std::cout << "Word length must be 5" << std::endl;
		return ;
	}

	if (_tried_words.size() >= 6)
	{
		return ;
	}

	for (std::string::size_type i = 0; i < 5; ++i)
	{
		word[i] = std::tolower(word[i]);
	}

	_tried_words.push_back(word);
	if (word == _chosen_word)
		_found_the_correct_word = 1;
}

void	Wordle::printStatus() const
{
	std::vector<std::string>::size_type i = 0;

	for(; i < _tried_words.size(); ++i)
	{
		for (int c = 0; c < 5; ++c)
		{
			if (_chosen_word[c] == _tried_words[i][c])
			{
				std::cout << COLOR_GREEN << _tried_words[i][c] << " " << COLOR_RESET;
			}
			else if (_chosen_word.find(_tried_words[i][c]) != std::string::npos)
			{
				std::cout << COLOR_YELLOW << _tried_words[i][c] << " " << COLOR_RESET;
			}
			else if (_chosen_word.find(_tried_words[i][c]) == std::string::npos)
			{
				std::cout << COLOR_RESET << _tried_words[i][c] << " ";
			}
		}
		std::cout << std::endl;
	}

	for(; i < 6; ++i)
	{
		std::cout << "_ _ _ _ _" << std::endl; 
	}
}

int	Wordle::hasGameEnded() const
{
	if (_found_the_correct_word)
		return (1);
	
	if (_tried_words.size() >= 6)
		return (1);

	return (0);
}

void	Wordle::printEndText() const
{
	if (_found_the_correct_word)
	{
		std:: cout << "Congratulations you found the word ";
		for (int i = 0; i < 5; ++i)
		{
			std::cout << static_cast<char>(std::toupper(_chosen_word[i]));
		}
		std::cout << " in " << _tried_words.size() << " guesses" << std::endl;	
	} else
	{
		std:: cout << "You lost the game with word ";
		for (int i = 0; i < 5; ++i)
		{
			std::cout << static_cast<char>(std::toupper(_chosen_word[i]));
		}
		std::cout << " in " << _tried_words.size() << " guesses" << std::endl;
	}
}

void	Wordle::chooseWord()
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % _how_many_words;
	_chosen_word = _dictionary[random_variable];
}
