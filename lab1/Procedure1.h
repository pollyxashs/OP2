#ifndef NEWLAB_PROCEDURE1_H
#define NEWLAB_PROCEDURE1_H
#pragma once

void discardIntegerPart(float* number)
{
    *number = *number - static_cast<int>(*number);
}

#endif
//NEWLAB_PROCEDURE1_H
