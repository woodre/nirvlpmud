/******************************************************************************
 *  File:           flame.c
 *  Author(s):      Jaraxle@Nirvana
 *  Copyright:      Copyright (c) 2004
 *                  All Rights Reserved.
 *  Source:         2004.09.02
 *  Notes:          
 *  Change History: 2005.10.21 - reformatted and modded several functions
 *****************************************************************************/
#pragma strict_types
#include "/players/jaraxle/define.h"
#define USER environment(this_object())
#define ATT USER->query_attack()

inherit "obj/armor";

int change_color;

/* Don't need this here
   --vital
set_type(string str){
  type = str;
}
*/

object ob;
int tmp, num;

void
reset(status arg)
{
  ::reset(arg);
  if (arg) return; /* Added return here for safety --Vital */
  set_name("orb of flame");
  set_alias("flame orb");
  set_long("A small red orb with a flickering flame in the center.\n"+
    HIW + "\'" + NORM + RED + "activate" + HIW + "\'" + NORM + " and " + HIW +
    "\'" + NORM + RED + "deactivate" + HIW + "\'" + NORM + " the orb.\n");
  set_ac(0);
  set_type("orb");            /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(0);
  set_value(4000);
  set_params("other|fire", 2, 30, "do_fire_special");
/* 2 ac, 30% resistance to other|fire damage, */
}

string
short()
{
  return "Orb of " + RED + "Flame" + NORM + "" + (worn_by ?
    " (floating nearby)" : "");
}

/* status */
/* id(string str) */
/* { */
/*   return str == "flame orb" || str == "orb" || str == "orb of flame" || st; */
/* } */

/*
query_worn() { return worn; }
query_type() { return type; }
query_save_flag(){ return 0; }
*/

void
init()
{
  ::init();

  add_action("activate","wear");
  add_action("deactivate","remove");
  add_action("activate","activate");
  add_action("deactivate","deactivate");
}

/* Moved into activate and/or deactivate function
wear_it(str)
{
  if(id(str))
  {
    write("You can "+HIW+"'"+NORM+RED+"activate"+HIW+"'"+NORM+" and "+HIW+"'"+NORM+RED+"deactivate"+HIW+"'"+NORM+" the orb to use this power.\n");
    return 1;
  }
}
*/

status
activate(string str)
{
  if (query_verb() != "activate") /* correct command check */
  {
    write("You can " + HIW + "\'" + NORM + RED + "activate" + HIW  + 
      "\'" + NORM + " the orb to use this power.\n");
    return 1;
  }
  if(environment() && environment()->is_kid() &&
    environment(environment(this_object())) ) /* environment checks */
  {
    object room; /* declared but unassigned - what room? */
    room = environment(environment(this_object())); /* added a def of room */
    tell_room(room, "The orb refuses the childs will.\n");
    return 1;
  }

  if(id(str))
  {
    if(!worn)
    {
      present(str, this_player())->wear(str); /* this should come first */
      write("The orb begins to slowly float to your side.\n"); /* then write */
      return 1;
    }
    return 0;
  }
}

status
deactivate(string str)
{
  if (query_verb() != "deactivate") /* correct command check */
  {
    write("You can " + HIW + "\'" + NORM + RED + "deactivate" + HIW + 
      "\'" + NORM + " the orb to power it down.\n");
    return 1;
  }
  if ( id(str) )
  {
    if (worn)
    {
      present(str, this_player())->remove(str); /* this first */
      write("The orb slowly sinks back into your hand.\n"); /* then write */
      return 1;
    }
    return 0;
  }
}

status
do_special(object owner)
{
  int i, cast;

  switch(random(5))
  {
    case 0: cast = "" + RED + "whip of fire" + NORM + "";
            break;
    case 1: cast = "" + HIR + "lick of flame" + NORM + "";
            break;
    case 2: cast = "" + RED + "spark of fire" + NORM + "";
            break;
    case 3: cast = "" + YEL + "spit of flame" + NORM + "";
            break;
    case 4: cast = "" + HIY + "ball of fire" + NORM + "";
            break;
  }

  i = random(8);
  if(!ATT) return 0;
  if(i==1)
  {
/*
      if(ATT->is_npc())
         ATT->heal_self(-(1+random(3)));
*/
    ATT->hit_player(random(2)+1, "other|fire");
    if(ATT)
      tell_room(environment(USER),
        capitalize( (string) (USER)->query_name()) + " burns  " +
        capitalize( (string) (ATT)->query_name()) + " with a " + cast + ".\n",
        ({ USER }));
    if(ATT)
      tell_object(USER, "You burn " + capitalize(  
        (string) (ATT)->query_name()) + " with a " + cast + ".\n");
    return 1;
  }
  return 1;
}

int
do_fire_special(object owner)
{
  if(!random(8))
  {
    tell_object(owner, "\
         The Orb of Flame glows a bright red as it absorbs some of the\n\
         fire damage.\n");
    return 1504;
/* 
15% [15] resistance boost
4  [04] ac boost
*/
  }
}
