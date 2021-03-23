#include "DNode.hpp"
#include "DLL.hpp"
#include "Task.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


DLL::DLL(){  // constructor - initializes an empty list
	last = NULL;
	first = NULL;
	numTasks = 0;
	tothrs = 0;
	totmin = 0;
}
DLL::DLL(string t, int p, int h, int m){  // constructor, initializes a list with one new node with data x
	DNode *i = new DNode(t,p,h,m);
	first = i;
	last = i;
	numTasks=1;
	tothrs = h;
	totmin = m;
}
/***************************************************************************************************/
/*Part 1																																		*/
/***************************************************************************************************/
void DLL::push(string n, int p, int h, int m) {
	// does what you'd think, with a caveat that if the
	//priority isn't 3, it will move the task up to the end of the set of tasks with that priority.
	//In other words, if the priority is 1, it will traverse the list in reverse order until it finds a
	//task with a priority of 1, and insert the new task between the last task with a priority of
	//1 and the first task with a priority of 2
	//it also updates the total time of the list
	DNode *i = new DNode(n,p,h,m);
	DNode *tmp;
	for(tmp=last; tmp != NULL && p < tmp->task->priority; tmp=tmp->prev){

	}
	/*
	 *
	 * i->next = tmp->next;
	 * i->prev = tmp;
	 * tmp->next->prev = i ;
	 * tmp->next = i;
	 */
	if (first==NULL && last ==NULL) {
		first=i;
		last=i;
	} else if (tmp==last) {
		tmp->next=i;
		i->prev = tmp;
		i->next=NULL;
		last = i;
	} else if (tmp == NULL) { // first
		first = i;
		i->next=tmp;
		tmp->prev=i;
		i->prev=NULL;
	} else { // in the middle of the list
		 i->next = tmp->next;
		 i->prev = tmp;
		 tmp->next->prev = i ;
		 tmp->next = i;
	}

//
//	if(tmp == first){
//		first = i;
//		last = i;
//	}
//	else{
//		tmp=last;
//		i->prev = tmp;
//		i->next = NULL;
//		tmp->next=i;
//		last=i;
//	}
//  tmp = NULL;
	numTasks+=1;
	totmin+=m;
	tothrs+=h;
}

Task *DLL::pop() {
	//does what you'd think - make sure to update the total time of the list.
	//Note -this isn't all that necessary for this particular project, but I
	//kinda had to make you write pop because it's fundamental to so much of
	//linked list data type uses (e.g., stack, undo).
	DNode *tmp;
	if(numTasks == 1){
		tmp=first;
		first = NULL;
		last = NULL;
		numTasks = 0;
	}
	else{
		tmp=last;
		last = last->prev;
		last->next->next = NULL;
		last->next = NULL;
		delete last;
	}
	return tmp->task;
}

void DLL::printList() {
	//prints out the entire list, along with the total time necessary to complete all tasks
	//on the list
	int a, b;
	if (totmin >= 60) {
		a = totmin%60;
		b = totmin/60;
		totmin = a;
		tothrs+=b;
	}
	if (totmin < 0) {
		//a = (-totmin) %60;
		b = ((-totmin) / 60)+1;
		a = 60*b + totmin;


//		a = totmin + 60;
//		b = tothrs - 1;
		totmin = a;
		tothrs-= b;
	}
	cout<<"Total Time Required: "<<tothrs<<":"<<totmin<<endl;
	DNode *tmp;
	for(tmp=first;tmp!=NULL;tmp=tmp->next){
		tmp->task->printTask();
	}
	cout<<" "<<endl;
}

void DLL::printList(int p) {
	//print out only all the tasks with a priority of p, along with the total time necessary
	//to complete the tasks with a priority of p
}

void DLL::moveUp(int tn) {
	// moves task with number tn up one in the list.
	//If it is at the beginning of the list,
	//it will be moved to the end of the list.
	// NOTE: if this moves a task up before a task with a higher priority (1 is
	// higher priority than 2 - I know the wording is a bit weird), then this
	// changes the priority of the task being moved to that higher priority
	DNode *list;
	for (list=first; list->task->tasknum !=tn; list=list->next){ // Didn't add the last part yet because idk how to sort priorities yet
	}

	if(list==first){
		DNode *Y=first;
		DNode *Z=last;
		first=first->next;
		first->prev=NULL;
		Z->next=Y;
		Y->prev=Z;
		Y->next=NULL;
		last=Y;
	}
	else if (list==first->next) { //somewhere here, this part is for changing the second thing to the first thing
		DNode *X=list;
		DNode *Y=list->prev;
		DNode *Z=list->next;
		X->prev=NULL;
		X->next=Y;
		Y->prev=X;
		Y->next=Z;
		Z->prev=Y;
	}
	else if(list==last){
		DNode *X=list->prev->prev;
		DNode *Y=list;
		DNode *Z=list->prev;
		X->next=Y;
		Y->prev=X;
		Y->next=Z;
		Z->prev=Y;
		Z->next=NULL;
		last=Z;
		Z=last;
	}
	else{
		DNode *W=list->prev->prev;
		DNode *X=list;
		DNode *Y=list->prev;
		DNode *Z=list->next;
		W->next=X;
		X->prev=W;
		X->next=Y;
		Y->prev=X;
		Y->next=Z;
		Z->prev=Y;
	}
	if(list->task->priority > list->next->task->priority){
		list->task->priority -= 1;
	}
}

