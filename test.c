#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Initialization
    const int screenWidth = 1000;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Buttons");
    Color backgroundColor = ColorFromNormalized((Vector4){1.0f, 0.96f, 0.88f, 1.0f});

    // Define the buttons
    Rectangle button1 = {20, 50, 120, 40};
    Rectangle button2 = {160, 50, 120, 40};
    Rectangle button3 = {300, 50, 120, 40};
    Rectangle button4 = {440, 50, 120, 40};
    Rectangle button5 = {580, 50, 120, 40};
    Color buttonColor = ColorFromNormalized((Vector4){1.0f, 0.41f, 0.41f, 1.0f});

    // Additional variables for the input box and array
    bool createMode = false;
    bool fillMode = false;
    bool deleteMode = false;
    bool sortMode = false;
    bool addMode = false;
    int fillIndex = 0;
    int deleteValue = -1;
    int addValue = -1;
    int step=0;
    char inputValue[64] = ""; // Buffer for user input
    Rectangle inputBox = {20, 120, 150, 30};

    int *myArray = NULL;
    int arraySize = 0;

    SetTargetFPS(60);

    // Main program loop
    while (!WindowShouldClose()) {
        // Handle input
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Check if the "Creer" button is clicked
            if (CheckCollisionPointRec(GetMousePosition(), button1)) {
                createMode = true;
                fillMode = false;
                deleteMode = false;
                sortMode = false;
                addMode = false;
                strcpy(inputValue, ""); // Clear the input buffer
            }

            // Check if the "Remplir" button is clicked
            if (CheckCollisionPointRec(GetMousePosition(), button2)) {
                fillMode = true;
                createMode = false;
                deleteMode = false;
                sortMode = false;
                addMode = false;
                fillIndex = 0;
                strcpy(inputValue, ""); // Clear the input buffer
            }

            // Check if the "Supprimer" button is clicked
            if (CheckCollisionPointRec(GetMousePosition(), button3)) {
                deleteMode = true;
                createMode = false;
                fillMode = false;
                sortMode = false;
                addMode = false;
                strcpy(inputValue, ""); // Clear the input buffer
            }

            // Check if the "Ajouter" button is clicked
            if (CheckCollisionPointRec(GetMousePosition(), button4)) {
                addMode = true;
                createMode = false;
                fillMode = false;
                deleteMode = false;
                sortMode = false;
                strcpy(inputValue, ""); // Clear the input buffer
            }

            // Check if the "Trier" button is clicked
            if (CheckCollisionPointRec(GetMousePosition(), button5)) {
                sortMode = true;
                step=0;
                createMode = false;
                fillMode = false;
                deleteMode = false;
                addMode = false;
            }
        }

        // Handle user input when creating the array
        if (createMode) {
            int key = GetKeyPressed();
            if (key > 0) {
                // Handle keys
                if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                    int len = strlen(inputValue);
                    if (len < 63) {
                        inputValue[len] = (char)key;
                        inputValue[len + 1] = '\0';
                    }
                } else if (key == KEY_BACKSPACE) {
                    int len = strlen(inputValue);
                    if (len > 0) {
                        inputValue[len - 1] = '\0';
                    }
                } else if (key == KEY_ENTER) {
                    // Create the array with the specified value
                    arraySize = atoi(inputValue);

                    if (arraySize > 0) {
                        myArray = (int *)malloc(arraySize * sizeof(int));
                        for (int i = 0; i < arraySize; i++) {
                            myArray[i] = 0;
                        }
                    }

                    // Disable creation mode
                    createMode = false;
                }
            }
        }

        // Handle user input when filling the array
        if (fillMode && fillIndex < arraySize) {
            int key = GetKeyPressed();
            if (key > 0) {
                // Handle keys
                if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                    int len = strlen(inputValue);
                    if (len < 63) {
                        inputValue[len] = (char)key;
                        inputValue[len + 1] = '\0';
                    }
                } else if (key == KEY_BACKSPACE) {
                    int len = strlen(inputValue);
                    if (len > 0) {
                        inputValue[len - 1] = '\0';
                    }
                } else if (key == KEY_ENTER) {
                    // Fill the current index of the array with the specified value
                    myArray[fillIndex] = atoi(inputValue);
                    fillIndex++;

                    // Clear the input buffer for the next value
                    strcpy(inputValue, "");
                }
            }
        }

        // Handle user input when deleting from the array
        if (deleteMode) {
            int key = GetKeyPressed();
            if (key > 0) {
                // Handle keys
                if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                    int len = strlen(inputValue);
                    if (len < 63) {
                        inputValue[len] = (char)key;
                        inputValue[len + 1] = '\0';
                    }
                } else if (key == KEY_BACKSPACE) {
                    int len = strlen(inputValue);
                    if (len > 0) {
                        inputValue[len - 1] = '\0';
                    }
                } else if (key == KEY_ENTER) {
                    // Delete all occurrences of the specified value from the array
                    deleteValue = atoi(inputValue);
                    bool found = false;

                    for (int i = 0; i < arraySize; i++) {
                        if (myArray[i] == deleteValue) {
                            found = true;
                            for (int j = i; j < arraySize - 1; j++) {
                                myArray[j] = myArray[j + 1];
                            }
                            arraySize--;
                            i--; // Decrement i to check the same index again
                        }
                    }

                    if (!found) {
                        DrawText("This value does not exist in the array", 200, 300, 20, BLACK);
                    }

                    // Disable deletion mode
                    deleteMode = false;
                }
            }
        }

        // Handle user input when adding to the array
        if (addMode) {
            int key = GetKeyPressed();
            if (key > 0) {
                // Handle keys
                if ((key >= KEY_ZERO) && (key <= KEY_NINE)) {
                    int len = strlen(inputValue);
                    if (len < 63) {
                        inputValue[len] = (char)key;
                        inputValue[len + 1] = '\0';
                    }
                } else if (key == KEY_BACKSPACE) {
                    int len = strlen(inputValue);
                    if (len > 0) {
                        inputValue[len - 1] = '\0';
                    }
                } else if (key == KEY_ENTER) {
                    // Add the specified value to the end of the array
                    addValue = atoi(inputValue);
                    arraySize++;
                    myArray = (int *)realloc(myArray, arraySize * sizeof(int));
                    myArray[arraySize - 1] = addValue;

                    // Disable addition mode
                    addMode = false;
                }
            }
        }
       // Handle user input when sorting the array
       if (sortMode) {

          if (step < arraySize - 1) {

        if (myArray[step] > myArray[step + 1]) {

            // Swap myArray[step] and myArray[step + 1]

            int temp = myArray[step];

            myArray[step] = myArray[step + 1];

            myArray[step + 1] = temp;

        }

        step++;

    } else {

        // Sorting is complete, reset step counter

        step = 0;
        sortMode=false;

    }

}

       

        // Draw
        BeginDrawing();

        ClearBackground(backgroundColor);

        // Draw the buttons
        DrawRectangleRec(button1, buttonColor);
        DrawRectangleRec(button2, buttonColor);
        DrawRectangleRec(button3, buttonColor);
        DrawRectangleRec(button4, buttonColor);
        DrawRectangleRec(button5, buttonColor);

        // Draw the button text
        DrawText("Creer", button1.x + button1.width / 2 - MeasureText("Creer", 20) / 2, button1.y + 10, 20, BLACK);
        DrawText("Remplir", button2.x + button2.width / 2 - MeasureText("Remplir", 20) / 2, button2.y + 10, 20, BLACK);
        DrawText("Supprimer", button3.x + button3.width / 2 - MeasureText("Supprimer", 20) / 2, button3.y + 10, 20, BLACK);
        DrawText("Ajouter", button4.x + button4.width / 2 - MeasureText("Ajouter", 20) / 2, button4.y + 10, 20, BLACK);
        DrawText("Trier", button5.x + button5.width / 2 - MeasureText("Trier", 20) / 2, button5.y + 10, 20, BLACK);

        // Draw the input box during creation, fill, or delete mode
        if (createMode || fillMode || deleteMode || addMode) {
            DrawRectangleRec(inputBox, RAYWHITE);
            DrawRectangleLinesEx(inputBox, 2, BLACK);
            DrawText(inputValue, inputBox.x + 5, inputBox.y + 8, 20, BLACK);
        }

        // Draw the array
        for (int i = 0; i < arraySize; i++) {
            DrawRectangle(200 + i * 30, 200, 30, 30, BLUE);
            DrawText(TextFormat("%d", myArray[i]), 205 + i * 30, 205, 20, BLACK);
        }

        EndDrawing();
    }

    // Free the allocated memory for the array
    free(myArray);

    // De-Initialization
    CloseWindow();

    return 0;
}
