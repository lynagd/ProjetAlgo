#include "raylib.h"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Buttons");

    // Define the buttons
    Rectangle button1 = { 50, 200, 200, 50 };
    Rectangle button2 = { 50, 300, 200, 50 };
    Rectangle button3 = { 550, 200, 200, 50 };
    Rectangle button4 = { 550, 300, 200, 50 };

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Draw the comment
            DrawText("Voulez vous creer un tableau?", screenWidth/2 - MeasureText("Voulez vous creer un tableau?", 20)/2, 50, 20, BLACK);

            // Draw the buttons
            DrawRectangleRec(button1, GRAY);
            DrawRectangleRec(button2, GRAY);
            DrawRectangleRec(button3, GRAY);
            DrawRectangleRec(button4, GRAY);

            // Draw the button text
            DrawText("Creer", button1.x + button1.width/2 - MeasureText("Creer", 20)/2, button1.y + 15, 20, BLACK);
            DrawText("Remplir", button2.x + button2.width/2 - MeasureText("Remplir", 20)/2, button2.y + 15, 20, BLACK);
            DrawText("Supprimer", button3.x + button3.width/2 - MeasureText("Supprimer", 20)/2, button3.y + 15, 20, BLACK);
            DrawText("Ajouter", button4.x + button4.width/2 - MeasureText("Ajouter", 20)/2, button4.y + 15, 20, BLACK);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
