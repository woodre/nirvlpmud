inherit "/room/room.c";

object fixture;

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus - PG Isolation Chamber";
   long_desc =
   "    This is the isolation chamber for the Nexus proving grounds. Monsters\n"+
   "  can be summoned here for testing in combat. A combat fixture sits here\n"+
   "  awaiting combat testing. It is advisable to look at it for more information.\n"+
   "  The entire room has a hermetically sealed and secure aspect to all of it.\n";   
  
   items = ({

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",

  });
  
  dest_dir = 
  ({
    "/players/mizan/core/02h/room05.c", "south",
  });

  set_no_clean(1);


    if(!fixture)
    {
        fixture = clone_object("/players/mizan/core/02h/testmonster.c");
        move_object(fixture, this_object());
    }
}

init()
{
   ::init();
   add_action("on_loadup","loadup");
}

on_loadup(str)
{
    object mons;

    if(!str) return 0;

    if(str == "gordie") mons = clone_object("/players/jenny/wings/mobs/closed/ghowe.c");
    
    if(mons)
    {
        move_object(mons, this_object());
        tell_room(this_object(), mons->short() + " is summoned to the isolation chamber.\n");
    }
    write("Ok.\n");
    return 1;
}

