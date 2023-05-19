#ifndef NEWLAB_PROCEDURE4_H
#define NEWLAB_PROCEDURE4_H

#pragma once

#include <vector>
#include <algorithm>

void swapRows(std::vector<std::vector<int>>& matrix, int row1, int row2)
{
    std::swap(matrix[row1], matrix[row2]);
}

#endif
//NEWLAB_PROCEDURE4_H
