#include "../define.h"

inherit ROOM;

reset(arg) {
  if(!present("student_guard", this_object())){
   move_object(clone_object("/players/guilds/warriors/mobs/guard"), this_object());
   move_object(clone_object("/players/guilds/warriors/mobs/guard"), this_object());
   }
   if(arg) return;
   set_light(1);
   set_short("Hall of the Warriors");
   set_long(
   "  This is a circular chamber made of pure silver marble. Pillars, carved\n"+
   "to look like giant minotaurs, stand as giant guardians supporting the\n"+
   "domed ceiling overhead. A golden door leads east to the library of the\n"+
   "Warriors, and a silver stairway leads down to the training grounds of\n"+
   "the hall or up to the Masters chambers. An archway leads south back to\n"+
   "the entry hall.\n");
   add_property("NT");
   add_item("marble",
   "A silver marble that is polished to a high sheen");
   add_item("pillars",
   "Huge pillars shaped into the sixteen foot tall figures of minotaurs. They\n"+
   "seem to almost strain under the weight of the dome overhead");
   add_item("dome",
   "A huge stone dome that is held up by four pillars");
   add_item("door",
   "A golden door that leads to the library");
   add_item("stairway", 
   "A silver stairway that leads down to the lower training grounds or up to the\n"+
   "Master's chambers");
   add_item("archway",
   "A marble archway that leads to the entry hall");
   add_exit(ROOMS+"sc1","south");
   add_exit(ROOMS+"sc3","east");
   add_exit(ROOMS+"sc4","up");
   add_exit(ROOMS+"sc6","down");
   }

init(){
 ::init();
 add_action("nogo","down", 1);
 }

nogo(){
if(!present("prof_guild_object", this_player())){
write("The guard stops you from going downstairs.\n");
return 1;
}
return;
}


okay_follow() { return 1; }
query_no_fight() { return 1; }
