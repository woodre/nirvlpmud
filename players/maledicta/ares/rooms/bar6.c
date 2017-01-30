/*   Bar Area-  Maledicta [01.06.01] */

#include "../define.h"
inherit ROOM;

reset(arg) {
if(!present("patron", this_object())){
   MO(CO("/players/maledicta/ares/mobs/bpatron"), this_object());
 if(!random(2)) MO(CO("/players/maledicta/ares/mobs/bpatron"), this_object());
   }
   if(arg) return;
   set_short("The Dangerous Blade [Bar]");
   set_light(1);
   set_long(
"   This is the southeast corner of the bar.  Here you find a few\n"+
"tables scattered around and a large window that has been boarded\n"+
"up. To the west is the bar and to the north and west is the \n"+
"entrance to the Dangerous Blade.\n");
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
      "window",
      "A large window that has been boarded up due to its use as a door\n"+
      "during the many fights that break out here");
   add_item(
      "boards",
      "Large wooden boards that have been nailed to the wall to block off\n"+
      "the window\n");
   add_item(
      "ceiling",
      "The ceiling is made of large wooden beams and is very low");
   add_item(
      "air",
      "A thick odorous air that makes you want to crawl on the floor to\n"+
      "avoid its pungent sickness. You especially have trouble breathing\n"+
      "so close to the fire");
   add_exit(ROOMS+"bar3","north");
   add_exit(ROOMS+"bar4","west");
   set_chance(8);
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("You hear the sounds of people chatting at the tables.");
   add_msg("The sound of breaking glass can be heard nearby.");
   add_msg("The sounds of an argument can be heard somewhere in a corner.");

   }

