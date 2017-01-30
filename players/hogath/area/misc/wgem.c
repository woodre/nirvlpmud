/*
 *      File:                   wgem.c
 *      Function:               barter item for water elementals
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
id(str){return (::id(str) || str == "water sapphire" || str == "Sapphire" || str == "sapphire" || str == "Water Sapphire");} 
reset(arg){
  if(arg) return;
  set_id("gem");
  set_alias("Gem");
  set_short(HIB+"Aquamarine"+NORM);
  set_long(HIB+"A hard, transparent form of beryl.  It chill surface has been\n"+
               "smoothed by the constant churning of the water elemental's insides.\n"+
               "It would fetch quite a reward if bartered to the right person.\n"+NORM);
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
