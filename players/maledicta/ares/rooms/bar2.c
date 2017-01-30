/*   Bar Area-  Maledicta [01.06.01] */

#include "../define.h"
inherit ROOM;

reset(arg) {
if(!present("patron", this_object())){
   MO(CO("/players/maledicta/ares/mobs/bpatron"), this_object());
  if(!random(4)) MO(CO("/players/maledicta/ares/mobs/bpatron"), this_object());
   }
   if(arg) return;
   set_short("The Dangerous Blade [Bar]");
   set_light(1);
   set_long(
"  You now stand in the northwest corner of the bar. From here you get\n"+
"a bad view of the rest of the room through the smoke filled air. There\n"+
"are several tables here with wooden chairs gathered around them. The\n"+
"entrance is to the east, with the main bar standing to the southeast. A\n"+
"fireplace stands to the south.\n");
   add_item(
      "tables",
      "Large wooden tables that are crudely crafted and are probably\n"+
      "deemed of 'throwaway' quality");
   add_item(
      "chairs",
      "Simple wooden benches that are made of poor quality wood. Most\n"+
      "of them look as though they have been put together hurriedly and\n"+
      "are designed to be thrown away");
   add_item(
      "bar",
      "A large wooden bar that spans the back of the room. From there\n"+
      "you may be served");
   add_item(
      "fireplace",
      "A large stone fireplace that spits out a small amount of heat and\n"+
      "just enough smoke to make the air thick");
   add_item(
      "ceiling",
      "The ceiling is made of large wooden beams and is very low");
   add_item(
      "air",
      "A thick odorous air that makes you want to crawl on the floor to\n"+
      "avoid its pungent sickness");
   set_chance(12);
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("The sound of breaking glass can be heard nearby.");
   add_msg("The sounds of an argument can be heard somewhere in a corner.");
   add_exit(ROOMS+"bar1","east");
   add_exit(ROOMS+"bar5","south");
   }

