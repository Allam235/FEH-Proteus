#include "FEHLCD.h"
#include "FEHUtility.h"
#include <FEHUtility.h>
#include <FEHImages.h>
#include <iostream>
#include <string>

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
void CordFlash(int*, char[], char[]);
void InfiniteCord();

void StartMenu();
void Credits();
void PlayMenu();
void PlayMenuGA();
void PlayMenuNew();
void StatisticsPage();
void TutorialPage();

void BlackjackGame();

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
                BlackjackGame();
            }
        } else if(buttonPressed.compare("Poker") == 0){
            cout << "Poker" << endl;
            if(diff.compare("") == 0){
                chooseDiff.Draw(90, 210);
            } else{
                cout << "Poker" << endl;
                BlackjackGame();
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

void BlackjackGame(){
    Credits();
}