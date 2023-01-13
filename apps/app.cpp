#include <fmt/format.h>
#include <raylib.h>
#include <filesystem>
#include <chrono>

#include "php_scripting/vm.hpp"
#include "php_scripting/php_module.hpp"


#define MAX_COLUMNS 20

using namespace std;
using namespace std::chrono;

PHP_FUNCTION (draw_text)
{
    char *message;
    size_t message_len;

    long x, y, size;
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "slll", &message, &message_len, &x, &y, &size) == FAILURE) {
        return;
    }


    DrawText(message, (int)x, (int)y, (int)size, RED);

    RETURN_NULL();
}

PHP_FUNCTION (print_coucou)
{
    printf("coucou !\n");
    RETURN_NULL();
}


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");

    // Define the camera to look into our 3d world (position, target, up vector)
    Camera camera = {0};
    camera.position = (Vector3) {4.0f, 2.0f, 4.0f};
    camera.target = (Vector3) {0.0f, 1.8f, 0.0f};
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Generates some random columns
    float heights[MAX_COLUMNS] = {0};
    Vector3 positions[MAX_COLUMNS] = {0};
    Color colors[MAX_COLUMNS] = {0};

    for (int i = 0; i < MAX_COLUMNS; i++) {
        heights[i] = (float) GetRandomValue(1, 12);
        positions[i] = (Vector3) {(float) GetRandomValue(-15, 15), heights[i] / 2.0f, (float) GetRandomValue(-15, 15)};
        colors[i] = (Color) {static_cast<unsigned char>(GetRandomValue(20, 255)),
                             static_cast<unsigned char>(GetRandomValue(10, 55)), 30, 255};
    }

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    SetTargetFPS(0);                           // Set our game to run at 60 frames-per-second

    EnableCursor();
    ShowCursor();

    Pachy::vm vm;

    Pachy::php_module module{"Raylib"};

    module.registerfunction("print_coucou", ZEND_FN(print_coucou));
    module.registerfunction("draw_text", ZEND_FN(draw_text));


    vm.addModule(module);


//    std::chrono::time_point<std::chrono::system_clock> start, end;
//    std::chrono::duration<double> elapsed_time ;
//    vector<duration<microseconds>> time_stats;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update

        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);                  // Update camera
        //----------------------------------------------------------------------------------

        // Draw

        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawPlane((Vector3) {0.0f, 0.0f, 0.0f}, (Vector2) {32.0f, 32.0f}, LIGHTGRAY); // Draw ground
        DrawCube((Vector3) {-16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
        DrawCube((Vector3) {16.0f, 2.5f, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
        DrawCube((Vector3) {0.0f, 2.5f, 16.0f}, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

        // Draw some cubes around
        for (int i = 0; i < MAX_COLUMNS; i++) {
            DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
            DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, MAROON);
        }

        EndMode3D();

        DrawRectangle(10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 220, 70, BLUE);

        DrawText("First person camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);

        DrawFPS(10,10);

//        start = high_resolution_clock::now();
        vm.execute("scripts/example.php");
//        end = high_resolution_clock::now();
//        elapsed_time = duration_cast<microseconds>(end - start);

//        time_stats.push_back(elapsed_time);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    CloseWindow();        // Close window and OpenGL context

    return 0;
}