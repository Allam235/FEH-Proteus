#include "FEHLCD.h"
#include "FEHUtility.h"
#include <FEHUtility.h>
#include <FEHImages.h>
#include <iostream>
#include <string>
#include <fstream>
#include <FEHRandom.h>

using namespace std;

class Button{
    public:
    Button(string inName, int inBLx, int inBLy, int inTRx, int inTRy){
        name = inName;
        BLx = inBLx;
        BLy = inBLy;
        TRx = inTRx;
        TRy = inTRy;
    }
        bool inButton(int* cord){
            int x = *cord;
            int y = *(cord+1);
            bool in = false;
            if(x > BLx && x < TRx && y < BLy && y > TRy){
                in = true;  
            }
            return in;
        }

        string getName(){
            return name;
        }

    private:

    string name;
    int BLx;
    int BLy;
    int TRx;
    int TRy;

};


int* Cord();
void InfiniteCord();

void StartMenu();
void Credits();
void PlayMenu();
void StatisticsPage();
void TutorialPage();
void BlackjackGame();
int CardValues(char*);
char* GenerateCardName();
int GenerateCardValue(char* CardName);

string checkButtonPressed(Button buttonArr[],int length, int* cord);





/*
    SDP Training Minigame #3
  
    There are two circles – one on the left, one on the right.​
    The two circles go from one side to the opposite side.​
    Make it so that when the two circles collide, they disappear.​
*/

int main() {
    // Clear background
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    //Menu();
    StartMenu();
    InfiniteCord();
    

    while (1) {
        LCD.Update();
        // Never end
    }
    return 0;
}

void InfiniteCord(){
    float x, y;
    float xT, yT;

    while(true){
        while(!LCD.Touch(&x,&y)) {};
        /* Wait until the touch releases */
        while(LCD.Touch(&xT,&yT)) {};
 
        /* Print proper x and y coordinates to screen */
        cout << '(' << x << "," << y << ')' << endl;
        
    }

}

string checkButtonPressed(Button buttonArr[], int length, int* cord){
    //loop through all button objects
    for(int i = 0; i<length; i++){
        if(buttonArr[i].inButton(cord)){
            cout << buttonArr[i].getName() << " pressed" << endl;
            return buttonArr[i].getName();
        }
    }
    return "none";
}


void Cord(int* cord){
    float x, y;
    float xT, yT;

    while(!LCD.Touch(&x,&y)) {};
    /* Wait until the touch releases */
    while(LCD.Touch(&xT,&yT)) {};

    /* Print proper x and y coordinates to screen */
    //cout << '(' << x << "," << y << ')' << endl;
    *(cord) = x;
    *(cord+1) = y;
    //cout << '(' << cord[0] << "," << cord[1] << ')' << endl;
    //cout << cord << endl;
}

void CordFlash(int* cord, string page1Loco, string page2Loco){
    float x, y;
    float xT, yT;
    FEHImage page1;
    page1.Open("Pre-GameScreens/PlayMenu.png");
    FEHImage page2;
    page2.Open("Pre-GameScreens/PlayMenu_GA.png");
    

    while(!LCD.Touch(&x,&y)) {
        LCD.Clear();
        page2.Draw(0, 0);
        Sleep(0.5);
        LCD.Clear();
        page1.Draw(0,0);
        Sleep(0.5);
    };
    /* Wait until the touch releases */
    while(LCD.Touch(&xT,&yT)) {};

    /* Print proper x and y coordinates to screen */
    //cout << '(' << x << "," << y << ')' << endl;
    *(cord) = x;
    *(cord+1) = y;
    //cout << '(' << cord[0] << "," << cord[1] << ')' << endl;
    //cout << cord << endl;
}

void Credits(){

    LCD.Clear();

    FEHImage creditsPage;
    int cord[2];
    // Open the image
    creditsPage.Open("Pre-GameScreens/Credits.png");
    creditsPage.Draw(0, 0);

    //play button (20,180) & (110,160)
    //create back button
    Button creditsPageBack = Button("back", 10, 230, 75, 210);
    while(true){
        Cord(cord);
        Button buttonArr[1] = {creditsPageBack};
        //check if back was pressed
        string buttonPressed = checkButtonPressed(buttonArr, 1, cord);

        //if yes send back to 
        if(buttonPressed.compare("back") == 0){
            cout << "Start Menu" << endl;
            StartMenu();
        }
    }
    

} 

