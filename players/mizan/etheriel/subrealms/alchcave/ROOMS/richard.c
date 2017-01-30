inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "Smoky, Greasy, And Utterly Repulsive Cavern";
   long_desc =
   "    You emerge from the cracks in the cavern walls to a strange new place.\n"+
   "  It is still a cave, but there are Christmas tree ornaments hanging all\n"+
   "  over the place. In the far corner, a carefully stacked pile of empty\n"+
   "  ice cream cartons is surrounded by randomly tossed bottles.\n";
   
  items = ({
    "bottles",
    "You can count at least thirty empty apple juice bottles. Some of them are\n"+
    "contain unknown liquids in various states of decay",

    "cartons",
    "The strange thing about these cartons is that they are all the same.\n"+
    "Mango flavored ice cream and sorbets",

    "ornaments",
    "Thousands of Christmas tree ornaments are hanging from the walls, carefully.\n"+
    "planted on the rocky crag walls of the cave. This is really... strange",

  });
  
  dest_dir = 
  ({
    "/players/mizan/etheriel/subrealms/alchcave/entrance.c", "slip",
  });
}

