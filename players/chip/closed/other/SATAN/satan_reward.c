/*
 *    File: /players/chip/closed/other/SATAN/satan_reward.c
 *    Function: Sellable Item
 *    Author(s): Chip@Nirvana
 *    Copyright: Copyright (c) 2008 Chip
 *               All Rights Reserved
 *    Source: 5/31/08
 *    Notes: This mark is intended to be a reward for defeating Satan, as
 *    well as being something to show off for doing such. I want to also
 *    add some sort of special effect like improved detox or natural regen,
 *    or perhaps cause a small to moderate fire damage of some sort.
 *    Change History:
 */
 
inherit "obj/treasure";
#include "/players/chip/ansi.h"

reset(arg) {
   if(arg) return;
   set_alias("666");
   set_long("You have three burns on the back of your\n"+
            "head that form "+HIR+"666"+NORM+". Take pride in this most\n"+
            "prestigious of markings...you've earned it.\n");
   set_weight(0);
   set_dest_flag(1);
}

extra_look()
 {
  if(this_player()==environment()) {
    return "You have "+HIR+"666"+NORM+" burned into the back of your head"; }
  else {
    return capitalize(environment()->query_name())+" has "+HIR+"666"+NORM+" burned into the back of "+environment()->query_possessive()+" head";  }
}

query_auto_load() { return "players/chip/closed/other/SATAN/satan_reward.c:"; }

status id(string arg) { return ( arg == "burn" || arg == "burns" || arg == "burn marks" ||
                                 arg == "brand" || arg == "marks"); }

get(){ return 1; }
drop(){ return 1; }