void PlayMenu(){
    LCD.Clear();
    FEHImage playMenu;
    int cord[2];
    // Open the image
    playMenu.Open("Pre-GameScreens/PlayMenu.png");
    playMenu.Draw(0, 0);

    //play button (20,180) & (110,160)
    //create back button
    Button playMenuBack = Button("back", 10, 230, 75, 210);

    Button buttonArr[1] = {playMenuBack};
    while(true){
        CordFlash(cord, "Pre-GameScreens/PlayMenu", "Pre-GameScreens/PlayMenu_GA");
        
        //check if back was pressed
        string buttonPressed = checkButtonPressed(buttonArr, 1, cord);

        //if yes send back to 
        if(buttonPressed.compare("back") == 0){
            cout << "Start Menu" << endl;
            StartMenu();
        }
    }
}

void StatisticsPage(){
    LCD.Clear();

    FEHImage statsPage;
    int cord[2];
    // Open the image
    statsPage.Open("Pre-GameScreens/Statistics.png");
    statsPage.Draw(0, 0);

    //play button (20,180) & (110,160)
    //create back button
    Button statsPageBack = Button("back", 10, 230, 75, 210);
    while(true){
        Cord(cord);
        Button buttonArr[1] = {statsPageBack};
        //check if back was pressed
        string buttonPressed = checkButtonPressed(buttonArr, 1, cord);

        //if yes send back to 
        if(buttonPressed.compare("back") == 0){
            cout << "Start Menu" << endl;
            StartMenu();
        }
    }
}

void TutorialPage(){
    LCD.Clear();

    FEHImage TutorialPage;
    int cord[2];
    // Open the image
    TutorialPage.Open("Pre-GameScreens/Tutorial.png");
    TutorialPage.Draw(0, 0);

    //play button (20,180) & (110,160)
    //create back button
    Button tutoPageBack = Button("back", 10, 230, 75, 210);
    while(true){
        Cord(cord);
        Button buttonArr[1] = {tutoPageBack};
        //check if back was pressed
        string buttonPressed = checkButtonPressed(buttonArr, 1, cord);

        //if yes send back to 
        if(buttonPressed.compare("back") == 0){
            cout << "Start Menu" << endl;
            StartMenu();
        }
    }
}

void StartMenu() {
    //screen size 320x240
    //LCD.WriteAt("Hello, welcome to F2HCasino", 0, 12);
    LCD.Clear();
    FEHImage startMenu;
    int cord[2];
    // Open the image
    startMenu.Open("Pre-GameScreens/Start Menu.png");
    startMenu.Draw(0, 0);
    //play button (95,130) & (225,100)
    Button startMenuPlay = Button("play", 95, 130, 225, 100);

    //play button (20,180) & (110,160)
    Button startMenuCredits = Button("credits", 20, 180, 110, 160);

    //play button (115,180) & (200,160)
    Button startMenuStat = Button("statistics", 115, 180, 200, 160);

    //play button (205,180) & (295,160)
    Button startMenuPlayTuto = Button("tutorial", 205, 180, 295, 160);

    Button buttonArr[4] = {startMenuPlay, startMenuCredits, startMenuStat, startMenuPlayTuto};

    while(true){
        Cord(cord);
        
        string buttonPressed = checkButtonPressed(buttonArr, 4, cord);

        if(buttonPressed.compare("credits") == 0){
            cout << "Credits Page" << endl;
            Credits();
        } else if(buttonPressed.compare("play") == 0){
            cout << "Play Menu" << endl;
            PlayMenu();
        } else if(buttonPressed.compare("statistics") == 0){
            cout << "Stat Page" << endl;
            StatisticsPage();
        } else if(buttonPressed.compare("tutorial") == 0){
            cout << "Tutorial Page" << endl;
            TutorialPage();
        }
        //cout << "Cord:" << "(" << *(cord) << "," << *(cord+1) << ")" << endl;
        //cout << "Result:" << startMenuPlay.inButton(cord) << endl;
    }

}

