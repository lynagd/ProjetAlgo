# lynacode
#include "raylib.h"

int main(void)
{
    // Initialisation
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Buttons");
    Color backgroundColor = ColorFromNormalized((Vector4){ 1.0f, 0.96f, 0.88f, 1.0f });
    // Define the buttons
    Rectangle button1 = { 50, 200, 200, 50 };
    Rectangle button2 = { 50, 300, 200, 50 };
    Rectangle button3 = { 550, 200, 200, 50 };
    Rectangle button4 = { 550, 300, 200, 50 };
    Color buttonColor = ColorFromNormalized((Vector4){ 1.0f, 0.41f, 0.41f, 1.0f }); 
    SetTargetFPS(60);

    // Main project loop
    while (!WindowShouldClose())
    {
        // Draw
        BeginDrawing();

            ClearBackground(backgroundColor);

            // Draw the comment
            DrawText("Voulez vous creer un tableau?", screenWidth/2 - MeasureText("Voulez vous creer un tableau?", 20)/2, 50, 20, RAYWHITE);

            // Draw the buttons
            DrawRectangleRec(button1, buttonColor);
            DrawRectangleRec(button2, buttonColor);
            DrawRectangleRec(button3, buttonColor);
            DrawRectangleRec(button4, buttonColor);

            // Draw the button text
            DrawText("Creer", button1.x + button1.width/2 - MeasureText("Creer", 20)/2, button1.y + 15, 20, RAYWHITE);
            DrawText("Remplir", button2.x + button2.width/2 - MeasureText("Remplir", 20)/2, button2.y + 15, 20, RAYWHITE);
            DrawText("Supprimer", button3.x + button3.width/2 - MeasureText("Supprimer", 20)/2, button3.y + 15, 20, RAYWHITE);
            DrawText("Ajouter", button4.x + button4.width/2 - MeasureText("Ajouter", 20)/2, button4.y + 15, 20, RAYWHITE);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}

      
      
