#include "highscore.h"
extern Console g_Console;

//Highscore for the game. Ultimately, timing is the one to see who's the 'winner' - Fastest. The steps is just there to show to the player(s) on how many steps the player(s) took to complete within that 'time'.
void highScore(string playtime, string playsteps){

	fstream myfile;
	fstream myfile2;
	myfile.open("highscore.txt", fstream::app);
	myfile << "\n" << playtime;
	myfile2.open("scoreSteps.txt", fstream::app);
	myfile2 << "\n" << playsteps;
}

void renderScore(){			//Rendering the title for the scoreboard.
	COORD c = g_Console.getConsoleSize();
	c.Y = 0;
	c.X = g_Console.getConsoleSize().X / 2 - 30;

	string line;
	ifstream myfile("scoreTitle.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			c.Y += 1;
			g_Console.writeToBuffer(c, line);
		}
		myfile.close();
	}


	//Please debug. Will show you clearer than what my human mouth/words can

	double highScore[5] = { 0.0, };	//This is for 5 timing
	int highscoreStep[5] = { 0, };	//For 5 steps

	int allSteps[150] = { 0, };		//This is for ALL the steps, the allSteps[ x ], x can put any no. But I just put 150.
	double allScores[150] = { 0.0, };	//This is for all the timings, can put any number but I just put 150.If have more scores then put more

	int i = 0;

	//I'm changing string to double, it will be easier to compare rather than using string to compare. If I use string, I would have to take the 'how many digits' before ' . ' into consideration.
	//This was the only way I could think of and know how to do it.
	//After changing. assigning them into an array which will store ALL of them in an unsorted manner.

	ifstream myFile("highscore.txt");
	if (myFile.is_open()){		//Open file.... from "highscore.txt"


		while (getline(myFile, line)){	//This here get every line for you in string format. Debug will show yo.

			double score;	//Double because the timing have decimal

			score = stod(line);	//'stod' changes/copies string to double, then is assigned to score double type.
			allScores[i] = score;	//Assigning score to allScores[i]. E.g. I give you a basket of apples, and asking you to put those apples into that container.
			i++;	//If I don't i++, then the all the score will be assigned to allScores[ 0 ] . 
		}	//The while loop will stop when it reaches the end

		myFile.close();
	}

	//I reset i to 0 is because the above part, the ' i ' > 0. It doesn't matter because in the end, they'll have the same value assigned to i.
	//Timing & steps come together. [Err... like there won't be more lines of steps than timing.]
	//Like wise for steps, I'm changing string to int instead of double since steps is ' 10 ' , '96' etc. 
	//Assigning them into an array which will store ALL of them.

	i = 0;//reset to 0
	ifstream myfile3("scoreSteps.txt");
	if (myfile3.is_open()){		//Opening file... from "scoreSteps.txt"

		while (getline(myfile3, line)){	//This here get every line for you in string format. Debug will show yo.

			int score;		//Steps do not have decimals.

			score = stoi(line);	//'stoi' changes/copies string to int, then is assigned to score int type.
			allSteps[i] = score;	//Assigning score to allSteps[i]. E.g. I give you a basket of apples, and asking you to put those apples into that container.
			i++;		//Same for steps, if no ++, score (steps) will be assigned to allSteps [ 0 ].
		}
		myfile3.close();
	}
	//the highscoreCount is to check how many highscores have been registered. 
	int highscoreCount = 0;
	for (; highscoreCount < 5; highscoreCount++)	//Since I only want 5, so  highscoreCount < 5.
	{

		double highestScore = 0;	//This is to temporary store a value from the array, then comparing it to the rest.
		int highestSteps = 0;

		for (int a = 0; a < i; a++)
		{	// a < i. Why i? Because above, when you finish copying data from notepad, the int i never die so we can use it. It tells us how many data is copied. (a < i) means i loop ALL the values in the allScores[] array.

			if (highestScore == 0)
			{	//if there is no highscore registered, put a score inside

				highestScore = allScores[a];
				highestSteps = allSteps[a];
			}
			if (highestScore > allScores[a])
			{	//If there is a score that is faster than the highscore, replace that value
				//This here is to make sure that there are no 2 of the same timing in the highscore.

				bool insideArray = false;
				for (int c = 0; c < 5; c++)
				{	//This loops the entire highScore[].

					if (highScore[c] == allScores[a])
					{//If there's any value in the highScore[] that's the same as the selected value of (allScores[]). We set to boolean to true.
						insideArray = true;
					}
				}
				if (!insideArray)	//If highestscore is not inside the array, store it in.
				{
					highestScore = allScores[a];//highest score
					highestSteps = allSteps[a];//highest steps 
				}

			}
		}
		highScore[highscoreCount] = highestScore;
		highscoreStep[highscoreCount] = highestSteps;
	}

	for (int b = 0; b < 5; b++)
	{
		std::string str;
		std::string strSteps;
		char digits[10];
		char steps[10];
		str = to_string(highScore[b]);
		strSteps = to_string(highscoreStep[b]);

		std::strcpy(digits, str.c_str());
		std::strcpy(steps, strSteps.c_str());


		/*
		to_string() function coverts your double data type to string.
		str.c_str() inside the strcpy makes your string data type into char array digits[].

		std::strcpy(digits, str.c_str()) copies the 'str' into char array digits[].

		*/
		c.X = g_Console.getConsoleSize().X / 2 - 30;
		c.Y += 1;
		g_Console.writeToBuffer(c, digits);
		COORD secsCoord;
		secsCoord.X = g_Console.getConsoleSize().X / 2 - 20;
		secsCoord.Y = c.Y;
		g_Console.writeToBuffer(secsCoord, " secs");


		c.X = g_Console.getConsoleSize().X / 2;

		g_Console.writeToBuffer(c, steps);
		secsCoord.X = g_Console.getConsoleSize().X / 2 + 5;
		secsCoord.Y = c.Y;
		g_Console.writeToBuffer(secsCoord, " Steps");

	}

}