void BlackjackGame()
{
    int restart =1;
    while (restart !=0){
  
char CardName[20];
char DealerHiddenCard[20], PlayerFirstCard[20], PlayerSecondCard[20],DealerFirstCard[20]; 
int PlayerCard1, PlayerCard2, DealerCard1, DealerCard2, PlayerTotal, DealerTotal;
LCD.Clear();
FEHImage BlackjackGame; //Table Image
BlackjackGame.Open("SDP_Images/Blackjack_Table.png(2).png"); //SDP/images
BlackjackGame.Draw(0,0);

//Betting and finalize betting

//clear buttons from the betting

// add the table screen again and then add two face down cards on the dealers area
LCD.Clear();
FEHImage BlackjackGame;
BlackjackGame.Open("SDP_Images/Blackjack_Table.png(2).png");
BlackjackGame.Draw(0,0);
    Sleep(1.5);

FEHImage CardBacks;  
CardBacks.Open("SDP_Images/Back_of_Card.png");
CardBacks.Draw(130,170); //Player card 1
    Sleep(0.8);
CardBacks.Draw(160,170); //Player card 2
    Sleep(0.8);
   //After the two player cards, add the dealer cards.
CardBacks.Draw(130,40); //Dealer card 1
    Sleep(0.8);
CardBacks.Draw(160,40); //Dealer card 2, this will stay face down
    Sleep(0.8);

FEHImage PlayerCardOne;
strcpy(CardName,GenerateCardName());
char OpenStatement[50] = "SDP_Images/"; //Player card 1
char Statement_End[20] = ".png";
strcat(OpenStatement,CardName);   //Generate a card and draw it
strcat(OpenStatement,Statement_End);
PlayerCardOne.Open(OpenStatement);
PlayerCardOne.Draw(110,170);
Sleep(1.0);
PlayerCard1 = GenerateCardValue(CardName); //Store the cards values into variables
strcpy(PlayerFirstCard,CardName);


FEHImage PlayerCardTwo;
strcpy(CardName,GenerateCardName()); //Player card 2
if (strcmp(CardName,PlayerFirstCard) == 0){
    strcpy(CardName,GenerateCardName());    //Check to make sure the two cards are not the same
}
char OpenStatement[50] = "SDP_Images/";
char Statement_End[20] = ".png";
strcat(OpenStatement,CardName);    //Generate a new card
strcat(OpenStatement,Statement_End);
PlayerCardTwo.Open(OpenStatement);
PlayerCardTwo.Draw(140,170);
Sleep(1.0);
PlayerCard2 = GenerateCardValue(CardName);
strcpy(PlayerSecondCard,CardName);

FEHImage DealerCardOne;
strcpy(CardName,GenerateCardName()); //Dealer card 1
char OpenStatement[50] = "SDP_Images/";
char Statement_End[20] = ".png";
strcat(OpenStatement,CardName);    //Generate a new card
strcat(OpenStatement,Statement_End);
DealerCardOne.Open(OpenStatement);
DealerCardOne.Draw(130,40);
DealerCard1 = GenerateCardValue(CardName);
strcpy(DealerFirstCard,CardName);


strcpy(CardName,GenerateCardName()); //Dealer card 2
if (strcmp(CardName,DealerFirstCard) == 0){
    strcpy(CardName,GenerateCardName());    //Check to make sure the two cards are not the same
}
strcpy(DealerHiddenCard,CardName);
DealerCard2 = GenerateCardValue(DealerHiddenCard);


PlayerTotal = PlayerCard1 + PlayerCard2; //Player Total 
DealerTotal = DealerCard1 + DealerCard2; //Dealer Total


if (PlayerTotal == 21){
    Sleep(3.0);
    LCD.WriteAt("Player 1 Wins",140,142); // Check if the values of the two cards are equal to 21 
    Sleep(5.0);
    break;
}

//Redraw the screen to ask whether to give the player another card.

LCD.Clear();
FEHImage QuestionScreen; //ask the player to stay or get another card
QuestionScreen.Open("BlackJack_Question.png");
QuestionScreen.Draw(0,0);

FEHImage CardBacks; 
CardBacks.Open("SDP_Images/Back_of_Card.png");
CardBacks.Draw(160,40);

FEHImage PlayerCardOne;
char OpenStatement[50] = "SDP_Images/"; //Player card 1
char Statement_End[20] = ".png";
strcat(OpenStatement,PlayerFirstCard);   //Generate a card and draw it
strcat(OpenStatement,Statement_End);
PlayerCardOne.Open(OpenStatement);
PlayerCardOne.Draw(130,170);

FEHImage PlayerCardTwo;
char OpenStatement[50] = "SDP_Images/"; //Player second card
char Statement_End[20] = ".png";
strcat(OpenStatement,PlayerSecondCard);    //Generate a new card
strcat(OpenStatement,Statement_End);
PlayerCardTwo.Open(OpenStatement);
PlayerCardTwo.Draw(160,170);

FEHImage DealerCardOne;
char OpenStatement[50] = "SDP_Images/"; //Dealer first card
char Statement_End[20] = ".png";
strcat(OpenStatement,DealerFirstCard);    //Generate a new card
strcat(OpenStatement,Statement_End);
DealerCardOne.Open(OpenStatement);
DealerCardOne.Draw(130,40);

//Add buttons to the options on the screen



// use the random generator to get another card and add its image to the table

// Check to see if the value of the three values of the cards are equal to or greater than 21


    }
}

