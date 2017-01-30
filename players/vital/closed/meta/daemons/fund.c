/******************************************************************************
 *  File:           fund.c
 *  Function:       Manage various and sundry guild functions
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         27/04/2004
 *  Notes:          Moved from several locations into the daemon
 *                  [keeping it small, keeping it real]
 *  Change History:
 *****************************************************************************/

#include "../inc/def.h"
#define VITAL find_player("vital")

/******************************************************************************
 *  Function:   psychic_suicide()
 *  Description:Death by mindlessness. Called by some spells when guild
 *              member doesn't have enough power.
 *  Arguments:  victim  -   name of victim in a string
 *****************************************************************************/
void
psychic_suicide(string victim)
{
    int hp;
    string name, pos;
    object WaitingDead, Killer;

    WaitingDead = find_player(victim);

    if(!environment(WaitingDead)) return;

    if((hp = (status)WaitingDead->query_hp()))
      WaitingDead->add_hit_point(-hp);

    pos = capitalize(possessive(WaitingDead));

    switch(random(5))
    {
      case 0: name = pos + " own carelessness"; break;
      case 1: name = "A lack of self-control"; break;
      case 2: name = pos + " own stupidity"; break;
      case 3: name = "Immaturity"; break;
      case 4: name = "A lack of discipline"; break;
    }

    Killer = clone_object("/obj/monster");
    Killer->set_name(name);
    move_object(Killer, environment(WaitingDead));
    WaitingDead->attacked_by(Killer);
    WaitingDead->death();
    destruct(Killer);
}

string
list_houses(mapping Houses)
{
    string house_list, *house_keys;
    int x, y;
    
    house_keys = keys(Houses);
    
    y = sizeof(house_keys);
    
    for ( x = 0; x < y; x++ )
    {
        if ( x != y ) house_list += house_keys[x] + ", ";
        else house_list += house_keys[x];
    }
    return house_list;
}

load_houses(object owner)
{
    mapping temp_houses;
    temp_houses = owner->query_houses();
    if (query_saved_house("creator")) temp_houses["Creator"] = 1;
        else
        temp_houses["Creator"] = 0;
    if (query_saved_house("coercer")) temp_houses["Coercer"] = 2;
        else
        temp_houses["Coercer"] = 0;
    if (query_saved_house("telekinetic")) temp_houses["Telekinetic"] = 4;
        else
        temp_houses["Telekinetic"] = 0;
    if (query_saved_house("farsensor")) temp_houses["Farsensor"] = 8;
        else
        temp_houses["Farsensor"] = 0;
    if (query_saved_house("redactor")) temp_houses["Redactor"] = 16;
        else
        temp_houses["Redactor"] = 0;
    return temp_houses;
}

