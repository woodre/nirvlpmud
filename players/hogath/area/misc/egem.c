/*
 *      File:                   egem.c
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
id(str){return (::id(str) || str == "Hematite" || str == "hematite" || str == "earth gem");} 
reset(arg){
  if(arg) return;
  set_id("gem");
  set_alias("Gem");
  set_short(HIK+"Hematite"+NORM);
  set_long(HIK+"Shiney and black, this gem was then center of power for an\n"+
               "earth elemental, and is all that remains from it's powerful\n"+
               "form.  It would fetch quite a reward if you found the right\n"+
               "person to barter it too.\n"+NORM);
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
