/*
 *      File:                   agem.c
 *      Function:               barter item for fire elementals
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "obj/treasure";
id(str){return (::id(str) || str == "quartz" || str == "blue quartz" || str == "air gem" || str == "Blue quartz" || str == "Blue Quartz");} 
reset(arg){
  if(arg) return;
  set_id("gem");
  set_alias("Gem");
  set_short(HIC+"Blue Quartz"+NORM);
  set_long(HIC+"An air elemental's heart, this transparent gem is a large\n"+
               "single crystal.  It would be quite valuabe to someone who\n"+
               "was interested in the magics of nature.\n"+NORM);
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
      "Jahira says: \"Another gem!  I can use this in my magic.\"\n"+
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
