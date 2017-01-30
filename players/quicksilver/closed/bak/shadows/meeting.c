#include "/players/blue/closed/lib/shadsecure.h"
inherit"/room/room.c";

reset(arg) {

   if(arg) return;


   set_light(1);
   short_desc = "The Shadow Meeting Room";
   long_desc = "Your eyes quickly adjust to the dark lighting....\n"+
"You are in a large room, with a high gothic ceiling arching far over"+
"head.\nEverything is made of a deep read granite, with fine engravings "+
"detailing\nbeautiful people and objects.  The floors are covered with fine"+
" rugs, and\ncouches are placed generously throughout the room.\n";

  dest_dir = ({
      "/room/shop","shop",
      "room/post","mail",
       "/players/catwoman/tl", "lockers",
      "/players/blue/closed/shadow/rooms/advance.c","west",
      "/players/blue/closed/shadow/rooms/east.c","east",
      "/room/plane2", "leave",
      "/room/church","church"
});

      move_object(clone_object("/players/blue/closed/shadow/obj/board"),
      this_object());
}


init() {
   ::init();
   add_action("move_north","north");
filter_room();
}

move_north(str) {
   object mark;
   if(str) return;
   mark = present("shadow-mark",TP);
   if(mark->query_shlevel() < 13) {
      write("That room is only for the commanders.\n");
      return 1;
   }
   TP->move_player("north#players/blue/closed/shadow/rooms/comm_room.c");
   return 1;
}
