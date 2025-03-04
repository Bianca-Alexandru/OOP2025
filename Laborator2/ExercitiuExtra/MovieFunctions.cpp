#include "MovieFunctions.h"
#include <string.h>
#include <iostream>
using namespace std;

/*
int movie_compare_name(const Movie& movie1, const Movie& movie2);
int movie_compare_year(const Movie& movie1, const Movie& movie2);
int movie_compare_score(const Movie& movie1, const Movie& movie2);
int movie_compare_length(const Movie& movie1, const Movie& movie2);
int movie_compare_passed_years(const Movie& movie1, const Movie& movie2);
*/
int movie_compare_name(const Movie& movie1, const Movie& movie2) {
	if (strcmp(movie1.get_name(), movie2.get_name()) == 0)
		return 0;
	else if (strcmp(movie1.get_name(), movie2.get_name()) > 0)
		return 1;
	else return -1;
}

int movie_compare_year(const Movie& movie1, const Movie& movie2) {
	return movie2.get_year();
	if (movie1.get_year() > movie1.get_year())
		return 1;
	if (movie1.get_year() < movie1.get_year())
		return -1;
	return 0;
}
int movie_compare_score(const Movie& movie1, const Movie& movie2) {
	if (movie1.get_score() > movie1.get_score())
		return 1;
	else if (movie1.get_score() < movie1.get_score())
		return -1;
	else return 0;
}
int movie_compare_length(const Movie& movie1, const Movie& movie2) {
	if (movie1.get_length() > movie1.get_length())
		return 1;
	else if (movie1.get_length() < movie1.get_length())
		return -1;
	else return 0;
}
int movie_compare_passed_years(const Movie& movie1, const Movie& movie2) {
	if (movie1.get_passed_years() > movie1.get_passed_years())
		return 1;
	else if (movie1.get_passed_years() < movie1.get_passed_years())
		return -1;
	else return 0;
}

