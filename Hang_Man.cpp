#include <string>
#include <iostream>
#include <ctime>
using namespace std;

const int MAXGUESS = 7;

const string WORD_LIST[] = {"angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house", "island", "jewel",  "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
        "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};
const string FIGURE[] = {
    "   -------------    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
          "   -------------    \n"
         "   |           |    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
          "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |           |    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
          "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          /     \n"
         "   |     \n"
         " -----   \n",

         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          / \\  \n"
         "   |     \n"
         " -----   \n",

};
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
string getSecretWord();
char playerGuessChar();
int badGuess(char guess, string printAns, string secretWord, int badGuessCount);
string printAnswer(char guess, string printAns, string secretWord, int badGuessCount);

int main()
{
    char guess;
    int badGuessCount = 0;
    string secretWord = getSecretWord();
    int len = secretWord.size();
    string printAns = secretWord;
    for (int i=0; i<len; i++)
    {
        printAns[i] = '-';
    }
    do
    {
        cout << "Press a character: ";
        guess = playerGuessChar();
        cout << endl;
        printAns = printAnswer(guess, printAns, secretWord, badGuessCount);
        badGuessCount = badGuess(guess, printAns, secretWord, badGuessCount);
        cout << "Bad Guess: " << badGuessCount << " / " << MAXGUESS << endl;
        cout << FIGURE[badGuessCount] << endl;
        if (badGuessCount == MAXGUESS && printAns != secretWord)
        	cout << "You lose! You guess wrong word over 7 times!" << "The Secret Word is: " << secretWord;
    	else if (printAns != secretWord)
        	cout << "Processing...: " << printAns << endl;
   	 	else
        	cout << "Congratulations! Your guess is true!" << endl << "The Secret Word is: " << secretWord;
        cout << endl;
    } while (badGuessCount < MAXGUESS && printAns != secretWord);
    return 0;
}

string getSecretWord()
{
    srand(time(0));
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex];
}

char playerGuessChar()
{
    char guess;
    cin >> guess;
    return guess;
}


int badGuess(char guess, string printAns, string secretWord, int badGuessCount)
{
    int len = secretWord.size();
    for (int i=0; i<len; i++)
    {
        if (guess == secretWord[i])
            return badGuessCount;
    }
    badGuessCount++;
    return badGuessCount;
}

string printAnswer(char guess, string printAns, string secretWord, int badGuessCount)
{
    int len = secretWord.size();
    for (int i=0; i<len; i++)
    {
        if (secretWord[i] == guess)
            printAns[i] = secretWord[i];
    }
    return printAns;
}
