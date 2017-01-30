#include "../define.h"

inherit ROOM;

reset(arg) {
if(!present("student_master", this_object())){
  move_object(clone_object("/players/data/closed/wizard/mobs/master.c"), this_object());
  }
   if(arg) return;
   set_light(1);
   set_short("Hall of the Warriors");
   set_long(
   "You now stand in a large barren room. Along the walls are large\n"+
   "maps of the world and paintings of great wars. A single desk with\n"+ 
   "a high backed chair behind it stands in the center of the room. A\n"+
   "window towards the back of the room looks out over the plains. A\n"+
   "door stands to the south and leads back out to the hallway.\n");
   add_property("NT");
   add_item("door",
   "A wooden door that leads to the hallway");
   add_item("walls",
   "Plain stone walls with numerous maps and paintings on them");
   add_item("maps",
   "Large maps of the realm of Nirvana");
   add_item("paintings",
   "Paintings that display some of the greatest wars known to man");
   add_item("desk",
   "A simple desk that stands in the center of the room");
   add_item("chair",
   "A high backed chair that looks VERY uncomfortable");
   add_item("window",
   "A perfect view of the plains of Molasar");
   add_exit(ROOMS+"sc4","out");
   }

okay_follow() { return 1; }
query_no_fight() { return 1; }