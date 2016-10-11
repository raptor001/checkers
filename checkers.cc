/************************************************************
*Author: Daniel Matthias Everhart
*Date:  04/18/2016
*Description:  This is the implementation file for chechers.h
*************************************************************/

#include<iostream>
#include<queue>
#include<list>
#include<cstdlib>
#include<string>
#include<cmath>
#include"colors.h"
#include"cspace.h"
#include"game.h"
#include"checkers.h"

using namespace std;

checkers::checkers() {
	restart();
	cout << "Welcome to Checkers\n\n";
	cout << "To move from B6 to A5 type in b6a5\n";
	cout << "or B6a5\n\n";
	cout << "To jump multiple jumps type each jump\n";
	cout << "separately ie: b6d4 d4b2\n\n";
	cout << "Be sure that there is a space in between\n\n\n";
}

void checkers::make_move(const std::string& move) {
	queue<string> moves;
	string move1 = toupper(move);
	int i1, j1, i2, j2;
	for(int i = 0; i < move1.size(); ++i) {
		if(move1[i] >= 'A' && move1[i] <= 'Z') {
			string a, b, c, d, ins;
			a = move1[i];
			b = move1[i + 1];
			c = move1[i + 2];
			d = move1[i + 3];
			ins = a + b + c + d;
			moves.push(ins);
			i += 4;
		}
	}
	while(!moves.empty()) {
		move1 = moves.front();
		j1 = move1[0] - 'A';
		i1 = move1[1] - '1';
		j2 = move1[2] - 'A';
		i2 = move1[3] - '1';
		spaces[i2][j2] = spaces[i1][j1];
		spaces[i1][j1].set_occupied(false);
		spaces[i1][j1].set_king(false);
		spaces[i1][j1].set_piece(BLACK);
		if(abs(i1 - i2) == 2) {
			spaces[(i2 + i1) / 2][(j1 + j2) / 2].set_occupied(false);
			spaces[(i2 + i1) / 2][(j1 + j2) / 2].set_king(false);
			spaces[(i2 + i1) / 2][(j1 + j2) / 2].set_piece(BLACK);
		}
		if(i2 == 0 || i2 == 7) {
			spaces[i2][j2].set_king(true);
		}
		moves.pop();
	}
		game::make_move(move);
}

void checkers::restart() {
	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(i < 3) {
				if(i % 2 == 1) {
					if(j % 2 == 1) {
						spaces[i][j].set_occupied(true);
						spaces[i][j].set_piece(CYAN);
					}
				} else {
					if(j % 2 == 0) {
						spaces[i][j].set_occupied(true);
						spaces[i][j].set_piece(CYAN);
					}
				}
			} else if(i > 4) {
				if(i % 2 == 1) {
					if(j % 2 == 1) {
						spaces[i][j].set_occupied(true);
						spaces[i][j].set_piece(GREEN);
					}
				} else {
					if(j % 2 == 0) {
						spaces[i][j].set_occupied(true);
						spaces[i][j].set_piece(GREEN);
					}
				}
			}
		}
	}
	game::restart();
}

