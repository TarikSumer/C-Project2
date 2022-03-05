
#ifndef LIBRARYSYSTEM_H_
#define LIBRARYSYSTEM_H_
#include <iostream>
using namespace std;

#include "circularSimpleNode.h"

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	class LibrarySystem {

	public:

		void addMovie(int movieId, string movieTitle, int year); //
		void deleteMovie(int movieId);//

		void addUser(int userId, string userName); //
		void deleteUser(int userId);

		void checkoutMovie(int movieId, int userId);

		void showAllMovies();  //
		void showMovie(int movieId);
		void showUser(int userId);
		movie returnMovie(int movieId);

		bool ifExist(int id); //checks for movie in not checkedout movie list
		bool ifUserExist(int userId); //
	};

#endif /* LIBRARYSYSTEM_H_ */
