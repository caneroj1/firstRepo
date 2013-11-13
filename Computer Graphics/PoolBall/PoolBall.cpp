/*  PoolBall Implementation
    CSC350, Final Project
    Created by Joseph Canero
 
    This file contains the function implementations for all of those defined in the header file
 */

#include "PoolBall.h"

//Parameterized Constructor
//set the coordinates of this ball to the coordinates of those that are passed in
PoolBall::PoolBall(double xPos, double yPos, double zPos, int bID) {
    //initialize positions
    xLoc = xPos;
    yLoc = yPos;
    zLoc = zPos;
    
    //initialize ID
    ballID = bID;
    
    //initialize velocity components
    xV = yV = zV = 0;
    angle = 0;
    //set radius and mass
    radius = 0.75;
    mass = 0.16;
}

//Non-parameterized Constructor
//****** This one should not be prioritized for use!!!!! ******
PoolBall::PoolBall() {
    xLoc = yLoc = zLoc = 0; //default values of each coordinate
    
    //initialize velocity components
    xV = yV = zV = 0;
    
    //set radius and mass
    radius = 0.75;
    mass = 0.16;
    
    //this is the best design decision ever
    ballID = 0;
}

//GETTERS

//Getter for ball angle
double PoolBall::getAngle() {
    return angle;
}

//Getter for x-component of velocity
double PoolBall::getXComponent() {
    return xV;
}

//Getter for y-component of velocity
double PoolBall::getYComponent() {
    return yV;
}

//Getter for z-component of velocity
double PoolBall::getZComponent() {
    return zV;
}

//Getter for x-coordinate of position
double PoolBall::getXLocation() {
    return xLoc;
}

//Getter for y-coordinate of position
double PoolBall::getYLocation() {
    return yLoc;
}

//Getter for z-coordinate of position
double PoolBall::getZLocation() {
    return zLoc;
}

//Getter for mass
float PoolBall::getMass() {
    return mass;
}

//Getter for radius
float PoolBall::getRadius() {
    return radius;
}

//Getter for ball ID
int PoolBall::getID() {
    return ballID;
}

//SETTERS

//Setter for ball angle
void PoolBall::setAngle(double ang) {
    angle = ang;
}

//Setter for x-component of velocity
void PoolBall::setXComponent(double xVel) {
    xV = xVel;
}

//Setter for y-component of velocity
void PoolBall::setYComponent(double yVel) {
    yV = yVel;
}

//Setter for z-component of velocity
void PoolBall::setZComponent(double zVel) {
    zV = zVel;
}

//Setter for x-coordinate of position
void PoolBall::setXLocation(double xL) {
    xLoc = xL;
}

//Setter for y-coordinate of position
void PoolBall::setYLocation(double yL) {
    yLoc = yL;
}

//Setter for z-coordinate of position
void PoolBall::setZLocation(double zL) {
    zLoc = zL;
}

//Setter for mass
void PoolBall::setMass(float m) {
    mass = m;
}

//Setter for radius
void PoolBall::setRadius(float r) {
    radius = r;
}

//Function to update the position of the ball using its velocity
void PoolBall::updatePosition() {
//    xLoc += xV - xLoc;
//    yLoc += yV - yLoc;
//    zLoc += zV - zLoc;
    xLoc += xV;
    yLoc += yV;
    zLoc += zV;

}

//Function to check if two PoolBall objects are the same. Each PoolBall object has an ID attribute that indicates which ball it is
bool PoolBall::operator!=(PoolBall Ball2) {
    if (ballID != Ball2.ballID) return true;
    else return false;
}

//Function to determine if this pool ball is colliding with another pool ball at location (b2x, b2y, b2z)
bool PoolBall::isColliding(PoolBall Ball2) {
    /*std::cout << "BALL 1 ID: " << ballID << " BALL 2 ID: " << Ball2.ballID << std::endl;
    std::cout << "IN COLLISION: BALL1 x y z " << xLoc << " " << yLoc << " " << zLoc << std::endl;
    std::cout << "IN COLLISION: BALL2 x y z " << Ball2.xLoc << " " << Ball2.yLoc << " " << Ball2.zLoc <<std::endl;*/
    //to determine if two uniform spheres are in a collision, it is as simple as determining if the distance between their centers is less than or equal to the diameter of a single ball
    if(ballID == Ball2.ballID) return false; //ball cannot collide with itself
    double centerDistance = sqrt( pow(xLoc + xV - Ball2.xLoc - Ball2.xV, 2) + pow(yLoc + yV - Ball2.yLoc - Ball2.yV, 2) + pow(zLoc - Ball2.zLoc, 2) ); //distance between the centers of the two pool balls
    //std::cout << "checking the centers!" << centerDistance << std::endl;
    if (centerDistance <= 2*radius) return true; //ball is colliding
    else return false;                              //ball is not colliding
}

void PoolBall::drawBall() {
    glPushMatrix();
    glTranslatef(0.0, 0.0, -15.0);
    glTranslatef(xLoc, yLoc, zLoc);
    glRotatef(angle, yV, -xV, 0);
    glutWireSphere(radius, 12, 10);
    glPopMatrix();
    //std::cout << "Velocity: " << xV << std::endl;
}