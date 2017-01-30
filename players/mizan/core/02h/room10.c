inherit "/room/room.c";
object ob;

void reset(int arg) 
{

   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus - Non Fight Start Chamber";
   long_desc =
   "    You are in a simple, super-sparse white room that resembles a racquetball\n"+
   "  court in appearance and size. The walls are almost a glowing white however.\n"+
   "  This is the NON-FIGHT-START area.\n";   
  
   items = ({

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/core/02h/room09.c", "west",
  });

  move_object(clone_object("/players/mizan/core/02h/item-roomdetector.c"), this_object());

  set_no_clean(1);

}

query_no_fight() { return 1; }

init()
{
   ::init();
}

