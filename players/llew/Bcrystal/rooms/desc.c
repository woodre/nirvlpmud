#pragma strict_types
#include "/players/llew/Bcrystal/rooms/bc_rooms.h"

/* This file holds a number of different descriptions for areas of the
 *  crystal, so I don't have to write 100 unique descriptions.  It has
 *  the added feature of being random every reboot. 
 */

string *describe_room(int section)
{
   /* For now, just return a general description. */
   return ({ "This is a blank description in the crystal area.\nYou are in section " + 
             section + ".\n", "crystal", "The crystal is crystaline" });
}
