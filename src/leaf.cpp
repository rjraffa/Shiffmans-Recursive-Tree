//
//  leaf.cpp
//  emptyExample
//
//  Created by Ryan Raffa on 4/17/12.
//  Based on Daniel Shiffman's Recursive Tree <http://www.shiffman.net>
//

#include "leaf.h"


//------------------------------------------------------------------
leaf::leaf(ofPoint l) {
    loc = l;
}


//------------------------------------------------------------------
void leaf::draw() {
    ofSetColor(50);
    ofCircle(loc.x, loc.y, 4);
}

