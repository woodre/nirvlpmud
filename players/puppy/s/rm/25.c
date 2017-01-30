#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(""+HIB+"The Smurfship"+NORM+"");
   set_long(
      "Many levers and buttons stick out from the console.  The ship's\n"+
      "walls are made of wood and have been smoothed out to remove\n"+
      "any imperfections.  Two seats in the center of the room provide\n"+
      "a perfect view through the main window at the front of the ship.\n");
   set_light(1);
   add_listen("main", "You hear the low rumbling of the ships engines.\n");
   add_smell("main", "You smell nothing special.");
   items = ({
         "console", "The main controls",
         "walls", "Smooth wooden walls of the ship",
         "two seats", "Captain's chairs sit behind the console", 
         "seats", "Captain's chairs sit behind the console", 
         "wood", "The smooth surface that makes up the walls of the ship",
         "main window", "A large opening in the front of the ship",
         "window", "A large opening in the front of the ship",
         "levers", "Controls to the spaceship",
         "buttons", "Controls to the spaceship"});
   dest_dir = ({
         "/players/puppy/s/rm/24.c", "out"});
   move_object(clone_object("/players/puppy/s/mob/astro.c"), this_object());
   return 1; }

init()
{
   ::init();
   add_action("bbutton", "push"); 
   add_action("llever", "pull");
}

bbutton(str) {
   if(!str){ notify_fail("What are you trying to push?\n"); return 0; }
   if(str == "button" || str == "buttons")  {
      write("You push one of the many buttons and nothing happens.\n");
      say(this_player()->query_name()+ " pushes some of the buttons but nothing happens.\n");
      return 1; }
}

llever(str) {
   if(!str){ notify_fail("What are you trying to pull?\n"); return 0; }
   if(str == "lever" || str == "levers")  {
      write("You pull some of the levers and nothing happens.\n");
      say(this_player()->query_name()+ " pulls some of the levers but nothing happens.\n");
      return 1;   }
}
