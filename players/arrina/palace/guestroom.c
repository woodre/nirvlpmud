inherit "room/room";
reset(arg) {
   if(!arg) {
   set_light(1);
      short_desc = "Guest Bedroom";

      long_desc =
     "You have entered the bedroom where select guests may stay\n"+ 
     "the night. A large bed is set before the east wall. A rug\n"+ 
     "fills the floor in the center of the room. Windows to the\n"+ 
     "south overlook the courtyard.\n";

   items = ({
     "bed","A large comfortable looking bed lies before you",
     "rug","A thick rug lies on the floor",
     "window","You look out at the moonlit courtyard",
  });

  dest_dir = ({
      "/players/arrina/palace/balcony.c","west",
  });
} }