int CardValues(char* CardName){
    int Pcard;
    if (CardName == "Ace_Diamonds"){
        Pcard =11;}
    if (CardName == "Ace_Hearts"){
        Pcard =11;}                  //Ace Cards
    if (CardName == "Ace_Spades"){
        Pcard =11;}
    if (CardName == "Ace_Clubs"){
        Pcard =11;}

    if (CardName == "King_Hearts"){
        Pcard =10;}
    if (CardName == "King_Clubs"){
        Pcard =10;}                 //King Cards
    if (CardName == "King_Spades"){
        Pcard =10;}
    if (CardName == "King_Diamonds"){
        Pcard =10;}

    if (CardName == "Queen_Hearts"){
        Pcard =10;}
    if (CardName == "Queen_Diamonds"){
        Pcard =10;}                 //Queen Cards
    if (CardName == "Queen_Clubs"){
        Pcard =10;}
    if (CardName == "Queen_Spades"){
        Pcard =10;}

    if (CardName == "Jack_Hearts"){
        Pcard =10;}
    if (CardName == "Jack_Diamonds"){
        Pcard =10;}                 //Jack Cards
    if (CardName == "Jack_Clubs"){
        Pcard =10;}
    if (CardName == "Jack_Spades"){
        Pcard =10;}
  
    if (CardName == "Ten_Hearts"){
        Pcard =10;}
    if (CardName == "Ten_Diamonds"){
        Pcard =10;}                 //Ten Cards
    if (CardName == "Ten_Clubs"){
        Pcard =10;}
    if (CardName == "Ten_Spades"){
        Pcard =10;}

    if (CardName == "Nine_Hearts"){
        Pcard =9;}
    if (CardName == "Nine_Diamonds"){
        Pcard =9;}                 //Nine Cards
    if (CardName == "Nine_Clubs"){
        Pcard =9;}
    if (CardName == "Nine_Spades"){
        Pcard =9;}

    if (CardName == "Eight_Hearts"){
        Pcard =8;}
    if (CardName == "Eight_Diamonds"){
        Pcard =8;}                 //Eight Cards
    if (CardName == "Eight_Clubs"){
        Pcard =8;}
    if (CardName == "Eight_Spades"){
        Pcard =8;}

    if (CardName == "Seven_Hearts"){
        Pcard =7;}
    if (CardName == "Seven_Diamonds"){
        Pcard =7;}                 //Seven Cards
    if (CardName == "Seven_Clubs"){
        Pcard =7;}
    if (CardName == "Seven_Spades"){
        Pcard =7;}

    if (CardName == "Six_Hearts"){
        Pcard =6;}
    if (CardName == "Six_Diamonds"){
        Pcard =6;}                 //Six Cards
    if (CardName == "Six_Clubs"){
        Pcard =6;}
    if (CardName == "Six_Spades"){
        Pcard =6;}

    if (CardName == "Five_Hearts"){
        Pcard =5;}
    if (CardName == "Five_Diamonds"){
        Pcard =5;}                 //Five Cards
    if (CardName == "Five_Clubs"){
        Pcard =5;}
    if (CardName == "Five_Spades"){
        Pcard =5;}

    if (CardName == "Four_Hearts"){
        Pcard =4;}
    if (CardName == "Four_Diamonds"){
        Pcard =4;}                 //Four Cards
    if (CardName == "Four_Clubs"){
        Pcard =4;}
    if (CardName == "Four_Spades"){
        Pcard =4;}

    if (CardName == "Three_Hearts"){
        Pcard =3;}
    if (CardName == "Three_Diamonds"){
        Pcard =3;}                 //Three Cards
    if (CardName == "Three_Clubs"){
        Pcard =3;}
    if (CardName == "Three_Spades"){
        Pcard =3;}

    if (CardName == "Two_Hearts"){
        Pcard =2;}
    if (CardName == "Two_Diamonds"){
        Pcard =2;}                 //Two Cards
    if (CardName == "Two_Clubs"){
        Pcard =2;}
    if (CardName == "Two_Spades"){
        Pcard =2;}
    
    //Return Value
    return Pcard;
}

char* GenerateCardName(){
    //Function defined to randomly generate a card name from the text file list
    char Cards[100][100], CardName[20];
    int i, PCards[10],DCards[10], CardNum, CardValue;
    ifstream CardNames;
    CardNames.open("Image_Names.txt");
    for (i=0;i<53;i++){
        CardNames >> Cards[0][i];       
    }
    CardNames.close();
    CardNum = ((52*Random.RandInt())/32767);
    strcpy(CardName,Cards[CardNum]);
    return CardName;
}
    
int GenerateCardValue(char* CardName){
    //Assign a value to the randomly generated card
    int CardValue;
    CardValue = CardValues(CardName);
    return CardValue;
}
    