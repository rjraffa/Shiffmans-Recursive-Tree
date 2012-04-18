/*
 *  leaf.h
 *
 *  Created by Ryan Raffa on 2/19/11.
 *  Based on Daniel Shiffman's Recursive Tree <http://www.shiffman.net>
 */

#ifndef _leaf
#define _leaf


#include "ofMain.h"

class leaf {

	public:
        leaf (ofPoint);
		void draw();
    
        ofPoint loc;
		
};

#endif