void checkers::display_status()const {
	cout << "Player one pieces: " << humanpieces() << endl;
	cout << "Player two pieces: " << computerpieces() << endl;
	cout << "   ";
	for(int i = 0; i < 8; ++i) {
		char let = i + 'A';
		cout << "   " << let << "   ";
	}
	cout << endl;
	cout << "   ";
	for(int i = 0; i < 8; ++i) cout << "_______";
	cout << endl;
	for(int i = 0; i < 8; ++i) {
		if(i % 2 == 0) {
			for(int z = 0; z < 8; z += 2) {
				if(z == 0) {
					cout << B_BLACK << "  |       ";
				} else {
					cout << B_BLACK << "       ";
				}
				if(z == 6) {
					cout << B_RED << "       " << B_BLACK << '|';
				} else {
					cout << B_RED << "       ";
				}
			}
			cout << B_BLACK << endl;
			for(int z = 0; z < 8; z += 2) {
				if(z == 0) {
					cout << B_BLACK << i + 1 << " |   " << spaces[i][z] << "   ";
				} else {
					cout << B_BLACK << "   " << spaces[i][z] << "   ";
				}
				if(z == 6) {
					cout << B_RED << "   " << spaces[i][z+1] << "   " << B_BLACK << '|';
				} else {
					cout << B_RED << "   " << spaces[i][z+1] << "   ";
				}
			}
			cout << B_BLACK << endl;
			for(int z = 0; z < 8; z += 2) {
				if(z == 0) {
					cout << B_BLACK << "  |       ";
				} else {
					cout << B_BLACK << "       ";
				}
				if(z == 6) {
					cout << B_RED << "       " << B_BLACK << '|';
				} else {
					cout << B_RED << "       ";
				}
			}
			cout << B_BLACK << endl;
		} else {
			for(int z = 0; z < 8; z += 2) {
				if(z == 0) {
					cout << B_BLACK << "  |";
					cout << B_RED << "       ";
				} else {
					cout << B_RED << "       ";
				}
				if(z == 6) {
					cout << B_BLACK << "       |";
				} else {
					cout << B_BLACK << "       ";
				}
			}
			cout << B_BLACK << endl;
			for(int z = 0; z < 8; z += 2) {
				if(z == 0) {
					cout << B_BLACK << i + 1 << " |" << B_RED << "   " << spaces[i][z] << "   ";
				} else {
					cout << B_RED << "   " << spaces[i][z] << "   ";
				}
				if(z == 6) {
					cout << B_BLACK << "   " << spaces[i][z+1] << "   |";
				} else {
					cout << B_BLACK << "   " << spaces[i][z+1] << "   ";
				}
			}
			cout << B_BLACK << endl;
			if(i < 7) {
				for(int z = 0; z < 8; z += 2) {
					if(z == 0) {
						cout << B_BLACK << "  |" << B_RED << "       ";
					} else {
						cout << B_RED << "       ";
					}
					if(z == 6) {
						cout << B_BLACK << "       |";
					}
					cout << B_BLACK << "       ";
				}
			} else {
				for(int z = 0; z < 8; z += 2) {
					if(z == 0) {
						cout << B_BLACK << "  |" << B_RED << "_______";
					} else {
						cout << B_RED << "_______";
					}
					if(z == 6) {
						cout << B_BLACK << "_______|";
					}
					if(z != 6) {
						cout << B_BLACK << "_______";
					}
				}
			}
			cout << B_BLACK << endl;
		}
	}
}

bool checkers::is_game_over()const {
	return (humanpieces() == 0 || computerpieces() == 0);
}

