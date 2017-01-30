/*   Bar Area-  jaraxle [01.06.01] */



#include "../define.h"

inherit ROOM;



reset(arg) {

  if(!present("DireThorne the Assassin")){

   MO(CO("/players/jaraxle/ares/mobs/direthorne.c"), this_object());

   }

   if(arg) return;

   set_short("The Dangerous Blade [Bar]");

   set_light(1);

   set_long(

"  This is the northeast corner of the Dangerous Blade. It is very\n"+

"dark here and you catch the faint smell of something strange. There\n"+

"are fewer tables gathered here and most of the patrons seem to flock\n"+

"to other parts of the room. The ceiling is even lower here than the\n"+

"rest of the bar and helps to bring the feeling of a cave. The entrance\n"+

"is to the west, and the bar is to the southwest.\n");

   add_item(

      "tables",

      "Large wooden tables that are crudely crafted and are probably\n"+

      "deemed of 'throwaway' quality. You notice there are fewer in\n"+

      "this area");

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

      "patrons",

      "A few scattered patrons that seem to inhabit this bar. They are\n"+

      "all lower class ruffians");

   add_item(

      "ceiling",

      "The ceiling is made of large wooden beams and it is almost dangerously\n"+

      "low here");

   add_item(

      "air",

      "A thick odorous air that makes you want to crawl on the floor to\n"+

      "avoid its pungent sickness");

   set_chance(5);

   add_msg("You hear the sounds of people chatting at the tables.");

   add_msg("You hear the sounds of people chatting at the tables.");

   add_msg("You hear the sounds of people chatting at the tables.");

   add_msg("You hear the sounds of people chatting at the tables.");

   add_msg("The sound of breaking glass can be heard nearby.");

   add_msg("Something small skitters over your feet and into the darkness.");

   



   add_smell("main", "You finally realize that smell is the coppery stench of blood.\n");



   add_exit(ROOMS+"bar1","west");

   add_exit(ROOMS+"bar6","south");

   }



