/******************************************************************************
 *  File:           yes_no.c
 *  Function:       return 1 for yes and 0 for no
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2003 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         22/1/04
 *  Notes:          
 *  Change History:
 *****************************************************************************/
#pragma strict_types
#pragma combine_strings

int
main(string answer)
{
    if ( answer == "yes" || answer == "y" )
        return 1;
    if ( answer == "no"  || answer == "n" )
        return 0;
    else
    {
        write("Are you sure? \[y\/n\]\n");
        input_to("main2");
    }
}

int
main2(string answer)
{
    if ( answer == "yes" || answer == "y" )
        return 1;
    if ( answer == "no"  || answer == "n" )
        return 0;
    else
    {
        write("Are you sure? You need to answer either \[y\/n\]\n");
        input_to("main");
    }
}