bool checkers::is_legal(const std::string& move)const {
	list<int> jumped;
	string path = toupper(move);
	queue<string> moves;
	for(int i = 0; i < path.size(); ++i) {
		if(path[i] >= 'A' && path[i] <= 'Z') {
			string a, b, c, d, ins;
			a = path[i];
			b = path[i + 1];
			c = path[i + 2];
			d = path[i + 3];
			ins = a + b + c + d;
			moves.push(ins);
			i += 4;
		}
	}
	if(moves.size() > 1) {
		path = moves.front();
		int i1, i2, j1, j2, pi, pj;
		j1 = path[0] - 'A';
		i1 = path[1] - '1';
		j2 = path[2] - 'A';
		i2 = path[3] - '1';
		if(!(i2 < 8 && i2 >= 0 && i1 < 8 && i1 >= 0 && j2 < 8 && j2 >=0 && j1 < 8 && j2 >= 0)) {
			display_message("Coordinates not on board\n");
			return false;
		}
		if(!diagonal(i1, j1, i2, j2)) return false;
		if(next_mover() == HUMAN) {
			if(!spaces[i1][j1].occupied() || spaces[i1][j1].color() != GREEN) {
				display_message("You do not own the starting spot\n");
				return false;
			}
			if(spaces[i2][j2].occupied()) {
				display_message("You cannot land on an occupied square\n");
				return false;
			}
			if(!enemypiece(i1, j1, i2, j2)) {
				display_message("You cannot jump your own piece or a blank spot\n");
				return false;
			}
			if(!(i2 < i1) && !spaces[i1][j1].king()) {
				display_message("You cannot move in that direction\n");
				return false;
			}
		} else {
			if(!spaces[i1][j1].occupied() || spaces[i1][j1].color() != CYAN) {
				display_message("You do not own the starting spot\n");
				return false;
			}
			if(spaces[i2][j2].occupied()) {
				display_message("You cannot land on an occupied square\n");
				return false;
			}
			if(!enemypiece(i1, j1, i2, j2)) {
				display_message("You cannot jump your own piece or a blank spot\n");
				return false;
			}
			if(!(i2 > i1) && !spaces[i1][j1].king()) {
				display_message("You cannot move in that direction\n");
				return false;
			}
		}
		jumped.push_back(((i1 + i2) / 2) * 10 + (j1 + j2) / 2);
		moves.pop();
		int i0 = i1;
		int j0 = j1;
		while(!moves.empty()) {
			pi = i2;
			pj = j2;
			path = moves.front();
			j1 = path[0] - 'A';
			i1 = path[1] - '1';
			j2 = path[2] - 'A';
			i2 = path[3] - '1';
			if((pi != i1 && pj != j1) || !(i2 < 8 && i2 >= 0 && i1 < 8 && i1 >= 0 && j2 < 8 && j2 >=0 && j1 < 8 && j2 >= 0)) {
				display_message("Invalid path\n");
				return false;
			}
			if(!diagonal(i1, j1, i2, j2)) return false;
			if(spaces[i2][j2].occupied()) {
				display_message("You cannot land on an occupied square\n");
				return false;
			}
			if(!enemypiece(i1, j1, i2, j2)) {
				display_message("You cannot jump your own piece or a blank spot\n");
				return false;
			}
			if(next_mover() == HUMAN) {
				if(!(i2 < i1) && !spaces[i0][j0].king()) {
					display_message("You cannot move in that direction\n");
					return false;
				}
			} else if(!(i2 > i1) && !spaces[i0][j0].king()) {
				display_message("You cannot move in that direction\n");
				return false;
			}
			jumped.push_back(((i1 + i2) / 2) * 10 + (j1 + j2) / 2);
			moves.pop();
		}
		if(!jumpavailable(i2, j2, spaces[i0][j0].king(), jumped)) return true;
		display_message("You must complete all available jumps in this path\n");
		return false;
	} else {
		path = moves.front();
		int i1, i2, j1, j2;
		j1 = path[0] - 'A';
		i1 = path[1] - '1';
		j2 = path[2] - 'A';
		i2 = path[3] - '1';
		if(!(i2 < 8 && i2 >= 0 && i1 < 8 && i1 >= 0 && j2 < 8 && j2 >=0 && j1 < 8 && j2 >= 0)) {
			display_message("Coordinates not on the board\n");
			return false;
		}
		if(!diagonal(i1, j1, i2, j2)) return false;
		if(next_mover() == HUMAN) {
			if(abs(i1 - i2) == 1) {
				if(jumpavailable()) {
					display_message("You have a jump available and must take it\n");
					return false;
				}
				return is_legalsh(i1, j1, i2, j2);
			} else if(abs(i1 - i2) == 2) {
				return is_legaldh(i1, j1, i2, j2);
			} else {
				display_message("You cannot move more than two spaces\n");
				return false;
			}
		} else {
			if(abs(i1 - i2) == 1) {
				if(jumpavailable()) {
					display_message("You have a jump available and must take it\n");
					return false;
				}
				return is_legalsc(i1, j1, i2, j2);
			} else if(abs(i1 - i2) == 2) {
				return is_legaldc(i1, j1, i2, j2);
			} else {
				display_message("You cannot move more than two spaces\n");
				return false;
			}
		}
		return false;
	}
}

