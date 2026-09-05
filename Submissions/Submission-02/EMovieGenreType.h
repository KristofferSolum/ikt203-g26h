//
// Created by krist on 05.09.2026.
//

#ifndef EMOVIEGENRETYPE_H
#define EMOVIEGENRETYPE_H

enum EMovieGenreType {
    ACTION = 1,
    COMEDY = 2,
    SCIFI = 4,
    HORROR = 8,
    DRAMA = 16
};

inline EMovieGenreType operator|(EMovieGenreType a, EMovieGenreType b) {
    return static_cast<EMovieGenreType>(static_cast<int>(a) | static_cast<int>(b));
}

#endif //EMOVIEGENRETYPE_H
