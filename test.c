#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

// Function to display a text input box
bool InputBox(const char *title, const char *message, char *inputText, int maxLength, bool submitOnEnter) {
    Rectangle boxRect = { GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 80, 300, 160 };
    Rectangle textRect = { boxRect.x + 40, boxRect.y + 80, boxRect.width - 80, 40 };
    Rectangle buttonRect = { boxRect.x + boxRect.width / 2 - 60, boxRect.y + boxRect.height - 50, 120, 40 };

    bool windowClosed = false;
    bool inputCompleted = false;
    int key = 0;
    int count = 0;

    while (!windowClosed) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleRec(boxRect, GRAY);
        DrawText(title, boxRect.x + 10, boxRect.y + 10, 20, WHITE);

        DrawText(message, textRect.x, textRect.y - 50, 20, BLACK);

        DrawRectangleRec(textRect, WHITE);
        DrawRectangleLines(textRect.x, textRect.y, textRect.width, textRect.height, BLACK);

        DrawText(inputText, textRect.x + 10, textRect.y + 10, 20, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), buttonRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            inputCompleted = true;
        }

        DrawRectangleRec(buttonRect, MAROON);
        DrawText("Valider", buttonRect.x + 10, buttonRect.y + 10, 20, WHITE);

        EndDrawing();

        // Handle keyboard input
        key = GetKeyPressed();
        if (key != 0) {
            if (count < maxLength) {
                inputText[count] = (char)key;
                count++;
            }
        }

        // Handle backspace
        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (count > 0) {
                count--;
                inputText[count] = '\0';
            }
        }

        // Check if the user pressed Enter and submitOnEnter is true
        if (IsKeyPressed(KEY_ENTER) && submitOnEnter) {
            inputCompleted = true;
        }

        // Check if the user clicked outside the input box to close the window
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
            !CheckCollisionPointRec(GetMousePosition(), boxRect)) {
            windowClosed = true;
        }
    }

    return inputCompleted;
}

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Buttons");
    Color backgroundColor = ColorFromNormalized((Vector4){1.0f, 0.96f, 0.88f, 1.0f});

    // Define the buttons
    Rectangle button1 = {50, 200, 200, 50};
    Rectangle button2 = {50, 300, 200, 50};
    Rectangle button3 = {550, 200, 200, 50};
    Rectangle button4 = {550, 300, 200, 50};
    Color buttonColor = ColorFromNormalized((Vector4){1.0f, 0.41f, 0.41f, 1.0f});
    int arraySize = 0;
    int *dynamicArray = NULL;
    SetTargetFPS(60);

    // Main project loop
    while (!WindowShouldClose()) {
        // Draw
        BeginDrawing();

        ClearBackground(backgroundColor);

        // Draw the comment
        DrawText("Voulez vous creer un tableau?", screenWidth / 2 - MeasureText("Voulez vous creer un tableau?", 20) / 2, 50, 20, BLACK);

        // Draw the buttons
        DrawRectangleRec(button1, buttonColor);
        DrawRectangleRec(button2, buttonColor);
        DrawRectangleRec(button3, buttonColor);
        DrawRectangleRec(button4, buttonColor);

        // Draw the button text
        DrawText("Creer", button1.x + button1.width / 2 - MeasureText("Creer", 20) / 2, button1.y + 15, 20, BLACK);
        DrawText("Remplir", button2.x + button2.width / 2 - MeasureText("Remplir", 20) / 2, button2.y + 15, 20, BLACK);
        DrawText("Supprimer", button3.x + button3.width / 2 - MeasureText("Supprimer", 20) / 2, button3.y + 15, 20, BLACK);
        DrawText("Ajouter", button4.x + button4.width / 2 - MeasureText("Ajouter", 20) / 2, button4.y + 15, 20, BLACK);

        // Check if the mouse is on the "Creer" button
        if (CheckCollisionPointRec(GetMousePosition(), button1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Show an input box to get the size of the array
            char inputText[32] = "";
            bool inputCompleted = InputBox("Entrez la taille du tableau (1 à 9):", "Taille:", inputText, 32, false);

            if (inputCompleted) {
                arraySize = atoi(inputText);

                // Ensure the size is in the range (1 to 9)
                if (arraySize < 1 || arraySize > 9) {
                    arraySize = 0;
                    DrawText("Erreur! Veuillez entrer une valeur entre 1 et 9.", 100, 150, 20, RED);
                } else {
                    // Dynamically allocate an array of the specified size
                    dynamicArray = (int *)malloc(arraySize * sizeof(int));

                    // Initialize the array with default values
                    for (int i = 0; i < arraySize; i++) {
                        dynamicArray[i] = 0;
                    }
                }
            }
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
