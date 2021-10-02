#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

class Player
{

	int bp, ap, sp, health;
	string CharacterName;
public:

	Player(string Character = "", int BP = 0, int AP = 0, int SP = 0, int HP = 0)
	{
		CharacterName = Character;
		bp = BP;
		ap = AP;
		sp = SP;
		health = HP;
	}

	void setHealth(int hp) {
		health = hp;
	}
	int getHealth() {
		return health;
	}
	int getAp() {
		return ap;
	}
	int getSp() {
		return sp;
	}
	int getBp() {
		return bp;
	}
	string getName() {
		return CharacterName;
	}
};

class Game
{
	string account_name;
	Player player_character;
	Player computer_character;
	vector <Player> characters;
public:
	void add_player(Player p) {
		characters.push_back(p);
	}
	void add_account(string name) {
		account_name = name;
	}
	void generateRandomOpponent() {
		// generate a random number and 
		// an AI enemy player based on that
		int random_index = rand() % 5;
		computer_character = characters[random_index];
	}
	void set_opponent_character(Player p) {
		computer_character = p;
	}

	void set_player_character(Player p) {
		player_character = p;

		// Besides player character, also randomly select a computer character
		// based on a random generated value
		// generateRandomOpponent();
	}
	Player get_player_character() {
		return player_character;
	}
	vector<Player> get_characters() {
		return characters;
	}
	Player get_opponent_character() {
		return computer_character;
	}
	string get_account_name() {
		return account_name;
	}
	void setPlayerHealth(int hp) {
		player_character.setHealth(hp);
	}
	void setOpponentHealth(int hp) {
		computer_character.setHealth(hp);
	}
	void attackPlayer() {
		// random value to see if the attacker uses ap or sp
		int ap_or_sp = rand() % 2 + 1;
		// random value to see if attack can be defended
		int def = rand() % 2 + 1;

		// attack power based on ap_or_sp
		int attack;
		if (ap_or_sp == 1)
		{
			attack = computer_character.getAp();
		}
		else
		{
			attack = computer_character.getSp();
		}
		// block power based on def
		int block;
		if (def == 1)
		{
			block = player_character.getBp();
		}
		else
		{
			block = 0;
		}

		// set defender's health accordingly
		player_character.setHealth(
			player_character.getHealth() - (attack - block)
		);
	}
	void attackOpponent() {
		// random value to see if the attacker uses ap or sp
		int ap_or_sp = rand() % 2 + 1;
		// random value to see if attack can be defended
		int def = rand() % 2 + 1;

		// attack power based on ap_or_sp
		int attack;
		if (ap_or_sp == 1)
		{
			attack = player_character.getAp();
		}
		else
		{
			attack = player_character.getSp();
		}
		// block power based on def
		int block;
		if (def == 1)
		{
			block = computer_character.getBp();
		}
		else
		{
			block = 0;
		}

		// set defender's health accordingly
		computer_character.setHealth(
			computer_character.getHealth() - (attack - block)
		);
	}
};

class ScoreBoard
{
	vector<string> players;
	vector<int> points;
public:

	void print_scoreboard()
	{
		cout << "\n\nName \tPoints " << endl;
		for (int i = 0; i < players.size(); i++) {
			cout << players[i] << "\t" << points[i] << endl;
		}
	}
	void addScore(string playerName, int score)
	{
		players.push_back(playerName);
		points.push_back(score);
	}
	void printToFile()
	{
		ofstream file("Score.txt");
		file << "Name \tPoints " << endl;
		for (int i = 0; i < players.size(); i++) {
			file << players[i] << "\t" << points[i] << endl;
		}
		file.close();
	}
};


