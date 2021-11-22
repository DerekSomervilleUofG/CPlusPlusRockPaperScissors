#pragma once
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include "RandInput.h"
#include "Utilities.h"
#include "ReadDelimitedFile.h"
#include <string>
using namespace std;
class RockPaperScissor {
private:
	
	Output *output;
	Input *input;
	Input* randInput;
	ReadDelimitedFile readDelimitedFile;
	Utilities utilities = Utilities();

	string generateRequest(vector<string> listOfItems) {
		string display = "Please select";
		int counter = 0;
		for (string item : listOfItems) {
			display += " " + to_string(counter);
			display += " - " + item;
			counter += 1;
		}
		return display;
	}
	vector<string> getListOfGames(vector<string> properties) {
		vector<string> games;
		for (string game : properties) {
			games.push_back(utilities.parseByDelimiter(game, ':')[0]);
		}

		return games;
	}

	vector<string> getWeapons(string listOfWeapons) {
		return utilities.parseByDelimiter(utilities.parseByDelimiter(listOfWeapons, ':')[1], ',');
	}
	vector<string> loadProperties() {
		return readDelimitedFile.getFileData("games.csv");
	}
	int getGame(vector<string> games) {
		output->output(generateRequest(games));
		int game = input->getInputInt();
		return game;
	}

	int getComputerWeapon() {
		return randInput->getInputInt();
	}

	string determineWinner(vector<string> weaponList, int userWeapon, int computerWeapon) {
		string winner;
		if (userWeapon == computerWeapon)
		{
			winner = "Draw both selected " + weaponList[computerWeapon];
		}
		else if ((userWeapon + 1) % 3 == computerWeapon)
		{
			winner = "You win and beat the computer's " + weaponList[computerWeapon];
		}
		else if ((computerWeapon + 1) % 3 == userWeapon)
		{
			winner = "Computer wins with " + weaponList[computerWeapon];
		}
		else {
			winner = "Please select 1. Rock, 2. Scissors or 3. Paper";
		}

		return winner + "\n";
	}

	vector<string> setUp() {
		vector<string> properties = loadProperties();
		vector<string> games = getListOfGames(properties);
		int game = getGame(games);
		vector<string> weapons = getWeapons(properties[game]);
		return weapons;
	}

	void play() {
		vector<string> weapons = setUp();
		int customerWeapon = 0;
		int computerWeapon;
		while (customerWeapon < weapons.size()) {
			output->output(generateRequest(weapons));
			customerWeapon = input->getInputInt();
			computerWeapon = getComputerWeapon();
			output->output(determineWinner(weapons, customerWeapon, computerWeapon));
		}

	}
public:
	RockPaperScissor(Output *output,Input *input, Input *randInput) {
		this->output = output;
		this->input = input;
		this->randInput = randInput;
	}

	void setOutput(Output *output) {
		this->output = output;
	}
	void setInput(Input *input) {
		this->input = input;
	}
	void setRandInput(Input* randInput) {
		this->randInput = randInput;
	}
	RockPaperScissor() {
		output = new ConsoleOutput();
		input = new ConsoleInput();
		randInput = new RandInput();
	}

	void main() {
		play();
	}


};
