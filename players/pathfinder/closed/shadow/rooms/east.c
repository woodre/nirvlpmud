/*east.c*/
#include "/players/blue/closed/lib/basic.h"
 
inherit "room/room";
 
reset(arg) {
   if(!arg) {
 
   short_desc = "Shadow Equipment Room";
   long_desc =
"You are in a medium sized room, with a deep burgundy carpet and several\n"+
"comfortable couches.  There is a lot of floor space here, so it could be a \n"+
"good place to drop any extra equitment you have so that other Shadows could\n"+
"use it.\n";
 
 
  dest_dir = ({"/players/pathfinder/closed/shadow/rooms/meeting", "west"});
   }
}
 
init() {
   ::init();
   filter_room();
}
 
filter_room() {
   object ob, tmp;
   ob = first_inventory(TO);
   while(ob) {
      tmp = next_inventory(ob);
      if(ob->is_player()) {
      if(ob&&!present("shadow-mark",ob)) {
         tell_room(this_object(), capitalize(this_player()->query_name())+
                  " tries to enter the room, but fails.\n");
         tell_object(ob, "The Master Shadow tells you: You do not belong here.  BEGONE!\n");
         move_object(ob, "/room/church");
      }
   }
      ob = tmp;
   }
   return 1;
}
