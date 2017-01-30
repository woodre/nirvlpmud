/******************************************************************************
 *  File:           querys.c
 *  Function:       return information about objects
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         31/05/2004
 *  Notes:          
 *  Change History:
 *****************************************************************************/

#include "../inc/def.h"

/* Use these ints to store/restore/rebuild Houses mapping */
int creator, coercer, telekinetic, farsensor, redactor;

/******************************************************************************
 *  Function:   query_saved_house(string string_house)
 *  Description:Determine if a house membership exists
 *  Arguments:  string Name of House, limited to:
 *              creator, coercer, telekinetic, farsensor, redactor
 *  Returns:    ID# of house if member, 0 if non-member, -1 if illegal house
 *****************************************************************************/
query_saved_house(string string_house)
{
    switch(string_house)
    {
        case "creator"      :
        case "Creator"      : return creator;
        case "coercer"      :
        case "Coercer"      : return coercer;
        case "telekinetic"  :
        case "Telekinetic"  : return telekinetic;
        case "farsensor"    :
        case "Farsensor"    : return farsensor;
        case "redactor"     :
        case "Redactor"     : return redactor;
        default             : return -1;
    }
    return 0;
}

/******************************************************************************
 *  Function:   add_house(string string_house) & set_house(string string_house)
 *  Description:Add a house membership by setting the ID# for that house
 *  Arguments:  string name of the house to add; limited to:
 *              creator, coercer, telekinetic, farsensor, redactor
 *  Returns:    1 on success, 0 on fail, -1 if illegal house
 *****************************************************************************/
int
add_house(string string_house)
{
    mapping Houses;
    Houses = (mapping)this_object()->query_houses();
    switch(string_house)
    {
        case "creator"      :
        case "Creator"      : Houses["Creator"] = 1;    return 1;
        case "coercer"      :
        case "Coercer"      : Houses["Coercer"] = 2;    return 1;
        case "telekinetic"  :
        case "Telekinetic"  : Houses["Telekinetic"] = 4;return 1;
        case "farsensor"    :
        case "Farsensor"    : Houses["Farsensor"] = 8;  return 1;
        case "redactor"     :
        case "Redactor"     : Houses["Redactor"] = 16;  return 1;
        default             : return -1;
    }
    return 0;
}

int
set_house(string string_house)
{
    return add_house(string_house);
}
