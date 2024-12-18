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
void BlackJackGame(int, int, string);
int CardValues(char*);
string GenerateCardName();
string SetDealerHiddenCard(int);
int GenerateCardValue(string);
void PrintCharArr(char* str, int length);
int calculateTotal(int[], int);

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

void PrintCharArr(char* str, int length){
    for(int i = 0; i< length; i++){
        cout << *(str+i);
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

void CordFlash(int* cord, char page1Loco[], char page2Loco[]){
    float x, y;
    float xT, yT;
    FEHImage page1;
    page1.Open(page1Loco);
    FEHImage page2;
    page2.Open(page2Loco);
    float beginTime = TimeNow();

    FEHImage images[2] = {page1, page2};
    int pageNum = 0;
    

    while(!LCD.Touch(&x,&y)) {
        if(TimeNow()-beginTime > 0.3){
            pageNum += (pageNum == 0)*1 + (pageNum == 1)*-1;
            beginTime  = TimeNow();
        }
        images[pageNum].Draw(0,0);
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

void StatisticsPage(){
    LCD.Clear();

    FEHImage statsPage;
    int cord[2];
    // Open the image
    statsPage.Open("Pre-GameScreens/Statistics.png");
    statsPage.Draw(0, 0);

    ifstream statsFileIn("statistics.txt");  // Open the file for reading
    int bank, numGames;  // Variables to store the extracted data
    
    // Read the values from the file
    statsFileIn >> bank;
    statsFileIn >> numGames;

    LCD.WriteAt(bank, 96, 67);
    LCD.WriteAt(numGames, 183, 82);



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
    startMenu.Open("Pre-GameScreens/StartMenu.png");
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

void PlayMenu(){
    LCD.Clear();
    FEHImage playMenu;
    FEHImage chooseDiff;

    int cord[2];
    // Open the image
    
    chooseDiff.Open("Pre-GameScreens/ChooseDiff.png");
    playMenu.Open("Pre-GameScreens/PlayMenu.png");
    playMenu.Draw(0, 0);

    Button playMenuBlackJack = Button("BlackJack", 180, 115, 305, 85);
    Button playMenuPoker = Button("Poker", 15, 115, 140, 85);
    Button playMenuGADiff = Button("Gambling Addict", 180, 195, 305, 165);
    Button playMenuNewbieDiff = Button("Newbie", 15, 195, 140, 165);

    //create back button
    Button playMenuBack = Button("back", 10, 230, 75, 210);

    Button buttonArr[5] = {playMenuBack, playMenuBlackJack, playMenuPoker, playMenuGADiff, playMenuNewbieDiff};
    string diff = "";
    while(true){
        if(diff.compare("GA") == 0){
            CordFlash(cord, "Pre-GameScreens/PlayMenu.png", "Pre-GameScreens/PlayMenu_GA.png");
        }else if (diff.compare("New") == 0){
            CordFlash(cord, "Pre-GameScreens/PlayMenu.png", "Pre-GameScreens/PlayMenu_Newbie.png");
        }else{
            Cord(cord);
        }

        //CordFlash(cord, "Pre-GameScreens/PlayMenu", "Pre-GameScreens/PlayMenu_GA");
        
        //check if back was pressed
        string buttonPressed = checkButtonPressed(buttonArr, 5, cord);
        //InfiniteCord();
        //if yes send back to 
        if(buttonPressed.compare("back") == 0){
            cout << "Start Menu" << endl;
            StartMenu();
        } else if(buttonPressed.compare("BlackJack") == 0){
            cout << "Black Jack" << endl;
            if(diff.compare("") == 0){
                chooseDiff.Draw(90, 210);
            } else{
                cout << "BlackJackGame" << endl;
                BlackJackGame(-1, -1, diff);
            }
        } else if(buttonPressed.compare("Poker") == 0){
            cout << "Poker" << endl;
            if(diff.compare("") == 0){
                chooseDiff.Draw(90, 210);
            } else{
                cout << "Poker" << endl;
                BlackJackGame(-1, -1, diff);
            }
        } else if(buttonPressed.compare("Gambling Addict") == 0){
            cout << "Gambling Addict" << endl;
            diff = "GA";
        } else if(buttonPressed.compare("Newbie") == 0){
            cout << "Newbie" << endl;
            diff = "New";
        }
    }
}

string GenerateCardName(){
    //Function defined to randomly generate a card name from the text file list
    string CardName;
    int PCards[10],DCards[10], CardNum, CardValue;
    ifstream CardNames;

    CardNum = ((52*Random.RandInt())/32767);// random card value;
    CardNames.open("Image_Names.txt");
    for (int i = 0; i<=CardNum; i++){
        CardNames >> CardName; 
    }

    CardNames.close();
    //cout << "CardName1: ";
    //PrintCharArr(CardName, strlen(CardName));
    //cout << endl;
    //cout << "Address: " << CardName << endl;
    return CardName;
}

//This method is for the GA difficulty where the dealer always gets 21
int GenerateCardValue(string CardName){
    int Pcard;
    // Check the rank of the card and set the value
    if (CardName.substr(0, 3) == "Ace") {
        Pcard = 11;
    } else if (CardName.substr(0, 4) == "King" || CardName.substr(0, 5) == "Queen" || CardName.substr(0, 4) == "Jack" || CardName.substr(0, 3) == "Ten") {
        Pcard = 10;
    } else if (CardName.substr(0, 4) == "Nine") {
        Pcard = 9;
    } else if (CardName.substr(0, 5) == "Eight") {
        Pcard = 8;
    } else if (CardName.substr(0, 5) == "Seven") {
        Pcard = 7;
    } else if (CardName.substr(0, 3) == "Six") {
        Pcard = 6;
    } else if (CardName.substr(0, 4) == "Five") {
        Pcard = 5;
    } else if (CardName.substr(0, 4) == "Four") {
        Pcard = 4;
    } else if (CardName.substr(0, 5) == "Three") {
        Pcard = 3;
    } else if (CardName.substr(0, 3) == "Two") {
        Pcard = 2;
    }
    //Return Value
    return Pcard;
}

int calculateTotal(int hand[], int handSize) {
    int total = 0;
    int aceCount = 0;

    // Calculate the total, counting Aces as 11
    for (int i = 0; i < handSize; ++i) {
        total += hand[i];
        if (hand[i] == 11) {  // Ace found
            aceCount++;
        }
    }

    // Adjust Aces if the total exceeds 21
    while (total > 21 && aceCount > 0) {
        total -= 10;  // Convert one Ace from 11 to 1
        aceCount--;
    }

    return total;
}

// Function to set the hidden card for the dealer so that their hand totals 21
string SetDealerHiddenCard(int firstCardValue) {
    if (firstCardValue == 11) {
        return "King_Hearts";
    } else if (firstCardValue == 9) {
        return "Two_Hearts";
    } else if (firstCardValue == 8) {
        return "Three_Hearts";
    } else if (firstCardValue == 7) {
        return "Four_Hearts";
    } else if (firstCardValue == 6) {
        return "Five_Hearts";
    } else if (firstCardValue == 5) {
        return "Six_Hearts";
    } else if (firstCardValue == 4) {
        return "Seven_Hearts";
    } else if (firstCardValue == 3) {
        return "Eight_Hearts";
    } else if (firstCardValue == 2) {
        return "Nine_Hearts";
    }
    return "Ace_Hearts";
}


void BlackJackGame(int bankIn = -1, int numG = -1, string diff = "New")
{   
    // screen 320x240
    // betting amount
    ifstream statsFileIn("statistics.txt");  // Open the file to read initial data
    
    FEHImage BettingScreen;
    FEHImage Warning;
    //if result = 1, tie, 2 means player won, 0 means player lost 
    int result = 2;
    int cord[2];
    int bank = bankIn;
    int numGames = numG;
    if(bank == -1){
        statsFileIn >> bank;
        statsFileIn >> numGames;  // Read bank and numGames
    }
    statsFileIn.close();  // Close after reading the initial values
    
    int betAmt = 0;
    string betAmtStr;
    int illegalAmount = 0;
    bool dealt = false;
    Warning.Open("SDP_Images/betWarning.png");
    BettingScreen.Open("SDP_Images/BettingScreen.png");
    BettingScreen.Draw(0,0);

    LCD.SetFontColor(WHITE);
    // update bet amt value on screen
    LCD.WriteAt(betAmt, 150, 100);
    // update bank value on screen
    LCD.WriteAt(bank, 92, 45);

    Button oneChip = Button("oneChip", 43, 175, 80, 139);
    Button fiveChip = Button("fiveChip", 82, 175, 120, 139);
    Button twentyFiveChip = Button("twentyFiveChip", 122, 175, 158, 139);
    Button fiftyChip = Button("fiftyChip", 161, 175, 197, 139);
    Button hundredChip = Button("hundredChip", 200, 175, 237, 139);
    Button fiveHundredChip = Button("fiveHundredChip", 240, 175, 278, 139);
    Button allIn = Button("all in", 56, 83, 97, 68);
    Button deal = Button("deal", 242, 106, 306, 78);
    // create back button
    Button playMenuBack = Button("back", 10, 230, 75, 210);

    Button buttonArr[9] = {playMenuBack, oneChip, fiveChip, twentyFiveChip, fiftyChip, hundredChip, fiveHundredChip, deal, allIn};
    while(!dealt){
        Cord(cord);
        string buttonPressed = checkButtonPressed(buttonArr, 9, cord);

        if (buttonPressed.compare(oneChip.getName()) == 0) {
            if(bank >= 1){
                bank -= 1;
                betAmt += 1;
                cout << "Button pressed: oneChip" << endl;
            }
            else{
                illegalAmount = 1;  // Not enough money to place a 1-chip bet
            }
        } else if (buttonPressed.compare("fiveChip") == 0) {
            if (bank >= 5) {
                bank -= 5;
                betAmt += 5;
                cout << "Button pressed: fiveChip" << endl;
            } else {
                illegalAmount = 5;  // Not enough money to place a 5-chip bet
            }
        } else if (buttonPressed.compare("twentyFiveChip") == 0) {
            if (bank >= 25) {
                bank -= 25;
                betAmt += 25;
                cout << "Button pressed: twentyFiveChip" << endl;
            } else {
                illegalAmount = 25;  // Not enough money to place a 25-chip bet
            }
        } else if (buttonPressed.compare("fiftyChip") == 0) {
            if (bank >= 50) {
                bank -= 50;
                betAmt += 50;
                cout << "Button pressed: fiftyChip" << endl;
            } else {
                illegalAmount = 50;  // Not enough money to place a 50-chip bet
            }
        } else if (buttonPressed.compare("hundredChip") == 0) {
            if (bank >= 100) {
                bank -= 100;
                betAmt += 100;
                cout << "Button pressed: hundredChip" << endl;
            } else {
                illegalAmount = 100;  // Not enough money to place a 100-chip bet
            }
        } else if (buttonPressed.compare("fiveHundredChip") == 0) {
            if (bank >= 500) {
                bank -= 500;
                betAmt += 500;
                cout << "Button pressed: fiveHundredChip" << endl;
            } else {
                illegalAmount = 500;  // Not enough money to place a 500-chip bet
            }
        } else if (buttonPressed.compare("deal") == 0) {
            cout << "Button pressed: deal" << endl;
            dealt = true;
        } else if (buttonPressed.compare("all in") == 0) {
            cout << "Button pressed: all in" << endl;
            dealt = true;
            betAmt = bank + betAmt;
            bank = 0;
        } else if (buttonPressed.compare("back") == 0) {
            ofstream statsFileOut("statistics.txt");  // Open file to save updates
            bank += betAmt;  // Update the bank balance
            betAmt = 0;  // Reset bet amount

            // Save the updated values back to the file
            cout << "Bank count is read in as:" << bank << endl;
            cout << "Game Count Is read in as:" << numGames << endl;
            statsFileOut << bank << endl;
            statsFileOut << numGames << endl;
            statsFileOut.close();  // close file

            PlayMenu();  // Go back to the play menu
        } else {
            cout << "Unknown button pressed!" << endl;
            cout << "Cord Pressed was, (" << cord[0] << "," << cord[1] << ")" << endl;
        }

        if(illegalAmount > 0){
            Warning.Draw(10,200);
        }
        illegalAmount = 0;

        // changes color to background color(a shade of green)
        LCD.SetFontColor(0x388E3C);
        // erases the previous values for bank and bet amt on screen
        //clears Bet
        LCD.FillRectangle(150, 100, 80, 20);
        //clears bank
        LCD.FillRectangle(92, 45, 100, 20);

        LCD.SetFontColor(WHITE);
        LCD.WriteAt(to_string(betAmt), 150, 100);
        LCD.WriteAt(to_string(bank), 92, 45);
    }
    /////////////////////////////////////////////////////////////////////////////////////Begin Dealing Cards

    int restart =1;
    string CardName, PlayerFirstCard, PlayerSecondCard, DealerFirstCard, DealerHiddenCard;
    int PlayerCard1Value, PlayerCard2Value, DealerCard1Value, DealerCard2Value, playerTotal, dealerTotal;
    int playerHand[10];
    int dealerHand[10];
    int playerCardCount = 0;
    int dealerCardCount = 0;
    LCD.Clear();
    FEHImage BlackjackGame; //Table Image

    
    
    BlackjackGame.Open("SDP_Images/Blackjack_Table.png");
    BlackjackGame.Draw(0,0);
    Sleep(1.5);

    //Betting and finalize betting

    //clear buttons from the betting

    // add the table screen again and then add two face down cards on the dealers area

    FEHImage CardBacks;  
    CardBacks.Open("SDP_Images/Back_of_Card.png");

    CardBacks.Draw(110,170); //Player card 1
        Sleep(0.8);
    CardBacks.Draw(140,170); //Player card 2
        Sleep(0.8);
    //After the two player cards, add the dealer cards.
    CardBacks.Draw(130,40); //Dealer card 1
        Sleep(0.8);
    CardBacks.Draw(160,40); //Dealer card 2, this will stay face down
        Sleep(0.8);


    //create randomized value for the first player card
    //create the image for the first player card
    FEHImage PlayerCardOneImg;
    //The name of the first card
    PlayerFirstCard = GenerateCardName();
    string CardLoco = ("SDP_Images/" + PlayerFirstCard + ".png");
    PlayerCardOneImg.Open(CardLoco.data());
    PlayerCardOneImg.Draw(110,170);
    Sleep(1.0);
    PlayerCard1Value = GenerateCardValue(PlayerFirstCard); //Store the cards values into variables
    playerHand[playerCardCount++] = PlayerCard1Value;  // Store player card value
    cout << "First Player Card " << PlayerFirstCard << " with a value of " << PlayerCard1Value << endl;


    //create randomized value for the second player card
    //create the image for the second player card
    FEHImage PlayerCardTwoImg;
    //ensure the first and second card are not the same
    PlayerSecondCard = GenerateCardName();
    while(PlayerSecondCard.compare(PlayerFirstCard) == 0){
        PlayerSecondCard = GenerateCardName();
    }
    //The name of the second card
    PlayerSecondCard = GenerateCardName();
    CardLoco = ("SDP_Images/" + PlayerSecondCard + ".png");
    PlayerCardTwoImg.Open(CardLoco.data());
    PlayerCardTwoImg.Draw(140,170);
    Sleep(1.0);
    PlayerCard2Value = GenerateCardValue(PlayerSecondCard); //Store the cards values into variables
    playerHand[playerCardCount++] = PlayerCard2Value;  // Store player card value
    cout << "Second Player Card " << PlayerSecondCard << " with a value of " << PlayerCard2Value << endl;

    FEHImage DealerCardOneImg;
    DealerFirstCard = GenerateCardName();//Dealer card 1
    CardLoco = "SDP_Images/" + DealerFirstCard + ".png";
    DealerCardOneImg.Open(CardLoco.data());
    DealerCardOneImg.Draw(130,40);
    DealerCard1Value = GenerateCardValue(DealerFirstCard);
    dealerHand[dealerCardCount++] = DealerCard1Value;  // Store dealer card value
    cout << "First Dealer Card " << DealerFirstCard << " with a value of " << DealerCard1Value << endl;

    //create the dealer hidden card
    DealerHiddenCard = GenerateCardName();
    while(DealerHiddenCard.compare(DealerFirstCard) == 0){
        DealerHiddenCard = GenerateCardName();
    }
    //if difficulty is GA, dealer gets 21
    if(diff.compare("GA") == 0){
        cout << "GA Diff: " << DealerCard1Value << endl;
        DealerHiddenCard = SetDealerHiddenCard(DealerCard1Value);
    }
    DealerCard2Value = GenerateCardValue(DealerHiddenCard);
    dealerHand[dealerCardCount++] = DealerCard2Value;  // Store dealer card value
    cout << "Second Dealer Card " << DealerHiddenCard << " with a value of " << DealerCard2Value << endl;

    playerTotal = calculateTotal(playerHand, playerCardCount);
    dealerTotal = calculateTotal(dealerHand, dealerCardCount);
    
    Sleep(1.0);

    LCD.Clear();

    FEHImage QuestionScreen; //ask the player to stay or get another card
    QuestionScreen.Open("SDP_Images/BlackJack_Question.png");
    QuestionScreen.Draw(0,0);
// Question Section //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //redraw all cards

    CardBacks.Open("SDP_Images/Back_of_Card.png");
    CardBacks.Draw(160,40);

    FEHImage DealerCardTwoImg;

    

    CardLoco = ("SDP_Images/" + PlayerFirstCard + ".png");
    PlayerCardOneImg.Open(CardLoco.data());
    PlayerCardOneImg.Draw(110,170);


    CardLoco = ("SDP_Images/" + PlayerSecondCard + ".png");
    PlayerCardTwoImg.Open(CardLoco.data());
    PlayerCardTwoImg.Draw(140,170);


    CardLoco = "SDP_Images/" + DealerFirstCard + ".png";
    DealerCardOneImg.Open(CardLoco.data());
    DealerCardOneImg.Draw(130,40);

    //Add buttons to the options on the screen

    Button stay = Button("Stay",22,200,55,163);

    Button oneMore = Button("OneMore",271,200,303,168);

    Button buttonarr1[2] = {stay , oneMore};
    int cord1[2];

    FEHImage dealerExtraImg;
    FEHImage playerExtraImg;

    string dealerExtraCard;
    string playerExtraCard;

    int dealerExtraValue;
    int playerExtraValue;

    bool breakOut = false;

    cout << "Player Total:" << playerTotal << endl;
    cout << "Dealer Total:" << dealerTotal << endl;
    string buttonPressed;
    int x_cordPlayer = 140;
    int x_cordDealer = 160;
    string bet = "Bet: " + betAmt;
    //LCD.WriteAt(bet, 100, 135);
    if(playerTotal == 21){
        LCD.WriteAt("Player Wins",140,135);
        result = 2;
        breakOut = true;
        Sleep(4.0);
        CardLoco = "SDP_Images/" + DealerHiddenCard + ".png";
        DealerCardTwoImg.Open(CardLoco.data());
        DealerCardTwoImg.Draw(160,40);
        Sleep(0.5);
    }


    while(!breakOut){

        
        Cord(cord1);
        buttonPressed = checkButtonPressed(buttonarr1, 2 , cord1);
        //keep asking for button clicks for until one of the buttons is hit
        while(buttonPressed.compare("none") == 0){
            Cord(cord1);
            buttonPressed = checkButtonPressed(buttonarr1, 2 , cord1);
        }

        if(buttonPressed.compare("OneMore") == 0){
            //the x cordinate must move over by 30 pixels
            x_cordPlayer +=30;
            playerExtraCard = GenerateCardName();
            CardLoco = ("SDP_Images/" + playerExtraCard + ".png");
            playerExtraImg.Open(CardLoco.data());
            playerExtraImg.Draw(x_cordPlayer,170);
            Sleep(0.5);
            playerHand[dealerCardCount++] = GenerateCardValue(playerExtraCard);
            playerTotal = calculateTotal(playerHand, playerCardCount);
            if(playerTotal > 21){
                CardLoco = "SDP_Images/" + DealerHiddenCard + ".png";
                DealerCardTwoImg.Open(CardLoco.data());
                DealerCardTwoImg.Draw(160,40);
                Sleep(0.5);
                LCD.WriteAt("Dealer Wins",140,135);
                result = 0;
                breakOut = true;
                Sleep(4.0);
            }
        }
        result = 0;
        if(buttonPressed.compare("Stay") == 0){
            CardLoco = "SDP_Images/" + DealerHiddenCard + ".png";
            DealerCardTwoImg.Open(CardLoco.data());
            DealerCardTwoImg.Draw(160,40);
            Sleep(0.5);
            if(dealerTotal == 21 || dealerTotal > playerTotal){
                Sleep(0.5);
                LCD.WriteAt("Dealer Wins",140,135);
                result = 0;
                breakOut = true;
                Sleep(4.0);
            }
            else if(dealerTotal >= 16){
                //once dealer reaches 17 or above, stop drawing
                if(dealerTotal < playerTotal){
                    LCD.WriteAt("Player Wins",140,135);
                    result = 2;
                    breakOut = true;
                    Sleep(4.0);
                }
                else{
                    LCD.WriteAt("Tie",140,135);
                    result = 1;
                    breakOut = true;
                    Sleep(4.0);
                }
            }
            while(!breakOut){
                x_cordDealer +=30;
                dealerExtraCard = GenerateCardName();
                CardLoco = ("SDP_Images/" + dealerExtraCard + ".png");
                dealerExtraImg.Open(CardLoco.data());
                dealerExtraImg.Draw(x_cordDealer,40);
                Sleep(0.5);
                dealerHand[dealerCardCount++] = GenerateCardValue(dealerExtraCard);
                dealerTotal = calculateTotal(dealerHand, dealerCardCount);
                if(dealerTotal >= 16){
                    //once dealer reaches 17 or above, stop drawing
                    if(dealerTotal > playerTotal){
                        LCD.WriteAt("Dealer Wins",140,135);
                        result = 0;
                        breakOut = true;
                        Sleep(4.0);
                    }
                    else if(dealerTotal < playerTotal){
                        LCD.WriteAt("Player Wins",140,135);
                        result = 2;
                        breakOut = true;
                        Sleep(4.0);
                    }
                    else{
                        LCD.WriteAt("Tie",140,135);
                        result = 1;
                        breakOut = true;
                        Sleep(4.0);
                    }
                }
                else if(dealerTotal > 21){
                    LCD.WriteAt("Dealer Wins",140,135);
                    result = 0;
                    breakOut = true;
                    Sleep(4.0);
                }
            }
        }

        if(playerTotal == 21){
            LCD.WriteAt("Player Wins",140,135);
            result = 2;
            breakOut = true;
            Sleep(4.0);
        } 

        cout << "Player Total:" << playerTotal << endl;
        cout << "Dealer Total:" << dealerTotal << endl;
    }
    Sleep(4.0);
    //if result = 1, tie, 2 means player won, 0 means player lost 
    numGames++;
    bank += (betAmt*result);
    //double increment if player won
    cout << "Bank count at end in as:" << bank << endl;
    cout << "Game Count at end in as:" << numGames << endl;
    BlackJackGame(bank, numGames, diff);

}