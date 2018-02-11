#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cctype>

class Word
{
    private:
        int count;
        int max;
        int min;
        std::string *choice;
    public:
        Word(int m, int ma)
        {
            count = 0;
            max = ma;
            min = m;
        }
        ~Word()
        {
            delete [] choice;
        }
        void infile();
        void put_inarray();
        std::string get_random_word();
        
};
class Hangman 
{
    private:
        char word[40];
        char progress[40];
        int word_length;
        void clear_progress(int length)
        {
            int i;
            for(i = 0; i < length; i++)
            {
                progress[i] = '-';
            }
            progress[i] = '\0';
        }
    protected:
        int matches;
        char last_guess;
        std::string chars_guessed;
        int wrong_guesses;
        int remaining;
        // chech if the letter the user guessed is in the word if not decrease the # of tries
        bool check(char user_guess)
        {
            last_guess = user_guess;    
            matches = 0;
            for(int i = 0; i < strlen(word); i++)
            {
                if(user_guess == word[i])
                {
                    progress[i] = user_guess;
                    matches++;
                }
            }
            if(matches > 0)
            {
                return true;
            }
            else
            {   
                if(find())
                {
                    wrong_guesses++;
                    remaining--;
                    chars_guessed += user_guess;
                    
                }
                return false;   
            }

        }
        bool find()
        {
            int count = 0;
            if(chars_guessed.length() == 0)
            {
                return true;
            }    
            else
            {
                for(int i = 0; i < chars_guessed.length(); i++)
                {
                    if(last_guess == chars_guessed[i])
                    {
                        count++;
                    }
                }
                if(count > 0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    public:         
        Hangman(std::string a)
        {
            initialize(a);                         
        }
        void initialize(std::string w);
        char *getter_word()
        {
            return word;   
        }
        char *getter_progress()
        {
            return progress;
        }       
        int getter_remaining()
        {
            return remaining;
        }
        bool is_word_complete()
        {
            return (!strcmp(word, progress)); 
        }

        
               
};
class HangmanConsole : public Hangman
{
    public:
        HangmanConsole(std::string start) : Hangman(start){}
        //show the status 
        void show_status(int stage)
        {
           switch (stage)
           {
                case 0:
                    std::cout << "+------\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "-----\n";
                   break;
               case 1:
                    std::cout << "+---------\n";
                    std::cout << "|     __l__\n";
                    std::cout << "|     |o o|\n";
                    std::cout << "|     | * |\n";
                    std::cout << "|     |---|\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "-----\n";
                    break;
               case 2:
                    std::cout << "+---------\n";
                    std::cout << "|     __l__\n";
                    std::cout << "|     |o o|\n";
                    std::cout << "|     | * |\n";
                    std::cout << "|     |---|\n";
                    std::cout << "|       |\n";
                    std::cout << "|       |\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "-----\n";
                    break;
               case 3:
                    std::cout << "+---------\n";
                    std::cout << "|     __l__\n";
                    std::cout << "|     |o o|\n";
                    std::cout << "|     | * |\n";
                    std::cout << "|     |---|\n";
                    std::cout << "|       |\n";
                    std::cout << "|       |\n";
                    std::cout << "|      /\n";
                    std::cout << "|     /\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "-----\n";
                    break;
              case 4:
                    std::cout << "+---------\n";
                    std::cout << "|     __l__\n";
                    std::cout << "|     |o o|\n";
                    std::cout << "|     | * |\n";
                    std::cout << "|     |---|\n";
                    std::cout << "|       |\n";
                    std::cout << "|       |\n";
                    std::cout << "|      / \\"<<std::endl;
                    std::cout << "|     /   \\"<<std::endl;
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "-----\n";
                    break;
             case 5:
                    std::cout << "+---------\n";
                    std::cout << "|     __l__\n";
                    std::cout << "|     |o o|\n";
                    std::cout << "|     | * |\n";
                    std::cout << "|     |---|\n";
                    std::cout << "|     / |\n";
                    std::cout << "|    /  |\n";
                    std::cout << "|      / \\"<<std::endl;
                    std::cout << "|     /   \\"<<std::endl;
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "-----\n";
                    break;
             case 6:
                    std::cout << "+---------\n";
                    std::cout << "|     __l__\n";
                    std::cout << "|     |o o|\n";
                    std::cout << "|     | * |\n";
                    std::cout << "|     |---|\n";
                    std::cout << "|     / | \\ \n";
                    std::cout << "|    /  |  \\ \n";
                    std::cout << "|      / \\"<<std::endl;
                    std::cout << "|     /   \\"<<std::endl;
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "|\n";
                    std::cout << "-----\n";
                    break;

           }
                       
        } 
        void show_info()
        {
            show_status(wrong_guesses);
            std::cout << std::endl;
            std::cout << getter_progress() << std::endl;
            std::cout << "matches found "<< last_guess << ": " << matches << std::endl;
            std::cout << "Wrong guesses:" << chars_guessed << std::endl;
            std::cout << "Tries remaining:" << remaining << std::endl;
        }
        friend std::istream &operator >>(std::istream &in, HangmanConsole &right)
        {
            char a;
            in >> a;
            right.check(a);
            return in;
        }
        
};
void Word::infile()
{
    std::ifstream ifs;

    ifs.open("enable1.txt");

    std::string word;

    if(ifs.is_open())
    {
        while(ifs >> word)
        {
            if(ifs.good())
            {
                if(word.length() >= min && word.length() <= max)
                {
                    count++;
                }
            }   

        }
        ifs.close();
    }


}
//gather all the words that satisfy the constraints that the user inputs
void Word::put_inarray()
{
    choice = new std::string[count];
    
    std::ifstream ifs;

    ifs.open("enable1.txt");

    std::string word;
    int i = 0;

    if(ifs.is_open())
    {
        while(ifs >> word)
        {
            if(ifs.good())
            {
                if(word.length() >= min && word.length() <= max)
                {
                    choice[i] = word;
                    i++;
                }
            }
        }
        ifs.close();
    }
}
//randomly pick a word from the words we gathered from put_array
std::string Word::get_random_word()
{
    int random = rand() % count;     
    return choice[random];   
}
void Hangman::initialize(std::string w)
{
    chars_guessed = "";
    wrong_guesses = 0;
    remaining = 6;
    int i;
    for(i = 0; i < w.length(); i++)
    {
        word[i] = w[i];
    }
    word[i] = '\0';
    clear_progress(i);
}

int main()
{
    srand(time(NULL));
  
    int mini;
    int maxi;
    std::string oneword;
    // ask for constraints 
    do{
    std::cout << "Enter min and max: ";
    std::cin >> mini >> maxi;
    }while((mini <= 1 && maxi <=1) || (mini > 28 && maxi > 28));
 
    Word w1(mini, maxi);
    w1.infile();
    w1.put_inarray();
    
    HangmanConsole game(w1.get_random_word());

    std::cout << "HANGMAN" << std::endl << "------" << std::endl << std::endl;
    std::cout << "Your word is: " << game.getter_progress() << std::endl;
    
    while(!game.is_word_complete() && game.getter_remaining() > 0)
    {
        std::cout << std::endl;
        std::cout << "Enter your guess: ";
        std::cin >> game;
        system("clear");
        game.show_info();
    }


    return 0;

} 
