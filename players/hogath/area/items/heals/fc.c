/*
 *      File:                   fc.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  sp only heal
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "/obj/generic_heal.c";
void reset(int arg){
  ::reset(arg);
  if(arg) return;
  set_name("Faeries' Cauldron");
  add_alias("faerie's cauldron");
  set_short(HIC+"Faeries'"+NORM+BOLD+" Cauldron"+NORM);
  set_long(
  "This mushroom has captured some refreshing water which.\n"+
  "you may drink\n");
  set_type("water");
  set_msg("You sip refreshing water from the cauldron.\n");
  set_msg2(" sips water from the cauldron.\n");
  add_cmd("sip");
  add_cmd("drink");
  set_heal(0,50);
  set_charges(3);
  set_soak(3);
  set_stuff(3);
  set_value(600);
}

id(str) { return str == "cauldron" || str == "faerie cauldron" || str == "faeries' cauldron" || str == "Faerie Cauldron" || str == "Faerie_Cauldron" || str == "Faeries's Cauldron"  || str == "Faeries' Cauldron" || str == "faeries'_cauldron" || str == "water";} 
  
