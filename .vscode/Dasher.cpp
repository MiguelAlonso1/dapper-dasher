#include <iostream>
#include <raylib.h>

int main ()
{
 InitWindow(400,200, "Miguel's little window");

 std::cout<<"Hello Baby!";

SetTargetFPS (60);

while (!WindowShouldClose() )
{
BeginDrawing();
ClearBackground(WHITE);

EndDrawing();

}//end game loop

//CloseWindow();


}//end main