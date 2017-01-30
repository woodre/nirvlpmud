#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short("This is the short");
   set_long("This is the description.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "room/post.c", "out"});
   move_object(clone_object("/players/puppy/EX/mob.c"), this_object());
   return 1; }
