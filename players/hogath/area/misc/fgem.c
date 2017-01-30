/*
 *      File:                   fgem.c
 *      Function:               barter item for fire elementals
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 11/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "obj/treasure";
id(str){return (::id(str) || str == "garnet" || str == "Garnet" || str == "fire gem");} 
reset(arg){
  if(arg) return;
  set_id("gem");
  set_alias("Gem");
  set_short(HIR+"Garnet"+NORM);
  set_long(HIR+"A general class of crystals, it is isometric in shape and.\n"+
               "warm to the touch.  Once an integral part of the magical\n"+
               "animation of a fire elemental, it would fetch quite a reward\n"+
               "if bartered to the right person\n"+NORM);
  set_weight(1);
}


init(){
  ::init();
  add_action("cmd_barter","barter");
}

cmd_barter(str){
  if(id(str)){
    if(present("jahira",environment(tp))){
      tell_room(environment(tp),
      "Jahira says: \"Another gem! I can use this in my magic.\"\n"+
      "Jahira gives "+tpn+" "+value+" coins.\n");
      tp->add_money(value);
      tp->add_wieght(-1);
      destruct(to);
      return 1;
    }
  }
  else {notify_fail("What were you trying to barter?\n");
  return 1;}
}
