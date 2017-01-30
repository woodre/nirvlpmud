#include "/obj/ansi.h"
inherit "/players/vertebraker/closed/std/room";
#define tp this_player()
#define tpn this_player()->query_name()
#define tprn this_player()->query_real_name()

reset(int arg)
{
   if(arg) return;
   set_light(1);
   set_short(BOLD+"A"+CYN+" Happy"+YEL+" Place"+NORM);
   set_long(
        "  As you look around you realize you are in an entrance room.\n"+
        "There are a couple of places you can go from this room. As you\n"+ 
        "look around you notice a light fog fills the room making it more\n"+
        "difficult to see.\n\n"+
   BOLD+"                            Park\n"+
        "                             Forest"+BLK+"\n"+
        "                             Circle"+NORM+"\n\n");
   add_item("fog","A light fog that swirls around you");
   add_exit("/room/south/sforst22.c","climb");
}

init(){
  ::init();
   add_action("park", "park");
   add_action("forest", "forest");
   add_action("circle", "circle");
    }

park(){
    write("You say 'park' and disappear into the fog!\n");
    this_player()->move_player("into the fog#players/fred/SP/Rooms/r1.c");
    return 1; }


forest(){
    write("You say 'forest' and disappear into the fog!\n");
    this_player()->move_player("into the fog#players/fred/forest/Rooms/vill_1.c");
    return 1; } 

circle(){
   write("You say 'circle' and disappear into the fog!\n");
   this_player()->move_player("into the fog#players/fred/mages/rooms/entrance.c");
   return 1; }
