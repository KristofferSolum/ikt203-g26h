//
// Created by krist on 05.09.2026.
//

#include "TMovie.h"

TMovie::TMovie(string Title, string Director, int Year, EMovieGenreType Genre, float Score) {
    this->Title = Title;
    this->Director = Director;
    this->Year = Year;
    this->Genre = Genre;
    this->Score = Score;
}

string TMovie::GetTitle() {
    return Title;
}

string TMovie::GetDirector() {
    return Director;
}

int TMovie::GetYear() {
    return Year;
}

EMovieGenreType TMovie::GetGenre() {
    return Genre;
}

float TMovie::GetScore() {
    return Score;
}