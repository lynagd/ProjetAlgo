# lynacode
#include <raylib.h>

int main(void) {
    // Initialisation de la fenêtre
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Raylib Buttons and Text");

    // Définition des positions et dimensions des boutons
    Rectangle buttonRect1 = { 50, 50, 200, 50 };
    Rectangle buttonRect2 = { 50, 150, 200, 50 };

    // Déclaration d'une variable pour stocker le texte du bouton
    const char* buttonText1 = "Button 1";
    const char* buttonText2 = "Button 2";

    // Variable pour stocker le texte à afficher
    const char* displayText = "Hello, Raylib!";

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Affichage des boutons
        DrawRectangleRec(buttonRect1, GRAY);
        DrawRectangleRec(buttonRect2, GRAY);

        // Affichage du texte des boutons
        DrawText(Créer, buttonRect1.x + 10, buttonRect1.y + 10, 20, BLACK);
        DrawText(Remplir, buttonRect2.x + 10, buttonRect2.y + 10, 20, BLACK);

        // Affichage du texte central
        DrawText(Voulez vous créer un tableau?, screenWidth / 2 - MeasureText(displayText, 20) / 2, screenHeight / 2 - 10, 20, BLACK);

        // Vérification si la souris est sur un bouton
        if (CheckCollisionPointRec(GetMousePosition(), buttonRect1) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            displayText = "Button 1 pressed!";
        } else if (CheckCollisionPointRec(GetMousePosition(), buttonRect2) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            displayText = "Button 2 pressed!";
        }

        EndDrawing();
    }

    // Fermeture de la fenêtre
    CloseWindow();

    return 0;
}
