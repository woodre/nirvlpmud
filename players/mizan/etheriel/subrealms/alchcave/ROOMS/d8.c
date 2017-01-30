inherit "/room/room.c";
object app;
int i;

void reset(int arg) 
{
   if(!app)
   {
      /* kludgey but works :) */
      i = 0;
      
      for(i = 0; i < 7; i++)
      {
         app = clone_object("/players/mizan/etheriel/subrealms/alchcave/beasties/apprentice.c");
         move_object(app, this_object());
      }
      
   }

   if(arg) return;
   set_light(1);
   
   short_desc = "The Caverns of Stupidity";

   long_desc =
   "    In this cavern there is a truly appaling sight. A giant pot sits in the\n"+
   "  middle of the room, filled with rotting corpses. Maggots are roasted alive\n"+
   "  along with the half-devoured carcasses in what seems to be some sort of\n"+
   "  distillation process.\n";
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d7.c", "west",
  });
}

