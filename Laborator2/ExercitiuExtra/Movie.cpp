#include "Movie.h"
#include <cstring>

const char* Movie::get_name() const{
	return this->name;
}
void Movie::set_name(const char* name){
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

int Movie::get_year() const{
	return this->year;
}
void Movie::set_year(int year){
	this->year = year;
}

double Movie::get_score() const{
	return this->score;
}
void Movie::set_score(double score){
	this->score = score;
}

int Movie::get_length() const{
	return this->length;
}
void Movie::set_length(int length){
	this->length = length;
}

int Movie::get_passed_years() const{
	return 2025 - this->year;
}