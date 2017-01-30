#include "/players/mythos/closed/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("poster");
  set_short("A Poster depicting a new "+BOLD+"HIGH"+NORM+" level area");
  set_long("You see a new area 1s and all the way\n"+
    "east of the church. There is a HIGH level area\n"+
    "which exists in the land of Ancient Japan.  Pass \n"+
    "the wall, go Ancient, and enter the rice fields to\n"+
    "get to the forest.[another way is to goportal, empire]\n"+
    "Or you may type "+RED+"EMPIRE"+NORM+" (in capitals) and be \n"+
    "trasported there (you must be here, near the poster).\n"+
    "Look at everything- for much is hidden.\n");
set_weight(1000000);
  set_value(0);
}

init() {
  ::init();
  add_action("tele","EMPIRE");
  }
  
tele() {
string realm;
realm=call_other(environment(this_player()),"realm",0);
  if(realm == "NT") {
  write("Nothing happens...\n"); return 1;}
  tell_room(environment(this_object()),capitalize(this_player()->query_name())+
             " is teleported to the the Far Eastern Empire- ANCIENT JAPAN.\n");
  tell_object(this_player(),"You are moved to the Far Eastern Empire- \n"+
                             "            ANCIENT JAPAN!\n\n\n");
  this_player()->add_spell_point(-40);
  move_object(this_player(),"/players/mythos/aroom/path1.c");
  command("l",this_player());
  return 1;}