string checkers::toupper(string target)const {
	string word = target;
	for(int i = 0; i < word.size(); ++i) {
		if(word[i] >= 'a' && word[i] <= 'z') {
			word[i] = word[i] - 'a' + 'A';
		}
	}
	return word;
}

bool checkers::diagonal(int i1, int j1, int i2, int j2)const {
	if(abs(j1 - j2) == abs(i2 - i1)) return true;
	display_message("Path not diagonal\n");
	return false;
}

bool checkers::is_legalsh(int i1, int j1, int i2, int j2)const {
	if(!spaces[i1][j1].occupied() || spaces[i1][j1].color() != GREEN) {
		display_message("You do not own the start point\n");
		return false;
	}
	if(spaces[i2][j2].occupied()) {
		display_message("You cannot land on an occupied square\n");
		return false;
	}
	if(spaces[i1][j1].king()) return true;
	if(!(i2 < i1)) display_message("You cannot move in that direction\n");
	return i2 < i1;
}

bool checkers::is_legalsc(int i1, int j1, int i2, int j2)const {
	if(!spaces[i1][j1].occupied() || spaces[i1][j1].color() != CYAN) {
		display_message("You do not own the start point\n");
		return false;
	}
	if(spaces[i2][j2].occupied()) {
		display_message("You cannot land on an occupied square\n");
		return false;
	}
	if(spaces[i1][j1].king()) return true;
	if(!(i2 > i1)) display_message("You cannot move in that direction\n");
	return i2 > i1;
}

bool checkers::is_legaldh(int i1, int j1, int i2, int j2)const {
	list<int> jumps;
	if(!spaces[i1][j1].occupied() || spaces[i1][j1].color() != GREEN) {
		display_message("You do not own the start point\n");
		return false;
	}
	if(spaces[i2][j2].occupied()) {
		display_message("You cannot land on an occupied square\n");
		return false;
	}
	if(!enemypiece(i1, j1, i2, j2)) {
		display_message("You cannot jump your own piece or a blank spot\n");
		return false;
	}
	jumps.push_back(((i1 + i2) / 2) * 10 + (j1 + j2) / 2);
	if(jumpavailable(i2, j2, spaces[i1][j1].king(), jumps)) {
		display_message("You must complete all jumps on this path\n");
		return false;
	}
	if(spaces[i1][j1].king()) return true;
	if(!(i2 < i1)) display_message("You cannot move in that direction\n");
	return i2 < i1;
}

bool checkers::is_legaldc(int i1, int j1, int i2, int j2)const {
	list<int> jumps;
	if(!spaces[i1][j1].occupied() || spaces[i1][j1].color() != CYAN) {
		display_message("You do not own the start point\n");
		return false;
	}
	if(spaces[i2][j2].occupied()) {
		display_message("You cannot land on an occupied square\n");
		return false;
	}
	if(!enemypiece(i1, j1, i2, j2)) {
		display_message("You cannot jump your own piece or a blank spot\n");
		return false;
	}
	jumps.push_back(((i1 + i2) / 2) * 10 + (j1 + j2) / 2); 
	if(jumpavailable(i2, j2, spaces[i1][j1].king(), jumps)) {
		display_message("You must complete all jumps on this path\n");
		return false;
	}
	if(spaces[i1][j1].king()) return true;
	if(!(i2 > i1)) display_message("You cannot move in that direction\n");
	return i2 > i1;
}

bool checkers::enemypiece(int i1, int j1, int i2, int j2)const {
	if(next_mover() == HUMAN) {
		if(spaces[(i2 + i1) / 2][(j1 + j2) / 2].color() == CYAN) return true;
	} else {
		if(spaces[(i2 + i1) / 2][(j1 + j2) / 2].color() == GREEN) return true;
	}
	return false;
}

int checkers::humanpieces()const {
	int count = 0;
	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(spaces[i][j].color() == GREEN) {
				++count;
			}
		}
	}
	return count;
}

int checkers::computerpieces()const {
	int count = 0;
	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(spaces[i][j].color() == CYAN) {
				++count;
			}
		}
	}
	return count;
}

