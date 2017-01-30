/*
 *      File:                   shard.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  1 in 100 chance for drop from
                                elemental, bring 4 to jahira with
                                the pommel and she will make a sword
                                of elemental slaying for you.
 *      Change History:         
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"

inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
  
  set_name("Shard");
  set_alt_name("shard");
  set_alias("dagger");
  set_short(HIW+"Broken Shard"+NORM);
  set_long("Jagged and broken, this shard looks like it was once\n"+
           "part of a noble blade.\n");
  set_class(10);
  set_value(100);
  set_hit_func(this_object());
}

weapon_hit(attacker){
  int W;
  W = random (10);
  if(W > 9)
  say(tpn+"' s shard "+HIY+" glows"+NORM+" brightly as it pierces "+atn+".\n");
  write("The shard "+HIY+" glows"+NORM+" brightly in your hand.\n");
  return 2;
}
