#include "/players/mythos/closed/guild/def.h"

inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(-2);
    short_desc = "DARKNESS";
    long_desc =
    "You enter a cave of immense size.  "+CYN+"Ice"+NORM+" lines the walls and\n"+
    "ceiling.  It is cold here... extremely cold.  A cold light\n"+
    "eminates from within the ice.\n";
  items = ({
    "north","Darkness....",
    "east","Darkness....",
    "south","Darkness....",
    "west","Darkness....",
    "ice","Perhaps you may wish to touch it...",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/cave.c", "out",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    if(!pp) { 
       tell_object(tp,"Something flashes and you are thrown out of the caves!\n");
        tp->heal_self(-1000);
        move_object(tp,"/players/mythos/closed/guild/forest/rooms/cave.c");
        return 1;}
   add_action("touch","touch");
   add_action("chip","chip");
}

touch(str) {
  if(!str) return 0;
  if(str == "ice" || str == "light") {
    write("Something whispers: Chip the ice to begin the transfer.\n"+
          "                    But know that once you begin you must\n"+
          "                    end it to get out.  Be wary.\n");
  return 1;}
}

chip(str) {
  if(!str) return 0;
  if(str == "ice") {
    write("You suddenly feel cold.\n");
    tp->move_player("light#players/mythos/closed/guild/task/horlach/home");
  return 1;}
  else {
    write("A voice screams in pain!\n");
    tp->zap_object(tp);
    return 1; 
  }
return 1; }