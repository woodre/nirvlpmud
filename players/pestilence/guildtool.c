#include "/players/pestilence/define.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("guild name");
  set_alias("tool");
  set_short("Guild name changer");
set_long(
"Changes your guild name.\n");
  set_value(500);
  set_weight(2);
}


init () {
   ::init() ;
     add_action ("set_guild","set_guild");
     }

    set_guild(str){
    USER->set_guild_name("Dark Order");


    write("You changed your guild name.\n");
    say(USER->query_name() +" has a new guild name\n");
      destruct(this_object());
     return 1;
}