void DLL::listDuration(int *th, int *tm,int tp) {
	// gets the list duration in hours and minutes (passed
	//in as pointers) of a particular priority (so the total time
	//needed to complete all tasks with priority of p)
	// I had you pass in the parameters as pointers for practice.
}


void DLL::moveDown(int tn) {
	//moves task with task number tn down one in the list.
	//If it is at the end of the list, it will move to
	//beginning of the list.
	//NOTE: if this moves a task after a task with a lower priority (again, 3 is
	//a lower priority than 2) then this changes the priority of the task being
	//moved.
	DNode *list;
	for(list=first;list->task->tasknum!=tn;list=list->next){
	}
	if(list==first){
		DNode *X=list->next->next;
		DNode *Y=list;
		DNode *Z=list->next;
		Y->next=X;
		X->prev=Y;
		Y->prev=Z;
		Z->next=Y;
		Z->prev=NULL;
		first=Z;
		Z=first;
	}
	else if(list==last){
		DNode *Y=first;
		DNode *Z=last;
		last=last->prev;
		last->next=NULL;
		Z->next=Y;
		Y->prev=Z;
		Z->prev=NULL;
		first=Z;
	}
	else{
		DNode *W=list->prev;
		DNode *X=list->next;
		DNode *Y=list;
		DNode *Z=list->next->next;
		W->next=X;
		X->prev=W;
		X->next=Y;
		Y->prev=X;
		Y->next=Z;
		Z->prev=Y;
	}
	if (list->task->priority < list->next->task->priority) {
		list->task->priority += 1;
	}
}

int DLL::remove(int tn) {
	//removes a task (based on its number) and updates the total time of the list
	//Make sure you link the next to the previous and the previous to the next.  The
	//biggest catch with this method is making sure you test to make sure the node
	//after and/or the node before the node you’re deleting aren’t NULL (i.e., you’re
	//not deleting the first or last node in the list)
	DNode *tmp;
	int r = 0;
	if(first->task->tasknum == tn){
		tothrs-=first->task->hr;
		totmin-=first->task->min;
		tmp = first;
		first->next->prev = NULL;
		first = tmp->next;
		r = 0;

	}
	else if(last->task->tasknum == tn){
		tothrs-=last->task->hr;
		totmin-=last->task->min;
		tmp = last;
		last->prev->next = NULL;
		last = tmp->prev;
		r = numTasks - 1;
	}
	else{
		for(tmp=first;tmp->task->tasknum!=tn;tmp=tmp->next){
			r+=1;
			if(tmp == last){
				return -1;
			}

		}
		tothrs-=tmp->task->hr;
		totmin-=tmp->task->min;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp->next=NULL;
		tmp->prev=NULL;



	}
	numTasks-= 1;
	cout << "Removing: ";
	tmp->task->printTask();
	delete tmp;
	return r;

}

void DLL::changePriority(int tn, int newp) {
	//changes the priority of the task.  This method also moves the task to the end
	//of the set of tasks with
	//that priority.  In other words, if you have the following:
	/*task1, 1, 2:20
		task2, 1, 3:20
		task3, 1, 1:15
		task4, 2, 3:10
		task5, 2, 1:10
		task6, 3, 3:15
		task7, 3, 2:54

		And you change task6’s priority to 1, the resulting list should be:
		task1, 1, 2:20
		task2, 1, 3:20
		task3, 1, 1:15
		task6, 1, 3:15
		task4, 2, 3:10
		task5, 2, 1:10
		task7, 3, 2:54
	 */
	/*DNode *tmp;
	tmp->task->priority = newp;*/
}

DLL::~DLL(){
	DNode *tmp = first;
	DNode *tmp2 = first->next;
	while (tmp != NULL) {
		delete tmp;
		tmp = tmp2;
		if (tmp != NULL) {
			tmp2 = tmp2->next;
		}
	}
	first = NULL;
	last = NULL;
	numTasks = 0;
	tothrs = 0;
	totmin = 0;
}

/******************Optional Helper Methods********************************/
void DLL::addTime(int h, int m) { //Called in
}

void DLL::removeTime(int h, int m) {
}
/********************End of Optional Helper Methods ********************/
