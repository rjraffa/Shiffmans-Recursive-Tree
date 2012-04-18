/*
 *  branch.h
 *
 *  Created by Ryan Raffa on 4/17/12.
 *  Based on Daniel Shiffman's Recursive Tree <http://www.shiffman.net>
 */

#ifndef _branch
#define _branch


#include "ofMain.h"

class branch {

	public:
        branch (ofPoint& l, ofPoint& v, float& n);
        branch (ofPoint l, ofPoint v, float n);
		void update();
		void draw();
        void render();
        bool timeToBranch();
  
        float heading2D(ofPoint);
        float mag(ofPoint);
    
        branch brancher(float angle);
    
        ofPoint start;
        ofPoint end;
        ofPoint vel;
        float timer;
        float timerstart;
        
        bool growing;
		
};

#endif