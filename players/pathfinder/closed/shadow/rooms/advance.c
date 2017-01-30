/*advance.c*/
#include "/players/blue/closed/lib/basic.h"
inherit "/room/room.c";
 
reset(arg) {
 
   if(arg) return;
 
   set_light(1);
   short_desc = "Shadow Advancement Room";
   long_desc = "It is so dark in here your eyes can barely make out anything.\n"+
"This is a small room, completely empty except for a strange black orb\n"+
"floating against the far wall.\n";
 /*
 
    if(!present("shadow-mark", this_object()))
      move_object(clone_object("/players/pathfinder/closed/shadow/shadow.c"),
         this_object());
 */
   dest_dir = ({
      "/players/pathfinder/closed/shadow/rooms/meeting.c","east",
   });
 
 
   if(!present("orb", this_object())) {
    move_object(clone_object("/players/pathfinder/closed/shadow/obj/black_orb"),
             this_object());
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
      if(ob&&!present("shadow-mark",ob)&&ob->query_level() < 20) {
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
