//Space class header
//Emily Caggiano. CS2401, Project 6(game)

#ifndef SPACE_H
#define SPACE_H

#include<cstdlib>
#include<iostream>
#include<string>

namespace main_savitch_14{ 

class Space{
   public:
	Space();
	bool is_black()const;
	bool is_white()const;
	void flip();
	bool is_empty()const;
	void make_white(); 
	void make_black();
   private:
	bool black, white, empty;
   };
}
#endif


