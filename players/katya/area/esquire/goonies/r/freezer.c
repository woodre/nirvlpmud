/*
 *     freezer.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(!arg)
  { 

object ob;
  ob = clone_object("/players/katya/area/esquire/goonies/o/man.c");
move_object(ob,this_object());

   set_light(1);

   short_desc = "A Freezer";

   long_desc="\
  A large freezer that seems to be a good place to store diner meals.\n\
Many shelves sit on the walls of the freezer.  The scent of many \n\
different types of ice cream are all around.  The temperature in the\n\
freezer feels like it is below zero and seems to be a sneaky spot to\n\
hide a corpse.\n",

   items=({
     "freezer",
       "A large freezer that is rarely used",
     "diner meals",
       "The meals stored in the freezer all seem to have frost bite on them",
     "meals",
       "The meals stored in the freezer all seem to have frost bite on them",
     "shelves",
       "Many old metal shelves have been screwed to the freezer walls.",
     "walls",
       "The walls have a thin layer of ice on them",
     "wall",
       "The walls have a thin layer of ice on them",
     "ice cream",
       "Many different types of ice cream are on the shelves",
    });

   dest_dir=({
        "/players/katya/area/esquire/goonies/r/basement",  "out",
   });}

 }

   init()  {
   ::init();

   add_action("cmd_smell","smell");
   add_action("get","get");
   }

   cmd_smell(str) {
   write("You smell the scent of many different types of ice cream\n");
   return 1;
   }

   get(arg) {
     if(arg != "corpse") {
     notify_fail("The corpse is too heavy for you to pick up!\n");
     return 0;
     }
    write("The corpse is too heavy for you to pick up!\n");
    say(capitalize(this_player()->query_name())+" attempts to pick up the corpse, but fails.\n");
    return 1;
  }
