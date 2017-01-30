/*
 *    File: /players/chip/closed/other/HALO/chief_reward.c
 *    Function: Reward Extra_Look Item
 *    Author(s): Chip@Nirvana
 *    Copyright: Copyright (c) 2013 Chip
 *               All Rights Reserved
 *    Source: 1/5/13
 *    Notes: This mark is intended to be a reward for defeating Master Chief, as
 *    well as being something to show off for doing such. I want to also
 *    add some sort of special effect like improved detox or natural regen.
 *    Change History:
 */
 
inherit "obj/treasure";
#include "/players/chip/ansi.h"

reset(arg) {
   if(arg) return;
   set_alias("cortana");
   set_long("You have "+GRN+"Master Chief"+NORM+"'s armor helm upon your head. Projecting\n"+
            "from the side onto your shoulder is "+CYN+"Cortana"+NORM+", your personal guide\n"+
            "in your missions. Wear it with pride, new Spartan! Do not fail the UNSC!\n");
   set_weight(0);
   set_dest_flag(1);
}

extra_look()
 {
  if(this_player()==environment()) {
    return "You have "+GRN+"Master Chief"+NORM+"'s armor helm upon your head"; }
  else {
    return capitalize(environment()->query_name())+" has "+GRN+"Master Chief"+NORM+"'s helmet, and "+CYN+"Cortana"+NORM+" on "+environment()->query_possessive()+" shoulder";  }
}

query_auto_load() { return "/players/chip/closed/other/HALO/chief_reward.c:"; }

status id(string arg) { return ( arg == "cortana" || arg == "helm" || arg == "chief helm" ||
                                 arg == "halo" || arg == "microchip"); }

get(){ return 1; }
drop(){ return 1; }

