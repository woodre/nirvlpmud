#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(""+HIK+"A dark castle"+NORM+"");
   set_long(
      "The castle walls appear to made totally of stone.  A large\n"+
      "table stands directly in the center of the room.  Atop the\n"+
      "table are many experiments bubbling with dark blue fluids.\n"+
      "An opening in the center of the room allows one to glimpse\n"+
      "some dark storm clouds above.\n");
   set_light(0);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "A musty odor is in the air");
   items = ({
         "castle walls", "Large boulders arranged to form this structure",
         "tubes", "Glass containers that hold the dark blue fluid",
         "walls", "Large boulders arranged to form this structure",
         "stone", "Large boulders arranged to form this structure",
         "large table", "A cluttered oak table",
         "dark blue fluids", "Bubbling fluids that flow through the tubes", 
         "blue fluids", "Bubbling fluids that flow through the tubes",
         "fluids", "Bubbling fluids that flow through the tubes",
         "table", "A cluttered oak table",
         "opening", "A hole in the ceiling that allows you a view of the sky",
         "dark storm clouds", "A large gray mass that is drawn to the castle",
         "storm clouds", "A large gray mass that is drawn to the castle",
         "clouds", "A large gray mass that is drawn to the castle",
         "sky", "The area above the castle that is gettng darker by the minute",
         "experiments", "Lots of bottles and tubes bubbling with blue fluids"});
   dest_dir = ({
         "/players/puppy/s/rm/27.c", "out"});
   move_object(clone_object("/players/puppy/s/mob/gargamel.c"), this_object());
   return 1; }
