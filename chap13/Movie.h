/******************************************************************
 * Section 13 Challenge
 * Movie.h
 * 
 * Models a Movie with the following atttributes
 * 
 * std::string name - the name of the movie 
 * std::string rating - G, PG, PG-13, R
 * int watched - the number of times you've watched the movie
 * ***************************************************************/
#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
private:
    std::string name;   // the name of the movie
    std::string rating;   // the movie rating G,PG, PG-13, R
    int watched;          // the number of times you've watched the movie
public:
    // Constructor - expects all 3 movie attributes
	Movie(std::string name_, std::string rating_, int watched_):name(name_), rating(rating_), watched(watched_){};	
    // Copy constructor 
    Movie(const Movie &source);
    // Destructor
    ~Movie();
    // Basic getters and setters for private attributes
    // implement these inline and watch your const-correctness
	std::string get_name() const{
		return name;
	}
    
	void set_name(std::string rat){
		rating = rat;
	}
    
	void set_watched(int watched){this->watched = watched;}
	int get_watched() const {return watched;}
    // Simply increment the watched attribute by 1
    void increment_watched(){++watched;}
    // simply displays the movie information ex.) Big, PG-13, 2
	void display() const;
};

#endif // _MOVIE_H_
