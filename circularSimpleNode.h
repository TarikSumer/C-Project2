/*
 * circularSimpleNode.h
 *
 *
 *      Author: Tarik
 */

#ifndef CIRCULARSIMPLENODE_H_
#define CIRCULARSIMPLENODE_H_

#include <iostream>
using namespace std;
//----------------------------------------

struct movie {
	int movieId;
	string movieTitle;
	int year;
};

struct circularSimpleNode { // list for movies checkedout(for each user) or not checkedout ones by anyone

		circularSimpleNode * next;
		movie movie;

};

struct user {
	int userId;
	string userName;
	circularSimpleNode * head = NULL;
};

struct circulardoublyNode {

		circulardoublyNode * next;
		circulardoublyNode * prev;
		user user;

};


#endif /* CIRCULARSIMPLENODE_H_ */
