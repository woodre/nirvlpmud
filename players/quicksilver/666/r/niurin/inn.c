#include "/players/quicksilver/666/include/std.h"

inherit ROOM;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_light(1);
   set_short("Kione y Chollagh Vuc");
   set_long("   As you glance around the room with your back to the door, your senses are\n"+
   "flooded with the sights and smells of Niurin's finest inn.  All around,\n"+
   "people are dining and chatting.  Serving wenches seem to glide across the\n"+
   "establishment's finely polished wooden floors, carrying food and drink from\n"+
   "table to table.\n"+
   "   Tables are spread throughout the room for dining and socializing.  To the\n"+
   "far west, there is a desk from which you could inquire about lodging, or\n"+
   "possibly seek the near infinite wisdom of the innkeeper.\n"+
   "   The main street of Niurin lies through the door to the east.");
   add_item("wenches", "The serving wenches appear youthful and buxom, all adorned with fine dresses.");
   add_item("serving wenches", "The serving wenches appear youthful and buxom, all adorned with fine dresses.");
   add_item("wench", "There really aren't any wenches close enough for you to single out a particular one.");
   add_item("serving wench", "There really aren't any wenches close enough for you to single out a particular one.");
   add_item("tables", "There really aren't any tables close enough for you to single out a particular one.");
   add_item("table", "There really isn't a table close enough for you to examine.");
   add_item("floor", "Don't you have anything more interesting to do than look at the floor?  If you\nmust know, it is a wood floor.");
   add_item("door", "Don't you have anything more interesting to do than look at the door?  If you\nmust know, it is a wooden door.");
   add_exit(ROOM_DIR+"niurin/inn_ne", "north");
   add_exit(ROOM_DIR+"niurin/inn_se", "south");
   add_exit(ROOM_DIR+"niurin/main1",  "east");
   add_exit(ROOM_DIR+"niurin/inn_w",  "west");
}

init() {
   ::init();
}