int main()
{
	Game game;
	ScoreBoard sb;
	string welcome;

	//
	// create the characters based on the file info
	//
	ifstream input;
	input.open("MK.txt");
	// Read file
	if (input.good())
	{
		string tmp;
		// reading and skipping first 3 lines
		getline(input, tmp);
		getline(input, tmp);
		getline(input, tmp);
		// Creating player objects from file 
		for (int i = 0; i < 5; i++) {
			int iTmp_bp, iTmp_ap, iTmp_sp;
			input >> tmp >> iTmp_bp >> iTmp_ap >> iTmp_sp;
			Player p(tmp, iTmp_bp, iTmp_ap, iTmp_sp);
			// adding player objects to vector
			game.add_player(p);
		}
	}
	input.close(); // close file

	//
	// Print file contents on the console
	//
	input.open("MK.txt"); // reopen file
	while (input.good()) {
		char ch;
		input.get(ch);
		welcome += ch;
	}
	input.close(); // close file


	bool game_over = false;

	while (game_over == false)
	{

		cout << welcome;
		// Player's name
		string name;
		cout << "Enter your name:  ";
		cin >> name;
		game.add_account(name);

		// Player's character
		cout << "Which character do you like? Press [1 to 5]: ";
		int opt_character;
		cin >> opt_character;
		// assign chosen character for player
		game.set_player_character(game.get_characters()[opt_character - 1]);

		// Run a loop for every stage 
		unsigned stage = 1;
		int stage_points;
		bool stage_win = true;
		// Run either 15 times or until the player 
		// loses and stage_win is false
		for (int i = 0; i < 15 && stage_win; i++)
		{
			// start stage with heading
			cout << endl << "==========Stage" << stage << " Begins=========" << endl << endl;

			// generate new enemy
			game.set_opponent_character(
				game.get_characters()[(stage - 1) % 5]
			);

			// Stage points
			stage_points = game.get_player_character().getHealth() + 100 * stage;

			//set health values for the player and the AI
			game.setPlayerHealth(stage_points);
			game.setOpponentHealth(100 * stage);

			//
			// stage fight begins
			//
			while (game.get_player_character().getHealth() > 0)
			{ // continue fighting as long as the fighters have health above 0
				//player attacks
				game.attackOpponent();

				// check if opponent died or not
				if (game.get_opponent_character().getHealth() > 0)
				{ // if computer AI is still alive, AI will attack the player
					// AI attacks player
					game.attackPlayer();
				}
				else
				{ // if the opponent cannot fight and ran out of health, break the loop
					break;
				}
			}
			// breaks the loop if either player or AI dies
			// If player dies, stage over
			if (game.get_player_character().getHealth() <= 0)
			{
				stage_win = false;

				// Also show stage summary
				cout << game.get_opponent_character().getName() << " wins over "
					<< game.get_account_name() << " with "
					<< game.get_opponent_character().getHealth() << " points." << endl;
			}
			// if player wins, print stage summary
			// and continue to next stage 
			else
			{
				stage_win = true;

				// print summary
				cout << game.get_account_name() << " wins over "
					<< game.get_opponent_character().getName() << " with "
					<< stage_points << " points." << endl;
			}

			// proceed to next stage
			stage++;
		}

		// Stage ended
		// print the points earned
		cout << endl << "========== GAME OVER =========" << endl << endl;
		cout << game.get_account_name() << " earns " << stage_points << " points." << endl << endl;
		sb.addScore(game.get_account_name(), stage_points);

		// Offer to show scoreboard
		cout << "Do you want to see all scoreboards [Y/N]: ";
		string opt_show_scoreboard;
		cin >> opt_show_scoreboard;
		if (opt_show_scoreboard == "Y")
		{
			sb.print_scoreboard();
		}


		// Offer to play again
		cout << "Do you want to play again [Y/N]: ";
		string opt_replay;
		cin >> opt_replay;
		// if yes, run again
		if (opt_replay == "Y")
		{
			game_over = false;
		}
		else
		{
			game_over = true;
		}
	}
	sb.printToFile();

	cout << endl << "Thanks for trying MORTAL COMBAT" << endl;

	// program quit
	return 0;
}