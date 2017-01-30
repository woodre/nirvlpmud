inherit "/room/room.c";
object app;

void reset(int arg) 
{
   if(!app)
   {
         app = clone_object("/players/mizan/etheriel/subrealms/alchcave/beasties/hydra-passive.c");
         move_object(app, this_object());
      
   }

   if(arg) return;
   set_light(0);
   
   short_desc = "The Frag Pit";

   long_desc =
   "    Descending into this fetid cavern, you realize that the rock walls\n"+
   "  are completely gummy from the various dried mush that was once a living\n"+
   "  creature of some sort. It squishes with an uneasy noise as you step\n"+
   "  but somehow you feel that is the least of your concerns at the moment.\n";
   
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d7.c", "up",
  });
}

