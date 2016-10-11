/*********************************************************
*Author: Daniel Matthias Everhart
*Date: 04/12/2016
*Description: This is the implementation for a checker
*space.
**********************************************************/

#include<iostream>
#include<cstdlib>
#include"cspace.h"
#include"colors.h"

using namespace std;

cspace::cspace() {
	full = false;
	crown = false;
	piece = BLACK;
}

void cspace::set_occupied(bool c) {
	full = c;
}

string cspace::color()const {
	return piece;
}

void cspace::set_king(bool c) {
	crown = c;
}

void cspace::set_piece(string c) {
	piece = c;
}

bool cspace::occupied()const {
	return full;
}

bool cspace::king()const {
	return crown;
}

ostream& cspace::output(ostream& oup) const {
	oup << piece;
	if(full == false) {
		oup << " ";
	} else {
		char b = '@';
		if(crown) b = 'k';
		oup << b;
	}
	oup << WHITE;
	return oup;
}

ostream& operator<<(ostream& oup, const cspace &h) {
	h.output(oup);
	return oup;
}