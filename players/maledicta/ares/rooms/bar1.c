/*   Bar Area-  Maledicta [01.06.01] */

#include "../define.h"
inherit ROOM;

reset(arg) {
  if(!present("patron", this_object())){
   MO(CO("/players/maledicta/ares/mobs/bpatron"), this_object());
   MO(CO("/players/maledicta/ares/mobs/bpatron"), this_object());
   }
   if(arg) return;
   set_short("The Dangerous Blade [Bar]");
   set_light(1);
   set_long(
"  You stand in the entranceway of the Dangerous Blade, the\n"+
"most notorious bar in all of New Ares.  Here you see several\n"+
"tables and chairs scattered about the main hall with a large\n"+
"wooden bar spanning the southern end of the room.  A stone\n"+
"fireplace stands along the western wall. The ceiling is low\n"+
"and a light smoke dims the air.\n");
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
   add_msg("A customer enters and moves past you to the bar.");
   add_msg("A customer shoves past you and exits the bar.");
 
   add_exit(ROOMS+"city22","out"); 
   add_exit(ROOMS+"bar2","west");
   add_exit(ROOMS+"bar3","east");
   add_exit(ROOMS+"bar4","south");
   }

init(){
  ::init();
  add_action("woo", "out");
  }

woo(){ 
write("\n\nYou leave the bar and travel down the alley back to the main road...\n\n");
return;
}