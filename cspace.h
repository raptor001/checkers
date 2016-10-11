/*********************************************************
*Author: Daniel Matthias Everhart
*Date: 04/12/2016
*Description: This is the header file describing the
*status of an individual square on a checker board
**********************************************************/

#ifndef CSPACE_H
#define CSPACE_H

#include"colors.h"
#include<iostream>

class cspace {
	public:
		cspace();
		void set_occupied(bool c);
		void set_color(std::string c);
		void set_king(bool c);
		void set_piece(std::string c);
		void set_jumped(bool c);
		bool occupied()const;
		std::string color()const;
		bool king()const;
		std::ostream& output(std::ostream& inp) const;
	private:
		bool full;
		std::string piece;
		bool crown;
};

std::ostream& operator <<(std::ostream& oup, const cspace &h);

#endif