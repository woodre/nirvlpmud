inherit "/room/room.c";

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "02h Nexus - Etheriel Junction";
   long_desc =
   "    Bathed in a soft orange light, this is a much quieter and inviting\n"+
   "  for some reason. A gigantic beanbag sits in the far corner of the room.\n"+
   "  Machines are here as well, but they sit in the center of the area and\n"+
   "  are soft and organic in shape, as opposed to the cold and sleeker feel\n"+
   "  of devices in other parts of the Operational Nexus. To the west is the\n"+
   "  way to the central Nexus. In case you haven't figured it out, this\n"+
   "  contains the devices that power the Plane of Etheriel. There appears to\n"+
   "  be a one-way portal down into the jello.\n";
   
  items = ({
    "machines",
    "There are machines everywhere in this room. They vaguely remind you of\n"+
    "some kind of server room.",

    "floor",
    "The floor appears to be made of some sort of milky white obsidian.",

    "portal",
    "The portal shimmers with an uncommonly bright orange tinted light\n"+
    "Beneath, you see what appears to be somewhere in the familiar Jello.",

    "beanbag",
    "Upon closer inspection, you realize that the beanbag is actually made of SpuckStuff.",
  });
  
  dest_dir = 
  ({
    "/players/mizan/core/02h/room03.c", "west",
    "/players/mizan/etheriel/ROOMS/spoogle.c", "down",
  });

  set_no_clean(1);

}

init()
{
   ::init();
}

