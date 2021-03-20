/*
 * DNode.cpp
 *
 *  Created on: Apr 2, 2020
 *      Author: 13027
 */
//e
#include <stdlib.h>
#include <iostream>
#include "DNode.hpp"
using namespace std;


DNode::DNode(string t, int p, int h, int m){
	task = new Task(t,p,h,m); //only one i'm unsure about is initializing task to NULL
	next = NULL;
	prev = NULL;
}


DNode::DNode(){
	task = NULL;
	next = NULL;
	prev = NULL;
}




