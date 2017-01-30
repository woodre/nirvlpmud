inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "The Caverns Of Stupidity - Hallway";

   long_desc =
   "    This appears to be part of a long hallway that leads through the caverns.\n"+
   "  Screaming and all sorts of violent grunts can be heard from along the side\n"+
   "  rooms. Strange markings and paintings were hastily scribbled into the rock\n"+
   "  face. A strange grate on the ground also has these markings on them.\n"+
   "  The smell is so bad that you cannot help yourself from vomiting into your\n"+
   "  mouth, and then forcing yourself to swallow it back down again.\n";
   
  items = ({

    "wall",
    "The wall appears to be covered in pig vomit",

    "markings",
    "A lot of the markings are repetitive. They read:\n"+
    "'BITTER 0WNZ J00!'\n'SCARTHE lol BUTHAXX0R!'",
    
    "paintings",
    "On the wall appears to be a crude painting of something that that looks like a\n"+
    "man spreading his rear end. This is truly horrid stuff",

    "grate",
    "There is a strange grate covering a hole here. It seems possible to go 'climb down'\n"+
    "the hole but something tells you that might be a bad idea..",

    "grating",
    "There is a strange grate covering a hole here. It seems possible to go 'climb down'\n"+
    "the hole but something tells you that might be a bad idea..",
    
  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d5.c", "north",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d10.c", "south",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d8.c", "east",
    "/players/mizan/etheriel/subrealms/alchcave/ROOMS/d9.c", "west",
  });
}

init()
{
   ::init();
   add_action("climb","climb");
}

climb()
{
   write("You slip through the grating and somewhere else...\n");
   this_player()->move_player("through the grating#/players/mizan/etheriel/subrealms/alchcave/ROOMS/d14.c");
   return 1;
}
