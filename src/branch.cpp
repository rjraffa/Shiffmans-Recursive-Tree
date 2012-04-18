//
//  branch.cpp
//  emptyExample
//
//  Created by Ryan Raffa on 4/17/12.
//  Based on Daniel Shiffman's Recursive Tree <http://www.shiffman.net>
//

#include "branch.h"


//------------------------------------------------------------------
branch::branch(ofPoint& l, ofPoint& v, float& n) {
    
    growing = true;
    
    start = l;
    end = l;
    vel = v;
    timerstart = n;
    timer = timerstart;
}


//------------------------------------------------------------------
branch::branch(ofPoint l, ofPoint v, float n) {
    
    growing = true;
    
    start = l;
    end = l;
    vel = v;
    timerstart = n;
    timer = timerstart;
}


//------------------------------------------------------------------
void branch::update() {
    if (growing) {
        end+=vel;
    }
}


// Draw a dot at location
//------------------------------------------------------------------
void branch::render() {
    ofSetLineWidth(1);
    ofLine(start.x,start.y,end.x,end.y);
}


// Did the timer run out?
//------------------------------------------------------------------
bool branch::timeToBranch() {
    timer--;
    if (timer < 0 && growing) {
        growing = false;
        return true;
    } 
    else {
        return false;
    }
}


// Create a new branch at the current location, but change direction by a given angle
//------------------------------------------------------------------
branch branch::brancher(float angle) {
    // What is my current heading
    float theta = heading2D(vel);
    // What is my current speed
    float magnify = mag(vel);
    // Turn me
    theta += ofDegToRad(angle);
    // Look, polar coordinates to cartesian!!
    ofPoint newvel = *new ofPoint(magnify*cos(theta),magnify*sin(theta));
    // Return a new Branch
    return branch(end,newvel,timerstart*0.66f);
}


//------------------------------------------------------------------
float branch::heading2D(ofPoint incoming) {
	float angle = (float)atan2(-incoming.y, incoming.x);
    return -1*angle;
}


//------------------------------------------------------------------
float branch::mag(ofPoint incoming) {
    return (float) sqrt(incoming.x*incoming.x + incoming.y*incoming.y + incoming.z*incoming.z);
}
