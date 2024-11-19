#include "FEHLCD.h"
#include "FEHUtility.h"
#include <FEHImages.h>

void Menu();
void Cord();

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
    Cord();
    

    while (1) {
        LCD.Update();
        // Never end
    }
    return 0;
}

void Cord(){
    float x, y;
    float xT, yT;

    while(true){
        while(!LCD.Touch(&x,&y)) {};
        /* Wait until the touch releases */
        while(LCD.Touch(&xT,&yT)) {};
 
        /* Print proper x and y coordinates to screen */
        LCD.WriteLine("The screen was under pressure");
        LCD.Write("At x coordinate: ");
        LCD.WriteLine(x);
        LCD.Write("At y coordinate: ");
        LCD.WriteLine(y);
        
    }

}


void Menu() {
    //screen size 320x240
    LCD.WriteAt("Hello, welcome to F2HCasino", 0, 12);

    FEHImage addictOff;
    // Open the image
    addictOff.Open("difficulty_img/Addict_W.png");
    addictOff.Draw(0, 0);





}