bool checkers::jumpavailable()const {
	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(next_mover() == HUMAN) {
				if(spaces[i][j].color() == GREEN && jumpavailable(i, j, spaces[i][j].king())) return true;
			} else {
				if(spaces[i][j].color() == CYAN && jumpavailable(i, j, spaces[i][j].king())) return true;
			}
		}
	}
	return false;
}

bool checkers::jumpavailable(int i, int j, bool king)const {
	if(next_mover() == HUMAN) {
		if(i > 1 && j < 6 && enemypiece(i, j, i - 2, j + 2) && !spaces[i - 2][j + 2].occupied()) return true;
		if(i > 1 && j > 1 && enemypiece(i, j, i - 2, j - 2) && !spaces[i - 2][j - 2].occupied()) return true;
		if(king) {
			if(i < 6 && j < 6 && enemypiece(i, j, i + 2, j + 2) && !spaces[i + 2][j + 2].occupied()) return true;
			if(j < 6 && i > 1 && enemypiece(i, j, i + 2, j - 2) && !spaces[i + 2][j - 2].occupied()) return true;
		}
	} else {
		if(j < 6 && i < 6 && enemypiece(i, j, i + 2, j + 2) && !spaces[i + 2][j + 2].occupied()) return true;
		if(j > 1 && i < 6 && enemypiece(i, j, i + 2, j - 2) && !spaces[i + 2][j - 2].occupied()) return true;
		if(king) {
			if(j < 6 && i > 1 && enemypiece(i, j, i - 2, j + 2) && !spaces[i + 2][j - 2].occupied()) return true;
			if(j > 1 && i > 1 && enemypiece(i, j, i - 2, j - 2) && !spaces[i - 2][j - 2].occupied()) return true;
		}
	}
	return false;
}

bool checkers::jumpavailable(int i, int j, bool king, list<int> jumps)const {
	if(next_mover() == HUMAN) {
		if(i > 1 && j < 6 && enemypiece(i, j, i - 2, j + 2) && !spaces[i - 2][j + 2].occupied()){ 
			if(!jumped(i - 1, j + 1, jumps)) return true;
		}
		if(i > 1 && j > 1 && enemypiece(i, j, i - 2, j - 2) && !spaces[i - 2][j - 2].occupied()) {
			if(!jumped(i - 1, j - 1, jumps)) return true;
		}
		if(king) {
			if(i < 6 && j < 6 && enemypiece(i, j, i + 2, j + 2) && !spaces[i + 2][j + 2].occupied()) {
				if(!jumped(i + 1, j + 1, jumps)) return true;
			}
			if(i < 6 && j > 1 && enemypiece(i, j, i + 2, j - 2) && !spaces[i + 2][j - 2].occupied()) {
				if(!jumped(i + 1, j - 1, jumps)) return true;
			}
		}
	} else {
		if(j < 6 && i < 6 && enemypiece(i, j, i + 2, j + 2) && !spaces[i + 2][j + 2].occupied()) {
			if(!jumped(i + 1, j + 1, jumps)) return true;
		}
		if(j > 1 && i < 6 && enemypiece(i, j, i + 2, j - 2) && !spaces[i + 2][j - 2].occupied()) {
			if(!jumped(i + 1, j - 1, jumps)) return true;
		}
		if(king) {
			if(j < 6 && i > 1 && enemypiece(i, j, i - 2, j + 2) && !spaces[i + 2][j - 2].occupied()){
				if(!jumped(i - 1, j + 1, jumps)) return true;
			}
			if(j > 1 && i > 1 && enemypiece(i, j, i - 2, j - 2) && !spaces[i - 2][j - 2].occupied()) {
				if(!jumped(i - 1, j - 1, jumps)) return true;
			}
		}
	}
	return false;
}

bool checkers::jumped(int i, int j, list<int> jumped)const {
	while(!jumped.empty()) {
		if(i == jumped.front() / 10 && j == jumped.front() % 10) {
			return true;
		}
		jumped.pop_front();
	}
	return false;
}