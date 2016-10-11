/************************************************************
*Author:  Daniel Matthias Everhart
*Date:  04/18/2016
*Description:  This is the headerfile for checkers.  Checkers
*is a child of the game class.  The main powerhouse behind
*this game is an extensive is legal function
*************************************************************/

#ifndef CHECKERS_H
#define CHECKERS_H

#include<iostream>
#include<list>
#include<cstdlib>
#include<string>
#include"colors.h"
#include"cspace.h"
#include"game.h"

class checkers : public main_savitch_14::game {
	public:
		checkers();
		void make_move(const std::string& move);
		void restart();
		void display_status()const;
		bool is_game_over()const;
		bool is_legal(const std::string& move)const;
	private:
		cspace spaces[8][8];
		std::string toupper(std::string target)const;
		bool diagonal(int i1, int j1, int i2, int j2)const;
		bool is_legalsh(int i1, int j1, int i2, int j2)const;
		bool is_legalsc(int i1, int j1, int i2, int j2)const;
		bool is_legaldh(int i1, int j1, int i2, int j2)const;
		bool is_legaldc(int i1, int j1, int i2, int j2)const;
		bool enemypiece(int i1, int j1, int i2, int j2)const;
		int humanpieces()const;
		int computerpieces()const;
		bool jumpavailable()const;
		bool jumpavailable(int i, int j, bool king)const;
		bool jumpavailable(int i, int j, bool king, list<int> jumps)const;
		bool jumped(int i, int j, list<int> jumps)const;
};

#endif