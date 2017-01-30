/*meeting.c*/
#include "/players/blue/closed/lib/basic.h"
inherit"/room/room.c";
 
reset(arg) {
 
  if(!present("board")) {
    move_object("/players/pathfinder/closed/shadow/obj/board",this_object());
  }
  if(!present("machine"))
  {
    move_object(clone_object("/players/emerson/obj/pin.c"), this_object());
  }
 
  if(arg) return;

   set_light(1);
   short_desc = "The Shadow Meeting Room";
   long_desc = "Your eyes quickly adjust to the dark lighting....\n"+
"You are in a large room, with a high gothic ceiling arching far overhead.\n"+
"Everything is made of deep red granite, with fine engravings detailing\n"+
"beautiful people and objects.  The floors are covered with fine rugs, and\n"+
"couches are placed generously throughout the room.\n";
 
  dest_dir = ({
      "/room/church","church",
      "/room/shop","shop",
      "room/post","mail",
      "/players/catwoman/tl", "lockers",
      "/players/boltar/hotel/hotel", "hotel",
      "/players/boltar/sprooms/daycare", "daycare",
    "/players/pathfinder/closed/shadow/rooms/advance", "west",
    "/players/pathfinder/closed/shadow/rooms/east", "east",
    "/players/blue/closed/shadow/rooms/meeting", "oldguild",
      "/players/pathfinder/detroit/rooms/entrance", "exit",
});
/*
 
      move_object(clone_object("/players/pathfinder/closed/shadow/obj/board"),
      this_object());
*/
}
 
init() {
   ::init();
   add_action("move_north","north");
   filter_room();
}
 
filter_room() {
   object ob, tmp;
   ob = first_inventory(TO);
   while(ob) {
      tmp = next_inventory(ob);
      if(ob->is_player()) {
      if(ob&&(ob->query_guild_name()!="shadow" && ob->query_level() < 20)) {
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
 
move_north(str) {
   object mark;
   if(str) return;
   mark = present("shadow-mark",TP);
   if(mark->query_shlevel() < 9) {
      write("That room is only for the commanders.\n");
      return 1;
   }
  TP->move_player("north#players/pathfinder/closed/shadow/rooms/comm_room.c");
   return 1;
}
