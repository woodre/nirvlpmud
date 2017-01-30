#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(""+BLU+"Papa Smurfs Workroom"+NORM+"");
   set_long(
      "This is a quiet place away from the rest of the village.  The\n"+
      "one window that is not covered in blue drapes faces directly\n"+
      "into the playground where Papa Smurf can keep an eye on the\n"+
      "Smurflings. There is a large workbench with a few experiments\n"+
      "in the center of the room and some bookcases against the\n"+  
      "side of the hut.  A stack of paper rests against one of the\n"+
      "legs to the workbench.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "window", "A window used to keep an eye on the Smurflings",
         "room", "The inside of Papa Smurf's  hut",
         "books", "Tons of refrence material for Papa Smurf to expand his mind with",
         "playground", "The grassy area that the Smurflings use to gather and share toys",
         "blue drapes", "Blue drapes made by Smurfette",
         "drapes", "Blue drapes made by Smurfette",
         "large workbench", "A workbench covered in experiments",
         "workbench", "A workbench covered in experiments",
         "experiments", "The secret creations of Papa Smurf",
         "side of the hut", "The walls of the mushroom that you are in",
         "hut", "The mushroom that you are in",
         "leg", "A piece of wood that helps to hold up the workbench",
         "legs", "Pieces of wood holding the workbench in place",
         "bookcases", "Shelves attached to the walls holding refrence books",
         "stack", "Papa Smurfs notes",
         "notes", "Papa Smurfs notes",
         "stack of paper", "Papa Smurfs notes",
         "paper", "Papa Smurfs notes"});
   dest_dir = ({
         "/players/puppy/s/rm/13.c", "out"});
   move_object(clone_object("/players/puppy/s/mob/papa.c"), this_object());
   return 1; }
