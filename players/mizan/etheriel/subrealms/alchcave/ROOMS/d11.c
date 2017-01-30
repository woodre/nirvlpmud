inherit "/room/room.c";
object app;
int i;

void reset(int arg) 
{
   if(!app)
   {
         app = clone_object("/players/mizan/etheriel/subrealms/alchcave/beasties/bitterment.c");
         move_object(app, this_object());
      
   }

   if(arg) return;
   set_light(1);
   
   short_desc = "The Consolation Focus";

   long_desc =
   "    Curious stacks of fist-sized boulders line the cave room in orderly rows.\n"+
   "  Scribbled on the walls in blood are the curious words 'I will not cheat'\n"+
   "  over and over again. At your feet, in great green letters carefully\n"+
   "  etched onto the floor is the word 'CLOUDKILL'. You are confused, but\n"+
   "  at least the stench of filth and sulphur is not quite so bad in this room.\n";
   
  
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