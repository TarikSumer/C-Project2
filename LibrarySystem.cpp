/*
 * LibrarySystem.cpp
 *
 *  Created on: 28 Kas 2020
 *      Author: Tarik
 */
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "LibrarySystem.h"
extern ofstream outputFile;

circularSimpleNode * head = new circularSimpleNode; // not checkedout movie list
circulardoublyNode * doublyhead = new circulardoublyNode;

bool LibrarySystem::ifExist(int id) {
    circularSimpleNode * current = head;
    bool flag = false;
    //Checks whether list is empty
         do{
             //Compares element to be found with each node in the list
            if(current->movie.movieId ==  id) {
                flag = true;
                break;
            }
            current = current->next;
        }while(current != head);
         if(flag)
            return true;
        else
            return false;
}

bool LibrarySystem::ifUserExist(int userId) {
	circulardoublyNode * current = doublyhead;
    bool flag = false;
    //Checks whether list is empty
         do{
             //Compares element to be found with each node in the list
            if(current->user.userId ==  userId) {
                flag = true;
                break;
            }
            current = current->next;
        }while(current != doublyhead);
         if(flag)
            return true;
        else
            return false;
}

void LibrarySystem::addUser(int userId, string userName) {
	   cout << "===addUser() method test===\n" ;

	   if(ifUserExist(userId)) {
		   cout << "User " << userId << " already exists" << endl;
	   }
	   else {
	   circulardoublyNode * newnode = new circulardoublyNode();
	   circulardoublyNode * ptr = doublyhead;
	   newnode->user.userId = userId, newnode->user.userName = userName;
	   newnode->next = doublyhead;
	   if (doublyhead != NULL) {
	      while (ptr->next != doublyhead) {
	      ptr = ptr->next;
	      }
		  ptr->next = newnode;
		  newnode->prev = ptr;
	   }
	   else {
	   newnode->next = newnode; // check
	   newnode->prev = newnode;
	   doublyhead = newnode;
	   }
	   cout << "User " << userId << " has been added" << endl;
	   }
}

void LibrarySystem::addMovie(int movieId, string movieTitle, int year) {
	cout << "===addMovie() method test===" << endl;
	   if(ifExist(movieId)) {
		   cout << "Movie " << movieId << " already exists" << endl;
	   }
	   else {
	   circularSimpleNode * newnode = new circularSimpleNode();
	   circularSimpleNode * ptr = head;
	   newnode->movie.movieId = movieId, newnode->movie.movieTitle = movieTitle, newnode->movie.year = year;
	   newnode->next = head;
	   if (head != NULL) {
	   while (ptr->next != head) {
	   ptr = ptr->next;
	   }
	   ptr->next = newnode;
	   }
	   else {
	   newnode->next = newnode; // check
	   head = newnode;
	   }
	   }
}

void LibrarySystem::showAllMovies() {
	cout << "===showAllMovie() method test===" << "Movie id - Movie name - Year - Status" << endl;
	circularSimpleNode * ptr;
	ptr = head;
	do {
		cout << ptr->movie.movieId << " " << ptr->movie.movieTitle << " " << ptr->movie.year << endl; //status de yazılacak!!!!!!
		ptr = ptr->next;
		} while(ptr != head);
}

void LibrarySystem::deleteMovie(int movieId) {
    circularSimpleNode * currentcheckedout = head;
    bool flag = false;
    //Checks whether list is empty
         do{
             //Compares element to be found with each node in the list
            if(currentcheckedout->next->movie.movieId ==  movieId) {
            	flag = true;
            	currentcheckedout->next = currentcheckedout->next->next;
            	cout << "Movie " << movieId << " has not been checked out" << endl;
            	cout << "Movie " << movieId << " has been deleted" << endl;
                break;
            }
            currentcheckedout = currentcheckedout->next;
        }while(currentcheckedout != head);
         //////
         if(flag == false) {  // then check for checkedout movies

        		circulardoublyNode * current = doublyhead;
        		circularSimpleNode * currentUserHead;
        	    bool flag = false;
        	    //Checks whether list is empty
        	         do{
        	        	 currentUserHead = current->user.head;
        	             //Compares element to be found with each node in the list
        	            if(current->user.head == NULL) {
        	                continue;
        	            } else {
        	            	do {
        	                    if(currentUserHead->next->movie.movieId == movieId) {
        	                        flag = true;

        	                        if(current->user.head->movie.movieId == movieId && current->user.head->next == current->user.head)
        	                        {
        	                            free(current->user.head);
        	                            current->user.head=NULL;
        	                            return;
        	                        } else {
        	                        	currentUserHead->next = currentUserHead->next->next;
        	                        }
        	                        break;
        	                    }
        	                currentUserHead = currentUserHead->next;
        	            	}while(currentUserHead->next != current->user.head);
        	            }
        	            current = current->next;
        	        }while(current != doublyhead);
        	        if (flag == true) {
        	        	cout << "Movie " << movieId << " has been checked out" << endl;
        	        	cout << "Movie " << movieId << " has been deleted" << endl;
        	        }else {
        	        	cout << "Movie " << movieId << " does not exist" << endl;
        	        }
        	}
}







