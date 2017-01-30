inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

string my_color;

reset(arg)
{
   ::reset(arg);
   if(arg) return;
   my_color = get_random_color();

   set_get(0);
   set_short("A gigantic pancake of dirt");
   set_long("This appears to be a gigantic pile of dirt. However you notice that\n"+
            "there is something uniquely different about it. There is something scribbed\n"+
            "into the dirt that appears to be faintly readable text as you pull closer.\n");
   set_name("dirt");
   set_alias("pancake");
   
   set_read("You can barely make it out, but it appears that you can 'cling' to the dirt.\n");
   set_smell("The pancake smells like... dirt.\n");
   set_taste("The pancake tastes like... dirt.\n");
}

init()
{
    ::init();
    add_action("on_cling","cling");
}

on_cling(str)
{
   if(this_player()->query_level() < 12)
   {
      write("This might not be a good idea for you. You sense that you might get killed in there.\n");
      return 1;
   }
   this_player()->move_player("into the warp#/players/mizan/etheriel/subrealms/h2_dealership/entrance.c");

   write_file("/players/mizan/logs/SUBREALM_H2_DEALERSHIP", (this_player()->query_real_name() + " has found the dealership on " + ctime() + "\n"));   
   
   return 1;
}