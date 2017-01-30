#include "/players/guilds/shadow/shadow_lib/color.h"

#define DEST find_object("/room/plane2")

id(str) { return str=="pool"; }
short() { return BOLD+"A Pool of Darkness"+NOSTYLE; }
long() {
   write("This is the entrance to the Shadow Guild.\n");
   write("To enter the pool, type 'enter pool'.\n");
}
get() { return 0; }
drop() { return 1; }
value() { return 0; }
weight() { return 100000; }

reset(arg) {
  
   if(!arg) {

   
   if(!present("pool",DEST)) {
      move_object(this_object(),"/room/plane2");
   }
   }
}

init() {
   add_action("enter_pool","enter");
}

enter_pool(str) {
   if(str !="pool") return;
   write("You enter the guild of the Shadows.\n");
   say(capitalize(this_player()->query_name())+" enters the pool.\n");
   this_player()->move_player("pool#players/guilds/shadow/rooms/guild_"+
           "enter.c");
   say(capitalize(this_player()->query_name())+" arrives.\n");
   return 1;
}
