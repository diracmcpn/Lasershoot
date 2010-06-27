#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "shape.h"
#include "vehicle.h"

#define WIDTH_SCREEN 800
#define HEIGHT_SCREEN 600
#define FRAME_PER_SECOND 40
#define VELOCITY_VEHICLE 60 //pixels/second
#define VELOCITY_CANON 40 //angle/second

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
    SDL_EnableKeyRepeat(10,1000/FRAME_PER_SECOND);

    while (again)
    {
        SDL_WaitEvent(&event);
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
                        rotwheel -= 8; //virtual angular velocity
                        break;

                    case SDLK_LEFT:
                        posx-=VELOCITY_VEHICLE/FRAME_PER_SECOND;
                        rotwheel += 8; //virtual angular velocity
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
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslated(WIDTH_SCREEN/2,HEIGHT_SCREEN/2,0);
        drawVehicle(posx,rotcanon,rotwheel);
        glFlush();
        SDL_GL_SwapBuffers();
    }

    SDL_Quit();

    return 0;
}
