#ifndef MOVIE_H
#define MOVIE_H

using namespace std;

class Movie {
private:
    char* name;
    int year, length;
    double score;

public:

    const char* get_name() const;
    void set_name(const char* name);

    int get_year() const;
    void set_year(int year);

    double get_score() const;
    void set_score(double score);

    int get_length() const;
    void set_length(int length);

    int get_passed_years() const;
    
};

#endif

