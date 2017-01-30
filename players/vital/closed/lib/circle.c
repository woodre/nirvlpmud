/******************************************************************************
 *  File:           circle.c
 *  Function:       return the various things of a circle given the radius
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2003 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         22/1/04
 *  Notes:          
 *  Change History:
 *****************************************************************************/

int
circumfrence(int radius)
{
    int circumfrence, diameter, pi;
    
    diameter = (radius + radius);
    pi = 31415926535;
    circumfrence = ( (diameter * pi)/10000000000 );
    return circumfrence;
}

int
circle_area(int radius)
{
    int radius_square, pi, area;
    
    radius_square = (radius * radius);
    pi = 31415926535;
    area = ( (radius_square * pi)/10000000000 );
    return area;
}
