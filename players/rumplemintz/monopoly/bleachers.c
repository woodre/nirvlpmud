/* bleachers.c
* The Monopoly bleachers.  You can get here from the entrance (main)
*/

inherit "room/room";
#include "path.h"

reset(arg) {
   if(arg) return;
   
   set_light(1);
   short_desc="Monopoly Bleachers";
   long_desc="You are in the Monopoly Bleachers where you can listen in on\n"
   +"the games going on down below.\n"
   +"Commands:  games, mwho <gamename>, mi <player>, mshout <game> <what>\n";
   dest_dir = ({
         PATH+"main","down",
   });
}

init() {
   ::init();
   add_action("show_games","games");
   add_action("mwho","mwho");
  add_action("mlook","look");
  add_action("mlook","l");
  add_action("minventory","i");
  add_action("minventory","mi");
  add_action("mshout","mshout");
}

show_games() {
  MAIN->show_games();
  return 1;
}

mwho(arg) {
  return MBIN->m_mwho(arg);
}

mlook(arg) {
  return MBIN->m_look(arg);
}

minventory(arg) {
  if(!arg) return 0;
  return MBIN->m_inventory(arg);
}

mshout(arg) {
  string game,what;
  if(!arg || sscanf(arg,"%s %s",game,what)!=2)
    WRITE("Usage: mshout <gamename> <string>\n");
  what=this_player()->query_name()+" mshouts from the bleachers: "+what+"\n";
  MAIN->gameshout(what,game);
  return 1;
}

