inherit "/room/room.c";
object app;
int i;

void reset(int arg) 
{
   if(!app)
   {
         app = clone_object("/players/mizan/etheriel/subrealms/alchcave/beasties/scarthe.c");
         move_object(app, this_object());
      
   }

   if(arg) return;
   set_light(1);
   
   short_desc = "The Bludgeoning Focus";

   long_desc =
   "    You vomit at the sight of what is here. The cavern walls and rock\n"+
   "  faces are completely covered with congealed blood and still-drying\n"+
   "  entrails of various animals. Moist organs are hammered in with stakes\n"+
   "  directly into the craggy rock walls. The floor is made slick from\n"+
   "  draining blood and various bodily fluids.\n";
   
  
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