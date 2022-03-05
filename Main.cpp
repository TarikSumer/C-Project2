//============================================================================
// Name        : Assignment2.cpp
// Author      : Tarık Sümer
// Version     :
// Copyright   :
// Description :
//============================================================================
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "LibrarySystem.h"
#include "circularSimpleNode.h"
//                                            ----------(-_-)----------
//                                   -------------Class Intersection------------
ofstream outputFile;

int main(int argc, char* argv[]) {                 //MAIN
		LibrarySystem * librarySystem = new LibrarySystem();


	   fstream newfile;

	   outputFile.open("output.txt", ios::out);  // performing write operation to file// path yerine argv[] vercez


	   newfile.open("commands.txt",ios::in); //open a file to perform read operation using file object


	   if (newfile.is_open()){   //checking whether the file is open
	      string line;
	      while(getline(newfile, line)){ //read data from newfile object and put it into line string.
	    	  std::stringstream test(line);
	    	  std::string segment;
	    	  std::vector<std::string> seglist;
	    	  while(std::getline(test, segment, '\t'))
	    	  	  {
	    		  	  seglist.push_back(segment);
	    	  	  }
	   //--------------------------------------------------------//
	    	  if (seglist[0] == "addMovie") {
	    		  librarySystem->addMovie(std::stoi(seglist[1]), seglist[2], std::stoi(seglist[3]));
	    	  }
	    	  else if (seglist[0] == "deleteMovie") {
	    		  librarySystem->deleteMovie(std::stoi(seglist[1]));
	    	  }
	    	  else if (seglist[0] == "addUser") {
	    		  librarySystem->addUser(std::stoi(seglist[1]), seglist[2]);
	    	  }
	    	  else if (seglist[0] == "deleteUser") {

	    	  }
	    	  else if (seglist[0] == "checkoutMovie") {

	    	  }
	    	  else if (seglist[0] == "showUser") {

	    	  }
	    	  else if (seglist[0] == "showMovie") {

	    	  }
	    	  else if (seglist[0] == "showAllMovies") {
	    		  librarySystem->showAllMovies();
	    	  }
	    	  else if (seglist[0] == "returnMovie") {

	    	  }
	      }
	   } //if block

	   newfile.close(); //close the file object.
	   outputFile.close();

	   return 0;
}
