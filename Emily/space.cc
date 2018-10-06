//function implementation for the Space class
//Emily Caggiano. CS2401, Project 6(game)

#include<iostream>
#include "space.h"

namespace main_savitch_14{

Space::Space(){
	black = false;
	white = false;
	empty = true;
}

bool Space::is_black()const{
	return black;
}

bool Space::is_white()const{
	return white;
}

void Space::flip(){
	if(white){
		white = false;
		black = true;
	}
	else{
		white = true;
		black = false;
	}
}

bool Space::is_empty()const{
	return empty;
}

void Space::make_white(){
	white = true;
	empty = black = false;
}

void Space::make_black(){
	black = true;
	empty = white = false;
}

}
