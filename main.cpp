#include "FEHLCD.h"
#include "FEHUtility.h"
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

void StartMenu();
int* Cord();
void Credits();
void InfiniteCord();
void PlayMenu();
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

string checkButtonPressed(Button buttonArr[],int length, int* cord){
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

void Credits(){

    LCD.Clear();

    FEHImage creditsPage;
    int cord[2];
    // Open the image
    creditsPage.Open("Credits.png");
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
    playMenu.Open("PlayMenu.png");
    playMenu.Draw(0, 0);

    //play button (20,180) & (110,160)
    //create back button
    Button playMenuBack = Button("back", 10, 230, 75, 210);

    Button buttonArr[1] = {playMenuBack};
    while(true){
        Cord(cord);
        
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
    startMenu.Open("Start Menu.png");
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
        }
        else if(buttonPressed.compare("play") == 0){
            cout << "Play Menu" << endl;
            PlayMenu();
        }
        //cout << "Cord:" << "(" << *(cord) << "," << *(cord+1) << ")" << endl;
        //cout << "Result:" << startMenuPlay.inButton(cord) << endl;
    }
    







}

