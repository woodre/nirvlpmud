#include "/players/khrell/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short("Cave Entrance");
   set_long("   This wide opening has been crudely chiseled and worked\n\
      in a rough manner.  Poorly made support beams frame the\n\
      tunnel and appear to be an attempt to keep any cave-ins from\n\
      crushing any who dare to walk though this area. The stink of\n\
      urine and fecal matter assails your senses and threatens to \n\
      make you sick\n");
   set_light(1);
   add_listen("main", "You hear nothing except your own heartbeat..\n");
   add_smell("main", "You smell the rank stale fetid air of the cave.\n");
   items = ({
         "beams", "Many crude and poorly cut and shaped beams of poor design."});
   dest_dir = ({
         "players/khrell/area/goblins/gobrm2", "north"});
   move_object(clone_object("/players/khrell/monster/goblins/gobmob.c"), this_object());
   return 1; }

/* additions by mizan */
init()
{
   ::init(); 
   /* calls our super */
   
   add_action("go_north","north");
   add_action("go_north","n");
}

go_north()
{
   if(!this_player()) return;
   if(this_player() && this_player()->is_player())
      return 0;
   else
      return 1;
}
