/*
 *      File:                  .c
 *      Function:               
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

reset(arg) {
  if(arg) return;
  set_id("horns");
  set_alias("Horns");
  set_short("Thornhead's Horn");
  set_long("This is the horn off off a Thornhead Demon.  It\n"+
           "should fetch quite a reward if bartered to the \n"+
           "right person.\n");
  set_weight(2);
  set_value(5000+random(1000));
}

init() {
  add_action("cmd_barter","barter");
}

cmd_barter(str){
  if(id(str)){
    if(present("jahira",environment(this_player()))){
      write("Jahira smiles and gives you"+value+" coins for the horn.\n"+
            "There is one less demon to torture the forest now, huzzah.\n");
      tp->add_money(value);
      tp->add_weight(-2);
      destruct(to);
      return 1;
    }
    notify_fail("Eh?  What did you want to barter?\n");
}
}
