/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wordle.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:13:11 by tpoho             #+#    #+#             */
/*   Updated: 2023/08/02 17:03:23 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDLE_HPP
# define WORDLE_HPP

# include <vector>
# include <string>

# define COLOR_RESET "\033[0m"
# define COLOR_GREEN "\033[32m"
# define COLOR_YELLOW "\033[33m"

class Wordle
{
	public:

		Wordle();
		~Wordle();

		int		readDictionary();
		void	printWordsAvailable() const;
		void	checkWord(std::string &word);
		void	printStatus() const;
		int		hasGameEnded() const;
		void	printEndText() const;

	private:

		Wordle(const Wordle &copy_constructor);
		const Wordle &operator=(const Wordle &copy_assignment);

		void	chooseWord();

		static int _how_many_words;
		static int _found_the_correct_word;
		std::vector<std::string> _tried_words;
		std::string _chosen_word;
		std::vector<std::string> _dictionary;
};

#endif
