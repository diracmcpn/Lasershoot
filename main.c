#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "shape.h"
#include "vehicle.h"

#define WIDTH_SCREEN 800
#define HEIGHT_SCREEN 600
#define FRAME_PER_SECOND 40 //
#define VELOCITY_VEHICLE 2.0 //pixels/second
#define VELOCITY_CANON 4.0 //angle/second

int main (int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("GetTheCube", NULL);
    SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 32, SDL_OPENGL);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,WIDTH_SCREEN,0,HEIGHT_SCREEN);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(WIDTH_SCREEN/2,HEIGHT_SCREEN/2,0);

    //drawFrame(100);
    double posx = 0;
    double rotcanon = 0;
    double rotwheel = 0;
    drawVehicle(posx,rotcanon,rotwheel);

    glFlush();
    SDL_GL_SwapBuffers();

    SDL_Event event;
    int again = 1;
    int previousTime = 0;
    int currentTime = 0;
    int elapsedTime = 0;

    while (again)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                again = 0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        posx+=VELOCITY_VEHICLE/FRAME_PER_SECOND;
                        rotwheel -= VELOCITY_VEHICLE/FRAME_PER_SECOND; //virtual angular velocity
                        break;

                    case SDLK_LEFT:
                        posx-=VELOCITY_VEHICLE/FRAME_PER_SECOND;
                        rotwheel += VELOCITY_VEHICLE/FRAME_PER_SECOND; //virtual angular velocity
                        break;

                    case SDLK_UP:
                        rotcanon += VELOCITY_CANON/FRAME_PER_SECOND;
                        if (rotcanon>85)
                        {
                            rotcanon = 85;
                        }
                        break;

                    case SDLK_DOWN:
                        rotcanon -= VELOCITY_CANON/FRAME_PER_SECOND;
                        if (rotcanon<0)
                        {
                            rotcanon = 0;
                        }
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
        currentTime = SDL_GetTicks();
        elapsedTime = currentTime - previousTime;

        if (elapsedTime > 1000/FRAME_PER_SECOND)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glTranslated(WIDTH_SCREEN/2,HEIGHT_SCREEN/2,0);
            drawVehicle(posx,rotcanon,rotwheel);
            glFlush();
            SDL_GL_SwapBuffers();

            previousTime = currentTime;
        }
        else
        {
            SDL_Delay(1000/FRAME_PER_SECOND - elapsedTime);
        }
    }

    SDL_Quit();

    return 0;
}
