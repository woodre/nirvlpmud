inherit "/room/room.c";
object app;

void reset(int arg) 
{
   if(!app)
   {
      app = clone_object("/players/mizan/etheriel/subrealms/alchcave/environs/sign.c");
      move_object(app, this_object());
   }

   if(arg) return;
   set_light(1);
   
   short_desc = "Entrance To The Caverns Of Stupidity";
   long_desc =
   "    This is a clearing within the rocky confines of this hellhole that\n"+
   "  actually seems to have undergone some real effort in its construction.\n"+
   "  Laborers seem to have carefully carved the rock faces as smooth and level\n"+
   "  as possible. A big and gaudy neon sign hanging in the dead center of this\n"+
   "  cavern which is just BEGGING to be read.\n";
   
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/entrance.c", "up",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d1.c", "down",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/store.c", "east",
  });
  
}

