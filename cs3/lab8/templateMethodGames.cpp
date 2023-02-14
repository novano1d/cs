//Modified by Matthew Moore
//10-28-2022
// Games, Template Method example
// Mikhail Nesterenko
// 2/4/2014

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>

using std::cout; using std::endl;

// template for any game where players take 
// turns to make moves
// and there is a winner
class Game{
public:
   Game():playersCount_(0), movesCount_(0), playerWon_(noWinner){}

   // template method
   void playGame(const int playersCount = 0) {
      playersCount_ = playersCount;
      movesCount_=0;

      initializeGame();

      for(int i=0; !endOfGame(); i = (i+1) % playersCount_ ){
	      makeMove(i);
	      if (i==playersCount_-1) 
	      ++movesCount_; 
      }
      printWinner();
   }

   virtual ~Game(){}

protected:
   // primitive operations
   virtual void initializeGame() = 0;
   virtual void makeMove(int player) = 0;
   virtual void printWinner() = 0;
   virtual bool endOfGame() { return playerWon_ != noWinner;} // this is a hook
                   // returns true if winner is decided
   static const int noWinner=-1;

   int playersCount_;
   int movesCount_;
   int playerWon_;
};

class Dice: public Game
{
//I was a little confused for the rules of the game?
//wasn't sure if pass was a one-time final decision to stop rolling or a turn by turn basis 
//I assumed it was a one-time decision to stop rolling and settle with your current score.
//also made it so computer can't pass on the first round because that doesn't make sense
public:
   void initializeGame()
   {
      playersCount_ = 2;
   }
   void printWinner()
   {
      if (playerWon_ == 0)
      {
         std::cout << "You lost!\n";
      }
      else if (playerWon_ == 1) std::cout << "You won!\n";
      else std::cout << "You tied!\n";
   }
   void makeMove(int player)
   {
      if ((turnNum_%2==0) && (movesCount_ == 3 || (computerPass_ && humanPass_)))
      {
         if ((computerScore_ == humanScore_) || (computerScore_ > humanScore_))
         {
            playerWon_ = 0;
         }
         else if (humanScore_ > computerScore_) playerWon_ = 1;
         return;
      }
      turnNum_++;
      std::vector<int> rolls;
      if (player == 0) //computer move
      {
         std::cout << "Round " << movesCount_ + 1 << ": ";
         std::cout << "Computer rolled: ";
         if (!computerPass_ && movesCount_ != 0) computerPass_ = randomBool();
         if (!computerPass_)
         {
            for (int i = 0; i < 5; i++) rolls.push_back(rollDice());
            for (int i = 0; i < rolls.size(); i++)
            {
               if (i != rolls.size()-1) std::cout << rolls[i] << ' ';
               else std::cout << rolls[i];
            }
         }
         else std::cout << "passed";   
         computerScore_ += std::accumulate(rolls.begin(), rolls.end(), 0);
         std::cout << ", computer's score = " << computerScore_ << std::endl;
      }
      else //player move
      {
         std::cout << "You rolled: ";
         if (!humanPass_)
         {
            for (int i = 0; i < 5; i++) rolls.push_back(rollDice());
            for (int i = 0; i < rolls.size(); i++)
            {
               if (i != rolls.size()-1) std::cout << rolls[i] << ' ';
               else std::cout << rolls[i];
            }
         }
         else std::cout << "passed";
         humanScore_ += std::accumulate(rolls.begin(), rolls.end(), 0);
         std::cout << ", your score = " << humanScore_ << std::endl;
         if (!humanPass_ && !(movesCount_+1 == 3) && !(computerPass_ && humanPass_))
         {
            char s;
            std::cout << "Roll again? [y/n] ";
            std::cin >> s;
            if (s == 'n') humanPass_ = true;
         }
      }
   }
private:
   int computerScore_ = 0;
   int humanScore_ = 0;
   bool computerPass_ = false;
   bool humanPass_ = false;
   int rollDice() { return rand()%(6) + 1; };
   int turnNum_ = 0;
   bool randomBool() { return rand()%(2); };
};


// Monopoly - a concrete game implementing primitive 
// operations for the template method
class Monopoly: public Game {
public:  
   // implementing concrete methods
   void initializeGame(){
      playersCount_ = rand() % numPlayers_ + 1 ; // initialize players
   }

   void makeMove(int player) {
      if (movesCount_ > minMoves_){ 
	 const int chance = minMoves_ + rand() % (maxMoves_ - minMoves_);
	 if (chance < movesCount_) playerWon_= player;
      }
   }

   void printWinner(){
      cout << "Monopoly, player "<< playerWon_<< " won in "
	   << movesCount_<< " moves." << endl;
   }

private:
   static const int numPlayers_ = 8; // max number of players
   static const int minMoves_ = 20; // nobody wins before minMoves_
   static const int maxMoves_ = 200; // somebody wins before maxMoves_
};




// Chess - another game implementing
// primitive operations
class Chess: public Game {
public:
   void initializeGame(){
      playersCount_ = numPlayers_; // initalize players
      for(int i=0; i < numPlayers_; ++i) 
	     experience_[i] = rand() % maxExperience_ + 1 ; 
   }

   void makeMove(int player){
      if (movesCount_ > minMoves_){
	 const int chance = (rand() % maxMoves_) / experience_[player];
	 if (chance < movesCount_) playerWon_= player;
      }
   }

   void printWinner(){
      cout << "Chess, player " << playerWon_ 
	   << " with experience " << experience_[playerWon_]
	   << " won in "<< movesCount_ << " moves over"
	   << " player with experience " << experience_[playerWon_== 0 ? 1:0] 
           << endl;
   }

private:
   static const int numPlayers_ = 2;
   static const int minMoves_ = 2; // nobody wins before minMoves_
   static const int maxMoves_ = 100; // somebody wins before maxMoves_
   static const int maxExperience_ = 5; // player's experience
                              // the higher, the greater probability of winning
   int experience_[numPlayers_]; 
};

int main() {
   srand(time(nullptr));

   Game* gp = nullptr;

   // play dice one time
   gp = new Dice;
   gp->playGame(); 
   delete gp;
}
