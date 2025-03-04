#include <iostream>
#include "Movie.h"
#include "MovieFunctions.h"
using namespace std;


int main() {
    Movie ep5;
    ep5.set_name("Star Wars: Episode V - The Empire Strikes Back");
    ep5.set_score(8.7);
    ep5.set_year(1980);
    ep5.set_length(124);
    cout << ep5.get_name() << endl;
    cout << ep5.get_score() << endl;
    cout << ep5.get_year() << endl;
    cout << ep5.get_length() << endl;
    cout << ep5.get_passed_years() << endl;
    
    Movie ep4;
    ep4.set_name("Star Wars: Episode IV - A New Hope");
    ep4.set_score(8.6);
    ep4.set_year(1977);
    ep4.set_length(121);

    cout << endl;
    cout << ep4.get_name() << endl;
    cout << ep4.get_score() << endl;
    cout << ep4.get_year() << endl;
    cout << ep4.get_length() << endl;
    cout << ep4.get_passed_years() << endl;

    Movie ep6;
    ep6.set_name("Star Wars: Episode VI - Return of the Jedi");
    ep6.set_score(8.3);
    ep6.set_year(1983);
    ep6.set_length(131);

    cout << movie_compare_name(ep4, ep5);
    
    printf(
        R"(
ep4, ep5 comparisons:
name        : %d
year        : %d
score       : %d
length      : %d
passed years: %d
)",
movie_compare_name(ep4, ep5),
movie_compare_year(ep4, ep5),
movie_compare_score(ep4, ep5),
movie_compare_length(ep4, ep5),
movie_compare_passed_years(ep4, ep5));
    /*

    MovieSeries series;
    series.init();
    series.add(&ep5);
    series.add(&ep4);
    series.add(&ep6);

    series.sort();
    series.print();*/
}
