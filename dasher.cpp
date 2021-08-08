
#include "raylib.h"

int main()
{
    int screenWidth{800};
    int screenHeight{400};
 InitWindow(screenWidth, screenHeight, "Miguel's little window");
 Texture2D player = LoadTexture("textures/dude.png");
    Rectangle rect;
    rect.height = player.height;
    rect.width = player.width / 6;
    rect.x = 0;
    rect.y = 0;
    Vector2 rectPosition;
    rectPosition.x = screenWidth/2 - rect.width / 2;
    rectPosition.y = screenHeight - rect.height;

bool isInAir {};
   
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        //game logic begins here

        //if ()
        if (IsKeyPressed(KEY_SPACE))// !isInAir)
        {
               // isInAir = true;
            rectPosition.y += -20; 
        }

           if (IsKeyDown(KEY_A))// !isInAir)
        {
               if(rect.x == player.width)
               rect.x = 0;
                rect.x += player.width / 6;
            rectPosition.x -= 4; 
        }

          if (IsKeyDown(KEY_D))// !isInAir)
        {
               // isInAir = true;
               if(rect.x == player.width)
               rect.x = 0;
                  rect.x += player.width / 6;
            rectPosition.x += 4; 
        }
       DrawTextureRec(player, rect, rectPosition, WHITE);
        ClearBackground(WHITE);

        EndDrawing();

    } //end game loop
UnloadTexture(player);
    CloseWindow();

} //end main