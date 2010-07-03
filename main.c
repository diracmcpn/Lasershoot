#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "shape.h"
#include "scene.h"
#include "physicmotor.h"
#include <stdio.h>
#include <time.h>

int main (int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    //----Scene----//
    Scene scene;
    scene.width = 800;
    scene.height = 600;

    SDL_WM_SetCaption("GetTheCube", NULL);
    SDL_SetVideoMode(scene.width, scene.height, 32, SDL_OPENGL);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,scene.width,0,scene.height); //origin(0,0) bottom left

//----Ground----//
    Ground ground;
    ground.position.x = scene.width/2;
    ground.position.y = 50;
    ground.line.length = scene.width;

//----Medium----//
    Medium medium;
    medium.rectangle.length = 100;
    medium.rectangle.width = 400;
    srand(time(NULL));
    medium.position.x = scene.width/2 + rand() * (3*scene.width/8.0/RAND_MAX);
    medium.position.y = ground.position.y + medium.rectangle.width/2;

//----Support----//
    Stand stand;
    stand.rectangle.length = 10;
    srand(time(NULL));
    stand.rectangle.width = ground.position.y + rand() * ((scene.height-ground.position.y)*9/10/RAND_MAX);
    stand.position.x = scene.width - stand.rectangle.length;
    stand.position.y = ground.position.y + stand.rectangle.width/2;

//----target----//
    Target target;
    target.circle.radius = 10;
    target.circle.nbVertex = 50;
    target.circle.piAngle = 2;
    target.position.x = stand.position.x;
    target.position.y = ground.position.y + stand.rectangle.width + target.circle.radius;

//----Vehicle----//
    Vehicle vehicle;

    //body
    vehicle.body.rectangle.length = 100;
    vehicle.body.rectangle.width = 30;
    vehicle.body.position.x = 0;
    vehicle.body.position.y = 0;

    //frontWheel
    vehicle.frontWheel.circle.radius = 12;
    vehicle.frontWheel.circle.nbVertex = 50;
    vehicle.frontWheel.circle.piAngle = 2;
    vehicle.frontWheel.position.x = vehicle.body.rectangle.length/2-vehicle.frontWheel.circle.radius;
    vehicle.frontWheel.position.y = -vehicle.body.rectangle.width/2-vehicle.frontWheel.circle.radius;

    vehicle.frontWheel.line.radius = 10;
    vehicle.frontWheel.line.nbVertex = 50;
    vehicle.frontWheel.line.piAngle = 1;

    vehicle.frontWheel.rotationAngle = 0;
    vehicle.frontWheel.rotationVelocity = 10.0;

    //rearWheel
    vehicle.rearWheel = vehicle.frontWheel;
    vehicle.rearWheel.position.x = -vehicle.frontWheel.position.x;

    //head//
    vehicle.head.circle.radius = 18;
    vehicle.head.circle.nbVertex = 50;
    vehicle.head.circle.piAngle = 1;

    vehicle.head.position.x = 0;
    vehicle.head.position.y = vehicle.body.rectangle.width/2;

    //canon//
    vehicle.canon.rectangle.length = 50;
    vehicle.canon.rectangle.width = 10;

    vehicle.canon.rotationAngle = 0;
    vehicle.canon.rotationVelocity = 4.0;
    vehicle.canon.minAngle = 0;
    vehicle.canon.maxAngle = 85;

    vehicle.canon.position.x = 0;
    vehicle.canon.position.y = vehicle.body.rectangle.width/2 + vehicle.head.circle.radius/2;

    //vehicle
    vehicle.position.x = vehicle.body.rectangle.length/2 + 10;
    vehicle.position.y = ground.position.y + vehicle.body.rectangle.width/2 + 2*vehicle.frontWheel.circle.radius;

    vehicle.velocity = 4.0;
    vehicle.minPos = vehicle.body.rectangle.length/2;
    vehicle.maxPos = medium.position.x - medium.rectangle.length/2 - vehicle.body.rectangle.length/2;

//------The World and Event------//
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
                        rotateWheel(&(vehicle.frontWheel), INDIRECT);
                        rotateWheel(&(vehicle.rearWheel), INDIRECT);
                        break;

                    case SDLK_LEFT:
                        translateVehicle(&vehicle, LEFT);
                        rotateWheel(&(vehicle.frontWheel), DIRECT);
                        rotateWheel(&(vehicle.rearWheel), DIRECT);
                        break;

                    case SDLK_UP:
                        rotateCanon(&(vehicle.canon), DIRECT);
                        break;

                    case SDLK_DOWN:
                        rotateCanon(&(vehicle.canon), INDIRECT);
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
            drawGround(&ground);
            drawMedium(&medium);
            drawStand(&stand);
            drawTarget(&target);
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
