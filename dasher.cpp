
#include "raylib.h"

int main()
{
    constexpr int screenWidth{800};
    constexpr int screenHeight{400};
    constexpr int gravity {4};
    int velocity {10};
    int speed {};
    int jumpHeight {-200};//negative cuz jump goes in the negative Y axis direction
    bool isInAir {};//false by default
    Music music;


    InitWindow(screenWidth, screenHeight, "Miguel's little window");
    InitAudioDevice();              // Initialize audio device
    Texture2D playerTexture = LoadTexture("textures/dude.png");
    music = LoadMusicStream("intro.wav");
    PlayMusicStream(music);     
    Rectangle rect//variable declaration
    {
        0,//x coordinate
        0,//y coordinate
        playerTexture.width / 6,//width
        playerTexture.height//height
    };

    Vector2 rectPosition//position of character
    {
        screenWidth/2 - rect.width / 2,//x coordinate
        screenHeight - rect.height//y coordinate
    };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        //game logic begins here
  UpdateMusicStream(music);
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            isInAir = true;
            rectPosition.y += jumpHeight;
        }

        if (IsKeyDown(KEY_A))//move character left
        {
          
            if (rect.x == playerTexture.width) //if rectangle in last sprite
                 rect.x = 0;
            else 
                if (!isInAir)//don't update sprite while player is jumping
                    rect.x += playerTexture.width / 6;

             rectPosition.x -= velocity;//move left
             speed = 10;
        }

        if (IsKeyDown(KEY_D))
        {
            
             if (rect.x == playerTexture.width) //if rectangle in last sprite
                 rect.x = 0;
            else 
                if (!isInAir)//don't update sprite while player is jumping
                    rect.x += playerTexture.width / 6;

             rectPosition.x += velocity;//move right
             speed = 10;
        }
        //ground check
        if (rectPosition.y < screenHeight - rect.height)
        {
            rectPosition.y += gravity;
        }
        else{isInAir = false;};

       DrawTextureRec(playerTexture, rect, rectPosition, WHITE);

       if (speed == 0)
            rect.x = 0;
      else
            speed--;
       ClearBackground(WHITE);

       EndDrawing();

    } //end game loop
     UnloadMusicStream(music);   // Descargo la musica de RAM
    UnloadTexture(playerTexture);
    CloseWindow();

} //end main