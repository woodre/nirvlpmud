/******************************************************************************
 *  File:           bag.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         2001.12.08
 *  Notes:          
 *  Change History: 2005.10.22
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

inherit "/obj/bag.c";
inherit "/obj/newtreasure.c";

#ifdef MAX_WEIGHT
#undef MAX_WEIGHT
#endif
#define MAX_WEIGHT 12

int local_weight;

void
reset(status arg)
{
  if (arg) return;
  local_weight = 0;
  set_info("This DS-12 case is made of a high-density plastic.\n");
}

void
long()
{
  write(format("A standard dimensional shifting case used as luggage by most \
of the people here in the N.U.T.S. "));
  if (first_inventory(this_object()))
    write("There seems to be things in the DS-12 case.\n");
  else
    write("You can put things in the DS-12 case.\n");
}

int
query_weight() { return 1; }

status
add_weight(int w)
{
  if (local_weight + w > MAX_WEIGHT)
    return 0;
  local_weight += w;
  return 1;
}

string
short() { return "A DS-12 case"; }

status
id(string str)
{
  return (str == "suitcase" || str == "case");
}

int
query_value() { return 12; }
