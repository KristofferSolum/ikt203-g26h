//
// Created by krist on 05.09.2026.
//

#ifndef TMOVIENODE_H
#define TMOVIENODE_H
#include <string>
#include "EMovieGenreType.h"
using namespace std;


class TMovie {
private:
    string Title;
    string Director;
    int Year;
    EMovieGenreType Genre;
    float Score;

    public:
    TMovie(string Title, string Director, int Year, EMovieGenreType Genre, float Score);
    string GetTitle();
    string GetDirector();
    int GetYear();
    EMovieGenreType GetGenre();
    float GetScore();
};


#endif //TMOVIENODE_H
