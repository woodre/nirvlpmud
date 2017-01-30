#include "/players/quicksilver/666/include/std.h"

inherit ROOM;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_light(1);
   set_short("St. Colman's Cathedral");
   set_long("St. Colman's Cathedral is an exquisite gem of neo-Gothic architecture by the\n"+
   "architects Pugin and Ashlin.  It took 47 years to build, starting in 1868.\n"+
   "Looking around, you see a large pipe organ, its numerous pipes spanning the\n"+
   "front of the wall.  You are awed by the vastness of the cathedral as you\n"+
   "glance around.\n"+
   "Being here in Cobh Cathedral is a moving spiritual experience.  The gothic\n"+
   "grandeur of the interior, the delicate carvings, the beautiful arches and the\n"+
   "mellow lighting combine to lift the human spirit.  The carvings recall the\n"+
   "history of the Church in Ireland from the time of St. Patrick to the present\n"+
   "century.  It is the story of faith earthed in the story of the people.");
   add_item("organ", "The Cathedral organ, by Telford and Telford, contains 2,468 pipes.  It is\n"+
   "only logical that the Cathedral is a regular venue for recitals by choirs\n"+
   "from all parts of the world.");
   add_item("carvings", "The carvings in the walls of the Cathedral relate the history of both the\nChurch of Ireland, and the names of the former bishops of the Cloyne diocese.");
   add_item("walls", "The carvings in the walls of the Cathedral relate the history of both the\nChurch of Ireland, and the names of the former bishops of the Cloyne diocese.");
   add_item("engravings", "The carvings in the walls of the Cathedral relate the history of both the\nChurch of Ireland, and the names of the former bishops of the Cloyne diocese.");
   add_exit("room/church", "church");
   add_exit("players/quicksilver/closed/wedding/r/ballroom",  "ballroom");
}

init() {
   ::init();
   add_action("start","start");
   add_action("hitit","hitit");
}

start() {
tell_room(this_object(), "Bishop Magee enters and clears his throat.\nA light tune comes forth from the massive organ.\n");
move_object(clone_object("players/quicksilver/closed/wedding/cre/magee.c"),this_object());
return 1;
}

hitit() {
tell_room(this_object(), "Bishop Magee nods slightly, and the organ fills the room with the wedding\nmarch.\n");
return 1;
}

