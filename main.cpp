//
//  main.cpp
//  SerpientesEscaleras
//
//  Created by Rosa Guadalupe Paredes Juarez on 18/05/20.
//  Copyright © 2020 Rosa Paredes. All rights reserved.
//

#include <iostream>
#include "MyGame.h"
#include <exception>
#include "InvalidConfigurationException.h"
using namespace std;

int main(int argc, const char * argv[]) {
	char par = 'n';
    cout << "¿Quiere configurar el juego? (Si = s / No = n)" <<endl;
	cin >> par;
	if(par == 's'){
		try {
			int tiles;
			int snakes;
			int ladders;
			int penalty;
			int reward;
			int players;
			int turns;
			char gType;
			cout << "Numero de casillas: ";
			cin >> tiles;
			if (tiles < 2) 
				throw InvalidConfigurationException("tiles", tiles);
	
			cout << endl << "Numero de Serpientes: ";
			cin >> snakes;
			if (snakes < 0 || snakes > (tiles/2))
				throw InvalidConfigurationException("snakes", snakes);
			
			cout << endl << "Numero de escaleras: ";
			cin >> ladders;
			if (ladders < 0 || ladders > (tiles/2))
				throw InvalidConfigurationException("ladders", ladders);
			
			cout << endl << "Penalizacion: ";
			cin >> penalty;
			if (penalty < 0 || penalty > tiles)
				throw InvalidConfigurationException("penalty", penalty);
			
			cout << endl << "Recompenza: ";
			cin >> reward;
			if (reward < 0 || reward > tiles)
				throw InvalidConfigurationException("reward", reward);
			
			cout << endl << "Numero de jugadores: ";
			cin >> players;
			if (players < 0 || players > tiles)
				throw InvalidConfigurationException("players", players);
			
			cout << endl << "Numero de turnos: ";
			cin >> turns;
			if (turns < 0)
				throw InvalidConfigurationException("turns", turns);
			
			cout << endl << "Tipo de juego: (Automatico = A / Manual = M) ";
			cin >> gType;
			MyGame game = MyGame(tiles, snakes, ladders, penalty, reward, turns, players, gType);
		
			
			game.start();
		}
		catch (exception &e){
			e.what();
		}
	}
	else if(par == 'n') {
		MyGame game;
		game.start();
	}
	else {
		cout << "Opcion invalida" << endl;
	}
	

    return 1;
}
