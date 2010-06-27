#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "shape.h"
#include "vehicle.h"
#include "basis.h"
#include "motor.h"

#define WIDTH_SCREEN 800
#define HEIGHT_SCREEN 600

int main (int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("GetTheCube", NULL);
    SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 32, SDL_OPENGL);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,WIDTH_SCREEN,0,HEIGHT_SCREEN); //(0,0) bottom left

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

//----Body----//
    Body body;

    Rectangle rectBody;
    rectBody.length = 100;
    rectBody.width = 30;
    body.rectangle = &rectBody;

    Coord posBody;
    posBody.x = 0;
    posBody.y = 0;
    body.position = &posBody;

//----frontWheel----//
    Wheel frontWheel;

    Disk diskWheel;
    diskWheel.radius = 12;
    diskWheel.nbVertex = 50;
    diskWheel.portion = FULL;
    frontWheel.disk = &diskWheel;

    Circle wheelLine;
    wheelLine.radius = 10;
    wheelLine.nbVertex = 50;
    wheelLine.portion = HALF;
    frontWheel.wheelLine = &wheelLine;

    frontWheel.rotationAngle = 0;
    frontWheel.rotationVelocity = 10.0;

    Coord posFrontWheel;
    posFrontWheel.x = rectBody.length/2-diskWheel.radius;
    posFrontWheel.y = -rectBody.width/2-diskWheel.radius;
    frontWheel.position = &posFrontWheel;

//----rearWheel----//
    Wheel rearWheel = frontWheel;

    Coord posRearWheel;
    posRearWheel.x = -rectBody.length/2+diskWheel.radius;
    posRearWheel.y = -rectBody.width/2-diskWheel.radius;
    rearWheel.position = &posRearWheel;

//----Head----//
    Head head;

    Disk diskHead;
    diskHead.radius = 18;
    diskHead.nbVertex = 50;
    diskHead.portion = HALF;
    head.disk = &diskHead;

    Coord posHead;
    posHead.x = 0;
    posHead.y = rectBody.width/2;
    head.position = &posHead;

//----Canon----//
    Canon canon;

    Rectangle rectCanon;
    rectCanon.length = 50;
    rectCanon.width = 10;
    canon.rectangle = &rectCanon;

    canon.rotationAngle = 0;
    canon.rotationVelocity = 4.0;

    Coord posCanon;
    posCanon.x = 0;
    posCanon.y = rectBody.width/2+diskHead.radius/2;
    canon.position = &posCanon;

//----Vehicle----//
    Vehicle vehicle;

    Coord posVehicle;
    posVehicle.x = WIDTH_SCREEN/2;
    posVehicle.y = HEIGHT_SCREEN/2;

    vehicle.velocity = 4.0;

    vehicle.position = &posVehicle;
    vehicle.body = &body;
    vehicle.frontWheel = &frontWheel;
    vehicle.rearWheel = &rearWheel;
    vehicle.canon = &canon;
    vehicle.head = &head;
    vehicle.position = &posVehicle;

    drawVehicle(&vehicle);

    glFlush();
    SDL_GL_SwapBuffers();

    SDL_Event event;
    int previousTime = 0;
    int currentTime = 0;
    int elapsedTime = 0;

    int again = 1;
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
                        translateVehicle(&vehicle, RIGHT);
                        rotateWheel(&frontWheel, INDIRECT);
                        rotateWheel(&rearWheel, INDIRECT);
                        break;

                    case SDLK_LEFT:
                        translateVehicle(&vehicle, LEFT);
                        rotateWheel(&frontWheel, DIRECT);
                        rotateWheel(&rearWheel, DIRECT);
                        break;

                    case SDLK_UP:
                        rotateCanon(&canon, DIRECT);
                        break;

                    case SDLK_DOWN:
                        rotateCanon(&canon, INDIRECT);
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
            drawVehicle(&vehicle);
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
