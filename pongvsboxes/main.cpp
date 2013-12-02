#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
//#include <GL/gl.h>
#include "Game.h"
#include "Player.h"


    Player player;

int main(int argc, char *argv[])
{

    // Request a 32-bits depth buffer when creating the window
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 32;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML graphics with OpenGL", sf::Style::Default, contextSettings);
    window.setVerticalSyncEnabled(true);

    // Make it the active window for OpenGL calls
    window.setActive();

    // Create a sprite for the background
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("resources/background.jpg"))
        return EXIT_FAILURE;
    sf::Sprite background(backgroundTexture);

    // Load an OpenGL texture.
    // We could directly use a sf::Texture as an OpenGL texture (with its Bind() member function),
    // but here we want more control on it (generate mipmaps, ...) so we create a new one from an image
    GLuint texture = 0;
    {

        sf::Image image;
        if (!image.loadFromFile("resources/texture.jpg"))
            return EXIT_FAILURE;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.getSize().x, image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    }

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glClearDepth(1.f);

    // Disable lighting
    glDisable(GL_LIGHTING);

    // Configure the viewport (the same size as the window)
    glViewport(0, 0, window.getSize().x, window.getSize().y);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

    // Bind the texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    //GLgloat player = new Player(0.0f, -92.0f, 0.0f, 40.0f, 15.0f);

    // Define a 3D cube (6 faces made of 2 triangles composed by 3 vertices)


    GLfloat player[] =
    {
        // positions    // texture coordinates
        -20, -100, -0.20,  0, 0,
        -20,  -85, -0.20,  1, 0,
        -20, -100,  0.20,  0, 1,
        -20, -100,  0.20,  0, 1,
        -20,  -85, -0.20,  1, 0,
        -20,  -85,  0.20,  1, 1,

         20, -100, -0.20,  0, 0,
         20,  -85, -0.20,  1, 0,
         20, -100,  0.20,  0, 1,
         20, -100,  0.20,  0, 1,
         20,  -85, -0.20,  1, 0,
         20,  -85,  0.20,  1, 1,

        -20, -100, -0.20,  0, 0,
         20, -100, -0.20,  1, 0,
        -20, -100,  0.20,  0, 1,
        -20, -100,  0.20,  0, 1,
         20, -100, -0.20,  1, 0,
         20, -100,  0.20,  1, 1,

        -20,  -85, -0.20,  0, 0,
         20,  -85, -0.20,  1, 0,
        -20,  -85,  0.20,  0, 1,
        -20,  -85,  0.20,  0, 1,
         20,  -85, -0.20,  1, 0,
         20,  -85,  0.20,  1, 1,

        -20, -100, -0.20,  0, 0,
         20, -100, -0.20,  1, 0,
        -20,  -85, -0.20,  0, 1,
        -20,  -85, -0.20,  0, 1,
         20, -100, -0.20,  1, 0,
         20,  -85, -0.20,  1, 1,

        -20, -100,  0.20,  0, 0,
         20, -100,  0.20,  1, 0,
        -20,  -85,  0.20,  0, 1,
        -20,  -85,  0.20,  0, 1,
         20, -100,  0.20,  1, 0,
         20,  -85,  0.20,  1, 1
    };

        GLfloat block[] =
    {
        // positions    // texture coordinates
        -20, -20, -0.20,  0, 0,
        -20,  -10, -0.20,  1, 0,
        -20, -20,  0.20,  0, 1,
        -20, -20,  0.20,  0, 1,
        -20,  -10, -0.20,  1, 0,
        -20,  -10,  0.20,  1, 1,

         20, -20, -0.20,  0, 0,
         20,  -10, -0.20,  1, 0,
         20, -20,  0.20,  0, 1,
         20, -20,  0.20,  0, 1,
         20,  -10, -0.20,  1, 0,
         20,  -10,  0.20,  1, 1,

        -20, -20, -0.20,  0, 0,
         20, -20, -0.20,  1, 0,
        -20, -20,  0.20,  0, 1,
        -20, -20,  0.20,  0, 1,
         20, -20, -0.20,  1, 0,
         20, -20,  0.20,  1, 1,

        -20,  -10, -0.20,  0, 0,
         20,  -10, -0.20,  1, 0,
        -20,  -10,  0.20,  0, 1,
        -20,  -10,  0.20,  0, 1,
         20,  -10, -0.20,  1, 0,
         20,  -10,  0.20,  1, 1,

        -20, -20, -0.20,  0, 0,
         20, -20, -0.20,  1, 0,
        -20,  -10, -0.20,  0, 1,
        -20,  -10, -0.20,  0, 1,
         20, -20, -0.20,  1, 0,
         20,  -10, -0.20,  1, 1,

        -20, -20,  0.20,  0, 0,
         20, -20,  0.20,  1, 0,
        -20,  -10,  0.20,  0, 1,
        -20,  -10,  0.20,  0, 1,
         20, -20,  0.20,  1, 0,
         20,  -10,  0.20,  1, 1
    };

    // Enable position and texture coordinates vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), player);
    glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), player + 3);


    // Disable normal and color vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);


    // Create a clock for measuring the time elapsed
    sf::Clock clock;

    // Start game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Escape key : exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            // Adjust the viewport when the window is resized
            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
        }

        // Draw the background
        window.pushGLStates();
        window.draw(background);
        window.popGLStates();

        // Clear the depth buffer
        glClear(GL_DEPTH_BUFFER_BIT);

        // We get the position of the mouse cursor, so that we can move the box accordingly
        float x =  sf::Mouse::getPosition(window).x * 200.f / window.getSize().x - 100.f;
        if(x <= -120)
            x = -120;
        else if(x >= 120)
            x = 120;
        //float y = -sf::Mouse::getPosition(window).y * 200.f / window.getSize().y + 100.f;


        // Apply some transformations
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(x, 0, -100.f);
        //glRotatef(clock.getElapsedTime().asSeconds() * 50.f, 1.f, 0.f, 0.f);
        //glRotatef(clock.getElapsedTime().asSeconds() * 30.f, 0.f, 1.f, 0.f);
        //glRotatef(clock.getElapsedTime().asSeconds() * 90.f, 0.f, 0.f, 1.f);

        // Draw the cube
        glDrawArrays(GL_TRIANGLES, 0, 30);


        // Finally, display the rendered frame on screen
        window.display();
    }

    // Don't forget to destroy our texture
    glDeleteTextures(1, &texture);

    return EXIT_SUCCESS;
}
