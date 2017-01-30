inherit "/room/room.c";
object app;
int i;

void reset(int arg) 
{
   if(!app)
   {
         app = clone_object("/players/mizan/etheriel/subrealms/alchcave/beasties/hydra.c");
         move_object(app, this_object());
      
   }

   if(arg) return;
   set_light(1);
   
   short_desc = "The Reckoning Focus";

   long_desc =
   "    You are in a sparsely lit room. The sounds of the earth around you\n"+
   "  groaning and buckling make you queasy and unsettled. If anything the\n"+
   "  source of all the sulphur stench has been explained in this part of\n"+
   "  the caverns.\n";
   
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d10.c", "out",
  });
}

init()
{
   ::init();
   add_action("go_north","north");
}

go_north()
{
   this_player()->move_player("out#/players/mizan/etheriel/subrealms/alchcave/ROOMS/d10.c");
   return 1;
}