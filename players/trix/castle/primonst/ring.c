#if 0 /* Rumplemintz */
#include "/open/ansi.h"
#else
#include <ansi.h>
#endif
/* 2005.08.12 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/players/forbin/closed/bfeq.c";

reset(arg){
   if(arg) return;
   ::reset(arg);
set_short(HIY+"B"+NORM+"ishop's "+HIY+"R"+NORM+"ing");
   set_long("You are looking at a wonderful gold made ring , symbolizing the power of the \n"+
      "Catholic church , and you are sure it is a great protection against danger.\n");
   set_ac(2);
   set_weight(1);
   set_value(1000);
   set_alias("ring");
   set_params("other|evil", 1, 5, "do_spec");
   set_name("ring");
   set_type("ring");
  set_bf_guild_bonus(5, 5);
}

do_spec(object owner){
    if(!random(5)){
      tell_object(owner, 
      "The ring glows as it resists the evil before it!\n");
      return 0501;
      }
return 0;
}
