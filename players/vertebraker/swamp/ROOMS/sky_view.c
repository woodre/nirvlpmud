#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Above the SwampLands");
   set_long(
"     You are atop a massive tree, looking out over the horizon.\n"+
"You can \"gaze\" at anyone in the vicinity, or \"roar\" out a message\n"+
"for anyone else in the swamp to hear...\n");
   add_exit(ROOMS+"s45","down"); }

init() {
   ::init();
   add_action("gaze","gaze");
   add_action("roar","roar"); }

gaze(str) {
   string where, blah;
   object ob;
   if(!str) {
      write("Gaze at who?\n");
      return 1; }
   ob = find_player(str);
   if(!ob) {
      write("You don't see them in the Swamp...\n");
      return 1; }
   if(ENV(ob)) ob = ENV(ob);
   where = file_name(ob);
   if(!ob->query_swamp()) {
      write("You don't see them in the Swamp...\n");
      return 1; }
   move_object(TP,ob);
   write("You look into the area....\n");
   command("look",TP);
   move_object(TP,TO);
   return 1; }

roar(str) {
   int x; string *rooms;
   object room;
   if(!str) {
      write("Roar what out to the SwampLands?\n");
      return 1; }
   rooms = get_dir("/players/vertebraker/swamp/ROOMS/");
   for(x=0;x<sizeof(rooms);x++) {
      room = find_object(rooms[x]);
      if(!room) room = "/players/vertebraker/swamp/ROOMS/"+rooms[x]+"";
      if(!room) room = find_object(room);
      if(room->query_swamp())
         tell_room(room,"A voice calls out, "+BOLD+str+NORM+"\n");
   }
   write("You scream out into the SwampLands, "+BOLD+str+NORM+"\n");
   return 1; }

